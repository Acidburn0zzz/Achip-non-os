#ifndef __SP_INTERRUPT_H
#define __SP_INTERRUPT_H


#include <stddef.h>

#include <types.h>
#include <common.h>

#include "config.h"

// typedef unsigned long       size_t;

/* Fix spelling error */
typedef struct __interrupt_operation{
	char dev_name[8]; 				/* interrupt devce name */
	size_t vector;					/* interrupt vector used to indentify interrupt */
	void (*device_config)();		/* user interrupt config function */
	void (*interrupt_handler)();	/* user interrupt handler function */
	void (*interrupt_handler_with_vector)(int vec);  /* user interrupt handler function vith parm */
} interrupt_operation;

#define SPINTC_IRQS		(32 * 7)

// Q628 SPINTC for ACHIP (A926: 0~199, DSP: 0~199)
// 9C000480
#define SPINTC_TYPE     RF_GRP(15,0)    //G9.0~6     - Type,      0: level-type, 1: edge-type
// 9C00049C
#define SPINTC_POLAR    RF_GRP(15,7)    //G9.7~13    - Polarity,  0: high-active, 1: low-active
// 9C0004B8
#define SPINTC_PRIO     RF_GRP(15,14)   //G9.14~20   - Priority,  0: fiq, 1: irq
// 9C0004D4
#define SPINTC_MASK     RF_GRP(15,21)   //G9.21~27   - Mask,      0: masked, 1: pass
// 9C000500
#define SPINTC_CLR      RF_GRP(21,0)   //G10.0~6    - Clear
// 9c00051C
#define SPINTC_MSKFIQ   RF_GRP(21,7)   //G10.7~13   - Read Masked FIQ
// 9c000538
#define SPINTC_MSKIRQ   RF_GRP(21,14)  //G10.14~20  - Read Masked IRQ

#define HAL_READ_UINT32( _register_, _value_ ) \
        ((_value_) = *((volatile unsigned int *)(_register_)))

#define HAL_WRITE_UINT32( _register_, _value_ ) \
        (*((volatile unsigned int *)(_register_)) = (_value_))

#ifdef THUMB_INTERWORK

	void vPortDisableInterruptsFromThumb( void ) __attribute__ ((naked));
	void vPortEnableInterruptsFromThumb( void ) __attribute__ ((naked));

	void vPortDisableInterruptsFromThumb( void )
	{
		asm volatile (
			"STMDB	SP!, {R0}		\n\t"	/* Push R0.									*/
			"MRS	R0, CPSR		\n\t"	/* Get CPSR.								*/
			"ORR	R0, R0, #0xC0	\n\t"	/* Disable IRQ, FIQ.						*/
			"MSR	CPSR, R0		\n\t"	/* Write back modified value.				*/
			"LDMIA	SP!, {R0}		\n\t"	/* Pop R0.									*/
			"BX		R14" );					/* Return back to thumb.					*/
	}

	void vPortEnableInterruptsFromThumb( void )
	{
		asm volatile (
			"STMDB	SP!, {R0}		\n\t"	/* Push R0.									*/
			"MRS	R0, CPSR		\n\t"	/* Get CPSR.								*/
			"BIC	R0, R0, #0xC0	\n\t"	/* Enable IRQ, FIQ.							*/
			"MSR	CPSR, R0		\n\t"	/* Write back modified value.				*/
			"LDMIA	SP!, {R0}		\n\t"	/* Pop R0.									*/
			"BX		R14" );					/* Return back to thumb.					*/
	}

#endif /* THUMB_INTERWORK */

#ifdef THUMB_INTERWORK

	// extern void vPortDisableInterruptsFromThumb( void ) __attribute__ ((naked));
	// extern void vPortEnableInterruptsFromThumb( void ) __attribute__ ((naked));

	#define portDISABLE_INTERRUPTS()	vPortDisableInterruptsFromThumb()
	#define portENABLE_INTERRUPTS()		vPortEnableInterruptsFromThumb()

#else

	#define portDISABLE_INTERRUPTS() do{prn_string("disable int\n");											\
		asm volatile (															\
			"STMDB	SP!, {R0}		\n\t"	/* Push R0.						*/	\
			"MRS	R0, CPSR		\n\t"	/* Get CPSR.					*/	\
			"ORR	R0, R0, #0xC0	\n\t"	/* Disable IRQ, FIQ.			*/	\
			"MSR	CPSR, R0		\n\t"	/* Write back modified value.	*/	\
			"LDMIA	SP!, {R0}			" )	/* Pop R0.						*/ ;prn_string("int disabled\n");}while(0)

	#define portENABLE_INTERRUPTS()	do{prn_string("enable int\n");											\
		asm volatile (															\
			"STMDB	SP!, {R0}		\n\t"	/* Push R0.						*/	\
			"MRS	R0, CPSR		\n\t"	/* Get CPSR.					*/	\
			"BIC	R0, R0, #0xC0	\n\t"	/* Enable IRQ, FIQ.				*/	\
			"MSR	CPSR, R0		\n\t"	/* Write back modified value.	*/	\
			"LDMIA	SP!, {R0}			" )	/* Pop R0.						*/ ;prn_string("int enabled\n");}while(0)

#endif /* THUMB_INTERWORK */

#define isrSAVE_CONTEXT()												\
{																		\
	asm volatile (														\
		"SUB LR, LR, #4 										\n\t"	\
		"STMFD SP!, {R0-R12, LR}								\n\t"	\
		);																\
}

#define isrRESTORE_CONTEXT()											\
{																		\
	asm volatile(														\
		"LDMFD SP!, {R0-R12, PC}^								\n\t"	\
		);																\
}

/* invoked by interrupt manager module */
void sp_interrupt_setup();

/* invoked by interrupt manager module */
void sp_interrupt_disable();

/* invoked by interrupt driver */
int interrupt_register(interrupt_operation *int_opt);

/* invoked by interrupt driver */
int interrupt_unregister(interrupt_operation *int_opt);

void hal_interrupt_configure(int vector, int level, int up);
void hal_interrupt_unmask(int vector);
void hal_interrupt_mask(int vector);
void hal_interrupt_acknowledge(int vector);

/*
 * Timers definition
 */
#define RF_TIMER_SRC_STC				(1 << 14)
#define RF_TIMER_SRC_RTC				(2 << 14)
#define RF_TIMER_SRC_TIMER				(3 << 14)
#define RF_TIMER_RUN_ON					(1 << 13)
#define RF_TIMER_RUN_OFF				(0 << 13)
#define RF_TIMER_GO_ON					(1 << 11)
#define RF_TIMER_GO_OFF					(0 << 11)
#define RF_TIMER_MASK					(0x3ff)
#define TIMER_CONFIG_STOP				(RF_TIMER_GO_OFF)
#define TIMER_CONFIG_STC				(RF_TIMER_SRC_STC      \
										| RF_TIMER_RUN_ON      \
										| RF_TIMER_GO_ON)


static inline void *int_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char* pdest = (unsigned char*)dest;
    unsigned char* psrc = (unsigned char*)src;

	while(n--){
        *pdest++ = *psrc++;
    }

	return dest;
}

#endif
/* end def sp_interrupt.h */
