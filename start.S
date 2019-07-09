#include <config.h>
#include <asm/link.h>
#include <asm/common.h>

#define STACK_SIZE 8*1024

.equ _ISR_STARTADDRESS, STACK_SRAM
.equ UserStack, _ISR_STARTADDRESS
.equ SVCStack, UserStack-STACK_SIZE
.equ UndefStack, SVCStack-STACK_SIZE
.equ AbortStack, UndefStack-STACK_SIZE
.equ IRQStack, AbortStack-STACK_SIZE
.equ FIQStack, IRQStack-STACK_SIZE

.equ USERMODE, 0x10
.equ FIQMODE, 0x11
.equ IRQMODE, 0x12
.equ SVCMODE, 0x13
.equ ABORTMODE, 0x17
.equ UNDEFMODE, 0x1B
.equ SYSMODE, 0x1F
.equ MODEMASK, 0x1F

.global _start
_start:
     MRS R0, CPSR
     BIC R0, R0, #MODEMASK

     #设置用户模式下的SP
     ORR R1, R0, #SYSMODE
     MSR CPSR_c, R1
     LDR SP, =UserStack

     #设置未定义模式下的SP
     ORR R1, R0, #UNDEFMODE
     MSR CPSR_c, R1
     LDR SP, =UndefStack

     #设置终止模式下的SP
     ORR R1, R0, #ABORTMODE
     MSR CPSR_c, R1
     LDR SP, =AbortStack

     #设置IRQ模式下的SP
     ORR R1, R0, #IRQMODE
     MSR CPSR_c, R1
     LDR SP, =IRQStack

     #设置FIQ模式下的SP
     ORR R1, R0, #FIQMODE
     MSR CPSR_c, R1
     LDR SP, =FIQStack

     #设置管理模式下的SP
     ORR R1, R0, #SVCMODE
     MSR CPSR_c, R1
     LDR SP, =SVCStack

     mcr p15, 0, r0, c8, c7, 0   /* invalidate TLB */
     mcr p15, 0, r0, c7, c5, 0   /* invalidate I Cache */

    /*
     * disable MMU and D cache
     * enable I cache
     */
    mrc p15, 0, r0, c1, c0, 0
    bic r0, r0, #0x00000300 /* clear bits 9:8 (---- --RS) */
    bic r0, r0, #0x00000087 /* clear bits 7, 2:0 (B--- -CAM) */
    bic r0, r0, #0x00002000 /* clear bit 13 (--V- ----) */
    orr r0, r0, #0x00000002 /* set bit 2 (A) Align */
    orr r0, r0, #0x00001000 /* set bit 12 (I) I-Cache */
    mcr p15, 0, r0, c1, c0, 0

	/*
	 * Zero BSS
	 */
    ldr r0, =__bss_start
    ldr r1, =__bss_end__
    mov r2, #0x00000000
clbss_l:
    cmp r0, r1          /* clear loop... */
    bhs clbss_e         /* if reached end of bss, exit */
    str r2, [r0]
    add r0, r0, #4
    b   clbss_l
clbss_e:

	bl main

