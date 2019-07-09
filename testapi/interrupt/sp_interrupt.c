#include <types.h>
#include "common_all.h"
#include "sp_interrupt.h"

void _RESET_handler( void ) __attribute__ ((naked));
void _UNDEF_INS_handler( void ) __attribute__ ((naked));
void _SWI_handler( void ) __attribute__ ((naked));
void _PREFE_ABORT_handler( void ) __attribute__ ((naked));
void _DATA_ABORT_handler( void ) __attribute__ ((naked));
void _NO_USED_handler( void ) __attribute__ ((naked));
void _IRQ_handler( void ) __attribute__ ((naked));
void _FIRQ_handler( void ) __attribute__ ((naked));

#define IRQS        (SPINTC_IRQS + 32) // add Achip(I141) IRQS
interrupt_operation  *int_opt_table[IRQS] = {0};

#define AINT_BASE   (SPINTC_IRQS - 32) // skip SGI(0~15)/PPI(16~31)

#include "gic.h"

#define CA7_CORE_BASE   0x9F100000
#define GIC_DIST_BASE   (CA7_CORE_BASE + GIC_DIST_OFFSET)
#define GIC_CPU_BASE    (CA7_CORE_BASE + GIC_CPU_OFFSET_A15)

#define FIQ_DISABLE     0x07 // EnableS | EnableNS | AckCtrl
#define FIQ_ENABLE      0x0F // EnableS | EnableNS | AckCtrl | FIQEn

#define dmb()  asm volatile ("dmb sy" : : : "memory")
#define readl(c)    ({ u32 __v = HAL_READ_UINT32(c, __v); dmb(); __v; })
#define writel(v,c) ({ u32 __v = v; dmb(); HAL_WRITE_UINT32(c, __v); __v; })

#define DIV_ROUND_UP(n,d) (((n) + (d) - 1) / (d))

int gic_irqs = 0;

void gic_dist_init(void)
{
    u32 base = GIC_DIST_BASE;
    int i;

    /*
     * Find out how many interrupts are supported.
     * The GIC only supports up to 1020 interrupt sources.
     */
    gic_irqs = readl(base + GICD_TYPER) & 0x1f;
    gic_irqs = (gic_irqs + 1) * 32;
    if (gic_irqs > 1020)
        gic_irqs = 1020;

    writel(0, base + GICD_CTLR);

    /*
     * Set all global interrupts to be level triggered, active low.
     */
    for (i = 32; i < gic_irqs; i += 16)
        writel(0, base + GICD_ICFGR + i * 4 / 16);

    /*
     * Set all global interrupts to CPU0 only.
     */
    for (i = 32; i < gic_irqs; i += 4)
        writel(0x01010101, base + GICD_ITARGETSRn + i * 4 / 4);

    /*
     * Set priority on all global interrupts.
     */
    for (i = 32; i < gic_irqs; i += 4)
        writel(0xa0a0a0a0, base + GICD_IPRIORITYRn + i * 4 / 4);

    /*
     * Disable all interrupts.  Leave the PPI and SGIs alone
     * as these enables are banked registers.
     */
    for (i = 32; i < gic_irqs; i += 32)
        writel(0xffffffff, base + GICD_ICENABLERn + i * 4 / 32);

    writel(3, base + GICD_CTLR);
}

void gic_cpu_init(void)
{
    u32 dist_base = GIC_DIST_BASE;
    u32 cpu_base = GIC_CPU_BASE;
    int i;

    /*
     * Deal with the banked PPI and SGI interrupts - disable all
     * PPI interrupts, ensure all SGI interrupts are enabled.
     */
    writel(0xffff0000, dist_base + GICD_ICENABLERn);
    writel(0x0000ffff, dist_base + GICD_ISENABLERn);

    /*
     * Set priority on PPI and SGI interrupts
     */
    for (i = 0; i < 32; i += 4)
        writel(0xa0a0a0a0, dist_base + GICD_IPRIORITYRn + i * 4 / 4);

    writel(0xf0, cpu_base + GICC_PMR);

    writel(0xffffffff, dist_base + GICD_IGROUPRn); // set ICDISR0 for SGI & PPI
    writel(FIQ_ENABLE, cpu_base + GICC_CTLR);
}

void gic_enable_irq(u32 irq, u32 enable)
{
    u32 offset = enable ? GICD_ISENABLERn : GICD_ICENABLERn;
    writel(1 << (irq % 32), GIC_DIST_BASE + offset  + (irq / 32) * 4);
    printf("@@@gic_enable_irq: %d %d\n", irq, enable);
}

void gic_eoi(u32 irq)
{
    writel(irq, GIC_CPU_BASE + GICC_EOIR);
}

u32 gic_ack(void)
{
    return readl(GIC_CPU_BASE + GICC_IAR);
}

void gic_set_fiq(u32 fiq)
{
    u32 base = GIC_DIST_BASE;
    int i;

    writel(0, base + GICD_CTLR);

    /* Set FIQ interrupt is Secure(Group0), others are Non-secure(Group1) */
    for (i = 1; i < DIV_ROUND_UP(gic_irqs, 32); i++) {
        writel((i == (fiq / 32)) ? (~(1 << (fiq & 0x1f))) : 0xffffffff,
            base + GICD_IGROUPRn + i * 4);
    }

    writel(3, base + GICD_CTLR); // dist Secure & Non-secure
}

int gic_init(void)
{
    printf("gic_init ...\n");

    gic_dist_init();
    gic_cpu_init();
    gic_set_fiq(0); // all set to IRQ

    return 0;
}





static void interrupt_reset(void)
{
    int i = 0;

    gic_init();

    /*Interrupts Initialize */
    for (i = 0; i < 7; i++) {
        // all edge
        HAL_WRITE_UINT32(SPINTC_TYPE + (i * 4), ~0);
        // all high-active
        HAL_WRITE_UINT32(SPINTC_POLAR + (i * 4), 0);
        // all irq
        HAL_WRITE_UINT32(SPINTC_PRIO + (i * 4), ~0);
        // all mask
        HAL_WRITE_UINT32(SPINTC_MASK + (i * 4), 0);
    }
}

static void interrupt_enable(void)
{
    portENABLE_INTERRUPTS();
}

static void interrupt_disable(void)
{
    portDISABLE_INTERRUPTS();
}

static int check_int_opt(interrupt_operation *int_opt)
{
    if (int_opt->vector < IRQS) {
        printf("check_int_opt: [vector] pass \n");
        if (int_opt->device_config != 0 && ((int_opt->interrupt_handler != 0) || (int_opt->interrupt_handler_with_vector != 0))) {
            printf("check_int_opt: [callback] pass \n");
            return 0;
        } else {
            return -1;
        }
    } else {
        return -1;
    }
}

static unsigned lookup_vector(void)
{
    unsigned dwMask;
    unsigned vector = 0, i;

    // get #
    for (i = 0; i < 7; i++) {
        // irq
        HAL_READ_UINT32(SPINTC_MSKIRQ + (i * 4), dwMask);
        if (dwMask) {
            vector = (i * 32);
            // find the bit
            while (!(dwMask & 0x1)) {
                dwMask >>= 1;
                vector++;
            }
            break;
        }

        // fiq
        HAL_READ_UINT32(SPINTC_MSKFIQ + (i * 4), dwMask);
        if (dwMask) {
            vector = (i * 32);
            // find the bit
            while (!(dwMask & 0x1)) {
                dwMask >>= 1;
                vector++;
            }
            break;
        }
    }

    return vector;
}

static void excute_int_config_opt(void)
{
    size_t i = 0;
    prn_string("Enter excute_int_config_opt() \n");
    while (i < IRQS) {
        if (int_opt_table[i] != 0) {
            (int_opt_table[i])->device_config();
        }
        i++;
    }
    prn_string("Exit excute_int_config_opt() \n");
}

static void excute_int_handler(unsigned vector)
{
    if (vector < IRQS) {
        if (int_opt_table[vector] != 0) {
            if ((int_opt_table[vector])->interrupt_handler != 0) {
                (int_opt_table[vector])->interrupt_handler();
            }
            if (int_opt_table[vector]->interrupt_handler_with_vector != 0) {
                int_opt_table[vector]->interrupt_handler_with_vector(vector);
            }
        }
    }
}

void gic_irq_handler(void)
{
    u32 irqstat = gic_ack();
    u32 irq = irqstat & ~0x1c00;

    //printf("@@@gic_irq_handler: %d\n", irq);
    excute_int_handler(irq + AINT_BASE);

    gic_eoi(irqstat);
}

#define EXT_INT0    (5 + SPINTC_IRQS)
#define EXT_INT1    (6 + SPINTC_IRQS)

static void ext0_cfg()
{
    hal_interrupt_configure(EXT_INT0, 1, 1); //level high
}

void ext0_isr(void)
{
    unsigned vector = lookup_vector();
    //printf("@@@ext0_isr: %d\n", vector);
    hal_interrupt_acknowledge(vector);  // int ack @ Bchip
    excute_int_handler(vector);
}

/* invoked by interrupt manager module */
void sp_interrupt_setup()
{
    static interrupt_operation opt;

    prn_string("Enter sp_interrupt_setup() \n");

    // register EXT_INT0
    memcpy(opt.dev_name, "EXT_INT0", strlen("EXT_INT0"));
    opt.vector = EXT_INT0;
    opt.device_config = ext0_cfg;
    opt.interrupt_handler = ext0_isr;
    interrupt_register(&opt);

    interrupt_disable();
    prn_string("intr reset\n");
    interrupt_reset();

    prn_string("reset done.");
    /* interrupt configuration registed by driver invoked here */
    excute_int_config_opt();

    prn_string("config opt done.");
    /* enable interrupt */
    interrupt_enable();

    // enable EXT_INT0
    hal_interrupt_unmask(EXT_INT0);

    prn_string("Exit sp_interrupt_setup() \n");
}

/* invoked by interrupt manager module */
void sp_interrupt_disable()
{
    interrupt_disable();
}

/* invoked by interrupt driver */
int interrupt_register(interrupt_operation *int_opt)
{
    if (check_int_opt(int_opt) < 0) {
        return -1;
    }

    int_opt_table[int_opt->vector] = int_opt;

    //printf("@@@interrupt_register: %d\n", int_opt->vector);
    return 0;
}

/* invoked by interrupt driver */
int interrupt_unregister(interrupt_operation *int_opt)
{
    if (check_int_opt(int_opt) < 0) {
        return -1;
    }
    int_opt_table[int_opt->vector] = 0;
    // prn_string("interrupt_unregister successfully \n");
    return 0;
}

void hal_interrupt_configure(int vector, int level, int up)
{
    unsigned int dwRegValue;

    if (vector < SPINTC_IRQS)
    {
        // 0:edge-type, 1:level-type
        HAL_READ_UINT32(SPINTC_TYPE + ((vector / 32) * 4), dwRegValue);
        if (level)
        {
            dwRegValue &= ~(1 << (vector % 32));
        }
        else
        {
            dwRegValue |= 1 << (vector % 32);
        }
        HAL_WRITE_UINT32(SPINTC_TYPE + ((vector / 32) * 4), dwRegValue);

        // 0:low-active, 1:high-active
        HAL_READ_UINT32(SPINTC_POLAR + ((vector / 32) * 4), dwRegValue);
        if (up)
        {
            dwRegValue &= ~(1 << (vector % 32));
        }
        else
        {
            dwRegValue |= 1 << (vector % 32);
        }
        HAL_WRITE_UINT32(SPINTC_POLAR + ((vector / 32) * 4), dwRegValue);
        //printf("@@@hal_interrupt_configure@B: %d %d\n", vector, level);
    }
    else
    {
        u32 reg, shift;

        vector -= AINT_BASE;
        reg = GIC_DIST_BASE + GICD_ICFGR + vector / 16 * 4;
        shift = (vector % 16) * 2;
        dwRegValue = readl(reg);
        if (level)
        {
            dwRegValue &= ~(3 << shift); // level high
        }
        else
        {
            dwRegValue |= (2 << shift); // edge rising
        }
        writel(dwRegValue, reg);
        //printf("@@@hal_interrupt_configure@A: %d %d\n", vector, level);
    }
}

void hal_interrupt_unmask(int vector)
{
    //printf("@@@hal_interrupt_unmask: %d\n", vector);
    if (vector < SPINTC_IRQS)
    {
        unsigned int dwMask;

        // mask # pass
        HAL_READ_UINT32(SPINTC_MASK + ((vector / 32) * 4), dwMask);
        dwMask |= 0x00000001 << (vector % 32);
        HAL_WRITE_UINT32(SPINTC_MASK + ((vector / 32) * 4), dwMask);
    }
    else
    {
        gic_enable_irq(vector - AINT_BASE, 1);
    }
}

void hal_interrupt_mask(int vector)
{
    //printf("@@@hal_interrupt_mask: %d\n", vector);
    if (vector < SPINTC_IRQS)
    {
        unsigned int dwMask;

        // mask # unpass
        HAL_READ_UINT32(SPINTC_MASK + ((vector / 32) * 4), dwMask);
        dwMask &= ~(0x00000001 << (vector % 32));
        HAL_WRITE_UINT32(SPINTC_MASK + ((vector / 32) * 4), dwMask);
    }
    else
    {
        gic_enable_irq(vector - AINT_BASE, 0);
    }
}

void hal_interrupt_acknowledge(int vector)
{
    unsigned int dwMask;

    dwMask = 0x00000001 << (vector % 32);
    // clear #
    HAL_WRITE_UINT32(SPINTC_CLR + ((vector / 32) * 4), dwMask);
}

/* invoked by interrupt vector */
void _RESET_handler( void )
{
    prn_string("_RESET_handler()\n");
}

void _UNDEF_INS_handler( void )
{
    prn_string("_UNDEF_INS_handler()\n");
}

void _SWI_handler( void )
{
    prn_string("_SWI_handler()\n");
}

void _PREFE_ABORT_handler( void )
{
    prn_string("_PREFE_ABORT_handler()\n");
}

void _DATA_ABORT_handler( void )
{
    prn_string("_DATA_ABORT_handler()\n");
}

void _NO_USED_handler( void )
{
    prn_string("_NO_USED_handler()\n");
}

void _IRQ_handler( void )
{
    isrSAVE_CONTEXT();
    gic_irq_handler();
    isrRESTORE_CONTEXT();
}

void _FIRQ_handler( void )
{
    prn_string("_FIRQ_handler()\n");
}
