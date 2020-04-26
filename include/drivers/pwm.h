#ifndef PWM_H_
#define PWM_H_

#define PWM_GPIO_PIN_OUT(m,n)	((m-1)*8+n+1)

enum {
	ePWM0=0,
	ePWM1,
	ePWM2,
	ePWM3,
	ePWM4,
	ePWM5,
	ePWM6,
	ePWM7,
	ePWM_MAX
};

enum {
	ePWM_DD0=0,
	ePWM_DD1,
	ePWM_DD2,
	ePWM_DD3,
	ePWM_DD_MAX
};

#define STATIC_ASSERT(b) extern int _static_assert[b ? 1 : -1]

struct _PWM_DD_REG_ {
	union {
		struct {
			u32 dd					:16;//b(0-15)
			u32 :16;
		};
		u32 idx_all;
	};
};
STATIC_ASSERT(sizeof(struct _PWM_DD_REG_) == 4);

struct _PWM_DU_REG_ {
	union {
		struct {
			u32 pwm_du				:8;	//b(0-7)
			u32 pwm_du_dd_sel		:2;	//b(8-9)
			u32						:6;	//b(10-15)
			u32 :16;
		};
		u32 idx_all;
	};
};
STATIC_ASSERT(sizeof(struct _PWM_DU_REG_) == 4);

struct moon244_regs {
	//GROUP 244
	union {
		struct {
			u32 pwm_en				:8;	//b(0-7)
			u32 pwm_bypass			:8;	//b(8-15)
			u32 :16;
		};
		u32 grp244_0;
	};
	union {
		struct {
			u32 pwm_cnt0_en			:1;	//b(0)
			u32 pwm_cnt1_en			:1;	//b(1)
			u32 pwm_cnt2_en			:1;	//b(2)
			u32 pwm_cnt3_en			:1;	//b(3)
			u32 pwm_clk54_en		:1;	//b(4)
			u32						:3;	//b(5-7)
			u32 pwm_dd0_sync_off	:1;	//b(8)
			u32 pwm_dd1_sync_off	:1;	//b(9)
			u32 pwm_dd2_sync_off	:1;	//b(10)
			u32 pwm_dd3_sync_off	:1;	//b(11)
			u32						:4;	//b(12-15)
			u32 :16;
		};
		u32 grp244_1;
	};
	struct _PWM_DD_REG_ pwm_dd[4];		//G244.2~5
	struct _PWM_DU_REG_ pwm_du[8];		//G244.6~13
	u32 grp244_14_31[18];
};


void pwm_enable(int pwm_num);
void pwm_disable(int pwm_num);
int pwm_set_by_freq(int pwm_num,u32 freq_hz,u32 duty);
int pwm_set_by_period(int pwm_num,u32 period_ns,u32 duty_ns);
void pwm_pinmux_set(int pwm_num,int gpio_pin);  // set pwm pinmux
#endif