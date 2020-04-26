#ifndef __STC_INC_H_
#define __STC_INC_H_

#include <types.h>

#define TIMER_KHZ           90
#define XTAL_CLK               (27 * 1000 * 1000)

void STC_init(void);
void STC_restart(void);
u32 STC_Get32(void);

void STC_delay_ticks(u32 ticks); /* 1 tick = 11.11 us */
void STC_delay_1ms(u32 msec);    /* max = 728 ms */
void STC_delay_us(u32 usec);     /* min = 11.11 us, max 728 ms */
u32 STC_get_timer(u32 base);

void AV1_STC_init(void);
u32 AV1_GetStc32(void);

#endif

