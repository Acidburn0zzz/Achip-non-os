#include <config.h>

//#define RF_GRP(group, reg)  ((4 * (group * 32 + reg)) + REG_BASE)

#define REGS0(addr, value) \
  ldr r0 , =value    ;     \
  ldr r1 , =addr     ;     \
  str r0 , [r1, #0]  ;

#define LDREG(addr, reg) \
  ldr r1 , =addr    ;    \
  ldr reg, [r1, #0] ;

#define STREG(addr, reg) \
  ldr r1 , =addr    ;    \
  str reg, [r1, #0] ;

#define STAMP(value) REGS0(RF_GRP(  0,  0), value)

#define UART0_WAIT                  \
100:                                \
    LDREG(RF_GRP(18, 1), r0);       \
    add r0, #1;  		            \
    cmp r0, #0;                     \
    beq 100b;

#define UART0_PUTC(value)           \
    ldr r0, =value;                 \
	UART0_WAIT;						\
    STREG(RF_GRP(18, 0), r0);       \

#define UART0_PUTCNL                        \
    UART0_PUTC(0x0D);                       \
    UART0_PUTC(0x0A);

#define DBG(value1, value2, value3, value4) \
    UART0_PUTC(value1);                     \
    UART0_PUTC(value2);                     \
    UART0_PUTC(value3);                     \
    UART0_PUTC(value4);                     \
    UART0_PUTCNL;                           \

#define PUTA0_0                 \
    and r0, r0, #0xF;           \
    cmp r0, #10;                \
    bcs 100f;                   \
    add r0, r0, #48;            \
    b 101f;                     \
100:                            \
    add r0, r0, #55;            \
101:                            \
    STREG(RF_GRP(18, 0), r0);

 #define PUTA                    \
     lsr r0, r12, #28; PUTA0_0;  \
     lsr r0, r12, #24; PUTA0_0;  \
     lsr r0, r12, #20; PUTA0_0;  \
     lsr r0, r12, #16; PUTA0_0;  \
     lsr r0, r12, #12; PUTA0_0;  \
     lsr r0, r12, #8; PUTA0_0;   \
     lsr r0, r12, #4; PUTA0_0;   \
     lsr r0, r12, #0; PUTA0_0;   \
     UART0_PUTCNL;

