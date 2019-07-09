/********************************************************
 * Copyright (c) 2017 by Sunplus Technology Co., Ltd.
 *    ____               __
 *   / __/_ _____  ___  / /_ _____
 *  _\ \/ // / _ \/ _ \/ / // (_-<
 * /___/\_,_/_//_/ .__/_/\_,_/___/
 *              /_/
 * Sunplus Technology Co., Ltd.19, Innovation First Road,
 * Science-Based Industrial Park, Hsin-Chu, Taiwan, R.O.C.
 * ------------------------------------------------------
 *
 * Description :  noc register header simple test for i137
 * ------------------------------------------------------
 * Rev  Date          Author(s)      Status & Comments
 * ======================================================
 * 0.1  2017/05/18    nz.lu          initial version
 */
#include <emuio.h>
#include <string.h>
#include "noc_reg.h"


struct noc_master_module {
    char                      *name;
    noc_ahbm_regs             *ahbm;
    noc_amba_master_addr_regs *amba_addr;
    unsigned int              ahbm_cnt;
    noc_amba_master_ctrl_regs *amba_ctrl;
    noc_bridge_regs           *bridge;
    noc_bridge_no_pf_regs     *bridge_np;
};

struct noc_slave_module {
    char                     *name;
    noc_amba_slave_ctrl_regs *amba_ctrl;
    noc_bridge_regs          *bridge;
};


enum master_module_list {
    A926_D0,
    A926_I0,
    CBDMA0_M0,
    DISP_DDFCH,
    IOCTRL_M0,
    SIB2_M,
    IOP_M0,
    PBUS0_M0,
    SIB1_M,
    U3F_M0,
    USB_M0,
    USB_M1,
    SIB3_M,
    RBM_M,
    MASTER_MAX_CNT
};


#define NOC_NONE   (99)
#define NOC_MASTER (0)
#define NOC_SLAVE  (1)


enum slave_module_list {
    CBDMA0_S0,
    SDCTRL_SD0,
    SPI_BR_BR,
    SPI_BR_RB,
    SPI_BR_S0,
    SLAVE_MAX_CNT
};

struct noc_master_module noc_masters[MASTER_MAX_CNT] =
{
    {"a926_d0", (noc_ahbm_regs *) noc_a926_d0_ahbm_regs, (noc_amba_master_addr_regs *) noc_a926_d0_amba_addr_regs, A926_D0_ADDR_INDEX_MAX, (noc_amba_master_ctrl_regs *) noc_a926_d0_amba_ctrl_regs, (noc_bridge_regs *) noc_a926_d0_brdg_regs, NULL},
    {"a926_i0", (noc_ahbm_regs *) noc_a926_i0_ahbm_regs, (noc_amba_master_addr_regs *) noc_a926_i0_amba_addr_regs, A926_I0_ADDR_INDEX_MAX, (noc_amba_master_ctrl_regs *) noc_a926_i0_amba_ctrl_regs, (noc_bridge_regs *) noc_a926_i0_brdg_regs, NULL},
    {"cbdma0_m0", NULL, (noc_amba_master_addr_regs *) noc_cbdma0_m0_amba_addr_regs, CBDMA0_M0_ADDR_INDEX_MAX, (noc_amba_master_ctrl_regs *) noc_cbdma0_m0_amba_ctrl_regs, (noc_bridge_regs *) noc_cbdma0_m0_brdg_regs, NULL},
    {"disp_ddfch", NULL, (noc_amba_master_addr_regs *) noc_disp_ddfch_amba_addr_regs, DISP_DDFCH_ADDR_INDEX_MAX, (noc_amba_master_ctrl_regs *) noc_disp_ddfch_amba_ctrl_regs, (noc_bridge_regs *) noc_disp_ddfch_brdg_regs, NULL},
    {"ioctrl_m0", NULL, (noc_amba_master_addr_regs *) noc_ioctrl_m0_amba_addr_regs, IOCTRL_M0_ADDR_INDEX_MAX, (noc_amba_master_ctrl_regs *) noc_ioctrl_m0_amba_ctrl_regs, (noc_bridge_regs *) noc_ioctrl_m0_brdg_regs, NULL},
    {"sib2_m", NULL, (noc_amba_master_addr_regs *) noc_sib2_m_amba_addr_regs, SIB2_M_ADDR_INDEX_MAX, (noc_amba_master_ctrl_regs *) noc_sib2_m_amba_ctrl_regs, (noc_bridge_regs *) noc_sib2_m_brdg_regs, NULL},
    {"iop_m0", NULL, (noc_amba_master_addr_regs *) noc_iop_m0_amba_addr_regs, IOP_M0_ADDR_INDEX_MAX, (noc_amba_master_ctrl_regs *) noc_iop_m0_amba_ctrl_regs, (noc_bridge_regs *) noc_iop_m0_brdg_regs, NULL},
    {"pbus0_m0", NULL, (noc_amba_master_addr_regs *) noc_pbus0_m0_amba_addr_regs, PBUS0_M0_ADDR_INDEX_MAX, (noc_amba_master_ctrl_regs *) noc_pbus0_m0_amba_ctrl_regs, (noc_bridge_regs *) noc_pbus0_m0_brdg_regs, NULL},
    {"sib1_m", NULL, (noc_amba_master_addr_regs *) noc_sib1_m_amba_addr_regs, SIB1_M_ADDR_INDEX_MAX, (noc_amba_master_ctrl_regs *) noc_sib1_m_amba_ctrl_regs, (noc_bridge_regs *) noc_sib1_m_brdg_regs, NULL},
    {"u3f_m0", NULL, (noc_amba_master_addr_regs *) noc_u3f_m0_amba_addr_regs, U3F_M0_ADDR_INDEX_MAX, (noc_amba_master_ctrl_regs *) noc_u3f_m0_amba_ctrl_regs, (noc_bridge_regs *) noc_u3f_m0_brdg_regs, NULL},
    {"usb_m0", NULL, (noc_amba_master_addr_regs *) noc_usb_m0_amba_addr_regs, USB_M0_ADDR_INDEX_MAX, (noc_amba_master_ctrl_regs *) noc_usb_m0_amba_ctrl_regs, (noc_bridge_regs *) noc_usb_m0_brdg_regs, NULL},
    {"usb_m1", NULL, (noc_amba_master_addr_regs *) noc_usb_m1_amba_addr_regs, USB_M1_ADDR_INDEX_MAX, (noc_amba_master_ctrl_regs *) noc_usb_m1_amba_ctrl_regs, (noc_bridge_regs *) noc_usb_m1_brdg_regs, NULL},
    {"sib3_m", NULL, (noc_amba_master_addr_regs *) noc_sib3_m_amba_addr_regs, SIB3_M_ADDR_INDEX_MAX, (noc_amba_master_ctrl_regs *) noc_sib3_m_amba_ctrl_regs, (noc_bridge_regs *) noc_sib3_m_brdg_regs, NULL},
    {"rbm_m", NULL, NULL, 0, (noc_amba_master_ctrl_regs *) noc_rbm_m_amba_ctrl_regs, NULL, (noc_bridge_no_pf_regs *) noc_rbm_m_brdg_regs}
};


struct noc_slave_module noc_slaves[SLAVE_MAX_CNT] =
{
    {"cbdma0_s0", (noc_amba_slave_ctrl_regs *) noc_cbdma0_s0_amba_ctrl_regs, (noc_bridge_regs *) noc_cbdma0_s0_brdg_regs},
    {"sdctrl_sd0", (noc_amba_slave_ctrl_regs *) noc_sdctrl_sd0_amba_ctrl_regs, (noc_bridge_regs *) noc_sdctrl_sd0_brdg_regs},
    {"spi_br_br", (noc_amba_slave_ctrl_regs *) noc_spi_br_br_amba_ctrl_regs, (noc_bridge_regs *) noc_spi_br_br_brdg_regs},
    {"spi_br_rb", (noc_amba_slave_ctrl_regs *) noc_spi_br_rb_amba_ctrl_regs, (noc_bridge_regs *) noc_spi_br_rb_brdg_regs},
    {"spi_br_s0", (noc_amba_slave_ctrl_regs *) noc_spi_br_s0_amba_ctrl_regs, (noc_bridge_regs *) noc_spi_br_s0_brdg_regs},

};


enum regs_group {
    NOC_AHBM,
    NOC_AMBA_MASTER_CTRL,
    NOC_AMBA_SLAVE_CTRL,
    NOC_BRIDGE,
    NOC_BRIDGE_NO_PF,
    REGS_GROUP_MAX
};

const char *module_name_list[] = {
    "a926_d0",
    "a926_i0",
    "cbdma0_m0",
    "disp_ddfch",
    "ioctrl_m0",
    "sib2_m",
    "iop_m0",
    "pbus0_m0",
    "sib1_m",
    "u3f_m0",
    "usb_m0",
    "usb_m1",
    "sib3_m",
    "rbm_m",
    "cbdma0_s0",
    "sdctrl_sd0",
    "spi_br_br",
    "spi_br_rb",
    "spi_br_s0",
    NULL
};


const char *regs_grp_name_list[] = {
    "ahbm", "ambam", "ambas", "bridge", "bridge_np", NULL
};

const char *reg_name_list[REGS_GROUP_MAX][64] =
{
    // ahbm
    {"ctl", "sts", "im" , NULL},
    // amba master
    {"tocfg", "osslv", "cgc", "cgo", "cfg", "sts", "bridge_id", "err",
    "toslvid", "era", "ewa", "intm", "caddr", "caddrmsk", "ccmd_0",
    "ccmdmsk_0", "cntr_0", "latnum_0", "ccmd_1", "ccmdmsk_1",
    "cntr_1", "latnum_1", "arovrd", "awovrd", NULL},
    // amba slave
    {"cgc", "cgo", "sts", "bridge_id", "err", "intm", "ccmd", "ccmdmsk", "cntr", "arovrd", "awovrd", NULL},
    // bridge
    {"p_0", "p_1", "p_2", "p_3", "txe", "txem", "btus_0", "btus_1", "txid", "btrl_0",
    "btrl_1", "btrl_2", "btrl_3", "btperr", "btperrm", "rxe", "rxem", "brs_0", "brs_1",
    "brs_2", "brs_3", "brs_4", "brs_5", "brs_6", "brs_7", "brs_8", "brs_9", "brs_10",
    "brs_11", "brs_12", "brs_13", "brs_14", "brs_15", "brus", "rxid", "brperr_0",
    "brperr_1", "brperrm_0", "brperrm_1", NULL},
    // bridge no profile
    {"btus_0", "btus_1", "txid", "btrl_0", "btrl_1", "btrl_2", "btrl_3",
    "btperr", "btperrm", "rxe", "rxem", "brs_0", "brs_1", "brs_2",
    "brs_3", "brs_4", "brs_5", "brs_6", "brs_7", "brs_8", "brs_9",
    "brs_10", "brs_11", "brs_12", "brs_13", "brs_14", "brs_15",
    "brus", "rxid", "brperr_0", "brperr_1", "brperrm_0", "brperrm_1", NULL}
};


const unsigned int reg_offset_list[REGS_GROUP_MAX][64] =
{
    // ahbm
    {0, 8, 16},
    // amba master
    {0, 8, 16, 24, 32, 256, 264, 512, 520, 528, 536, 576,
    768, 776, 784, 792, 800, 808, 816, 824, 832, 840,
    864, 872},
    // amba slave
    {0, 8, 240, 248, 496, 560, 752, 760, 768, 776, 784},
    // bridge
    {0, 8, 16, 24, 64, 72, 88, 96, 120, 128, 136, 144, 152, 168, 176, 288, 296,
    304, 312, 320, 328, 336, 344, 352, 360, 368, 376, 384, 392, 400, 408, 416,
    424, 432, 440, 464, 472, 480, 488},
    // bridge no profile
    {0, 8, 32, 40, 48, 56, 64, 80, 88, 200, 208, 216, 224, 232, 240, 248,
    256, 264, 272, 280, 288, 296, 304, 312, 320, 328, 336, 344, 352, 376,
    384, 392, 400}
};




int check_ahbm_reg(noc_ahbm_regs *regs)
{

    printf("\t[AHBM]\n");
    printf("\tctl : 0x%08x\n", (unsigned) regs->ctl);
    printf("\tsts : 0x%08x\n", (unsigned) regs->sts);
    printf("\tim  : 0x%08x\n", (unsigned) regs->im);
    return 0;
}

int check_amba_addr_reg(noc_amba_master_addr_regs *regs, unsigned int max_cnt)
{
    int idx;
    printf("[AMBA ADDR]\n");
    for (idx = 0; idx < max_cnt; idx++) {
        printf("\t[%02d] adbase : 0x%08x\n", idx, (unsigned) regs->amba_addr[idx].adbase);
        printf("\t     admask : 0x%08x\n", (unsigned) regs->amba_addr[idx].admask);
    }

    return 0;
}

int check_amba_master_ctrl_reg(noc_amba_master_ctrl_regs *regs)
{
    printf("[AMBA CTRL]\n");
    printf("\ttocfg      : 0x%08x\n", (unsigned) regs->tocfg);
    printf("\tosslv      : 0x%08x\n", (unsigned) regs->osslv);
    printf("\tcgc        : 0x%08x\n", (unsigned) regs->cgc);
    printf("\tcgo        : 0x%08x\n", (unsigned) regs->cgo);
    printf("\tcfg        : 0x%08x\n", (unsigned) regs->cfg);
    printf("\tsts        : 0x%08x\n", (unsigned) regs->sts);
    printf("\tbridge_id  : 0x%08x\n", (unsigned) regs->bridge_id);
    printf("\terr        : 0x%08x\n", (unsigned) regs->err);
    printf("\ttoslvid    : 0x%08x\n", (unsigned) regs->toslvid);
    printf("\tera        : 0x%08x\n", (unsigned) regs->era);
    printf("\tewa        : 0x%08x\n", (unsigned) regs->ewa);
    printf("\tintm       : 0x%08x\n", (unsigned) regs->intm);
    printf("\tcaddr      : 0x%08x\n", (unsigned) regs->caddr);
    printf("\tcaddrmsk   : 0x%08x\n", (unsigned) regs->caddrmsk);
    printf("\tccmd_0     : 0x%08x\n", (unsigned) regs->cmd_cap[0].ccmd);
    printf("\tccmdmsk_0  : 0x%08x\n", (unsigned) regs->cmd_cap[0].ccmdmsk);
    printf("\tcntr_0     : 0x%08x\n", (unsigned) regs->cmd_cap[0].cntr);
    printf("\tlatnum_0   : 0x%08x\n", (unsigned) regs->cmd_cap[0].latnum);
    printf("\tccmd_1     : 0x%08x\n", (unsigned) regs->cmd_cap[1].ccmd);
    printf("\tccmdmsk_1  : 0x%08x\n", (unsigned) regs->cmd_cap[1].ccmdmsk);
    printf("\tcntr_1     : 0x%08x\n", (unsigned) regs->cmd_cap[1].cntr);
    printf("\tlatnum_1   : 0x%08x\n", (unsigned) regs->cmd_cap[1].latnum);
    printf("\tarovrd     : 0x%08x\n", (unsigned) regs->arovrd);
    printf("\tawovrd     : 0x%08x\n", (unsigned) regs->awovrd);
    return 0;
}


int check_amba_slave_ctrl_reg(noc_amba_slave_ctrl_regs *regs)
{
    printf("[AMBA CTRL]\n");
    printf("\tcgc        : 0x%08x\n", (unsigned) regs->cgc);
    printf("\tcgo        : 0x%08x\n", (unsigned) regs->cgo);
    printf("\tsts        : 0x%08x\n", (unsigned) regs->sts);
    printf("\tbridge_id  : 0x%08x\n", (unsigned) regs->bridge_id);
    printf("\terr        : 0x%08x\n", (unsigned) regs->err);
    printf("\tintm       : 0x%08x\n", (unsigned) regs->intm);
    printf("\tccmd       : 0x%08x\n", (unsigned) regs->ccmd);
    printf("\tccmdmsk    : 0x%08x\n", (unsigned) regs->ccmdmsk);
    printf("\tcntr       : 0x%08x\n", (unsigned) regs->cntr);
    printf("\tarovrd     : 0x%08x\n", (unsigned) regs->arovrd);
    printf("\tawovrd     : 0x%08x\n", (unsigned) regs->awovrd);
    return 0;
}


int check_bridge_reg(noc_bridge_regs *regs)
{
    int idx;
    printf("[BRIDGE]\n");
    printf("\tp_0       : 0x%08x\n", (unsigned) regs->p[0]);
    printf("\tp_1       : 0x%08x\n", (unsigned) regs->p[1]);
    printf("\tp_2       : 0x%08x\n", (unsigned) regs->p[2]);
    printf("\tp_3       : 0x%08x\n", (unsigned) regs->p[3]);
    printf("\ttxe       : 0x%08x\n", (unsigned) regs->txe);
    printf("\ttxem      : 0x%08x\n", (unsigned) regs->txem);
    printf("\tbtus_0    : 0x%08x\n", (unsigned) regs->btus[0]);
    printf("\tbtus_1    : 0x%08x\n", (unsigned) regs->btus[1]);
    printf("\ttxid      : 0x%08x\n", (unsigned) regs->txid);

    for (idx = 0; idx < 4; idx++)   {
        printf("\tbtrl_%d    : 0x%08x\n", idx ,(unsigned) regs->btrl[idx]);
    }

    printf("\tbtperr    : 0x%08x\n", (unsigned) regs->btperr);
    printf("\tbtperrm   : 0x%08x\n", (unsigned) regs->btperrm);
    printf("\trxe       : 0x%08x\n", (unsigned) regs->rxe);
    printf("\trxem      : 0x%08x\n", (unsigned) regs->rxem);

    for (idx = 0; idx < 16; idx++)  {
        printf("\tbrs_%d     : 0x%08x\n", idx, (unsigned) regs->brs[idx]);
    }

    printf("\tbrus      : 0x%08x\n", (unsigned) regs->brus);
    printf("\trxid      : 0x%08x\n", (unsigned) regs->rxid);
    printf("\tbrperr_0  : 0x%08x\n", (unsigned) regs->brperr[0]);
    printf("\tbrperr_1  : 0x%08x\n", (unsigned) regs->brperr[1]);
    printf("\tbrperrm_0 : 0x%08x\n", (unsigned) regs->brperrm[0]);
    printf("\tbrperrm_1 : 0x%08x\n", (unsigned) regs->brperrm[1]);

    return 0;
}

int check_bridge_np_reg(noc_bridge_no_pf_regs *regs)
{
    int idx;
    printf("[BRIDGE NP]\n");
    printf("\tbtus_0    : 0x%08x\n", (unsigned) regs->btus[0]);
    printf("\tbtus_1    : 0x%08x\n", (unsigned) regs->btus[1]);
    printf("\ttxid      : 0x%08x\n", (unsigned) regs->txid);

    for (idx = 0; idx < 4; idx++)   {
        printf("\tbtrl_%d    : 0x%08x\n", idx ,(unsigned) regs->btrl[idx]);
    }

    printf("\tbtperr    : 0x%08x\n", (unsigned) regs->btperr);
    printf("\tbtperrm   : 0x%08x\n", (unsigned) regs->btperrm);
    printf("\trxe       : 0x%08x\n", (unsigned) regs->rxe);
    printf("\trxem      : 0x%08x\n", (unsigned) regs->rxem);

    for (idx = 0; idx < 16; idx++)  {
        printf("\tbrs_%d     : 0x%08x\n", idx, (unsigned) regs->brs[idx]);
    }

    printf("\tbrus      : 0x%08x\n", (unsigned) regs->brus);
    printf("\trxid      : 0x%08x\n", (unsigned) regs->rxid);
    printf("\tbrperr_0  : 0x%08x\n", (unsigned) regs->brperr[0]);
    printf("\tbrperr_1  : 0x%08x\n", (unsigned) regs->brperr[1]);
    printf("\tbrperrm_0 : 0x%08x\n", (unsigned) regs->brperrm[0]);
    printf("\tbrperrm_1 : 0x%08x\n", (unsigned) regs->brperrm[1]);
    return 0;
}


void dump_noc_reg()
{
    int idx;
    struct noc_master_module *noc_mm;
    struct noc_slave_module *noc_sm;

    volatile unsigned int *reg_clk_en = (unsigned int *) 0x9C00001C;
    volatile unsigned int *reg_gclk_en = (unsigned int *) 0x9C000030;

    // bit 6 is for noc
    *reg_clk_en |= (1 << 6);
    *reg_gclk_en |= (1 << 6);

    for (idx = 0; idx < MASTER_MAX_CNT; idx++) {

        noc_mm = &noc_masters[idx];
        printf("\n\n[INFO] Check module %s.\n", noc_mm->name);

        if (noc_mm->ahbm != NULL) {
            check_ahbm_reg(noc_mm->ahbm);
        }
        if (noc_mm->amba_addr != NULL) {
            check_amba_addr_reg(noc_mm->amba_addr, noc_mm->ahbm_cnt);
        }
        if (noc_mm->amba_ctrl != NULL) {
            check_amba_master_ctrl_reg(noc_mm->amba_ctrl);
        }
        if (noc_mm->bridge != NULL) {
            check_bridge_reg(noc_mm->bridge);
        }
        if (noc_mm->bridge_np != NULL) {
            check_bridge_np_reg(noc_mm->bridge_np);
        }
    }

    for (idx = 0; idx < SLAVE_MAX_CNT; idx++) {

        noc_sm = &noc_slaves[idx];
        printf("\n\n[INFO] Check module %s.\n", noc_sm->name);

        if (noc_sm->amba_ctrl != NULL) {
            check_amba_slave_ctrl_reg(noc_sm->amba_ctrl);
        }
        if (noc_sm->bridge != NULL) {
            check_bridge_reg(noc_sm->bridge);
        }

    }

}


void print_name_list(const char *name_list[])
{
    unsigned int i = 0;
    while (name_list[i] != NULL) {
        printf(" %s", name_list[i]);
        i++;
    }
    printf("\n");
}

unsigned int get_reg_index(const char *name_list[], char *rn)
{
    unsigned int i = 0;
    while (name_list[i] != NULL) {
		if (strncmp(name_list[i], rn, strlen(rn)) == 0)
            return i;
        i++;
    }

    return 0xFFFFFFFF;
}


void write_noc_reg(char *module_name, char *reg_grp, char *reg_name, unsigned int value)
{
    volatile unsigned int *base = NULL, *reg = NULL;
    struct noc_master_module *noc_mm = NULL;
    struct noc_slave_module *noc_sm = NULL;
    unsigned int reg_grp_type = 0xFFFFFFFF;
    unsigned int reg_name_idx, idx;
    unsigned int module_type = NOC_NONE;

    if (module_name == NULL) {
        printf("Invalid module name == NULL.\n");
        print_name_list(module_name_list);
        return;
    }

    // get noc module by module name
    for (idx = 0; idx < MASTER_MAX_CNT; idx++) {
		if (strncmp(noc_masters[idx].name, module_name, strlen(module_name)) == 0 ) {
            noc_mm = &noc_masters[idx];
            module_type = NOC_MASTER;
            break;
        }
    }

    if (module_type == NOC_NONE) {
        for (idx = 0; idx < SLAVE_MAX_CNT; idx++) {
			if (strncmp(noc_slaves[idx].name, module_name, strlen(module_name)) == 0) {
                noc_sm = &noc_slaves[idx];
                module_type = NOC_SLAVE;
                break;
            }
        }
    }

    if (module_type == NOC_NONE) {
        printf("Invalid module name.\n");
        print_name_list(module_name_list);
        return;
    }

    if (reg_grp == NULL) {
        printf("Invalid regs group name == NULL.\n");
        print_name_list(regs_grp_name_list);
        return;
    }

    // get reg_grp_type by module name
    for (idx = 0; idx < REGS_GROUP_MAX; idx++) {
		if (strncmp(regs_grp_name_list[idx], reg_grp, strlen(reg_grp)) == 0) {
            reg_grp_type = idx;
            break;
        }
    }

    if (reg_grp_type == 0xFFFFFFFF) {
        printf("Invalid regs group name.\n");
        print_name_list(regs_grp_name_list);
        return;
    }

    // get base address by reg_grp_type and noc module
    if (module_type == NOC_MASTER) {
        switch(reg_grp_type) {
            case NOC_AHBM:
                base = (volatile unsigned int *) noc_mm->ahbm;
                break;

            case NOC_AMBA_MASTER_CTRL:
                base = (volatile unsigned int *) noc_mm->amba_ctrl;
                break;

            case NOC_BRIDGE:
                base = (volatile unsigned int *) noc_mm->bridge;
                break;

            case NOC_BRIDGE_NO_PF:
                base = (volatile unsigned int *) noc_mm->bridge_np;
                break;
            default:
                break;
        }
    }
    else {
        switch(reg_grp_type) {
            case NOC_AMBA_SLAVE_CTRL:
                base = (volatile unsigned int *) noc_sm->amba_ctrl;
                break;

            case NOC_BRIDGE:
                base = (volatile unsigned int *) noc_sm->bridge;
                break;

            default:
                break;
        }
    }

    reg_name_idx = get_reg_index(reg_name_list[reg_grp_type], reg_name);

    if (reg_name_idx == 0xFFFFFFFF) {
        printf("Invalid regs name.\n");
        print_name_list(reg_name_list[reg_grp_type]);
        return;
    }
    reg = (volatile unsigned int *) ((unsigned int)base + reg_offset_list[reg_grp_type][reg_name_idx]);
    *reg = value;
    printf("%s = 0x%08x\n", reg_name_list[reg_grp_type][reg_name_idx], *reg);

}


void read_noc_regs(char *module_name, char *reg_grp, char *reg_name)
{
    struct noc_master_module *noc_mm = NULL;
    struct noc_slave_module *noc_sm = NULL;
    unsigned int reg_grp_type = 0xFFFFFFFF, idx;
    volatile unsigned int *base = NULL, *reg = NULL;
    unsigned int module_type = NOC_NONE;

    if (module_name == NULL) {
        printf("Module name is NULL.\n");
        print_name_list(module_name_list);
        return;
    }


    for (idx = 0; idx < MASTER_MAX_CNT; idx++) {
		if (strncmp(noc_masters[idx].name, module_name, strlen(module_name)) == 0 ) {
            noc_mm = &noc_masters[idx];
            module_type = NOC_MASTER;
            break;
        }
    }


    if (module_type == NOC_NONE) {
        for (idx = 0; idx < SLAVE_MAX_CNT; idx++) {
			if (strncmp(noc_slaves[idx].name, module_name, strlen(module_name)) == 0) {
                noc_sm = &noc_slaves[idx];
                module_type = NOC_SLAVE;
                break;
            }
        }
    }

    if (module_type == NOC_NONE) {
        printf("Invalid module name.\n");
        print_name_list(module_name_list);
        return;
    }

    if (reg_grp == NULL) {
        printf("Invalid regs group name is NULL.\n");
        print_name_list(regs_grp_name_list);
        return;
    }

    // get reg_grp_type by module name
    for (idx = 0; idx < REGS_GROUP_MAX; idx++) {
		if (strncmp(regs_grp_name_list[idx], reg_grp, strlen(reg_grp)) == 0) {
            reg_grp_type = idx;
            break;
        }
    }

    if (reg_grp_type == 0xFFFFFFFF) {
        printf("Invalid regs group name.\n");
        print_name_list(regs_grp_name_list);
        return;
    }

    // get base address by reg_grp_type and noc module
    if (module_type == NOC_MASTER) {
        switch(reg_grp_type) {
            case NOC_AHBM:
                base = (volatile unsigned int *) noc_mm->ahbm;
                break;

            case NOC_AMBA_MASTER_CTRL:
                base = (volatile unsigned int *) noc_mm->amba_ctrl;
                break;

            case NOC_BRIDGE:
                base = (volatile unsigned int *) noc_mm->bridge;
                break;

            case NOC_BRIDGE_NO_PF:
                base = (volatile unsigned int *) noc_mm->bridge_np;
                break;
            default:
                break;
        }
    }
    else {
        switch(reg_grp_type) {
            case NOC_AMBA_SLAVE_CTRL:
                base = (volatile unsigned int *) noc_sm->amba_ctrl;
                break;

            case NOC_BRIDGE:
                base = (volatile unsigned int *) noc_sm->bridge;
                break;

            default:
                break;
        }
    }

    if (reg_name == NULL) {
        // dump all in reg group
        idx = 0;
        while(reg_name_list[reg_grp_type][idx] != NULL) {
            reg = (volatile unsigned int *) ((unsigned int)base + reg_offset_list[reg_grp_type][idx]);
            printf("%s = 0x%08x\n", reg_name_list[reg_grp_type][idx], *reg);
            idx++;
        }
    } else {

        idx = get_reg_index(reg_name_list[reg_grp_type], reg_name);

        if (reg_grp_type == 0xFFFFFFFF) {
            printf("Invalid regs name.\n");
            print_name_list(reg_name_list[reg_grp_type]);
            return;
        }
        reg = (volatile unsigned int *) ((unsigned int)base + reg_offset_list[reg_grp_type][idx]);
        printf("%s = 0x%08x\n", reg_name_list[reg_grp_type][idx], *reg);
    }

}

#include "sp_interrupt.h"

extern void noc_perf_log(void);
extern void noc_perf_fs(void);

interrupt_operition t3_opt;
interrupt_operition fs_opt;

interrupt_operition cbdma0_opt;
interrupt_operition cbdma1_opt;


#define TIMER3_TICKS	(63000-1)		/* 700ms */
#define TIMER3_CONFIG_STC (1<<2)	/*src: stc*/
#define TIMER3_RELOAD	(1<<1)		/*timer3 auto reload*/
#define TIMER3_RUN 		(1<<0)		/*timer3 run*/
#define TIMER3_STOP     (0<<0)		/*timer3 stop*/

void timer3_isr_cfg()
{
	printf("[CFG] Timer3\n");
	STC_REG->timer3_ctl = TIMER3_CONFIG_STC | TIMER3_RELOAD | TIMER3_RUN;
	STC_REG->timer3_pres_val = 0;
	STC_REG->timer3_reload = TIMER3_TICKS;
	STC_REG->timer3_cnt = TIMER3_TICKS;
	hal_interrupt_configure(154, 0, 1);
}

void field_start_isr_cfg()
{
	printf("[CFG] Field Start\n");
	// hal_interrupt_configure(0, 0, 1);
}


void noc_initial_settings()
{
	int i;
	printf("Initial NoC.\n");
	volatile unsigned int *reg_clk_en = (unsigned int *) 0x9C00001C;
	volatile unsigned int *reg_gclk_en = (unsigned int *) 0x9C000030;

	// bit 6 is for noc
	*reg_clk_en |= (1 << 6);
	*reg_gclk_en |= (1 << 6);

	memcpy(cbdma0_opt.dev_name, "CBDMA0", strlen("CBDMA0"));
	cbdma0_opt.vector = 128;
	cbdma0_opt.device_config = cbdma0_isr_cfg;
	cbdma0_opt.interrupt_handler = cbdma0_isr;
	interrupt_register(&cbdma0_opt);

	// memcpy(t3_opt.dev_name, "Timer3", strlen("Timer3"));
	// t3_opt.vector = 154;
	// t3_opt.device_config = timer3_isr_cfg;
	// t3_opt.interrupt_handler = noc_perf_log;
	// interrupt_register(&t3_opt);

	// memcpy(fs_opt.dev_name, "FStart", strlen("FStart"));
	// fs_opt.vector = 0;
	// fs_opt.device_config = field_start_isr_cfg;
	// fs_opt.interrupt_handler = noc_perf_fs;
	// interrupt_register(&fs_opt);

	// for (i = 0; i < DISP_DDFCH_ADDR_INDEX_MAX; i++) {
	// 	printf("disp_ddfch base addr: 0x%llx\n", noc_disp_ddfch_amba_addr_regs->amba_addr[i].adbase);
	// 	printf("disp_ddfch mask     : 0x%llx\n", noc_disp_ddfch_amba_addr_regs->amba_addr[i].admask);
	// }

	printf("Initial NoC Done.\n");
}






