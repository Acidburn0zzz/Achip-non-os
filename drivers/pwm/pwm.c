#include "common_all.h"
#include "monitor.h"
#include <stdarg.h>
#include <string.h>
#include "drivers/pwm.h"

#define MOON244_REG ((volatile struct moon244_regs *)RF_GRP(244, 0))

#define PWM_DEBUG

#ifdef PWM_DEBUG
#define pwm_printf	printf
#else
#define pwm_printf(s ...)
#endif

void pwm_enable(int pwm_num)
{
	if(pwm_num >= ePWM_MAX)
		return;
	MOON244_REG->pwm_bypass &= ~(1<<pwm_num); //bypass disable
	MOON244_REG->pwm_en |= 1<<pwm_num; // set pwm0 enable
}

void pwm_disable(int pwm_num)
{
	if(pwm_num >= ePWM_MAX)
		return;
	MOON244_REG->pwm_bypass &= ~(1<<pwm_num);//bypass disable
	MOON244_REG->pwm_en &= ~(1<<pwm_num); //  pwm0 disable
}

void pwm_pinmux_set(int pwm_num,int gpio_pin)
{
	int quotients = pwm_num/2;
	int remainder = pwm_num%2;
	if(remainder==0)
		MOON2_REG->sft_cfg[14+quotients] |= RF_MASK_V((0x3f), gpio_pin); 
	else
		MOON2_REG->sft_cfg[14+quotients] |= RF_MASK_V((0x3f<<8), (gpio_pin<<8)); 
}

static void pwm_reg_init(void)
{
	MOON244_REG->grp244_0 = 0x0000;
	MOON244_REG->grp244_1 = 0x0f00;
	MOON244_REG->pwm_dd[0].idx_all = 0x0000;
	MOON244_REG->pwm_dd[1].idx_all = 0x0000;
	MOON244_REG->pwm_dd[2].idx_all = 0x0000;
	MOON244_REG->pwm_dd[3].idx_all = 0x0000;
	MOON244_REG->pwm_du[0].idx_all = 0x0000;
	MOON244_REG->pwm_du[1].idx_all = 0x0000;
	MOON244_REG->pwm_du[2].idx_all = 0x0000;
	MOON244_REG->pwm_du[3].idx_all = 0x0000;
	MOON244_REG->pwm_du[4].idx_all = 0x0000;
	MOON244_REG->pwm_du[5].idx_all = 0x0000;
	MOON244_REG->pwm_du[6].idx_all = 0x0000;
	MOON244_REG->pwm_du[7].idx_all = 0x0000;
}


static int get_available_new_dd(int pwm_num,u32 dd_freq)
{
    int i;
    u32 tmp2;
  	int dd_sel_new = ePWM_DD_MAX,dd_sel_old = ePWM_DD_MAX;

  	if (MOON244_REG->grp244_1 & (1 << pwm_num))
		dd_sel_old = MOON244_REG->pwm_du[pwm_num].pwm_du_dd_sel;
	else
		dd_sel_old = ePWM_DD_MAX;
/* find the same freq and turnon clk source */
	for (i = 0; i < ePWM_DD_MAX; ++i) {
		if ((MOON244_REG->grp244_1 & (1 << i))
			&& (MOON244_REG->pwm_dd[i].dd == dd_freq))
			break;
	}
	if (i != ePWM_DD_MAX)
		dd_sel_new = i;

	/* dd_sel only myself used */
	if (dd_sel_new == ePWM_DD_MAX) {
		for (i = 0; i < ePWM_MAX; ++i) {
			if (i == pwm_num)
				continue;

			tmp2 = MOON244_REG->pwm_du[i].pwm_du_dd_sel;
			if ((MOON244_REG->grp244_1 & (1 << i))
					&& (tmp2 == dd_sel_old))
				break;
		}
		if (i == ePWM_MAX)
			dd_sel_new = dd_sel_old;
	}

	/* find unused clk source */
	if (dd_sel_new == ePWM_DD_MAX) {
		for (i = 0; i < ePWM_DD_MAX; ++i) {
			if (!(MOON244_REG->grp244_1 & (1 << i)))
				break;
		}
		dd_sel_new = i;
	}

	if (dd_sel_new == ePWM_DD_MAX) {
		return -1;
	}

	if ((dd_sel_old != dd_sel_new) && (dd_sel_old != ePWM_DD_MAX))
		MOON244_REG->grp244_1 &= ~(1 << dd_sel_old);

	return dd_sel_new;
}

static int init_flag = 0;
/*frequency = (1 / sys clk * PWM DD0(16bit)) * 256    freq = 12Hz~791Khz*/

int pwm_set_by_period(int pwm_num,u32 period_ns,u32 duty_ns)
{
	u32 dd_sel_new = ePWM_DD_MAX;
	u32 duty = 0, dd_freq = 0x80;
	u32 tmp2;
	u64 tmp;
	int i;

	if(init_flag == 0)
	{
		pwm_reg_init();
		init_flag = 1;
	}
	if (pwm_num > ePWM_MAX)
		return -1;

	duty_ns = (duty_ns > period_ns)?period_ns:duty_ns;

	tmp = 202500000 * (u64)period_ns+(256000000000ULL >> 1);
	dd_freq = (u32)(tmp/256000000000ULL);

	pwm_printf("set pwm:%d period_ns %d source clk rate:%llu duty_freq:0x%x(%d)\n",pwm_num, period_ns,tmp, dd_freq, dd_freq);

	if (dd_freq == 0)
		return -1;

	dd_sel_new = get_available_new_dd(pwm_num,dd_freq);

	if(dd_sel_new == -1){
		pwm_printf("pwm%d Can't found clk source[0x%x(%d)/256].\n",pwm_num, dd_freq, dd_freq);
		return -1;
	}

	MOON244_REG->grp244_1 |= (1 << dd_sel_new);
	MOON244_REG->pwm_dd[dd_sel_new].dd = dd_freq;

	pwm_printf("%s:%d found clk source:%d and set [0x%x(%d)/256]\n",__func__, __LINE__, dd_sel_new, dd_freq, dd_freq);

	if (duty_ns == period_ns) {
		MOON244_REG->pwm_bypass |= (1 << pwm_num);
		pwm_printf("%s:%d set pwm:%d bypass duty\n",__func__, __LINE__, pwm_num);
	} else {
		MOON244_REG->pwm_bypass &= ~(1 << pwm_num);

		tmp = (u64)duty_ns * 256 + (period_ns >> 1);
		duty = (u32)(tmp/(u32)period_ns);
		pwm_printf("%s:%d set pwm:%d duty:0x%x(%d)\n",__func__, __LINE__, pwm_num, duty, duty);

		MOON244_REG->pwm_du[pwm_num].pwm_du = duty;
		MOON244_REG->pwm_du[pwm_num].pwm_du_dd_sel = dd_sel_new;
	}

	pwm_printf("%s:%d pwm:%d, output freq:%lu Hz, duty:%u \n\n",__func__, __LINE__,
			pwm_num, 202500000 / (dd_freq * 256),(duty * 100) / 256);

	return 0;
}

/******************************************
* pwm_num : pwm0~pwm7 (0--7)
* freq_hz: freq set.unit HZ.
* duty : pwm duty.high level period.  (0--255)
******************************************/

int pwm_set_by_freq(int pwm_num,u32 freq_hz,u32 duty)
{

	u32 period_ns = 1000000000/freq_hz;
	u32 pwm_duty = duty;

	u64 tmp = (u64)(pwm_duty*(u64)period_ns);
	u32	duty_ns = (u32)((u64)tmp/256);
	
	pwm_printf("tmp=%lld set pwm:%d freq_hz:%d duty:%d period_ns:%ld duty_ns:(%llu)\n",tmp,pwm_num, freq_hz,duty,period_ns, duty_ns);
	pwm_set_by_period(pwm_num,period_ns,duty_ns);
	return 0;
}

