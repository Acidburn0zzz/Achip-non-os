/********************************************************
 * Copyright (c) 2015 by Sunplus Technology Co., Ltd.
 *    ____               __
 *   / __/_ _____  ___  / /_ _____
 *  _\ \/ // / _ \/ _ \/ / // (_-<
 * /___/\_,_/_//_/ .__/_/\_,_/___/
 *              /_/
 * Sunplus Technology Co., Ltd.19, Innovation First Road,
 * Science-Based Industrial Park, Hsin-Chu, Taiwan, R.O.C.
 * ------------------------------------------------------
 * Description  : Regmap for 8388.
 * Create Date  : 2015-12-08 18:51:11
 */
#ifndef __8388_REGMAP_ALL_H__
#define __8388_REGMAP_ALL_H__

/**
 *  [dv]  : default value,
 *  [des] : description,
 */


typedef struct
{
    // GROUP 0 [moon]
    unsigned stamp;                                /* < 0> [dv: 0x00000630] [des: HD STB Chip Revision Stamp Register ] */
    unsigned reserved_0;                              /* < 1> [dv: 0x00000000] [des: Reserved ] */
    unsigned reserved_1;                              /* < 2> [dv: 0x00000000] [des: Reserved ] */
    unsigned reserved_2;                              /* < 3> [dv: 0x00000000] [des: Reserved ] */
    unsigned mo_clk_sel0;                             /* < 4> [dv: 0x00000000] [des: Clock Setting and Selection Register \#0 ] */
    unsigned mo_clk_sel1;                             /* < 5> [dv: 0x00000000] [des: Clock Setting and Selection Register \#1 ] */
    unsigned mo_pllsys_cfg_sel;                       /* < 6> [dv: 0x1a40c2e4] [des: PLLSYS Configuration Register ] */
    unsigned clken[5];
    // unsigned mo_clken0;                               /* < 7> [dv: 0xffffffff] [des: Clock Enable Register \#0] */
    // unsigned mo_clken1;                               /* < 8> [dv: 0xffffffff] [des: Clock Enable Register \#1] */
    // unsigned mo_clken2;                                < 9> [dv: 0xffffffff] [des: Clock Enable Register \#2]
    // unsigned mo_clken3;                               /* <10> [dv: 0xffffffff] [des: Clock Enable Register \#3] */
    // unsigned mo_clken4;                               /* <11> [dv: 0xfffff7ff] [des: Clock Enable Register \#4] */
    unsigned gclken[5];
    // unsigned mo_gclken0;                              /* <12> [dv: 0xffffffbf] [des: Clock Gating Enable Register \#0] */
    // unsigned mo_gclken1;                              /* <13> [dv: 0xffffffff] [des: Clock Gating Enable Register \#1] */
    // unsigned mo_gclken2;                               <14> [dv: 0xffffffff] [des: Clock Gating Enable Register \#2]
    // unsigned mo_gclken3;                              /* <15> [dv: 0xffffffff] [des: Clock Gating Enable Register \#3] */
    // unsigned mo_gclken4;                              /* <16> [dv: 0xffffffff] [des: Clock Gating Enable Register \#4] */
    unsigned reset[5];
    // unsigned mo_reset0;                               /* <17> [dv: 0xfffffeaa] [des: Hardware Reset Control Register \#0] */
    // unsigned mo_reset1;                               /* <18> [dv: 0xdffffffd] [des: Hardware Reset Control Register \#1] */
    // unsigned mo_reset2;                                <19> [dv: 0xffffffff] [des: Hardware Reset Control Register \#2]
    // unsigned mo_reset3;                               /* <20> [dv: 0xffefffff] [des: Hardware Reset Control Register \#3] */
    // unsigned mo_reset4;                               /* <21> [dv: 0xfffffcff] [des: Hardware Reset Control Register \#4] */
    unsigned reserved_3;                              /* <22> [dv: 0x00000000] [des: Reserved ] */
    unsigned reserved_4;                              /* <23> [dv: 0x00000000] [des: Reserved ] */
    unsigned reserved_5;                              /* <24> [dv: 0x00000000] [des: Reserved ] */
    unsigned reserved_6;                              /* <25> [dv: 0x00000000] [des: Reserved ] */
    unsigned reserved_7;                              /* <26> [dv: 0x00000000] [des: Reserved ] */
    unsigned reserved_8;                              /* <27> [dv: 0x00000000] [des: Reserved ] */
    unsigned mo_hw_cfg;                               /* <28> [dv:  0x0007f1f] [des: Hardware configuration ] */
    unsigned mo_sfg_cfg_func;                         /* <29> [dv: 0x00000001] [des: SFT configuration Function ] */
    unsigned reserved_9;                              /* <30> [dv: 0x00000000] [des: reserved ] */
    unsigned reserved_10;                             /* <31> [dv: 0x00000000] [des: reserved ] */
    // GROUP 1 [moon_1]
    unsigned sft_cfg_0;                               /* < 0> [dv: 0x00000000] [des: TEST Mode Pin MUX Control Register ] */
    unsigned sft_cfg_1;                               /* < 1> [dv: 0x00000011] [des: PIN Mux Table Control Register \#1] */
    unsigned sft_cfg_2;                               /* < 2> [dv:        0x0] [des: PIN Mux Table Control Register \#2] */
    unsigned sft_cfg_3;                               /* < 3> [dv:        0x0] [des: PIN Mux Table Control Register \#3] */
    unsigned sft_cfg_4;                               /* < 4> [dv:        0x0] [des: PIN Mux Table Control Register \#4] */
    unsigned sft_cfg_5;                               /* < 5> [dv:        0x0] [des: PIN Mux Table Control Register \#5] */
    unsigned sft_cfg_6;                               /* < 6> [dv:        0x0] [des: PIN Mux Table Control Register \#6] */
    unsigned sft_cfg_7;                               /* < 7> [dv:        0x0] [des: PIN Mux Table Control Register \#7] */
    unsigned sft_cfg_8;                               /* < 8> [dv:        0x0] [des: PIN Mux Table Control Register \#8] */
    unsigned sft_cfg_9;                               /* < 9> [dv:        0x0] [des: PIN Mux Table Control Register \#9] */
    unsigned sft_cfg_10;                              /* <10> [dv: 0x00010000] [des: Miscellaneous Pin MUX Control Register - 0 ] */
    unsigned sft_cfg_11;                              /* <11> [dv: 0x00000000] [des: LVDSTX Control Register] */
    unsigned sft_cfg_12;                              /* <12> [dv: 0x00000001] [des: CA9 Control Register ] */
    unsigned sft_cfg_13;                              /* <13> [dv: 0x014fffff] [des: Default Vaule for MO_DRAM_A_SIZE, MO_DRAM_B_SIZE] */
    unsigned sft_cfg_14;                              /* <14> [dv: 0x80000002] [des: USB0 PHY Configuration 0  ] */
    unsigned sft_cfg_15;                              /* <15> [dv: 0x80000004] [des: USB1 PHY Configuration 0  ] */
    unsigned sft_cfg_16;                              /* <16> [dv: 0x0f000000] [des: Video DAC Configuration  ] */
    unsigned sft_cfg_17;                              /* <17> [dv: 0x00000020] [des: THERMAL Control  ] */
    unsigned sft_cfg_18;                              /* <18> [dv: 0x80000006] [des: USB2 PHY Configuration 0  ] */
    unsigned sft_cfg_19;                              /* <19> [dv: 0x00040404] [des: USB 0/1/2 PHY Configuration 1  ] */
    unsigned sft_cfg_20;                              /* <20> [dv: 0x04000000] [des: USB 0/1/2 PHY Status 0] */
    unsigned sft_cfg_21;                              /* <21> [dv: 0x00000000] [des: USB 0/1/2 PHY Control 0] */
    unsigned sft_cf_22;                               /* <22> [dv:        0x0] [des: CPU Debug Interface Control Register] */
    unsigned sft_cfg_23;                              /* <23> [dv:        0x0] [des: Reserved  ] */
    unsigned sft_cfg_24;                              /* <24> [dv: 0x6138b022] [des: PLLTV \& PLLA Configuration 0  ] */
    unsigned sft_cfg_25;                              /* <25> [dv: 0x00449cc8] [des: PLLC2(A926) Configuration  ] */
    unsigned sft_cfg_26;                              /* <26> [dv: 0x001a4a00] [des: PLLDIS Configuration 0  ] */
    unsigned sft_cfg_27;                              /* <27> [dv: 0x55a00080] [des: PLLDIS Configuration 1  ] */
    unsigned sft_cfg_28;                              /* <28> [dv: 0x02449500] [des: PLLC1(CA9) Configuration  ] */
    unsigned sft_cfg_29;                              /* <29> [dv: 0xdf1f87c0] [des: PLLH Configuration 0  ] */
    unsigned sft_cfg_30;                              /* <30> [dv: 0x00055514] [des: PLLH Configuration 1  ] */
    unsigned sft_cfg_31;                              /* <31> [dv:        0x0] [des: Reserved] */
    // GROUP 2 [moon_2]
    unsigned sft_cfg_0_1;                             /* < 0> [dv: 0x22222222] [des: AADC GPIO Control Register \#0] */
    unsigned sft_cfg_1_1;                             /* < 1> [dv: 0x00002222] [des: AADC GPIO Control Register \#1] */
    unsigned sft_cfg_2_1;                             /* < 2> [dv:        0x0] [des: UPHY0 OTP Trim Control Register] */
    unsigned sft_cfg_3_1;                             /* < 3> [dv: 0x00003030] [des: USB Controller Control Register] */
    unsigned sft_cfg_4_1;                             /* < 4> [dv: 0xa14bbb49] [des: SPDIF PLL Control Register \#0] */
    unsigned sft_cfg_5_1;                             /* < 5> [dv: 0x92069206] [des: SPDIF PLL Control Register \#1] */
    unsigned sft_cfg_6_1;                             /* < 6> [dv: 0x91069e47] [des: SPDIF PLL Control Register \#2] */
    unsigned sft_cfg_7_1;                             /* < 7> [dv:        0x0] [des: SPDIF PLL Control Register \#3] */
    unsigned sft_cfg_8_1;                             /* < 8> [dv: 0x00000040] [des: Servo GPIO Control Register] */
    unsigned sft_cfg_9_1;                             /* < 9> [dv:        0x0] [des: DAC Control Register] */
    unsigned sft_cfg_10_1;                            /* <10> [dv:        0x0] [des: DISP PROBL Selection Register] */
    unsigned sft_cfg_11_1;                            /* <11> [dv: 0x00022222] [des: ADAC GPIO Control Register] */
    unsigned sft_cfg_12_1;                            /* <12> [dv:        0x1] [des: GC520(GPU) Control Register] */
    unsigned sft_cfg_13_1;                            /* <13> [dv: 0x00000006] [des: Servo Control Register] */
    unsigned sft_cfg_14_1;                            /* <14> [dv:        0x0] [des: Reserved] */
    unsigned sft_cfg_15_1;                            /* <15> [dv:        0x0] [des: Reserved] */
    unsigned sft_cfg_16_1;                            /* <16> [dv:        0x0] [des: Reserved] */
    unsigned sft_cfg_17_1;                            /* <17> [dv:        0x0] [des: Reserved] */
    unsigned sft_cfg_18_1;                            /* <18> [dv:        0x0] [des: Reserved] */
    unsigned sft_cfg_19_1;                            /* <19> [dv:        0x0] [des: Reserved] */
    unsigned sft_cfg_20_1;                            /* <20> [dv:        0x0] [des: Reserved] */
    unsigned sft_cfg_21_1;                            /* <21> [dv:        0x0] [des: Reserved] */
    unsigned sft_cfg_22;                              /* <22> [dv:        0x0] [des: Reserved] */
    unsigned sft_cfg_23_1;                            /* <23> [dv:        0x0] [des: Reserved] */
    unsigned sft_cfg_24_1;                            /* <24> [dv:        0x0] [des: Reserved] */
    unsigned sft_cfg_25_1;                            /* <25> [dv:        0x0] [des: Reserved] */
    unsigned sft_cfg_26_1;                            /* <26> [dv:        0x0] [des: Reserved] */
    unsigned sft_cfg_27_1;                            /* <27> [dv:        0x0] [des: Reserved] */
    unsigned sft_cfg_28_1;                            /* <28> [dv:        0x0] [des: Reserved] */
    unsigned sft_cfg_29_1;                            /* <29> [dv:        0x0] [des: Reserved] */
    unsigned sft_cfg_30_1;                            /* <30> [dv:        0x0] [des: Reserved] */
    unsigned sft_cfg_31_1;                            /* <31> [dv:        0x0] [des: Reserved] */
    // GROUP 3
    unsigned grp3_reserved[32];
    // GROUP 4 [pad_ctl]
    unsigned pad_ctrl_reg0;                           /* < 0> [dv: 0x00000000] [des: PAD control register \#0 ] */
    unsigned pad_ctrl_reg1;                           /* < 1> [dv: 0x00000000] [des: PAD control register \#1 ] */
    unsigned pad_ctrl_reg2;                           /* < 2> [dv: 0x00000000] [des: PAD control register \#2 ] */
    unsigned pad_ctrl_reg3;                           /* < 3> [dv: 0x00000000] [des: PAD control register \#3 ] */
    unsigned pad_ctrl_reg4;                           /* < 4> [dv: 0x00000000] [des: PAD control register \#4 ] */
    unsigned sft_cfg_reg5;                            /* < 5> [dv: 0x00000000] [des: Reserved ] */
    unsigned sft_cfg_reg6;                            /* < 6> [dv: 0x00000000] [des: Reserved ] */
    unsigned sft_cfg_reg7;                            /* < 7> [dv: 0x00000000] [des: Reserved ] */
    unsigned sft_cfg_reg8;                            /* < 8> [dv: 0x00000000] [des: Reserved ] */
    unsigned sft_cfg_reg9;                            /* < 9> [dv: 0x00000000] [des: Reserved ] */
    unsigned pad_ctrl_reg5;                           /* <10> [dv: 0x00000000] [des: PAD control register \#5 ] */
    unsigned pad_ctrl_reg6;                           /* <11> [dv: 0x00000000] [des: PAD control register \#6 ] */
    unsigned pad_ctrl_reg7;                           /* <12> [dv: 0x00000000] [des: PAD control register \#7 ] */
    unsigned pad_ctrl_reg8;                           /* <13> [dv: 0x00000000] [des: PAD control register \#8 ] */
    unsigned pad_ctrl_reg9;                           /* <14> [dv: 0x00000000] [des: PAD control register \#9 ] */
    unsigned sft_cfg_reg15;                           /* <15> [dv: 0x00000000] [des: Reserved ] */
    unsigned sft_cfg_reg16;                           /* <16> [dv: 0x00000000] [des: Reserved ] */
    unsigned sft_cfg_reg17;                           /* <17> [dv: 0x00000000] [des: Reserved ] */
    unsigned sft_cfg_reg18;                           /* <18> [dv: 0x00000000] [des: Reserved ] */
    unsigned sft_cfg_reg19;                           /* <19> [dv: 0x00000000] [des: Reserved ] */
    unsigned spi_softpad_ctrl_reg0;                   /* <20> [dv: 0x3000000f] [des: SPI Softpad control register \#0 ] */
    unsigned sft_cfg_reg21;                           /* <21> [dv: 0x00000000] [des: Reserved ] */
    unsigned sft_cfg_reg22;                           /* <22> [dv: 0x00000000] [des: Reserved ] */
    unsigned sft_cfg_reg23;                           /* <23> [dv: 0x00000000] [des: Reserved ] */
    unsigned sft_cfg_reg24;                           /* <24> [dv: 0x00000000] [des: Reserved ] */
    unsigned gpio_first_control_register_0;           /* <25> [dv: 0x00000000] [des: GPIO FIRST Control Register \#0 ] */
    unsigned gpio_first_control_register_1;           /* <26> [dv: 0x00000000] [des: GPIO FIRST Control Register \#1 ] */
    unsigned gpio_first_control_register_2;           /* <27> [dv: 0x00000000] [des: GPIO FIRST Control Register \#2 ] */
    unsigned gpio_first_control_register_3;           /* <28> [dv: 0x00000000] [des: GPIO FIRST Control Register \#3 ] */
    unsigned gpio_first_control_register_4;           /* <29> [dv: 0x00000000] [des: GPIO FIRST Control Register \#4 ] */
    unsigned gpio_first_control_register_5;           /* <30> [dv: 0x00000000] [des: GPIO FIRST Control Register \#5 ] */
    unsigned sft_cfg_31_2;                            /* <31> [dv: 0x00000000] [des: Reserved] */
    // GROUP 5 [gpioxt]
    unsigned gpio_master_0;                           /* < 0> [dv: 0xffffffff] [des: Master of GPIO pin select \#0 ] */
    unsigned gpio_master_1;                           /* < 1> [dv: 0xffffffff] [des: Master of GPIO pin select \#1 ] */
    unsigned gpio_master_2;                           /* < 2> [dv: 0xffffffff] [des: Master of GPIO pin select \#2 ] */
    unsigned gpio_master_3;                           /* < 3> [dv: 0xffffffff] [des: Master of GPIO pin select \#3 ] */
    unsigned gpio_master_4;                           /* < 4> [dv: 0xffffffff] [des: Master of GPIO pin select \#4 ] */
    unsigned gpio_master_5;                           /* < 5> [dv: 0x07ffffff] [des: Master of GPIO pin select \#5 ] */
    unsigned reserved_0_1;                            /* < 6> [dv: 0x00000000] [des: Reserved] */
    unsigned reserved_1_1;                            /* < 7> [dv: 0x00000000] [des: Reserved ] */
    unsigned gpio_oe_0;                               /* < 8> [dv: 0x00000000] [des: GPIO direction select \#0 ] */
    unsigned gpio_oe_1;                               /* < 9> [dv: 0x00000000] [des: GPIO direction select \#1 ] */
    unsigned gpio_oe_2;                               /* <10> [dv: 0x00000000] [des: GPIO direction select \#2 ] */
    unsigned gpio_oe_3;                               /* <11> [dv: 0x00000000] [des: GPIO direction select \#3 ] */
    unsigned gpio_oe_4;                               /* <12> [dv: 0x00000000] [des: GPIO direction select \#4 ] */
    unsigned gpio_oe_5;                               /* <13> [dv: 0x00000000] [des: GPIO direction select \#5 ] */
    unsigned reserved_2_1;                            /* <14> [dv: 0x00000000] [des: Reserved ] */
    unsigned reserved_3_1;                            /* <15> [dv: 0x00000000] [des: Reserved ] */
    unsigned gpio_out_0;                              /* <16> [dv: 0x00000000] [des: GPIO output data (used when in output mode) \#0 ] */
    unsigned gpio_out_1;                              /* <17> [dv: 0x00000000] [des: GPIO output data (used when in output mode) \#1 ] */
    unsigned gpio_out_2;                              /* <18> [dv: 0x00000000] [des: GPIO output data (used when in output mode) \#2 ] */
    unsigned gpio_out_3;                              /* <19> [dv: 0x00000000] [des: GPIO output data (used when in output mode) \#3 ] */
    unsigned gpio_out_4;                              /* <20> [dv: 0x00000000] [des: GPIO output data (used when in output mode) \#4 ] */
    unsigned gpio_out_5;                              /* <21> [dv: 0x00000000] [des: GPIO output data (used when in output mode) \#5 ] */
    unsigned reserved_4_1;                            /* <22> [dv: 0x00000000] [des: Reserved ] */
    unsigned reserved_5_1;                            /* <23> [dv: 0x00000000] [des: Reserved ] */
    unsigned gpio_in_0;                               /* <24> [dv: 0x00000000] [des: GPIO input status port \#0 ] */
    unsigned gpio_in_1;                               /* <25> [dv: 0x00000000] [des: GPIO input status port \#1 ] */
    unsigned gpio_in_2;                               /* <26> [dv: 0x00000000] [des: GPIO input status port \#2 ] */
    unsigned gpio_in_3;                               /* <27> [dv: 0x00000000] [des: GPIO input status port \#3 ] */
    unsigned gpio_in_4;                               /* <28> [dv: 0x00000000] [des: GPIO input status port \#4 ] */
    unsigned gpio_in_5;                               /* <29> [dv: 0x00000000] [des: GPIO input status port \#5 ] */
    unsigned reserved_6_1;                            /* <30> [dv: 0x00000000] [des: Reserved ] */
    unsigned reserved_7_1;                            /* <31> [dv: 0x00000000] [des: Reserved ] */
    // GROUP 6
    unsigned grp6_reserved[32];
    // GROUP 7 [pad_ctl1]
    unsigned pad_ctrl_reg10;                          /* < 0> [dv: 0xffffffff] [des: PAD control register \#10 ] */
    unsigned pad_ctrl_reg11;                          /* < 1> [dv: 0xffffffff] [des: PAD control register \#11 ] */
    unsigned pad_ctrl_reg12;                          /* < 2> [dv: 0xffffffff] [des: PAD control register \#12 ] */
    unsigned pad_ctrl_reg13;                          /* < 3> [dv: 0xffffffff] [des: PAD control register \#13 ] */
    unsigned pad_ctrl_reg14;                          /* < 4> [dv: 0x0000007f] [des: PAD control register \#14 ] */
    unsigned sft_cfg_5_2;                             /* < 5> [dv:        0x0] [des: Reserved] */
    unsigned sft_cfg_6_2;                             /* < 6> [dv:        0x0] [des: Reserved] */
    unsigned sft_cfg_7_2;                             /* < 7> [dv:        0x0] [des: Reserved] */
    unsigned sft_cfg_8_2;                             /* < 8> [dv:        0x0] [des: Reserved] */
    unsigned sft_cfg_9_2;                             /* < 9> [dv:        0x0] [des: Reserved] */
    unsigned pad_ctrl_reg15;                          /* <10> [dv: 0x00000000] [des: PAD control register \#15 ] */
    unsigned pad_ctrl_reg16;                          /* <11> [dv: 0x00000000] [des: PAD control register \#16 ] */
    unsigned pad_ctrl_reg17;                          /* <12> [dv: 0x00000000] [des: PAD control register \#17 ] */
    unsigned pad_ctrl_reg18;                          /* <13> [dv: 0x00000000] [des: PAD control register \#18 ] */
    unsigned pad_ctrl_reg19;                          /* <14> [dv: 0x0000007e] [des: PAD control register \#19 ] */
    unsigned sft_cfg_15_2;                            /* <15> [dv:        0x0] [des: Reserved] */
    unsigned sft_cfg_16_2;                            /* <16> [dv:        0x0] [des: Reserved] */
    unsigned sft_cfg_17_2;                            /* <17> [dv:        0x0] [des: Reserved] */
    unsigned sft_cfg_18_2;                            /* <18> [dv:        0x0] [des: Reserved] */
    unsigned sft_cfg_19_2;                            /* <19> [dv:        0x0] [des: Reserved] */
    unsigned pad_ctrl_reg20;                          /* <20> [dv: 0x00000000] [des: PAD control register \#20 ] */
    unsigned pad_ctrl_reg21;                          /* <21> [dv: 0x00000000] [des: PAD control register \#21 ] */
    unsigned pad_ctrl_reg22;                          /* <22> [dv: 0x00000000] [des: PAD control register \#22 ] */
    unsigned pad_ctrl_reg23;                          /* <23> [dv: 0x00000000] [des: PAD control register \#23 ] */
    unsigned pad_ctrl_reg24;                          /* <24> [dv: 0x00000000] [des: PAD control register \#24 ] */
    unsigned sft_cfg_25_2;                            /* <25> [dv:        0x0] [des: Reserved] */
    unsigned sft_cfg_26_2;                            /* <26> [dv:        0x0] [des: Reserved] */
    unsigned sft_cfg_27_2;                            /* <27> [dv:        0x0] [des: Reserved] */
    unsigned sft_cfg_28_2;                            /* <28> [dv:        0x0] [des: Reserved] */
    unsigned sft_cfg_29_2;                            /* <29> [dv:        0x0] [des: Reserved] */
    unsigned sft_cfg_30_2;                            /* <30> [dv:        0x0] [des: Reserved] */
    unsigned sft_cfg_31_3;                            /* <31> [dv:        0x0] [des: Reserved] */
    // GROUP 8 [io_processor]
    unsigned iop_control;                             /* < 0> [dv:     0x6011] [des: IOP sub-system control] */
    unsigned grp8_reserved_0;                         /* < 1> */
    unsigned iop_bp;                                  /* < 2> [dv:     0xffff] [des: IOP instruction breakpoint] */
    unsigned iop_regsel;                              /* < 3> [dv:     0x0000] [des: IOP register select] */
    unsigned iop_regout;                              /* < 4> [dv:     0x0000] [des: IOP register value] */
    unsigned iop_memlimit;                            /* < 5> [dv:     0x00FF] [des: IOP memory limit] */
    unsigned iop_resume_pcl;                          /* < 6> [dv:     0x0000] [des: IOP store pc low 2byte for system resume] */
    unsigned iop_resume_pch;                          /* < 7> [dv:     0x0000] [des: IOP store pc high 2byte for system resume] */
    unsigned iop_data[12];
	//unsigned iop_data0;                               /* < 8> [dv:     0x0000] [des: IOP-RISC mailbox register 0] */
    //unsigned iop_data1;                               /* < 9> [dv:     0x0000] [des: IOP-RISC mailbox register 1] */
    //unsigned iop_data2;                               /* <10> [dv:     0x0000] [des: IOP-RISC mailbox register 2] */
    //unsigned iop_data3;                               /* <11> [dv:     0x0000] [des: IOP-RISC mailbox register 3] */
    //unsigned iop_data4;                               /* <12> [dv:     0x0000] [des: IOP-RISC mailbox register 4] */
    //unsigned iop_data5;                               /* <13> [dv:     0x0000] [des: IOP-RISC mailbox register 5] */
    //unsigned iop_data6;                               /* <14> [dv:     0x0000] [des: IOP-RISC mailbox register 6] */
    //unsigned iop_data7;                               /* <15> [dv:     0x0000] [des: IOP-RISC mailbox register 7] */
    //unsigned iop_data8;                               /* <16> [dv:     0x0000] [des: IOP-RISC mailbox register 8] */
    //unsigned iop_data9;                               /* <17> [dv:     0x0000] [des: IOP-RISC mailbox register 9] */
    //unsigned iop_data10;                              /* <18> [dv:     0x0000] [des: IOP-RISC mailbox register 10] */
    //unsigned iop_data11;                              /* <19> [dv:     0x0000] [des: IOP-RISC mailbox register 11] */
    unsigned iop_base_adr_l;                          /* <20> [dv:     0x0000] [des: IOP base address[31:16]] */
    unsigned iop_base_adr_h;                          /* <21> [dv:     0x0000] [des: IOP base address[15:0]] */
    unsigned memory_bridge_control;                   /* <22> [dv:     0x0000] [des: Memory bridge control] */
    unsigned iop_remap_adr_l;                         /* <23> [dv:     0x0000] [des: IOP remapping base address[15]] */
    unsigned iop_remap_adr_h;                         /* <24> [dv:     0x0000] [des: IOP remapping base address[31:16]] */
    unsigned iop_direct_adr;                          /* <25> [dv:     0x0000] [des: IOP direct address[15:0]] */
    unsigned grp8_reserved_1;                         /* <26> */
    unsigned grp8_reserved_2;                         /* <27> */
    unsigned grp8_reserved_3;                         /* <28> */
    unsigned grp8_reserved_4;                         /* <29> */
    unsigned grp8_reserved_5;                         /* <30> */
    unsigned grp8_reserved_6;                         /* <31> */
    // GROUP 9 [interrupt]
    unsigned intr_type_0;                             /* < 0> [dv: 0x8000025f] [des: Interrupt type register0] */
    unsigned intr_type_1;                             /* < 1> [dv: 0x08000004] [des: Interrupt type register1] */
    unsigned intr_type_2;                             /* < 2> [dv: 0x00000000] [des: Interrupt type register2] */
    unsigned intr_type_3;                             /* < 3> [dv: 0x0003c000] [des: Interrupt type register3] */
    unsigned intr_type_4;                             /* < 4> [dv: 0xff800000] [des: Interrupt type register4] */
    unsigned intr_type_5;                             /* < 5> [dv: 0xffc000ff] [des: Interrupt type register5] */
    unsigned intr_type_6;                             /* < 6> [dv: 0x000000ff] [des: Interrupt type register6] */
    unsigned intr_polarity_0;                         /* < 7> [dv:     0x0000] [des: Interrupt polarity register0] */
    unsigned intr_polarity_1;                         /* < 8> [dv:     0x0000] [des: Interrupt polarity register1] */
    unsigned intr_polarity_2;                         /* < 9> [dv:     0x0000] [des: Interrupt polarity register2] */
    unsigned intr_polarity_3;                         /* <10> [dv:     0x0000] [des: Interrupt polarity register3] */
    unsigned intr_polarity_4;                         /* <11> [dv:     0x0000] [des: Interrupt polarity register4] */
    unsigned intr_polarity_5;                         /* <12> [dv:     0x0000] [des: Interrupt polarity register5] */
    unsigned intr_polarity_6;                         /* <13> [dv:     0x0000] [des: Interrupt polarity register6] */
    unsigned a926_priority_0;                         /* <14> [dv:     0x0000] [des: ARM926 priority register0] */
    unsigned a926_priority_1;                         /* <15> [dv:     0x0000] [des: ARM926 priority register1] */
    unsigned a926_priority_2;                         /* <16> [dv:     0x0000] [des: ARM926 priority register2] */
    unsigned a926_priority_3;                         /* <17> [dv:     0x0000] [des: ARM926 priority register3] */
    unsigned a926_priority_4;                         /* <18> [dv:     0x0000] [des: ARM926 priority register4] */
    unsigned a926_priority_5;                         /* <19> [dv:     0x0000] [des: ARM926 priority register5] */
    unsigned a926_priority_6;                         /* <20> [dv:     0x0000] [des: ARM926 priority register6] */
    unsigned a926_intr_mask_0;                        /* <21> [dv:     0x0000] [des: ARM926 interrupt mask register0] */
    unsigned a926_intr_mask_1;                        /* <22> [dv:     0x0000] [des: ARM926 interrupt mask register1] */
    unsigned a926_intr_mask_2;                        /* <23> [dv:     0x0000] [des: ARM926 interrupt mask register2] */
    unsigned a926_intr_mask_3;                        /* <24> [dv:     0x0000] [des: ARM926 interrupt mask register3] */
    unsigned a926_intr_mask_4;                        /* <25> [dv:     0x0000] [des: ARM926 interrupt mask register4] */
    unsigned a926_intr_mask_5;                        /* <26> [dv:     0x0000] [des: ARM926 interrupt mask register5] */
    unsigned a926_intr_mask_6;                        /* <27> [dv:     0x0000] [des: ARM926 interrupt mask register6] */
    unsigned dsp_intr_clr0;                           /* <28> [dv:     0x0000] [des: DSP interrupt clear register0] */
    unsigned dsp_intr_clr1;                           /* <29> [dv:     0x0000] [des: DSP interrupt clear register1] */
    unsigned dsp_intr_clr2;                           /* <30> [dv:     0x0000] [des: DSP interrupt clear register2] */
    unsigned dsp_intr_clr3;                           /* <31> [dv:     0x0000] [des: DSP interrupt clear register3] */
    // GROUP 10 [interrupt]
    unsigned a926_intr_clr_0;                         /* < 0> [dv:     0x0000] [des: ARM926 interrupt clear register0] */
    unsigned a926_intr_clr_1;                         /* < 1> [dv:     0x0000] [des: ARM926 interrupt clear register1] */
    unsigned a926_intr_clr_2;                         /* < 2> [dv:     0x0000] [des: ARM926 interrupt clear register2] */
    unsigned a926_intr_clr_3;                         /* < 3> [dv:     0x0000] [des: ARM926 interrupt clear register3] */
    unsigned a926_intr_clr_4;                         /* < 4> [dv:     0x0000] [des: ARM926 interrupt clear register4] */
    unsigned a926_intr_clr_5;                         /* < 5> [dv:     0x0000] [des: ARM926 interrupt clear register5] */
    unsigned a926_intr_clr_6;                         /* < 6> [dv:     0x0000] [des: ARM926 interrupt clear register6] */
    unsigned masked_a926_fiqs_0;                      /* < 7> [dv:     0x0000] [des: Masked ARM926 FIQ register0] */
    unsigned masked_a926_fiqs_1;                      /* < 8> [dv:     0x0000] [des: Masked ARM926 FIQ register1] */
    unsigned masked_a926_fiqs_2;                      /* < 9> [dv:     0x0000] [des: Masked ARM926 FIQ register2] */
    unsigned masked_a926_fiqs_3;                      /* <10> [dv:     0x0000] [des: Masked ARM926 FIQ register3] */
    unsigned masked_a926_fiqs_4;                      /* <11> [dv:     0x0000] [des: Masked ARM926 FIQ register4] */
    unsigned masked_a926_fiqs_5;                      /* <12> [dv:     0x0000] [des: Masked ARM926 FIQ register5] */
    unsigned masked_a926_fiqs_6;                      /* <13> [dv:     0x0000] [des: Masked ARM926 FIQ register6] */
    unsigned masked_a926_irqs_0;                      /* <14> [dv:     0x0000] [des: Masked ARM926 IRQ register0] */
    unsigned masked_a926_irqs_1;                      /* <15> [dv:     0x0000] [des: Masked ARM926 IRQ register1] */
    unsigned masked_a926_irqs_2;                      /* <16> [dv:     0x0000] [des: Masked ARM926 IRQ register2] */
    unsigned masked_a926_irqs_3;                      /* <17> [dv:     0x0000] [des: Masked ARM926 IRQ register3] */
    unsigned masked_a926_irqs_4;                      /* <18> [dv:     0x0000] [des: Masked ARM926 IRQ register4] */
    unsigned masked_a926_irqs_5;                      /* <19> [dv:     0x0000] [des: Masked ARM926 IRQ register5] */
    unsigned masked_a926_irqs_6;                      /* <20> [dv:     0x0000] [des: Masked ARM926 IRQ register6] */
    unsigned dsp_intr_mask_0;                         /* <21> [dv:     0x0000] [des: DSP interrupt mask register0] */
    unsigned dsp_intr_mask_1;                         /* <22> [dv:     0x0000] [des: DSP interrupt mask register1] */
    unsigned dsp_intr_mask_2;                         /* <23> [dv:     0x0000] [des: DSP interrupt mask register2] */
    unsigned dsp_intr_mask_3;                         /* <24> [dv:     0x0000] [des: DSP interrupt mask register3] */
    unsigned dsp_intr_mask_4;                         /* <25> [dv:     0x0000] [des: DSP interrupt mask register4] */
    unsigned dsp_intr_mask_5;                         /* <26> [dv:     0x0000] [des: DSP interrupt mask register5] */
    unsigned dsp_intr_mask_6;                         /* <27> [dv:     0x0000] [des: DSP interrupt mask register6] */
    unsigned dsp_intr_clr4;                           /* <28> [dv:     0x0000] [des: DSP interrupt clear register4] */
    unsigned dsp_intr_clr5;                           /* <29> [dv:     0x0000] [des: DSP interrupt clear register5] */
    unsigned dsp_intr_clr6;                           /* <30> [dv:     0x0000] [des: DSP interrupt clear register6] */
    unsigned intr_group;                              /* <31> [dv:     0x0000] [des: Interrupt group register] */
    // GROUP 11 [tset_test-and-set]
    unsigned tset_0;                                  /* < 0> [dv:     0x0001] [des: Test and set semaphore register _0 for dual CPU inter-operation] */
    unsigned tset_1;                                  /* < 1> [dv:     0x0001] [des: Test and set semaphore register _1 for dual CPU inter-operation] */
    unsigned tset_2;                                  /* < 2> [dv:     0x0001] [des: Test and set semaphore register _2 for dual CPU inter-operation] */
    unsigned tset_3;                                  /* < 3> [dv:     0x0001] [des: Test and set semaphore register _3 for dual CPU inter-operation] */
    unsigned tset_4;                                  /* < 4> [dv:     0x0001] [des: Test and set semaphore register _4 for dual CPU inter-operation] */
    unsigned tset_5;                                  /* < 5> [dv:     0x0001] [des: Test and set semaphore register _5 for dual CPU inter-operation] */
    unsigned tset_6;                                  /* < 6> [dv:     0x0001] [des: Test and set semaphore register _6 for dual CPU inter-operation] */
    unsigned tset_7;                                  /* < 7> [dv:     0x0001] [des: Test and set semaphore register _7 for dual CPU inter-operation] */
    unsigned tset_8;                                  /* < 8> [dv:     0x0001] [des: Test and set semaphore register _8 for dual CPU inter-operation] */
    unsigned tset_9;                                  /* < 9> [dv:     0x0001] [des: Test and set semaphore register _9 for dual CPU inter-operation] */
    unsigned tset_10;                                 /* <10> [dv:     0x0001] [des: Test and set semaphore register _10 for dual CPU inter-operation] */
    unsigned tset_11;                                 /* <11> [dv:     0x0001] [des: Test and set semaphore register _11 for dual CPU inter-operation] */
    unsigned tset_12;                                 /* <12> [dv:     0x0001] [des: Test and set semaphore register _12 for dual CPU inter-operation] */
    unsigned tset_13;                                 /* <13> [dv:     0x0001] [des: Test and set semaphore register _13 for dual CPU inter-operation] */
    unsigned tset_14;                                 /* <14> [dv:     0x0001] [des: Test and set semaphore register _14 for dual CPU inter-operation] */
    unsigned tset_15;                                 /* <15> [dv:     0x0001] [des: Test and set semaphore register _15 for dual CPU inter-operation] */
    unsigned tset_16;                                 /* <16> [dv:     0x0001] [des: Test and set semaphore register _16 for dual CPU inter-operation] */
    unsigned tset_17;                                 /* <17> [dv:     0x0001] [des: Test and set semaphore register _17 for dual CPU inter-operation] */
    unsigned tset_18;                                 /* <18> [dv:     0x0001] [des: Test and set semaphore register _18 for dual CPU inter-operation] */
    unsigned tset_19;                                 /* <19> [dv:     0x0001] [des: Test and set semaphore register _19 for dual CPU inter-operation] */
    unsigned tset_20;                                 /* <20> [dv:     0x0001] [des: Test and set semaphore register _20 for dual CPU inter-operation] */
    unsigned tset_21;                                 /* <21> [dv:     0x0001] [des: Test and set semaphore register _21 for dual CPU inter-operation] */
    unsigned tset_22;                                 /* <22> [dv:     0x0001] [des: Test and set semaphore register _22 for dual CPU inter-operation] */
    unsigned tset_23;                                 /* <23> [dv:     0x0001] [des: Test and set semaphore register _23 for dual CPU inter-operation] */
    unsigned tset_24;                                 /* <24> [dv:     0x0001] [des: Test and set semaphore register _24 for dual CPU inter-operation] */
    unsigned tset_25;                                 /* <25> [dv:     0x0001] [des: Test and set semaphore register _25 for dual CPU inter-operation] */
    unsigned tset_26;                                 /* <26> [dv:     0x0001] [des: Test and set semaphore register _26 for dual CPU inter-operation] */
    unsigned tset_27;                                 /* <27> [dv:     0x0001] [des: Test and set semaphore register _27 for dual CPU inter-operation] */
    unsigned tset_28;                                 /* <28> [dv:     0x0001] [des: Test and set semaphore register _28 for dual CPU inter-operation] */
    unsigned tset_29;                                 /* <29> [dv:     0x0001] [des: Test and set semaphore register _29 for dual CPU inter-operation] */
    unsigned tset_30;                                 /* <30> [dv:     0x0001] [des: Test and set semaphore register _30 for dual CPU inter-operation] */
    unsigned tset_31;                                 /* <31> [dv:     0x0001] [des: Test and set semaphore register _31 for dual CPU inter-operation] */
    // GROUP 12 [stc]
    unsigned stc_15_0;                                /* < 0> [dv:     0x0001] [des: STC Counter Register] */
    unsigned stc_31_16;                               /* < 1> [dv:     0x0000] [des: STC Counter Register] */
    unsigned stc_64;                                  /* < 2> [dv:     0x0000] [des: STC Counter Register] */
    unsigned stc_divisor;                             /* < 3> [dv:     0x04af] [des: STC pre-scaling Register] */
    unsigned rtc_15_0;                                /* < 4> [dv:     0x0001] [des: RTC counter register] */
    unsigned rtc_23_16;                               /* < 5> [dv:     0x0000] [des: RTC counter register] */
    unsigned rtc_divisor;                             /* < 6> [dv:       0x59] [des: RTC Divider Register] */
    unsigned stc_config;                              /* < 7> [dv:     0x0000] [des: External reference clock dividor] */
    unsigned timer0_ctl;                              /* < 8> [dv:     0x0000] [des: Timer0 Control Register] */
    unsigned timer0_cnt;                              /* < 9> [dv:     0x0000] [des: Timer0 Counter register] */
    unsigned timer1_ctl;                              /* <10> [dv:     0x0000] [des: Timer1 Control Register] */
    unsigned timer1_cnt;                              /* <11> [dv:     0x0000] [des: Timer1 Counter register] */
    unsigned timerw_ctl;                              /* <12> [dv:     0x0000] [des: Watchdog Timer Control register] */
    unsigned timerw_cnt;                              /* <13> [dv:     0xffff] [des: Watchdog Timer Counter register] */
    unsigned stc_47_32;                               /* <14> [dv:     0x0000] [des: STC Counter Register] */
    unsigned stc_63_48;                               /* <15> [dv:     0x0000] [des: STC Counter Register] */
    unsigned timer2_ctl;                              /* <16> [dv:     0x0000] [des: Timer2 Control Register] */
    unsigned timer2_pres_value;                       /* <17> [dv:     0x0000] [des: Timer2 16-bit pre-scaling value] */
    unsigned timer2_reload;                           /* <18> [dv:     0x0000] [des: Timer2 16-bit reload value] */
    unsigned timer2_cnt;                              /* <19> [dv:     0x0000] [des: Timer2 16-bit counter value] */
    unsigned timer3_ctl;                              /* <20> [dv:     0x0000] [des: Timer3 Control Register] */
    unsigned timer3_pres_value;                       /* <21> [dv:     0x0000] [des: Timer3 16-bit pre-scaling value] */
    unsigned timer3_reload;                           /* <22> [dv:     0x0000] [des: Timer3 16-bit reload value] */
    unsigned timer3_cnt;                              /* <23> [dv:     0x0000] [des: Timer3 16-bit counter value] */
    unsigned stcl_0;                                  /* <24> [dv:     0x0000] [des: Latched value (bit 15:0) of STC counter] */
    unsigned stcl_1;                                  /* <25> [dv:     0x0000] [des: Latched value (bit 31:16) of STC counter] */
    unsigned stcl_2;                                  /* <26> [dv:     0x0000] [des: Latched value (bit 32) of STC counter] */
    unsigned atc_0;                                   /* <27> [dv:     0x0001] [des: 34 bit ATC counter bit[15:0]] */
    unsigned atc_1;                                   /* <28> [dv:     0x0000] [des: 34 bit ATC counter bit[31:16]] */
    unsigned atc_2;                                   /* <29> [dv:     0x0000] [des: 34 bit ATC counter bit[33:32]] */
    unsigned reserved30;                              /* <30> [dv:     0x0000] [des: Reserved] */
    unsigned reserved31;                              /* <31> [dv:     0x0000] [des: Reserved] */
    // GROUP 13 [br_wrapper]
    unsigned protect_en;                              /* < 0> [dv:     0x0000] [des: BR WRAPPER Protect Enable Register] */
    unsigned protect_sta_addr;                        /* < 1> [dv:     0x0000] [des: BR WRAPPER Protect Start Address] */
    unsigned protect_end_addr;                        /* < 2> [dv:     0x0000] [des: BR WRAPPER Protect End Address] */
    unsigned grp13_reserved_0[29];                        /* < 3> */
    // GROUP 14 [dummy_master]
    unsigned op_mode;                                 /* < 0> [dv: 0x00002003] [des: Operation Mode for dummy master0 ] */
    unsigned addr_base;                               /* < 1> [dv: 0x00000000] [des: Base address accessed by dummy master0] */
    unsigned addr_offset;                             /* < 2> [dv: 0x00000000] [des: Offset address accessed by dummy master0 ] */
    unsigned control;                                 /* < 3> [dv: 0x00000000] [des: Dummy master0 control] */
    unsigned urgent;                                  /* < 4> [dv: 0x00000000] [des: Urgent for dummy master0 ] */
    unsigned request_period;                          /* < 5> [dv: 0x00000040] [des: Request Period] */
    unsigned request_count;                           /* < 6> [dv: 0x00000000] [des: Non-Surviced Request Count of dummy master0] */
    unsigned error;                                   /* < 7> [dv: 0x00000000] [des:  Error Flag for self-check of dummy master0 ] */
    unsigned reserved_0_2;                            /* < 8> [dv: 0x00000000] [des: Reserved] */
    unsigned reserved_1_2;                            /* < 9> [dv: 0x00000000] [des: Reserved] */
    unsigned reserved_2_2;                            /* <10> [dv: 0x00000000] [des: Reserved] */
    unsigned reserved_3_2;                            /* <11> [dv: 0x00000000] [des: Reserved] */
    unsigned reserved_4_2;                            /* <12> [dv: 0x00000000] [des: Reserved] */
    unsigned reserved_5_2;                            /* <13> [dv: 0x00000000] [des: Reserved] */
    unsigned reserved_6_2;                            /* <14> [dv: 0x00000000] [des: Reserved] */
    unsigned reserved_7_2;                            /* <15> [dv: 0x00000000] [des: Reserved] */
    unsigned reserved_8_1;                            /* <16> [dv: 0x00000000] [des: Reserved] */
    unsigned reserved_9_1;                            /* <17> [dv: 0x00000000] [des: Reserved] */
    unsigned reserved_10_1;                           /* <18> [dv: 0x00000000] [des: Reserved] */
    unsigned reserved_11;                             /* <19> [dv: 0x00000000] [des: Reserved] */
    unsigned reserved_12;                             /* <20> [dv: 0x00000000] [des: Reserved] */
    unsigned reserved_13;                             /* <21> [dv: 0x00000000] [des: Reserved] */
    unsigned reserved_14;                             /* <22> [dv: 0x00000000] [des: Reserved] */
    unsigned reserved_15;                             /* <23> [dv: 0x00000000] [des: Reserved] */
    unsigned reserved_16;                             /* <24> [dv: 0x00000000] [des: Reserved] */
    unsigned reserved_17;                             /* <25> [dv: 0x00000000] [des: Reserved] */
    unsigned reserved_18;                             /* <26> [dv: 0x00000000] [des: Reserved] */
    unsigned reserved_19;                             /* <27> [dv: 0x00000000] [des: Reserved] */
    unsigned reserved_20;                             /* <28> [dv: 0x00000000] [des: Reserved] */
    unsigned reserved_21;                             /* <29> [dv: 0x00000000] [des: Reserved] */
    unsigned reserved_22;                             /* <30> [dv: 0x00000000] [des: Reserved] */
    unsigned reserved_23;                             /* <31> [dv: 0x00000000] [des: Reserved] */
    // GROUP 15 [interrupt]
    unsigned masked_dsp_intr_0;                       /* < 0> [dv:     0x0000] [des: Masked DSP interrupt register0] */
    unsigned masked_dsp_intr_1;                       /* < 1> [dv:     0x0000] [des: Masked DSP interrupt register1] */
    unsigned masked_dsp_intr_2;                       /* < 2> [dv:     0x0000] [des: Masked DSP interrupt register2] */
    unsigned masked_dsp_intr_3;                       /* < 3> [dv:     0x0000] [des: Masked DSP interrupt register3] */
    unsigned masked_dsp_intr_4;                       /* < 4> [dv:     0x0000] [des: Masked DSP interrupt register4] */
    unsigned masked_dsp_intr_5;                       /* < 5> [dv:     0x0000] [des: Masked DSP interrupt register5] */
    unsigned masked_dsp_intr_6;                       /* < 6> [dv:     0x0000] [des: Masked DSP interrupt register6] */
    unsigned grp15_reserved_0;                        /* < 7> */
    unsigned grp15_reserved_1;                        /* < 8> */
    unsigned grp15_reserved_2;                        /* < 9> */
    unsigned grp15_reserved_3;                        /* <10> */
    unsigned grp15_reserved_4;                        /* <11> */
    unsigned grp15_reserved_5;                        /* <12> */
    unsigned grp15_reserved_6;                        /* <13> */
    unsigned grp15_reserved_7;                        /* <14> */
    unsigned grp15_reserved_8;                        /* <15> */
    unsigned grp15_reserved_9;                        /* <16> */
    unsigned grp15_reserved_10;                       /* <17> */
    unsigned grp15_reserved_11;                       /* <18> */
    unsigned grp15_reserved_12;                       /* <19> */
    unsigned grp15_reserved_13;                       /* <20> */
    unsigned grp15_reserved_14;                       /* <21> */
    unsigned grp15_reserved_15;                       /* <22> */
    unsigned grp15_reserved_16;                       /* <23> */
    unsigned grp15_reserved_17;                       /* <24> */
    unsigned grp15_reserved_18;                       /* <25> */
    unsigned grp15_reserved_19;                       /* <26> */
    unsigned grp15_reserved_20;                       /* <27> */
    unsigned grp15_reserved_21;                       /* <28> */
    unsigned grp15_reserved_22;                       /* <29> */
    unsigned grp15_reserved_23;                       /* <30> */
    unsigned grp15_reserved_24;                       /* <31> */
    // GROUP 16 [uart2]
    unsigned uart2_data;                              /* < 0> [dv:     0x0000] [des: UART2 Data Port Register] */
    unsigned uart2_lsr;                               /* < 1> [dv:     0x0041] [des: UART2 Line Status Register] */
    unsigned uart2_msr;                               /* < 2> [dv:     0x0000] [des: Modem Status Register] */
    unsigned uart2_lcr;                               /* < 3> [dv:     0x0003] [des: UART2 Line-Control Register] */
    unsigned uart2_mcr;                               /* < 4> [dv:     0x0000] [des: UART2 Modem Control Register] */
    unsigned uart2_div_l;                             /* < 5> [dv:     0x903a] [des: UART2 Clock Divider Low Register] */
    unsigned uart2_div_h;                             /* < 6> [dv:     0x0000] [des: UART2 Clock Divider High Register] */
    unsigned uart2_isc;                               /* < 7> [dv:     0x0000] [des: UART2 Interrupt Status/Control register] */
    unsigned uart2_tx_residue;                        /* < 8> [dv:     0x0000] [des: UART2 TX Residue] */
    unsigned uart2_rx_residue;                        /* < 9> [dv:     0x0000] [des: UART2 RX Residue] */
    unsigned uart2_rx_threshold;                      /* <10> [dv:     0x0000] [des: UART2 RX FIFO Threshold] */
    unsigned grp16_reserved_0;                        /* <11> */
    unsigned grp16_reserved_1;                        /* <12> */
    unsigned grp16_reserved_2;                        /* <13> */
    unsigned grp16_reserved_3;                        /* <14> */
    unsigned grp16_reserved_4;                        /* <15> */
    unsigned grp16_reserved_5;                        /* <16> */
    unsigned grp16_reserved_6;                        /* <17> */
    unsigned grp16_reserved_7;                        /* <18> */
    unsigned grp16_reserved_8;                        /* <19> */
    unsigned grp16_reserved_9;                        /* <20> */
    unsigned grp16_reserved_10;                       /* <21> */
    unsigned grp16_reserved_11;                       /* <22> */
    unsigned grp16_reserved_12;                       /* <23> */
    unsigned grp16_reserved_13;                       /* <24> */
    unsigned grp16_reserved_14;                       /* <25> */
    unsigned grp16_reserved_15;                       /* <26> */
    unsigned grp16_reserved_16;                       /* <27> */
    unsigned grp16_reserved_17;                       /* <28> */
    unsigned grp16_reserved_18;                       /* <29> */
    unsigned grp16_reserved_19;                       /* <30> */
    unsigned grp16_reserved_20;                       /* <31> */
    // GROUP 17 [uart3]
    unsigned uart3_data;                              /* < 0> [dv:     0x0000] [des: UART3 Data Port Register] */
    unsigned uart3_lsr;                               /* < 1> [dv:     0x0041] [des: UART3 Line Status Register] */
    unsigned uart3_msr;                               /* < 2> [dv:     0x0000] [des: Modem Status Register] */
    unsigned uart3_lcr;                               /* < 3> [dv:     0x0003] [des: UART3 Line-Control Register] */
    unsigned uart3_mcr;                               /* < 4> [dv:     0x0000] [des: UART3 Modem Control Register] */
    unsigned uart3_div_l;                             /* < 5> [dv:     0x903a] [des: UART3 Clock Divider Low Register] */
    unsigned uart3_div_h;                             /* < 6> [dv:     0x0000] [des: UART3 Clock Divider High Register] */
    unsigned uart3_isc;                               /* < 7> [dv:     0x0000] [des: UART3 Interrupt Status/Control register] */
    unsigned uart3_tx_residue;                        /* < 8> [dv:     0x0000] [des: UART3 TX Residue] */
    unsigned uart3_rx_residue;                        /* < 9> [dv:     0x0000] [des: UART3 RX Residue] */
    unsigned uart3_rx_threshold;                      /* <10> [dv:     0x0000] [des: UART3 RX FIFO Threshold] */
    unsigned grp17_reserved_0;                        /* <11> */
    unsigned grp17_reserved_1;                        /* <12> */
    unsigned grp17_reserved_2;                        /* <13> */
    unsigned grp17_reserved_3;                        /* <14> */
    unsigned grp17_reserved_4;                        /* <15> */
    unsigned grp17_reserved_5;                        /* <16> */
    unsigned grp17_reserved_6;                        /* <17> */
    unsigned grp17_reserved_7;                        /* <18> */
    unsigned grp17_reserved_8;                        /* <19> */
    unsigned grp17_reserved_9;                        /* <20> */
    unsigned grp17_reserved_10;                       /* <21> */
    unsigned grp17_reserved_11;                       /* <22> */
    unsigned grp17_reserved_12;                       /* <23> */
    unsigned grp17_reserved_13;                       /* <24> */
    unsigned grp17_reserved_14;                       /* <25> */
    unsigned grp17_reserved_15;                       /* <26> */
    unsigned grp17_reserved_16;                       /* <27> */
    unsigned grp17_reserved_17;                       /* <28> */
    unsigned grp17_reserved_18;                       /* <29> */
    unsigned grp17_reserved_19;                       /* <30> */
    unsigned grp17_reserved_20;                       /* <31> */
    // GROUP 18 [uart0]
    unsigned uart0_data;                              /* < 0> [dv:     0x0000] [des: UART0 Data Port Register] */
    unsigned uart0_lsr;                               /* < 1> [dv:     0x0041] [des: UART0 Line Status Register] */
    unsigned uart0_msr;                               /* < 2> [dv:     0x0000] [des: Modem Status Register] */
    unsigned uart0_lcr;                               /* < 3> [dv:     0x0003] [des: UART0 Line-Control Register] */
    unsigned uart0_mcr;                               /* < 4> [dv:     0x0000] [des: UART0 Modem Control Register] */
    unsigned uart0_div_l;                             /* < 5> [dv:     0x903a] [des: UART0 Clock Divider Low Register] */
    unsigned uart0_div_h;                             /* < 6> [dv:     0x0000] [des: UART0 Clock Divider High Register] */
    unsigned uart0_isc;                               /* < 7> [dv:     0x0000] [des: UART0 Interrupt Status/Control register] */
    unsigned uart0_tx_residue;                        /* < 8> [dv:     0x0000] [des: UART0 TX Residue] */
    unsigned uart0_rx_residue;                        /* < 9> [dv:     0x0000] [des: UART0 RX Residue] */
    unsigned uart0_rx_threshold;                      /* <10> [dv:     0x0000] [des: UART0 RX FIFO Threshold] */
    unsigned grp18_reserved_0;                        /* <11> */
    unsigned grp18_reserved_1;                        /* <12> */
    unsigned grp18_reserved_2;                        /* <13> */
    unsigned grp18_reserved_3;                        /* <14> */
    unsigned grp18_reserved_4;                        /* <15> */
    unsigned grp18_reserved_5;                        /* <16> */
    unsigned grp18_reserved_6;                        /* <17> */
    unsigned grp18_reserved_7;                        /* <18> */
    unsigned grp18_reserved_8;                        /* <19> */
    unsigned grp18_reserved_9;                        /* <20> */
    unsigned grp18_reserved_10;                       /* <21> */
    unsigned grp18_reserved_11;                       /* <22> */
    unsigned grp18_reserved_12;                       /* <23> */
    unsigned grp18_reserved_13;                       /* <24> */
    unsigned grp18_reserved_14;                       /* <25> */
    unsigned grp18_reserved_15;                       /* <26> */
    unsigned grp18_reserved_16;                       /* <27> */
    unsigned grp18_reserved_17;                       /* <28> */
    unsigned grp18_reserved_18;                       /* <29> */
    unsigned grp18_reserved_19;                       /* <30> */
    unsigned grp18_reserved_20;                       /* <31> */
    // GROUP 19 [uart1]
    unsigned uart1_data;                              /* < 0> [dv:     0x0000] [des: UART1 Data Port Register] */
    unsigned uart1_lsr;                               /* < 1> [dv:     0x0041] [des: UART1 Line Status Register] */
    unsigned uart1_msr;                               /* < 2> [dv:     0x0000] [des: Modem Status Register] */
    unsigned uart1_lcr;                               /* < 3> [dv:     0x0003] [des: UART1 Line-Control Register] */
    unsigned uart1_mcr;                               /* < 4> [dv:     0x0000] [des: UART1 Modem Control Register] */
    unsigned uart1_div_l;                             /* < 5> [dv:     0x903a] [des: UART1 Clock Divider Low Register] */
    unsigned uart1_div_h;                             /* < 6> [dv:     0x0000] [des: UART1 Clock Divider High Register] */
    unsigned uart1_isc;                               /* < 7> [dv:     0x0000] [des: UART1 Interrupt Status/Control register] */
    unsigned uart1_tx_residue;                        /* < 8> [dv:     0x0000] [des: UART1 TX Residue] */
    unsigned uart1_rx_residue;                        /* < 9> [dv:     0x0000] [des: UART1 RX Residue] */
    unsigned uart1_rx_threshold;                      /* <10> [dv:     0x0000] [des: UART1 RX FIFO Threshold] */
    unsigned grp19_reserved_0;                        /* <11> */
    unsigned grp19_reserved_1;                        /* <12> */
    unsigned grp19_reserved_2;                        /* <13> */
    unsigned grp19_reserved_3;                        /* <14> */
    unsigned grp19_reserved_4;                        /* <15> */
    unsigned grp19_reserved_5;                        /* <16> */
    unsigned grp19_reserved_6;                        /* <17> */
    unsigned grp19_reserved_7;                        /* <18> */
    unsigned grp19_reserved_8;                        /* <19> */
    unsigned grp19_reserved_9;                        /* <20> */
    unsigned grp19_reserved_10;                       /* <21> */
    unsigned grp19_reserved_11;                       /* <22> */
    unsigned grp19_reserved_12;                       /* <23> */
    unsigned grp19_reserved_13;                       /* <24> */
    unsigned grp19_reserved_14;                       /* <25> */
    unsigned grp19_reserved_15;                       /* <26> */
    unsigned grp19_reserved_16;                       /* <27> */
    unsigned grp19_reserved_17;                       /* <28> */
    unsigned grp19_reserved_18;                       /* <29> */
    unsigned grp19_reserved_19;                       /* <30> */
    unsigned grp19_reserved_20;                       /* <31> */
    // GROUP 20 [dpll_digital_pll]
    unsigned dpll0_ctrl;                              /* < 0> [dv:     0x0000] [des: DPLL0 Control Register] */
    unsigned dpll0_remainder;                         /* < 1> [dv:     0x0000] [des: DPLL0 Remainder Register] */
    unsigned dpll0_denominator;                       /* < 2> [dv:     0x0000] [des: DPLL0 Denominator Register] */
    unsigned dpll0_divider;                           /* < 3> [dv:     0x0000] [des: DPLL0 Divider Register] */
    unsigned dpll0_sprd_num;                          /* < 4> [dv:     0xXXXX] [des: DPLL0 Spread Clock Number] */
    unsigned reserved_0_3;                            /* < 5> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_1_3;                            /* < 6> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_2_3;                            /* < 7> [dv:     0x0000] [des: Reserved] */
    unsigned dpll1_ctrl;                              /* < 8> [dv:     0x0000] [des: DPLL1 Control Register] */
    unsigned dpll1_remainder;                         /* < 9> [dv:     0x0000] [des: DPLL1 Remainder Register] */
    unsigned dpll1_denominator;                       /* <10> [dv:     0x0000] [des: DPLL1 Denominator Register] */
    unsigned dpll1_divider;                           /* <11> [dv:     0x0000] [des: DPLL1 Divider Register] */
    unsigned dpll1_sprd_num;                          /* <12> [dv:     0xXXXX] [des: DPLL1 Spread Clock Number] */
    unsigned reserved_3_3;                            /* <13> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_4_3;                            /* <14> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_5_3;                            /* <15> [dv:     0x0000] [des: Reserved] */
    unsigned dpll2_ctrl;                              /* <16> [dv:     0x0000] [des: DPLL2 Control Register] */
    unsigned dpll2_remainder;                         /* <17> [dv:     0x0000] [des: DPLL2 Remainder Register] */
    unsigned dpll2_denominator;                       /* <18> [dv:     0x0000] [des: DPLL2 Denominator Register] */
    unsigned dpll2_divider;                           /* <19> [dv:     0x0000] [des: DPLL2 Divider Register] */
    unsigned dpll2_sprd_num;                          /* <20> [dv:     0xXXXX] [des: DPLL2 Spread Clock Number] */
    unsigned reserved_6_3;                            /* <21> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_7_3;                            /* <22> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_8_2;                            /* <23> [dv:     0x0000] [des: Reserved] */
    unsigned dpll3_ctrl;                              /* <24> [dv:     0x0000] [des: DPLL3 Control Register] */
    unsigned dpll3_remainder;                         /* <25> [dv:     0x0000] [des: DPLL3 Remainder Register] */
    unsigned dpll3_denominator;                       /* <26> [dv:     0x0000] [des: DPLL3 Denominator Register] */
    unsigned dpll3_divider;                           /* <27> [dv:     0x0000] [des: DPLL3 Divider Register] */
    unsigned dpll3_sprd_num;                          /* <28> [dv:     0xXXXX] [des: DPLL3 Spread Clock Number] */
    unsigned reserved_9_2;                            /* <29> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_10_2;                           /* <30> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_11_1;                           /* <31> [dv:     0x0000] [des: Reserved] */
    // GROUP 21
    unsigned grp21_reserved[32];
    // GROUP 22 [spi_controller_registers]
    unsigned spi_ctrl;                                /* < 0> [dv:     0x0117] [des: SPI Control Register] */
    unsigned spi_wait;                                /* < 1> [dv:     0x012A] [des: SPI Timing Register] */
    unsigned spi_cust_cmd;                            /* < 2> [dv:     0x0013] [des: SPI Customized Command Register] */
    unsigned spi_addr_low;                            /* < 3> [dv:     0x0000] [des: SPI Address Low Regsister] */
    unsigned spi_addr_high;                           /* < 4> [dv:     0x0000] [des: SPI Address High Register] */
    unsigned spi_data_low;                            /* < 5> [dv:     0x0000] [des: SPI Data Low Register] */
    unsigned spi_data_high;                           /* < 6> [dv:     0x0000] [des: SPI Data High Register] */
    unsigned spi_status;                              /* < 7> [dv:     0x0000] [des: SPI Status Register] */
    unsigned spi_cfg0;                                /* < 8> [dv:     0x0000] [des: SPI Configuration0 Register] */
    unsigned spi_cfg1;                                /* < 9> [dv:     0x3B00] [des: SPI Configuration1 Register] */
    unsigned spi_cfg2;                                /* <10> [dv:     0x1200] [des: SPI Configuration2 Register] */
    unsigned spi_cfg3;                                /* <11> [dv:     0x0009] [des: SPI Configuration3 Register] */
    unsigned spi_cfg4;                                /* <12> [dv:     0x0015] [des: SPI Configuration4 Register] */
    unsigned spi_cfg5;                                /* <13> [dv:     0x0015] [des: SPI Configuration5 Register] */
    unsigned spi_cfg6;                                /* <14> [dv:     0x0095] [des: SPI Configuration6 Register] */
    unsigned spi_cfg7;                                /* <15> [dv:     0x0095] [des: SPI Configuration7 Register] */
    unsigned spi_cfg8;                                /* <16> [dv:     0x0000] [des: SPI Configuration8 Register] */
    unsigned spi_cust_cmd_2;                          /* <17> [dv:     0x0004] [des: SPI Customized Command2 Register] */
    unsigned spi_data_64;                             /* <18> [dv:     0x0000] [des: SPI Data Buffer Regsiter] */
    unsigned spi_buf_addr;                            /* <19> [dv:     0x0000] [des: SPI Buffer Address Register] */
    unsigned spi_status_2;                            /* <20> [dv:     0x2000] [des: SPI Status2 Register] */
    unsigned spi_status_3;                            /* <21> [dv:     0x0000] [des: SPI Status3 Register] */
    unsigned spi_mode_status;                         /* <22> [dv:     0x0000] [des: SPI Mode Status Register] */
    unsigned spi_err_status;                          /* <23> [dv:     0x0000] [des: SPI Controller Error Status Register] */
    unsigned grp22_reserved_0;                        /* <24> */
    unsigned grp22_reserved_1;                        /* <25> */
    unsigned grp22_reserved_2;                        /* <26> */
    unsigned grp22_reserved_3;                        /* <27> */
    unsigned grp22_reserved_4;                        /* <28> */
    unsigned grp22_reserved_5;                        /* <29> */
    unsigned grp22_reserved_6;                        /* <30> */
    unsigned grp22_reserved_7;                        /* <31> */
    // GROUP 23 [spi_protection_scramble_descramble_registers]
    unsigned spi_protect_mode;                        /* < 0> [dv:     0x0000] [des: Protect Mode Register] */
    unsigned spi_region0_start_addr_low;              /* < 1> [dv:     0x0000] [des: Lower 16bits of Protection Region0 Start Address] */
    unsigned spi_region0_start_addr_high;             /* < 2> [dv:     0x0000] [des: Higher 16bit of Protection Region0 Start Address] */
    unsigned spi_region0_size;                        /* < 3> [dv:     0x0000] [des: Size of Protection Region0] */
    unsigned spi_region1_start_addr_low;              /* < 4> [dv:     0x0000] [des: Lower 16bits of Protection Region1 Start Address] */
    unsigned spi_region1_start_addr_high;             /* < 5> [dv:     0x0000] [des: Higher 16bits of Protection Region1 Start Address] */
    unsigned spi_region1_size;                        /* < 6> [dv:     0x0000] [des: Size of Protection Region1] */
    unsigned spi_region2_start_addr_low;              /* < 7> [dv:     0x0000] [des: Lower 16bits of Protection Region2 Start Address] */
    unsigned spi_region2_start_addr_high;             /* < 8> [dv:     0x0000] [des: Higher 16bits of Protection Region2 Start Address] */
    unsigned spi_region2_size;                        /* < 9> [dv:     0x0000] [des: Size of Protection Region2] */
    unsigned spi_out_of_range;                        /* <10> [dv:     0x0000] [des: Out of Range Control] */
    unsigned spi_scramble1;                           /* <11> [dv:     0x0000] [des: SPI Scramble1 Register] */
    unsigned spi_scramble2;                           /* <12> [dv:     0x0000] [des: SPI Scramble2 Register] */
    unsigned spi_scramble3;                           /* <13> [dv:     0x0000] [des: SPI Scramble3 Register] */
    unsigned grp23_reserved_0;                        /* <14> */
    unsigned grp23_reserved_1;                        /* <15> */
    unsigned grp23_reserved_2;                        /* <16> */
    unsigned grp23_reserved_3;                        /* <17> */
    unsigned grp23_reserved_4;                        /* <18> */
    unsigned grp23_reserved_5;                        /* <19> */
    unsigned grp23_reserved_6;                        /* <20> */
    unsigned grp23_reserved_7;                        /* <21> */
    unsigned grp23_reserved_8;                        /* <22> */
    unsigned grp23_reserved_9;                        /* <23> */
    unsigned grp23_reserved_10;                       /* <24> */
    unsigned grp23_reserved_11;                       /* <25> */
    unsigned grp23_reserved_12;                       /* <26> */
    unsigned grp23_reserved_13;                       /* <27> */
    unsigned grp23_reserved_14;                       /* <28> */
    unsigned grp23_reserved_15;                       /* <29> */
    unsigned grp23_reserved_16;                       /* <30> */
    unsigned grp23_reserved_17;                       /* <31> */
    // GROUP 24 [cb_switch_cbus_switch]
    unsigned cbus_wdog_ctl;                           /* < 0> [dv: 0x00000200] [des: CPU Bus Switch Watchdog Control] */
    unsigned cbus_wdog_sel;                           /* < 1> [dv: 0x0000000f] [des: CPU Bus Switch Watchdog Cycle Select] */
    unsigned cbus_wdog_status;                        /* < 2> [dv: 0x00000000] [des: CPU Bus Switch Watchdog Status] */
    unsigned cbus_unmap_mid;                          /* < 3> [dv: 0x00000000] [des: CPU Bus Switch Unmapped Master ID] */
    unsigned cbus_unmap_addr;                         /* < 4> [dv: 0x00000000] [des: CPU Bus Switch Unmapped Address] */
    unsigned cbus_dec_wdog_set;                       /* < 5> [dv: 0x50f00000] [des: RGST Watchdog Setting, it's maintain in RBUS G500 now] */
    unsigned cbus_dec_wdog_cmd_info;                  /* < 6> [dv: 0x00000000] [des: RGST Watchdog Command Info.] */
    unsigned cbus_dec_wdog_data_info;                 /* < 7> [dv: 0x00000000] [des: RGST Watchdog Data Info.] */
    unsigned unmap_region0_start;                     /* < 8> [dv: 0x00000000] [des: Start Address of Unmap Region 0] */
    unsigned unmap_region0_end;                       /* < 9> [dv: 0x00000000] [des: End Address of Unmap Region 0] */
    unsigned unmap_region1_start;                     /* <10> [dv: 0x00000000] [des: Start Address of Unmap Region 1] */
    unsigned unmap_region1_end;                       /* <11> [dv: 0x00000000] [des: End Address of Unmap Region 1] */
    unsigned cbus_dramb_disable_set;                  /* <12> [dv: 0x00000000] [des: CBSU DRAMB Disable Setting.] */
    unsigned reserved_0_4;                            /* <13> [dv: 0x00000000] [des: Reserved.] */
    unsigned reserved_1_4;                            /* <14> [dv: 0x00000000] [des: Reserved.] */
    unsigned reserved_2_4;                            /* <15> [dv: 0x00000000] [des: Reserved.] */
    unsigned cbus_preformance_monitor_set;            /* <16> [dv: 0x00000000] [des: CBUS Preformance Monitor Enable/Reset Setting.] */
    unsigned cbus_preformance_monitor_id_set;         /* <17> [dv: 0x00000000] [des: CBUS Preformance Monitor Master ID Setting.] */
    unsigned cbus_preformance_monitor_event_set;      /* <18> [dv: 0x00000000] [des: CBUS Preformance Monitor Event Setting.] */
    unsigned cbus_preformance_monitor_output;         /* <19> [dv: 0x00000000] [des: CBUS Preformance Monitor Output.] */
    unsigned reserved_3_4;                            /* <20> [dv: 0x00000000] [des: Reserved.] */
    unsigned reserved_4_4;                            /* <21> [dv: 0x00000000] [des: Reserved.] */
    unsigned reserved_5_4;                            /* <22> [dv: 0x00000000] [des: Reserved.] */
    unsigned reserved_6_4;                            /* <23> [dv: 0x00000000] [des: Reserved.] */
    unsigned reserved_7_4;                            /* <24> [dv: 0x00000000] [des: Reserved.] */
    unsigned reserved_8_3;                            /* <25> [dv: 0x00000000] [des: Reserved.] */
    unsigned reserved_9_3;                            /* <26> [dv: 0x00000000] [des: Reserved.] */
    unsigned reserved_10_3;                           /* <27> [dv: 0x00000000] [des: Reserved.] */
    unsigned reserved_11_2;                           /* <28> [dv: 0x00000000] [des: Reserved.] */
    unsigned reserved_12_1;                           /* <29> [dv: 0x00000000] [des: Reserved.] */
    unsigned reserved_13_1;                           /* <30> [dv: 0x00000000] [des: Reserved.] */
    unsigned reserved_14_1;                           /* <31> [dv: 0x00000000] [des: Reserved.] */
    // GROUP 25 [peri_bg_peripheral_bus_pbus]
    unsigned peri_globe_ctrl;                         /* < 0> [dv:     0x0000] [des: PBUS Global Control] */
    unsigned peri_page;                               /* < 1> [dv:     0x0000] [des: PBUS Page Setting] */
    unsigned peri_mon_setting;                        /* < 2> [dv:     0x000c] [des: PBUS Monitor Setting] */
    unsigned peri_m0_setting;                         /* < 3> [dv:     0x0000] [des: PBUS Master 0 Setting -- AUD] */
    unsigned peri_m1_setting;                         /* < 4> [dv:     0x0000] [des: PBUS Master 1 Setting -- UADMA0] */
    unsigned peri_m2_setting;                         /* < 5> [dv:     0x0000] [des: PBUS Master 2 Setting -- UADMA1] */
    unsigned peri_m3_setting;                         /* < 6> [dv:     0x0000] [des: PBUS Master 3 Setting -- CARD0] */
    unsigned peri_m4_setting;                         /* < 7> [dv:     0x0000] [des: PBUS Master 4 Setting -- CARD1] */
    unsigned peri_m5_setting;                         /* < 8> [dv:     0x0000] [des: PBUS Master 5 Setting -- CARD4] */
    unsigned reserved_0_5;                            /* < 9> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_1_5;                            /* <10> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_2_5;                            /* <11> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_3_5;                            /* <12> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_4_5;                            /* <13> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_5_5;                            /* <14> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_6_5;                            /* <15> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_7_5;                            /* <16> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_8_4;                            /* <17> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_9_4;                            /* <18> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_10_4;                           /* <19> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_11_3;                           /* <20> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_12_2;                           /* <21> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_13_2;                           /* <22> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_14_2;                           /* <23> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_15_1;                           /* <24> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_16_1;                           /* <25> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_17_1;                           /* <26> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_18_1;                           /* <27> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_19_1;                           /* <28> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_20_1;                           /* <29> [dv:     0x0000] [des: Reserved] */
    unsigned peri_mon_log_a_d;                        /* <30> [dv:     0x0000] [des: PBUS MON LOG A to D] */
    unsigned peri_mon_log_e;                          /* <31> [dv:     0x0000] [des: PBUS MON LOG E] */
    // GROUP 26 [cb_dma_cbus_dma_controller]
    unsigned dma_hw_ver;                              /* < 0> [dv: 0x20120706] [des: ] */
    unsigned dma_config;                              /* < 1> [dv: 0x00030000] [des: ] */
    unsigned dma_length;                              /* < 2> [dv: 0x00000000] [des: ] */
    unsigned dma_src_adr;                             /* < 3> [dv: 0x00000000] [des: ] */
    unsigned dma_des_adr;                             /* < 4> [dv: 0x00000000] [des: ] */
    unsigned dma_int_flag;                            /* < 5> [dv: 0x00000000] [des: ] */
    unsigned dma_int_en;                              /* < 6> [dv: 0x00000001] [des: ] */
    unsigned memset_value;                            /* < 7> [dv: 0x00000000] [des: ] */
    unsigned sdram_size_config;                       /* < 8> [dv: 0x00004040] [des: ] */
    unsigned grp26_reserved_0;                        /* < 9> */
    unsigned grp26_reserved_1;                        /* <10> */
    unsigned grp26_reserved_2;                        /* <11> */
    unsigned grp26_reserved_3;                        /* <12> */
    unsigned grp26_reserved_4;                        /* <13> */
    unsigned grp26_reserved_5;                        /* <14> */
    unsigned grp26_reserved_6;                        /* <15> */
    unsigned grp26_reserved_7;                        /* <16> */
    unsigned grp26_reserved_8;                        /* <17> */
    unsigned grp26_reserved_9;                        /* <18> */
    unsigned grp26_reserved_10;                       /* <19> */
    unsigned grp26_reserved_11;                       /* <20> */
    unsigned grp26_reserved_12;                       /* <21> */
    unsigned grp26_reserved_13;                       /* <22> */
    unsigned grp26_reserved_14;                       /* <23> */
    unsigned grp26_reserved_15;                       /* <24> */
    unsigned grp26_reserved_16;                       /* <25> */
    unsigned grp26_reserved_17;                       /* <26> */
    unsigned grp26_reserved_18;                       /* <27> */
    unsigned grp26_reserved_19;                       /* <28> */
    unsigned grp26_reserved_20;                       /* <29> */
    unsigned grp26_reserved_21;                       /* <30> */
    unsigned grp26_reserved_22;                       /* <31> */
    // GROUP 27 [cb_dma1_cbus_dma_controller]
    unsigned dma_hw_ver_1;                            /* < 0> [dv: 0x20150910] [des: ] */
    unsigned dma_config_1;                            /* < 1> [dv: 0x00030000] [des: ] */
    unsigned dma_length_1;                            /* < 2> [dv: 0x00000000] [des: ] */
    unsigned dma_src_adr_1;                           /* < 3> [dv: 0x00000000] [des: ] */
    unsigned dma_des_adr_1;                           /* < 4> [dv: 0x00000000] [des: ] */
    unsigned dma_int_flag_1;                          /* < 5> [dv: 0x00000000] [des: ] */
    unsigned dma_int_en_1;                            /* < 6> [dv: 0x00000001] [des: ] */
    unsigned memset_value_1;                          /* < 7> [dv: 0x00000000] [des: ] */
    unsigned sdram_size_config_1;                     /* < 8> [dv: 0x00004040] [des: ] */
    unsigned grp27_reserved_0;                        /* < 9> */
    unsigned grp27_reserved_1;                        /* <10> */
    unsigned grp27_reserved_2;                        /* <11> */
    unsigned grp27_reserved_3;                        /* <12> */
    unsigned grp27_reserved_4;                        /* <13> */
    unsigned grp27_reserved_5;                        /* <14> */
    unsigned grp27_reserved_6;                        /* <15> */
    unsigned grp27_reserved_7;                        /* <16> */
    unsigned grp27_reserved_8;                        /* <17> */
    unsigned grp27_reserved_9;                        /* <18> */
    unsigned grp27_reserved_10;                       /* <19> */
    unsigned grp27_reserved_11;                       /* <20> */
    unsigned grp27_reserved_12;                       /* <21> */
    unsigned grp27_reserved_13;                       /* <22> */
    unsigned grp27_reserved_14;                       /* <23> */
    unsigned grp27_reserved_15;                       /* <24> */
    unsigned grp27_reserved_16;                       /* <25> */
    unsigned grp27_reserved_17;                       /* <26> */
    unsigned grp27_reserved_18;                       /* <27> */
    unsigned grp27_reserved_19;                       /* <28> */
    unsigned grp27_reserved_20;                       /* <29> */
    unsigned grp27_reserved_21;                       /* <30> */
    unsigned grp27_reserved_22;                       /* <31> */
    // GROUP 28
    unsigned grp28_reserved[32];
    // GROUP 29 [mbus_mbus_monitor]
    unsigned mbus0_setting;                           /* < 0> [dv: 0x00003000] [des: MBUS0 Setting] */
    unsigned mbus0_monitor_setting;                   /* < 1> [dv: 0x00000000] [des: MBUS0 Monitor Setting] */
    unsigned mbus_monitor_en;                         /* < 2> [dv: 0x00000000] [des: MBUS Montior Enable] */
    unsigned mbus_abnormal_latency_limit;             /* < 3> [dv: 0x00000400] [des: MBUS Abnormal Latency Limit] */
    unsigned mbus0_latency;                           /* < 4> [dv: 0x00000000] [des: MBUS0 Latency] */
    unsigned mbus0_command;                           /* < 5> [dv: 0x00000000] [des: MBUS0 COMMAND] */
    unsigned mbus0_sd_tranx;                          /* < 6> [dv: 0x00000000] [des: SD Transaction count] */
    unsigned mbus0_latency_extend;                    /* < 7> [dv: 0x00000000] [des: MBUS0 Latency extension] */
    unsigned l2c_bandwidth_setting;                   /* < 8> [dv: 0x00400040] [des: L2C of SDCTRL Bandwidth Setting] */
    unsigned reserved_0_6;                            /* < 9> [dv: 0x00000000] [des: Reserved] */
    unsigned reserved_1_6;                            /* <10> [dv: 0x00000000] [des: Reserved] */
    unsigned reserved_2_6;                            /* <11> [dv: 0x00000000] [des: Reserved] */
    unsigned reserved_3_6;                            /* <12> [dv: 0x00000000] [des: Reserved] */
    unsigned reserved_4_6;                            /* <13> [dv: 0x00000000] [des: Reserved] */
    unsigned reserved_5_6;                            /* <14> [dv: 0x00000000] [des: Reserved] */
    unsigned reserved_6_6;                            /* <15> [dv: 0x00000000] [des: Reserved] */
    unsigned mbus_int_en;                             /* <16> [dv: 0x00000107] [des: MBUS INTERRUPT Enable] */
    unsigned mbus_int_status;                         /* <17> [dv: 0x00000000] [des: Status of MBUS INTERRUPT] */
    unsigned mbus_int_addr;                           /* <18> [dv: 0x00000000] [des: ADDRESS of MBUS INTERRUPT] */
    unsigned mbus_ab_sel;                             /* <19> [dv: 0x00000000] [des: MBUS SDRAMA/B SELECT] */
    unsigned mbus_ab_arb_type;                        /* <20> [dv: 0x00000000] [des: MBUS SDRAMA/B ARBITRATION TYPE] */
    unsigned mbus_ab_priority;                        /* <21> [dv: 0x00000000] [des: MBUS SDRAMA/B PRIORITY] */
    unsigned mbus_base_index_offset;                  /* <22> [dv: 0x00000000] [des: MBUS BASE INDEX OFFSET] */
    unsigned reserved_7_6;                            /* <23> [dv: 0x00000000] [des: Reserved] */
    unsigned reserved_8_5;                            /* <24> [dv: 0x00000000] [des: Reserved] */
    unsigned reserved_9_5;                            /* <25> [dv: 0x00000000] [des: Reserved] */
    unsigned reserved_10_5;                           /* <26> [dv: 0x00000000] [des: Reserved] */
    unsigned reserved_11_4;                           /* <27> [dv: 0x00000000] [des: Reserved] */
    unsigned reserved_12_3;                           /* <28> [dv: 0x00000000] [des: Reserved] */
    unsigned reserved_13_3;                           /* <29> [dv: 0x00000000] [des: Reserved] */
    unsigned reserved_14_3;                           /* <30> [dv: 0x00000000] [des: Reserved] */
    unsigned reserved_15_2;                           /* <31> [dv: 0x00000000] [des: Reserved] */
    // GROUP 30
    unsigned grp30_reserved[32];
    // GROUP 31 [mbus_mbar0]
    unsigned mbar0_page_setting;                      /* < 0> [dv:     0x0000] [des: MBAR0 Page Setting] */
    unsigned mbar0_m1_setting;                        /* < 1> [dv:     0x0000] [des: MBAR0 Master 1 Setting -- C2MBG     ] */
    unsigned mbar0_m2_setting;                        /* < 2> [dv:     0x0000] [des: MBAR0 Master 2 Setting -- DSPD     ] */
    unsigned mbar0_m3_setting;                        /* < 3> [dv:     0x0000] [des: MBAR0 Master 3 Setting -- PERI_WP     ] */
    unsigned mbar0_m4_setting;                        /* < 4> [dv:     0x0000] [des: MBAR0 Master 4 Setting -- CBDMA0     ] */
    unsigned mbar0_m5_setting;                        /* < 5> [dv:     0x0000] [des: MBAR0 Master 5 Setting -- GC520_WP     ] */
    unsigned mbar0_m6_setting;                        /* < 6> [dv:     0x0000] [des: MBAR0 Master 6 Setting -- USBC0_WP     ] */
    unsigned mbar0_m7_setting;                        /* < 7> [dv:     0x0000] [des: MBAR0 Master 7 Setting -- USBC1_WP     ] */
    unsigned mbar0_m8_setting;                        /* < 8> [dv:     0x0000] [des: MBAR0 Master 8 Setting -- USBH_WP     ] */
    unsigned mbar0_m9_setting;                        /* < 9> [dv:     0x0000] [des: MBAR0 Master 9 Setting -- M2S_SDIF_WP     ] */
    unsigned mbar0_m10_setting;                       /* <10> [dv:     0x0000] [des: MBAR0 Master 10 Setting -- DDFCH0_WP     ] */
    unsigned mbar0_m11_setting;                       /* <11> [dv:     0x0000] [des: MBAR0 Master 11 Setting -- DDFCH1_WP     ] */
    unsigned mbar0_m12_setting;                       /* <12> [dv:     0x0000] [des: MBAR0 Master 12 Setting -- OSD0_WP     ] */
    unsigned mbar0_m13_setting;                       /* <13> [dv:     0x0000] [des: MBAR0 Master 13 Setting -- OSD1_WP     ] */
    unsigned mbar0_m14_setting;                       /* <14> [dv:     0x0000] [des: MBAR0 Master 14 Setting -- OSD2_WP     ] */
    unsigned mbar0_m15_setting;                       /* <15> [dv:     0x0000] [des: MBAR0 Master 15 Setting -- AFRC_WP     ] */
    unsigned mbar0_m16_setting;                       /* <16> [dv:     0x0000] [des: MBAR0 Master 16 Setting -- TNRIW0_WP     ] */
    unsigned mbar0_m17_setting;                       /* <17> [dv:     0x0000] [des: MBAR0 Master 17 Setting -- TNRIW1_WP     ] */
    unsigned mbar0_m18_setting;                       /* <18> [dv:     0x0000] [des: MBAR0 Master 18 Setting -- V656IN0_WP     ] */
    unsigned mbar0_m19_setting;                       /* <19> [dv:     0x0000] [des: MBAR0 Master 19 Setting -- V656IN1_WP     ] */
    unsigned mbar0_m20_setting;                       /* <20> [dv:     0x0000] [des: MBAR0 Master 20 Setting -- NC        ] */
    unsigned mbar0_m21_setting;                       /* <21> [dv:     0x0000] [des: MBAR0 Master 21 Setting -- MR_MIX_WP     ] */
    unsigned mbar0_m22_setting;                       /* <22> [dv:     0x0000] [des: MBAR0 Master 22 Setting -- TVDEC_WP     ] */
    unsigned mbar0_m23_setting;                       /* <23> [dv:     0x0000] [des: MBAR0 Master 23 Setting -- LV00     ] */
    unsigned mbar0_m24_setting;                       /* <24> [dv:     0x0000] [des: MBAR0 Master 24 Setting -- LF_MIX_WP     ] */
    unsigned mbar0_m25_setting;                       /* <25> [dv:     0x0000] [des: MBAR0 Master 25 Setting -- MR_CHR_MIX_WP     ] */
    unsigned mbar0_m26_setting;                       /* <26> [dv:     0x0000] [des: MBAR0 Master 26 Setting -- LF_CHR_MIX_WP     ] */
    unsigned mbar0_m27_setting;                       /* <27> [dv:     0x0000] [des: MBAR0 Master 27 Setting -- MPRG_MIX_WP     ] */
    unsigned mbar0_m28_setting;                       /* <28> [dv:     0x0000] [des: MBAR0 Master 28 Setting -- DMAG_MIX_WP     ] */
    unsigned mbar0_m29_setting;                       /* <29> [dv:     0x0000] [des: MBAR0 Master 29 Setting -- HS_WP     ] */
    unsigned mbar0_m30_setting;                       /* <30> [dv:     0x0000] [des: MBAR0 Master 30 Setting -- DUMMY     ] */
    unsigned mbar0_m31_setting;                       /* <31> [dv:     0x0000] [des: MBAR0 Master 31 Setting -- HS_CHR_WP     ] */
    // GROUP 32 [sdctrl_a_mcpp]
    unsigned mcpp0_ver;                               /* < 0> [dv: 0x0000_CD00] [des: MBUS Command Parallel Processor Version] */
    unsigned mcpp0_type_cfg;                          /* < 1> [dv: 0x0038_039F] [des: MCPP Type Configuration] */
    unsigned mcpp0_flush_set;                         /* < 2> [dv: 0xE000_0004] [des: MCPP Flush Level Setting] */
    unsigned mcpp0_life_set_0;                        /* < 3> [dv: 0x0000_0096] [des: MCPP Life Time Setting 0] */
    unsigned mcpp0_rgst_debug;                        /* < 4> [dv: 0x0000_0000] [des: MCPP RGST Debug] */
    unsigned mcpp0_prof_set;                          /* < 5> [dv: 0x0000_0000] [des: MCPP Profililng Setting] */
    unsigned mcpp0_prof_result;                       /* < 6> [dv: 0x0000_0000] [des: MCPP Profiling Result] */
    unsigned mcpp0_life_set_1;                        /* < 7> [dv: 0x0000_0000] [des: MCPP Life Time Setting 1] */
    unsigned mcpp0_life_set_2;                        /* < 8> [dv: 0x0000_0000] [des: MCPP Life Time Setting 2] */
    unsigned mcpp0_life_set_3;                        /* < 9> [dv: 0x0000_0000] [des: MCPP Life Time Setting 3] */
    unsigned mcpp0_life_set_4;                        /* <10> [dv: 0x0000_0000] [des: MCPP Life Time Setting 4] */
    unsigned mcpp0_clk_free_run;                      /* <11> [dv: 0x0000_0000] [des: MCPP Free Run Clock Setting] */
    unsigned grp32_reserved_0;                        /* <12> */
    unsigned grp32_reserved_1;                        /* <13> */
    unsigned grp32_reserved_2;                        /* <14> */
    unsigned grp32_reserved_3;                        /* <15> */
    unsigned grp32_reserved_4;                        /* <16> */
    unsigned grp32_reserved_5;                        /* <17> */
    unsigned grp32_reserved_6;                        /* <18> */
    unsigned grp32_reserved_7;                        /* <19> */
    unsigned grp32_reserved_8;                        /* <20> */
    unsigned grp32_reserved_9;                        /* <21> */
    unsigned grp32_reserved_10;                       /* <22> */
    unsigned grp32_reserved_11;                       /* <23> */
    unsigned grp32_reserved_12;                       /* <24> */
    unsigned grp32_reserved_13;                       /* <25> */
    unsigned grp32_reserved_14;                       /* <26> */
    unsigned grp32_reserved_15;                       /* <27> */
    unsigned grp32_reserved_16;                       /* <28> */
    unsigned grp32_reserved_17;                       /* <29> */
    unsigned grp32_reserved_18;                       /* <30> */
    unsigned grp32_reserved_19;                       /* <31> */
    // GROUP 33 [sdctrl_a_g1]
    unsigned sd0_ver_0;                               /* < 0> [dv:     0xDC31] [des: SDRAM Controller Version] */
    unsigned sd0_ddr_phy_dpcu_cfg;                    /* < 1> [dv: 0x0000_0000] [des: DDR PHY DPCU Configuration] */
    unsigned sd0_sys_config_1;                        /* < 2> [dv: 0x0000_0C0C] [des: SDRAM Controller System Bus Configuration Set-1] */
    unsigned sd0_sys_config_2;                        /* < 3> [dv: 0x0000_2060] [des: SDRAM Controller System Bus Configuration Set-2] */
    unsigned sd0_sys_config_3;                        /* < 4> [dv: 0x7878_7878] [des: SDRAM Controller System Bus Configuration Set-3] */
    unsigned sd0_sdram_cfg;                           /* < 5> [dv: 0x0000_A700] [des: SDRAM Type Configuration] */
    unsigned sd0_config_0;                            /* < 6> [dv: 0x00ED_01BA] [des: SDRAM Controller Operation Configuration 0] */
    unsigned sd0_config_1;                            /* < 7> [dv: 0x0000_0005] [des: SDRAM Controller Operation Configuration 1] */
    unsigned sd0_asref_0;                             /* < 8> [dv: 0x0000_8C9E] [des: SDRAM Controller (Auto) Refresh/Self Refresh Configuration 0] */
    unsigned sd0_aref_1;                              /* < 9> [dv: 0x0000_0003] [des: SDRAM Controller (Auto) Refresh Configuration 1.] */
    unsigned sd0_sref_1;                              /* <10> [dv: 0x0000_4000] [des: SDRAM Controller Self Refresh Configuration 1.] */
    unsigned sd0_par_latency;                         /* <11> [dv: 0x0640_3100] [des: SDRAM Parameters - Access Latency] */
    unsigned sd0_par_interval;                        /* <12> [dv: 0x0000_2463] [des: SDRAM Parameters - Access Interval] */
    unsigned sd0_par_timing_0;                        /* <13> [dv: 0x0040_0C52] [des: SDRAM Parameters - Timing Configuration 0] */
    unsigned sd0_par_timing_1;                        /* <14> [dv: 0x0000_1735] [des: SDRAM Parameters - Timing Configuration 1] */
    unsigned sd0_par_timing_2;                        /* <15> [dv: 0x0000_4511] [des: SDRAM Parameters - Timing Configuration 2] */
    unsigned sd0_par_timing_3;                        /* <16> [dv: 0x0000_1105] [des: SDRAM Parameters - Timing Configuration 3] */
    unsigned sd0_mrs_cfg;                             /* <17> [dv: 0x0000_0000] [des: SDRAM (E)MRS Setting Register] */
    unsigned sd0_mrs_trg;                             /* <18> [dv: 0x0000_0000] [des: SDRAM (E)MRS Trigger] */
    unsigned sd0_odt_cfg;                             /* <19> [dv: 0x0000_2300] [des: SDRAM Controller ODT Configuration (DDR2/3)] */
    unsigned sd0_int;                                 /* <20> [dv: 0x0000_0000] [des: SDRAM Controller Interrupt Status.] */
    unsigned sd0_int_mask;                            /* <21> [dv: 0x0000_0000] [des: SDRAM Controller Interrupt MASK.] */
    unsigned sd0_add_merr;                            /* <22> [dv: 0x0000_0000] [des: (for debug)Record of Low Part of Address for Access Error of Address over the Size of Device] */
    unsigned sd0_wire_merr;                           /* <23> [dv: 0x0000_0000] [des: (for debug)Record of Low part of Command and Master ID for Access Error of Address over the Size of Device] */
    unsigned sd0_mrs_0;                               /* <24> [dv: 0x0000_0000] [des: Record MRS Setting Registers 0] */
    unsigned sd0_mrs_1;                               /* <25> [dv: 0x0000_0000] [des: Record MRS Setting Registers 1] */
    unsigned sd0_clk_free_set;                        /* <26> [dv: 0x0000_0000] [des: Clock free run setting] */
    unsigned sd0_zqcl_set;                            /* <27> [dv: 0x0000_01ff] [des: ZQCL setting] */
    unsigned sd0_zqcs_set;                            /* <28> [dv: 0x0000_3f00] [des: ZQCS setting] */
    unsigned sd0_scpp_ctrl;                           /* <29> [dv: 0x0000_4007] [des: SDRAM Command Pre-Processor Control] */
    unsigned sd0_rfifo_set;                           /* <30> [dv: 0x0000_0020] [des: MI RDATA FIFO Setting] */
    unsigned sd0_ddr3_signal;                         /* <31> [dv: 0x0000_0000] [des: DDR3 Signal Register] */
    // GROUP 34 [sdctrl_a_g2]
    unsigned sd0_ver_1;                               /* < 0> [dv:     0xDC31] [des: SDRAM Controller Version] */
    unsigned sd0_mon_ctrl;                            /* < 1> [dv: 0x0000_0000] [des: Monitor Control Register] */
    unsigned sd0_mon_status;                          /* < 2> [dv: 0x0000_0000] [des: Monitor Status Register] */
    unsigned sd0_mon1_type;                           /* < 3> [dv: 0x0000_0000] [des: Monitor 1 Type Control Register] */
    unsigned sd0_mon1_start_addr;                     /* < 4> [dv: 0x0000_0000] [des: Monitor 1 Start Address Register] */
    unsigned sd0_mon1_addr_offset;                    /* < 5> [dv: 0x0000_0000] [des: Monitor 1 Address Offset Register] */
    unsigned sd0_mon1_hit_mb_addr;                    /* < 6> [dv: 0x0000_0000] [des: Monitor 1 Hit Command Address Register] */
    unsigned sd0_mon1_hit_status;                     /* < 7> [dv: 0x0000_0000] [des: Monitor 1 Hit Status Register] */
    unsigned sd0_mon2_type;                           /* < 8> [dv: 0x0000_0000] [des: Monitor 2 Type Control Register] */
    unsigned sd0_mon2_start_addr;                     /* < 9> [dv: 0x0000_0000] [des: Monitor 2 Start Address Register] */
    unsigned sd0_mon2_addr_offset;                    /* <10> [dv: 0x0000_0000] [des: Monitor 2 Address Offset Register] */
    unsigned sd0_mon2_hit_mb_addr;                    /* <11> [dv: 0x0000_0000] [des: Monitor 2 Hit Command Address Register] */
    unsigned sd0_mon2_hit_status;                     /* <12> [dv: 0x0000_0000] [des: Monitor 2 Hit Status Register] */
    unsigned sd0_mon3_type;                           /* <13> [dv: 0x0000_0000] [des: Monitor 3 Type Control Register] */
    unsigned sd0_mon3_start_addr;                     /* <14> [dv: 0x0000_0000] [des: Monitor 3 Start Address Register] */
    unsigned sd0_mon3_addr_offset;                    /* <15> [dv: 0x0000_0000] [des: Monitor 3 Address Offset Register] */
    unsigned sd0_mon3_hit_mb_addr;                    /* <16> [dv: 0x0000_0000] [des: Monitor 3 Hit Command Address Register] */
    unsigned sd0_mon3_hit_status;                     /* <17> [dv: 0x0000_0000] [des: Monitor 3 Hit Status Register] */
    unsigned sd0_mon4_type;                           /* <18> [dv: 0x0000_0000] [des: Monitor 4 Type Control Register] */
    unsigned sd0_mon4_start_addr;                     /* <19> [dv: 0x0000_0000] [des: Monitor 4 Start Address Register] */
    unsigned sd0_mon4_addr_offset;                    /* <20> [dv: 0x0000_0000] [des: Monitor 4 Address Offset Register] */
    unsigned sd0_mon4_hit_mb_addr;                    /* <21> [dv: 0x0000_0000] [des: Monitor 4 Hit Command Address Register] */
    unsigned sd0_mon4_hit_status;                     /* <22> [dv: 0x0000_0000] [des: Monitor 4 Hit Status Register] */
    unsigned sd0_chksum_cfg;                          /* <23> [dv: 0x0000_0000] [des: SDRAM Controller Checksum Function Configuration] */
    unsigned sd0_chksum_rdata;                        /* <24> [dv: 0x0000_0000] [des: SDRAM Controller Read Data Checksum] */
    unsigned sd0_chksum_wdata;                        /* <25> [dv: 0x0000_0000] [des: SDRAM Controller Write Data Checksum] */
    unsigned sd0_dfi_ack_rec;                         /* <26> [dv: 0x0000_0000] [des: DDR PHY Interface Ack Signal Counting Record] */
    unsigned grp34_reserved_0;                        /* <27> */
    unsigned grp34_reserved_1;                        /* <28> */
    unsigned grp34_reserved_2;                        /* <29> */
    unsigned grp34_reserved_3;                        /* <30> */
    unsigned grp34_reserved_4;                        /* <31> */
    // GROUP 35 [sdctrl_a_g3]
    unsigned sd0_ddr_phy_set_0;                       /* < 0> [dv: 0x0000_0000] [des: ] */
    unsigned sd0_ddr_phy_set_1;                       /* < 1> [dv: 0x0000_0000] [des: ] */
    unsigned sd0_ddr_phy_set_2;                       /* < 2> [dv: 0x0000_0000] [des: ] */
    unsigned sd0_ddr_phy_set_3;                       /* < 3> [dv: 0x0000_0000] [des: ] */
    unsigned sd0_ddr_phy_set_4;                       /* < 4> [dv: 0x0000_0000] [des: ] */
    unsigned sd0_ddr_phy_set_5;                       /* < 5> [dv: 0x0000_0000] [des: ] */
    unsigned sd0_ddr_phy_set_6;                       /* < 6> [dv: 0x0000_0000] [des: ] */
    unsigned sd0_ddr_phy_set_7;                       /* < 7> [dv: 0x0000_0000] [des: ] */
    unsigned sd0_ddr_phy_set_8;                       /* < 8> [dv: 0x0000_0000] [des: ] */
    unsigned sd0_ddr_phy_set_9;                       /* < 9> [dv: 0x0000_0000] [des: ] */
    unsigned sd0_ddr_phy_set_10;                      /* <10> [dv: 0x0000_0000] [des: ] */
    unsigned sd0_ddr_phy_set_11;                      /* <11> [dv: 0x0000_0000] [des: ] */
    unsigned sd0_ddr_phy_set_12;                      /* <12> [dv: 0x0000_0000] [des: ] */
    unsigned sd0_ddr_phy_set_13;                      /* <13> [dv: 0x0000_0000] [des: ] */
    unsigned sd0_ddr_phy_set_14;                      /* <14> [dv: 0x0000_0000] [des: ] */
    unsigned sd0_ddr_phy_set_15;                      /* <15> [dv: 0x0000_0000] [des: ] */
    unsigned sd0_ddr_phy_set_16;                      /* <16> [dv: 0x0000_0000] [des: ] */
    unsigned sd0_ddr_phy_set_17;                      /* <17> [dv: 0x0000_0000] [des: ] */
    unsigned sd0_ddr_phy_set_18;                      /* <18> [dv: 0x0000_0000] [des: ] */
    unsigned sd0_ddr_phy_set_19;                      /* <19> [dv: 0x0000_0000] [des: ] */
    unsigned sd0_ddr_phy_set_20;                      /* <20> [dv: 0x0000_0000] [des: ] */
    unsigned sd0_ddr_phy_set_21;                      /* <21> [dv: 0x0000_0000] [des: ] */
    unsigned sd0_ddr_phy_set_22;                      /* <22> [dv: 0x0000_0000] [des: ] */
    unsigned sd0_ddr_phy_set_23;                      /* <23> [dv: 0x0000_0000] [des: ] */
    unsigned sd0_ddr_phy_set_24;                      /* <24> [dv: 0x0000_0000] [des: ] */
    unsigned sd0_ddr_phy_set_25;                      /* <25> [dv: 0x0000_0000] [des: ] */
    unsigned sd0_ddr_phy_set_26;                      /* <26> [dv: 0x0000_0000] [des: ] */
    unsigned sd0_ddr_phy_set_27;                      /* <27> [dv: 0x0000_0000] [des: ] */
    unsigned sd0_ddr_phy_set_28;                      /* <28> [dv: 0x0000_0000] [des: ] */
    unsigned sd0_ddr_phy_set_29;                      /* <29> [dv: 0x0000_0000] [des: ] */
    unsigned sd0_ddr_phy_set_30;                      /* <30> [dv: 0x0000_0000] [des: ] */
    unsigned sd0_ddr_phy_set_31;                      /* <31> [dv: 0x0000_0000] [des: ] */
    // GROUP 36 [sdctrl_a_bg_2d_g1]
    unsigned bg_2d0_index[128];
    // GROUP 40 [sdctrl_a_l2c_ctl_g1]
    unsigned l2c0_ctrl_ver_0;                         /* < 0> [dv: 0x0000_CA00] [des: Level 2 Cache Controller Version] */
    unsigned l2c0_type_config;                        /* < 1> [dv: 0x0000_0000] [des: CACHE Type Configuration] */
    unsigned l2c0_chk_option;                         /* < 2> [dv: 0x0000_0000] [des: L2C_CTL Check Option] */
    unsigned l2c0_mcb_id;                             /* < 3> [dv: 0x0201_0014] [des: Specification of Master ID] */
    unsigned l2c0_int;                                /* < 4> [dv: 0x0000_0000] [des: L2C Interrupt Status] */
    unsigned l2c0_rgst_bus_chk;                       /* < 5> [dv: 0x0000_0000] [des: L2C RGST Bus Check] */
    unsigned l2c0_mcb_adr_conf_rec_0;                 /* < 6> [dv: 0x0000_0000] [des: Record of Address Confiliction in MCB] */
    unsigned l2c0_mcb_adr_conf_rec_1;                 /* < 7> [dv: 0x0000_0000] [des: Record of Address Confiliction in MCB] */
    unsigned l2c0_mcb_adr_conf_rec_2;                 /* < 8> [dv: 0x0000_0000] [des: Record of Address Confiliction in MCB] */
    unsigned l2c0_mb_adr_conf_rec_0;                  /* < 9> [dv: 0x0000_0000] [des: Record of Address Confiliction in MB] */
    unsigned l2c0_mb_adr_conf_rec_1;                  /* <10> [dv: 0x0000_0000] [des: Record of Address Confiliction in MB] */
    unsigned l2c0_mb_adr_conf_rec_2;                  /* <11> [dv: 0x0000_0000] [des: Record of Address Confiliction in MB] */
    unsigned l2c0_mb_cmd_err_rec_0;                   /* <12> [dv: 0x0000_0000] [des: Record of Command Error in MB] */
    unsigned l2c0_mb_cmd_err_rec_1;                   /* <13> [dv: 0x0000_0000] [des: Record of Command Error in MB] */
    unsigned l2c0_mb_cmd_err_rec_2;                   /* <14> [dv: 0x0000_0000] [des: Record of Command Error in MB] */
    unsigned l2c0_mcb_cmd_err_rec_0;                  /* <15> [dv: 0x0000_0000] [des: Record of Command Error in MCB] */
    unsigned l2c0_mcb_cmd_err_rec_1;                  /* <16> [dv: 0x0000_0000] [des: Record of Command Error in MCB] */
    unsigned l2c0_mcb_cmd_err_rec_2;                  /* <17> [dv: 0x0000_0000] [des: Record of Command Error in MCB] */
    unsigned l2c0_rgst_acc_tag_0;                     /* <18> [dv: 0x0000_0000] [des: Directly Write/Read TAG] */
    unsigned l2c0_rgst_acc_tag_1;                     /* <19> [dv: 0x0000_0000] [des: Way0 Data of Directly Write/Read TAG] */
    unsigned l2c0_rgst_acc_tag_2;                     /* <20> [dv: 0x0000_0000] [des: Way1 Data of Directly Write/Read TAG] */
    unsigned l2c0_rgst_acc_cache_0;                   /* <21> [dv: 0x0020_0000] [des: Directly Write/Read CACHE] */
    unsigned l2c0_rgst_acc_cache_1;                   /* <22> [dv: 0x0000_0000] [des: Low Word Data of Directly Write/Read CACHE] */
    unsigned l2c0_rgst_acc_cache_2;                   /* <23> [dv: 0x0000_0000] [des: High Word Data of Directly Write/Read CACHE] */
    unsigned l2c0_cache_err_code;                     /* <24> [dv: 0x0000_0000] [des: Cache Defect Detected Code] */
    unsigned l2c0_bg2d_err_rec_0;                     /* <25> [dv: 0x0000_0000] [des: 2D Brige Error Record0] */
    unsigned l2c0_bg2d_err_rec_1;                     /* <26> [dv: 0x0000_0000] [des: 2D Brige Error Record1] */
    unsigned l2c0_mb_exc_addr1;                       /* <27> [dv: 0x0000_0000] [des: Memory Bus Exception Adddress Range 1] */
    unsigned l2c0_mb_exc_addr2;                       /* <28> [dv: 0x0000_0000] [des: Memory Bus Exception Adddress Range 2] */
    unsigned grp40_reserved_0;                        /* <29> */
    unsigned grp40_reserved_1;                        /* <30> */
    unsigned grp40_reserved_2;                        /* <31> */
    // GROUP 41 [sdctrl_a_l2c_ctl_g2]
    unsigned l2c0_ctrl_ver_1;                         /* < 0> [dv: 0x0000_CA00] [des: Level 2 Cache Controller Version] */
    unsigned l2c0_hit_prof_0;                         /* < 1> [dv: 0x0000_0000] [des: L2C HIT Rate Profiling Setting 0] */
    unsigned l2c0_hit_prof_1;                         /* < 2> [dv: 0x0000_0000] [des: L2C HIT Rate Profiling Setting 1] */
    unsigned l2c0_hit_prof_2;                         /* < 3> [dv: 0x0000_0000] [des: L2C HIT Rate Profiling Setting 2] */
    unsigned l2c0_hit_prof_result_0;                  /* < 4> [dv: 0x0000_0000] [des: L2C Hit Rate Profiling Result 0] */
    unsigned l2c0_hit_prof_result_1;                  /* < 5> [dv: 0x0000_0000] [des: L2C Hit Rate Profiling Result 1] */
    unsigned l2c0_hit_prof_result_2;                  /* < 6> [dv: 0x0000_0000] [des: L2C Hit Rate Profiling Result 2] */
    unsigned l2c0_hit_prof_result_3;                  /* < 7> [dv: 0x0000_0000] [des: L2C Hit Rate Profiling Result 3] */
    unsigned l2c0_hit_prof_result_4;                  /* < 8> [dv: 0x0000_0000] [des: L2C Hit Rate Profiling Result 4] */
    unsigned l2c0_hit_prof_result_5;                  /* < 9> [dv: 0x0000_0000] [des: L2C Hit Rate Profiling Result 5] */
    unsigned l2c0_hit_prof_result_6;                  /* <10> [dv: 0x0000_0000] [des: L2C Hit Rate Profiling Result 6] */
    unsigned l2c0_hit_prof_result_7;                  /* <11> [dv: 0x0000_0000] [des: L2C Hit Rate Profiling Result 7] */
    unsigned l2c0_hit_prof_3;                         /* <12> [dv: 0x0000_0000] [des: L2C Hit Rate Profiling Setting 3] */
    unsigned grp41_reserved_0;                        /* <13> */
    unsigned grp41_reserved_1;                        /* <14> */
    unsigned grp41_reserved_2;                        /* <15> */
    unsigned grp41_reserved_3;                        /* <16> */
    unsigned grp41_reserved_4;                        /* <17> */
    unsigned grp41_reserved_5;                        /* <18> */
    unsigned grp41_reserved_6;                        /* <19> */
    unsigned grp41_reserved_7;                        /* <20> */
    unsigned grp41_reserved_8;                        /* <21> */
    unsigned grp41_reserved_9;                        /* <22> */
    unsigned grp41_reserved_10;                       /* <23> */
    unsigned grp41_reserved_11;                       /* <24> */
    unsigned grp41_reserved_12;                       /* <25> */
    unsigned grp41_reserved_13;                       /* <26> */
    unsigned grp41_reserved_14;                       /* <27> */
    unsigned grp41_reserved_15;                       /* <28> */
    unsigned grp41_reserved_16;                       /* <29> */
    unsigned grp41_reserved_17;                       /* <30> */
    unsigned grp41_reserved_18;                       /* <31> */
    // GROUP 42 [sdctrl_a_l2c_ctl_g3]
    unsigned l2c0_ctrl_ver_2;                         /* < 0> [dv: 0x0000_CA00] [des: Level 2 Cache Controller Version] */
    unsigned sd0_trimmer_cfg_basic;                   /* < 1> [dv: 0x0000_01E0] [des: SDRAM Trimmer Configuration: Basic] */
    unsigned sd0_trimmer_cfg_len;                     /* < 2> [dv: 0x0000_0000] [des: SDRAM Trimmer Configuration: Length] */
    unsigned sd0_trimmer_cfg_pri;                     /* < 3> [dv: 0x0000_0000] [des: SDRAM Trimmer Configuration; Priority Modes] */
    unsigned sd0_trimmer_cfg_cmd_bl;                  /* < 4> [dv: 0x0000_0000] [des: SDRAM Trimmer Configuration: Command and Burst Length] */
    unsigned sd0_trimmer_cfg_adr_data;                /* < 5> [dv: 0x0000_0000] [des: SDRAM Trimmer Configuration: Address and Data] */
    unsigned sd0_trimmer_cfg_ind_0;                   /* < 6> [dv: 0x0000_0000] [des: SDRAM Trimmer Configuration: Initial Data0] */
    unsigned sd0_trimmer_cfg_ind_1;                   /* < 7> [dv: 0x0000_0000] [des: SDRAM Trimmer Configuration: Initial Data1] */
    unsigned sd0_trimmer_cfg_ina;                     /* < 8> [dv: 0x0000_0000] [des: SDRAM Trimmer Configuration: Initial Address] */
    unsigned sd0_trimmer_err_rec_chk;                 /* < 9> [dv: 0x0000_0000] [des: SDRAM Trimmer Error Record: Counting and Flag] */
    unsigned sd0_trimmer_err_rec_data_0;              /* <10> [dv: 0x0000_0000] [des: SDRAM Trimmer Error Record: Data 0] */
    unsigned sd0_trimmer_err_data_1;                  /* <11> [dv: 0x0000_0000] [des: SDRAM Trimmer Error Record: Data 1] */
    unsigned sd0_trimmer_err_rec_datal_0;             /* <12> [dv: 0x0000_0000] [des: SDRAM Trimmer Error Record: Last Data 0] */
    unsigned sd0_trimmer_err_rec_datal_1;             /* <13> [dv: 0x0000_0000] [des: SDRAM Trimmer Error Record: Last Data 1] */
    unsigned sd0_trimmer_err_rec_datan_0;             /* <14> [dv: 0x0000_0000] [des: SDRAM Trimmer Error Record: Next Data 0] */
    unsigned sd0_trimmer_err_rec_datan_1;             /* <15> [dv: 0x0000_0000] [des: SDRAM Trimmer Error Record: next Data 1] */
    unsigned sd0_trimmer_exp_rec_data_0;              /* <16> [dv: 0x0000_0000] [des: SDRAM Trimmer Expected Record: Data 0] */
    unsigned sd0_trimmer_exp_rec_data_1;              /* <17> [dv: 0x0000_0000] [des: SDRAM Trimmer Expected Record: Data 1] */
    unsigned sd0_trimmer_exp_rec_datal_0;             /* <18> [dv: 0x0000_0000] [des: SDRAM Trimmer Expected Record: Last Data 0] */
    unsigned sd0_trimmer_exp_rec_datal_1;             /* <19> [dv: 0x0000_0000] [des: SDRAM Trimmer Expected Record: Last Data 1] */
    unsigned sd0_trimmer_exp_rec_datan_0;             /* <20> [dv: 0x0000_0000] [des: SDRAM Trimmer Expected Record: Next Data 0] */
    unsigned sd0_trimmer_exp_rec_datan_1;             /* <21> [dv: 0x0000_0000] [des: SDRAM Trimmer Exxpected Record: Next Data 1] */
    unsigned sd0_trimmer_err_rec_no;                  /* <22> [dv: 0x0000_0000] [des: SDRAM Trimmer Error Record: Command and Data Number] */
    unsigned sd0_trimmer_err_rec_rpt;                 /* <23> [dv: 0x0000_0000] [des: SDRAM Trimmer Error Record: Repeated Number] */
    unsigned grp42_reserved_0;                        /* <24> */
    unsigned grp42_reserved_1;                        /* <25> */
    unsigned grp42_reserved_2;                        /* <26> */
    unsigned grp42_reserved_3;                        /* <27> */
    unsigned grp42_reserved_4;                        /* <28> */
    unsigned grp42_reserved_5;                        /* <29> */
    unsigned grp42_reserved_6;                        /* <30> */
    unsigned grp42_reserved_7;                        /* <31> */
    // GROUP 43
    unsigned grp43_reserved[32];
    // GROUP 44
    unsigned grp44_reserved[32];
    // GROUP 45
    unsigned grp45_reserved[32];
    // GROUP 46 [dsp_reg]
    unsigned dsp_dma0_sram_addr;                      /* < 0> [dv:     0x0000] [des: DSP DMA0 Control] */
    unsigned dsp_dma0_dram_addr;                      /* < 1> [dv:     0x0000] [des: DSP DMA0 Control] */
    unsigned dsp_dma0_txsize;                         /* < 2> [dv:     0x0000] [des: DSP DMA0 Control] */
    unsigned dsp_dma0_control;                        /* < 3> [dv:     0x0000] [des: DSP DMA0 Control] */
    unsigned dsp_dma0_status;                         /* < 4> [dv:     0x0001] [des: DSP DMA0 Control] */
    unsigned dsp_dma1_sram_addr;                      /* < 5> [dv:     0x0000] [des: DSP DMA1 Control] */
    unsigned dsp_dma1_dram_addr;                      /* < 6> [dv:     0x0000] [des: DSP DMA1 Control] */
    unsigned dsp_dma1_txsize;                         /* < 7> [dv:     0x0000] [des: DSP DMA1 Control] */
    unsigned dsp_dma1_control;                        /* < 8> [dv:     0x0000] [des: DSP DMA1 Control] */
    unsigned dsp_dma1_status;                         /* < 9> [dv:     0x0001] [des: DSP DMA1 Control] */
    unsigned dsp_dma2_sram_addr;                      /* <10> [dv:     0x0000] [des: DSP DMA2 Control] */
    unsigned dsp_dma2_dram_addr;                      /* <11> [dv:     0x0000] [des: DSP DMA2 Control] */
    unsigned dsp_dma2_txsize;                         /* <12> [dv:     0x0000] [des: DSP DMA2 Control] */
    unsigned dsp_dma2_control;                        /* <13> [dv:     0x0000] [des: DSP DMA2 Control] */
    unsigned dsp_dma2_status;                         /* <14> [dv:     0x0001] [des: DSP DMA2 Control] */
    unsigned reserved_0_7;                            /* <15> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_1_7;                            /* <16> [dv:     0x0000] [des: Reserved] */
    unsigned dsp_inst_page_0;                         /* <17> [dv: 0x80000000] [des: DSP Paging Address] */
    unsigned dsp_inst_page_1;                         /* <18> [dv: 0x00000000] [des: DSP Paging Address] */
    unsigned dsp_inst_page_2;                         /* <19> [dv: 0x00000000] [des: DSP Paging Address] */
    unsigned dsp_inst_page_3;                         /* <20> [dv: 0x00000000] [des: DSP Paging Address] */
    unsigned dsp_inst_page_4;                         /* <21> [dv: 0x00000000] [des: DSP Paging Address] */
    unsigned dsp_inst_page_5;                         /* <22> [dv: 0x00000000] [des: DSP Paging Address] */
    unsigned dsp_inst_page_6;                         /* <23> [dv: 0x00000000] [des: DSP Paging Address] */
    unsigned dsp_inst_page_7;                         /* <24> [dv: 0x00000000] [des: DSP Paging Address] */
    unsigned dsp_data_page;                           /* <25> [dv: 0x00000000] [des: DSP Paging Address] */
    unsigned dsp_rom_page;                            /* <26> [dv: 0x00000000] [des: DSP Paging Address] */
    unsigned dsp_data_page2;                          /* <27> [dv: 0x00000000] [des: DSP Paging Address] */
    unsigned dsp_data_page3;                          /* <28> [dv: 0x00000000] [des: DSP Paging Address] */
    unsigned grp46_reserved_0;                        /* <29> */
    unsigned grp46_reserved_1;                        /* <30> */
    unsigned grp46_reserved_2;                        /* <31> */
    // GROUP 47 [dsp_risc]
    unsigned rdif_ctrl;                               /* < 0> [dv:     0x0001] [des: DSP_RDIF_CTRL] */
    unsigned rdif_int_ctrl;                           /* < 1> [dv:     0x0000] [des: DSP_RDIF_CTRL] */
    unsigned rdif_vint_vector;                        /* < 2> [dv:     0x0000] [des: DSP_RDIF_CTRL] */
    unsigned rdif_code_key;                           /* < 3> [dv: 0xabcddead] [des: DSP_RDIF_CTRL] */
    unsigned dsp_status;                              /* < 4> [dv:     0x0000] [des: DSP_RDIF_CTRL] */
    unsigned rdif_cfg;                                /* < 5> [dv:     0x0001] [des: DSP_RDIF_CTRL] */
    unsigned rdif_oh_ctrl;                            /* < 6> [dv:     0x0000] [des: DSP_RDIF_CTRL] */
    unsigned dsp_error_status;                        /* < 7> [dv:     0x0000] [des: DSP_ERROR_STATUS] */
    unsigned dsp_timer_ctrl;                          /* < 8> [dv:     0x0000] [des: DSP_TIMER_CTRL] */
    unsigned dsp_tcount;                              /* < 9> [dv:     0x0000] [des: DSP_TIMER_CTRL] */
    unsigned dsp_tperiod;                             /* <10> [dv:     0x0000] [des: DSP_TIMER_CTRL] */
    unsigned dsp_timer_status;                        /* <11> [dv:     0x0000] [des: DSP_TIMER_CTRL] */
    unsigned pmu_timer_count;                         /* <12> [dv:     0x0000] [des: PMU_TIMER_COUNT] */
    unsigned pmu_timer_period;                        /* <13> [dv:     0x0000] [des: PMU_TIMER_PERIOD] */
    unsigned pmu_ctrl;                                /* <14> [dv:     0x0000] [des: PMU_CTRL] */
    unsigned reserved_0_8;                            /* <15> [dv:     0x0000] [des: reserved] */
    unsigned dram_inst_page0_len;                     /* <16> [dv:     0x0000] [des: DSP_INST_PAGE0_LEN] */
    unsigned dram_inst_page1_len;                     /* <17> [dv:     0x0000] [des: DSP_INST_PAGE1_LEN] */
    unsigned dram_inst_page2_len;                     /* <18> [dv:     0x0000] [des: DSP_INST_PAGE2_LEN] */
    unsigned dram_inst_page3_len;                     /* <19> [dv:     0x0000] [des: DSP_INST_PAGE3_LEN] */
    unsigned dram_inst_page4_len;                     /* <20> [dv:     0x0000] [des: DSP_INST_PAGE4_LEN] */
    unsigned dram_inst_page5_len;                     /* <21> [dv:     0x0000] [des: DSP_INST_PAGE5_LEN] */
    unsigned dram_inst_page6_len;                     /* <22> [dv:     0x0000] [des: DSP_INST_PAGE6_LEN] */
    unsigned dram_inst_page7_len;                     /* <23> [dv:     0x0000] [des: DSP_INST_PAGE7_LEN] */
    unsigned dram_data_page_len;                      /* <24> [dv:     0x0000] [des: DSP_DATA_PAGE_LEN] */
    unsigned dram_rom_page_len;                       /* <25> [dv:     0x0000] [des: DSP_ROM_PAGE_LEN] */
    unsigned aud_opt_test_pat;                        /* <26> [dv:     0x0000] [des: AUD_OPT_TEST_PAT] */
    unsigned grp47_reserved_0;                        /* <27> */
    unsigned grp47_reserved_1;                        /* <28> */
    unsigned grp47_reserved_2;                        /* <29> */
    unsigned grp47_reserved_3;                        /* <30> */
    unsigned grp47_reserved_4;                        /* <31> */
    // GROUP 48 [dsp_monitor_debugger]
    unsigned dsp_monitor_trigger;                     /* < 0> [dv:     0x0000] [des: DSP_MONITOR] */
    unsigned dsp_cache_burst_req_cnt;                 /* < 1> [dv:     0x0000] [des: DSP_MONITOR] */
    unsigned dsp_cycle;                               /* < 2> [dv:     0x0000] [des: DSP_MONITOR] */
    unsigned dsp_dma_cnt;                             /* < 3> [dv:     0x0000] [des: DSP_MONITOR] */
    unsigned dsp_cache_single_req_cnt;                /* < 4> [dv:     0x0000] [des: DSP_MONITOR] */
    unsigned dsp_dma_cycle;                           /* < 5> [dv:     0x0000] [des: DSP_MONITOR] */
    unsigned dsp_max_dma_cycle;                       /* < 6> [dv:     0x0000] [des: DSP_MONITOR] */
    unsigned dsp_min_dma_cycle;                       /* < 7> [dv:     0xffff] [des: DSP_MONITOR] */
    unsigned dsp_cache_acc_cycle;                     /* < 8> [dv:     0x0000] [des: DSP_MONITOR] */
    unsigned dsp_dma_status;                          /* < 9> [dv:     0x0000] [des: DSP_MONITOR] */
    unsigned dsp_error;                               /* <10> [dv:     0x0000] [des: DSP_MONITOR] */
    unsigned pmu_period_sleep_cnt;                    /* <11> [dv:     0x0000] [des: PMU_CONTROL] */
    unsigned pmu_period_sleep_cycle;                  /* <12> [dv:     0x0000] [des: PMU_CONTROL] */
    unsigned pmu_dma_sleep_cnt;                       /* <13> [dv:     0x0000] [des: PMU_CONTROL] */
    unsigned pmu_dma_sleep_cycle;                     /* <14> [dv:     0x0000] [des: PMU_CONTROL] */
    unsigned reserved_0_9;                            /* <15> [dv:     0x0000] [des: reserved] */
    unsigned ocm_inst_reg;                            /* <16> [dv:     0x0000] [des: DSP_DEBUGGER] */
    unsigned ocm_cntl_reg;                            /* <17> [dv:     0x0000] [des: DSP_DEBUGGER] */
    unsigned ocm_stat_reg;                            /* <18> [dv:     0x0000] [des: DSP_DEBUGGER] */
    unsigned reserved_1_8;                            /* <19> [dv:     0x0000] [des: reserved] */
    unsigned ocm_data_reg_0;                          /* <20> [dv:     0x0000] [des: DSP_DEBUGGER] */
    unsigned ocm_data_reg_1;                          /* <21> [dv:     0x0000] [des: DSP_DEBUGGER] */
    unsigned ocm_data_reg_2;                          /* <22> [dv:     0x0000] [des: DSP_DEBUGGER] */
    unsigned ocm_data_reg_3;                          /* <23> [dv:     0x0000] [des: DSP_DEBUGGER] */
    unsigned ocm_data_reg_4;                          /* <24> [dv:     0x0000] [des: DSP_DEBUGGER] */
    unsigned ocm_data_reg_5;                          /* <25> [dv:     0x0000] [des: DSP_DEBUGGER] */
    unsigned ocm_data_reg_6;                          /* <26> [dv:     0x0000] [des: DSP_DEBUGGER] */
    unsigned ocm_data_reg_7;                          /* <27> [dv:     0x0000] [des: DSP_DEBUGGER] */
    unsigned reserved_2_7;                            /* <28> [dv:     0x0000] [des: reserved] */
    unsigned reserved_3_7;                            /* <29> [dv:     0x0000] [des: reserved] */
    unsigned reserved_4_7;                            /* <30> [dv:     0x0000] [des: reserved] */
    unsigned reserved_5_7;                            /* <31> [dv:     0x0000] [des: reserved] */
    // GROUP 49 [dsp_mailbox]
    unsigned dsp_port0;                               /* < 0> [dv:     0x0000] [des: DSP_PORT0] */
    unsigned dsp_port1;                               /* < 1> [dv:     0x0000] [des: DSP_PORT1] */
    unsigned dsp_port2;                               /* < 2> [dv:     0x0000] [des: DSP_PORT2] */
    unsigned dsp_port3;                               /* < 3> [dv:     0x0000] [des: DSP_PORT3] */
    unsigned dsp_port4;                               /* < 4> [dv:     0x0000] [des: DSP_PORT4] */
    unsigned dsp_port5;                               /* < 5> [dv:     0x0000] [des: DSP_PORT5] */
    unsigned dsp_port6;                               /* < 6> [dv:     0x0000] [des: DSP_PORT6] */
    unsigned dsp_port7;                               /* < 7> [dv:     0x0000] [des: DSP_PORT7] */
    unsigned dsp_port8;                               /* < 8> [dv:     0x0000] [des: DSP_PORT8] */
    unsigned dsp_port9;                               /* < 9> [dv:     0x0000] [des: DSP_PORT9] */
    unsigned dsp_port10;                              /* <10> [dv:     0x0000] [des: DSP_PORT10] */
    unsigned dsp_port11;                              /* <11> [dv:     0x0000] [des: DSP_PORT11] */
    unsigned dsp_port12;                              /* <12> [dv:     0x0000] [des: DSP_PORT12] */
    unsigned dsp_port13;                              /* <13> [dv:     0x0000] [des: DSP_PORT13] */
    unsigned dsp_port14;                              /* <14> [dv:     0x0000] [des: DSP_PORT14] */
    unsigned dsp_port15;                              /* <15> [dv:     0x0000] [des: DSP_PORT15] */
    unsigned dsp_port16;                              /* <16> [dv:     0x0000] [des: DSP_PORT16] */
    unsigned dsp_port17;                              /* <17> [dv:     0x0000] [des: DSP_PORT17] */
    unsigned dsp_port18;                              /* <18> [dv:     0x0000] [des: DSP_PORT18] */
    unsigned dsp_port19;                              /* <19> [dv:     0x0000] [des: DSP_PORT19] */
    unsigned dsp_port20;                              /* <20> [dv:     0x0000] [des: DSP_PORT20] */
    unsigned dsp_port21;                              /* <21> [dv:     0x0000] [des: DSP_PORT21] */
    unsigned dsp_port22;                              /* <22> [dv:     0x0000] [des: DSP_PORT22] */
    unsigned dsp_port23;                              /* <23> [dv:     0x0000] [des: DSP_PORT23] */
    unsigned dsp_port24;                              /* <24> [dv:     0x0000] [des: DSP_PORT24] */
    unsigned dsp_port25;                              /* <25> [dv:     0x0000] [des: DSP_PORT25] */
    unsigned dsp_port26;                              /* <26> [dv:     0x0000] [des: DSP_PORT26] */
    unsigned dsp_port27;                              /* <27> [dv:     0x0000] [des: DSP_PORT27] */
    unsigned dsp_port28;                              /* <28> [dv:     0x0000] [des: DSP_PORT28] */
    unsigned dsp_port29;                              /* <29> [dv:     0x0000] [des: DSP_PORT29] */
    unsigned dsp_port30;                              /* <30> [dv:     0x0000] [des: DSP_PORT30] */
    unsigned dsp_port31;                              /* <31> [dv:     0x0000] [des: DSP_PORT31] */
    // GROUP 50 [ddr_phy-a_control_unit_g1]
    unsigned dpcu_glo_set;                            /* < 0> [dv: 0x0002aa21] [des: DPCU Global Setting ] */
    unsigned dpcu_init_ctrl;                          /* < 1> [dv: 0x00000012] [des: DPCU Initial control ] */
    unsigned dpcu_init_status;                        /* < 2> [dv: 0x00000000] [des: DPCU Initial status ] */
    unsigned dpcu_aphy_cnter;                         /* < 3> [dv: 0x00050910] [des: DPCU APHY Counter ] */
    unsigned dpcu_ddl_calib_set;                      /* < 4> [dv: 0x00f0f0f3] [des: DPCU DDL Calibration Global Setting ] */
    unsigned dpcu_ddl_acck_calib;                     /* < 5> [dv: 0x00000000] [des: DPCU DDL Calibration AC/ACK ] */
    unsigned reserved_0_10;                           /* < 6> [dv: 0x00000000] [des: DPCU Global reserved ] */
    unsigned reserved_1_9;                            /* < 7> [dv: 0x00000000] [des: DPCU Global reserved ] */
    unsigned dpcu_aphy_glo;                           /* < 8> [dv: 0x00000950] [des: APHY - Global ] */
    unsigned dpcu_aphy_macro0;                        /* < 9> [dv: 0x00000000] [des: APHY - MACRO Status Output - 0 ] */
    unsigned dpcu_aphy_macro1;                        /* <10> [dv: 0x00000000] [des: APHY - MACRO Status Output - 1 ] */
    unsigned dpcu_aphy_mpll0;                         /* <11> [dv: 0x000401c2] [des: APHY - MPLL_0 ] */
    unsigned dpcu_aphy_mpll1;                         /* <12> [dv: 0x00455618] [des: APHY - MPLL_1 ] */
    unsigned dpcu_aphy_ctcal0;                        /* <13> [dv: 0x000030ec] [des: APHY - CTCAL_0 ] */
    unsigned dpcu_aphy_ctcal1;                        /* <14> [dv: 0x000007d0] [des: APHY - CTCAL_1 ] */
    unsigned reserved_2_8;                            /* <15> [dv: 0x00000016] [des: reserved ] */
    unsigned dpcu_aphy_div;                           /* <16> [dv: 0x00000000] [des: APHY - DIVIDER ] */
    unsigned dpcu_aphy_ddl_value;                     /* <17> [dv: 0x00000000] [des: APHY - DDL Static DLY Value ] */
    unsigned dpcu_aphy_iopad0;                        /* <18> [dv: 0x00200005] [des: APHY - IOPAD_0_PZQ ] */
    unsigned dpcu_aphy_iopad1;                        /* <19> [dv: 0x0d6a101d] [des: APHY - IOPAD_1_PZQ_VREF ] */
    unsigned dpcu_aphy_iopad2;                        /* <20> [dv: 0x02b6aad0] [des: APHY - IOPAD_2_ADDR and CMD ] */
    unsigned dpcu_aphy_iopad3;                        /* <21> [dv: 0x0000c400] [des: APHY - IOPAD_3_DX ] */
    unsigned dpcu_aphy_iopad4;                        /* <22> [dv: 0x00000000] [des: APHY - IOPAD_4_reserved ] */
    unsigned dpcu_aphy_debug_mode;                    /* <23> [dv: 0x00000000] [des: APHY - DEBUG mode ] */
    unsigned dpcu_aphy_osc_mode;                      /* <24> [dv: 0x0000000c] [des: APHY - OSC mode ] */
    unsigned dpcu_aphy_dummy_port;                    /* <25> [dv: 0x00000000] [des: APHY - DUMMY ports ] */
    unsigned reserved_3_8;                            /* <26> [dv: 0x00000000] [des: reserved ] */
    unsigned reserved_4_8;                            /* <27> [dv: 0x00000000] [des: reserved ] */
    unsigned reserved_5_8;                            /* <28> [dv: 0x00000000] [des: reserved ] */
    unsigned reserved_6_7;                            /* <29> [dv: 0x00000000] [des: reserved ] */
    unsigned reserved_7_7;                            /* <30> [dv: 0x00000000] [des: reserved ] */
    unsigned reserved_8_6;                            /* <31> [dv: 0x00000000] [des: reserved ] */
    // GROUP 51 [ddr_phy-a_control_unit_g2]
    unsigned dpcu_training_status;                    /* < 0> [dv: 0x00000000] [des: DPCU Training Status ] */
    unsigned dpcu_training_setting0;                  /* < 1> [dv: 0x000bb800] [des: DPCU Training Setting - 0 ] */
    unsigned dpcu_training_setting1;                  /* < 2> [dv: 0x00800008] [des: DPCU Training Setting - 1 ] */
    unsigned dpcu_training_setting2;                  /* < 3> [dv: 0x01234567] [des: DPCU Training Setting - 2 ] */
    unsigned dpcu_training_setting3;                  /* < 4> [dv: 0xfedcba98] [des: DPCU Training Setting - 3 ] */
    unsigned dpcu_training_setting4;                  /* < 5> [dv: 0x0c800003] [des: DPCU Training Setting - 4 ] */
    unsigned dpcu_training5;                          /* < 6> [dv: 0x00000301] [des: DPCU Training Setting -5 ] */
    unsigned dpcu_vt_status0;                         /* < 7> [dv: 0x00000000] [des: DPCU VT Detection Status - 0 ] */
    unsigned dpcu_vt_setting0;                        /* < 8> [dv: 0x00000080] [des: DPCU VT Detection Setting - 0 ] */
    unsigned dpcu_vt_setting0_1;                      /* < 9> [dv: 0x00f0f0f1] [des: DPCU VT Detection Setting - 1 ] */
    unsigned dpcu_ci_ctl;                             /* <10> [dv: 0x00021001] [des: CMD ISSUE Control ] */
    unsigned dpcu_ci_status;                          /* <11> [dv: 0x0000000c] [des: CMD ISSUE STATUS ] */
    unsigned dpcu_ac0;                                /* <12> [dv: 0x0f01ffb3] [des: DPCU_AC0 ] */
    unsigned dpcu_ac1;                                /* <13> [dv: 0xa1f2641b] [des: DPCU_AC1 ] */
    unsigned dpcu_ac2;                                /* <14> [dv: 0x275a1553] [des: DPCU_AC2 ] */
    unsigned dpcu_ac3;                                /* <15> [dv: 0x0f761a7f] [des: DPCU_AC3 ] */
    unsigned dpcu_ac4;                                /* <16> [dv: 0x00270ff0] [des: DPCU_AC4 ] */
    unsigned dpcu_ac5;                                /* <17> [dv: 0x00000007] [des: DPCU_AC5 ] */
    unsigned dpcu_ac6;                                /* <18> [dv: 0x1ff3ff7f] [des: DPCU_AC6 ] */
    unsigned dpcu_ac7;                                /* <19> [dv: 0x0a0a1f1f] [des: DPCU_AC7 ] */
    unsigned dpcu_ac8;                                /* <20> [dv: 0x0f1f0f08] [des: DPCU_AC8 ] */
    unsigned dpcu_ac9;                                /* <21> [dv: 0x1f0f0f00] [des: DPCU_AC9 ] */
    unsigned dpcu_ac10;                               /* <22> [dv: 0x00000000] [des: DPCU_AC10 ] */
    unsigned reserved_0_11;                           /* <23> [dv: 0x00000000] [des: reserved ] */
    unsigned dpcu_mr_ddr2;                            /* <24> [dv: 0x00000e73] [des: DPCU_MR_DDR2 ] */
    unsigned dpcu_mr01_ddr3;                          /* <25> [dv: 0x00000c70] [des: DPCU_MR01_DDR3 ] */
    unsigned dpcu_mr23_ddr3;                          /* <26> [dv: 0x00000018] [des: DPCU_MR23_DDR3 ] */
    unsigned dpcu_ci_sw_ctl;                          /* <27> [dv: 0x00000000] [des: DPCU_CI_SW_CMD_CTL ] */
    unsigned dpcu_ci_sw_loop_num;                     /* <28> [dv: 0x00000000] [des: DPCU_SW_LOOP_NUM_SETTING ] */
    unsigned dpcu_ci_sw_cmdfifo_rd;                   /* <29> [dv: 0x00000000] [des: DPCU_SW_CMDFIFO_RD ] */
    unsigned reserved_1_10;                           /* <30> [dv: 0x00000000] [des: reserved ] */
    unsigned reserved_2_9;                            /* <31> [dv: 0x00000000] [des: reserved ] */
    // GROUP 52 [ddr_phy-a_control_unit_g3]
    unsigned serdes_static_setting;                   /* < 0> [dv: 0x00000001] [des: SerDes Static Setting ] */
    unsigned serdes_ddl_setting;                      /* < 1> [dv: 0x00000021] [des: SerDes DDL Setting ] */
    unsigned data_serdes_training_results;            /* < 2> [dv: 0x00000000] [des: Data SerDes training results ] */
    unsigned psd_init_calib_value;                    /* < 3> [dv: 0x00000000] [des: PSD initial calibration value ] */
    unsigned aphy_wl_psd;                             /* < 4> [dv: 0x00000000] [des: APHY PSD status - WL_PSD ] */
    unsigned aphy_rg_psd;                             /* < 5> [dv: 0x00003000] [des: APHY PSD status - RG_PSD ] */
    unsigned aphy_rdqs_psd;                           /* < 6> [dv: 0x00000000] [des: APHY PSD status - RDQS_PSD ] */
    unsigned aphy_wdq_psd;                            /* < 7> [dv: 0x00000000] [des: APHY PSD status - WDQ_PSD ] */
    unsigned aphy_bdd_value;                          /* < 8> [dv: 0x00000000] [des: APHY PSD status - WDM / WDQS / OE BDD ] */
    unsigned aphy_wdq_bdd_dly0;                       /* < 9> [dv: 0x00000000] [des: APHY BDD status - WDQ_BDD_0 ] */
    unsigned aphy_wdq_bdd_dly1;                       /* <10> [dv: 0x00000000] [des: APHY BDD status - WDQ_BDD_1 ] */
    unsigned aphy_rdqs_bdd;                           /* <11> [dv: 0x00000000] [des: APHY PSD status - RDQS_BDD ] */
    unsigned aphy_rdq_bdd_dly0;                       /* <12> [dv: 0x00000000] [des: APHY PSD status - RDQ_BDD_0 ] */
    unsigned aphy_rdq_bdd_dly1;                       /* <13> [dv: 0x00000000] [des: APHY PSD status - RDQ_BDD_1 ] */
    unsigned training_rg_info0;                       /* <14> [dv: 0x00000000] [des: Training  information - RG_PSD_0 ] */
    unsigned training_rg_info1;                       /* <15> [dv: 0x00000000] [des: Training  information - RG_PSD_1 ] */
    unsigned training_eye_info;                       /* <16> [dv: 0x00000000] [des: Training  information - EYE_PSD_0 ] */
    unsigned sw_dyup_psd_ctl_status;                  /* <17> [dv: 0x00000000] [des: PSD SW Dynamic Update - Control/Status ] */
    unsigned sw_dyup_psd;                             /* <18> [dv: 0x00000000] [des: PSD SW Dynamic Update - SW Update Value ] */
    unsigned psd_vt_det_ctl0;                         /* <19> [dv: 0x00000000] [des: PSD VT Detection - VT_CTL_0 ] */
    unsigned psd_vt_det_status;                       /* <20> [dv: 0x00000000] [des: PSD VT Detection - VT_Status ] */
    unsigned ci_info;                                 /* <21> [dv: 0x000000ff] [des: CMD_ISSUE Information - SW_DATA_MASK ] */
    unsigned ci_info_sw_data_p0;                      /* <22> [dv: 0x00000000] [des: CMD_ISSUE Information - SW_DATA_LOW ] */
    unsigned ci_info_sw_data_p1;                      /* <23> [dv: 0x00000000] [des: CMD_ISSUE Information - SW_DATA_HIGH ] */
    unsigned ci_info_wrfifo_dm;                       /* <24> [dv: 0x00000000] [des: CMD_ISSUE Information - WRFIFO_DM ] */
    unsigned ci_info_wrfifo_data_p0;                  /* <25> [dv: 0x00000000] [des: CMD_ISSUE Information - WRFIFO_DATA_LOW ] */
    unsigned ci_info_wrfifo_data_p1;                  /* <26> [dv: 0x00000000] [des: CMD_ISSUE Information - WRFIFO_DATA_HIGH ] */
    unsigned ci_info_rdfifo_data_p0;                  /* <27> [dv: 0x00000000] [des: CMD_ISSUE Information - RDFIFO_DATA_LOW ] */
    unsigned ci_info_rdfifo_data_p1;                  /* <28> [dv: 0x00000000] [des: CMD_ISSUE Information - RDFIFO_DATA_HIGH ] */
    unsigned ci_rsl_info;                             /* <29> [dv: 0x00000f00] [des: CMD ISSUE Information - RSL and read total latency ] */
    unsigned ci_rd_comp_error_cnt;                    /* <30> [dv: 0x00000000] [des: CMD ISSUE Information - Read and compare function error counter ] */
    unsigned reserved_0_12;                           /* <31> [dv: 0x00000000] [des: reserved ] */
    // GROUP 53 [ddr_phy-a_control_unit_g4]
    unsigned serdes_static_setting_1;                 /* < 0> [dv: 0x00000001] [des: SerDes Static Setting ] */
    unsigned serdes_ddl_setting_1;                    /* < 1> [dv: 0x00000021] [des: SerDes DDL Setting ] */
    unsigned data_serdes_training_results_1;          /* < 2> [dv: 0x00000000] [des: Data SerDes training results ] */
    unsigned psd_init_calib_value_1;                  /* < 3> [dv: 0x00000000] [des: PSD initial calibration value ] */
    unsigned aphy_wl_psd_1;                           /* < 4> [dv: 0x00000000] [des: APHY PSD status - WL_PSD ] */
    unsigned aphy_rg_psd_1;                           /* < 5> [dv: 0x00003000] [des: APHY PSD status - RG_PSD ] */
    unsigned aphy_rdqs_psd_1;                         /* < 6> [dv: 0x00000000] [des: APHY PSD status - RDQS_PSD ] */
    unsigned aphy_wdq_psd_1;                          /* < 7> [dv: 0x00000000] [des: APHY PSD status - WDQ_PSD ] */
    unsigned aphy_bdd_value_1;                        /* < 8> [dv: 0x00000000] [des: APHY PSD status - WDM / WDQS / OE BDD ] */
    unsigned aphy_wdq_bdd_dly0_1;                     /* < 9> [dv: 0x00000000] [des: APHY BDD status - WDQ_BDD_0 ] */
    unsigned aphy_wdq_bdd_dly1_1;                     /* <10> [dv: 0x00000000] [des: APHY BDD status - WDQ_BDD_1 ] */
    unsigned aphy_rdqs_bdd_1;                         /* <11> [dv: 0x00000000] [des: APHY PSD status - RDQS_BDD ] */
    unsigned aphy_rdq_bdd_dly0_1;                     /* <12> [dv: 0x00000000] [des: APHY PSD status - RDQ_BDD_0 ] */
    unsigned aphy_rdq_bdd_dly1_1;                     /* <13> [dv: 0x00000000] [des: APHY PSD status - RDQ_BDD_1 ] */
    unsigned training_rg_info0_1;                     /* <14> [dv: 0x00000000] [des: Training  information - RG_PSD_0 ] */
    unsigned training_rg_info1_1;                     /* <15> [dv: 0x00000000] [des: Training  information - RG_PSD_1 ] */
    unsigned training_eye_info_1;                     /* <16> [dv: 0x00000000] [des: Training  information - EYE_PSD_0 ] */
    unsigned sw_dyup_psd_ctl_status_1;                /* <17> [dv: 0x00000000] [des: PSD SW Dynamic Update - Control/Status ] */
    unsigned sw_dyup_psd_1;                           /* <18> [dv: 0x00000000] [des: PSD SW Dynamic Update - SW Update Value ] */
    unsigned psd_vt_det_ctl0_1;                       /* <19> [dv: 0x00000000] [des: PSD VT Detection - VT_CTL_0 ] */
    unsigned psd_vt_det_status_1;                     /* <20> [dv: 0x00000000] [des: PSD VT Detection - VT_Status ] */
    unsigned ci_info_1;                               /* <21> [dv: 0x000000ff] [des: CMD_ISSUE Information - SW_DATA_MASK ] */
    unsigned ci_info_sw_data_p0_1;                    /* <22> [dv: 0x00000000] [des: CMD_ISSUE Information - SW_DATA_LOW ] */
    unsigned ci_info_sw_data_p1_1;                    /* <23> [dv: 0x00000000] [des: CMD_ISSUE Information - SW_DATA_HIGH ] */
    unsigned ci_info_wrfifo_dm_1;                     /* <24> [dv: 0x00000000] [des: CMD_ISSUE Information - WRFIFO_DM ] */
    unsigned ci_info_wrfifo_data_p0_1;                /* <25> [dv: 0x00000000] [des: CMD_ISSUE Information - WRFIFO_DATA_LOW ] */
    unsigned ci_info_wrfifo_data_p1_1;                /* <26> [dv: 0x00000000] [des: CMD_ISSUE Information - WRFIFO_DATA_HIGH ] */
    unsigned ci_info_rdfifo_data_p0_1;                /* <27> [dv: 0x00000000] [des: CMD_ISSUE Information - RDFIFO_DATA_LOW ] */
    unsigned ci_info_rdfifo_data_p1_1;                /* <28> [dv: 0x00000000] [des: CMD_ISSUE Information - RDFIFO_DATA_HIGH ] */
    unsigned ci_rsl_info_1;                           /* <29> [dv: 0x00000f00] [des: CMD ISSUE Information - RSL and read total latency ] */
    unsigned ci_rd_comp_error_cnt_1;                  /* <30> [dv: 0x00000000] [des: CMD ISSUE Information - Read and compare function error counter ] */
    unsigned reserved_0_13;                           /* <31> [dv: 0x00000000] [des: reserved ] */
    // GROUP 54
    unsigned grp54_reserved[32];
    // GROUP 55 [ddc]
    unsigned reserved_0_14;                           /* < 0> [dv: 0x02110060] [des: ] */
    unsigned reserved_1_11;                           /* < 1> [dv:        0x0] [des: ] */
    unsigned reserved_2_10;                           /* < 2> [dv:        0x0] [des: ] */
    unsigned reserved_3_9;                            /* < 3> [dv:        0x0] [des: ] */
    unsigned reserved_4_9;                            /* < 4> [dv:        0x0] [des: ] */
    unsigned i2c_sram_addr;                           /* < 5> [dv:        0x0] [des: ] */
    unsigned reserved_5_9;                            /* < 6> [dv: 0x00009200] [des: ] */
    unsigned ddc_finish_flag;                         /* < 7> [dv:        0x0] [des: ] */
    unsigned ddc_ctrl1;                               /* < 8> [dv:        0x0] [des: ] */
    unsigned ddc_slvaddr;                             /* < 9> [dv:        0x0] [des: ] */
    unsigned ddc_ctrl2;                               /* <10> [dv: 0x00506000] [des: ] */
    unsigned ddc_sram_data;                           /* <11> [dv:        0x0] [des: ] */
    unsigned ddc_set_sram_addr;                       /* <12> [dv:        0x0] [des: ] */
    unsigned ddc_rom_addr;                            /* <13> [dv: 0x00000050] [des: ] */
    unsigned ddc_ddc_addr;                            /* <14> [dv: 0x00000050] [des: ] */
    unsigned ddc_test_data;                           /* <15> [dv:           ] [des: ] */
    unsigned ddc_ddc_i2cslavefilter;                  /* <16> [dv: 0x00000033] [des: ] */
    unsigned ddc_null_msg_source;                     /* <17> [dv: 0x6EBE806E] [des: ] */
    unsigned ddc_ddcci_ctrl1;                         /* <18> [dv: 0x0001006E] [des: ] */
    unsigned ddc_ddcci_ctrl2;                         /* <19> [dv:        0x0] [des: ] */
    unsigned ddc_ddcci_status;                        /* <20> [dv:        0x0] [des: ] */
    unsigned ddc_ddcci_ctrl3;                         /* <21> [dv:        0x0] [des: ] */
    unsigned ddc_ddcci_ctrl0;                         /* <22> [dv: 0x00000000] [des: ] */
    unsigned ddc_ddcci_ctrl4;                         /* <23> [dv: 0x0300017f] [des: ] */
    unsigned ddc_ddcci_ctrl5;                         /* <24> [dv:        0x0] [des: ] */
    unsigned reserved_6_8;                            /* <25> [dv:        0x0] [des: ] */
    unsigned reserved_7_8;                            /* <26> [dv:        0x0] [des: ] */
    unsigned reserved_8_7;                            /* <27> [dv:        0x0] [des: ] */
    unsigned reserved_9_6;                            /* <28> [dv:        0x0] [des: ] */
    unsigned reserved_10_6;                           /* <29> [dv:        0x0] [des: ] */
    unsigned reserved_11_5;                           /* <30> [dv:        0x0] [des: ] */
    unsigned ddc_sram_probe;                          /* <31> [dv: 0x00000c03] [des: ] */
    // GROUP 56
    unsigned grp56_reserved[32];
    // GROUP 57 [i2c0_master]
    unsigned control0;                                /* < 0> [dv: 0x02100060] [des: ] */
    unsigned control1;                                /* < 1> [dv: 0x00000000] [des: ] */
    unsigned control2;                                /* < 2> [dv: 0x152207ff] [des: ] */
    unsigned control3;                                /* < 3> [dv: 0x00000000] [des: ] */
    unsigned control4;                                /* < 4> [dv: 0x00000000] [des: ] */
    unsigned control5;                                /* < 5> [dv: 0x00000000] [des: ] */
    unsigned i2cm_status0;                            /* < 6> [dv: 0x00000000] [des: ] */
    unsigned interrupt;                               /* < 7> [dv:           ] [des: ] */
    unsigned int_en0;                                 /* < 8> [dv: 0x00000800] [des: ] */
    unsigned i2cm_mode;                               /* < 9> [dv: 0x00508002] [des: ] */
    unsigned i2cm_status1;                            /* <10> [dv:           ] [des: ] */
    unsigned i2cm_status2;                            /* <11> [dv:           ] [des: ] */
    unsigned control6;                                /* <12> [dv:        0x0] [des: ] */
    unsigned int_en1;                                 /* <13> [dv:        0x0] [des: ] */
    unsigned i2cm_status3;                            /* <14> [dv:           ] [des: ] */
    unsigned i2cm_status4;                            /* <15> [dv:           ] [des: ] */
    unsigned int_en2;                                 /* <16> [dv:        0x0] [des: ] */
    unsigned control7;                                /* <17> [dv: 0x00010001] [des: ] */
    unsigned reserved0;                               /* <18> [dv:        0x0] [des: ] */
    unsigned reserved1;                               /* <19> [dv:        0x0] [des: ] */
    unsigned reserved2;                               /* <20> [dv:        0x0] [des: ] */
    unsigned reserved3;                               /* <21> [dv:        0x0] [des: ] */
    unsigned reserved4;                               /* <22> [dv:        0x0] [des: ] */
    unsigned reserved5;                               /* <23> [dv:        0x0] [des: ] */
    unsigned data00_03;                               /* <24> [dv:        0x0] [des: ] */
    unsigned data04_07;                               /* <25> [dv:        0x0] [des: ] */
    unsigned data08_11;                               /* <26> [dv:        0x0] [des: ] */
    unsigned data12_15;                               /* <27> [dv:        0x0] [des: ] */
    unsigned data16_19;                               /* <28> [dv:        0x0] [des: ] */
    unsigned data20_23;                               /* <29> [dv:        0x0] [des: ] */
    unsigned data24_27;                               /* <30> [dv:        0x0] [des: ] */
    unsigned data28_31;                               /* <31> [dv:        0x0] [des: ] */
    // GROUP 58 [i2c0_master]
    unsigned control0_1;                              /* < 0> [dv: 0x02100060] [des: ] */
    unsigned control1_1;                              /* < 1> [dv: 0x00000000] [des: ] */
    unsigned control2_1;                              /* < 2> [dv: 0x152207ff] [des: ] */
    unsigned control3_1;                              /* < 3> [dv: 0x00000000] [des: ] */
    unsigned control4_1;                              /* < 4> [dv: 0x00000000] [des: ] */
    unsigned control5_1;                              /* < 5> [dv: 0x00000000] [des: ] */
    unsigned i2cm_status0_1;                          /* < 6> [dv: 0x00000000] [des: ] */
    unsigned interrupt_1;                             /* < 7> [dv:           ] [des: ] */
    unsigned int_en0_1;                               /* < 8> [dv: 0x00000800] [des: ] */
    unsigned i2cm_mode_1;                             /* < 9> [dv: 0x00508002] [des: ] */
    unsigned i2cm_status1_1;                          /* <10> [dv:           ] [des: ] */
    unsigned i2cm_status2_1;                          /* <11> [dv:           ] [des: ] */
    unsigned control6_1;                              /* <12> [dv:        0x0] [des: ] */
    unsigned int_en1_1;                               /* <13> [dv:        0x0] [des: ] */
    unsigned i2cm_status3_1;                          /* <14> [dv:           ] [des: ] */
    unsigned i2cm_status4_1;                          /* <15> [dv:           ] [des: ] */
    unsigned int_en2_1;                               /* <16> [dv:        0x0] [des: ] */
    unsigned control7_1;                              /* <17> [dv: 0x00010001] [des: ] */
    unsigned reserved0_1;                             /* <18> [dv:        0x0] [des: ] */
    unsigned reserved1_1;                             /* <19> [dv:        0x0] [des: ] */
    unsigned reserved2_1;                             /* <20> [dv:        0x0] [des: ] */
    unsigned reserved3_1;                             /* <21> [dv:        0x0] [des: ] */
    unsigned reserved4_1;                             /* <22> [dv:        0x0] [des: ] */
    unsigned reserved5_1;                             /* <23> [dv:        0x0] [des: ] */
    unsigned data00_03_1;                             /* <24> [dv:        0x0] [des: ] */
    unsigned data04_07_1;                             /* <25> [dv:        0x0] [des: ] */
    unsigned data08_11_1;                             /* <26> [dv:        0x0] [des: ] */
    unsigned data12_15_1;                             /* <27> [dv:        0x0] [des: ] */
    unsigned data16_19_1;                             /* <28> [dv:        0x0] [des: ] */
    unsigned data20_23_1;                             /* <29> [dv:        0x0] [des: ] */
    unsigned data24_27_1;                             /* <30> [dv:        0x0] [des: ] */
    unsigned data28_31_1;                             /* <31> [dv:        0x0] [des: ] */
    // GROUP 59
    unsigned grp59_reserved[32];
    // GROUP 60 [aud_reg_g0]
    unsigned audif_ctrl;                              /* < 0> [dv: 0x00000000] [des: AUD Interface Control] */
    unsigned aud_enable;                              /* < 1> [dv: 0x001f0000] [des: Audio FIFO Request Enable] */
    unsigned pcm_cfg;                                 /* < 2> [dv: 0x00000000] [des: Audio PCM ($\rm {I^2S] */
    unsigned i2s_mute_flag_ctrl;                      /* < 3> [dv: 0x00000000] [des: Mute Flag of I2S TX Module] */
    unsigned ext_adc_cfg;                             /* < 4> [dv: 0x00000000] [des: External ADC ($\rm {I^2S] */
    unsigned int_dac_ctrl0;                           /* < 5> [dv: 0xc423877f] [des: Internal DAC Control 0 (ACODEC_CFG0)] */
    unsigned int_adc_ctrl0;                           /* < 6> [dv: 0x5c1e5c1e] [des: Internal ADC Config 0] */
    unsigned adc_in_path_switch;                      /* < 7> [dv: 0x00000000] [des: ADC Input Path Switch] */
    unsigned int_adc_dac_cfg;                         /* < 8> [dv: 0x0010004d] [des: Internal ADC and DAC ($\rm {I^2S] */
    unsigned g60addr9_reserved;                       /* < 9> [dv: 0x00000000] [des: Reserved] */
    unsigned iec_cfg;                                 /* <10> [dv: 0x00004000] [des: S/PDIF Configuration] */
    unsigned iec0_valid_out;                          /* <11> [dv: 0x00000000] [des: Valid Bit for S/PDIF TX0] */
    unsigned iec0_par0_out;                           /* <12> [dv: 0x00000000] [des: Channel Status of S/PDIF TX0] */
    unsigned iec0_par1_out;                           /* <13> [dv: 0x00000000] [des: Channel Status of S/PDIF TX0] */
    unsigned iec1_valid_out;                          /* <14> [dv: 0x00000000] [des: Valid Bit for S/PDIF TX1] */
    unsigned iec1_par0_out;                           /* <15> [dv: 0x00000000] [des: Channel Status of S/PDIF TX1] */
    unsigned iec1_par1_out;                           /* <16> [dv: 0x00000000] [des: Channel Status of S/PDIF TX1] */
    unsigned iec0_rx_debug_info;                      /* <17> [dv: 0x00000000] [des: Debug Information of S/PDIF RX0] */
    unsigned iec0_valid_in;                           /* <18> [dv: 0x00000000] [des: Valid Bit of S/PDIF RX0] */
    unsigned iec0_par0_in;                            /* <19> [dv: 0x00000000] [des: Channel Status of S/PDIF RX0] */
    unsigned iec0_par1_in;                            /* <20> [dv: 0x00000000] [des: Channel Status of S/PDIF RX0] */
    unsigned iec1_rx_debug_info;                      /* <21> [dv: 0x00000000] [des: Debug Information of S/PDIF RX1] */
    unsigned iec1_valid_in;                           /* <22> [dv: 0x00000000] [des: Valid Bit of S/PDIF RX1] */
    unsigned iec1_par0_in;                            /* <23> [dv: 0x00000000] [des: Channel Status of S/PDIF RX1] */
    unsigned iec1_par1_in;                            /* <24> [dv: 0x00000000] [des: Channel Status of S/PDIF RX1] */
    unsigned iec2_rx_debug_info;                      /* <25> [dv: 0x00000000] [des: Debug Information of S/PDIF RX2] */
    unsigned iec2_valid_in;                           /* <26> [dv: 0x00000000] [des: Valid Bit of S/PDIF RX2] */
    unsigned iec2_par0_in;                            /* <27> [dv: 0x00000000] [des: Channel Status of S/PDIF RX2] */
    unsigned iec2_par1_in;                            /* <28> [dv: 0x00000000] [des: Channel Status of S/PDIF RX2] */
    unsigned g60addr29_reserved;                      /* <29> [dv: 0x00000000] [des: SACD Channel Number (Reserved)] */
    unsigned iec_tx_user_wdata;                       /* <30> [dv: 0x00000000] [des: IEC Tx User FIFO Data] */
    unsigned iec_tx_user_ctrl;                        /* <31> [dv: 0x00000044] [des: IEC Tx User FIFO Control] */
    // GROUP 61 [aud_reg_g1]
    unsigned adcp_ch_enable;                          /* < 0> [dv: 0x00000000] [des: ADCPRC Configuration Group 1] */
    unsigned adcp_fubypass;                           /* < 1> [dv: 0x00007777] [des: ADCPRC Configuration Group 2] */
    unsigned adcp_mode_ctrl;                          /* < 2> [dv: 0x00000000] [des: ADCPRC Mode Control] */
    unsigned adcp_init_ctrl;                          /* < 3> [dv:     0x0000] [des: ADCP Initialization Control] */
    unsigned adcp_coeff_din;                          /* < 4> [dv: 0x00000000] [des: Coefficient Data Input] */
    unsigned adcp_agc_cfg;                            /* < 5> [dv: 0x00650200] [des: ADCPRC AGC Configuration of Ch0/1] */
    unsigned adcp_agc_cfg2;                           /* < 6> [dv: 0x00650200] [des: ADCPRC AGC Configuration of Ch2/3] */
    unsigned adcp_gain_0;                             /* < 7> [dv: 0x00800000] [des: ADCPRC System Gain0] */
    unsigned adcp_gain_1;                             /* < 8> [dv: 0x00800000] [des: ADCP System Gain1] */
    unsigned adcp_gain_2;                             /* < 9> [dv: 0x00800000] [des: ADCP System Gain2] */
    unsigned adcp_gain_3;                             /* <10> [dv: 0x00800000] [des: ADCP System Gain3] */
    unsigned adcp_risc_gain;                          /* <11> [dv: 0x00001111] [des: ADCP RISC Gain] */
    unsigned adcp_mic_l;                              /* <12> [dv: 0x00000000] [des: ADCPRC Microphone-in Left Channel Data] */
    unsigned adcp_mic_r;                              /* <13> [dv: 0x00000000] [des: ADCPRC Microphone-in Right Channel Data] */
    unsigned adcp_agc_gain;                           /* <14> [dv: 0x00000000] [des: ADCPRC AGC Gain] */
    unsigned g61addr15_reserved;                      /* <15> [dv: 0x00000000] [des: Reserved] */
    unsigned aud_apt_mode;                            /* <16> [dv: 0x00000001] [des: Audio Playback Timer Mode] */
    unsigned aud_apt_data;                            /* <17> [dv:     0x0000] [des: Audio Playback Timer] */
    unsigned aud_apt_parameter;                       /* <18> [dv: 0x00000000] [des: Audio Playback Timer Parameter] */
    unsigned aud_audhwya2;                            /* <19> [dv: 0x00000000] [des: DRAM Base Address Offset2] */
    unsigned aud_audhwya;                             /* <20> [dv: 0x00000000] [des: DRAM Base Address Offset] */
    unsigned aud_inc_0;                               /* <21> [dv: 0x00000000] [des: DMA Counter Increment/Decrement] */
    unsigned aud_delta_0;                             /* <22> [dv: 0x00000000] [des: Delta Value] */
    unsigned aud_fifo_enable;                         /* <23> [dv: 0x00000000] [des: Audio FIFO Enable] */
    unsigned aud_fifo_mode;                           /* <24> [dv: 0x00000000] [des: FIFO Mode Control] */
    unsigned aud_fifo_support;                        /* <25> [dv: 0x000F7EFF] [des: Supported FIFOs (Debug Function)] */
    unsigned aud_fifo_reset;                          /* <26> [dv: 0x00000000] [des: Host FIFO Reset] */
    unsigned aud_chk_ctrl;                            /* <27> [dv: 0x00000100] [des: Checksum Control (Debug Function)] */
    unsigned aud_new_pts;                             /* <28> [dv: 0x00000000] [des: New PTS] */
    unsigned aud_new_pts_ptr;                         /* <29> [dv: 0x00000000] [des: FIFO PTR Related to New PTS] */
    unsigned aud_embedded_input_ctrl;                 /* <30> [dv: 0x00000000] [des: Embedded Input Control (Debug Function)] */
    unsigned aud_misc_ctrl;                           /* <31> [dv:     0x0801] [des: Miscellaneous Control] */
    // GROUP 62 [aud_reg_g2]
    unsigned aud_ext_dac_xck_cfg;                     /* < 0> [dv: 0x00000000] [des: External DAC XCK Configuration] */
    unsigned aud_ext_dac_bck_cfg;                     /* < 1> [dv: 0x00000000] [des: External DAC BCK Configuration] */
    unsigned aud_iec0_bclk_cfg;                       /* < 2> [dv: 0x00000000] [des: S/PDIF TX0 BCLK Configuration] */
    unsigned aud_ext_adc_xck_cfg;                     /* < 3> [dv: 0x00000000] [des: External ADC XCK Configuration] */
    unsigned aud_ext_adc_bck_cfg;                     /* < 4> [dv: 0x00000000] [des: External ADC BCK Configuration] */
    unsigned aud_int_adc_xck_cfg;                     /* < 5> [dv: 0x00000000] [des: Internal ADC XCK Configuration] */
    unsigned g62addr6_reserved;                       /* < 6> [dv: 0x00000000] [des: Reserved] */
    unsigned aud_int_dac_xck_cfg;                     /* < 7> [dv: 0x00000000] [des: Internal DAC XCK Configuration] */
    unsigned aud_int_dac_bck_cfg;                     /* < 8> [dv: 0x00000000] [des: Internal DAC BCK Configuration] */
    unsigned aud_iec1_bclk_cfg;                       /* < 9> [dv: 0x00000000] [des: S/PDIF TX1 BCLK Configuration] */
    unsigned g62addr10_reserved;                      /* <10> [dv: 0x00000000] [des: Reserved] */
    unsigned aud_pcm_iec_bclk_cfg;                    /* <11> [dv: 0x00000000] [des: PCM S/PDIF TX BCLK Configuration] */
    unsigned aud_xck_osr104_cfg;                      /* <12> [dv: 0x00000000] [des: Internal DAC XCK OSR104 Configuration] */
    unsigned aud_hdmi_tx_mclk_cfg;                    /* <13> [dv: 0x00000000] [des: HDMI TX MCLK Configuration] */
    unsigned aud_hdmi_tx_bclk_cfg;                    /* <14> [dv: 0x00000000] [des: HDMI TX BCLK Configuration] */
    unsigned hdmi_tx_pcm_cfg;                         /* <15> [dv: 0x0000004d] [des: HDMI TX PCM ($\rm {I^2S] */
    unsigned hdmi_rx_cfg;                             /* <16> [dv: 0x0000004d] [des: HDMI RX ($\rm {I^2S] */
    unsigned aud_aadc_agc_cfg0;                       /* <17> [dv: 0xf007f007] [des: DAGC0/1 Config0] */
    unsigned aud_aadc_agc_cfg1;                       /* <18> [dv: 0x80FF80FF] [des: DAGC0/1 Config1] */
    unsigned aud_aadc_agc_cfg2;                       /* <19> [dv: 0x00F000F0] [des: DAGC0/1 Config2] */
    unsigned aud_aadc_agc_cfg3;                       /* <20> [dv: 0x08000800] [des: DAGC0/1 Config3] */
    unsigned int_adc_ctrl3;                           /* <21> [dv: 0x3f245c1e] [des: Internal ADC Config 3] */
    unsigned int_adc_ctrl2;                           /* <22> [dv: 0x06de1e1e] [des: Internal ADC Config 2] */
    unsigned int_dac_ctrl2;                           /* <23> [dv: 0x1e1e1e1e] [des: Internal DAC Control 2] */
    unsigned g62addr24_reserved;                      /* <24> [dv: 0x00000000] [des: Reserved] */
    unsigned int_dac_ctrl1;                           /* <25> [dv: 0x00081e40] [des: Internal DAC Control 1] */
    unsigned aud_force_cken;                          /* <26> [dv: 0x00000000] [des: AUD Force CKEN] */
    unsigned aud_recovery_ctrl;                       /* <27> [dv: 0x00000001] [des: AUD Recovery Control] */
    unsigned pcm_iec_par0_out;                        /* <28> [dv: 0x00000000] [des: Channel Status of PCM S/PDIF TX] */
    unsigned pcm_iec_par1_out;                        /* <29> [dv: 0x00000000] [des: Channel Status of PCM S/PDIF TX and Configurations] */
    unsigned dmactrl_cnt_inc_1;                       /* <30> [dv: 0x00000000] [des: DMA Counter Increment/Decrement] */
    unsigned dmactrl_cnt_delta_1;                     /* <31> [dv: 0x00000000] [des: Delta Value] */
    // GROUP 63 [aud_reg_g3]
    unsigned bt_ifx_cfg;                              /* < 0> [dv:     0x0000] [des: BlueTooth IFX Config ] */
    unsigned bt_i2s_cfg;                              /* < 1> [dv:     0x0001] [des: BT I2S Format Configuration] */
    unsigned bt_xck_cfg;                              /* < 2> [dv:     0x0000] [des: BlueTooth XCK Config ] */
    unsigned bt_bck_cfg;                              /* < 3> [dv:     0x0000] [des: BlueTooth BCK Config ] */
    unsigned bt_sync_cfg;                             /* < 4> [dv:     0x1010] [des: BlueTooth SYNC Config ] */
    unsigned ifx0_sampling_rate_cnt;                  /* < 5> [dv: 0x00000000] [des: IFX0_SAMPLING_RATE_CNT] */
    unsigned ifx1_sampling_rate_cnt;                  /* < 6> [dv: 0x00000000] [des: IFX1_SAMPLING_RATE_CNT] */
    unsigned asrc_ctrl;                               /* < 7> [dv: 0x00000000] [des: ASRC_CTRL] */
    unsigned g63addr8_reserved;                       /* < 8> [dv: 0x00000000] [des: Reserved] */
    unsigned g63addr9_reserved;                       /* < 9> [dv: 0x00000000] [des: Reserved] */
    unsigned g63addr10_reserved;                      /* <10> [dv: 0x00000000] [des: Reserved] */
    unsigned g63addr11_reserved;                      /* <11> [dv: 0x00000000] [des: Reserved] */
    unsigned g63addr12_reserved;                      /* <12> [dv: 0x00000000] [des: Reserved] */
    unsigned pgag_sample_cnt_0l;                      /* <13> [dv: 0x00000000] [des: ADAC_PGA_GAIN ctrl monitor sample counter (debug use.)] */
    unsigned adac_pga_gain_0l_ctrl;                   /* <14> [dv: 0x00000000] [des: ADAC_PGA_GAIN_0L_CTRL] */
    unsigned adac_pga_gain_0r_ctrl;                   /* <15> [dv: 0x00000000] [des: ADAC_PGA_GAIN_0R_CTRL] */
    unsigned adac_pga_gain_1l_ctrl;                   /* <16> [dv: 0x00000000] [des: ADAC_PGA_GAIN_1L_CTRL] */
    unsigned adac_pga_gain_1r_ctrl;                   /* <17> [dv: 0x00000000] [des: ADAC_PGA_GAIN_1R_CTRL] */
    unsigned adac_pga_gain_2r_ctrl;                   /* <18> [dv: 0x00000000] [des: ADAC_PGA_GAIN_2R_CTRL] */
    unsigned aud_aadc_agc_status;                     /* <19> [dv:     0x0000] [des: DAGC0/1/2 STATUS] */
    unsigned aud_aadc_agc2_cfg0;                      /* <20> [dv:     0xf007] [des: DAGC2 config0] */
    unsigned aud_aadc_agc2_cfg1;                      /* <21> [dv:     0x80FF] [des: DAGC2 config1] */
    unsigned aud_aadc_agc2_cfg2;                      /* <22> [dv:     0x00F0] [des: DAGC2 config2] */
    unsigned aud_aadc_agc2_cfg3;                      /* <23> [dv:     0x0800] [des: DAGC2 config3] */
    unsigned aud_opt_test_pat_1;                      /* <24> [dv: 0x97634502] [des: AUD_OPT_TEST_PAT] */
    unsigned dsp_opt_lsb;                             /* <25> [dv:     0x0000] [des: DSP_OPT_LSB] */
    unsigned dsp_opt_msb;                             /* <26> [dv:     0x0000] [des: DSP_OPT_MSB] */
    unsigned int_adc_ctrl1;                           /* <27> [dv:     0x0000] [des: Internal ADC Config1] */
    unsigned other_status;                            /* <28> [dv:     0x0000] [des: aud other status] */
    unsigned cdrpll_losd_ctrl;                        /* <29> [dv: 0x00001030] [des: CDRPLL_LOSD_CTRL] */
    unsigned losd_release_cnt;                        /* <30> [dv: 0x02100000] [des: LOSD_RELEASE_CNT] */
    unsigned other_ctrl;                              /* <31> [dv: 0x00000000] [des: aud other ctrl] */
    // GROUP 64 [aud_dma_g0]
    unsigned aud_a0_base;                             /* < 0> [dv: 0x00000000] [des: Base Address] */
    unsigned aud_a0_length;                           /* < 1> [dv: 0x00000000] [des: FIFO Length] */
    unsigned aud_a0_ptr;                              /* < 2> [dv: 0x00000000] [des: FIFO Pointer] */
    unsigned aud_a0_cnt;                              /* < 3> [dv: 0x00000000] [des: FIFO Count] */
    unsigned aud_a1_base;                             /* < 4> [dv: 0x00000000] [des: Base Address] */
    unsigned aud_a1_length;                           /* < 5> [dv: 0x00000000] [des: FIFO Length] */
    unsigned aud_a1_ptr;                              /* < 6> [dv: 0x00000000] [des: FIFO Pointer] */
    unsigned aud_a1_cnt;                              /* < 7> [dv: 0x00000000] [des: FIFO Count] */
    unsigned aud_a2_base;                             /* < 8> [dv: 0x00000000] [des: Base Address] */
    unsigned aud_a2_length;                           /* < 9> [dv: 0x00000000] [des: FIFO Length] */
    unsigned aud_a2_ptr;                              /* <10> [dv: 0x00000000] [des: FIFO Pointer] */
    unsigned aud_a2_cnt;                              /* <11> [dv: 0x00000000] [des: FIFO Count] */
    unsigned aud_a3_base;                             /* <12> [dv: 0x00000000] [des: Base Address] */
    unsigned aud_a3_length;                           /* <13> [dv: 0x00000000] [des: FIFO Length] */
    unsigned aud_a3_ptr;                              /* <14> [dv: 0x00000000] [des: FIFO Pointer] */
    unsigned aud_a3_cnt;                              /* <15> [dv: 0x00000000] [des: FIFO Count] */
    unsigned aud_a4_base;                             /* <16> [dv: 0x00000000] [des: Base Address] */
    unsigned aud_a4_length;                           /* <17> [dv: 0x00000000] [des: FIFO Length] */
    unsigned aud_a4_ptr;                              /* <18> [dv: 0x00000000] [des: FIFO Pointer] */
    unsigned aud_a4_cnt;                              /* <19> [dv: 0x00000000] [des: FIFO Count] */
    unsigned aud_a5_base;                             /* <20> [dv: 0x00000000] [des: Base Address] */
    unsigned aud_a5_length;                           /* <21> [dv: 0x00000000] [des: FIFO Length] */
    unsigned aud_a5_ptr;                              /* <22> [dv: 0x00000000] [des: FIFO Pointer] */
    unsigned aud_a5_cnt;                              /* <23> [dv: 0x00000000] [des: FIFO Count] */
    unsigned aud_a6_base;                             /* <24> [dv: 0x00000000] [des: Base Address] */
    unsigned aud_a6_length;                           /* <25> [dv: 0x00000000] [des: FIFO Length] */
    unsigned aud_a6_ptr;                              /* <26> [dv: 0x00000000] [des: FIFO Pointer] */
    unsigned aud_a6_cnt;                              /* <27> [dv: 0x00000000] [des: FIFO Count] */
    unsigned aud_a7_base;                             /* <28> [dv: 0x00000000] [des: Base Address] */
    unsigned aud_a7_length;                           /* <29> [dv: 0x00000000] [des: FIFO Length] */
    unsigned aud_a7_ptr;                              /* <30> [dv: 0x00000000] [des: FIFO Pointer] */
    unsigned aud_a7_cnt;                              /* <31> [dv: 0x00000000] [des: FIFO Count] */
    // GROUP 65 [aud_dma_g1]
    unsigned aud_a8_base;                             /* < 0> [dv: 0x00000000] [des: Base Address] */
    unsigned aud_a8_length;                           /* < 1> [dv: 0x00000000] [des: FIFO Length] */
    unsigned aud_a8_ptr;                              /* < 2> [dv: 0x00000000] [des: FIFO Pointer] */
    unsigned aud_a8_cnt;                              /* < 3> [dv: 0x00000000] [des: FIFO Count] */
    unsigned aud_a9_base;                             /* < 4> [dv: 0x00000000] [des: Base Address] */
    unsigned aud_a9_length;                           /* < 5> [dv: 0x00000000] [des: FIFO Length] */
    unsigned aud_a9_ptr;                              /* < 6> [dv: 0x00000000] [des: FIFO Pointer] */
    unsigned aud_a9_cnt;                              /* < 7> [dv: 0x00000000] [des: FIFO Count] */
    unsigned aud_a10_base;                            /* < 8> [dv: 0x00000000] [des: Base Address] */
    unsigned aud_a10_length;                          /* < 9> [dv: 0x00000000] [des: FIFO Length] */
    unsigned aud_a10_ptr;                             /* <10> [dv: 0x00000000] [des: FIFO Pointer] */
    unsigned aud_a10_cnt;                             /* <11> [dv: 0x00000000] [des: FIFO Count] */
    unsigned aud_a11_base;                            /* <12> [dv: 0x00000000] [des: Base Address] */
    unsigned aud_a11_length;                          /* <13> [dv: 0x00000000] [des: FIFO Length] */
    unsigned aud_a11_ptr;                             /* <14> [dv: 0x00000000] [des: FIFO Pointer] */
    unsigned aud_a11_cnt;                             /* <15> [dv: 0x00000000] [des: FIFO Count] */
    unsigned aud_a12_base;                            /* <16> [dv: 0x00000000] [des: Base Address] */
    unsigned aud_a12_length;                          /* <17> [dv: 0x00000000] [des: FIFO Length] */
    unsigned aud_a12_ptr;                             /* <18> [dv: 0x00000000] [des: FIFO Pointer] */
    unsigned aud_a12_cnt;                             /* <19> [dv: 0x00000000] [des: FIFO Count] */
    unsigned aud_a13_base;                            /* <20> [dv: 0x00000000] [des: Base Address] */
    unsigned aud_a13_length;                          /* <21> [dv: 0x00000000] [des: FIFO Length] */
    unsigned aud_a13_ptr;                             /* <22> [dv: 0x00000000] [des: FIFO Pointer] */
    unsigned aud_a13_cnt;                             /* <23> [dv: 0x00000000] [des: FIFO Count] */
    unsigned aud_a14_base;                            /* <24> [dv: 0x00000000] [des: Base Address] */
    unsigned aud_a14_length;                          /* <25> [dv: 0x00000000] [des: FIFO Length] */
    unsigned aud_a14_ptr;                             /* <26> [dv: 0x00000000] [des: FIFO Pointer] */
    unsigned aud_a14_cnt;                             /* <27> [dv: 0x00000000] [des: FIFO Count] */
    unsigned aud_a15_base;                            /* <28> [dv: 0x00000000] [des: Base Address] */
    unsigned aud_a15_length;                          /* <29> [dv: 0x00000000] [des: FIFO Length] */
    unsigned aud_a15_ptr;                             /* <30> [dv: 0x00000000] [des: FIFO Pointer] */
    unsigned aud_a15_cnt;                             /* <31> [dv: 0x00000000] [des: FIFO Count] */
    // GROUP 66 [aud_dma_g2]
    unsigned aud_a16_base;                            /* < 0> [dv: 0x00000000] [des: Base Address] */
    unsigned aud_a16_length;                          /* < 1> [dv: 0x00000000] [des: FIFO Length] */
    unsigned aud_a16_ptr;                             /* < 2> [dv: 0x00000000] [des: FIFO Pointer] */
    unsigned aud_a16_cnt;                             /* < 3> [dv: 0x00000000] [des: FIFO Count] */
    unsigned aud_a17_base;                            /* < 4> [dv: 0x00000000] [des: Base Address] */
    unsigned aud_a17_length;                          /* < 5> [dv: 0x00000000] [des: FIFO Length] */
    unsigned aud_a17_ptr;                             /* < 6> [dv: 0x00000000] [des: FIFO Pointer] */
    unsigned aud_a17_cnt;                             /* < 7> [dv: 0x00000000] [des: FIFO Count] */
    unsigned aud_a18_base;                            /* < 8> [dv: 0x00000000] [des: Base Address] */
    unsigned aud_a18_length;                          /* < 9> [dv: 0x00000000] [des: FIFO Length] */
    unsigned aud_a18_ptr;                             /* <10> [dv: 0x00000000] [des: FIFO Pointer] */
    unsigned aud_a18_cnt;                             /* <11> [dv: 0x00000000] [des: FIFO Count] */
    unsigned aud_a19_base;                            /* <12> [dv: 0x00000000] [des: Base Address] */
    unsigned aud_a19_length;                          /* <13> [dv: 0x00000000] [des: FIFO Length] */
    unsigned aud_a19_ptr;                             /* <14> [dv: 0x00000000] [des: FIFO Pointer] */
    unsigned aud_a19_cnt;                             /* <15> [dv: 0x00000000] [des: FIFO Count] */
    unsigned g66addr16_reserved0;                     /* <16> [dv: 0x00000000] [des: Reserved] */
    unsigned g66addr17_reserved0;                     /* <17> [dv: 0x00000000] [des: Reserved] */
    unsigned g66addr18_reserved0;                     /* <18> [dv: 0x00000000] [des: Reserved] */
    unsigned g66addr19_reserved0;                     /* <19> [dv: 0x00000000] [des: Reserved] */
    unsigned g66addr20_reserved0;                     /* <20> [dv: 0x00000000] [des: Reserved] */
    unsigned g66addr21_reserved0;                     /* <21> [dv: 0x00000000] [des: Reserved] */
    unsigned g66addr22_reserved0;                     /* <22> [dv: 0x00000000] [des: Reserved] */
    unsigned g66addr23_reserved0;                     /* <23> [dv: 0x00000000] [des: Reserved] */
    unsigned g66addr24_reserved0;                     /* <24> [dv: 0x00000000] [des: Reserved] */
    unsigned g66addr25_reserved0;                     /* <25> [dv: 0x00000000] [des: Reserved] */
    unsigned g66addr26_reserved0;                     /* <26> [dv: 0x00000000] [des: Reserved] */
    unsigned g66addr27_reserved0;                     /* <27> [dv: 0x00000000] [des: Reserved] */
    unsigned g66addr28_reserved0;                     /* <28> [dv: 0x00000000] [des: Reserved] */
    unsigned g66addr29_reserved0;                     /* <29> [dv: 0x00000000] [des: Reserved] */
    unsigned g66addr30_reserved0;                     /* <30> [dv: 0x00000000] [des: Reserved] */
    unsigned g66addr31_reserved0;                     /* <31> [dv: 0x00000000] [des: Reserved] */
    // GROUP 67 [aud_grm]
    unsigned aud_grm_master_gain;                     /* < 0> [dv: 0x00000000] [des: Gain Control] */
    unsigned aud_grm_gain_control_0;                  /* < 1> [dv: 0x80808080] [des: Gain Control] */
    unsigned aud_grm_gain_control_1;                  /* < 2> [dv: 0x00000000] [des: Gain Control] */
    unsigned aud_grm_gain_control_2;                  /* < 3> [dv: 0x00000000] [des: Gain Control] */
    unsigned aud_grm_gain_control_3;                  /* < 4> [dv: 0x00000000] [des: Gain Control] */
    unsigned aud_grm_gain_control_4;                  /* < 5> [dv: 0x00000000] [des: Gain Control] */
    unsigned aud_grm_mix_control_0;                   /* < 6> [dv: 0x00000000] [des: Mixer Setting] */
    unsigned aud_grm_mix_control_1;                   /* < 7> [dv: 0x00000000] [des: Mixer Setting] */
    unsigned aud_grm_mix_control_2;                   /* < 8> [dv: 0x00000000] [des: Mixer Setting] */
    unsigned aud_grm_switch_0;                        /* < 9> [dv: 0x00000000] [des: Channel Switch] */
    unsigned aud_grm_switch_1;                        /* <10> [dv: 0x00000000] [des: Channel Switch] */
    unsigned aud_grm_switch_int;                      /* <11> [dv: 0x00000000] [des: INT DAC Channel Switch] */
    unsigned aud_grm_delta_volume;                    /* <12> [dv: 0x00000000] [des: Gain Update] */
    unsigned aud_grm_delta_ramp_pcm;                  /* <13> [dv: 0x00000000] [des: Gain Update] */
    unsigned aud_grm_delta_ramp_risc;                 /* <14> [dv: 0x00000000] [des: Gain Update] */
    unsigned aud_grm_delta_ramp_linein;               /* <15> [dv: 0x00000000] [des: Gain Update] */
    unsigned aud_grm_other;                           /* <16> [dv: 0x00000000] [des: Other Setting] */
    unsigned aud_grm_gain_control_5;                  /* <17> [dv: 0x80808080] [des: Gain Control] */
    unsigned aud_grm_gain_control_6;                  /* <18> [dv: 0x80808080] [des: Gain Control] */
    unsigned aud_grm_gain_control_7;                  /* <19> [dv: 0x80000000] [des: Gain Control] */
    unsigned aud_grm_gain_control_8;                  /* <20> [dv: 0x80000000] [des: Gain Control] */
    unsigned aud_grm_fifo_eflag;                      /* <21> [dv: 0x00000000] [des: FIFO Error Flag] */
    unsigned aud_grm_gain_control_9;                  /* <22> [dv: 0x80008000] [des: IEC Tx Interface Gain] */
    unsigned aud_grm_gain_control_10;                 /* <23> [dv: 0x00008000] [des: I2S Tx Interface Gain] */
    unsigned aud_grm_switch_hdmi;                     /* <24> [dv: 0x00000000] [des: HDMI DAC Channel Switch] */
    unsigned g67addr25_reserved;                      /* <25> [dv: 0x00000000] [des: Reserved] */
    unsigned g67addr26_reserved;                      /* <26> [dv: 0x00000000] [des: Reserved] */
    unsigned g67addr27_reserved;                      /* <27> [dv: 0x00000000] [des: Reserved] */
    unsigned g67addr28_reserved;                      /* <28> [dv: 0x00000000] [des: Reserved] */
    unsigned g67addr29_reserved;                      /* <29> [dv: 0x00000000] [des: Reserved] */
    unsigned g67addr30_reserved;                      /* <30> [dv: 0x00000000] [des: Reserved] */
    unsigned g67addr31_reserved;                      /* <31> [dv: 0x00000000] [des: Reserved] */
    // GROUP 68 [aud_monitor]
    unsigned g68addr0_reserved;                       /* < 0> [dv: 0x00000000] [des: Reserved] */
    unsigned g68addr1_reserved;                       /* < 1> [dv: 0x00000000] [des: Reserved] */
    unsigned g68addr2_reserved;                       /* < 2> [dv: 0x00000000] [des: Reserved] */
    unsigned g68addr3_reserved;                       /* < 3> [dv: 0x00000000] [des: Reserved] */
    unsigned g68addr4_reserved;                       /* < 4> [dv: 0x00000000] [des: Reserved] */
    unsigned g68addr5_reserved;                       /* < 5> [dv: 0x00000000] [des: Reserved] */
    unsigned g68addr6_reserved;                       /* < 6> [dv: 0x00000000] [des: Reserved] */
    unsigned g68addr7_reserved;                       /* < 7> [dv: 0x00000000] [des: Reserved] */
    unsigned g68addr8_reserved;                       /* < 8> [dv: 0x00000000] [des: Reserved] */
    unsigned g68addr9_reserved;                       /* < 9> [dv: 0x00000000] [des: Reserved] */
    unsigned g68addr10_reserved;                      /* <10> [dv: 0x00000000] [des: Reserved] */
    unsigned g68addr11_reserved;                      /* <11> [dv: 0x00000000] [des: Reserved] */
    unsigned g68addr12_reserved;                      /* <12> [dv: 0x00000000] [des: Reserved] */
    unsigned g68addr13_reserved;                      /* <13> [dv: 0x00000000] [des: Reserved] */
    unsigned g68addr14_reserved;                      /* <14> [dv: 0x00000000] [des: Reserved] */
    unsigned g68addr15_reserved;                      /* <15> [dv: 0x00000000] [des: Reserved] */
    unsigned g68addr16_reserved;                      /* <16> [dv: 0x00000000] [des: Reserved] */
    unsigned g68addr17_reserved;                      /* <17> [dv: 0x00000000] [des: Reserved] */
    unsigned g68addr18_reserved;                      /* <18> [dv: 0x00000000] [des: Reserved] */
    unsigned g68addr19_reserved;                      /* <19> [dv: 0x00000000] [des: Reserved] */
    unsigned g68addr20_reserved;                      /* <20> [dv: 0x00000000] [des: Reserved] */
    unsigned g68addr21_reserved;                      /* <21> [dv: 0x00000000] [des: Reserved] */
    unsigned g68addr22_reserved;                      /* <22> [dv: 0x00000000] [des: Reserved] */
    unsigned g68addr23_reserved;                      /* <23> [dv: 0x00000000] [des: Reserved] */
    unsigned aud_monitor_trigger;                     /* <24> [dv:     0x0000] [des: AUD_MONITOR] */
    unsigned aud_sbar_cnt;                            /* <25> [dv:     0x0000] [des: AUD_SBAR_CNT] */
    unsigned aud_sbar_cycle;                          /* <26> [dv:     0x0000] [des: AUD_SBAR_CYCLE] */
    unsigned aud_max_sbar_cycle;                      /* <27> [dv:     0x0000] [des: AUD_MAX_SBAR_CYCLE] */
    unsigned aud_min_sbar_cycle;                      /* <28> [dv:     0xffff] [des: AUD_MIN_SBAR_CYCLE] */
    unsigned aud_sbar_status;                         /* <29> [dv:     0x0000] [des: AUD_SBAR_STATUS] */
    unsigned g68addr30_reserved;                      /* <30> [dv: 0x00000000] [des: Reserved] */
    unsigned g68addr31_reserved;                      /* <31> [dv: 0x00000000] [des: Reserved] */
    // GROUP 69 [aud_reg_g4]
    unsigned adcp_gps_ch_enable;                      /* < 0> [dv: 0x00000000] [des: ADCPRC GPS Configuration Group 1] */
    unsigned adcp_gps_fubypass;                       /* < 1> [dv: 0x00007777] [des: ADCPRC GPS Configuration Group 2] */
    unsigned adcp_gps_mode_ctrl;                      /* < 2> [dv: 0x00000000] [des: ADCPRC GPS Mode Control] */
    unsigned adcp_gps_init_ctrl;                      /* < 3> [dv:     0x0000] [des: ADCP GPS Initialization Control] */
    unsigned adcp_gps_coeff_din;                      /* < 4> [dv: 0x00000000] [des: Coefficient Data Input] */
    unsigned adcp_gps_agc_cfg;                        /* < 5> [dv: 0x00650200] [des: ADCPRC GPS AGC Configuration of Ch0/1] */
    unsigned adcp_gps_agc_cfg2;                       /* < 6> [dv: 0x00650200] [des: ADCPRC GPS AGC Configuration of Ch2/3] */
    unsigned adcp_gps_gain_0;                         /* < 7> [dv: 0x00800000] [des: ADCPRC GPS System Gain0] */
    unsigned adcp_gps_gain_1;                         /* < 8> [dv: 0x00800000] [des: ADCP GPS System Gain1] */
    unsigned adcp_gps_gain_2;                         /* < 9> [dv: 0x00800000] [des: ADCP GPS System Gain2] */
    unsigned adcp_gps_gain_3;                         /* <10> [dv: 0x00800000] [des: ADCP GPS System Gain3] */
    unsigned adcp_gps_risc_gain;                      /* <11> [dv: 0x00001111] [des: ADCP GPS RISC Gain] */
    unsigned adcp_gps_mic_l;                          /* <12> [dv: 0x00000000] [des: ADCPRC GPS Microphone-in Left Channel Data] */
    unsigned adcp_gps_mic_r;                          /* <13> [dv: 0x00000000] [des: ADCPRC GPS Microphone-in Right Channel Data] */
    unsigned adcp_gps_agc_gain;                       /* <14> [dv: 0x00000000] [des: ADCPRC GPS AGC Gain] */
    unsigned g69addr15_reserved0;                     /* <15> [dv: 0x00000000] [des: Reserved] */
    unsigned g69addr16_reserved0;                     /* <16> [dv: 0x00000000] [des: Reserved] */
    unsigned g69addr17_reserved0;                     /* <17> [dv: 0x00000000] [des: Reserved] */
    unsigned g69addr18_reserved0;                     /* <18> [dv: 0x00000000] [des: Reserved] */
    unsigned g69addr19_reserved0;                     /* <19> [dv: 0x00000000] [des: Reserved] */
    unsigned g69addr20_reserved0;                     /* <20> [dv: 0x00000000] [des: Reserved] */
    unsigned g69addr21_reserved0;                     /* <21> [dv: 0x00000000] [des: Reserved] */
    unsigned g69addr22_reserved0;                     /* <22> [dv: 0x00000000] [des: Reserved] */
    unsigned g69addr23_reserved0;                     /* <23> [dv: 0x00000000] [des: Reserved] */
    unsigned g69addr24_reserved0;                     /* <24> [dv: 0x00000000] [des: Reserved] */
    unsigned g69addr25_reserved0;                     /* <25> [dv: 0x00000000] [des: Reserved] */
    unsigned g69addr26_reserved0;                     /* <26> [dv: 0x00000000] [des: Reserved] */
    unsigned g69addr27_reserved0;                     /* <27> [dv: 0x00000000] [des: Reserved] */
    unsigned g69addr28_reserved0;                     /* <28> [dv: 0x00000000] [des: Reserved] */
    unsigned g69addr29_reserved0;                     /* <29> [dv: 0x00000000] [des: Reserved] */
    unsigned g69addr30_reserved0;                     /* <30> [dv: 0x00000000] [des: Reserved] */
    unsigned g69addr31_reserved0;                     /* <31> [dv: 0x00000000] [des: Reserved] */
    // GROUP 70
    unsigned grp70_reserved[32];
    // GROUP 71
    unsigned grp71_reserved[32];
    // GROUP 72
    unsigned grp72_reserved[32];
    // GROUP 73
    unsigned grp73_reserved[32];
    // GROUP 74
    unsigned grp74_reserved[32];
    // GROUP 75
    unsigned grp75_reserved[32];
    // GROUP 76
    unsigned grp76_reserved[32];
    // GROUP 77
    unsigned grp77_reserved[32];
    // GROUP 78
    unsigned grp78_reserved[32];
    // GROUP 79
    unsigned grp79_reserved[32];
    // GROUP 80
    unsigned vpp_dis_x_start;
    unsigned vpp_dis_y_start;
    unsigned vpp_dis_x_size;
    unsigned vpp_dis_y_size;
    unsigned vpp_v_offset;
    unsigned vpp_h_offset;
    unsigned vpp_bg_y;
    unsigned vpp_bg_cb_cr;
    unsigned vpp_v_filter0_setup;
    unsigned vpp_v_filter1_setup;
    unsigned vpp_h_filter_float;
    unsigned vpp_config;
    unsigned vpp_config_1;
    unsigned vpp_ds_field_config;
    unsigned vpp_dip_config;
    unsigned vpp_dip_param;
    unsigned vpp_acc_init;
    unsigned vpp_ref0_luma;
    unsigned vpp_ref0_chroma;
    unsigned vpp_ref1_luma;
    unsigned vpp_ref1_chroma;
    unsigned vpp_bidir_luma;
    unsigned vpp_bidir_chroma;
    unsigned vpp_dip_ref_base;
    unsigned vpp_dip_param_threshold;
    unsigned vpp_dip_param_fading;
    unsigned vpp_act_region_top;
    unsigned vpp_act_region_bottom;
    unsigned vpp_config_2;
    unsigned vpp_clut_ay;
    unsigned vpp_clut_uv;
    unsigned vpp_ref0_extension;
    // GROUP 81
    unsigned grp81_reserved[32];
    // GROUP 82
    unsigned grp82_reserved[32];
    // GROUP 83 [secgrp1]
    unsigned cbus_master_sec_0;                       /* < 0> [dv: 0x0000_0000] [des: Configure Security Attribute of CBUS Master] */
    unsigned cbus_master_sec_1;                       /* < 1> [dv: 0x0000_0000] [des: Configure Security Attribute of CBUS Master] */
    unsigned mbus_master_sec_0;                       /* < 2> [dv: 0x0000_0000] [des: Configure Security Attribute of MBUS Master] */
    unsigned mbus_master_sec_1;                       /* < 3> [dv: 0x0000_0000] [des: Configure Security Attribute of MBUS Master] */
    unsigned mbus_master_sec_2;                       /* < 4> [dv: 0x0000_0000] [des: Configure Security Attribute of MBUS Master] */
    unsigned mbus_master_sec_3;                       /* < 5> [dv: 0x0000_0000] [des: Configure Security Attribute of MBUS Master] */
    unsigned pbus_master_sec_0;                       /* < 6> [dv: 0x0000_0000] [des: Configure Security Attribute of PBUS Master] */
    unsigned pbus_master_sec_1;                       /* < 7> [dv: 0x0000_0000] [des: Configure Security Attribute of PBUS Master] */
    unsigned cbdma0_sram_secure_region_0;             /* < 8> [dv: 0x0000_0000] [des: Configure Secure region 0 of CBDMA0 SRAM] */
    unsigned cbdma0_sram_secure_region_1;             /* < 9> [dv: 0x0001_0000] [des: Configure Secure region 1 of CBDMA0 SRAM] */
    unsigned cbdma1_sram_secure_region_0;             /* <10> [dv: 0x0000_0000] [des: Configure Secure region 0 of CBDMA1 SRAM] */
    unsigned cbdma1_sram_secure_region_1;             /* <11> [dv: 0x0001_0000] [des: Configure Secure region 1 of CBDMA1 SRAM] */
    unsigned boot_rom_secure_region;                  /* <12> [dv: 0x0000_0000] [des: Configure Secure region of BOOT ROM] */
    unsigned g83_r13;                                 /* <13> [dv: 0x0000_0000] [des: Reserved Register] */
    unsigned spi_flash_secure_region;                 /* <14> [dv: 0x0000_0000] [des: Configure Secure region of SPI FLASH] */
    unsigned g83_r15;                                 /* <15> [dv: 0x0000_0000] [des: Reserved Register] */
    unsigned g83_r16;                                 /* <16> [dv: 0x0000_0000] [des: Reserved Register] */
    unsigned g83_r17;                                 /* <17> [dv: 0x0000_0000] [des: Reserved Register] */
    unsigned g83_r18;                                 /* <18> [dv: 0x0000_0000] [des: Reserved Register] */
    unsigned g83_r19;                                 /* <19> [dv: 0x0000_0000] [des: Reserved Register] */
    unsigned cpu_debug_ctrl;                          /* <20> [dv: 0x0000_0000] [des: Configure debug control of CPU] */
    unsigned a926_debug_ctrl;                         /* <21> [dv: 0x0000_0A01] [des: Configure debug control of A926] */
    unsigned i2c2cbus_debug_id;                       /* <22> [dv: 0x0000_0000] [des: I2C2CBUS ID/Status for Debug Information] */
    unsigned i2c2cbus_debug_address;                  /* <23> [dv: 0x0000_0000] [des: I2C2CBUS R/W BUS Address for Debug Information] */
    unsigned i2c2cbus_debug_data;                     /* <24> [dv: 0x0000_0000] [des: I2C2CBUS R/W BUS Data for Debug Information] */
    unsigned grp83_reserved_0;                        /* <25> */
    unsigned grp83_reserved_1;                        /* <26> */
    unsigned grp83_reserved_2;                        /* <27> */
    unsigned grp83_reserved_3;                        /* <28> */
    unsigned grp83_reserved_4;                        /* <29> */
    unsigned grp83_reserved_5;                        /* <30> */
    unsigned grp83_reserved_6;                        /* <31> */
    // GROUP 84
    unsigned grp84_reserved[32];
    // GROUP 85
    unsigned grp85_reserved[32];
    // GROUP 86
    unsigned grp86_reserved[32];
    // GROUP 87 [spi_controller_registers]
    unsigned spi_ctrl_1;                              /* < 0> [dv:     0xc117] [des: SPI Control Register] */
    unsigned spi_wait_1;                              /* < 1> [dv:     0x012a] [des: SPI Timing Register] */
    unsigned spi_cust_cmd_1;                          /* < 2> [dv:     0x0013] [des: SPI Customized Command Register] */
    unsigned spi_addr_low_1;                          /* < 3> [dv:     0x0000] [des: SPI Address Low Regsister] */
    unsigned spi_addr_high_1;                         /* < 4> [dv:     0x0000] [des: SPI Address High Register] */
    unsigned spi_data_low_1;                          /* < 5> [dv:     0x0000] [des: SPI Data Low Register] */
    unsigned spi_data_high_1;                         /* < 6> [dv:     0x0000] [des: SPI Data High Register] */
    unsigned spi_status_1;                            /* < 7> [dv:     0x0000] [des: SPI Status Register] */
    unsigned spi_cfg0_1;                              /* < 8> [dv:     0x0000] [des: SPI Configuration0 Register] */
    unsigned spi_cfg1_1;                              /* < 9> [dv:     0x3b00] [des: SPI Configuration1 Register] */
    unsigned spi_cfg2_1;                              /* <10> [dv:     0x1200] [des: SPI Configuration2 Register] */
    unsigned spi_cfg3_1;                              /* <11> [dv:     0x0009] [des: SPI Configuration3 Register] */
    unsigned spi_cfg4_1;                              /* <12> [dv:     0x0015] [des: SPI Configuration4 Register for DATA64 access] */
    unsigned spi_cfg5_1;                              /* <13> [dv:     0x0015] [des: SPI Configuration5 Register for OCP access] */
    unsigned spi_cfg6_1;                              /* <14> [dv:     0x0095] [des: SPI Configuration6 Register for DATA64 access] */
    unsigned spi_cfg7_1;                              /* <15> [dv:     0x0095] [des: SPI Configuration7 Register for OCP access] */
    unsigned spi_cfg8_1;                              /* <16> [dv:     0x0000] [des: SPI Configuration8 Register] */
    unsigned spi_cust_cmd_2_1;                        /* <17> [dv:     0x0004] [des: SPI Customized Command2 Register for DATA64 access] */
    unsigned spi_data_64_1;                           /* <18> [dv:     0x0000] [des: SPI Data Buffer Regsiter] */
    unsigned spi_rbuf_addr;                           /* <19> [dv:     0x0000] [des: SPI Read Buffer Address Register] */
    unsigned spi_status_2_1;                          /* <20> [dv:     0x2020] [des: SPI Status2 Register] */
    unsigned spi_status_3_1;                          /* <21> [dv:     0x0000] [des: SPI Status3 Register] */
    unsigned spi_mode_status_1;                       /* <22> [dv:     0x0000] [des: SPI Mode Status Register] */
    unsigned spi_err_status_1;                        /* <23> [dv:     0x0000] [des: SPI Controller Error Status Register] */
    unsigned spi_threshold;                           /* <24> [dv:     0x1fff] [des: Issue interrupt after reading threshold data] */
    unsigned spi_finish;                              /* <25> [dv:     0x1fff] [des: Issue interrupt after transmission complete] */
    unsigned spi_int;                                 /* <26> [dv:     0x0000] [des: SPI_NAND interrupt information and clear] */
    unsigned spi_wbuf_addr;                           /* <27> [dv:     0x0000] [des: SPI Write Buffer Address Register] */
    unsigned grp87_reserved_0;                        /* <28> */
    unsigned grp87_reserved_1;                        /* <29> */
    unsigned grp87_reserved_2;                        /* <30> */
    unsigned grp87_reserved_3;                        /* <31> */
    // GROUP 88 [spi_protection_scramble_descramble_registers]
    unsigned spi_protect_mode_1;                      /* < 0> [dv:     0x0000] [des: Protect Mode Register] */
    unsigned spi_region0_start_addr_low_1;            /* < 1> [dv:     0x0000] [des: Lower 16bits of Protection Region0 Start Address] */
    unsigned spi_region0_start_addr_high_1;           /* < 2> [dv:     0x0000] [des: Higher 16bit of Protection Region0 Start Address] */
    unsigned spi_region0_size_1;                      /* < 3> [dv:     0x0000] [des: Size of Protection Region0] */
    unsigned spi_region1_start_addr_low_1;            /* < 4> [dv:     0x0000] [des: Lower 16bits of Protection Region1 Start Address] */
    unsigned spi_region1_start_addr_high_1;           /* < 5> [dv:     0x0000] [des: Higher 16bits of Protection Region1 Start Address] */
    unsigned spi_region1_size_1;                      /* < 6> [dv:     0x0000] [des: Size of Protection Region1] */
    unsigned spi_region2_start_addr_low_1;            /* < 7> [dv:     0x0000] [des: Lower 16bits of Protection Region2 Start Address] */
    unsigned spi_region2_start_addr_high_1;           /* < 8> [dv:     0x0000] [des: Higher 16bits of Protection Region2 Start Address] */
    unsigned spi_region2_size_1;                      /* < 9> [dv:     0x0000] [des: Size of Protection Region2] */
    unsigned spi_out_of_range_1;                      /* <10> [dv:     0x0000] [des: Out of Range Control] */
    unsigned spi_scramble1_1;                         /* <11> [dv:     0x0000] [des: SPI Scramble1 Register] */
    unsigned spi_scramble2_1;                         /* <12> [dv:     0x0000] [des: SPI Scramble2 Register] */
    unsigned spi_scramble3_1;                         /* <13> [dv:     0x0000] [des: SPI Scramble3 Register] */
    unsigned grp88_reserved_0;                        /* <14> */
    unsigned grp88_reserved_1;                        /* <15> */
    unsigned grp88_reserved_2;                        /* <16> */
    unsigned grp88_reserved_3;                        /* <17> */
    unsigned grp88_reserved_4;                        /* <18> */
    unsigned grp88_reserved_5;                        /* <19> */
    unsigned grp88_reserved_6;                        /* <20> */
    unsigned grp88_reserved_7;                        /* <21> */
    unsigned grp88_reserved_8;                        /* <22> */
    unsigned grp88_reserved_9;                        /* <23> */
    unsigned grp88_reserved_10;                       /* <24> */
    unsigned grp88_reserved_11;                       /* <25> */
    unsigned grp88_reserved_12;                       /* <26> */
    unsigned grp88_reserved_13;                       /* <27> */
    unsigned grp88_reserved_14;                       /* <28> */
    unsigned grp88_reserved_15;                       /* <29> */
    unsigned grp88_reserved_16;                       /* <30> */
    unsigned grp88_reserved_17;                       /* <31> */
    // GROUP 89
    unsigned grp89_reserved[32];
    // GROUP 90 [spi_combo_touch]
    unsigned tx_data2_1_0_addr;                       /* < 0> [dv:     0x0000] [des: Transmit register1] */
    unsigned tx_data6_5_4_3;                          /* < 1> [dv:     0x0000] [des: Transmit register2] */
    unsigned tx_data10_9_8_7;                         /* < 2> [dv:     0x0000] [des: Transmit register3] */
    unsigned tx_data14_13_12_11;                      /* < 3> [dv:     0x0000] [des: Transmit register4] */
    unsigned tx_data15;                               /* < 4> [dv:     0x0000] [des: Transmit register5] */
    unsigned reserved_0_15;                           /* < 5> [dv:     0x0000] [des: ] */
    unsigned reserved_1_12;                           /* < 6> [dv:     0x0000] [des: ] */
    unsigned reserved_2_11;                           /* < 7> [dv:     0x0000] [des: ] */
    unsigned reserved_3_10;                           /* < 8> [dv:     0x0000] [des: ] */
    unsigned rx_data3_2_1_0;                          /* < 9> [dv:     0x0000] [des: Receive register1] */
    unsigned rx_data7_6_5_4;                          /* <10> [dv:     0x0000] [des: Receive register2] */
    unsigned rx_data11_10_9_8;                        /* <11> [dv:     0x0000] [des: Receive register3] */
    unsigned rx_data15_14_13_12;                      /* <12> [dv:     0x0000] [des: Receive register4] */
    unsigned reserved_4_10;                           /* <13> [dv:     0x0000] [des: ] */
    unsigned reserved_5_10;                           /* <14> [dv:     0x0000] [des: ] */
    unsigned reserved_6_9;                            /* <15> [dv:     0x0000] [des: ] */
    unsigned reserved_7_9;                            /* <16> [dv:     0x0000] [des: ] */
    unsigned spi_ctrl_clk_sel;                        /* <17> [dv:     0x0000] [des: SPI touch control and clock select register] */
    unsigned byte_no;                                 /* <18> [dv:     0x0000] [des: SPI transmission byte No. register] */
    unsigned spi_int_busy;                            /* <19> [dv:     0x0020] [des: SPI touch interrupt control register] */
    unsigned touch_dma_ctrl;                          /* <20> [dv:     0x0000] [des: SPI touch DMA control register] */
    unsigned touch_dma_length;                        /* <21> [dv:     0x0000] [des: SPI touch DMA length register] */
    unsigned touch_dma_addr;                          /* <22> [dv:     0x0000] [des: SPI touch DMA address register] */
    unsigned reserved_8_8;                            /* <23> [dv:     0x0000] [des: ] */
    unsigned dma_addr_status;                         /* <24> [dv:     0x0000] [des: SPI touch DMA address status register] */
    unsigned reserved_9_7;                            /* <25> [dv:     0x0000] [des: ] */
    unsigned uart_dma_ctrl;                           /* <26> [dv:     0x0000] [des: Uart DMA control register] */
    unsigned reserved_10_7;                           /* <27> [dv:     0x0000] [des: ] */
    unsigned spi_touch_debug_sel;                     /* <28> [dv:     0x0000] [des: SPI touch debug signal select register] */
    unsigned spi_combo_debug_sel;                     /* <29> [dv:     0x0000] [des: SPI combo debug signal select register] */
    unsigned spi_extra_cycle_ctrl;                    /* <30> [dv:     0x0000] [des: SPI extra cycle control register] */
    unsigned reserved_11_6;                           /* <31> [dv:     0x0000] [des: ] */
    // GROUP 91 [spi_combo_master]
    unsigned tx_data2_1_0_addr_1;                     /* < 0> [dv:     0x0000] [des: Transmit register1] */
    unsigned tx_data6_5_4_3_1;                        /* < 1> [dv:     0x0000] [des: Transmit register2] */
    unsigned tx_data10_9_8_7_1;                       /* < 2> [dv:     0x0000] [des: Transmit register3] */
    unsigned tx_data14_13_12_11_1;                    /* < 3> [dv:     0x0000] [des: Transmit register4] */
    unsigned tx_data15_1;                             /* < 4> [dv:     0x0000] [des: Transmit register5] */
    unsigned reserved_0_16;                           /* < 5> [dv:     0x0000] [des: ] */
    unsigned reserved_1_13;                           /* < 6> [dv:     0x0000] [des: ] */
    unsigned reserved_2_12;                           /* < 7> [dv:     0x0000] [des: ] */
    unsigned reserved_3_11;                           /* < 8> [dv:     0x0000] [des: ] */
    unsigned rx_data3_2_1_0_1;                        /* < 9> [dv:     0x0000] [des: Receive register1] */
    unsigned rx_data7_6_5_4_1;                        /* <10> [dv:     0x0000] [des: Receive register2] */
    unsigned rx_data11_10_9_8_1;                      /* <11> [dv:     0x0000] [des: Receive register3] */
    unsigned rx_data15_14_13_12_1;                    /* <12> [dv:     0x0000] [des: Receive register4] */
    unsigned reserved_4_11;                           /* <13> [dv:     0x0000] [des: ] */
    unsigned reserved_5_11;                           /* <14> [dv:     0x0000] [des: ] */
    unsigned reserved_6_10;                           /* <15> [dv:     0x0000] [des: ] */
    unsigned reserved_7_10;                           /* <16> [dv:     0x0000] [des: ] */
    unsigned spi_ctrl_clk_sel_1;                      /* <17> [dv:     0x0000] [des: SPI master control and clock select register] */
    unsigned byte_no_1;                               /* <18> [dv:     0x0000] [des: SPI transmission byte No. register] */
    unsigned spi_int_busy_1;                          /* <19> [dv:     0x0020] [des: SPI master interrupt control register] */
    unsigned master_dma_ctrl;                         /* <20> [dv:     0x0000] [des: SPI master DMA control register] */
    unsigned master_dma_length;                       /* <21> [dv:     0x0000] [des: SPI master DMA length register] */
    unsigned master_dma_addr;                         /* <22> [dv:     0x0000] [des: SPI master DMA address register] */
    unsigned reserved_8_9;                            /* <23> [dv:     0x0000] [des: ] */
    unsigned dma_addr_status_1;                       /* <24> [dv:     0x0000] [des: SPI master DMA address status register] */
    unsigned reserved_9_8;                            /* <25> [dv:     0x0000] [des: ] */
    unsigned uart_dma_ctrl_1;                         /* <26> [dv:     0x0000] [des: Uart DMA control register] */
    unsigned reserved_10_8;                           /* <27> [dv:     0x0000] [des: ] */
    unsigned spi_master_debug_sel;                    /* <28> [dv:     0x0000] [des: SPI master debug signal select register] */
    unsigned spi_combo_debug_sel_1;                   /* <29> [dv:     0x0000] [des: SPI combo debug signal select register] */
    unsigned spi_extra_cycle_ctrl_1;                  /* <30> [dv:     0x0000] [des: SPI extra cycle control register] */
    unsigned reserved_11_7;                           /* <31> [dv:     0x0000] [des: ] */
    // GROUP 92 [spi_combo_slave]
    unsigned tx_data2_1_0;                            /* < 0> [dv:     0x0000] [des: SPI slave transmit data register1] */
    unsigned tx_data6_5_4_3_2;                        /* < 1> [dv:     0x0000] [des: SPI slave transmit data register2] */
    unsigned tx_data10_9_8_7_2;                       /* < 2> [dv:     0x0000] [des: SPI slave transmit data register3] */
    unsigned tx_data14_13_12_11_2;                    /* < 3> [dv:     0x0000] [des: SPI slave transmit data register4] */
    unsigned tx_data15_2;                             /* < 4> [dv:     0x0000] [des: SPI slave transmit data register5] */
    unsigned reserved_0_17;                           /* < 5> [dv:     0x0000] [des: ] */
    unsigned reserved_1_14;                           /* < 6> [dv:     0x0000] [des: ] */
    unsigned reserved_2_13;                           /* < 7> [dv:     0x0000] [des: ] */
    unsigned reserved_3_12;                           /* < 8> [dv:     0x0000] [des: ] */
    unsigned rx_data3_2_1_0_2;                        /* < 9> [dv:     0x0000] [des: SPI slave receive data register1] */
    unsigned rx_data7_6_5_4_2;                        /* <10> [dv:     0x0000] [des: SPI slave receive data register2] */
    unsigned rx_data11_10_9_8_2;                      /* <11> [dv:     0x0000] [des: SPI slave receive data register3] */
    unsigned rx_data15_14_13_12_2;                    /* <12> [dv:     0x0000] [des: SPI slave receive data register7] */
    unsigned reserved_4_12;                           /* <13> [dv:     0x0000] [des: ] */
    unsigned reserved_5_12;                           /* <14> [dv:     0x0000] [des: ] */
    unsigned reserved_6_11;                           /* <15> [dv:     0x0000] [des: ] */
    unsigned reserved_7_11;                           /* <16> [dv:     0x0000] [des: ] */
    unsigned risc_int_data_rdy;                       /* <17> [dv:     0x0000] [des: SPI slave interrupt register] */
    unsigned slave_dma_ctrl;                          /* <18> [dv:     0x0000] [des: SPI slave DMA control register] */
    unsigned slave_dma_length;                        /* <19> [dv:     0x0000] [des: SPI slave DMA length register] */
    unsigned slave_dma_addr;                          /* <20> [dv:     0x0000] [des: SPI slave DMA address register] */
    unsigned reserved_8_10;                           /* <21> [dv:     0x0000] [des: ] */
    unsigned reserved_9_9;                            /* <22> [dv:     0x0000] [des: ] */
    unsigned addr_spi_busy;                           /* <23> [dv:     0x0000] [des: SPI slave index signal register] */
    unsigned spi_slave_debug_sel;                     /* <24> [dv:     0x0000] [des: SPI slave debug signal select register] */
    unsigned reserved_10_9;                           /* <25> [dv:     0x0000] [des: ] */
    unsigned reserved_11_8;                           /* <26> [dv:     0x0000] [des: ] */
    unsigned reserved_12_4;                           /* <27> [dv:     0x0000] [des: ] */
    unsigned reserved_13_4;                           /* <28> [dv:     0x0000] [des: ] */
    unsigned reserved_14_4;                           /* <29> [dv:     0x0000] [des: ] */
    unsigned reserved_15_3;                           /* <30> [dv:     0x0000] [des: ] */
    unsigned reserved_16_2;                           /* <31> [dv:     0x0000] [des: ] */
    // GROUP 93
    unsigned grp93_reserved[32];
    // GROUP 94 [res_touch]
    unsigned rg_cfg00;                                /* < 0> [dv:     0x00ff] [des:  TOUCH Control Register 00 ] */
    unsigned rg_cfg01;                                /* < 1> [dv:     0x1DFF] [des:  TOUCH Control Register 01 ] */
    unsigned rg_cfg02;                                /* < 2> [dv:     0x1B40] [des:  TOUCH Control Register 02  ] */
    unsigned rg_cfg03;                                /* < 3> [dv:     0x2802] [des:  TOUCH Control Register 03  ] */
    unsigned rg_cfg04;                                /* < 4> [dv:     0x6A72] [des:  TOUCH Control Register 04  ] */
    unsigned rg_cfg05;                                /* < 5> [dv:     0x0302] [des:  TOUCH Control Register 05  ] */
    unsigned rg_cfg06;                                /* < 6> [dv:     0x0302] [des:  TOUCH Control Register 06  ] */
    unsigned rg_cfg07;                                /* < 7> [dv:     0x0203] [des:  TOUCH Control Register 07  ] */
    unsigned rg_cfg08;                                /* < 8> [dv:     0x0000] [des:  TOUCH Control Register 08  ] */
    unsigned rg_cfg09;                                /* < 9> [dv:     0x0202] [des:  TOUCH Control Register 09 ] */
    unsigned rg_cfg0a;                                /* <10> [dv:     0x0203] [des:  TOUCH Control Register 0A ] */
    unsigned rg_cfg0b;                                /* <11> [dv:     0xa000] [des:  TOUCH Control Register 0B ] */
    unsigned rg_cfg0c;                                /* <12> [dv:     0x1000] [des:  TOUCH Control Register 0C ] */
    unsigned rg_cfg0d;                                /* <13> [dv:     0x0000] [des:  TOUCH Control Register 0D ] */
    unsigned rg_cfg0e;                                /* <14> [dv:     0x4B3E] [des:  TOUCH Control Register 0E ] */
    unsigned rg_cfg0f;                                /* <15> [dv:     0x700A] [des:  TOUCH Control Register 0F ] */
    unsigned rg_cfg10;                                /* <16> [dv:     0x0200] [des:  TOUCH Control Register 10 ] */
    unsigned rg_cfg11;                                /* <17> [dv:     0x0000] [des:  TOUCH Control Register 11 ] */
    unsigned rg_cfg12;                                /* <18> [dv:     0x0000] [des:  TOUCH Control Register 12 ] */
    unsigned rg_cfg13;                                /* <19> [dv:     0x0000] [des:  TOUCH Control Register 13 ] */
    unsigned rg_cfg14;                                /* <20> [dv:     0x0000] [des:  TOUCH Control Register 14 ] */
    unsigned rg_cfg15;                                /* <21> [dv:     0x0000] [des:  TOUCH Control Register 15 ] */
    unsigned rg_cfg16;                                /* <22> [dv:     0x0000] [des:  TOUCH Control Register 16 ] */
    unsigned rg_cfg17;                                /* <23> [dv:     0x0000] [des:  TOUCH Control Register 17 ] */
    unsigned rg_cfg18;                                /* <24> [dv:     0x0002] [des:  TOUCH Control Register 18 ] */
    unsigned rg_cfg19;                                /* <25> [dv:     0x00B0] [des:  TOUCH Control Register 19 ] */
    unsigned rg_cfg1a;                                /* <26> [dv:     0x0000] [des:  TOUCH Control Register 1A ] */
    unsigned rg_cfg1b;                                /* <27> [dv:     0x4203] [des:  TOUCH Control Register 1B ] */
    unsigned rg_cfg1c;                                /* <28> [dv:     0x8203] [des:  TOUCH Control Register 1C ] */
    unsigned rg_cfg1d;                                /* <29> [dv:     0x0000] [des:  TOUCH Control Register 1D ] */
    unsigned rg_cfg1e;                                /* <30> [dv:     0x0000] [des:  TOUCH Control Register 1E ] */
    unsigned rg_cfg1f;                                /* <31> [dv:     0x0200] [des:  TOUCH Control Register 1F ] */
    // GROUP 95
    unsigned grp95_reserved[32];
    // GROUP 96 [stc_av0]
    unsigned stc_15_0_1;                              /* < 0> [dv:     0x0001] [des: STC Counter Register] */
    unsigned stc_31_16_1;                             /* < 1> [dv:     0x0000] [des: STC Counter Register] */
    unsigned stc_64_1;                                /* < 2> [dv:     0x0000] [des: STC Counter Register] */
    unsigned stc_divisor_1;                           /* < 3> [dv:     0x04af] [des: STC pre-scaling Register] */
    unsigned rtc_15_0_1;                              /* < 4> [dv:     0x0001] [des: RTC counter register] */
    unsigned rtc_23_16_1;                             /* < 5> [dv:     0x0000] [des: RTC counter register] */
    unsigned rtc_divisor_1;                           /* < 6> [dv:       0x59] [des: RTC Divider Register] */
    unsigned stc_config_1;                            /* < 7> [dv:     0x0000] [des: External reference clock dividor] */
    unsigned timer0_ctl_1;                            /* < 8> [dv:     0x0000] [des: Timer0 Control Register] */
    unsigned timer0_cnt_1;                            /* < 9> [dv:     0x0000] [des: Timer0 Counter register] */
    unsigned timer1_ctl_1;                            /* <10> [dv:     0x0000] [des: Timer1 Control Register] */
    unsigned timer1_cnt_1;                            /* <11> [dv:     0x0000] [des: Timer1 Counter register] */
    unsigned reserved12;                              /* <12> [dv:     0x0000] [des: Reserved] */
    unsigned grp96_reserved_0;                        /* <13> */
    unsigned stc_47_32_1;                             /* <14> [dv:     0x0000] [des: STC Counter Register] */
    unsigned stc_63_48_1;                             /* <15> [dv:     0x0000] [des: STC Counter Register] */
    unsigned timer2_ctl_1;                            /* <16> [dv:     0x0000] [des: Timer2 Control Register] */
    unsigned timer2_pres_value_1;                     /* <17> [dv:     0x0000] [des: Timer2 16-bit pre-scaling value] */
    unsigned timer2_reload_1;                         /* <18> [dv:     0x0000] [des: Timer2 16-bit reload value] */
    unsigned timer2_cnt_1;                            /* <19> [dv:     0x0000] [des: Timer2 16-bit counter value] */
    unsigned timer3_ctl_1;                            /* <20> [dv:     0x0000] [des: Timer3 Control Register] */
    unsigned timer3_pres_value_1;                     /* <21> [dv:     0x0000] [des: Timer3 16-bit pre-scaling value] */
    unsigned timer3_reload_1;                         /* <22> [dv:     0x0000] [des: Timer3 16-bit reload value] */
    unsigned timer3_cnt_1;                            /* <23> [dv:     0x0000] [des: Timer3 16-bit counter value] */
    unsigned stcl_0_1;                                /* <24> [dv:     0x0000] [des: Latched value (bit 15:0) of STC counter] */
    unsigned stcl_1_1;                                /* <25> [dv:     0x0000] [des: Latched value (bit 31:16) of STC counter] */
    unsigned stcl_2_1;                                /* <26> [dv:     0x0000] [des: Latched value (bit 32) of STC counter] */
    unsigned atc_0_1;                                 /* <27> [dv:     0x0001] [des: 34 bit ATC counter bit[15:0]] */
    unsigned atc_1_1;                                 /* <28> [dv:     0x0000] [des: 34 bit ATC counter bit[31:16]] */
    unsigned atc_2_1;                                 /* <29> [dv:     0x0000] [des: 34 bit ATC counter bit[33:32]] */
    unsigned reserved30_1;                            /* <30> [dv:     0x0000] [des: Reserved] */
    unsigned reserved31_1;                            /* <31> [dv:     0x0000] [des: Reserved] */
    // GROUP 97 [stc_av1]
    unsigned stc_15_0_2;                              /* < 0> [dv:     0x0001] [des: STC Counter Register] */
    unsigned stc_31_16_2;                             /* < 1> [dv:     0x0000] [des: STC Counter Register] */
    unsigned stc_64_2;                                /* < 2> [dv:     0x0000] [des: STC Counter Register] */
    unsigned stc_divisor_2;                           /* < 3> [dv:     0x04af] [des: STC pre-scaling Register] */
    unsigned rtc_15_0_2;                              /* < 4> [dv:     0x0001] [des: RTC counter register] */
    unsigned rtc_23_16_2;                             /* < 5> [dv:     0x0000] [des: RTC counter register] */
    unsigned rtc_divisor_2;                           /* < 6> [dv:       0x59] [des: RTC Divider Register] */
    unsigned stc_config_2;                            /* < 7> [dv:     0x0000] [des: External reference clock dividor] */
    unsigned timer0_ctl_2;                            /* < 8> [dv:     0x0000] [des: Timer0 Control Register] */
    unsigned timer0_cnt_2;                            /* < 9> [dv:     0x0000] [des: Timer0 Counter register] */
    unsigned timer1_ctl_2;                            /* <10> [dv:     0x0000] [des: Timer1 Control Register] */
    unsigned timer1_cnt_2;                            /* <11> [dv:     0x0000] [des: Timer1 Counter register] */
    unsigned grp97_reserved_0;                        /* <12> */
    unsigned grp97_reserved_1;                        /* <13> */
    unsigned stc_47_32_2;                             /* <14> [dv:     0x0000] [des: STC Counter Register] */
    unsigned stc_63_48_2;                             /* <15> [dv:     0x0000] [des: STC Counter Register] */
    unsigned timer2_ctl_2;                            /* <16> [dv:     0x0000] [des: Timer2 Control Register] */
    unsigned timer2_pres_value_2;                     /* <17> [dv:     0x0000] [des: Timer2 16-bit pre-scaling value] */
    unsigned timer2_reload_2;                         /* <18> [dv:     0x0000] [des: Timer2 16-bit reload value] */
    unsigned timer2_cnt_2;                            /* <19> [dv:     0x0000] [des: Timer2 16-bit counter value] */
    unsigned timer3_ctl_2;                            /* <20> [dv:     0x0000] [des: Timer3 Control Register] */
    unsigned timer3_pres_value_2;                     /* <21> [dv:     0x0000] [des: Timer3 16-bit pre-scaling value] */
    unsigned timer3_reload_2;                         /* <22> [dv:     0x0000] [des: Timer3 16-bit reload value] */
    unsigned timer3_cnt_2;                            /* <23> [dv:     0x0000] [des: Timer3 16-bit counter value] */
    unsigned stcl_0_2;                                /* <24> [dv:     0x0000] [des: Latched value (bit 15:0) of STC counter] */
    unsigned stcl_1_2;                                /* <25> [dv:     0x0000] [des: Latched value (bit 31:16) of STC counter] */
    unsigned stcl_2_2;                                /* <26> [dv:     0x0000] [des: Latched value (bit 32) of STC counter] */
    unsigned atc_0_2;                                 /* <27> [dv:     0x0001] [des: 34 bit ATC counter bit[15:0]] */
    unsigned atc_1_2;                                 /* <28> [dv:     0x0000] [des: 34 bit ATC counter bit[31:16]] */
    unsigned atc_2_2;                                 /* <29> [dv:     0x0000] [des: 34 bit ATC counter bit[33:32]] */
    unsigned reserved30_2;                            /* <30> [dv:     0x0000] [des: Reserved] */
    unsigned reserved31_2;                            /* <31> [dv:     0x0000] [des: Reserved] */
    // GROUP 98 [pmc]
    unsigned pmc_timer;                               /* < 0> [dv: 0x01000100] [des: PMC Timer] */
    unsigned pmc_ctrl;                                /* < 1> [dv: 0x00000010] [des: PMC Control Register] */
    unsigned xtal27m_password_i;                      /* < 2> [dv: 0x00000000] [des: XTAL27M Password I] */
    unsigned xtal27m_password_ii;                     /* < 3> [dv: 0x00000000] [des: XTAL27M Password II] */
    unsigned xtal32k_password_i;                      /* < 4> [dv: 0x00000000] [des: XTAL32K Password I] */
    unsigned xtal32k_password_ii;                     /* < 5> [dv: 0x00000000] [des: XTAL32K Password II] */
    unsigned clk27m_password_i;                       /* < 6> [dv: 0x00000000] [des: CLK27M Password I] */
    unsigned clk27m_password_ii;                      /* < 7> [dv: 0x00000000] [des: CLK27M Password II] */
    unsigned pmc_timer2;                              /* < 8> [dv: 0x00000100] [des: PMC Timer2] */
    unsigned grp98_reserved_0;                        /* < 9> */
    unsigned grp98_reserved_1;                        /* <10> */
    unsigned grp98_reserved_2;                        /* <11> */
    unsigned grp98_reserved_3;                        /* <12> */
    unsigned grp98_reserved_4;                        /* <13> */
    unsigned grp98_reserved_5;                        /* <14> */
    unsigned grp98_reserved_6;                        /* <15> */
    unsigned grp98_reserved_7;                        /* <16> */
    unsigned grp98_reserved_8;                        /* <17> */
    unsigned grp98_reserved_9;                        /* <18> */
    unsigned grp98_reserved_10;                       /* <19> */
    unsigned grp98_reserved_11;                       /* <20> */
    unsigned grp98_reserved_12;                       /* <21> */
    unsigned grp98_reserved_13;                       /* <22> */
    unsigned grp98_reserved_14;                       /* <23> */
    unsigned grp98_reserved_15;                       /* <24> */
    unsigned grp98_reserved_16;                       /* <25> */
    unsigned grp98_reserved_17;                       /* <26> */
    unsigned grp98_reserved_18;                       /* <27> */
    unsigned grp98_reserved_19;                       /* <28> */
    unsigned grp98_reserved_20;                       /* <29> */
    unsigned grp98_reserved_21;                       /* <30> */
    unsigned grp98_reserved_22;                       /* <31> */
    // GROUP 99 [stc_av2]
    unsigned stc_15_0_3;                              /* < 0> [dv:     0x0001] [des: STC Counter Register] */
    unsigned stc_31_16_3;                             /* < 1> [dv:     0x0000] [des: STC Counter Register] */
    unsigned stc_64_3;                                /* < 2> [dv:     0x0000] [des: STC Counter Register] */
    unsigned stc_divisor_3;                           /* < 3> [dv:     0x04af] [des: STC pre-scaling Register] */
    unsigned rtc_15_0_3;                              /* < 4> [dv:     0x0001] [des: RTC counter register] */
    unsigned rtc_23_16_3;                             /* < 5> [dv:     0x0000] [des: RTC counter register] */
    unsigned rtc_divisor_3;                           /* < 6> [dv:       0x59] [des: RTC Divider Register] */
    unsigned stc_config_3;                            /* < 7> [dv:     0x0000] [des: External reference clock dividor] */
    unsigned timer0_ctl_3;                            /* < 8> [dv:     0x0000] [des: Timer0 Control Register] */
    unsigned timer0_cnt_3;                            /* < 9> [dv:     0x0000] [des: Timer0 Counter register] */
    unsigned timer1_ctl_3;                            /* <10> [dv:     0x0000] [des: Timer1 Control Register] */
    unsigned timer1_cnt_3;                            /* <11> [dv:     0x0000] [des: Timer1 Counter register] */
    unsigned grp99_reserved_0;                        /* <12> */
    unsigned grp99_reserved_1;                        /* <13> */
    unsigned stc_47_32_3;                             /* <14> [dv:     0x0000] [des: STC Counter Register] */
    unsigned stc_63_48_3;                             /* <15> [dv:     0x0000] [des: STC Counter Register] */
    unsigned timer2_ctl_3;                            /* <16> [dv:     0x0000] [des: Timer2 Control Register] */
    unsigned timer2_pres_value_3;                     /* <17> [dv:     0x0000] [des: Timer2 16-bit pre-scaling value] */
    unsigned timer2_reload_3;                         /* <18> [dv:     0x0000] [des: Timer2 16-bit reload value] */
    unsigned timer2_cnt_3;                            /* <19> [dv:     0x0000] [des: Timer2 16-bit counter value] */
    unsigned timer3_ctl_3;                            /* <20> [dv:     0x0000] [des: Timer3 Control Register] */
    unsigned timer3_pres_value_3;                     /* <21> [dv:     0x0000] [des: Timer3 16-bit pre-scaling value] */
    unsigned timer3_reload_3;                         /* <22> [dv:     0x0000] [des: Timer3 16-bit reload value] */
    unsigned timer3_cnt_3;                            /* <23> [dv:     0x0000] [des: Timer3 16-bit counter value] */
    unsigned stcl_0_3;                                /* <24> [dv:     0x0000] [des: Latched value (bit 15:0) of STC counter] */
    unsigned stcl_1_3;                                /* <25> [dv:     0x0000] [des: Latched value (bit 31:16) of STC counter] */
    unsigned stcl_2_3;                                /* <26> [dv:     0x0000] [des: Latched value (bit 32) of STC counter] */
    unsigned atc_0_3;                                 /* <27> [dv:     0x0001] [des: 34 bit ATC counter bit[15:0]] */
    unsigned atc_1_3;                                 /* <28> [dv:     0x0000] [des: 34 bit ATC counter bit[31:16]] */
    unsigned atc_2_3;                                 /* <29> [dv:     0x0000] [des: 34 bit ATC counter bit[33:32]] */
    unsigned reserved30_3;                            /* <30> [dv:     0x0000] [des: Reserved] */
    unsigned reserved31_3;                            /* <31> [dv:     0x0000] [des: Reserved] */
    // GROUP 100
    unsigned grp100_reserved[32];
    // GROUP 101
    unsigned grp101_reserved[32];
    // GROUP 102
    unsigned grp102_reserved[32];
    // GROUP 103
    unsigned grp103_reserved[32];
    // GROUP 104
    unsigned grp104_reserved[32];
    // GROUP 105
    unsigned grp105_reserved[32];
    // GROUP 106
    unsigned grp106_reserved[32];
    // GROUP 107
    unsigned grp107_reserved[32];
    // GROUP 108
    unsigned grp108_reserved[32];
    // GROUP 109 [huf_grp]
    unsigned jpeg_huff_mode;                          /* < 0> [dv:     0x3000] [des: Huffman Decoder Mode Register] */
    unsigned jpeg_huff_ctrl;                          /* < 1> [dv:     0x0000] [des: Huffman Decoder Control Register] */
    unsigned jpeg_huff_status;                        /* < 2> [dv:     0x0008] [des: Huffman Decoder Status Register] */
    unsigned jpeg_huff_scan_ctrl;                     /* < 3> [dv:     0x0000] [des: Huffman Scan Control Register] */
    unsigned jpeg_huff_table;                         /* < 4> [dv:     0x0000] [des: Huffman Decoder Table Register] */
    unsigned jpeg_huff_mcuno;                         /* < 5> [dv:     0x0000] [des: Huffman MCU Number Register] */
    unsigned jpeg_huff_jpeghsize;                     /* < 6> [dv:     0x0000] [des: Huffman JPEG Horizontal Size Register] */
    unsigned jpeg_huff_jpegvsize;                     /* < 7> [dv:     0x0000] [des: Huffman JPEG Vertical Size Register] */
    unsigned jpeg_huff_bitstream;                     /* < 8> [dv:     0x0000] [des: Huffman Bitstream Register] */
    unsigned jpeg_huff_bits_dma_offset;               /* < 9> [dv:     0x0000] [des: Huffman Bitstream DMA Offset Register] */
    unsigned jpeg_huff_wr_huff_info;                  /* <10> [dv:     0x0000] [des: Huffman Decoder Information Update Register] */
    unsigned jpeg_huff_bits_info;                     /* <11> [dv:     0x0000] [des: Huffman Bitstream Information Register] */
    unsigned jpeg_huff_rd_huff_info;                  /* <12> [dv:     0x0001] [des: Huffman Decoder Information Register] */
    unsigned jpeg_huff_dma_offset_0;                  /* <13> [dv:     0x0000] [des: Huffman DMA1 Offset Register] */
    unsigned jpeg_huff_dma_offset_1;                  /* <14> [dv:     0x0000] [des: Huffman DMA2 Offset Register] */
    unsigned jpeg_huff_acval_offset_0;                /* <15> [dv:     0x0000] [des: Huffman AC Table 0 Offset Register] */
    unsigned jpeg_huff_acval_offset_1;                /* <16> [dv:     0x0000] [des: Huffman AC Table 1 Offset Register] */
    unsigned jpeg_huff_acval_offset_2;                /* <17> [dv:     0x0000] [des: Huffman AC Table 2 Offset Register] */
    unsigned jpeg_huff_acval_offset_3;                /* <18> [dv:     0x0000] [des: Huffman AC Table 3 Offset Register] */
    unsigned jpeg_huff_wr_dc_01;                      /* <19> [dv:     0x5555] [des: Huffman Write DC 0-1 Table Register] */
    unsigned jpeg_huff_wr_dc_23;                      /* <20> [dv:     0x5555] [des: Huffman Write DC 2-3 Table Register] */
    unsigned jpeg_huff_wr_acval_0;                    /* <21> [dv:     0x5555] [des: Huffman Write AC 0 Table Register] */
    unsigned jpeg_huff_wr_acval_1;                    /* <22> [dv:     0x5555] [des: Huffman Write AC 1 Table Register] */
    unsigned jpeg_huff_wr_acval_2;                    /* <23> [dv:     0x5555] [des: Huffman Write AC 2 Table Register] */
    unsigned jpeg_huff_wr_acval_3;                    /* <24> [dv:     0x5555] [des: Huffman Write AC 3 Table Register] */
    unsigned jpeg_huff_rd_addr;                       /* <25> [dv:     0x0000] [des: Huffman Read Table Register] */
    unsigned jpeg_huff_rd_val;                        /* <26> [dv:     0xe400] [des: Huffman Read Table Value Register] */
    unsigned jpeg_huff_probe;                         /* <27> [dv:     0x0000] [des: Huffman Probe Entry Register] */
    unsigned jr_control;                              /* <28> [dv:     0x0000] [des: JPEG Render Control Register] */
    unsigned jr_status;                               /* <29> [dv:     0x0040] [des: JPEG Render Status Register] */
    unsigned jr_reg_num;                              /* <30> [dv:     0x0000] [des: JPEG Render Register Number Register] */
    unsigned jr_reg_data;                             /* <31> [dv:     0x0000] [des: JPEG Render Register Data Register] */
    // GROUP 110 [jdm_grp]
    unsigned jdm_mode;                                /* < 0> [dv:     0x0000] [des: JDM Mode] */
    unsigned jdm_status;                              /* < 1> [dv:     0x0000] [des: JDM Status] */
    unsigned jdm_dma1_mode;                           /* < 2> [dv:     0x0000] [des: JDM DMA Mode] */
    unsigned jdm_dma1_xaddr;                          /* < 3> [dv:     0x0000] [des: JDM X Address] */
    unsigned jdm_dma1_yaddr;                          /* < 4> [dv:     0x0000] [des: JDM Y Address] */
    unsigned jdm_dma1_done;                           /* < 5> [dv:     0x0001] [des: DMA Done] */
    unsigned jdm_dma1_start_addr;                     /* < 6> [dv:     0x0000] [des: DMA Buffer Start Address] */
    unsigned jdm_dma1_block_num;                      /* < 7> [dv:     0x0000] [des: DMA Block Number] */
    unsigned grp110_reserved_0;                       /* < 8> */
    unsigned grp110_reserved_1;                       /* < 9> */
    unsigned grp110_reserved_2;                       /* <10> */
    unsigned grp110_reserved_3;                       /* <11> */
    unsigned grp110_reserved_4;                       /* <12> */
    unsigned grp110_reserved_5;                       /* <13> */
    unsigned jdm_png_trans_info_0;                    /* <14> [dv:     0x0000] [des: PNG Trasfer Info 0] */
    unsigned jdm_png_trans_info_1;                    /* <15> [dv:     0x0000] [des: PNG Trasfer Info 1] */
    unsigned jdm_gclk_free;                           /* <16> [dv:     0x0000] [des: Gated Clock Free Run] */
    unsigned jdm_mem_bound_protect_0;                 /* <17> [dv:     0x0000] [des: Memory Boundary Protection 0] */
    unsigned jdm_mem_bound_protect_1;                 /* <18> [dv:     0x0000] [des: Memory Boundary Protection 1] */
    unsigned jdm_dmabuf_chksum_addr;                  /* <19> [dv:     0x0000] [des: DMA Buffer Address for Checksum] */
    unsigned jdm_dmabuf_chksum_0;                     /* <20> [dv:     0x0000] [des: DMA Buffer Checksum 0] */
    unsigned jdm_dmabuf_chksum_1;                     /* <21> [dv:     0x0000] [des: DMA Buffer Checksum 1] */
    unsigned mj_dc_luma_base_addr_l;                  /* <22> [dv:     0x0000] [des: DC luma base LSB] */
    unsigned mj_dc_luma_base_addr_h;                  /* <23> [dv:     0x0000] [des: DC luma base MSB] */
    unsigned mj_dc_chroma_base_addr_l;                /* <24> [dv:     0x0000] [des: DC Chroma base LSB] */
    unsigned mj_dc_chroma_base_addr_h;                /* <25> [dv:     0x0000] [des: DC Chroma base MSB] */
    unsigned mj_dc_width;                             /* <26> [dv:     0x0000] [des: DC buffer width] */
    unsigned grp110_reserved_6;                       /* <27> */
    unsigned grp110_reserved_7;                       /* <28> */
    unsigned jdm_jpeg_offset;                         /* <29> [dv:     0x0000] [des: JPEG IDCT Offset] */
    unsigned grp110_reserved_8;                       /* <30> */
    unsigned grp110_reserved_9;                       /* <31> */
    // GROUP 111 [jpeg_invq_grp]
    unsigned jpeg_invq_qmx_par;                       /* < 0> [dv:        n/a] [des: INVQ Quantization Matrix Access Register] */
    unsigned jpeg_invq_mode;                          /* < 1> [dv:     0x0000] [des: INVQ Operation Mode] */
    unsigned jpeg_invq_chksum;                        /* < 2> [dv:        n/a] [des: INVQ Checksum] */
    unsigned grp111_reserved_0;                       /* < 3> */
    unsigned grp111_reserved_1;                       /* < 4> */
    unsigned grp111_reserved_2;                       /* < 5> */
    unsigned grp111_reserved_3;                       /* < 6> */
    unsigned grp111_reserved_4;                       /* < 7> */
    unsigned grp111_reserved_5;                       /* < 8> */
    unsigned grp111_reserved_6;                       /* < 9> */
    unsigned grp111_reserved_7;                       /* <10> */
    unsigned grp111_reserved_8;                       /* <11> */
    unsigned grp111_reserved_9;                       /* <12> */
    unsigned grp111_reserved_10;                      /* <13> */
    unsigned grp111_reserved_11;                      /* <14> */
    unsigned grp111_reserved_12;                      /* <15> */
    unsigned grp111_reserved_13;                      /* <16> */
    unsigned grp111_reserved_14;                      /* <17> */
    unsigned grp111_reserved_15;                      /* <18> */
    unsigned grp111_reserved_16;                      /* <19> */
    unsigned grp111_reserved_17;                      /* <20> */
    unsigned grp111_reserved_18;                      /* <21> */
    unsigned grp111_reserved_19;                      /* <22> */
    unsigned grp111_reserved_20;                      /* <23> */
    unsigned grp111_reserved_21;                      /* <24> */
    unsigned grp111_reserved_22;                      /* <25> */
    unsigned grp111_reserved_23;                      /* <26> */
    unsigned grp111_reserved_24;                      /* <27> */
    unsigned grp111_reserved_25;                      /* <28> */
    unsigned grp111_reserved_26;                      /* <29> */
    unsigned grp111_reserved_27;                      /* <30> */
    unsigned grp111_reserved_28;                      /* <31> */
    // GROUP 112 [png_grp]
    unsigned png_dec_mode;                            /* < 0> [dv:     0x0010] [des: PNG Decoder Mode] */
    unsigned png_bs_str_addr_m;                       /* < 1> [dv:     0x0000] [des: Bitstream Start Address] */
    unsigned png_bs_str_addr_l;                       /* < 2> [dv:     0x0000] [des: Bitstream Start Address] */
    unsigned png_bs_end_addr_m;                       /* < 3> [dv:     0xffff] [des: Bitstream End Address] */
    unsigned png_bs_end_addr_l;                       /* < 4> [dv:     0xffff] [des: Bitstream End Address] */
    unsigned png_bs_buf_addr;                         /* < 5> [dv:     0x0000] [des: Bitstream Buffer Base Address] */
    unsigned png_bs_offset;                           /* < 6> [dv:     0x0000] [des: Bitstream Offset] */
    unsigned png_bs_used_cnt;                         /* < 7> [dv:     0x0000] [des: Used Bitstream Count] */
    unsigned png_bs_used_bit;                         /* < 8> [dv:     0x0000] [des: Used Bitstream] */
    unsigned png_dec_ctrl;                            /* < 9> [dv:     0x0000] [des: PNG Decoding Control] */
    unsigned png_img_width;                           /* <10> [dv:     0x0000] [des: Image Width] */
    unsigned png_img_height;                          /* <11> [dv:     0x0000] [des: Image Height] */
    unsigned png_img_type;                            /* <12> [dv:     0x0000] [des: Image Type] */
    unsigned png_chunk_size_m;                        /* <13> [dv:     0x0000] [des: Chunk Size] */
    unsigned png_chunk_size_l;                        /* <14> [dv:     0x0000] [des: Chunk Size] */
    unsigned png_blk_info;                            /* <15> [dv:     0x0000] [des: Block Information] */
    unsigned png_huf_tb_addr;                         /* <16> [dv:     0x0000] [des: Huffman Table Base Address] */
    unsigned png_huf_tb_ctrl;                         /* <17> [dv:     0x0000] [des: Huffman Table Access Control] */
    unsigned png_huf_tb_data;                         /* <18> [dv:     0x0000] [des: Huffman Table Content] */
    unsigned png_interrupt;                           /* <19> [dv:     0x0000] [des: Interrupt Control] */
    unsigned png_scl_ext_addr_m;                      /* <20> [dv:     0x0000] [des: Pre-Scanline External Base Address] */
    unsigned png_scl_ext_addr_l;                      /* <21> [dv:     0x0000] [des: Pre-Scanline External Base Address] */
    unsigned png_scl_buf_addr;                        /* <22> [dv:     0x0000] [des: Pre-Scanline Buffer Base Address] */
    unsigned png_bw_ext_addr_m;                       /* <23> [dv:     0x0000] [des: Backward Data External Base Address] */
    unsigned png_bw_ext_addr_l;                       /* <24> [dv:     0x0000] [des: Backward Data External Base Address] */
    unsigned png_rem_chunk_size_m;                    /* <25> [dv:     0xffff] [des: Remaining Chunk Size] */
    unsigned png_rem_chunk_size_l;                    /* <26> [dv:     0xffff] [des: Remaining Chunk Size] */
    unsigned png_pxl_ext_addr_m;                      /* <27> [dv:     0x0000] [des: Pixel Data External Base Address] */
    unsigned png_pxl_ext_addr_l;                      /* <28> [dv:     0x0000] [des: Pixel Data External Base Address] */
    unsigned png_pxl_line;                            /* <29> [dv:     0x0000] [des: Pixel Line] */
    unsigned png_probe_addr;                          /* <30> [dv:     0x0000] [des: Debug Address] */
    unsigned png_probe_value;                         /* <31> [dv:     0x0000] [des: Debug Value] */
    // GROUP 113
    unsigned grp113_reserved[32];
    // GROUP 114
    unsigned grp114_reserved[32];
    // GROUP 115 [gps]
    unsigned rf_rdata;                                /* < 0> [dv: 0x00000000] [des: GPS RF Dump Data Register] */
    unsigned gps_ctrl;                                /* < 1> [dv: 0x00000000] [des: GPS Control Register] */
    unsigned gps_dump_ctrl;                           /* < 2> [dv: 0x000d0000] [des: GPS Dump Control Register] */
    unsigned grp115_reserved_0;                       /* < 3> */
    unsigned grp115_reserved_1;                       /* < 4> */
    unsigned grp115_reserved_2;                       /* < 5> */
    unsigned grp115_reserved_3;                       /* < 6> */
    unsigned grp115_reserved_4;                       /* < 7> */
    unsigned grp115_reserved_5;                       /* < 8> */
    unsigned grp115_reserved_6;                       /* < 9> */
    unsigned grp115_reserved_7;                       /* <10> */
    unsigned grp115_reserved_8;                       /* <11> */
    unsigned grp115_reserved_9;                       /* <12> */
    unsigned grp115_reserved_10;                      /* <13> */
    unsigned grp115_reserved_11;                      /* <14> */
    unsigned grp115_reserved_12;                      /* <15> */
    unsigned grp115_reserved_13;                      /* <16> */
    unsigned grp115_reserved_14;                      /* <17> */
    unsigned grp115_reserved_15;                      /* <18> */
    unsigned grp115_reserved_16;                      /* <19> */
    unsigned grp115_reserved_17;                      /* <20> */
    unsigned grp115_reserved_18;                      /* <21> */
    unsigned grp115_reserved_19;                      /* <22> */
    unsigned grp115_reserved_20;                      /* <23> */
    unsigned grp115_reserved_21;                      /* <24> */
    unsigned grp115_reserved_22;                      /* <25> */
    unsigned grp115_reserved_23;                      /* <26> */
    unsigned grp115_reserved_24;                      /* <27> */
    unsigned grp115_reserved_25;                      /* <28> */
    unsigned grp115_reserved_26;                      /* <29> */
    unsigned grp115_reserved_27;                      /* <30> */
    unsigned grp115_reserved_28;                      /* <31> */
    // GROUP 116 [rtc]
    unsigned grp116_reserved_0;                       /* < 0> */
    unsigned rtc_ctrl;                                /* < 1> [dv: 0x00000000] [des: RTC Control Register] */
    unsigned rtc_timer;                               /* < 2> [dv: 0x00000000] [des: RTC Timer Register] */
    unsigned rtc_ontime_set;                          /* < 3> [dv: 0x00000000] [des: RTC Ontime Setting] */
    unsigned rtc_clock_set;                           /* < 4> [dv: 0x00000000] [des: RTC Clock Setting] */
    unsigned grp116_reserved_1;                       /* < 5> */
    unsigned grp116_reserved_2;                       /* < 6> */
    unsigned grp116_reserved_3;                       /* < 7> */
    unsigned grp116_reserved_4;                       /* < 8> */
    unsigned reserved_0_18;                           /* < 9> [dv: 0x00000000] [des: Reserved] */
    unsigned grp116_reserved_5;                       /* <10> */
    unsigned grp116_reserved_6;                       /* <11> */
    unsigned grp116_reserved_7;                       /* <12> */
    unsigned grp116_reserved_8;                       /* <13> */
    unsigned grp116_reserved_9;                       /* <14> */
    unsigned grp116_reserved_10;                      /* <15> */
    unsigned grp116_reserved_11;                      /* <16> */
    unsigned grp116_reserved_12;                      /* <17> */
    unsigned grp116_reserved_13;                      /* <18> */
    unsigned grp116_reserved_14;                      /* <19> */
    unsigned grp116_reserved_15;                      /* <20> */
    unsigned grp116_reserved_16;                      /* <21> */
    unsigned grp116_reserved_17;                      /* <22> */
    unsigned grp116_reserved_18;                      /* <23> */
    unsigned grp116_reserved_19;                      /* <24> */
    unsigned grp116_reserved_20;                      /* <25> */
    unsigned grp116_reserved_21;                      /* <26> */
    unsigned grp116_reserved_22;                      /* <27> */
    unsigned grp116_reserved_23;                      /* <28> */
    unsigned grp116_reserved_24;                      /* <29> */
    unsigned grp116_reserved_25;                      /* <30> */
    unsigned grp116_reserved_26;                      /* <31> */
    // GROUP 117
    unsigned grp117_reserved[32];
    // GROUP 118 [card_ctl_general_registers]
    unsigned card_mediatype;                          /* < 0> [dv:     0x0000] [des: Card Media Type] */
    unsigned reserved_0_19;                           /* < 1> [dv:     0x0000] [des: Reserved] */
    unsigned card_cpu_page_cnt;                       /* < 2> [dv:     0xffff] [des: CPU Page Count] */
    unsigned card_ctl_page_cnt;                       /* < 3> [dv:     0x0000] [des: CARD_CTL Page Count] */
    unsigned sdram_sector_0_size;                     /* < 4> [dv:     0xffff] [des: Length of SDRAM Sector_0] */
    unsigned ring_buffer_on;                          /* < 5> [dv:     0x0000] [des: Ring Buffer On] */
    unsigned card_gclk_disable;                       /* < 6> [dv:     0x0000] [des: Clock Gated Disable] */
    unsigned sdram_sector_1_addr;                     /* < 7> [dv:     0x0000] [des: Start Address of SDRAM sector_1] */
    unsigned sdram_sector_1_size_150;                 /* < 8> [dv:     0x0000] [des: Length of SDRAM Sector_1] */
    unsigned sdram_sector_2_addr;                     /* < 9> [dv:     0x0000] [des: Start Address of SDRAM sector_2] */
    unsigned sdram_sector_2_size_150;                 /* <10> [dv:     0x0000] [des: Length of SDRAM Sector_2] */
    unsigned sdram_sector_3_addr;                     /* <11> [dv:     0x0000] [des: Start Address of SDRAM sector_3] */
    unsigned sdram_sector_3_size_150;                 /* <12> [dv:     0x0000] [des: Length of SDRAM Sector_3] */
    unsigned sdram_sector_4_addr;                     /* <13> [dv:     0x0000] [des: Start Address of SDRAM sector_4] */
    unsigned sdram_sector_4_size_150;                 /* <14> [dv:     0x0000] [des: Length of SDRAM Sector_4] */
    unsigned sdram_sector_5_addr;                     /* <15> [dv:     0x0000] [des: Start Address of SDRAM sector_5] */
    unsigned sdram_sector_5_size_150;                 /* <16> [dv:     0x0000] [des: Length of SDRAM Sector_5] */
    unsigned sdram_sector_6_addr;                     /* <17> [dv:     0x0000] [des: Start Address of SDRAM sector_6] */
    unsigned sdram_sector_6_size_150;                 /* <18> [dv:     0x0000] [des: Length of SDRAM Sector_6] */
    unsigned sdram_sector_7_addr;                     /* <19> [dv:     0x0000] [des: Start Address of SDRAM sector_7] */
    unsigned sdram_sector_7_size_150;                 /* <20> [dv:     0x0000] [des: Length of SDRAM Sector_7] */
    unsigned sdram_sectro_cnt;                        /* <21> [dv:     0x0000] [des: SDRAM Sector Counter] */
    unsigned reserved_1_15;                           /* <22> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_2_14;                           /* <23> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_3_13;                           /* <24> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_4_13;                           /* <25> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_5_13;                           /* <26> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_6_12;                           /* <27> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_7_12;                           /* <28> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_8_11;                           /* <29> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_9_10;                           /* <30> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_10_10;                          /* <31> [dv:     0x0000] [des: Reserved] */
    // GROUP 119 [card_ctl_sd_controller]
    unsigned reserved_0_20;                           /* < 0> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_1_16;                           /* < 1> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_2_15;                           /* < 2> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_3_14;                           /* < 3> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_4_14;                           /* < 4> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_5_14;                           /* < 5> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_6_13;                           /* < 6> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_7_13;                           /* < 7> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_8_12;                           /* < 8> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_9_11;                           /* < 9> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_10_11;                          /* <10> [dv:     0x0000] [des: Reserved] */
    unsigned sd_vol_ctrl;                             /* <11> [dv:     0x0003] [des: SD Voltage register] */
    unsigned sd_int;                                  /* <12> [dv:     0x0000] [des: SD INT Control] */
    unsigned sd_page_num;                             /* <13> [dv:     0x0000] [des: SD Page number for this transfer] */
    unsigned sd_config0;                              /* <14> [dv:     0x00c0] [des: SD Controller transaction mode select] */
    unsigned sdio_ctrl;                               /* <15> [dv:     0x0000] [des: SDIO Controller Reset] */
    unsigned sd_rst;                                  /* <16> [dv:     0x0000] [des: SD Controller Reset] */
    unsigned sd_config;                               /* <17> [dv:     0x3003] [des: SD Controller Type Selection] */
    unsigned sd_ctrl;                                 /* <18> [dv:     0x0000] [des: SD Controller Control Signal] */
    unsigned sd_status;                               /* <19> [dv:     0x0035] [des: SD Controller Status] */
    unsigned sd_state;                                /* <20> [dv:     0x4000] [des: SD Controller State Machine] */
    unsigned sd_blocksize;                            /* <21> [dv:     0x01ff] [des: SD Controller Data Length] */
    unsigned sd_hwdma_config;                         /* <22> [dv:     0x0000] [des: SD HW DMA Configure] */
    unsigned sd_timing_config0;                       /* <23> [dv:     0x05ff] [des: SD Controller Response Timer] */
    unsigned sd_timing_config1;                       /* <24> [dv:     0x0020] [des: SD Controller CRC Timer] */
    unsigned sd_piodatatx;                            /* <25> [dv:     0xffff] [des: SD PIO Mode TX Data] */
    unsigned sd_piodatarx;                            /* <26> [dv:     0x0000] [des: SD PIO Mode RX Data] */
    unsigned sd_cmdbuf_0;                             /* <27> [dv:     0x00ff] [des: SD Command Buffer0] */
    unsigned sd_cmdbuf_1;                             /* <28> [dv:     0x00ff] [des: SD Command Buffer1] */
    unsigned sd_cmdbuf_2;                             /* <29> [dv:     0x00ff] [des: SD Command Buffer2] */
    unsigned sd_cmdbuf_3;                             /* <30> [dv:     0x00ff] [des: SD Command Buffer3] */
    unsigned sd_cmdbuf_4;                             /* <31> [dv:     0x00ff] [des: SD Command Buffer4] */
    // GROUP 120 [card_ctl_sd_controller_and_ms_controller]
    unsigned sd_rspbuf_0_3;                           /* < 0> [dv:     0x0000] [des: SD Response Buffer0~3] */
    unsigned sd_rspbuf_4_5;                           /* < 1> [dv:     0x0000] [des: SD Response Buffer4~5] */
    unsigned sd_crc16even_0;                          /* < 2> [dv:     0x0000] [des: SD CRC16 Buffer0 for Even Dat0(DDR mode)] */
    unsigned sd_crc16even_1;                          /* < 3> [dv:     0x0000] [des: SD CRC16 Buffer1 for Even Dat1(DDR mode)] */
    unsigned sd_crc16even_2;                          /* < 4> [dv:     0x0000] [des: SD CRC16 Buffer2 for Even Dat2(DDR mode)] */
    unsigned sd_crc16even_3;                          /* < 5> [dv:     0x0000] [des: SD CRC16 Buffer3 for Even Dat3(DDR mode)] */
    unsigned sd_crc7buf;                              /* < 6> [dv:     0x0001] [des: SD CRC7 Buffer] */
    unsigned sd_crc16buf0;                            /* < 7> [dv:     0x0000] [des: SD CRC16 Buffer0] */
    unsigned sd_hw_state;                             /* < 8> [dv:     0x0000] [des: Hardware SD State Machine] */
    unsigned sd_crc16buf1;                            /* < 9> [dv:     0x0000] [des: SD CRC16 Buffer1] */
    unsigned sd_hw_cmd13_rca;                         /* <10> [dv:     0x0000] [des: SD HW DMA RCA] */
    unsigned sd_crc16buf2;                            /* <11> [dv:     0x0000] [des: SD CRC16 Buffer2] */
    unsigned sd_tx_dummy_num;                         /* <12> [dv:     0x0007] [des: Dummy Clock Number] */
    unsigned sd_crc16buf3;                            /* <13> [dv:     0x0000] [des: SD CRC16 Buffer3] */
    unsigned sd_clk_dly;                              /* <14> [dv:     0x0002] [des: SD Clock Delay] */
    unsigned reserved_0_21;                           /* <15> [dv:     0x0000] [des: Reserved] */
    unsigned ms_piodmarst;                            /* <16> [dv:     0x0000] [des: MS Operation Mode and Reset Signal] */
    unsigned ms_cmd;                                  /* <17> [dv:     0x0000] [des: MS TPC Code And Data Size] */
    unsigned reserved_1_17;                           /* <18> [dv:     0x0000] [des: Reserved] */
    unsigned ms_hw_state;                             /* <19> [dv:     0x0000] [des: Hardware MS State] */
    unsigned ms_modespeed;                            /* <20> [dv:     0x00ff] [des: MS Clock Frequency Configure] */
    unsigned ms_timout;                               /* <21> [dv:     0x001f] [des: MS Busy Rdy Timer] */
    unsigned ms_state;                                /* <22> [dv:     0x0001] [des: MS Controller State Machine] */
    unsigned ms_status;                               /* <23> [dv:     0x0000] [des: Debug information of MS Controller] */
    unsigned ms_rddata_0;                             /* <24> [dv:     0x0000] [des: Read Data Buffer0] */
    unsigned ms_rddata_1;                             /* <25> [dv:     0x0000] [des: Read data Buffer1] */
    unsigned ms_rddata_2;                             /* <26> [dv:     0x0000] [des: Read Data Buffer2] */
    unsigned ms_rddata_3;                             /* <27> [dv:     0x0000] [des: Read data Buffer3] */
    unsigned ms_crcbuf_70;                            /* <28> [dv:     0x0000] [des: Low Byte of MS Data CRC16] */
    unsigned ms_crcbuf_158;                           /* <29> [dv:     0x0000] [des: High Byte of MS Data CRC16] */
    unsigned ms_crcerror;                             /* <30> [dv:     0x0002] [des: MS CRC Check Result and Busy Rdy TimeOut] */
    unsigned ms_piordy;                               /* <31> [dv:     0x0000] [des: MS Controller PIO Ready] */
    // GROUP 121 [card_ctl_ms_controller]
    unsigned ms_wd_data_0;                            /* < 0> [dv:     0x0000] [des: MS Controller Write Data Buffer0] */
    unsigned ms_wd_data_1;                            /* < 1> [dv:     0x0000] [des: MS Controller Write Data Buffer1] */
    unsigned ms_wd_data_2;                            /* < 2> [dv:     0x0000] [des: MS Controller Write Data Buffer2] */
    unsigned ms_wd_data_3;                            /* < 3> [dv:     0x0000] [des: MS Controller Write Data Buffer3] */
    unsigned ms_wd_data_4;                            /* < 4> [dv:     0x0000] [des: MS Controller Write Data Buffer4] */
    unsigned ms_wd_data_5;                            /* < 5> [dv:     0x0000] [des: MS Controller Write Data Buffer5] */
    unsigned ms_wd_data_6;                            /* < 6> [dv:     0x0000] [des: MS Controller Write Data Buffer6] */
    unsigned ms_wd_data_7;                            /* < 7> [dv:     0x0000] [des: MS Controller Write Data Buffer7] */
    unsigned ms_wd_data_8;                            /* < 8> [dv:     0x0000] [des: MS Controller Write Data Buffer8] */
    unsigned ms_wd_data_9;                            /* < 9> [dv:     0x0000] [des: MS Controller Write Data Buffer9] */
    unsigned ms_wd_data_10;                           /* <10> [dv:     0x0000] [des: MS Controller Write Data Buffer10] */
    unsigned ms_wd_data_11;                           /* <11> [dv:     0x0000] [des: MS Controller Write Data Buffer11] */
    unsigned ms_wd_data_12;                           /* <12> [dv:     0x0000] [des: MS Controller Write Data Buffer12] */
    unsigned ms_wd_data_13;                           /* <13> [dv:     0x0000] [des: MS Controller Write Data Buffer13] */
    unsigned ms_wd_data_14;                           /* <14> [dv:     0x0000] [des: MS Controller Write Data Buffer14] */
    unsigned ms_wd_data_15;                           /* <15> [dv:     0x0000] [des: MS Controller Write Data Buffer15] */
    unsigned reserved_0_22;                           /* <16> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_1_18;                           /* <17> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_2_16;                           /* <18> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_3_15;                           /* <19> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_4_15;                           /* <20> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_5_15;                           /* <21> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_6_14;                           /* <22> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_7_14;                           /* <23> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_8_13;                           /* <24> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_9_12;                           /* <25> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_10_12;                          /* <26> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_11_9;                           /* <27> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_12_5;                           /* <28> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_13_5;                           /* <29> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_14_5;                           /* <30> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_15_4;                           /* <31> [dv:     0x0000] [des: Reserved] */
    // GROUP 122 [card_ctl_dma_controller_registers]
    unsigned dma_data;                                /* < 0> [dv:     0x0000] [des: DMA Write DATA] */
    unsigned dma_srcdst;                              /* < 1> [dv:     0x0000] [des: DMA Source and Detination Selection] */
    unsigned dma_size;                                /* < 2> [dv:     0x0000] [des: Data Size in DMA Transfer] */
    unsigned dma_hw_stop_rst;                         /* < 3> [dv:     0x0000] [des: HW DMA Stop and HW DMA Reset] */
    unsigned dma_ctrl;                                /* < 4> [dv:     0x0000] [des: DMA Reset] */
    unsigned dma_base_addr_150;                       /* < 5> [dv:     0x0000] [des: DMA Base Address Lower 16 bits] */
    unsigned dma_base_addr_3116;                      /* < 6> [dv:     0x0000] [des: DMA Base Address Higher 16 bits] */
    unsigned dma_hw_en;                               /* < 7> [dv:     0x0000] [des: HW DMA Enable] */
    unsigned dma_hw_page_addr_0_150;                  /* < 8> [dv:     0x0000] [des: Lower 16 bits of HW DMA Start Page Address of Block0] */
    unsigned dma_hw_page_addr_0_3116;                 /* < 9> [dv:     0x0000] [des: Higher 16 bits of HW DMA Start Page Address of Block0] */
    unsigned dma_hw_page_addr_1_150;                  /* <10> [dv:     0x0000] [des: Lower 16 bits of HW DMA Start Page Address of Block1] */
    unsigned dma_hw_page_addr_1_3116;                 /* <11> [dv:     0x0000] [des: Higher 16 bits of HW DMA Start Page Address of Block1] */
    unsigned dma_hw_page_addr_2_150;                  /* <12> [dv:     0x0000] [des: Lower 16 bits of HW DMA Start Page Address of Block2] */
    unsigned dma_hw_page_addr_2_3116;                 /* <13> [dv:     0x0000] [des: Higher 16 bits of HW DMA Start Page Address of Block2] */
    unsigned dma_hw_page_addr_3_150;                  /* <14> [dv:     0x0000] [des: Lower 16 bits of HW DMA Start Page Address of Block3] */
    unsigned dma_hw_page_addr_3_3116;                 /* <15> [dv:     0x0000] [des: Higher 16 bits of HW DMA Start Page Address of Block3] */
    unsigned dma_hw_page_num0;                        /* <16> [dv:     0x0000] [des: HW DMA Page Number of Block0] */
    unsigned dma_hw_page_num1;                        /* <17> [dv:     0x0000] [des: HW DMA Page Number of Block1] */
    unsigned dma_hw_page_num2;                        /* <18> [dv:     0x0000] [des: HW DMA Page Number of Block2] */
    unsigned dma_hw_page_num3;                        /* <19> [dv:     0x0000] [des: HW DMA Page Number of Block3] */
    unsigned dma_hw_block_num;                        /* <20> [dv:     0x0000] [des: HW DMA Block Number and Block counter] */
    unsigned dma_start;                               /* <21> [dv:     0x0000] [des: DMA Start] */
    unsigned dma_hw_page_cnt;                         /* <22> [dv:     0x0000] [des: HW DMA Page Counter for Page Number for Each Block] */
    unsigned dma_cmp;                                 /* <23> [dv:     0x0000] [des: 512 bytes data transfer complete] */
    unsigned dma_int_en_2;                            /* <24> [dv:     0x0000] [des: DMA Interrput Enable] */
    unsigned reserved_0_23;                           /* <25> [dv:     0x0000] [des: Reserved] */
    unsigned dma_hw_wait_num_150;                     /* <26> [dv:     0xffff] [des:  Lower 16 Bits of HW Wait Number] */
    unsigned dma_hw_wait_num_3116;                    /* <27> [dv:     0xffff] [des: Higher 16 Bits of HW Wait Number] */
    unsigned dma_hw_delay_num;                        /* <28> [dv:     0x003f] [des: HW Dealy Number] */
    unsigned reserved_1_19;                           /* <29> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_2_17;                           /* <30> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_3_16;                           /* <31> [dv:     0x0000] [des: Reserved] */
    // GROUP 123
    unsigned grp123_reserved[32];
    // GROUP 124
    unsigned grp124_reserved[32];
    // GROUP 125 [card_ctl_general_registers]
    unsigned card_mediatype_1;                        /* < 0> [dv:     0x0000] [des: Card Media Type] */
    unsigned reserved_0_24;                           /* < 1> [dv:     0x0000] [des: Reserved] */
    unsigned card_cpu_page_cnt_1;                     /* < 2> [dv:     0xffff] [des: CPU Page Count] */
    unsigned card_ctl_page_cnt_1;                     /* < 3> [dv:     0x0000] [des: CARD_CTL Page Count] */
    unsigned sdram_sector_0_size_1;                   /* < 4> [dv:     0xffff] [des: Length of SDRAM Sector_0] */
    unsigned ring_buffer_on_1;                        /* < 5> [dv:     0x0000] [des: Ring Buffer On] */
    unsigned card_gclk_disable_1;                     /* < 6> [dv:     0x0000] [des: Clock Gated Disable] */
    unsigned sdram_sector_1_addr_1;                   /* < 7> [dv:     0x0000] [des: Start Address of SDRAM sector_1] */
    unsigned sdram_sector_1_size_150_1;               /* < 8> [dv:     0x0000] [des: Length of SDRAM Sector_1] */
    unsigned sdram_sector_2_addr_1;                   /* < 9> [dv:     0x0000] [des: Start Address of SDRAM sector_2] */
    unsigned sdram_sector_2_size_150_1;               /* <10> [dv:     0x0000] [des: Length of SDRAM Sector_2] */
    unsigned sdram_sector_3_addr_1;                   /* <11> [dv:     0x0000] [des: Start Address of SDRAM sector_3] */
    unsigned sdram_sector_3_size_150_1;               /* <12> [dv:     0x0000] [des: Length of SDRAM Sector_3] */
    unsigned sdram_sector_4_addr_1;                   /* <13> [dv:     0x0000] [des: Start Address of SDRAM sector_4] */
    unsigned sdram_sector_4_size_150_1;               /* <14> [dv:     0x0000] [des: Length of SDRAM Sector_4] */
    unsigned sdram_sector_5_addr_1;                   /* <15> [dv:     0x0000] [des: Start Address of SDRAM sector_5] */
    unsigned sdram_sector_5_size_150_1;               /* <16> [dv:     0x0000] [des: Length of SDRAM Sector_5] */
    unsigned sdram_sector_6_addr_1;                   /* <17> [dv:     0x0000] [des: Start Address of SDRAM sector_6] */
    unsigned sdram_sector_6_size_150_1;               /* <18> [dv:     0x0000] [des: Length of SDRAM Sector_6] */
    unsigned sdram_sector_7_addr_1;                   /* <19> [dv:     0x0000] [des: Start Address of SDRAM sector_7] */
    unsigned sdram_sector_7_size_150_1;               /* <20> [dv:     0x0000] [des: Length of SDRAM Sector_7] */
    unsigned sdram_sectro_cnt_1;                      /* <21> [dv:     0x0000] [des: SDRAM Sector Counter] */
    unsigned reserved_1_20;                           /* <22> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_2_18;                           /* <23> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_3_17;                           /* <24> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_4_16;                           /* <25> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_5_16;                           /* <26> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_6_15;                           /* <27> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_7_15;                           /* <28> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_8_14;                           /* <29> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_9_13;                           /* <30> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_10_13;                          /* <31> [dv:     0x0000] [des: Reserved] */
    // GROUP 126 [card_ctl_sd_controller]
    unsigned reserved_0_25;                           /* < 0> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_1_21;                           /* < 1> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_2_19;                           /* < 2> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_3_18;                           /* < 3> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_4_17;                           /* < 4> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_5_17;                           /* < 5> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_6_16;                           /* < 6> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_7_16;                           /* < 7> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_8_15;                           /* < 8> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_9_14;                           /* < 9> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_10_14;                          /* <10> [dv:     0x0000] [des: Reserved] */
    unsigned sd_vol_ctrl_1;                           /* <11> [dv:     0x0003] [des: SD Voltage register] */
    unsigned sd_int_1;                                /* <12> [dv:     0x0000] [des: SD INT Control] */
    unsigned sd_page_num_1;                           /* <13> [dv:     0x0000] [des: SD Page number for this transfer] */
    unsigned sd_config0_1;                            /* <14> [dv:     0x00c0] [des: SD Controller transaction mode select] */
    unsigned sdio_ctrl_1;                             /* <15> [dv:     0x0000] [des: SDIO Controller Reset] */
    unsigned sd_rst_1;                                /* <16> [dv:     0x0000] [des: SD Controller Reset] */
    unsigned sd_config_1;                             /* <17> [dv:     0x3003] [des: SD Controller Type Selection] */
    unsigned sd_ctrl_1;                               /* <18> [dv:     0x0000] [des: SD Controller Control Signal] */
    unsigned sd_status_1;                             /* <19> [dv:     0x0035] [des: SD Controller Status] */
    unsigned sd_state_1;                              /* <20> [dv:     0x4000] [des: SD Controller State Machine] */
    unsigned sd_blocksize_1;                          /* <21> [dv:     0x01ff] [des: SD Controller Data Length] */
    unsigned sd_hwdma_config_1;                       /* <22> [dv:     0x0000] [des: SD HW DMA Configure] */
    unsigned sd_timing_config0_1;                     /* <23> [dv:     0x05ff] [des: SD Controller Response Timer] */
    unsigned sd_timing_config1_1;                     /* <24> [dv:     0x0020] [des: SD Controller CRC Timer] */
    unsigned sd_piodatatx_1;                          /* <25> [dv:     0xffff] [des: SD PIO Mode TX Data] */
    unsigned sd_piodatarx_1;                          /* <26> [dv:     0x0000] [des: SD PIO Mode RX Data] */
    unsigned sd_cmdbuf_0_1;                           /* <27> [dv:     0x00ff] [des: SD Command Buffer0] */
    unsigned sd_cmdbuf_1_1;                           /* <28> [dv:     0x00ff] [des: SD Command Buffer1] */
    unsigned sd_cmdbuf_2_1;                           /* <29> [dv:     0x00ff] [des: SD Command Buffer2] */
    unsigned sd_cmdbuf_3_1;                           /* <30> [dv:     0x00ff] [des: SD Command Buffer3] */
    unsigned sd_cmdbuf_4_1;                           /* <31> [dv:     0x00ff] [des: SD Command Buffer4] */
    // GROUP 127 [card_ctl_sd_controller_and_ms_controller]
    unsigned sd_rspbuf_0_3_1;                         /* < 0> [dv:     0x0000] [des: SD Response Buffer0~3] */
    unsigned sd_rspbuf_4_5_1;                         /* < 1> [dv:     0x0000] [des: SD Response Buffer4~5] */
    unsigned sd_crc16even_0_1;                        /* < 2> [dv:     0x0000] [des: SD CRC16 Buffer0 for Even Dat0(DDR mode)] */
    unsigned sd_crc16even_1_1;                        /* < 3> [dv:     0x0000] [des: SD CRC16 Buffer1 for Even Dat1(DDR mode)] */
    unsigned sd_crc16even_2_1;                        /* < 4> [dv:     0x0000] [des: SD CRC16 Buffer2 for Even Dat2(DDR mode)] */
    unsigned sd_crc16even_3_1;                        /* < 5> [dv:     0x0000] [des: SD CRC16 Buffer3 for Even Dat3(DDR mode)] */
    unsigned sd_crc7buf_1;                            /* < 6> [dv:     0x0001] [des: SD CRC7 Buffer] */
    unsigned sd_crc16buf0_1;                          /* < 7> [dv:     0x0000] [des: SD CRC16 Buffer0] */
    unsigned sd_hw_state_1;                           /* < 8> [dv:     0x0000] [des: Hardware SD State Machine] */
    unsigned sd_crc16buf1_1;                          /* < 9> [dv:     0x0000] [des: SD CRC16 Buffer1] */
    unsigned sd_hw_cmd13_rca_1;                       /* <10> [dv:     0x0000] [des: SD HW DMA RCA] */
    unsigned sd_crc16buf2_1;                          /* <11> [dv:     0x0000] [des: SD CRC16 Buffer2] */
    unsigned sd_tx_dummy_num_1;                       /* <12> [dv:     0x0007] [des: Dummy Clock Number] */
    unsigned sd_crc16buf3_1;                          /* <13> [dv:     0x0000] [des: SD CRC16 Buffer3] */
    unsigned sd_clk_dly_1;                            /* <14> [dv:     0x0002] [des: SD Clock Delay] */
    unsigned reserved_0_26;                           /* <15> [dv:     0x0000] [des: Reserved] */
    unsigned ms_piodmarst_1;                          /* <16> [dv:     0x0000] [des: MS Operation Mode and Reset Signal] */
    unsigned ms_cmd_1;                                /* <17> [dv:     0x0000] [des: MS TPC Code And Data Size] */
    unsigned reserved_1_22;                           /* <18> [dv:     0x0000] [des: Reserved] */
    unsigned ms_hw_state_1;                           /* <19> [dv:     0x0000] [des: Hardware MS State] */
    unsigned ms_modespeed_1;                          /* <20> [dv:     0x00ff] [des: MS Clock Frequency Configure] */
    unsigned ms_timout_1;                             /* <21> [dv:     0x001f] [des: MS Busy Rdy Timer] */
    unsigned ms_state_1;                              /* <22> [dv:     0x0001] [des: MS Controller State Machine] */
    unsigned ms_status_1;                             /* <23> [dv:     0x0000] [des: Debug information of MS Controller] */
    unsigned ms_rddata_0_1;                           /* <24> [dv:     0x0000] [des: Read Data Buffer0] */
    unsigned ms_rddata_1_1;                           /* <25> [dv:     0x0000] [des: Read data Buffer1] */
    unsigned ms_rddata_2_1;                           /* <26> [dv:     0x0000] [des: Read Data Buffer2] */
    unsigned ms_rddata_3_1;                           /* <27> [dv:     0x0000] [des: Read data Buffer3] */
    unsigned ms_crcbuf_70_1;                          /* <28> [dv:     0x0000] [des: Low Byte of MS Data CRC16] */
    unsigned ms_crcbuf_158_1;                         /* <29> [dv:     0x0000] [des: High Byte of MS Data CRC16] */
    unsigned ms_crcerror_1;                           /* <30> [dv:     0x0002] [des: MS CRC Check Result and Busy Rdy TimeOut] */
    unsigned ms_piordy_1;                             /* <31> [dv:     0x0000] [des: MS Controller PIO Ready] */
    // GROUP 128 [card_ctl_ms_controller]
    unsigned ms_wd_data_0_1;                          /* < 0> [dv:     0x0000] [des: MS Controller Write Data Buffer0] */
    unsigned ms_wd_data_1_1;                          /* < 1> [dv:     0x0000] [des: MS Controller Write Data Buffer1] */
    unsigned ms_wd_data_2_1;                          /* < 2> [dv:     0x0000] [des: MS Controller Write Data Buffer2] */
    unsigned ms_wd_data_3_1;                          /* < 3> [dv:     0x0000] [des: MS Controller Write Data Buffer3] */
    unsigned ms_wd_data_4_1;                          /* < 4> [dv:     0x0000] [des: MS Controller Write Data Buffer4] */
    unsigned ms_wd_data_5_1;                          /* < 5> [dv:     0x0000] [des: MS Controller Write Data Buffer5] */
    unsigned ms_wd_data_6_1;                          /* < 6> [dv:     0x0000] [des: MS Controller Write Data Buffer6] */
    unsigned ms_wd_data_7_1;                          /* < 7> [dv:     0x0000] [des: MS Controller Write Data Buffer7] */
    unsigned ms_wd_data_8_1;                          /* < 8> [dv:     0x0000] [des: MS Controller Write Data Buffer8] */
    unsigned ms_wd_data_9_1;                          /* < 9> [dv:     0x0000] [des: MS Controller Write Data Buffer9] */
    unsigned ms_wd_data_10_1;                         /* <10> [dv:     0x0000] [des: MS Controller Write Data Buffer10] */
    unsigned ms_wd_data_11_1;                         /* <11> [dv:     0x0000] [des: MS Controller Write Data Buffer11] */
    unsigned ms_wd_data_12_1;                         /* <12> [dv:     0x0000] [des: MS Controller Write Data Buffer12] */
    unsigned ms_wd_data_13_1;                         /* <13> [dv:     0x0000] [des: MS Controller Write Data Buffer13] */
    unsigned ms_wd_data_14_1;                         /* <14> [dv:     0x0000] [des: MS Controller Write Data Buffer14] */
    unsigned ms_wd_data_15_1;                         /* <15> [dv:     0x0000] [des: MS Controller Write Data Buffer15] */
    unsigned reserved_0_27;                           /* <16> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_1_23;                           /* <17> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_2_20;                           /* <18> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_3_19;                           /* <19> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_4_18;                           /* <20> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_5_18;                           /* <21> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_6_17;                           /* <22> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_7_17;                           /* <23> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_8_16;                           /* <24> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_9_15;                           /* <25> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_10_15;                          /* <26> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_11_10;                          /* <27> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_12_6;                           /* <28> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_13_6;                           /* <29> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_14_6;                           /* <30> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_15_5;                           /* <31> [dv:     0x0000] [des: Reserved] */
    // GROUP 129 [card_ctl_dma_controller_registers]
    unsigned dma_data_1;                              /* < 0> [dv:     0x0000] [des: DMA Write DATA] */
    unsigned dma_srcdst_1;                            /* < 1> [dv:     0x0000] [des: DMA Source and Detination Selection] */
    unsigned dma_size_1;                              /* < 2> [dv:     0x0000] [des: Data Size in DMA Transfer] */
    unsigned dma_hw_stop_rst_1;                       /* < 3> [dv:     0x0000] [des: HW DMA Stop and HW DMA Reset] */
    unsigned dma_ctrl_1;                              /* < 4> [dv:     0x0000] [des: DMA Reset] */
    unsigned dma_base_addr_150_1;                     /* < 5> [dv:     0x0000] [des: DMA Base Address Lower 16 bits] */
    unsigned dma_base_addr_3116_1;                    /* < 6> [dv:     0x0000] [des: DMA Base Address Higher 16 bits] */
    unsigned dma_hw_en_1;                             /* < 7> [dv:     0x0000] [des: HW DMA Enable] */
    unsigned dma_hw_page_addr_0_150_1;                /* < 8> [dv:     0x0000] [des: Lower 16 bits of HW DMA Start Page Address of Block0] */
    unsigned dma_hw_page_addr_0_3116_1;               /* < 9> [dv:     0x0000] [des: Higher 16 bits of HW DMA Start Page Address of Block0] */
    unsigned dma_hw_page_addr_1_150_1;                /* <10> [dv:     0x0000] [des: Lower 16 bits of HW DMA Start Page Address of Block1] */
    unsigned dma_hw_page_addr_1_3116_1;               /* <11> [dv:     0x0000] [des: Higher 16 bits of HW DMA Start Page Address of Block1] */
    unsigned dma_hw_page_addr_2_150_1;                /* <12> [dv:     0x0000] [des: Lower 16 bits of HW DMA Start Page Address of Block2] */
    unsigned dma_hw_page_addr_2_3116_1;               /* <13> [dv:     0x0000] [des: Higher 16 bits of HW DMA Start Page Address of Block2] */
    unsigned dma_hw_page_addr_3_150_1;                /* <14> [dv:     0x0000] [des: Lower 16 bits of HW DMA Start Page Address of Block3] */
    unsigned dma_hw_page_addr_3_3116_1;               /* <15> [dv:     0x0000] [des: Higher 16 bits of HW DMA Start Page Address of Block3] */
    unsigned dma_hw_page_num0_1;                      /* <16> [dv:     0x0000] [des: HW DMA Page Number of Block0] */
    unsigned dma_hw_page_num1_1;                      /* <17> [dv:     0x0000] [des: HW DMA Page Number of Block1] */
    unsigned dma_hw_page_num2_1;                      /* <18> [dv:     0x0000] [des: HW DMA Page Number of Block2] */
    unsigned dma_hw_page_num3_1;                      /* <19> [dv:     0x0000] [des: HW DMA Page Number of Block3] */
    unsigned dma_hw_block_num_1;                      /* <20> [dv:     0x0000] [des: HW DMA Block Number and Block counter] */
    unsigned dma_start_1;                             /* <21> [dv:     0x0000] [des: DMA Start] */
    unsigned dma_hw_page_cnt_1;                       /* <22> [dv:     0x0000] [des: HW DMA Page Counter for Page Number for Each Block] */
    unsigned dma_cmp_1;                               /* <23> [dv:     0x0000] [des: 512 bytes data transfer complete] */
    unsigned dma_int_en_3;                            /* <24> [dv:     0x0000] [des: DMA Interrput Enable] */
    unsigned reserved_0_28;                           /* <25> [dv:     0x0000] [des: Reserved] */
    unsigned dma_hw_wait_num_150_1;                   /* <26> [dv:     0xffff] [des:  Lower 16 Bits of HW Wait Number] */
    unsigned dma_hw_wait_num_3116_1;                  /* <27> [dv:     0xffff] [des: Higher 16 Bits of HW Wait Number] */
    unsigned dma_hw_delay_num_1;                      /* <28> [dv:     0x003f] [des: HW Dealy Number] */
    unsigned reserved_1_24;                           /* <29> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_2_21;                           /* <30> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_3_20;                           /* <31> [dv:     0x0000] [des: Reserved] */
    // GROUP 130
    unsigned grp130_reserved[32];
    // GROUP 131
    unsigned grp131_reserved[32];
    // GROUP 132
    unsigned grp132_reserved[32];
    // GROUP 133
    unsigned grp133_reserved[32];
    // GROUP 134
    unsigned grp134_reserved[32];
    // GROUP 135
    unsigned grp135_reserved[32];
    // GROUP 136
    unsigned grp136_reserved[32];
    // GROUP 137 [secondary_huf_grp]
    unsigned jpeg_huff_mode_1;                        /* < 0> [dv:     0x3000] [des: Huffman Decoder Mode Register] */
    unsigned jpeg_huff_ctrl_1;                        /* < 1> [dv:     0x0000] [des: Huffman Decoder Control Register] */
    unsigned jpeg_huff_status_1;                      /* < 2> [dv:     0x0008] [des: Huffman Decoder Status Register] */
    unsigned jpeg_huff_scan_ctrl_1;                   /* < 3> [dv:     0x0000] [des: Huffman Scan Control Register] */
    unsigned jpeg_huff_table_1;                       /* < 4> [dv:     0x0000] [des: Huffman Decoder Table Register] */
    unsigned jpeg_huff_mcuno_1;                       /* < 5> [dv:     0x0000] [des: Huffman MCU Number Register] */
    unsigned jpeg_huff_jpeghsize_1;                   /* < 6> [dv:     0x0000] [des: Huffman JPEG Horizontal Size Register] */
    unsigned jpeg_huff_jpegvsize_1;                   /* < 7> [dv:     0x0000] [des: Huffman JPEG Vertical Size Register] */
    unsigned jpeg_huff_bitstream_1;                   /* < 8> [dv:     0x0000] [des: Huffman Bitstream Register] */
    unsigned jpeg_huff_bits_dma_offset_1;             /* < 9> [dv:     0x0000] [des: Huffman Bitstream DMA Offset Register] */
    unsigned jpeg_huff_wr_huff_info_1;                /* <10> [dv:     0x0000] [des: Huffman Decoder Information Update Register] */
    unsigned jpeg_huff_bits_info_1;                   /* <11> [dv:     0x0000] [des: Huffman Bitstream Information Register] */
    unsigned jpeg_huff_rd_huff_info_1;                /* <12> [dv:     0x0001] [des: Huffman Decoder Information Register] */
    unsigned jpeg_huff_dma_offset_0_1;                /* <13> [dv:     0x0000] [des: Huffman DMA1 Offset Register] */
    unsigned jpeg_huff_dma_offset_1_1;                /* <14> [dv:     0x0000] [des: Huffman DMA2 Offset Register] */
    unsigned jpeg_huff_acval_offset_0_1;              /* <15> [dv:     0x0000] [des: Huffman AC Table 0 Offset Register] */
    unsigned jpeg_huff_acval_offset_1_1;              /* <16> [dv:     0x0000] [des: Huffman AC Table 1 Offset Register] */
    unsigned jpeg_huff_acval_offset_2_1;              /* <17> [dv:     0x0000] [des: Huffman AC Table 2 Offset Register] */
    unsigned jpeg_huff_acval_offset_3_1;              /* <18> [dv:     0x0000] [des: Huffman AC Table 3 Offset Register] */
    unsigned jpeg_huff_wr_dc_01_1;                    /* <19> [dv:     0x5555] [des: Huffman Write DC 0-1 Table Register] */
    unsigned jpeg_huff_wr_dc_23_1;                    /* <20> [dv:     0x5555] [des: Huffman Write DC 2-3 Table Register] */
    unsigned jpeg_huff_wr_acval_0_1;                  /* <21> [dv:     0x5555] [des: Huffman Write AC 0 Table Register] */
    unsigned jpeg_huff_wr_acval_1_1;                  /* <22> [dv:     0x5555] [des: Huffman Write AC 1 Table Register] */
    unsigned jpeg_huff_wr_acval_2_1;                  /* <23> [dv:     0x5555] [des: Huffman Write AC 2 Table Register] */
    unsigned jpeg_huff_wr_acval_3_1;                  /* <24> [dv:     0x5555] [des: Huffman Write AC 3 Table Register] */
    unsigned jpeg_huff_rd_addr_1;                     /* <25> [dv:     0x0000] [des: Huffman Read Table Register] */
    unsigned jpeg_huff_rd_val_1;                      /* <26> [dv:     0xe400] [des: Huffman Read Table Value Register] */
    unsigned jpeg_huff_probe_1;                       /* <27> [dv:     0x0000] [des: Huffman Probe Entry Register] */
    unsigned jr_control_1;                            /* <28> [dv:     0x0000] [des: JPEG Render Control Register] */
    unsigned jr_status_1;                             /* <29> [dv:     0x0040] [des: JPEG Render Status Register] */
    unsigned jr_reg_num_1;                            /* <30> [dv:     0x0000] [des: JPEG Render Register Number Register] */
    unsigned jr_reg_data_1;                           /* <31> [dv:     0x0000] [des: JPEG Render Register Data Register] */
    // GROUP 138 [secondary_jdm_grp]
    unsigned jdm_mode_1;                              /* < 0> [dv:     0x0000] [des: JDM Mode] */
    unsigned jdm_status_1;                            /* < 1> [dv:     0x0000] [des: JDM Status] */
    unsigned jdm_dma1_mode_1;                         /* < 2> [dv:     0x0000] [des: JDM DMA Mode] */
    unsigned jdm_dma1_xaddr_1;                        /* < 3> [dv:     0x0000] [des: JDM X Address] */
    unsigned jdm_dma1_yaddr_1;                        /* < 4> [dv:     0x0000] [des: JDM Y Address] */
    unsigned jdm_dma1_done_1;                         /* < 5> [dv:     0x0001] [des: DMA Done] */
    unsigned jdm_dma1_start_addr_1;                   /* < 6> [dv:     0x0000] [des: DMA Buffer Start Address] */
    unsigned jdm_dma1_block_num_1;                    /* < 7> [dv:     0x0000] [des: DMA Block Number] */
    unsigned grp138_reserved_0;                       /* < 8> */
    unsigned grp138_reserved_1;                       /* < 9> */
    unsigned grp138_reserved_2;                       /* <10> */
    unsigned grp138_reserved_3;                       /* <11> */
    unsigned grp138_reserved_4;                       /* <12> */
    unsigned grp138_reserved_5;                       /* <13> */
    unsigned jdm_png_trans_info_0_1;                  /* <14> [dv:     0x0000] [des: PNG Trasfer Info 0] */
    unsigned jdm_png_trans_info_1_1;                  /* <15> [dv:     0x0000] [des: PNG Trasfer Info 1] */
    unsigned jdm_gclk_free_1;                         /* <16> [dv:     0x0000] [des: Gated Clock Free Run] */
    unsigned jdm_mem_bound_protect_0_1;               /* <17> [dv:     0x0000] [des: Memory Boundary Protection 0] */
    unsigned jdm_mem_bound_protect_1_1;               /* <18> [dv:     0x0000] [des: Memory Boundary Protection 1] */
    unsigned jdm_dmabuf_chksum_addr_1;                /* <19> [dv:     0x0000] [des: DMA Buffer Address for Checksum] */
    unsigned jdm_dmabuf_chksum_0_1;                   /* <20> [dv:     0x0000] [des: DMA Buffer Checksum 0] */
    unsigned jdm_dmabuf_chksum_1_1;                   /* <21> [dv:     0x0000] [des: DMA Buffer Checksum 1] */
    unsigned mj_dc_luma_base_addr_l_1;                /* <22> [dv:     0x0000] [des: DC luma base LSB] */
    unsigned mj_dc_luma_base_addr_h_1;                /* <23> [dv:     0x0000] [des: DC luma base MSB] */
    unsigned mj_dc_chroma_base_addr_l_1;              /* <24> [dv:     0x0000] [des: DC Chroma base LSB] */
    unsigned mj_dc_chroma_base_addr_h_1;              /* <25> [dv:     0x0000] [des: DC Chroma base MSB] */
    unsigned mj_dc_width_1;                           /* <26> [dv:     0x0000] [des: DC buffer width] */
    unsigned grp138_reserved_6;                       /* <27> */
    unsigned grp138_reserved_7;                       /* <28> */
    unsigned jdm_jpeg_offset_1;                       /* <29> [dv:     0x0000] [des: JPEG IDCT Offset] */
    unsigned grp138_reserved_8;                       /* <30> */
    unsigned grp138_reserved_9;                       /* <31> */
    // GROUP 139 [secondary_jpeg_invq_grp]
    unsigned jpeg_invq_qmx_par_1;                     /* < 0> [dv:        n/a] [des: INVQ Quantization Matrix Access Register] */
    unsigned jpeg_invq_mode_1;                        /* < 1> [dv:     0x0000] [des: INVQ Operation Mode] */
    unsigned jpeg_invq_chksum_1;                      /* < 2> [dv:        n/a] [des: INVQ Checksum] */
    unsigned grp139_reserved_0;                       /* < 3> */
    unsigned grp139_reserved_1;                       /* < 4> */
    unsigned grp139_reserved_2;                       /* < 5> */
    unsigned grp139_reserved_3;                       /* < 6> */
    unsigned grp139_reserved_4;                       /* < 7> */
    unsigned grp139_reserved_5;                       /* < 8> */
    unsigned grp139_reserved_6;                       /* < 9> */
    unsigned grp139_reserved_7;                       /* <10> */
    unsigned grp139_reserved_8;                       /* <11> */
    unsigned grp139_reserved_9;                       /* <12> */
    unsigned grp139_reserved_10;                      /* <13> */
    unsigned grp139_reserved_11;                      /* <14> */
    unsigned grp139_reserved_12;                      /* <15> */
    unsigned grp139_reserved_13;                      /* <16> */
    unsigned grp139_reserved_14;                      /* <17> */
    unsigned grp139_reserved_15;                      /* <18> */
    unsigned grp139_reserved_16;                      /* <19> */
    unsigned grp139_reserved_17;                      /* <20> */
    unsigned grp139_reserved_18;                      /* <21> */
    unsigned grp139_reserved_19;                      /* <22> */
    unsigned grp139_reserved_20;                      /* <23> */
    unsigned grp139_reserved_21;                      /* <24> */
    unsigned grp139_reserved_22;                      /* <25> */
    unsigned grp139_reserved_23;                      /* <26> */
    unsigned grp139_reserved_24;                      /* <27> */
    unsigned grp139_reserved_25;                      /* <28> */
    unsigned grp139_reserved_26;                      /* <29> */
    unsigned grp139_reserved_27;                      /* <30> */
    unsigned grp139_reserved_28;                      /* <31> */
    // GROUP 140
    unsigned grp140_reserved[32];
    // GROUP 141
    unsigned grp141_reserved[32];
    // GROUP 142
    unsigned grp142_reserved[32];
    // GROUP 143
    unsigned grp143_reserved[32];
    // GROUP 144
    unsigned grp144_reserved[32];
    // GROUP 145
    unsigned grp145_reserved[32];
    // GROUP 146
    unsigned grp146_reserved[32];
    // GROUP 147
    unsigned grp147_reserved[32];
    // GROUP 148
    unsigned grp148_reserved[32];
    // GROUP 149 [uphy0_rn]
    unsigned cfg0;                                    /* < 0> [dv:       0x80] [des: CONFIG0] */
    unsigned cfg1;                                    /* < 1> [dv:       0x21] [des: CONFIG1] */
    unsigned cfg2;                                    /* < 2> [dv:       0x00] [des: CONFIG2] */
    unsigned cfg3;                                    /* < 3> [dv:       0x21] [des: CONFIG3] */
    unsigned cfg4;                                    /* < 4> [dv:       0x20] [des: CONFIG4] */
    unsigned cfg5;                                    /* < 5> [dv:       0x00] [des: CONFIG5] */
    unsigned cfg6;                                    /* < 6> [dv:       0x00] [des: CONFIG6] */
    unsigned cfg7;                                    /* < 7> [dv:       0x8a] [des: CONFIG7] */
    unsigned cfg8;                                    /* < 8> [dv:       0x00] [des: CONFIG8] */
    unsigned cfg9;                                    /* < 9> [dv:       0x06] [des: CONFIG9] */
    unsigned cfg10;                                   /* <10> [dv:       0x00] [des: CONFIG10] */
    unsigned cfg11;                                   /* <11> [dv:       0x00] [des: CONFIG11] */
    unsigned cfg12;                                   /* <12> [dv:       0x07] [des: CONFIG12] */
    unsigned cfg13;                                   /* <13> [dv:       0x00] [des: CONFIG13] */
    unsigned cfg14;                                   /* <14> [dv:       0x11] [des: CONFIG14] */
    unsigned cfg15;                                   /* <15> [dv:       0x00] [des: CONFIG15] */
    unsigned cfg16;                                   /* <16> [dv:       0x00] [des: CONFIG16] */
    unsigned cfg17;                                   /* <17> [dv:       0x84] [des: CONFIG17] */
    unsigned cfg18;                                   /* <18> [dv:       0x10] [des: CONFIG18] */
    unsigned cfg19;                                   /* <19> [dv:       0x00] [des: CONFIG19] */
    unsigned cfg20;                                   /* <20> [dv:       0x09] [des: CONFIG20] */
    unsigned cfg21;                                   /* <21> [dv:       0x01] [des: CONFIG21] */
    unsigned grp149_reserved_0;                       /* <22> */
    unsigned grp149_reserved_1;                       /* <23> */
    unsigned grp149_reserved_2;                       /* <24> */
    unsigned grp149_reserved_3;                       /* <25> */
    unsigned grp149_reserved_4;                       /* <26> */
    unsigned grp149_reserved_5;                       /* <27> */
    unsigned grp149_reserved_6;                       /* <28> */
    unsigned grp149_reserved_7;                       /* <29> */
    unsigned grp149_reserved_8;                       /* <30> */
    unsigned grp149_reserved_9;                       /* <31> */
    // GROUP 150 [uphy0_rn]
    unsigned cfg0_1;                                  /* < 0> [dv:       0x80] [des: CONFIG0] */
    unsigned cfg1_1;                                  /* < 1> [dv:       0x21] [des: CONFIG1] */
    unsigned cfg2_1;                                  /* < 2> [dv:       0x00] [des: CONFIG2] */
    unsigned cfg3_1;                                  /* < 3> [dv:       0x21] [des: CONFIG3] */
    unsigned cfg4_1;                                  /* < 4> [dv:       0x20] [des: CONFIG4] */
    unsigned cfg5_1;                                  /* < 5> [dv:       0x00] [des: CONFIG5] */
    unsigned cfg6_1;                                  /* < 6> [dv:       0x00] [des: CONFIG6] */
    unsigned cfg7_1;                                  /* < 7> [dv:       0x8a] [des: CONFIG7] */
    unsigned cfg8_1;                                  /* < 8> [dv:       0x00] [des: CONFIG8] */
    unsigned cfg9_1;                                  /* < 9> [dv:       0x06] [des: CONFIG9] */
    unsigned cfg10_1;                                 /* <10> [dv:       0x00] [des: CONFIG10] */
    unsigned cfg11_1;                                 /* <11> [dv:       0x00] [des: CONFIG11] */
    unsigned cfg12_1;                                 /* <12> [dv:       0x07] [des: CONFIG12] */
    unsigned cfg13_1;                                 /* <13> [dv:       0x00] [des: CONFIG13] */
    unsigned cfg14_1;                                 /* <14> [dv:       0x11] [des: CONFIG14] */
    unsigned cfg15_1;                                 /* <15> [dv:       0x00] [des: CONFIG15] */
    unsigned cfg16_1;                                 /* <16> [dv:       0x00] [des: CONFIG16] */
    unsigned cfg17_1;                                 /* <17> [dv:       0x84] [des: CONFIG17] */
    unsigned cfg18_1;                                 /* <18> [dv:       0x10] [des: CONFIG18] */
    unsigned cfg19_1;                                 /* <19> [dv:       0x00] [des: CONFIG19] */
    unsigned cfg20_1;                                 /* <20> [dv:       0x09] [des: CONFIG20] */
    unsigned cfg21_1;                                 /* <21> [dv:       0x01] [des: CONFIG21] */
    unsigned grp150_reserved_0;                       /* <22> */
    unsigned grp150_reserved_1;                       /* <23> */
    unsigned grp150_reserved_2;                       /* <24> */
    unsigned grp150_reserved_3;                       /* <25> */
    unsigned grp150_reserved_4;                       /* <26> */
    unsigned grp150_reserved_5;                       /* <27> */
    unsigned grp150_reserved_6;                       /* <28> */
    unsigned grp150_reserved_7;                       /* <29> */
    unsigned grp150_reserved_8;                       /* <30> */
    unsigned grp150_reserved_9;                       /* <31> */
    // GROUP 151 [uphy2_rn]
    unsigned cfg0_2;                                  /* < 0> [dv:       0x80] [des: CONFIG0] */
    unsigned cfg1_2;                                  /* < 1> [dv:       0x21] [des: CONFIG1] */
    unsigned cfg2_2;                                  /* < 2> [dv:       0x00] [des: CONFIG2] */
    unsigned cfg3_2;                                  /* < 3> [dv:       0x21] [des: CONFIG3] */
    unsigned cfg4_2;                                  /* < 4> [dv:       0x20] [des: CONFIG4] */
    unsigned cfg5_2;                                  /* < 5> [dv:       0x00] [des: CONFIG5] */
    unsigned cfg6_2;                                  /* < 6> [dv:       0x00] [des: CONFIG6] */
    unsigned cfg7_2;                                  /* < 7> [dv:       0x8a] [des: CONFIG7] */
    unsigned cfg8_2;                                  /* < 8> [dv:       0x00] [des: CONFIG8] */
    unsigned cfg9_2;                                  /* < 9> [dv:       0x06] [des: CONFIG9] */
    unsigned cfg10_2;                                 /* <10> [dv:       0x00] [des: CONFIG10] */
    unsigned cfg11_2;                                 /* <11> [dv:       0x00] [des: CONFIG11] */
    unsigned cfg12_2;                                 /* <12> [dv:       0x07] [des: CONFIG12] */
    unsigned cfg13_2;                                 /* <13> [dv:       0x00] [des: CONFIG13] */
    unsigned cfg14_2;                                 /* <14> [dv:       0x11] [des: CONFIG14] */
    unsigned cfg15_2;                                 /* <15> [dv:       0x00] [des: CONFIG15] */
    unsigned cfg16_2;                                 /* <16> [dv:       0x00] [des: CONFIG16] */
    unsigned cfg17_2;                                 /* <17> [dv:       0x84] [des: CONFIG17] */
    unsigned cfg18_2;                                 /* <18> [dv:       0x10] [des: CONFIG18] */
    unsigned cfg19_2;                                 /* <19> [dv:       0x00] [des: CONFIG19] */
    unsigned cfg20_2;                                 /* <20> [dv:       0x00] [des: Reserved] */
    unsigned cfg21_2;                                 /* <21> [dv:       0x01] [des: CONFIG21] */
    unsigned grp151_reserved_0;                       /* <22> */
    unsigned grp151_reserved_1;                       /* <23> */
    unsigned grp151_reserved_2;                       /* <24> */
    unsigned grp151_reserved_3;                       /* <25> */
    unsigned grp151_reserved_4;                       /* <26> */
    unsigned grp151_reserved_5;                       /* <27> */
    unsigned grp151_reserved_6;                       /* <28> */
    unsigned grp151_reserved_7;                       /* <29> */
    unsigned grp151_reserved_8;                       /* <30> */
    unsigned grp151_reserved_9;                       /* <31> */
    // GROUP 152
    unsigned grp152_reserved[32];
    // GROUP 153
    unsigned grp153_reserved[32];
    // GROUP 154
    unsigned grp154_reserved[32];
    // GROUP 155
    unsigned grp155_reserved[32];
    // GROUP 156
    unsigned grp156_reserved[32];
    // GROUP 157
    unsigned grp157_reserved[32];
    // GROUP 158
    unsigned grp158_reserved[32];
    // GROUP 159
    unsigned grp159_reserved[32];
    // GROUP 160
    unsigned grp160_reserved[32];
    // GROUP 161
    unsigned grp161_reserved[32];
    // GROUP 162
    unsigned grp162_reserved[32];
    // GROUP 163
    unsigned grp163_reserved[32];
    // GROUP 164
    unsigned grp164_reserved[32];
    // GROUP 165 [vip_gp]
    unsigned vip_gp_src_fmt;                          /* < 0> [dv:        0x1] [des: ] */
    unsigned vip_gp_pol_lace_field;                   /* < 1> [dv:       0x55] [des: ] */
    unsigned vip_gp_cs_edg_ref;                       /* < 2> [dv:        0x0] [des: ] */
    unsigned vip_gp_sog_hs_sel_reshp;                 /* < 3> [dv:        0x0] [des: ] */
    unsigned vip_gp_yuv_chg_f_inv;                    /* < 4> [dv:        0x0] [des: ] */
    unsigned vip_gp_iclk_tune_inv;                    /* < 5> [dv:        0x0] [des: ] */
    unsigned vip_gp_hs_vs_tune;                       /* < 6> [dv:        0x1] [des: ] */
    unsigned vip_gp_sync_status;                      /* < 7> [dv:           ] [des: ] */
    unsigned vip_gp_option0;                          /* < 8> [dv:        0x0] [des: ] */
    unsigned vip_gp_dat_align;                        /* < 9> [dv:       0x24] [des: ] */
    unsigned vip_gp_dat_tune;                         /* <10> [dv:        0x0] [des: ] */
    unsigned vip_gp_dither1;                          /* <11> [dv:       0x20] [des: ] */
    unsigned vip_gp_8b_sta_lb;                        /* <12> [dv:        0x0] [des: ] */
    unsigned vip_gp_8b_sta_hb;                        /* <13> [dv:        0x0] [des: ] */
    unsigned vip_gp_dither2;                          /* <14> [dv:        0x0] [des: ] */
    unsigned vip_gp_undither;                         /* <15> [dv:        0x0] [des: ] */
    unsigned vip_gp_hs_freq;                          /* <16> [dv:           ] [des: ] */
    unsigned grp165_reserved_0;                       /* <17> */
    unsigned vip_gp_vs_freq;                          /* <18> [dv:           ] [des: ] */
    unsigned grp165_reserved_1;                       /* <19> */
    unsigned vip_gp_htotal;                           /* <20> [dv:           ] [des: ] */
    unsigned grp165_reserved_2;                       /* <21> */
    unsigned vip_gp_hvalid;                           /* <22> [dv:           ] [des: ] */
    unsigned grp165_reserved_3;                       /* <23> */
    unsigned vip_gp_vtotal;                           /* <24> [dv:           ] [des: ] */
    unsigned grp165_reserved_4;                       /* <25> */
    unsigned vip_gp_vstart;                           /* <26> [dv:           ] [des: ] */
    unsigned grp165_reserved_5;                       /* <27> */
    unsigned vip_gp_vvalid;                           /* <28> [dv:           ] [des: ] */
    unsigned grp165_reserved_6;                       /* <29> */
    unsigned vip_gp_hstart_rpt;                       /* <30> [dv:           ] [des: ] */
    unsigned grp165_reserved_7;                       /* <31> */
    // GROUP 166 [vip_gp_crop_win]
    unsigned vip_gp_h_sta;                            /* < 0> [dv:       0xC9] [des: ] */
    unsigned grp166_reserved_0;                       /* < 1> */
    unsigned vip_gp_h_valid;                          /* < 2> [dv:      0x27F] [des: ] */
    unsigned grp166_reserved_1;                       /* < 3> */
    unsigned vip_gp_v_sta;                            /* < 4> [dv:       0x27] [des: ] */
    unsigned grp166_reserved_2;                       /* < 5> */
    unsigned vip_gp_vvld;                             /* < 6> [dv:      0x1DF] [des: ] */
    unsigned grp166_reserved_3;                       /* < 7> */
    unsigned vip_gp_dca_rpt_sel;                      /* < 8> [dv:        0x0] [des: ] */
    unsigned vip_gp_dca_rpt;                          /* < 9> [dv:           ] [des: ] */
    unsigned grp166_reserved_4;                       /* <10> */
    unsigned vip_gp_dca_param_sel;                    /* <11> [dv:        0x0] [des: ] */
    unsigned vip_gp_dca_param;                        /* <12> [dv:        0x0] [des: ] */
    unsigned grp166_reserved_5;                       /* <13> */
    unsigned vip_gp_syncp_ctrl;                       /* <14> [dv:        0x0] [des: ] */
    unsigned vip_gp_sts_load;                         /* <15> [dv:        0x0] [des: ] */
    unsigned vip_gp_hs_chg_th_l;                      /* <16> [dv:       0x10] [des: ] */
    unsigned vip_gp_vs_chg_th_l;                      /* <17> [dv:        0x4] [des: ] */
    unsigned vip_gp_hvs_chg_th_h;                     /* <18> [dv:        0x0] [des: ] */
    unsigned vip_gp_vsta_msk_th;                      /* <19> [dv:       0x00] [des: ] */
    unsigned vip_gp_hs_chg_cnt_th;                    /* <20> [dv:        0x1] [des: ] */
    unsigned vip_gp_hs_pres_th;                       /* <21> [dv:       0xf0] [des: ] */
    unsigned vip_gp_vs_pres_th;                       /* <22> [dv:       0x80] [des: ] */
    unsigned vip_gp_vcnt_th_l;                        /* <23> [dv:        0x0] [des: ] */
    unsigned vip_gp_vcnt_th_h;                        /* <24> [dv:        0x0] [des: ] */
    unsigned vip_gp_fld_det_win;                      /* <25> [dv:       0x6E] [des: ] */
    unsigned vip_gp_freq_det;                         /* <26> [dv:       0x40] [des: ] */
    unsigned vip_gp_pat_en;                           /* <27> [dv:        0x0] [des: ] */
    unsigned vip_gp_pat_param;                        /* <28> [dv:        0x0] [des: ] */
    unsigned vip_gp_auto_rpt0;                        /* <29> [dv:           ] [des: ] */
    unsigned vip_gp_auto_rpt1;                        /* <30> [dv:           ] [des: ] */
    unsigned vip_gp_auto_rpt2;                        /* <31> [dv:           ] [des: ] */
    // GROUP 167 [vip_gp_auto_cali]
    unsigned vip_gp_auto_rpt3;                        /* < 0> [dv:           ] [des: ] */
    unsigned vip_gp_auto_rpt4;                        /* < 1> [dv:           ] [des: ] */
    unsigned vip_gp_auto_rpt5;                        /* < 2> [dv:           ] [des: ] */
    unsigned vip_gp_auto_rpt6;                        /* < 3> [dv:           ] [des: ] */
    unsigned vip_gp_auto_rpt7;                        /* < 4> [dv:           ] [des: ] */
    unsigned vip_gp_auto_ctrl;                        /* < 5> [dv:        0x0] [des: ] */
    unsigned grp167_reserved_0;                       /* < 6> */
    unsigned grp167_reserved_1;                       /* < 7> */
    unsigned grp167_reserved_2;                       /* < 8> */
    unsigned grp167_reserved_3;                       /* < 9> */
    unsigned grp167_reserved_4;                       /* <10> */
    unsigned grp167_reserved_5;                       /* <11> */
    unsigned grp167_reserved_6;                       /* <12> */
    unsigned grp167_reserved_7;                       /* <13> */
    unsigned grp167_reserved_8;                       /* <14> */
    unsigned grp167_reserved_9;                       /* <15> */
    unsigned grp167_reserved_10;                      /* <16> */
    unsigned grp167_reserved_11;                      /* <17> */
    unsigned grp167_reserved_12;                      /* <18> */
    unsigned grp167_reserved_13;                      /* <19> */
    unsigned grp167_reserved_14;                      /* <20> */
    unsigned grp167_reserved_15;                      /* <21> */
    unsigned grp167_reserved_16;                      /* <22> */
    unsigned grp167_reserved_17;                      /* <23> */
    unsigned vip_gp_grab_hpos_l;                      /* <24> [dv:        0x0] [des: ] */
    unsigned vip_gp_grab_vpos_l;                      /* <25> [dv:        0x0] [des: ] */
    unsigned vip_gp_grab_hvpos_h;                     /* <26> [dv:        0x0] [des: ] */
    unsigned vip_gp_grab_addr;                        /* <27> [dv:        0x0] [des: ] */
    unsigned vip_gp_int_mask1;                        /* <28> [dv:       0xFF] [des: ] */
    unsigned vip_gp_int_mask2;                        /* <29> [dv:       0x1F] [des: ] */
    unsigned vip_gp_int_sts1;                         /* <30> [dv:        0x0] [des: ] */
    unsigned vip_gp_int_sts2;                         /* <31> [dv:        0x0] [des: ] */
    // GROUP 168 [vip_gp]
    unsigned vip_gp_buf_ctrl;                         /* < 0> [dv:        0x0] [des: ] */
    unsigned vip_gp_sd_ctrl;                          /* < 1> [dv:        0x0] [des: ] */
    unsigned vip_gp_hsd_adv_mode;                     /* < 2> [dv:       0x02] [des: ] */
    unsigned vip_gp_vs_fld_sts;                       /* < 3> [dv:           ] [des: ] */
    unsigned vip_gp_hsdf_l;                           /* < 4> [dv:        0x0] [des: ] */
    unsigned vip_gp_hsdf_m;                           /* < 5> [dv:        0x0] [des: ] */
    unsigned vip_gp_hsdf_h;                           /* < 6> [dv:        0x0] [des: ] */
    unsigned vip_gp_vsdf_l;                           /* < 7> [dv:        0x0] [des: ] */
    unsigned vip_gp_vsdf_h;                           /* < 8> [dv:        0x0] [des: ] */
    unsigned vip_gp_clamp_ctrl;                       /* < 9> [dv:        0x0] [des: ] */
    unsigned vip_gp_clamp_param;                      /* <10> [dv:        0x0] [des: ] */
    unsigned vip_gp_cal_opt0;                         /* <11> [dv:        0x0] [des: ] */
    unsigned vip_gp_cal_opt1;                         /* <12> [dv:        0x0] [des: ] */
    unsigned vip_gp_cal_opt2;                         /* <13> [dv:        0x0] [des: ] */
    unsigned vip_gp_hfreq_th_l;                       /* <14> [dv:        0x0] [des: ] */
    unsigned vip_gp_hfreq_th_h;                       /* <15> [dv:        0x0] [des: ] */
    unsigned vip_bc_sd_ctrl;                          /* <16> [dv:        0x2] [des: ] */
    unsigned vip_bc_buf_ptr_rst;                      /* <17> [dv:        0x0] [des: ] */
    unsigned vip_bc_buf_init_ptr;                     /* <18> [dv:        0x0] [des: ] */
    unsigned vip_bc_tab_dat_h;                        /* <19> [dv:        0x0] [des: ] */
    unsigned vip_bc_tab_dat_m;                        /* <20> [dv:        0x0] [des: ] */
    unsigned vip_bc_tab_dat_l;                        /* <21> [dv:        0x0] [des: ] */
    unsigned grp168_reserved_0;                       /* <22> */
    unsigned grp168_reserved_1;                       /* <23> */
    unsigned grp168_reserved_2;                       /* <24> */
    unsigned grp168_reserved_3;                       /* <25> */
    unsigned grp168_reserved_4;                       /* <26> */
    unsigned grp168_reserved_5;                       /* <27> */
    unsigned grp168_reserved_6;                       /* <28> */
    unsigned grp168_reserved_7;                       /* <29> */
    unsigned vip_bc_tab_dat_ext;                      /* <30> [dv:        0x0] [des: ] */
    unsigned grp168_reserved_8;                       /* <31> */
    // GROUP 169 [vip_gp]
    unsigned vip_gp_y_cnt_0;                          /* < 0> [dv:           ] [des: ] */
    unsigned grp169_reserved_0;                       /* < 1> */
    unsigned vip_gp_y_cnt_1;                          /* < 2> [dv:           ] [des: ] */
    unsigned grp169_reserved_1;                       /* < 3> */
    unsigned vip_gp_y_cnt_2;                          /* < 4> [dv:           ] [des: ] */
    unsigned grp169_reserved_2;                       /* < 5> */
    unsigned vip_gp_y_cnt_3;                          /* < 6> [dv:           ] [des: ] */
    unsigned grp169_reserved_3;                       /* < 7> */
    unsigned vip_gp_y_cnt_4;                          /* < 8> [dv:           ] [des: ] */
    unsigned grp169_reserved_4;                       /* < 9> */
    unsigned vip_gp_y_cnt_5;                          /* <10> [dv:           ] [des: ] */
    unsigned grp169_reserved_5;                       /* <11> */
    unsigned vip_gp_y_cnt_6;                          /* <12> [dv:           ] [des: ] */
    unsigned grp169_reserved_6;                       /* <13> */
    unsigned vip_gp_y_cnt_7;                          /* <14> [dv:           ] [des: ] */
    unsigned grp169_reserved_7;                       /* <15> */
    unsigned vip_gp_y_cnt_8;                          /* <16> [dv:           ] [des: ] */
    unsigned grp169_reserved_8;                       /* <17> */
    unsigned vip_gp_y_cnt_9;                          /* <18> [dv:           ] [des: ] */
    unsigned grp169_reserved_9;                       /* <19> */
    unsigned vip_gp_y_cnt_a;                          /* <20> [dv:           ] [des: ] */
    unsigned grp169_reserved_10;                      /* <21> */
    unsigned vip_gp_y_cnt_b;                          /* <22> [dv:           ] [des: ] */
    unsigned grp169_reserved_11;                      /* <23> */
    unsigned vip_gp_y_cnt_c;                          /* <24> [dv:           ] [des: ] */
    unsigned grp169_reserved_12;                      /* <25> */
    unsigned vip_gp_y_cnt_d;                          /* <26> [dv:           ] [des: ] */
    unsigned grp169_reserved_13;                      /* <27> */
    unsigned vip_gp_y_cnt_e;                          /* <28> [dv:           ] [des: ] */
    unsigned grp169_reserved_14;                      /* <29> */
    unsigned vip_gp_y_cnt_f;                          /* <30> [dv:           ] [des: ] */
    unsigned grp169_reserved_15;                      /* <31> */
    // GROUP 170 [vip_gp]
    unsigned vip_gp_his_vt_bdr;                       /* < 0> [dv:        0x0] [des: ] */
    unsigned vip_gp_his_vb_bdr;                       /* < 1> [dv:        0x0] [des: ] */
    unsigned vip_gp_his_hl_bdr;                       /* < 2> [dv:        0x0] [des: ] */
    unsigned vip_gp_his_hr_bdr;                       /* < 3> [dv:        0x0] [des: ] */
    unsigned grp170_reserved_0;                       /* < 4> */
    unsigned grp170_reserved_1;                       /* < 5> */
    unsigned grp170_reserved_2;                       /* < 6> */
    unsigned grp170_reserved_3;                       /* < 7> */
    unsigned grp170_reserved_4;                       /* < 8> */
    unsigned grp170_reserved_5;                       /* < 9> */
    unsigned grp170_reserved_6;                       /* <10> */
    unsigned grp170_reserved_7;                       /* <11> */
    unsigned grp170_reserved_8;                       /* <12> */
    unsigned grp170_reserved_9;                       /* <13> */
    unsigned grp170_reserved_10;                      /* <14> */
    unsigned grp170_reserved_11;                      /* <15> */
    unsigned grp170_reserved_12;                      /* <16> */
    unsigned grp170_reserved_13;                      /* <17> */
    unsigned grp170_reserved_14;                      /* <18> */
    unsigned vip_gp_flm32_ctrl1;                      /* <19> [dv:        0x4] [des: ] */
    unsigned vip_gp_flm32_ctrl2;                      /* <20> [dv:       0x36] [des: ] */
    unsigned vip_gp_flm32_hsta;                       /* <21> [dv:        0x0] [des: ] */
    unsigned vip_gp_flm32_hvld;                       /* <22> [dv:       0x5A] [des: ] */
    unsigned vip_gp_flm32_vsta;                       /* <23> [dv:        0x0] [des: ] */
    unsigned vip_gp_flm32_vvld;                       /* <24> [dv:       0x3C] [des: ] */
    unsigned vip_gp_flm32_mp_cg;                      /* <25> [dv:       0x55] [des: ] */
    unsigned vip_gp_flm32_mp_cth1;                    /* <26> [dv:       0x30] [des: ] */
    unsigned vip_gp_flm32_mp_cth2;                    /* <27> [dv:       0x30] [des: ] */
    unsigned vip_gp_flm32_mp_cth;                     /* <28> [dv:       0x02] [des: ] */
    unsigned vip_gp_flm32_mve_cth;                    /* <29> [dv:       0x02] [des: ] */
    unsigned vip_gp_flm32_err_mp_th;                  /* <30> [dv:       0x20] [des: ] */
    unsigned vip_gp_flm32_mp_diff_th;                 /* <31> [dv:       0x4E] [des: ] */
    // GROUP 171 [vip_gp_flm32]
    unsigned vip_gp_flm32_move_th;                    /* < 0> [dv:       0x20] [des: ] */
    unsigned grp171_reserved_0;                       /* < 1> */
    unsigned grp171_reserved_1;                       /* < 2> */
    unsigned grp171_reserved_2;                       /* < 3> */
    unsigned grp171_reserved_3;                       /* < 4> */
    unsigned vip_gp_flm32_sts;                        /* < 5> [dv:           ] [des: ] */
    unsigned vip_gp_656_hsta_rpt;                     /* < 6> [dv:           ] [des: ] */
    unsigned grp171_reserved_4;                       /* < 7> */
    unsigned vip_gp_656_hvld_rpt;                     /* < 8> [dv:           ] [des: ] */
    unsigned vip_gp_h_flip;                           /* < 9> [dv:       0x10] [des: ] */
    unsigned grp171_reserved_5;                       /* <10> */
    unsigned grp171_reserved_6;                       /* <11> */
    unsigned grp171_reserved_7;                       /* <12> */
    unsigned grp171_reserved_8;                       /* <13> */
    unsigned vip_gp_pxl_ofst;                         /* <14> [dv:        0x0] [des: ] */
    unsigned vip_gp_lne_ofst;                         /* <15> [dv:        0x0] [des: ] */
    unsigned vip_gp_bist1;                            /* <16> [dv:           ] [des: ] */
    unsigned vip_gp_bist2;                            /* <17> [dv:           ] [des: ] */
    unsigned vip_gp_bist3;                            /* <18> [dv:           ] [des: ] */
    unsigned vip_gp_hs_act;                           /* <19> [dv:           ] [des: ] */
    unsigned vip_gp_vs_act;                           /* <20> [dv:           ] [des: ] */
    unsigned vip_gp_dat_ofst_en;                      /* <21> [dv:        0x0] [des: ] */
    unsigned vip_gp_dat_ofst_lb;                      /* <22> [dv:        0x0] [des: ] */
    unsigned vip_gp_dat_ofst_mb;                      /* <23> [dv:        0x0] [des: ] */
    unsigned vip_gp_dat_ofst_hb;                      /* <24> [dv:        0x0] [des: ] */
    unsigned vip_gp_vs_fp;                            /* <25> [dv:        0x0] [des: ] */
    unsigned vip_gp_vs_rpt_th;                        /* <26> [dv:      0x3FF] [des: ] */
    unsigned grp171_reserved_9;                       /* <27> */
    unsigned grp171_reserved_10;                      /* <28> */
    unsigned grp171_reserved_11;                      /* <29> */
    unsigned grp171_reserved_12;                      /* <30> */
    unsigned grp171_reserved_13;                      /* <31> */
    // GROUP 172 [vip_gp]
    unsigned grp172_reserved_0;                       /* < 0> */
    unsigned grp172_reserved_1;                       /* < 1> */
    unsigned grp172_reserved_2;                       /* < 2> */
    unsigned grp172_reserved_3;                       /* < 3> */
    unsigned grp172_reserved_4;                       /* < 4> */
    unsigned vip_gp_vtot_rpt_th;                      /* < 5> [dv:        0x0] [des: ] */
    unsigned grp172_reserved_5;                       /* < 6> */
    unsigned vip_gp_mpc_0;                            /* < 7> [dv:        0x0] [des: ] */
    unsigned vip_gp_mpc_1;                            /* < 8> [dv:        0x0] [des: ] */
    unsigned vip_gp_mpc_2;                            /* < 9> [dv:        0x0] [des: ] */
    unsigned vip_gp_lpf_coef0;                        /* <10> [dv:        0x0] [des: ] */
    unsigned vip_gp_lpf_coef1;                        /* <11> [dv:        0x0] [des: ] */
    unsigned vip_gp_lpf_coef2;                        /* <12> [dv:        0x0] [des: ] */
    unsigned vip_gp_hsca_ini_l;                       /* <13> [dv:        0x0] [des: ] */
    unsigned vip_gp_hsca_ini_m;                       /* <14> [dv:        0x0] [des: ] */
    unsigned vip_gp_hsca_ini_h;                       /* <15> [dv:       0x20] [des: ] */
    unsigned grp172_reserved_6;                       /* <16> */
    unsigned grp172_reserved_7;                       /* <17> */
    unsigned grp172_reserved_8;                       /* <18> */
    unsigned grp172_reserved_9;                       /* <19> */
    unsigned grp172_reserved_10;                      /* <20> */
    unsigned grp172_reserved_11;                      /* <21> */
    unsigned grp172_reserved_12;                      /* <22> */
    unsigned grp172_reserved_13;                      /* <23> */
    unsigned grp172_reserved_14;                      /* <24> */
    unsigned grp172_reserved_15;                      /* <25> */
    unsigned grp172_reserved_16;                      /* <26> */
    unsigned vip_gp_v2h_rpt;                          /* <27> [dv:           ] [des: ] */
    unsigned vip_gp_clk_perious;                      /* <28> [dv:           ] [des: ] */
    unsigned vip_gp_clk_inv_each;                     /* <29> [dv:        0x0] [des: ] */
    unsigned vip_gp_output_sel;                       /* <30> [dv:        0x0] [des: ] */
    unsigned grp172_reserved_17;                      /* <31> */
    // GROUP 173 [vip_gp]
    unsigned vip_gp_src_fmt_1;                        /* < 0> [dv:        0x1] [des: ] */
    unsigned vip_gp_pol_lace_field_1;                 /* < 1> [dv:       0x55] [des: ] */
    unsigned vip_gp_cs_edg_ref_1;                     /* < 2> [dv:        0x0] [des: ] */
    unsigned vip_gp_sog_hs_sel_reshp_1;               /* < 3> [dv:        0x0] [des: ] */
    unsigned vip_gp_yuv_chg_f_inv_1;                  /* < 4> [dv:        0x0] [des: ] */
    unsigned vip_gp_iclk_tune_inv_1;                  /* < 5> [dv:        0x0] [des: ] */
    unsigned vip_gp_hs_vs_tune_1;                     /* < 6> [dv:        0x1] [des: ] */
    unsigned vip_gp_sync_status_1;                    /* < 7> [dv:           ] [des: ] */
    unsigned vip_gp_option0_1;                        /* < 8> [dv:        0x0] [des: ] */
    unsigned vip_gp_dat_align_1;                      /* < 9> [dv:       0x24] [des: ] */
    unsigned vip_gp_dat_tune_1;                       /* <10> [dv:        0x0] [des: ] */
    unsigned vip_gp_dither1_1;                        /* <11> [dv:       0x20] [des: ] */
    unsigned vip_gp_8b_sta_lb_1;                      /* <12> [dv:        0x0] [des: ] */
    unsigned vip_gp_8b_sta_hb_1;                      /* <13> [dv:        0x0] [des: ] */
    unsigned vip_gp_dither2_1;                        /* <14> [dv:        0x0] [des: ] */
    unsigned vip_gp_undither_1;                       /* <15> [dv:        0x0] [des: ] */
    unsigned vip_gp_hs_freq_1;                        /* <16> [dv:           ] [des: ] */
    unsigned grp173_reserved_0;                       /* <17> */
    unsigned vip_gp_vs_freq_1;                        /* <18> [dv:           ] [des: ] */
    unsigned grp173_reserved_1;                       /* <19> */
    unsigned vip_gp_htotal_1;                         /* <20> [dv:           ] [des: ] */
    unsigned grp173_reserved_2;                       /* <21> */
    unsigned vip_gp_hvalid_1;                         /* <22> [dv:           ] [des: ] */
    unsigned grp173_reserved_3;                       /* <23> */
    unsigned vip_gp_vtotal_1;                         /* <24> [dv:           ] [des: ] */
    unsigned grp173_reserved_4;                       /* <25> */
    unsigned vip_gp_vstart_1;                         /* <26> [dv:           ] [des: ] */
    unsigned grp173_reserved_5;                       /* <27> */
    unsigned vip_gp_vvalid_1;                         /* <28> [dv:           ] [des: ] */
    unsigned grp173_reserved_6;                       /* <29> */
    unsigned vip_gp_hstart_rpt_1;                     /* <30> [dv:           ] [des: ] */
    unsigned grp173_reserved_7;                       /* <31> */
    // GROUP 174 [vip_gp_crop_win]
    unsigned vip_gp_h_sta_1;                          /* < 0> [dv:       0xC9] [des: ] */
    unsigned grp174_reserved_0;                       /* < 1> */
    unsigned vip_gp_h_valid_1;                        /* < 2> [dv:      0x27F] [des: ] */
    unsigned grp174_reserved_1;                       /* < 3> */
    unsigned vip_gp_v_sta_1;                          /* < 4> [dv:       0x27] [des: ] */
    unsigned grp174_reserved_2;                       /* < 5> */
    unsigned vip_gp_vvld_1;                           /* < 6> [dv:      0x1DF] [des: ] */
    unsigned grp174_reserved_3;                       /* < 7> */
    unsigned vip_gp_dca_rpt_sel_1;                    /* < 8> [dv:        0x0] [des: ] */
    unsigned vip_gp_dca_rpt_1;                        /* < 9> [dv:           ] [des: ] */
    unsigned grp174_reserved_4;                       /* <10> */
    unsigned vip_gp_dca_param_sel_1;                  /* <11> [dv:        0x0] [des: ] */
    unsigned vip_gp_dca_param_1;                      /* <12> [dv:        0x0] [des: ] */
    unsigned grp174_reserved_5;                       /* <13> */
    unsigned vip_gp_syncp_ctrl_1;                     /* <14> [dv:        0x0] [des: ] */
    unsigned vip_gp_sts_load_1;                       /* <15> [dv:        0x0] [des: ] */
    unsigned vip_gp_hs_chg_th_l_1;                    /* <16> [dv:       0x10] [des: ] */
    unsigned vip_gp_vs_chg_th_l_1;                    /* <17> [dv:        0x4] [des: ] */
    unsigned vip_gp_hvs_chg_th_h_1;                   /* <18> [dv:        0x0] [des: ] */
    unsigned vip_gp_vsta_msk_th_1;                    /* <19> [dv:       0x00] [des: ] */
    unsigned vip_gp_hs_chg_cnt_th_1;                  /* <20> [dv:        0x1] [des: ] */
    unsigned vip_gp_hs_pres_th_1;                     /* <21> [dv:       0xf0] [des: ] */
    unsigned vip_gp_vs_pres_th_1;                     /* <22> [dv:       0x80] [des: ] */
    unsigned vip_gp_vcnt_th_l_1;                      /* <23> [dv:        0x0] [des: ] */
    unsigned vip_gp_vcnt_th_h_1;                      /* <24> [dv:        0x0] [des: ] */
    unsigned vip_gp_fld_det_win_1;                    /* <25> [dv:       0x6E] [des: ] */
    unsigned vip_gp_freq_det_1;                       /* <26> [dv:       0x40] [des: ] */
    unsigned vip_gp_pat_en_1;                         /* <27> [dv:        0x0] [des: ] */
    unsigned vip_gp_pat_param_1;                      /* <28> [dv:        0x0] [des: ] */
    unsigned vip_gp_auto_rpt0_1;                      /* <29> [dv:           ] [des: ] */
    unsigned vip_gp_auto_rpt1_1;                      /* <30> [dv:           ] [des: ] */
    unsigned vip_gp_auto_rpt2_1;                      /* <31> [dv:           ] [des: ] */
    // GROUP 175 [vip_gp_auto_cali]
    unsigned vip_gp_auto_rpt3_1;                      /* < 0> [dv:           ] [des: ] */
    unsigned vip_gp_auto_rpt4_1;                      /* < 1> [dv:           ] [des: ] */
    unsigned vip_gp_auto_rpt5_1;                      /* < 2> [dv:           ] [des: ] */
    unsigned vip_gp_auto_rpt6_1;                      /* < 3> [dv:           ] [des: ] */
    unsigned vip_gp_auto_rpt7_1;                      /* < 4> [dv:           ] [des: ] */
    unsigned vip_gp_auto_ctrl_1;                      /* < 5> [dv:        0x0] [des: ] */
    unsigned grp175_reserved_0;                       /* < 6> */
    unsigned grp175_reserved_1;                       /* < 7> */
    unsigned grp175_reserved_2;                       /* < 8> */
    unsigned grp175_reserved_3;                       /* < 9> */
    unsigned grp175_reserved_4;                       /* <10> */
    unsigned grp175_reserved_5;                       /* <11> */
    unsigned grp175_reserved_6;                       /* <12> */
    unsigned grp175_reserved_7;                       /* <13> */
    unsigned grp175_reserved_8;                       /* <14> */
    unsigned grp175_reserved_9;                       /* <15> */
    unsigned grp175_reserved_10;                      /* <16> */
    unsigned grp175_reserved_11;                      /* <17> */
    unsigned grp175_reserved_12;                      /* <18> */
    unsigned grp175_reserved_13;                      /* <19> */
    unsigned grp175_reserved_14;                      /* <20> */
    unsigned grp175_reserved_15;                      /* <21> */
    unsigned grp175_reserved_16;                      /* <22> */
    unsigned grp175_reserved_17;                      /* <23> */
    unsigned vip_gp_grab_hpos_l_1;                    /* <24> [dv:        0x0] [des: ] */
    unsigned vip_gp_grab_vpos_l_1;                    /* <25> [dv:        0x0] [des: ] */
    unsigned vip_gp_grab_hvpos_h_1;                   /* <26> [dv:        0x0] [des: ] */
    unsigned vip_gp_grab_addr_1;                      /* <27> [dv:        0x0] [des: ] */
    unsigned vip_gp_int_mask1_1;                      /* <28> [dv:       0xFF] [des: ] */
    unsigned vip_gp_int_mask2_1;                      /* <29> [dv:       0x1F] [des: ] */
    unsigned vip_gp_int_sts1_1;                       /* <30> [dv:        0x0] [des: ] */
    unsigned vip_gp_int_sts2_1;                       /* <31> [dv:        0x0] [des: ] */
    // GROUP 176 [vip_gp]
    unsigned vip_gp_buf_ctrl_1;                       /* < 0> [dv:        0x0] [des: ] */
    unsigned vip_gp_sd_ctrl_1;                        /* < 1> [dv:        0x0] [des: ] */
    unsigned vip_gp_hsd_adv_mode_1;                   /* < 2> [dv:       0x02] [des: ] */
    unsigned vip_gp_vs_fld_sts_1;                     /* < 3> [dv:           ] [des: ] */
    unsigned vip_gp_hsdf_l_1;                         /* < 4> [dv:        0x0] [des: ] */
    unsigned vip_gp_hsdf_m_1;                         /* < 5> [dv:        0x0] [des: ] */
    unsigned vip_gp_hsdf_h_1;                         /* < 6> [dv:        0x0] [des: ] */
    unsigned vip_gp_vsdf_l_1;                         /* < 7> [dv:        0x0] [des: ] */
    unsigned vip_gp_vsdf_h_1;                         /* < 8> [dv:        0x0] [des: ] */
    unsigned vip_gp_clamp_ctrl_1;                     /* < 9> [dv:        0x0] [des: ] */
    unsigned vip_gp_clamp_param_1;                    /* <10> [dv:        0x0] [des: ] */
    unsigned vip_gp_cal_opt0_1;                       /* <11> [dv:        0x0] [des: ] */
    unsigned vip_gp_cal_opt1_1;                       /* <12> [dv:        0x0] [des: ] */
    unsigned vip_gp_cal_opt2_1;                       /* <13> [dv:        0x0] [des: ] */
    unsigned vip_gp_hfreq_th_l_1;                     /* <14> [dv:        0x0] [des: ] */
    unsigned vip_gp_hfreq_th_h_1;                     /* <15> [dv:        0x0] [des: ] */
    unsigned vip_bc_sd_ctrl_1;                        /* <16> [dv:        0x2] [des: ] */
    unsigned vip_bc_buf_ptr_rst_1;                    /* <17> [dv:        0x0] [des: ] */
    unsigned vip_bc_buf_init_ptr_1;                   /* <18> [dv:        0x0] [des: ] */
    unsigned vip_bc_tab_dat_h_1;                      /* <19> [dv:        0x0] [des: ] */
    unsigned vip_bc_tab_dat_m_1;                      /* <20> [dv:        0x0] [des: ] */
    unsigned vip_bc_tab_dat_l_1;                      /* <21> [dv:        0x0] [des: ] */
    unsigned grp176_reserved_0;                       /* <22> */
    unsigned grp176_reserved_1;                       /* <23> */
    unsigned grp176_reserved_2;                       /* <24> */
    unsigned grp176_reserved_3;                       /* <25> */
    unsigned grp176_reserved_4;                       /* <26> */
    unsigned grp176_reserved_5;                       /* <27> */
    unsigned grp176_reserved_6;                       /* <28> */
    unsigned grp176_reserved_7;                       /* <29> */
    unsigned vip_bc_tab_dat_ext_1;                    /* <30> [dv:        0x0] [des: ] */
    unsigned grp176_reserved_8;                       /* <31> */
    // GROUP 177 [vip_gp]
    unsigned vip_gp_y_cnt_0_1;                        /* < 0> [dv:           ] [des: ] */
    unsigned grp177_reserved_0;                       /* < 1> */
    unsigned vip_gp_y_cnt_1_1;                        /* < 2> [dv:           ] [des: ] */
    unsigned grp177_reserved_1;                       /* < 3> */
    unsigned vip_gp_y_cnt_2_1;                        /* < 4> [dv:           ] [des: ] */
    unsigned grp177_reserved_2;                       /* < 5> */
    unsigned vip_gp_y_cnt_3_1;                        /* < 6> [dv:           ] [des: ] */
    unsigned grp177_reserved_3;                       /* < 7> */
    unsigned vip_gp_y_cnt_4_1;                        /* < 8> [dv:           ] [des: ] */
    unsigned grp177_reserved_4;                       /* < 9> */
    unsigned vip_gp_y_cnt_5_1;                        /* <10> [dv:           ] [des: ] */
    unsigned grp177_reserved_5;                       /* <11> */
    unsigned vip_gp_y_cnt_6_1;                        /* <12> [dv:           ] [des: ] */
    unsigned grp177_reserved_6;                       /* <13> */
    unsigned vip_gp_y_cnt_7_1;                        /* <14> [dv:           ] [des: ] */
    unsigned grp177_reserved_7;                       /* <15> */
    unsigned vip_gp_y_cnt_8_1;                        /* <16> [dv:           ] [des: ] */
    unsigned grp177_reserved_8;                       /* <17> */
    unsigned vip_gp_y_cnt_9_1;                        /* <18> [dv:           ] [des: ] */
    unsigned grp177_reserved_9;                       /* <19> */
    unsigned vip_gp_y_cnt_a_1;                        /* <20> [dv:           ] [des: ] */
    unsigned grp177_reserved_10;                      /* <21> */
    unsigned vip_gp_y_cnt_b_1;                        /* <22> [dv:           ] [des: ] */
    unsigned grp177_reserved_11;                      /* <23> */
    unsigned vip_gp_y_cnt_c_1;                        /* <24> [dv:           ] [des: ] */
    unsigned grp177_reserved_12;                      /* <25> */
    unsigned vip_gp_y_cnt_d_1;                        /* <26> [dv:           ] [des: ] */
    unsigned grp177_reserved_13;                      /* <27> */
    unsigned vip_gp_y_cnt_e_1;                        /* <28> [dv:           ] [des: ] */
    unsigned grp177_reserved_14;                      /* <29> */
    unsigned vip_gp_y_cnt_f_1;                        /* <30> [dv:           ] [des: ] */
    unsigned grp177_reserved_15;                      /* <31> */
    // GROUP 178 [vip_gp]
    unsigned vip_gp_his_vt_bdr_1;                     /* < 0> [dv:        0x0] [des: ] */
    unsigned vip_gp_his_vb_bdr_1;                     /* < 1> [dv:        0x0] [des: ] */
    unsigned vip_gp_his_hl_bdr_1;                     /* < 2> [dv:        0x0] [des: ] */
    unsigned vip_gp_his_hr_bdr_1;                     /* < 3> [dv:        0x0] [des: ] */
    unsigned grp178_reserved_0;                       /* < 4> */
    unsigned grp178_reserved_1;                       /* < 5> */
    unsigned grp178_reserved_2;                       /* < 6> */
    unsigned grp178_reserved_3;                       /* < 7> */
    unsigned grp178_reserved_4;                       /* < 8> */
    unsigned grp178_reserved_5;                       /* < 9> */
    unsigned grp178_reserved_6;                       /* <10> */
    unsigned grp178_reserved_7;                       /* <11> */
    unsigned grp178_reserved_8;                       /* <12> */
    unsigned grp178_reserved_9;                       /* <13> */
    unsigned grp178_reserved_10;                      /* <14> */
    unsigned grp178_reserved_11;                      /* <15> */
    unsigned grp178_reserved_12;                      /* <16> */
    unsigned grp178_reserved_13;                      /* <17> */
    unsigned grp178_reserved_14;                      /* <18> */
    unsigned vip_gp_flm32_ctrl1_1;                    /* <19> [dv:        0x4] [des: ] */
    unsigned vip_gp_flm32_ctrl2_1;                    /* <20> [dv:       0x36] [des: ] */
    unsigned vip_gp_flm32_hsta_1;                     /* <21> [dv:        0x0] [des: ] */
    unsigned vip_gp_flm32_hvld_1;                     /* <22> [dv:       0x5A] [des: ] */
    unsigned vip_gp_flm32_vsta_1;                     /* <23> [dv:        0x0] [des: ] */
    unsigned vip_gp_flm32_vvld_1;                     /* <24> [dv:       0x3C] [des: ] */
    unsigned vip_gp_flm32_mp_cg_1;                    /* <25> [dv:       0x55] [des: ] */
    unsigned vip_gp_flm32_mp_cth1_1;                  /* <26> [dv:       0x30] [des: ] */
    unsigned vip_gp_flm32_mp_cth2_1;                  /* <27> [dv:       0x30] [des: ] */
    unsigned vip_gp_flm32_mp_cth_1;                   /* <28> [dv:       0x02] [des: ] */
    unsigned vip_gp_flm32_mve_cth_1;                  /* <29> [dv:       0x02] [des: ] */
    unsigned vip_gp_flm32_err_mp_th_1;                /* <30> [dv:       0x20] [des: ] */
    unsigned vip_gp_flm32_mp_diff_th_1;               /* <31> [dv:       0x4E] [des: ] */
    // GROUP 179 [vip_gp_flm32]
    unsigned vip_gp_flm32_move_th_1;                  /* < 0> [dv:       0x20] [des: ] */
    unsigned grp179_reserved_0;                       /* < 1> */
    unsigned grp179_reserved_1;                       /* < 2> */
    unsigned grp179_reserved_2;                       /* < 3> */
    unsigned grp179_reserved_3;                       /* < 4> */
    unsigned vip_gp_flm32_sts_1;                      /* < 5> [dv:           ] [des: ] */
    unsigned vip_gp_656_hsta_rpt_1;                   /* < 6> [dv:           ] [des: ] */
    unsigned grp179_reserved_4;                       /* < 7> */
    unsigned vip_gp_656_hvld_rpt_1;                   /* < 8> [dv:           ] [des: ] */
    unsigned vip_gp_h_flip_1;                         /* < 9> [dv:       0x10] [des: ] */
    unsigned grp179_reserved_5;                       /* <10> */
    unsigned grp179_reserved_6;                       /* <11> */
    unsigned grp179_reserved_7;                       /* <12> */
    unsigned grp179_reserved_8;                       /* <13> */
    unsigned vip_gp_pxl_ofst_1;                       /* <14> [dv:        0x0] [des: ] */
    unsigned vip_gp_lne_ofst_1;                       /* <15> [dv:        0x0] [des: ] */
    unsigned vip_gp_bist1_1;                          /* <16> [dv:           ] [des: ] */
    unsigned vip_gp_bist2_1;                          /* <17> [dv:           ] [des: ] */
    unsigned vip_gp_bist3_1;                          /* <18> [dv:           ] [des: ] */
    unsigned vip_gp_hs_act_1;                         /* <19> [dv:           ] [des: ] */
    unsigned vip_gp_vs_act_1;                         /* <20> [dv:           ] [des: ] */
    unsigned vip_gp_dat_ofst_en_1;                    /* <21> [dv:        0x0] [des: ] */
    unsigned vip_gp_dat_ofst_lb_1;                    /* <22> [dv:        0x0] [des: ] */
    unsigned vip_gp_dat_ofst_mb_1;                    /* <23> [dv:        0x0] [des: ] */
    unsigned vip_gp_dat_ofst_hb_1;                    /* <24> [dv:        0x0] [des: ] */
    unsigned vip_gp_vs_fp_1;                          /* <25> [dv:        0x0] [des: ] */
    unsigned vip_gp_vs_rpt_th_1;                      /* <26> [dv:      0x3FF] [des: ] */
    unsigned grp179_reserved_9;                       /* <27> */
    unsigned grp179_reserved_10;                      /* <28> */
    unsigned grp179_reserved_11;                      /* <29> */
    unsigned grp179_reserved_12;                      /* <30> */
    unsigned grp179_reserved_13;                      /* <31> */
    // GROUP 180 [vip_gp]
    unsigned grp180_reserved_0;                       /* < 0> */
    unsigned grp180_reserved_1;                       /* < 1> */
    unsigned grp180_reserved_2;                       /* < 2> */
    unsigned grp180_reserved_3;                       /* < 3> */
    unsigned grp180_reserved_4;                       /* < 4> */
    unsigned vip_gp_vtot_rpt_th_1;                    /* < 5> [dv:        0x0] [des: ] */
    unsigned grp180_reserved_5;                       /* < 6> */
    unsigned vip_gp_mpc_0_1;                          /* < 7> [dv:        0x0] [des: ] */
    unsigned vip_gp_mpc_1_1;                          /* < 8> [dv:        0x0] [des: ] */
    unsigned vip_gp_mpc_2_1;                          /* < 9> [dv:        0x0] [des: ] */
    unsigned vip_gp_lpf_coef0_1;                      /* <10> [dv:        0x0] [des: ] */
    unsigned vip_gp_lpf_coef1_1;                      /* <11> [dv:        0x0] [des: ] */
    unsigned vip_gp_lpf_coef2_1;                      /* <12> [dv:        0x0] [des: ] */
    unsigned vip_gp_hsca_ini_l_1;                     /* <13> [dv:        0x0] [des: ] */
    unsigned vip_gp_hsca_ini_m_1;                     /* <14> [dv:        0x0] [des: ] */
    unsigned vip_gp_hsca_ini_h_1;                     /* <15> [dv:       0x20] [des: ] */
    unsigned grp180_reserved_6;                       /* <16> */
    unsigned grp180_reserved_7;                       /* <17> */
    unsigned grp180_reserved_8;                       /* <18> */
    unsigned grp180_reserved_9;                       /* <19> */
    unsigned grp180_reserved_10;                      /* <20> */
    unsigned grp180_reserved_11;                      /* <21> */
    unsigned grp180_reserved_12;                      /* <22> */
    unsigned grp180_reserved_13;                      /* <23> */
    unsigned grp180_reserved_14;                      /* <24> */
    unsigned grp180_reserved_15;                      /* <25> */
    unsigned grp180_reserved_16;                      /* <26> */
    unsigned vip_gp_v2h_rpt_1;                        /* <27> [dv:           ] [des: ] */
    unsigned vip_gp_clk_perious_1;                    /* <28> [dv:           ] [des: ] */
    unsigned vip_gp_clk_inv_each_1;                   /* <29> [dv:        0x0] [des: ] */
    unsigned grp180_reserved_17;                      /* <30> */
    unsigned grp180_reserved_18;                      /* <31> */
    // GROUP 181
    unsigned grp181_reserved[32];
    // GROUP 182
    unsigned grp182_reserved[32];
    // GROUP 183
    unsigned grp183_reserved[32];
    // GROUP 184
    unsigned grp184_reserved[32];
    // GROUP 185 [deinterlace_data_fetch_0_ddfch0]
    unsigned ddfch0_latch_en;                         /* < 0> [dv:     0x0001] [des: ddfch latch enable] */
    unsigned ddfch0_mode_option;                      /* < 1> [dv:    0x5e000] [des: mode option] */
    unsigned ddfch0_enable;                           /* < 2> [dv:     0x00e0] [des: ddfch enable] */
    unsigned ddfch0_urgent_thd;                       /* < 3> [dv:   0xd6d6d6] [des: ddfch mbus urgent threshold] */
    unsigned ddfch0_cmdq_thd;                         /* < 4> [dv:     0x3def] [des: ddfch mbus command queue threshold] */
    unsigned ddfch0_mr_base_addr;                     /* < 5> [dv:     0x0000] [des: motion base address] */
    unsigned ddfch0_luma_base_addr_0;                 /* < 6> [dv:     0x0000] [des: luma/yuy2 base addr for frame_0] */
    unsigned ddfch0_luma_base_addr_1;                 /* < 7> [dv:     0x0000] [des: luma/yuy2 base addr for frame_1] */
    unsigned ddfch0_luma_base_addr_2;                 /* < 8> [dv:     0x0000] [des: luma/yuy2 base addr for frame_2] */
    unsigned ddfch0_crma_base_addr_0;                 /* < 9> [dv:     0x0000] [des: chroma base addr for frame_0] */
    unsigned ddfch0_crma_base_addr_1;                 /* <10> [dv:     0x0000] [des: chroma base addr for frame_1] */
    unsigned ddfch0_crma_base_addr_2;                 /* <11> [dv:     0x0000] [des: chroma base addr for frame_2] */
    unsigned reserved_0_29;                           /* <12> [dv:     0x0000] [des: ] */
    unsigned reserved_1_25;                           /* <13> [dv:     0x0000] [des: ] */
    unsigned reserved_2_22;                           /* <14> [dv:     0x0000] [des: ] */
    unsigned reserved_3_21;                           /* <15> [dv:     0x0000] [des: ] */
    unsigned reserved_4_19;                           /* <16> [dv:     0x0000] [des: ] */
    unsigned ddfch0_mr_frame_size;                    /* <17> [dv:     0x0000] [des: line pitch of source in motion frame buffer] */
    unsigned ddfch0_mr_crop_size;                     /* <18> [dv:     0x0000] [des: motion write/read user mode crop size] */
    unsigned ddfch0_mr_crop_offset;                   /* <19> [dv:     0x0000] [des: motion write/read user mode crop offset] */
    unsigned ddfch0_vdo_frame_size;                   /* <20> [dv:     0x0000] [des: line pitch of source in video frame buffer ] */
    unsigned ddfch0_vdo_crop_size;                    /* <21> [dv:     0x0000] [des: video crop size] */
    unsigned ddfch0_vdo_crop_offset;                  /* <22> [dv:     0x0000] [des: video crop offset] */
    unsigned ddfch0_config_0;                         /* <23> [dv:     0x0000] [des: video side band signal config] */
    unsigned ddfch0_config_1;                         /* <24> [dv:     0x0000] [des: range mapping config] */
    unsigned ddfch0_checksum_sel;                     /* <25> [dv:     0x0000] [des: check sum select] */
    unsigned ddfch0_chksum_info;                      /* <26> [dv:     0x0000] [des: check sum] */
    unsigned ddfch0_error_flag_info;                  /* <27> [dv:     0x0000] [des: ddfch error flag] */
    unsigned ddfch0_bist;                             /* <28> [dv:     0x0000] [des: ddfch bist mode and output 422 YCbCr by configuration] */
    unsigned ddfch0_mbus_info_pre;                    /* <29> [dv:     0x0000] [des: previous dfch mbus info (reserved in 8388) ] */
    unsigned ddfch0_mbus_info_nxt;                    /* <30> [dv:     0x0000] [des: next dfch mbus info (reserved in 8388) ] */
    unsigned ddfch0_mbus_info_cur;                    /* <31> [dv:     0x0000] [des: current dfch mbus info (reserved in 8388) ] */
    // GROUP 186 [deinterlace_data_fetch_1_ddfch1]
    unsigned ddfch1_latch_en;                         /* < 0> [dv:     0x0001] [des: ddfch latch enable] */
    unsigned ddfch1_mode_option;                      /* < 1> [dv:    0x5e000] [des: mode option] */
    unsigned ddfch1_enable;                           /* < 2> [dv:     0x00e0] [des: ddfch enable] */
    unsigned ddfch1_urgent_thd;                       /* < 3> [dv:   0xd6d6d6] [des: ddfch mbus urgent threshold] */
    unsigned ddfch1_cmdq_thd;                         /* < 4> [dv:     0x3def] [des: ddfch mbus command queue threshold] */
    unsigned ddfch1_mr_base_addr;                     /* < 5> [dv:     0x0000] [des: motion base address] */
    unsigned ddfch1_luma_base_addr_0;                 /* < 6> [dv:     0x0000] [des: luma/yuy2 base addr for frame_0] */
    unsigned ddfch1_luma_base_addr_1;                 /* < 7> [dv:     0x0000] [des: luma/yuy2 base addr for frame_1] */
    unsigned ddfch1_luma_base_addr_2;                 /* < 8> [dv:     0x0000] [des: luma/yuy2 base addr for frame_2] */
    unsigned ddfch1_crma_base_addr_0;                 /* < 9> [dv:     0x0000] [des: chroma base addr for frame_0] */
    unsigned ddfch1_crma_base_addr_1;                 /* <10> [dv:     0x0000] [des: chroma base addr for frame_1] */
    unsigned ddfch1_crma_base_addr_2;                 /* <11> [dv:     0x0000] [des: chroma base addr for frame_2] */
    unsigned reserved_0_30;                           /* <12> [dv:     0x0000] [des: ] */
    unsigned reserved_1_26;                           /* <13> [dv:     0x0000] [des: ] */
    unsigned reserved_2_23;                           /* <14> [dv:     0x0000] [des: ] */
    unsigned reserved_3_22;                           /* <15> [dv:     0x0000] [des: ] */
    unsigned reserved_4_20;                           /* <16> [dv:     0x0000] [des: ] */
    unsigned ddfch1_mr_frame_size;                    /* <17> [dv:     0x0000] [des: line pitch of source in motion frame buffer] */
    unsigned ddfch1_mr_crop_size;                     /* <18> [dv:     0x0000] [des: motion write/read user mode crop size] */
    unsigned ddfch1_mr_crop_offset;                   /* <19> [dv:     0x0000] [des: motion write/read user mode crop offset] */
    unsigned ddfch1_vdo_frame_size;                   /* <20> [dv:     0x0000] [des: line pitch of source in video frame buffer ] */
    unsigned ddfch1_vdo_crop_size;                    /* <21> [dv:     0x0000] [des: video crop size] */
    unsigned ddfch1_vdo_crop_offset;                  /* <22> [dv:     0x0000] [des: video crop offset] */
    unsigned ddfch1_config_0;                         /* <23> [dv:     0x0000] [des: video side band signal config] */
    unsigned ddfch1_config_1;                         /* <24> [dv:     0x0000] [des: range mapping config] */
    unsigned ddfch1_checksum_sel;                     /* <25> [dv:     0x0000] [des: check sum select] */
    unsigned ddfch1_chksum_info;                      /* <26> [dv:     0x0000] [des: check sum] */
    unsigned ddfch1_error_flag_info;                  /* <27> [dv:     0x0000] [des: ddfch error flag] */
    unsigned ddfch1_bist;                             /* <28> [dv:     0x0000] [des: ddfch bist mode and output 422 YCbCr by configuration] */
    unsigned ddfch1_mbus_info_pre;                    /* <29> [dv:     0x0000] [des: previous dfch mbus info (reserved in 8388) ] */
    unsigned ddfch1_mbus_info_nxt;                    /* <30> [dv:     0x0000] [des: next dfch mbus info (reserved in 8388) ] */
    unsigned ddfch1_mbus_info_cur;                    /* <31> [dv:     0x0000] [des: current dfch mbus info (reserved in 8388) ] */
    // GROUP 187 [deint0_deinterlacing]
    unsigned deint_param_1;                           /* < 0> [dv:     0x0000] [des: Deinterlacing Parameter 1] */
    unsigned deint_cnt_y_his_r;                       /* < 1> [dv:     0x0000] [des: Deint Input His_r Counter] */
    unsigned deint_gclk_param_1;                      /* < 2> [dv:     0x0000] [des: Gated Clock Parameter 1] */
    unsigned deint_gclk_param_2;                      /* < 3> [dv:     0x0000] [des: Gated Clock Parameter 2] */
    unsigned deint_checksum;                          /* < 4> [dv:     0x0000] [des: Deint Check Sum Register] */
    unsigned deint_cnt_y_pre;                         /* < 5> [dv:     0x0000] [des: Deint Input Pre Counter] */
    unsigned deint_cnt_y_cur;                         /* < 6> [dv:     0x0000] [des: Deint Input Cur Counter] */
    unsigned deint_cnt_y_nxt;                         /* < 7> [dv:     0x0000] [des: Deint Input Nxt Counter] */
    unsigned deint_scene_change_param_1;              /* < 8> [dv:     0x0000] [des: Scene Change Parameter 1] */
    unsigned deint_scene_change_param_2;              /* < 9> [dv:     0x0000] [des: Scene Change Parameter 2] */
    unsigned deint_cnt_y_his_w;                       /* <10> [dv:     0x0000] [des: Deint Input His_w Counter] */
    unsigned deint_pulldown22_param_1;                /* <11> [dv:     0x0000] [des: PullDown22 Parameter 1] */
    unsigned deint_pulldown22_param_2;                /* <12> [dv:     0x0000] [des: PullDown22 Parameter 2] */
    unsigned deint_pulldown22_param_3;                /* <13> [dv:     0x0000] [des: PullDown22 Parameter 3] */
    unsigned deint_pulldown22_param_4;                /* <14> [dv:     0x0000] [des: PullDown22 Parameter 4] */
    unsigned deint_pulldown22_param_5;                /* <15> [dv:     0x0000] [des: PullDown22 Parameter 5] */
    unsigned deint_pulldown22_param_6;                /* <16> [dv:     0x0000] [des: PullDown22 Parameter 6] */
    unsigned deint_pulldown22_param_7;                /* <17> [dv:     0x0000] [des: PullDown22 Parameter 7] */
    unsigned deint_pulldown22_param_8;                /* <18> [dv:     0x0000] [des: PullDown22 Parameter 8] */
    unsigned deint_x_size;                            /* <19> [dv:     0x0000] [des: Deint Output Width] */
    unsigned deint_pulldown32_param_1;                /* <20> [dv:     0x0000] [des: PullDown32 Parameter 1] */
    unsigned deint_pulldown32_param_2;                /* <21> [dv:     0x0000] [des: PullDown32 Parameter 2] */
    unsigned deint_pulldown32_param_3;                /* <22> [dv:     0x0000] [des: PullDown32 Parameter 3] */
    unsigned deint_pulldown32_param_4;                /* <23> [dv:     0x0000] [des: PullDown32 Parameter 4] */
    unsigned deint_pulldown32_param_5;                /* <24> [dv:     0x0000] [des: PullDown32 Parameter 5] */
    unsigned deint_pulldown32_param_6;                /* <25> [dv:     0x0000] [des: PullDown32 Parameter 6] */
    unsigned deint_pulldown32_param_7;                /* <26> [dv:     0x0000] [des: PullDown32 Parameter 7] */
    unsigned deint_pulldown32_param_8;                /* <27> [dv:     0x0000] [des: PullDown32 Parameter 8] */
    unsigned deint_y_size;                            /* <28> [dv:     0x0000] [des: Deint Output Height] */
    unsigned deint_bad_edit_param_1;                  /* <29> [dv:     0x0000] [des: Bad Edition Parameter 1] */
    unsigned deint_bad_edit_param_2;                  /* <30> [dv:     0x0000] [des: Bad Edition Parameter 2] */
    unsigned deint_bad_edit_param_3;                  /* <31> [dv:     0x0000] [des: Bad Edition Parameter 3] */
    // GROUP 188 [deint0_deinterlacing]
    unsigned deint_decision_param_1;                  /* < 0> [dv:     0x0000] [des: Decision Parameter 1] */
    unsigned deint_decision_param_2;                  /* < 1> [dv:     0x0000] [des: Decision Parameter 2] */
    unsigned deint_decision_param_3;                  /* < 2> [dv:     0x0000] [des: Decision Parameter 3] */
    unsigned deint_decision_param_4;                  /* < 3> [dv:     0x0000] [des: Decision Parameter 4] */
    unsigned deint_decision_param_5;                  /* < 4> [dv:     0x0000] [des: Decision Parameter 5] */
    unsigned deint_decision_param_6;                  /* < 5> [dv:     0x0000] [des: Decision Parameter 6] */
    unsigned deint_decision_param_7;                  /* < 6> [dv:     0x0000] [des: Decision Parameter 7] */
    unsigned deint_decision_param_8;                  /* < 7> [dv:     0x0000] [des: Decision Parameter 8] */
    unsigned deint_decision_param_9;                  /* < 8> [dv:     0x0000] [des: Decision Parameter 9] */
    unsigned deint_decision_param_a;                  /* < 9> [dv:     0x0000] [des: Decision Parameter A] */
    unsigned deint_decision_param_b;                  /* <10> [dv:     0x0000] [des: Decision Parameter B] */
    unsigned deint_val_field_luma_l;                  /* <11> [dv:     0x0000] [des: Field luma sum low bit] */
    unsigned deint_val_field_luma_h;                  /* <12> [dv:     0x0000] [des: Field luma sum high bit] */
    unsigned deint_intra_param_1;                     /* <13> [dv:     0x0000] [des: Intra Parameter 1] */
    unsigned deint_intra_param_2;                     /* <14> [dv:     0x0000] [des: Intra Parameter 2] */
    unsigned deint_intra_param_3;                     /* <15> [dv:     0x0000] [des: Intra Parameter 3] */
    unsigned deint_intra_param_4;                     /* <16> [dv:     0x0000] [des: Intra Parameter 4] */
    unsigned deint_intra_param_5;                     /* <17> [dv:     0x0000] [des: Intra Parameter 5] */
    unsigned deint_intra_param_6;                     /* <18> [dv:     0x0000] [des: Intra Parameter 6] */
    unsigned deint_intra_param_7;                     /* <19> [dv:     0x0000] [des: Intra Parameter 7] */
    unsigned deint_intra_param_8;                     /* <20> [dv:     0x0000] [des: Intra Parameter 8] */
    unsigned deint_read_cnt_y;                        /* <21> [dv:     0x0000] [des: Deint Output Read Counter] */
    unsigned deint_inter_param_1;                     /* <22> [dv:     0x0000] [des: Inter Parameter 1] */
    unsigned deint_mixing_param_1;                    /* <23> [dv:     0x0000] [des: Mixing Parameter 1] */
    unsigned deint_val_22_sawtooth;                   /* <24> [dv:     0x0000] [des: Value of PullDown22] */
    unsigned deint_val_32_motion;                     /* <25> [dv:     0x0000] [des: Value of PullDown32] */
    unsigned deint_val_be_tmp;                        /* <26> [dv:     0x0000] [des: Temproal Value of Bad Edition] */
    unsigned deint_val_be_spt;                        /* <27> [dv:     0x0000] [des: Spatial Value of Bad Edition] */
    unsigned deint_val_be_mix;                        /* <28> [dv:     0x0000] [des: Mixing Value of Bad Edition] */
    unsigned deint_val_be_info1;                      /* <29> [dv:     0x0000] [des: Information of Bad Edition] */
    unsigned deint_val_be_info2;                      /* <30> [dv:     0x0000] [des: Information of Bad Edition] */
    unsigned deint_val_scene_change;                  /* <31> [dv:     0x0000] [des: Value of Scene Change] */
    // GROUP 189 [deint1_deinterlacing]
    unsigned deint_param_1_1;                         /* < 0> [dv:     0x0000] [des: Deinterlacing Parameter 1] */
    unsigned deint_cnt_y_his_r_1;                     /* < 1> [dv:     0x0000] [des: Deint Input His_r Counter] */
    unsigned deint_gclk_param_1_1;                    /* < 2> [dv:     0x0000] [des: Gated Clock Parameter 1] */
    unsigned deint_gclk_param_2_1;                    /* < 3> [dv:     0x0000] [des: Gated Clock Parameter 2] */
    unsigned deint_checksum_1;                        /* < 4> [dv:     0x0000] [des: Deint Check Sum Register] */
    unsigned deint_cnt_y_pre_1;                       /* < 5> [dv:     0x0000] [des: Deint Input Pre Counter] */
    unsigned deint_cnt_y_cur_1;                       /* < 6> [dv:     0x0000] [des: Deint Input Cur Counter] */
    unsigned deint_cnt_y_nxt_1;                       /* < 7> [dv:     0x0000] [des: Deint Input Nxt Counter] */
    unsigned deint_scene_change_param_1_1;            /* < 8> [dv:     0x0000] [des: Scene Change Parameter 1] */
    unsigned deint_scene_change_param_2_1;            /* < 9> [dv:     0x0000] [des: Scene Change Parameter 2] */
    unsigned deint_cnt_y_his_w_1;                     /* <10> [dv:     0x0000] [des: Deint Input His_w Counter] */
    unsigned deint_pulldown22_param_1_1;              /* <11> [dv:     0x0000] [des: PullDown22 Parameter 1] */
    unsigned deint_pulldown22_param_2_1;              /* <12> [dv:     0x0000] [des: PullDown22 Parameter 2] */
    unsigned deint_pulldown22_param_3_1;              /* <13> [dv:     0x0000] [des: PullDown22 Parameter 3] */
    unsigned deint_pulldown22_param_4_1;              /* <14> [dv:     0x0000] [des: PullDown22 Parameter 4] */
    unsigned deint_pulldown22_param_5_1;              /* <15> [dv:     0x0000] [des: PullDown22 Parameter 5] */
    unsigned deint_pulldown22_param_6_1;              /* <16> [dv:     0x0000] [des: PullDown22 Parameter 6] */
    unsigned deint_pulldown22_param_7_1;              /* <17> [dv:     0x0000] [des: PullDown22 Parameter 7] */
    unsigned deint_pulldown22_param_8_1;              /* <18> [dv:     0x0000] [des: PullDown22 Parameter 8] */
    unsigned deint_x_size_1;                          /* <19> [dv:     0x0000] [des: Deint Output Width] */
    unsigned deint_pulldown32_param_1_1;              /* <20> [dv:     0x0000] [des: PullDown32 Parameter 1] */
    unsigned deint_pulldown32_param_2_1;              /* <21> [dv:     0x0000] [des: PullDown32 Parameter 2] */
    unsigned deint_pulldown32_param_3_1;              /* <22> [dv:     0x0000] [des: PullDown32 Parameter 3] */
    unsigned deint_pulldown32_param_4_1;              /* <23> [dv:     0x0000] [des: PullDown32 Parameter 4] */
    unsigned deint_pulldown32_param_5_1;              /* <24> [dv:     0x0000] [des: PullDown32 Parameter 5] */
    unsigned deint_pulldown32_param_6_1;              /* <25> [dv:     0x0000] [des: PullDown32 Parameter 6] */
    unsigned deint_pulldown32_param_7_1;              /* <26> [dv:     0x0000] [des: PullDown32 Parameter 7] */
    unsigned deint_pulldown32_param_8_1;              /* <27> [dv:     0x0000] [des: PullDown32 Parameter 8] */
    unsigned deint_y_size_1;                          /* <28> [dv:     0x0000] [des: Deint Output Height] */
    unsigned deint_bad_edit_param_1_1;                /* <29> [dv:     0x0000] [des: Bad Edition Parameter 1] */
    unsigned deint_bad_edit_param_2_1;                /* <30> [dv:     0x0000] [des: Bad Edition Parameter 2] */
    unsigned deint_bad_edit_param_3_1;                /* <31> [dv:     0x0000] [des: Bad Edition Parameter 3] */
    // GROUP 190 [deint1_deinterlacing]
    unsigned deint_decision_param_1_1;                /* < 0> [dv:     0x0000] [des: Decision Parameter 1] */
    unsigned deint_decision_param_2_1;                /* < 1> [dv:     0x0000] [des: Decision Parameter 2] */
    unsigned deint_decision_param_3_1;                /* < 2> [dv:     0x0000] [des: Decision Parameter 3] */
    unsigned deint_decision_param_4_1;                /* < 3> [dv:     0x0000] [des: Decision Parameter 4] */
    unsigned deint_decision_param_5_1;                /* < 4> [dv:     0x0000] [des: Decision Parameter 5] */
    unsigned deint_decision_param_6_1;                /* < 5> [dv:     0x0000] [des: Decision Parameter 6] */
    unsigned deint_decision_param_7_1;                /* < 6> [dv:     0x0000] [des: Decision Parameter 7] */
    unsigned deint_decision_param_8_1;                /* < 7> [dv:     0x0000] [des: Decision Parameter 8] */
    unsigned deint_decision_param_9_1;                /* < 8> [dv:     0x0000] [des: Decision Parameter 9] */
    unsigned deint_decision_param_a_1;                /* < 9> [dv:     0x0000] [des: Decision Parameter A] */
    unsigned deint_decision_param_b_1;                /* <10> [dv:     0x0000] [des: Decision Parameter B] */
    unsigned deint_val_field_luma_l_1;                /* <11> [dv:     0x0000] [des: Field luma sum low bit] */
    unsigned deint_val_field_luma_h_1;                /* <12> [dv:     0x0000] [des: Field luma sum high bit] */
    unsigned deint_intra_param_1_1;                   /* <13> [dv:     0x0000] [des: Intra Parameter 1] */
    unsigned deint_intra_param_2_1;                   /* <14> [dv:     0x0000] [des: Intra Parameter 2] */
    unsigned deint_intra_param_3_1;                   /* <15> [dv:     0x0000] [des: Intra Parameter 3] */
    unsigned deint_intra_param_4_1;                   /* <16> [dv:     0x0000] [des: Intra Parameter 4] */
    unsigned deint_intra_param_5_1;                   /* <17> [dv:     0x0000] [des: Intra Parameter 5] */
    unsigned deint_intra_param_6_1;                   /* <18> [dv:     0x0000] [des: Intra Parameter 6] */
    unsigned deint_intra_param_7_1;                   /* <19> [dv:     0x0000] [des: Intra Parameter 7] */
    unsigned deint_intra_param_8_1;                   /* <20> [dv:     0x0000] [des: Intra Parameter 8] */
    unsigned deint_read_cnt_y_1;                      /* <21> [dv:     0x0000] [des: Deint Output Read Counter] */
    unsigned deint_inter_param_1_1;                   /* <22> [dv:     0x0000] [des: Inter Parameter 1] */
    unsigned deint_mixing_param_1_1;                  /* <23> [dv:     0x0000] [des: Mixing Parameter 1] */
    unsigned deint_val_22_sawtooth_1;                 /* <24> [dv:     0x0000] [des: Value of PullDown22] */
    unsigned deint_val_32_motion_1;                   /* <25> [dv:     0x0000] [des: Value of PullDown32] */
    unsigned deint_val_be_tmp_1;                      /* <26> [dv:     0x0000] [des: Temproal Value of Bad Edition] */
    unsigned deint_val_be_spt_1;                      /* <27> [dv:     0x0000] [des: Spatial Value of Bad Edition] */
    unsigned deint_val_be_mix_1;                      /* <28> [dv:     0x0000] [des: Mixing Value of Bad Edition] */
    unsigned deint_val_be_info1_1;                    /* <29> [dv:     0x0000] [des: Information of Bad Edition] */
    unsigned deint_val_be_info2_1;                    /* <30> [dv:     0x0000] [des: Information of Bad Edition] */
    unsigned deint_val_scene_change_1;                /* <31> [dv:     0x0000] [des: Value of Scene Change] */
    // GROUP 191 [vscl0_g0_video_scaler_group_0]
    unsigned vscl0_config1;                           /* < 0> [dv:     0x0000] [des: VSCL0 Config1 Register] */
    unsigned vscl0_config2;                           /* < 1> [dv:     0x0000] [des: VSCL0 Config2 Register] */
    unsigned reserved_0_31;                           /* < 2> [dv:     0x0000] [des: reserved_2] */
    unsigned vscl0_actrl_i_xlen;                      /* < 3> [dv:     0x0000] [des: ACTRL Input Pixel Register] */
    unsigned vscl0_actrl_i_ylen;                      /* < 4> [dv:     0x0000] [des: ACTRL Input Line Register] */
    unsigned vscl0_actrl_s_xstart;                    /* < 5> [dv:     0x0000] [des: ACTRL start pixel of crop frame] */
    unsigned vscl0_actrl_s_ystart;                    /* < 6> [dv:     0x0000] [des: ACTRL start line of crop frame] */
    unsigned vscl0_actrl_s_xlen;                      /* < 7> [dv:     0x0000] [des: ACTRL Output Pixel Register] */
    unsigned vscl0_actrl_s_ylen;                      /* < 8> [dv:     0x0000] [des: ACTRL Output Line Register] */
    unsigned vscl0_dctrl_o_xlen;                      /* < 9> [dv:     0x0000] [des: DCTRL Output Active Pixel Register] */
    unsigned vscl0_dctrl_o_ylen;                      /* <10> [dv:     0x0000] [des: DCTRL Output Active Line Register] */
    unsigned vscl0_dctrl_d_xstart;                    /* <11> [dv:     0x0000] [des: DCTRL Output Active Start Pixel Register] */
    unsigned vscl0_dctrl_d_ystart;                    /* <12> [dv:     0x0000] [des: DCTRL Output Active Start Line Register] */
    unsigned vscl0_dctrl_d_xlen;                      /* <13> [dv:     0x0000] [des: DCTRL Input Pixel Register] */
    unsigned vscl0_dctrl_d_ylen;                      /* <14> [dv:     0x0000] [des: DCTRL Input Line Register] */
    unsigned vscl0_dctrl_bgc_c;                       /* <15> [dv:     0x8080] [des: DCTRL Background Color Chroma Register] */
    unsigned vscl0_dctrl_bgc_y;                       /* <16> [dv:     0x0010] [des: DCTRL Background Color Luma Register] */
    unsigned reserved_1_27;                           /* <17> [dv:     0x0000] [des: reserved_17] */
    unsigned vscl0_hint_ctrl;                         /* <18> [dv:     0x0000] [des: HINT Control Register] */
    unsigned vscl0_hint_hfactor_low;                  /* <19> [dv:     0x0000] [des: HINT Scaling Factor Low Register] */
    unsigned vscl0_hint_hfactor_high;                 /* <20> [dv:     0x0000] [des: HINT Scaling Factor High Register] */
    unsigned vscl0_hint_initf_low;                    /* <21> [dv:     0x0000] [des: HINT Initial Phase Low Register] */
    unsigned vscl0_hint_initf_high;                   /* <22> [dv:     0x0000] [des: HINT Initial Phase High Register] */
    unsigned reserved_2_24;                           /* <23> [dv:     0x0000] [des: Reserved_23] */
    unsigned reserved_3_23;                           /* <24> [dv:     0x0000] [des: Reserved_24] */
    unsigned vscl0_hint_overshoot;                    /* <25> [dv:     0x0000] [des: HINT Overshoot Register] */
    unsigned reserved_4_21;                           /* <26> [dv:     0x0000] [des: Reserved_26] */
    unsigned reserved_5_19;                           /* <27> [dv:     0x0000] [des: Reserved_27] */
    unsigned vscl0_sram_ctrl;                         /* <28> [dv:     0x0000] [des: SRAM Control Register] */
    unsigned vscl0_sram_addr;                         /* <29> [dv:     0x0000] [des: SRAM Address Register] */
    unsigned vscl0_sram_write_data;                   /* <30> [dv:     0x0000] [des: SRAM Write Data Register] */
    unsigned vscl0_sram_read_data;                    /* <31> [dv:     0x0000] [des: SRAM Read Data Register] */
    // GROUP 192 [vscl0_g1_video_scaler_group_1]
    unsigned vscl0_vint_ctrl;                         /* < 0> [dv:     0x0000] [des: VINT Control Register] */
    unsigned vscl0_vint_vfactor_low;                  /* < 1> [dv:     0x0000] [des: VINT Scaling Factor Low Register] */
    unsigned vscl0_vint_vfactor_high;                 /* < 2> [dv:     0x0000] [des: VINT Scaling Factor High Register] */
    unsigned vscl0_vint_initf_low;                    /* < 3> [dv:     0x0000] [des: VINT Initial Phase Low Register] */
    unsigned vscl0_vint_initf_high;                   /* < 4> [dv:     0x0000] [des: VINT Initial Phase High Register] */
    unsigned vscl0_dr_ctrl;                           /* < 5> [dv:     0x0000] [des: Dering control signal] */
    unsigned vscl0_dr_dege_detect1;                   /* < 6> [dv:     0x0000] [des: Dering edge detection relative] */
    unsigned vscl0_dr_dege_detect2;                   /* < 7> [dv:     0x0000] [des: Dering edge detection relative] */
    unsigned vscl0_dr_clamp_detect;                   /* < 8> [dv:     0x0000] [des: Dering clamp value relative] */
    unsigned vscl0_vimg_ctrl;                         /* < 9> [dv:     0x0000] [des: VSCL0 VIMG Control Register] */
    unsigned vscl0_vimg_vpeak_lut_1;                  /* <10> [dv:     0x0000] [des: VIMG VPEAK Gain LUT Register 1] */
    unsigned vscl0_vimg_vpeak_lut_2;                  /* <11> [dv:     0x0000] [des: VIMG VPEAK Gain LUT Register 2] */
    unsigned vscl0_vimg_vpeak_lut_3;                  /* <12> [dv:     0x0000] [des: VIMG VPEAK Gain LUT Register 3] */
    unsigned vscl0_vimg_vpeak_lut_4;                  /* <13> [dv:     0x0000] [des: VIMG VPEAK Gain LUT Register 4] */
    unsigned vscl0_vimg_vpeak_lut_5;                  /* <14> [dv:     0x0000] [des: VIMG VPEAK Gain LUT Register 5] */
    unsigned vscl0_vimg_vpeak_lut_6;                  /* <15> [dv:     0x0000] [des: VIMG VPEAK Gain LUT Register 6] */
    unsigned vscl0_vimg_vpeak_config;                 /* <16> [dv:     0x0000] [des: VIMG VPEAK Config Register] */
    unsigned vscl0_vimg_diag_config_1;                /* <17> [dv:     0x0000] [des: VIMG Diagonal Filter Config Register 1] */
    unsigned vscl0_vimg_diag_config_2;                /* <18> [dv:     0x0000] [des: VIMG Diagonal Filter Config Register 2] */
    unsigned reserved_0_32;                           /* <19> [dv:     0x0000] [des: Reserved_19] */
    unsigned reserved_1_28;                           /* <20> [dv:     0x0000] [des: Reserved_20] */
    unsigned vscl0_checksum_select;                   /* <21> [dv:     0x0000] [des: Checksum select Register] */
    unsigned vscl0_checksum_result;                   /* <22> [dv:     0x0000] [des: Checksum Rrsult Register] */
    unsigned grp192_reserved_0;                       /* <23> */
    unsigned grp192_reserved_1;                       /* <24> */
    unsigned grp192_reserved_2;                       /* <25> */
    unsigned grp192_reserved_3;                       /* <26> */
    unsigned grp192_reserved_4;                       /* <27> */
    unsigned grp192_reserved_5;                       /* <28> */
    unsigned grp192_reserved_6;                       /* <29> */
    unsigned grp192_reserved_7;                       /* <30> */
    unsigned grp192_reserved_8;                       /* <31> */
    // GROUP 193 [vscl1_g0_video_scaler_group_0]
    unsigned vscl1_config1;                           /* < 0> [dv:     0x0000] [des: VSCL1 Config1 Register] */
    unsigned vscl1_config2;                           /* < 1> [dv:     0x0000] [des: VSCL1 Config2 Register] */
    unsigned reserved_0_33;                           /* < 2> [dv:     0x0000] [des: reserved_2] */
    unsigned vscl1_actrl_i_xlen;                      /* < 3> [dv:     0x0000] [des: ACTRL Input Pixel Register] */
    unsigned vscl1_actrl_i_ylen;                      /* < 4> [dv:     0x0000] [des: ACTRL Input Line Register] */
    unsigned vscl1_actrl_s_xstart;                    /* < 5> [dv:     0x0000] [des: ACTRL start pixel of crop frame] */
    unsigned vscl1_actrl_s_ystart;                    /* < 6> [dv:     0x0000] [des: ACTRL start line of crop frame] */
    unsigned vscl1_actrl_s_xlen;                      /* < 7> [dv:     0x0000] [des: ACTRL Output Pixel Register] */
    unsigned vscl1_actrl_s_ylen;                      /* < 8> [dv:     0x0000] [des: ACTRL Output Line Register] */
    unsigned vscl1_dctrl_o_xlen;                      /* < 9> [dv:     0x0000] [des: DCTRL Output Active Pixel Register] */
    unsigned vscl1_dctrl_o_ylen;                      /* <10> [dv:     0x0000] [des: DCTRL Output Active Line Register] */
    unsigned vscl1_dctrl_d_xstart;                    /* <11> [dv:     0x0000] [des: DCTRL Output Active Start Pixel Register] */
    unsigned vscl1_dctrl_d_ystart;                    /* <12> [dv:     0x0000] [des: DCTRL Output Active Start Line Register] */
    unsigned vscl1_dctrl_d_xlen;                      /* <13> [dv:     0x0000] [des: DCTRL Input Pixel Register] */
    unsigned vscl1_dctrl_d_ylen;                      /* <14> [dv:     0x0000] [des: DCTRL Input Line Register] */
    unsigned vscl1_dctrl_bgc_c;                       /* <15> [dv:     0x8080] [des: DCTRL Background Color Chroma Register] */
    unsigned vscl1_dctrl_bgc_y;                       /* <16> [dv:     0x0010] [des: DCTRL Background Color Luma Register] */
    unsigned reserved_1_29;                           /* <17> [dv:     0x0000] [des: reserved_17] */
    unsigned vscl1_hint_ctrl;                         /* <18> [dv:     0x0000] [des: HINT Control Register] */
    unsigned vscl1_hint_hfactor_low;                  /* <19> [dv:     0x0000] [des: HINT Scaling Factor Low Register] */
    unsigned vscl1_hint_hfactor_high;                 /* <20> [dv:     0x0000] [des: HINT Scaling Factor High Register] */
    unsigned vscl1_hint_initf_low;                    /* <21> [dv:     0x0000] [des: HINT Initial Phase Low Register] */
    unsigned vscl1_hint_initf_high;                   /* <22> [dv:     0x0000] [des: HINT Initial Phase High Register] */
    unsigned reserved_2_25;                           /* <23> [dv:     0x0000] [des: Reserved_23] */
    unsigned reserved_3_24;                           /* <24> [dv:     0x0000] [des: Reserved_24] */
    unsigned vscl1_hint_overshoot;                    /* <25> [dv:     0x0000] [des: HINT Overshoot Register] */
    unsigned reserved_4_22;                           /* <26> [dv:     0x0000] [des: Reserved_26] */
    unsigned reserved_5_20;                           /* <27> [dv:     0x0000] [des: Reserved_27] */
    unsigned vscl1_sram_ctrl;                         /* <28> [dv:     0x0000] [des: SRAM Control Register] */
    unsigned vscl1_sram_addr;                         /* <29> [dv:     0x0000] [des: SRAM Address Register] */
    unsigned vscl1_sram_write_data;                   /* <30> [dv:     0x0000] [des: SRAM Write Data Register] */
    unsigned vscl1_sram_read_data;                    /* <31> [dv:     0x0000] [des: SRAM Read Data Register] */
    // GROUP 194 [vscl1_g1_video_scaler_group_1]
    unsigned vscl1_vint_ctrl;                         /* < 0> [dv:     0x0000] [des: VINT Control Register] */
    unsigned vscl1_vint_vfactor_low;                  /* < 1> [dv:     0x0000] [des: VINT Scaling Factor Low Register] */
    unsigned vscl1_vint_vfactor_high;                 /* < 2> [dv:     0x0000] [des: VINT Scaling Factor High Register] */
    unsigned vscl1_vint_initf_low;                    /* < 3> [dv:     0x0000] [des: VINT Initial Phase Low Register] */
    unsigned vscl1_vint_initf_high;                   /* < 4> [dv:     0x0000] [des: VINT Initial Phase High Register] */
    unsigned vscl1_dr_ctrl;                           /* < 5> [dv:     0x0000] [des: Dering control signal] */
    unsigned vscl1_dr_dege_detect1;                   /* < 6> [dv:     0x0000] [des: Dering edge detection relative] */
    unsigned vscl1_dr_dege_detect2;                   /* < 7> [dv:     0x0000] [des: Dering edge detection relative] */
    unsigned vscl1_dr_clamp_detect;                   /* < 8> [dv:     0x0000] [des: Dering clamp value relative] */
    unsigned vscl1_vimg_ctrl;                         /* < 9> [dv:     0x0000] [des: VSCL1 VIMG Control Register] */
    unsigned vscl1_vimg_vpeak_lut_1;                  /* <10> [dv:     0x0000] [des: VIMG VPEAK Gain LUT Register 1] */
    unsigned vscl1_vimg_vpeak_lut_2;                  /* <11> [dv:     0x0000] [des: VIMG VPEAK Gain LUT Register 2] */
    unsigned vscl1_vimg_vpeak_lut_3;                  /* <12> [dv:     0x0000] [des: VIMG VPEAK Gain LUT Register 3] */
    unsigned vscl1_vimg_vpeak_lut_4;                  /* <13> [dv:     0x0000] [des: VIMG VPEAK Gain LUT Register 4] */
    unsigned vscl1_vimg_vpeak_lut_5;                  /* <14> [dv:     0x0000] [des: VIMG VPEAK Gain LUT Register 5] */
    unsigned vscl1_vimg_vpeak_lut_6;                  /* <15> [dv:     0x0000] [des: VIMG VPEAK Gain LUT Register 6] */
    unsigned vscl1_vimg_vpeak_config;                 /* <16> [dv:     0x0000] [des: VIMG VPEAK Config Register] */
    unsigned vscl1_vimg_diag_config_1;                /* <17> [dv:     0x0000] [des: VIMG Diagonal Filter Config Register 1] */
    unsigned vscl1_vimg_diag_config_2;                /* <18> [dv:     0x0000] [des: VIMG Diagonal Filter Config Register 2] */
    unsigned reserved_0_34;                           /* <19> [dv:     0x0000] [des: Reserved_19] */
    unsigned reserved_1_30;                           /* <20> [dv:     0x0000] [des: Reserved_20] */
    unsigned vscl1_checksum_select;                   /* <21> [dv:     0x0000] [des: Checksum select Register] */
    unsigned vscl1_checksum_result;                   /* <22> [dv:     0x0000] [des: Checksum Rrsult Register] */
    unsigned grp194_reserved_0;                       /* <23> */
    unsigned grp194_reserved_1;                       /* <24> */
    unsigned grp194_reserved_2;                       /* <25> */
    unsigned grp194_reserved_3;                       /* <26> */
    unsigned grp194_reserved_4;                       /* <27> */
    unsigned grp194_reserved_5;                       /* <28> */
    unsigned grp194_reserved_6;                       /* <29> */
    unsigned grp194_reserved_7;                       /* <30> */
    unsigned grp194_reserved_8;                       /* <31> */
    // GROUP 195 [noise_reduction_nr0]
    unsigned nr0_en;                                  /* < 0> [dv:     0x0020] [des: NR config register] */
    unsigned nr0_deovs_win;                           /* < 1> [dv:     0x0000] [des: DEOVS windows configuration] */
    unsigned nr0_deovs_cor_th;                        /* < 2> [dv:     0x0000] [des: Coring threshold] */
    unsigned nr0_deovs_ring_edge_th;                  /* < 3> [dv:     0x0000] [des: Ringing and edge detection threshold] */
    unsigned nr0_deovs_ring_l01;                      /* < 4> [dv:     0x0000] [des: Edge level factor] */
    unsigned nr0_deovs_ring_l23;                      /* < 5> [dv:     0x0000] [des: Edge level factor] */
    unsigned nr0_deovs_fn_l0123;                      /* < 6> [dv:     0x0000] [des: Flattern factor] */
    unsigned nr0_dr_ctrl;                             /* < 7> [dv:     0x0000] [des: Deringing control signal] */
    unsigned nr0_dr_edge_det1;                        /* < 8> [dv:     0x0000] [des: Dering edge detection relative] */
    unsigned nr0_dr_edge_det2;                        /* < 9> [dv:     0x0000] [des: Dering edge detection relative] */
    unsigned nr0_dr_clamp_det;                        /* <10> [dv:     0x0000] [des: Dering clamp value relative] */
    unsigned nr0_dm_edge_det1;                        /* <11> [dv:     0x0000] [des: Demosq edge detection] */
    unsigned nr0_dm_edge_det2;                        /* <12> [dv:     0x0000] [des: Demosq edge detection] */
    unsigned nr0_dm_clamp_det1;                       /* <13> [dv:     0x0000] [des: Demosq limiter] */
    unsigned nr0_dm_clamp_det2;                       /* <14> [dv:     0x0000] [des: Demosq limiter] */
    unsigned nr0_snr_ctrl;                            /* <15> [dv:     0x0000] [des: SNR control signal] */
    unsigned nr0_snr_edge_det1;                       /* <16> [dv:     0x0000] [des: SNR edge detection] */
    unsigned nr0_snr_edge_det2;                       /* <17> [dv:     0x0000] [des: SNR edge detection] */
    unsigned nr0_snr_edge_det3;                       /* <18> [dv:     0x0000] [des: SNR edge detection] */
    unsigned nr0_snr_clamp_value;                     /* <19> [dv:     0x0000] [des: SNR clamp value] */
    unsigned nr0_snr_masnr_factor1;                   /* <20> [dv:     0x0000] [des: MASNR factor] */
    unsigned nr0_snr_masnr_factor2;                   /* <21> [dv:     0x0000] [des: MASNR factor] */
    unsigned nr0_pix_no;                              /* <22> [dv:     0x0000] [des: Frame width] */
    unsigned nr0_line_no;                             /* <23> [dv:     0x0000] [des: Frame height] */
    unsigned nr0_gated_ctrl;                          /* <24> [dv:     0x0000] [des: Gated clock control] */
    unsigned nr0_chksum_en;                           /* <25> [dv:     0x0000] [des: Check sum enable] */
    unsigned nr0_chksum_ans;                          /* <26> [dv:     0x0000] [des: Check sum result] */
    unsigned grp195_reserved_0;                       /* <27> */
    unsigned grp195_reserved_1;                       /* <28> */
    unsigned grp195_reserved_2;                       /* <29> */
    unsigned grp195_reserved_3;                       /* <30> */
    unsigned grp195_reserved_4;                       /* <31> */
    // GROUP 196 [noise_reduction_nr1]
    unsigned nr1_en;                                  /* < 0> [dv:     0x0020] [des: NR config register] */
    unsigned nr1_deovs_win;                           /* < 1> [dv:     0x0000] [des: DEOVS windows configuration] */
    unsigned nr1_deovs_cor_th;                        /* < 2> [dv:     0x0000] [des: Coring threshold] */
    unsigned nr1_deovs_ring_edge_th;                  /* < 3> [dv:     0x0000] [des: Ringing and edge detection threshold] */
    unsigned nr1_deovs_ring_l01;                      /* < 4> [dv:     0x0000] [des: Edge level factor] */
    unsigned nr1_deovs_ring_l23;                      /* < 5> [dv:     0x0000] [des: Edge level factor] */
    unsigned nr1_deovs_fn_l0123;                      /* < 6> [dv:     0x0000] [des: Flattern factor] */
    unsigned nr1_dr_ctrl;                             /* < 7> [dv:     0x0000] [des: Deringing control signal] */
    unsigned nr1_dr_edge_det1;                        /* < 8> [dv:     0x0000] [des: Dering edge detection relative] */
    unsigned nr1_dr_edge_det2;                        /* < 9> [dv:     0x0000] [des: Dering edge detection relative] */
    unsigned nr1_dr_clamp_det;                        /* <10> [dv:     0x0000] [des: Dering clamp value relative] */
    unsigned nr1_dm_edge_det1;                        /* <11> [dv:     0x0000] [des: Demosq edge detection] */
    unsigned nr1_dm_edge_det2;                        /* <12> [dv:     0x0000] [des: Demosq edge detection] */
    unsigned nr1_dm_clamp_det1;                       /* <13> [dv:     0x0000] [des: Demosq limiter] */
    unsigned nr1_dm_clamp_det2;                       /* <14> [dv:     0x0000] [des: Demosq limiter] */
    unsigned nr1_snr_ctrl;                            /* <15> [dv:     0x0000] [des: SNR control signal] */
    unsigned nr1_snr_edge_det1;                       /* <16> [dv:     0x0000] [des: SNR edge detection] */
    unsigned nr1_snr_edge_det2;                       /* <17> [dv:     0x0000] [des: SNR edge detection] */
    unsigned nr1_snr_edge_det3;                       /* <18> [dv:     0x0000] [des: SNR edge detection] */
    unsigned nr1_snr_clamp_value;                     /* <19> [dv:     0x0000] [des: SNR clamp value] */
    unsigned nr1_snr_masnr_factor1;                   /* <20> [dv:     0x0000] [des: MASNR factor] */
    unsigned nr1_snr_masnr_factor2;                   /* <21> [dv:     0x0000] [des: MASNR factor] */
    unsigned nr1_pix_no;                              /* <22> [dv:     0x0000] [des: Frame width] */
    unsigned nr1_line_no;                             /* <23> [dv:     0x0000] [des: Frame height] */
    unsigned nr1_gated_ctrl;                          /* <24> [dv:     0x0000] [des: Gated clock control] */
    unsigned nr1_chksum_en;                           /* <25> [dv:     0x0000] [des: Check sum enable] */
    unsigned nr1_chksum_ans;                          /* <26> [dv:     0x0000] [des: Check sum result] */
    unsigned grp196_reserved_0;                       /* <27> */
    unsigned grp196_reserved_1;                       /* <28> */
    unsigned grp196_reserved_2;                       /* <29> */
    unsigned grp196_reserved_3;                       /* <30> */
    unsigned grp196_reserved_4;                       /* <31> */
    // GROUP 197 [image_processing_img0]
    unsigned img0_config;                             /* < 0> [dv:     0x0001] [des: IMG config register] */
    unsigned img0_pkti_ctrl;                          /* < 1> [dv:     0x0000] [des: PKTI Control Register] */
    unsigned img0_pkti_bp1_coef_1;                    /* < 2> [dv:     0x0000] [des: PKTI User BP1 Coefficient Register 1] */
    unsigned img0_pkti_bp1_coef_2;                    /* < 3> [dv:     0x0000] [des: PKTI User BP1 Coefficient Register 2] */
    unsigned img0_pkti_bp1_coef_3;                    /* < 4> [dv:     0x0000] [des: PKTI User BP1 Coefficient Register 3] */
    unsigned img0_pkti_lpk_config;                    /* < 5> [dv:     0x0000] [des: PKTI LPK Config Register] */
    unsigned img0_pkti_lpk_gain;                      /* < 6> [dv:     0x0000] [des: PKTI LPK Gain Register] */
    unsigned img0_pkti_lpk_lut_1;                     /* < 7> [dv:     0x0000] [des: PKTI LPK Gain LUT Register 1] */
    unsigned img0_pkti_lpk_lut_2;                     /* < 8> [dv:     0x0000] [des: PKTI LPK Gain LUT Register 2] */
    unsigned img0_pkti_lpk_lut_3;                     /* < 9> [dv:     0x0000] [des: PKTI LPK Gain LUT Register 3] */
    unsigned img0_pkti_lpk_lut_4;                     /* <10> [dv:     0x0000] [des: PKTI LPK Gain LUT Register 4] */
    unsigned img0_pkti_lpk_lut_5;                     /* <11> [dv:     0x0000] [des: PKTI LPK Gain LUT Register 5] */
    unsigned img0_pkti_lpk_lut_6;                     /* <12> [dv:     0x0000] [des: PKTI LPK Gain LUT Register 6] */
    unsigned img0_pkti_lpk_ovsht_1;                   /* <13> [dv:     0x0000] [des: PKTI LPK Overshoot Register 1] */
    unsigned img0_pkti_lpk_ovsht_2;                   /* <14> [dv:     0x0000] [des: PKTI LPK Overshoot Register 2] */
    unsigned img0_pkti_lti_gain;                      /* <15> [dv:     0x0000] [des: PKTI LTI Gain Register] */
    unsigned img0_pkti_lti_lut_1;                     /* <16> [dv:     0x0000] [des: PKTI LTI Gain LUT Register 1] */
    unsigned img0_pkti_lti_lut_2;                     /* <17> [dv:     0x0000] [des: PKTI LTI Gain LUT Register 2] */
    unsigned img0_pkti_lti_lut_3;                     /* <18> [dv:     0x0000] [des: PKTI LTI Gain LUT Register 3] */
    unsigned img0_pkti_lti_lut_4;                     /* <19> [dv:     0x0000] [des: PKTI LTI Gain LUT Register 4] */
    unsigned img0_pkti_lti_lut_5;                     /* <20> [dv:     0x0000] [des: PKTI LTI Gain LUT Register 5] */
    unsigned img0_pkti_lti_lut_6;                     /* <21> [dv:     0x0000] [des: PKTI LTI Gain LUT Register 6] */
    unsigned img0_pkti_lti_ovsht_1;                   /* <22> [dv:     0x0000] [des: PKTI LTI Overshoot Register 1] */
    unsigned img0_pkti_lti_ovsht_2;                   /* <23> [dv:     0x0000] [des: PKTI LTI Overshoot Register 2] */
    unsigned img0_sram_ctrl;                          /* <24> [dv:     0x0000] [des: Sram Control Register] */
    unsigned img0_sram_addr;                          /* <25> [dv:     0x0000] [des: SRAM Address Register] */
    unsigned img0_sram_write_data;                    /* <26> [dv:     0x0000] [des: SRAM Write Data Register] */
    unsigned img0_sram_read_data;                     /* <27> [dv:     0x0000] [des: SRAM Read Data Register] */
    unsigned img0_pix_no;                             /* <28> [dv:     0x0000] [des: Frame width] */
    unsigned img0_line_no;                            /* <29> [dv:     0x0000] [des: Frame height] */
    unsigned img0_chksum_ans;                         /* <30> [dv:     0x0000] [des: Check sum result] */
    unsigned grp197_reserved_0;                       /* <31> */
    // GROUP 198 [image_processing_img1]
    unsigned img1_config;                             /* < 0> [dv:     0x0001] [des: IMG config register] */
    unsigned img1_pkti_ctrl;                          /* < 1> [dv:     0x0000] [des: PKTI Control Register] */
    unsigned img1_pkti_bp1_coef_1;                    /* < 2> [dv:     0x0000] [des: PKTI User BP1 Coefficient Register 1] */
    unsigned img1_pkti_bp1_coef_2;                    /* < 3> [dv:     0x0000] [des: PKTI User BP1 Coefficient Register 2] */
    unsigned img1_pkti_bp1_coef_3;                    /* < 4> [dv:     0x0000] [des: PKTI User BP1 Coefficient Register 3] */
    unsigned img1_pkti_lpk_config;                    /* < 5> [dv:     0x0000] [des: PKTI LPK Config Register] */
    unsigned img1_pkti_lpk_gain;                      /* < 6> [dv:     0x0000] [des: PKTI LPK Gain Register] */
    unsigned img1_pkti_lpk_lut_1;                     /* < 7> [dv:     0x0000] [des: PKTI LPK Gain LUT Register 1] */
    unsigned img1_pkti_lpk_lut_2;                     /* < 8> [dv:     0x0000] [des: PKTI LPK Gain LUT Register 2] */
    unsigned img1_pkti_lpk_lut_3;                     /* < 9> [dv:     0x0000] [des: PKTI LPK Gain LUT Register 3] */
    unsigned img1_pkti_lpk_lut_4;                     /* <10> [dv:     0x0000] [des: PKTI LPK Gain LUT Register 4] */
    unsigned img1_pkti_lpk_lut_5;                     /* <11> [dv:     0x0000] [des: PKTI LPK Gain LUT Register 5] */
    unsigned img1_pkti_lpk_lut_6;                     /* <12> [dv:     0x0000] [des: PKTI LPK Gain LUT Register 6] */
    unsigned img1_pkti_lpk_ovsht_1;                   /* <13> [dv:     0x0000] [des: PKTI LPK Overshoot Register 1] */
    unsigned img1_pkti_lpk_ovsht_2;                   /* <14> [dv:     0x0000] [des: PKTI LPK Overshoot Register 2] */
    unsigned img1_pkti_lti_gain;                      /* <15> [dv:     0x0000] [des: PKTI LTI Gain Register] */
    unsigned img1_pkti_lti_lut_1;                     /* <16> [dv:     0x0000] [des: PKTI LTI Gain LUT Register 1] */
    unsigned img1_pkti_lti_lut_2;                     /* <17> [dv:     0x0000] [des: PKTI LTI Gain LUT Register 2] */
    unsigned img1_pkti_lti_lut_3;                     /* <18> [dv:     0x0000] [des: PKTI LTI Gain LUT Register 3] */
    unsigned img1_pkti_lti_lut_4;                     /* <19> [dv:     0x0000] [des: PKTI LTI Gain LUT Register 4] */
    unsigned img1_pkti_lti_lut_5;                     /* <20> [dv:     0x0000] [des: PKTI LTI Gain LUT Register 5] */
    unsigned img1_pkti_lti_lut_6;                     /* <21> [dv:     0x0000] [des: PKTI LTI Gain LUT Register 6] */
    unsigned img1_pkti_lti_ovsht_1;                   /* <22> [dv:     0x0000] [des: PKTI LTI Overshoot Register 1] */
    unsigned img1_pkti_lti_ovsht_2;                   /* <23> [dv:     0x0000] [des: PKTI LTI Overshoot Register 2] */
    unsigned img1_sram_ctrl;                          /* <24> [dv:     0x0000] [des: Sram Control Register] */
    unsigned img1_sram_addr;                          /* <25> [dv:     0x0000] [des: SRAM Address Register] */
    unsigned img1_sram_write_data;                    /* <26> [dv:     0x0000] [des: SRAM Write Data Register] */
    unsigned img1_sram_read_data;                     /* <27> [dv:     0x0000] [des: SRAM Read Data Register] */
    unsigned img1_pix_no;                             /* <28> [dv:     0x0000] [des: Frame width] */
    unsigned img1_line_no;                            /* <29> [dv:     0x0000] [des: Frame height] */
    unsigned img1_chksum_ans;                         /* <30> [dv:     0x0000] [des: Check sum result] */
    unsigned grp198_reserved_0;                       /* <31> */
    // GROUP 199 [vpost0]
    unsigned vpost0_config;                           /* < 0> [dv:     0x0001] [des: VPOST config register] */
    unsigned vpost0_adj_config;                       /* < 1> [dv:     0x0000] [des: ADJ Control Register] */
    unsigned vpost0_adj_src;                          /* < 2> [dv:     0x0000] [des: VPP contrast adjustment turning point] */
    unsigned vpost0_adj_des;                          /* < 3> [dv:     0x0000] [des: VPP contrast adjustment turning point] */
    unsigned vpost0_adj_slope0;                       /* < 4> [dv:     0x0000] [des: VPOST contrast adjustment slope] */
    unsigned vpost0_adj_slope1;                       /* < 5> [dv:     0x0000] [des: VPOST contrast adjustment slope] */
    unsigned vpost0_adj_slope2;                       /* < 6> [dv:     0x0000] [des: VPOST contrast adjustment slope] */
    unsigned vpost0_adj_bound;                        /* < 7> [dv:     0x0000] [des: VPOST new luma boundary value] */
    unsigned vpost0_cspace_config;                    /* < 8> [dv:     0x0000] [des: CSPACE control register] */
    unsigned vpost0_opif_config;                      /* < 9> [dv:     0x0000] [des: OPIF control register] */
    unsigned vpost0_opif_bgy;                         /* <10> [dv:     0x0000] [des: Background color Y] */
    unsigned vpost0_opif_bguv;                        /* <11> [dv:     0x0000] [des: Background color UV] */
    unsigned vpost0_opif_alpha;                       /* <12> [dv:     0xffff] [des: Alpha value setting] */
    unsigned vpost0_opif_msktop;                      /* <13> [dv:     0x0000] [des: Top masked region] */
    unsigned vpost0_opif_mskbot;                      /* <14> [dv:     0x0000] [des: Bottom masked region] */
    unsigned vpost0_xlen;                             /* <15> [dv:     0x0000] [des: Frame width] */
    unsigned vpost0_ylen;                             /* <16> [dv:     0x0000] [des: Frame height] */
    unsigned vpost0_chksum_ans;                       /* <17> [dv:     0x0000] [des: VPOST check sum result] */
    unsigned vpp_xstart;                              /* <18> [dv:     0x000e] [des: VPP horizontal start position] */
    unsigned vpp_ystart;                              /* <19> [dv:     0x0025] [des: VPP vertical start position] */
    unsigned grp199_reserved_0;                       /* <20> */
    unsigned grp199_reserved_1;                       /* <21> */
    unsigned grp199_reserved_2;                       /* <22> */
    unsigned grp199_reserved_3;                       /* <23> */
    unsigned grp199_reserved_4;                       /* <24> */
    unsigned grp199_reserved_5;                       /* <25> */
    unsigned grp199_reserved_6;                       /* <26> */
    unsigned grp199_reserved_7;                       /* <27> */
    unsigned grp199_reserved_8;                       /* <28> */
    unsigned grp199_reserved_9;                       /* <29> */
    unsigned grp199_reserved_10;                      /* <30> */
    unsigned grp199_reserved_11;                      /* <31> */
    // GROUP 200 [vpost1]
    unsigned vpost1_config;                           /* < 0> [dv:     0x0001] [des: VPOST config register] */
    unsigned vpost1_adj_config;                       /* < 1> [dv:     0x0000] [des: ADJ Control Register] */
    unsigned vpost1_adj_src;                          /* < 2> [dv:     0x0000] [des: VPP contrast adjustment turning point] */
    unsigned vpost1_adj_des;                          /* < 3> [dv:     0x0000] [des: VPP contrast adjustment turning point] */
    unsigned vpost1_adj_slope0;                       /* < 4> [dv:     0x0000] [des: VPOST contrast adjustment slope] */
    unsigned vpost1_adj_slope1;                       /* < 5> [dv:     0x0000] [des: VPOST contrast adjustment slope] */
    unsigned vpost1_adj_slope2;                       /* < 6> [dv:     0x0000] [des: VPOST contrast adjustment slope] */
    unsigned vpost1_adj_bound;                        /* < 7> [dv:     0x0000] [des: VPOST new luma boundary value] */
    unsigned vpost1_cspace_config;                    /* < 8> [dv:     0x0000] [des: CSPACE control register] */
    unsigned vpost1_opif_config;                      /* < 9> [dv:     0x0000] [des: OPIF control register] */
    unsigned vpost1_opif_bgy;                         /* <10> [dv:     0x0000] [des: Background color Y] */
    unsigned vpost1_opif_bguv;                        /* <11> [dv:     0x0000] [des: Background color UV] */
    unsigned vpost1_opif_alpha;                       /* <12> [dv:     0xffff] [des: Alpha value setting] */
    unsigned vpost1_opif_msktop;                      /* <13> [dv:     0x0000] [des: Top masked region] */
    unsigned vpost1_opif_mskbot;                      /* <14> [dv:     0x0000] [des: Bottom masked region] */
    unsigned vpost1_xlen;                             /* <15> [dv:     0x0000] [des: Frame width] */
    unsigned vpost1_ylen;                             /* <16> [dv:     0x0000] [des: Frame height] */
    unsigned vpost1_chksum_ans;                       /* <17> [dv:     0x0000] [des: VPOST check sum result] */
    unsigned vpp_xstart_1;                            /* <18> [dv:     0x000e] [des: VPP horizontal start position] */
    unsigned vpp_ystart_1;                            /* <19> [dv:     0x0025] [des: VPP vertical start position] */
    unsigned grp200_reserved_0;                       /* <20> */
    unsigned grp200_reserved_1;                       /* <21> */
    unsigned grp200_reserved_2;                       /* <22> */
    unsigned grp200_reserved_3;                       /* <23> */
    unsigned grp200_reserved_4;                       /* <24> */
    unsigned grp200_reserved_5;                       /* <25> */
    unsigned grp200_reserved_6;                       /* <26> */
    unsigned grp200_reserved_7;                       /* <27> */
    unsigned grp200_reserved_8;                       /* <28> */
    unsigned grp200_reserved_9;                       /* <29> */
    unsigned grp200_reserved_10;                      /* <30> */
    unsigned grp200_reserved_11;                      /* <31> */
    // GROUP 201 [hd2sd_hd2sd_scaler]
    unsigned hd2sd_config;                            /* < 0> [dv:     0x0095] [des: Configuration Register] */
    unsigned hd2sd_user_hexp0;                        /* < 1> [dv:     0x5556] [des: User-mode HEXP Register 0] */
    unsigned hd2sd_user_hexp1;                        /* < 2> [dv:     0x0004] [des: User-mode HEXP Register 1] */
    unsigned hd2sd_user_vexp0;                        /* < 3> [dv:     0x449a] [des: User-mode VEXP Register 0] */
    unsigned hd2sd_user_vexp1;                        /* < 4> [dv:     0x0042] [des: User-mode VEXP Register 1] */
    unsigned hd2sd_user_vexp2;                        /* < 5> [dv:     0x001f] [des: User-mode VEXP Register 2] */
    unsigned hd2sd_user_sd_reset0;                    /* < 6> [dv:     0x04fa] [des: User-mode SD_RESET Register 0] */
    unsigned hd2sd_user_sd_reset1;                    /* < 7> [dv:     0x4f37] [des: User-mode SD_RESET Register 1] */
    unsigned hd2sd_status;                            /* < 8> [dv:     0x0000] [des: Status Register] */
    unsigned hd2sd_peaking_config;                    /* < 9> [dv:     0x1333] [des: Luma Peaking Config Register] */
    unsigned hd2sd_peaking_lut0;                      /* <10> [dv:     0x1808] [des: Luma Peaking LUT Register 0] */
    unsigned hd2sd_peaking_lut1;                      /* <11> [dv:     0x0074] [des: Luma Peaking LUT Register 1] */
    unsigned hd2sd_peaking_limit;                     /* <12> [dv:     0x1010] [des: Luma Peaking Limit Register] */
    unsigned hd2sd_hd_checksum;                       /* <13> [dv:     0x0000] [des: HD Checksum Register] */
    unsigned hd2sd_sd_checksum;                       /* <14> [dv:     0x0000] [des: SD Checksum Register] */
    unsigned hd2sd_user_sdtve_vrst0;                  /* <15> [dv:     0x0000] [des: User-mode SDTVE_VRST Register 0] */
    unsigned hd2sd_user_sdtve_vrst1;                  /* <16> [dv:     0x0000] [des: User-mode SDTVE_VRST Register 1] */
    unsigned hd2sd_user_sdtve_hrst;                   /* <17> [dv:     0x0010] [des: User-mode SDTVE_HRST Register] */
    unsigned hd2sd_bgc_y;                             /* <18> [dv:     0x0010] [des: Background Color Y Register] */
    unsigned hd2sd_bgc_c;                             /* <19> [dv:     0x8080] [des: Background Color C Register] */
    unsigned hd2sd_config2;                           /* <20> [dv:     0x0000] [des: Input Data Mask Selection] */
    unsigned hd2sd_user_hact;                         /* <21> [dv:     0x0000] [des: Scaling down hact size] */
    unsigned hd2sd_user_vact;                         /* <22> [dv:     0x0000] [des: Scaling down vact size] */
    unsigned hd2sd_tve_user_mode;                     /* <23> [dv:     0x0000] [des: User mode size output to TVE] */
    unsigned grp201_reserved_0;                       /* <24> */
    unsigned grp201_reserved_1;                       /* <25> */
    unsigned grp201_reserved_2;                       /* <26> */
    unsigned grp201_reserved_3;                       /* <27> */
    unsigned grp201_reserved_4;                       /* <28> */
    unsigned grp201_reserved_5;                       /* <29> */
    unsigned grp201_reserved_6;                       /* <30> */
    unsigned grp201_reserved_7;                       /* <31> */
    // GROUP 202 [afrc_auto_frame_rate_convertion]
    unsigned afrc_mode0;                              /* < 0> [dv:        0x0] [des: AFRC main control register (1/3)] */
    unsigned afrc_fb_ctrl0;                           /* < 1> [dv:        0x8] [des: Frame buffer control related registers (1/2)] */
    unsigned afrc_fb_ctrl1;                           /* < 2> [dv:     0x2012] [des: Frame buffer control related registers (2/2)] */
    unsigned afrc_bist_mode0;                         /* < 3> [dv:        0x0] [des: Build-in self test register (1/2)] */
    unsigned afrc_bist_mode1;                         /* < 4> [dv:        0x0] [des: Build-in self test register (2/2)] */
    unsigned afrc_urgent_thd;                         /* < 5> [dv:        240] [des: Urgent threshould (for system bus)] */
    unsigned afrc_iw_req_clkcnt;                      /* < 6> [dv:          0] [des: Custom bandwidth limiter for AFRC-W (for system bus)] */
    unsigned afrc_faddr0_lw;                          /* < 7> [dv:          0] [des: Base address of frame buffer - low word] */
    unsigned afrc_faddr0_hw;                          /* < 8> [dv:          0] [des: Base address of frame buffer - high word] */
    unsigned afrc_fb_step;                            /* < 9> [dv:     0x1b00] [des: Step(/size) of each frame buffer] */
    unsigned afrc_tgr_hact;                           /* <10> [dv:        720] [des: Number of active pixel] */
    unsigned afrc_tgr_htot;                           /* <11> [dv:        858] [des: Number of total pixel] */
    unsigned afrc_tgr_vact_st_t;                      /* <12> [dv:         43] [des: Active start line number in top field] */
    unsigned afrc_tgr_vact_ed_t;                      /* <13> [dv:        522] [des: Active end line number in top field] */
    unsigned afrc_tgr_vact_st_b;                      /* <14> [dv:         43] [des: Active start line number in bottom field] */
    unsigned afrc_tgr_vact_ed_b;                      /* <15> [dv:        522] [des: Active end line number in bottom field] */
    unsigned afrc_tgr_vtot;                           /* <16> [dv:        525] [des: Number of total line] */
    unsigned afrc_sync_vcnt;                          /* <17> [dv:          0] [des: AFRC-R line counter reset value] */
    unsigned afrc_sync_hcnt;                          /* <18> [dv:          0] [des: AFRC-R pixel counter reset value] */
    unsigned afrc_out_vact_st_t;                      /* <19> [dv:          0] [des: Top field active start line number (when interface output)] */
    unsigned afrc_out_vact_st_b;                      /* <20> [dv:          0] [des: Bottom field active start line number (when interface output)] */
    unsigned afrc_irq_line;                           /* <21> [dv:        0x1] [des: Line number interrupt to CPU] */
    unsigned afrc_debug;                              /* <22> [dv:        0x1] [des: [READ ONLY] AFRC-R line counter] */
    unsigned afrc_chkout_a;                           /* <23> [dv:          0] [des: [READ ONLY] Result of checksum A] */
    unsigned afrc_chkout_b;                           /* <24> [dv:          0] [des: [READ ONLY] Result of checksum B] */
    unsigned reserved_0_35;                           /* <25> [dv:       0x00] [des: Reserved] */
    unsigned reserved_1_31;                           /* <26> [dv:       0x00] [des: Reserved] */
    unsigned reserved_2_26;                           /* <27> [dv:       0x00] [des: Reserved] */
    unsigned afrc_afrc_rw_sync2;                      /* <28> [dv:          0] [des: Single DRAM Frame Buffer Operation Mode (2/2)] */
    unsigned afrc_mode1;                              /* <29> [dv:     0x0806] [des: AFRC main control register (2/3)] */
    unsigned afrc_mode2;                              /* <30> [dv:     0x2000] [des: AFRC main control register (3/3)] */
    unsigned afrc_afrc_rw_sync;                       /* <31> [dv:     0x1000] [des: Single DRAM Frame Buffer Operation Mode (1/2)] */
    // GROUP 203 [tgen_timing_generator]
    unsigned tgen_config;                             /* < 0> [dv:     0x0000] [des: TGEN Config Register] */
    unsigned tgen_reset;                              /* < 1> [dv:     0x0000] [des: TGEN Reset Register] */
    unsigned user_int1_config;                        /* < 2> [dv:     0x0180] [des: User Interrupt 1 Config Register] */
    unsigned reserved_0_36;                           /* < 3> [dv:     0x1200] [des: Reserved] */
    unsigned dtg_config;                              /* < 4> [dv:     0x0010] [des: DTG Config Register] */
    unsigned reserved_1_32;                           /* < 5> [dv:     0x1006] [des: Reserved] */
    unsigned dtg_adjust2;                             /* < 6> [dv:     0x0101] [des: DTG Adjust Register 2] */
    unsigned reserved_2_27;                           /* < 7> [dv:     0x1003] [des: Reserved] */
    unsigned dtg_total_pixel;                         /* < 8> [dv:     0x035a] [des: DTG Total Pixel Register] */
    unsigned dtg_ds_line_start_cd_point;              /* < 9> [dv:     0x0311] [des: DTG DS_LINE_START CD Point Register] */
    unsigned dtg_total_line;                          /* <10> [dv:     0x020d] [des: DTG Total Line Register] */
    unsigned dtg_field_end_line;                      /* <11> [dv:     0x0205] [des: DTG Field End Line Register] */
    unsigned dtg_tve_line_rst_cnt;                    /* <12> [dv:     0x0002] [des: DTG TVE Line Reset Control Register] */
    unsigned dtg_status1;                             /* <13> [dv:     0x1001] [des: DTG Status Register 1] */
    unsigned dtg_status2;                             /* <14> [dv:     0x0001] [des: DTG Status Register 2] */
    unsigned dtg_start_line;                          /* <15> [dv:     0x0026] [des: DTG ACTIVE START LINE] */
    unsigned atg_config;                              /* <16> [dv:     0x0002] [des: ATG Config Register] */
    unsigned atg_clk_ratio_low;                       /* <17> [dv:     0x851F] [des: ATG Clock Ratio Low Register] */
    unsigned atg_clk_ratio_high;                      /* <18> [dv:     0x002F] [des: ATG Clock Ratio High Register] */
    unsigned atg_total_pixel;                         /* <19> [dv:     0x035A] [des: ATG Total Pixel Register] */
    unsigned atg_first_line_total_pixel;              /* <20> [dv:     0x035A] [des: ATG First Line Total Pixel Register] */
    unsigned atg_field_end_line;                      /* <21> [dv:     0x0205] [des: ATG Field End Line Register] */
    unsigned atg_ds_line_start_cd_point;              /* <22> [dv:     0x0311] [des: ATG DS_LINE_START CD Point Register] */
    unsigned atg_adjust1;                             /* <23> [dv:     0x211f] [des: ATG Adjust Register 1] */
    unsigned atg_adjust2;                             /* <24> [dv:     0x1d1b] [des: ATG Adjust Register 2] */
    unsigned atg_adjust3;                             /* <25> [dv:     0x1917] [des: ATG Adjust Register 3] */
    unsigned atg_adjust4;                             /* <26> [dv:     0x1207] [des: ATG Adjust Register 4] */
    unsigned atg_status1;                             /* <27> [dv:     0x1001] [des: ATG Status Register 1] */
    unsigned atg_status2;                             /* <28> [dv:     0x0001] [des: ATG Status Register 2] */
    unsigned source_sel;                              /* <29> [dv:     0x0000] [des: Source select] */
    unsigned dtg_field_start_adj_lcnt;                /* <30> [dv:     0x0001] [des: Source select] */
    unsigned grp203_reserved_0;                       /* <31> */
    // GROUP 204 [tgen_timing_generator]
    unsigned tgen_config_1;                           /* < 0> [dv:     0x0000] [des: TGEN Config Register] */
    unsigned tgen_reset_1;                            /* < 1> [dv:     0x0000] [des: TGEN Reset Register] */
    unsigned user_int1_config_1;                      /* < 2> [dv:     0x0180] [des: User Interrupt 1 Config Register] */
    unsigned reserved_0_37;                           /* < 3> [dv:     0x1200] [des: Reserved] */
    unsigned dtg_config_1;                            /* < 4> [dv:     0x0010] [des: DTG Config Register] */
    unsigned reserved_1_33;                           /* < 5> [dv:     0x1006] [des: Reserved] */
    unsigned dtg_adjust2_1;                           /* < 6> [dv:     0x0101] [des: DTG Adjust Register 2] */
    unsigned reserved_2_28;                           /* < 7> [dv:     0x1003] [des: Reserved] */
    unsigned dtg_total_pixel_1;                       /* < 8> [dv:     0x035a] [des: DTG Total Pixel Register] */
    unsigned dtg_ds_line_start_cd_point_1;            /* < 9> [dv:     0x0311] [des: DTG DS_LINE_START CD Point Register] */
    unsigned dtg_total_line_1;                        /* <10> [dv:     0x020d] [des: DTG Total Line Register] */
    unsigned dtg_field_end_line_1;                    /* <11> [dv:     0x0205] [des: DTG Field End Line Register] */
    unsigned dtg_tve_line_rst_cnt_1;                  /* <12> [dv:     0x0002] [des: DTG TVE Line Reset Control Register] */
    unsigned dtg_status1_1;                           /* <13> [dv:     0x1001] [des: DTG Status Register 1] */
    unsigned dtg_status2_1;                           /* <14> [dv:     0x0001] [des: DTG Status Register 2] */
    unsigned dtg_start_line_1;                        /* <15> [dv:     0x0026] [des: DTG ACTIVE START LINE] */
    unsigned atg_config_1;                            /* <16> [dv:     0x0002] [des: ATG Config Register] */
    unsigned atg_clk_ratio_low_1;                     /* <17> [dv:     0x851F] [des: ATG Clock Ratio Low Register] */
    unsigned atg_clk_ratio_high_1;                    /* <18> [dv:     0x002F] [des: ATG Clock Ratio High Register] */
    unsigned atg_total_pixel_1;                       /* <19> [dv:     0x035A] [des: ATG Total Pixel Register] */
    unsigned atg_first_line_total_pixel_1;            /* <20> [dv:     0x035A] [des: ATG First Line Total Pixel Register] */
    unsigned atg_field_end_line_1;                    /* <21> [dv:     0x0205] [des: ATG Field End Line Register] */
    unsigned atg_ds_line_start_cd_point_1;            /* <22> [dv:     0x0311] [des: ATG DS_LINE_START CD Point Register] */
    unsigned atg_adjust1_1;                           /* <23> [dv:     0x211f] [des: ATG Adjust Register 1] */
    unsigned atg_adjust2_1;                           /* <24> [dv:     0x1d1b] [des: ATG Adjust Register 2] */
    unsigned atg_adjust3_1;                           /* <25> [dv:     0x1917] [des: ATG Adjust Register 3] */
    unsigned atg_adjust4_1;                           /* <26> [dv:     0x1207] [des: ATG Adjust Register 4] */
    unsigned atg_status1_1;                           /* <27> [dv:     0x1001] [des: ATG Status Register 1] */
    unsigned atg_status2_1;                           /* <28> [dv:     0x0001] [des: ATG Status Register 2] */
    unsigned source_sel_1;                            /* <29> [dv:     0x0000] [des: Source select] */
    unsigned dtg_field_start_adj_lcnt_1;              /* <30> [dv:     0x0001] [des: Source select] */
    unsigned grp204_reserved_0;                       /* <31> */
    // GROUP 205 [amix_0_aperture_mixer_0]
    unsigned amix_0_config0;                          /* < 0> [dv:     0xfc00] [des: AMIX_0 Config Register 0] */
    unsigned amix_0_config1;                          /* < 1> [dv:     0x0555] [des: AMIX_0 Config Register 1] */
    unsigned amix_0_config2;                          /* < 2> [dv:     0x0fff] [des: AMIX_0 Config Register 2] */
    unsigned amix_0_plane_alpha;                      /* < 3> [dv:     0x0000] [des: AMIX_0 Plane Alpha Register] */
    unsigned amix_0_plane_alpha2;                     /* < 4> [dv:     0x0000] [des: AMIX_0 Plane Alpha Register 2] */
    unsigned amix_0_plane_alpha3;                     /* < 5> [dv:     0x0000] [des: AMIX_0 Plane Alpha Register 3] */
    unsigned reserved_0_38;                           /* < 6> [dv:     0x0000] [des: Reserved Register] */
    unsigned reserved_1_34;                           /* < 7> [dv:     0x0000] [des: Reserved Register] */
    unsigned reserved_2_29;                           /* < 8> [dv:     0x0000] [des: Reserved Register] */
    unsigned reserved_3_25;                           /* < 9> [dv:     0x0000] [des: Reserved Register] */
    unsigned reserved_4_23;                           /* <10> [dv:     0x0000] [des: Reserved Register] */
    unsigned reserved_5_21;                           /* <11> [dv:     0x0000] [des: Reserved Register] */
    unsigned reserved_6_18;                           /* <12> [dv:     0x0000] [des: Reserved Register] */
    unsigned reserved_7_18;                           /* <13> [dv:     0x0000] [des: Reserved Register] */
    unsigned amix_0_bgc_y;                            /* <14> [dv:     0x0010] [des: AMIX_0 Background Color Y Register] */
    unsigned amix_0_bgc_c;                            /* <15> [dv:     0x8080] [des: AMIX_0 Background Color C Register] */
    unsigned reserved_8_17;                           /* <16> [dv:     0x0000] [des: Reserved Register] */
    unsigned amix_0_ptg_config;                       /* <17> [dv:     0x0240] [des: AMIX_0 PTG Config Register] */
    unsigned amix_0_ptg_config_2;                     /* <18> [dv:     0x0000] [des: AMIX_0 PTG Config Register] */
    unsigned amix_0_ptg_config_3;                     /* <19> [dv:     0x0000] [des: AMIX_0 PTG Config Register] */
    unsigned amix_0_ptg_config_4;                     /* <20> [dv:     0x0010] [des: AMIX_0 PTG Config Register] */
    unsigned amix_0_ptg_config_5;                     /* <21> [dv:     0x0080] [des: AMIX_0 PTG Config Register] */
    unsigned amix_0_ptg_config_6;                     /* <22> [dv:     0x0080] [des: AMIX_0 PTG Config Register] */
    unsigned grp205_reserved_0;                       /* <23> */
    unsigned grp205_reserved_1;                       /* <24> */
    unsigned grp205_reserved_2;                       /* <25> */
    unsigned grp205_reserved_3;                       /* <26> */
    unsigned grp205_reserved_4;                       /* <27> */
    unsigned grp205_reserved_5;                       /* <28> */
    unsigned grp205_reserved_6;                       /* <29> */
    unsigned grp205_reserved_7;                       /* <30> */
    unsigned grp205_reserved_8;                       /* <31> */
    // GROUP 206 [amix_0_aperture_mixer_0]
    unsigned amix_0_config0_1;                        /* < 0> [dv:     0xfc00] [des: AMIX_0 Config Register 0] */
    unsigned amix_0_config1_1;                        /* < 1> [dv:     0x0555] [des: AMIX_0 Config Register 1] */
    unsigned amix_0_config2_1;                        /* < 2> [dv:     0x0fff] [des: AMIX_0 Config Register 2] */
    unsigned amix_0_plane_alpha_1;                    /* < 3> [dv:     0x0000] [des: AMIX_0 Plane Alpha Register] */
    unsigned amix_0_plane_alpha2_1;                   /* < 4> [dv:     0x0000] [des: AMIX_0 Plane Alpha Register 2] */
    unsigned amix_0_plane_alpha3_1;                   /* < 5> [dv:     0x0000] [des: AMIX_0 Plane Alpha Register 3] */
    unsigned reserved_0_39;                           /* < 6> [dv:     0x0000] [des: Reserved Register] */
    unsigned reserved_1_35;                           /* < 7> [dv:     0x0000] [des: Reserved Register] */
    unsigned reserved_2_30;                           /* < 8> [dv:     0x0000] [des: Reserved Register] */
    unsigned reserved_3_26;                           /* < 9> [dv:     0x0000] [des: Reserved Register] */
    unsigned reserved_4_24;                           /* <10> [dv:     0x0000] [des: Reserved Register] */
    unsigned reserved_5_22;                           /* <11> [dv:     0x0000] [des: Reserved Register] */
    unsigned reserved_6_19;                           /* <12> [dv:     0x0000] [des: Reserved Register] */
    unsigned reserved_7_19;                           /* <13> [dv:     0x0000] [des: Reserved Register] */
    unsigned amix_0_bgc_y_1;                          /* <14> [dv:     0x0010] [des: AMIX_0 Background Color Y Register] */
    unsigned amix_0_bgc_c_1;                          /* <15> [dv:     0x8080] [des: AMIX_0 Background Color C Register] */
    unsigned reserved_8_18;                           /* <16> [dv:     0x0000] [des: Reserved Register] */
    unsigned amix_0_ptg_config_1;                     /* <17> [dv:     0x0240] [des: AMIX_0 PTG Config Register] */
    unsigned amix_0_ptg_config_2_1;                   /* <18> [dv:     0x0000] [des: AMIX_0 PTG Config Register] */
    unsigned amix_0_ptg_config_3_1;                   /* <19> [dv:     0x0000] [des: AMIX_0 PTG Config Register] */
    unsigned amix_0_ptg_config_4_1;                   /* <20> [dv:     0x0010] [des: AMIX_0 PTG Config Register] */
    unsigned amix_0_ptg_config_5_1;                   /* <21> [dv:     0x0080] [des: AMIX_0 PTG Config Register] */
    unsigned amix_0_ptg_config_6_1;                   /* <22> [dv:     0x0080] [des: AMIX_0 PTG Config Register] */
    unsigned grp206_reserved_0;                       /* <23> */
    unsigned grp206_reserved_1;                       /* <24> */
    unsigned grp206_reserved_2;                       /* <25> */
    unsigned grp206_reserved_3;                       /* <26> */
    unsigned grp206_reserved_4;                       /* <27> */
    unsigned grp206_reserved_5;                       /* <28> */
    unsigned grp206_reserved_6;                       /* <29> */
    unsigned grp206_reserved_7;                       /* <30> */
    unsigned grp206_reserved_8;                       /* <31> */
    // GROUP 207 [dmix_0_display_mixer_0]
    unsigned dmix_0_config;                           /* < 0> [dv:     0x0006] [des: DMIX_0 Config Register] */
    unsigned reserved_0_40;                           /* < 1> [dv:     0x0000] [des: Reserved Register] */
    unsigned reserved_1_36;                           /* < 2> [dv:     0x0000] [des: Reserved Register] */
    unsigned reserved_2_31;                           /* < 3> [dv:     0x0000] [des: Reserved Register] */
    unsigned dmix_0_yc_adjust;                        /* < 4> [dv:     0x0000] [des: DMIX_0 YC Adjust Register] */
    unsigned dmix_0_luma_cp1;                         /* < 5> [dv:     0x0000] [des: DMIX_0 Luma Adjust Control Point 1 Register] */
    unsigned dmix_0_luma_cp2;                         /* < 6> [dv:     0x5060] [des: DMIX_0 Luma Adjust Control Point 2 Register] */
    unsigned dmix_0_luma_cp3;                         /* < 7> [dv:     0xB0A0] [des: DMIX_0 Luma Adjust Control Point 3 Register] */
    unsigned dmix_0_luma_slope0;                      /* < 8> [dv:     0x0100] [des: DMIX_0 Luma Adjust Slope 0 Register] */
    unsigned dmix_0_luma_slope1;                      /* < 9> [dv:     0x00D5] [des: DMIX_0 Luma Adjust Slope 1 Register] */
    unsigned dmix_0_luma_slope2;                      /* <10> [dv:     0x0180] [des: DMIX_0 Luma Adjust Slope 2 Register] */
    unsigned dmix_0_luma_slope3;                      /* <11> [dv:     0x00D5] [des: DMIX_0 Luma Adjust Slope 3 Register] */
    unsigned dmix_0_chroma_satcos;                    /* <12> [dv:     0x0200] [des: DMIX_0 Chroma Adjust SATCOS Register] */
    unsigned dmix_0_chroma_satsin;                    /* <13> [dv:     0x0000] [des: DMIX_0 Chroma Adjust SATSIN Register] */
    unsigned dmix_0_checksum_setting;                 /* <14> [dv:     0x0001] [des: DMIX_0 CHECK SUM SETTING] */
    unsigned dmix_0_chksum_usermode_v;                /* <15> [dv:     0x01e0] [des: DMIX_0 CHECK SUM USER MODE V active] */
    unsigned dmix_0_chksum_usermode_h;                /* <16> [dv:     0x02d0] [des: DMIX_0 CHECK SUM USER MODE H active] */
    unsigned dmix_0_chksum_usermode_start_line;       /* <17> [dv:     0x0024] [des: DMIX_0 CHECK SUM USER MODE V start line] */
    unsigned dmix_0_to_venc_chksum;                   /* <18> [dv:        0x0] [des: DMIX_0 TO VENC CHECK SUM] */
    unsigned dmix_0_to_hd2sd_chksum;                  /* <19> [dv:        0x0] [des: DMIX_0 TO hd2sd CHECK SUM] */
    unsigned dmix_0_fgc_y_alpha;                      /* <20> [dv:     0x0010] [des: DMIX_0 Frontground Color Y and alpha Register] */
    unsigned dmix_0_fgc_c;                            /* <21> [dv:     0x8080] [des: DMIX_0 Frontground Color C Register] */
    unsigned dmix_0_pix_en_sel;                       /* <22> [dv:        0x0] [des: DMIX_0 PIX_EN SEL] */
    unsigned dmix_snr_set;                            /* <23> [dv:     0x0000] [des: DMIX SNR Set Register] */
    unsigned dmix_snr_start_set;                      /* <24> [dv:     0x0000] [des: DMIX SNR Start Set Register] */
    unsigned grp207_reserved_0;                       /* <25> */
    unsigned grp207_reserved_1;                       /* <26> */
    unsigned grp207_reserved_2;                       /* <27> */
    unsigned grp207_reserved_3;                       /* <28> */
    unsigned grp207_reserved_4;                       /* <29> */
    unsigned grp207_reserved_5;                       /* <30> */
    unsigned grp207_reserved_6;                       /* <31> */
    // GROUP 208 [dmix_0_display_mixer_0]
    unsigned dmix_0_config_1;                         /* < 0> [dv:     0x0006] [des: DMIX_0 Config Register] */
    unsigned reserved_0_41;                           /* < 1> [dv:     0x0000] [des: Reserved Register] */
    unsigned reserved_1_37;                           /* < 2> [dv:     0x0000] [des: Reserved Register] */
    unsigned reserved_2_32;                           /* < 3> [dv:     0x0000] [des: Reserved Register] */
    unsigned dmix_0_yc_adjust_1;                      /* < 4> [dv:     0x0000] [des: DMIX_0 YC Adjust Register] */
    unsigned dmix_0_luma_cp1_1;                       /* < 5> [dv:     0x0000] [des: DMIX_0 Luma Adjust Control Point 1 Register] */
    unsigned dmix_0_luma_cp2_1;                       /* < 6> [dv:     0x5060] [des: DMIX_0 Luma Adjust Control Point 2 Register] */
    unsigned dmix_0_luma_cp3_1;                       /* < 7> [dv:     0xB0A0] [des: DMIX_0 Luma Adjust Control Point 3 Register] */
    unsigned dmix_0_luma_slope0_1;                    /* < 8> [dv:     0x0100] [des: DMIX_0 Luma Adjust Slope 0 Register] */
    unsigned dmix_0_luma_slope1_1;                    /* < 9> [dv:     0x00D5] [des: DMIX_0 Luma Adjust Slope 1 Register] */
    unsigned dmix_0_luma_slope2_1;                    /* <10> [dv:     0x0180] [des: DMIX_0 Luma Adjust Slope 2 Register] */
    unsigned dmix_0_luma_slope3_1;                    /* <11> [dv:     0x00D5] [des: DMIX_0 Luma Adjust Slope 3 Register] */
    unsigned dmix_0_chroma_satcos_1;                  /* <12> [dv:     0x0200] [des: DMIX_0 Chroma Adjust SATCOS Register] */
    unsigned dmix_0_chroma_satsin_1;                  /* <13> [dv:     0x0000] [des: DMIX_0 Chroma Adjust SATSIN Register] */
    unsigned dmix_0_checksum_setting_1;               /* <14> [dv:     0x0001] [des: DMIX_0 CHECK SUM SETTING] */
    unsigned dmix_0_chksum_usermode_v_1;              /* <15> [dv:     0x01e0] [des: DMIX_0 CHECK SUM USER MODE V active] */
    unsigned dmix_0_chksum_usermode_h_1;              /* <16> [dv:     0x02d0] [des: DMIX_0 CHECK SUM USER MODE H active] */
    unsigned dmix_0_chksum_usermode_start_line_1;     /* <17> [dv:     0x0024] [des: DMIX_0 CHECK SUM USER MODE V start line] */
    unsigned dmix_0_to_venc_chksum_1;                 /* <18> [dv:        0x0] [des: DMIX_0 TO VENC CHECK SUM] */
    unsigned dmix_0_to_hd2sd_chksum_1;                /* <19> [dv:        0x0] [des: DMIX_0 TO hd2sd CHECK SUM] */
    unsigned dmix_0_fgc_y_alpha_1;                    /* <20> [dv:     0x0010] [des: DMIX_0 Frontground Color Y and alpha Register] */
    unsigned dmix_0_fgc_c_1;                          /* <21> [dv:     0x8080] [des: DMIX_0 Frontground Color C Register] */
    unsigned dmix_0_pix_en_sel_1;                     /* <22> [dv:        0x0] [des: DMIX_0 PIX_EN SEL] */
    unsigned dmix_snr_set_1;                          /* <23> [dv:     0x0000] [des: DMIX SNR Set Register] */
    unsigned dmix_snr_start_set_1;                    /* <24> [dv:     0x0000] [des: DMIX SNR Start Set Register] */
    unsigned grp208_reserved_0;                       /* <25> */
    unsigned grp208_reserved_1;                       /* <26> */
    unsigned grp208_reserved_2;                       /* <27> */
    unsigned grp208_reserved_3;                       /* <28> */
    unsigned grp208_reserved_4;                       /* <29> */
    unsigned grp208_reserved_5;                       /* <30> */
    unsigned grp208_reserved_6;                       /* <31> */
    // GROUP 209 [venc_g1_for_sd]
    unsigned tv_mode_0;                               /* < 0> [dv:     0xB081] [des: SD common control register (1/13)] */
    unsigned tv_mode_1;                               /* < 1> [dv:     0xAC00] [des: SD common control register (2/13)] */
    unsigned tv_mode_2;                               /* < 2> [dv:     0x1000] [des: SD common control register (3/13)] */
    unsigned tv_mode_3;                               /* < 3> [dv:     0x2400] [des: SD common control register (4/13)] */
    unsigned tv_mode_4;                               /* < 4> [dv:     0x303F] [des: SD common control register (5/13)] */
    unsigned tv_mode_5;                               /* < 5> [dv:     0x000F] [des: SD common control register (6/13)] */
    unsigned tv_subc_f_0;                             /* < 6> [dv:     0x8ACB] [des: Subcarrier frequency register (1/2)] */
    unsigned tv_subc_f_1;                             /* < 7> [dv:     0x2A09] [des: Subcarrier frequency register (2/2)] */
    unsigned tv_subc_p;                               /* < 8> [dv:     0x0000] [des: Subcarrier frequency phase offset register] */
    unsigned tv_line_t_0;                             /* < 9> [dv:     0x0000] [des: Closed caption and Teletext, Line of Top filed register (1/2)] */
    unsigned tv_line_t_1;                             /* <10> [dv:     0x0000] [des: Closed caption and Teletext, Line of Top filed register (2/2)] */
    unsigned tv_line_b_0;                             /* <11> [dv:     0x0000] [des: Closed caption and Teletext, Line of Bottom field register (1/2)] */
    unsigned tv_line_b_1;                             /* <12> [dv:     0x0000] [des: Closed caption and Teletext, Line of Bottom field register (2/2)] */
    unsigned tv_cc_t;                                 /* <13> [dv:     0x0000] [des: Closed caption, Data register for Top field] */
    unsigned tv_cc_b;                                 /* <14> [dv:     0x0000] [des: Closed caption, Data register for Bottom field] */
    unsigned tv_cgms_0;                               /* <15> [dv:     0x0000] [des: CGMS/WSS, Data register (1/2)] */
    unsigned tv_cgms_1;                               /* <16> [dv:     0x0000] [des: CGMS/WSS, Data register (2/2)] */
    unsigned tv_id_status;                            /* <17> [dv:     0x1410] [des: Check status register of CGMS/WSS/CC/ASFIFO] */
    unsigned tv_dac;                                  /* <18> [dv:     0x0000] [des: DAC output current setup register (1/2)] */
    unsigned g209_reserved_19;                        /* <19> [dv:     0x0000] [des: Reserved Register] */
    unsigned macro0;                                  /* <20> [dv:     0x00DA] [des: Macrovision register 0] */
    unsigned macro1;                                  /* <21> [dv:     0x4512] [des: Macrovision register 1] */
    unsigned macro2;                                  /* <22> [dv:     0x2A87] [des: Macrovision register 2] */
    unsigned macro3;                                  /* <23> [dv:     0x3D50] [des: Macrovision register 3] */
    unsigned macro4;                                  /* <24> [dv:     0x1FF0] [des: Macrovision register 4] */
    unsigned macro5;                                  /* <25> [dv:     0x154F] [des: Macrovision register 5] */
    unsigned macro6;                                  /* <26> [dv:     0xE7E6] [des: Macrovision register 6] */
    unsigned macro7;                                  /* <27> [dv:     0x0402] [des: Macrovision register 7] */
    unsigned macro8;                                  /* <28> [dv:     0x7260] [des: Macrovision register 8] */
    unsigned g209_reserved_29;                        /* <29> [dv:     0x0000] [des: Reserved Register] */
    unsigned g209_reserved_30;                        /* <30> [dv:     0x0000] [des: Reserved Register] */
    unsigned macro9;                                  /* <31> [dv:     0x0000] [des: Macrovision register 9] */
    // GROUP 210 [venc_g2_for_sd]
    unsigned g210_reserved_0;                         /* < 0> [dv:     0x0000] [des: Reserved register] */
    unsigned g210_reserved_1;                         /* < 1> [dv:     0x0000] [des: Reserved register] */
    unsigned g210_reserved_2;                         /* < 2> [dv:     0x0000] [des: Reserved register] */
    unsigned g210_reserved_3;                         /* < 3> [dv:     0x0000] [des: Reserved register] */
    unsigned g210_reserved_4;                         /* < 4> [dv:     0x0000] [des: Reserved register] */
    unsigned tv_pccon_0;                              /* < 5> [dv:     0x0018] [des: PC or panel's AC timing setup (1/18)] */
    unsigned tv_pccon_1;                              /* < 6> [dv:     0x005C] [des: PC or panel's AC timing setup (2/18)] */
    unsigned tv_pccon_2;                              /* < 7> [dv:     0x0018] [des: PC or panel's AC timing setup (3/18)] */
    unsigned tv_pccon_3;                              /* < 8> [dv:     0x005C] [des: PC or panel's AC timing setup (4/18)] */
    unsigned tv_pccon_4;                              /* < 9> [dv:     0x0018] [des: Pixel Number of End of Left Bar (lower 8 bits)] */
    unsigned tv_pccon_5;                              /* <10> [dv:     0x005C] [des: Pixel Number of End of Left Bar (higher 8 bits)] */
    unsigned tv_pccon_6;                              /* <11> [dv:     0x0001] [des: PC or panel's AC timing setup (7/18)] */
    unsigned tv_pccon_7;                              /* <12> [dv:     0x0004] [des: PC or panel's AC timing setup (8/18)] */
    unsigned g210_reserved_13;                        /* <13> [dv:     0x0000] [des: Reserved register] */
    unsigned g210_reserved_14;                        /* <14> [dv:     0x0000] [des: Reserved register] */
    unsigned tv_pccon_10;                             /* <15> [dv:     0x0274] [des: PC or panel's AC timing setup (11/18)] */
    unsigned tv_pccon_11;                             /* <16> [dv:     0x0274] [des: PC or panel's AC timing setup (12/18)] */
    unsigned tv_pccon_12;                             /* <17> [dv:     0x001B] [des: PC or panel's AC timing setup (13/18)] */
    unsigned tv_pccon_13;                             /* <18> [dv:     0x0420] [des: PC or panel's AC timing setup (14/18)] */
    unsigned tv_pccon_14;                             /* <19> [dv:     0x0320] [des: PC or panel's AC timing setup (15/18)] */
    unsigned tv_pccon_15;                             /* <20> [dv:     0x0095] [des: PC or panel's AC timing setup (16/18)] */
    unsigned tv_pccon_16;                             /* <21> [dv:     0X005A] [des: PC or panel's AC timing setup (17/18)] */
    unsigned tv_pccon_17;                             /* <22> [dv:     0x0080] [des: PC or panel's AC timing setup (18/18)] */
    unsigned tv_pccon_18;                             /* <23> [dv:     0x0001] [des: PC(CH-B) misc. setup] */
    unsigned g210_reserved_24;                        /* <24> [dv:     0x0000] [des: Reserved register] */
    unsigned tv_temp1_g1;                             /* <25> [dv:     0x0000] [des: DAC Adaptive LPF Register] */
    unsigned tv_dac_checksum;                         /* <26> [dv:     0x0000] [des: DAC check sum register] */
    unsigned tv_mode5;                                /* <27> [dv:     0x00BF] [des: SD common control register (7/13)] */
    unsigned tv_mode6;                                /* <28> [dv:     0x0000] [des: SD common control register (8/13)] */
    unsigned tv_mode7;                                /* <29> [dv:     0x0000] [des: SD common control register (9/13)] */
    unsigned g210_reserved_30;                        /* <30> [dv:     0x0000] [des: Reserved register] */
    unsigned g210_reserved_31;                        /* <31> [dv:     0x0000] [des: Reserved register] */
    // GROUP 211 [venc_g3_for_sd]
    unsigned tv2_mode0;                               /* < 0> [dv:     0x0248] [des: SD common control register (10/13)] */
    unsigned rg_scm_adj;                              /* < 1> [dv:     0x0000] [des: SECAM_adjust register] */
    unsigned luma_adj_cp1;                            /* < 2> [dv:     0x0000] [des: Luma Adjust Control Point 1 Register] */
    unsigned luma_adj_cp2;                            /* < 3> [dv:     0x5060] [des: Luma Adjust Control Point 2 Register] */
    unsigned luma_adj_cp3;                            /* < 4> [dv:     0xb0a0] [des: Luma Adjust Control Point 1 Register] */
    unsigned probe_cfg;                               /* < 5> [dv:     0x0000] [des: probe control] */
    unsigned g211_reserved_6;                         /* < 6> [dv:     0x0000] [des: Reserved register] */
    unsigned tv2_wc_tline;                            /* < 7> [dv:     0x0017] [des: CGMS/WSS, Line of Top field register] */
    unsigned tv2_wc_bline;                            /* < 8> [dv:     0x0150] [des: CGMS/WSS, Line of Bottom field register] */
    unsigned tv2_wc_psline;                           /* < 9> [dv:     0x0023] [des: CGMS/WSS, Line of non-interlace scan register] */
    unsigned tv2_mode1;                               /* <10> [dv:     0x3A28] [des: SD common control register (11/13)] */
    unsigned tv2_mode2;                               /* <11> [dv:     0x80E4] [des: SD common control register (12/13)] */
    unsigned tv2_mode3;                               /* <12> [dv:     0x8200] [des: SD common control register (13/13)] */
    unsigned tv2_y_range;                             /* <13> [dv:     0xEB10] [des: Value limiter of Luma] */
    unsigned tv2_c_range;                             /* <14> [dv:     0xF010] [des: Value limiter of Chroma] */
    unsigned tv2_cgmsb_0;                             /* <15> [dv:     0x0000] [des: Type-B CGMS data 0] */
    unsigned tv2_cgmsb_1;                             /* <16> [dv:     0x0000] [des: Type-B CGMS data 1] */
    unsigned tv2_cgmsb_2;                             /* <17> [dv:     0x0000] [des: Type-B CGMS data 2] */
    unsigned tv2_cgmsb_3;                             /* <18> [dv:     0x0000] [des: Type-B CGMS data 3] */
    unsigned tv2_vpd_mode0;                           /* <19> [dv:     0x0056] [des: [VPD] Video Power Down control register 1/3] */
    unsigned tv2_vpd_mode1;                           /* <20> [dv:     0x0080] [des: [VPD] Video Power Down control register 2/3] */
    unsigned tv2_vpd_thd;                             /* <21> [dv:     0x0800] [des: [VPD] Manual compared threshold (pixel)] */
    unsigned tv2_vpd_stline;                          /* <22> [dv:     0x026D] [des: [VPD] Manual Compared Start Line Number] */
    unsigned tv2_vpd_edline;                          /* <23> [dv:     0x0001] [des: [VPD] Manual compared end line number] */
    unsigned tv2_vpd_vldcnt;                          /* <24> [dv:     0x0000] [des: [VPD] Report detected valid pixel counter (pixel)] */
    unsigned tv2_vpd_mode2;                           /* <25> [dv:     0x0F17] [des: [VPD] Video Power Down control register 3/3] */
    unsigned pc_rgb_sog_cfg;                          /* <26> [dv:     0x0000] [des: Progressive Sync on Green register] */
    unsigned tv_hd2sd_pnt;                            /* <27> [dv:     0x0000] [des: PC or panel's AC timing setup ( 20/20 )] */
    unsigned luma_adj_slope0;                         /* <28> [dv:     0x0100] [des: Luma Adjust Slope 0 Register] */
    unsigned luma_adj_slope1;                         /* <29> [dv:     0x00d5] [des: Luma Adjust Slope 1 Register] */
    unsigned luma_adj_slope2;                         /* <30> [dv:     0x0180] [des: Luma Adjust Slope 2 Register] */
    unsigned luma_adj_slope3;                         /* <31> [dv:     0x00d5] [des: Luma Adjust Slope 3 Register] */
    // GROUP 212
    unsigned grp212_reserved[32];
    // GROUP 213 [osd0_g0]
    unsigned osd_ctrl;                                /* < 0> [dv:       0x20] [des: OSD Control Register] */
    unsigned osd_en;                                  /* < 1> [dv:          0] [des: OSD Enable] */
    unsigned osd_tlink_addr_l;                        /* < 2> [dv:     0xffe0] [des: OSD Top Link Register Low] */
    unsigned osd_tlink_addr_h;                        /* < 3> [dv:     0xffff] [des: OSD Top Link Register High] */
    unsigned osd_xstart;                              /* < 4> [dv:        0xe] [des: osd horizontal start position] */
    unsigned osd_ystart;                              /* < 5> [dv:       0x25] [des: osd vertical start position] */
    unsigned osd_reserved_2;                          /* < 6> [dv:        0x0] [des: ] */
    unsigned osd_reserved_3;                          /* < 7> [dv:        0x0] [des: ] */
    unsigned osd_req_ctrl;                            /* < 8> [dv:     0x8010] [des: OSD Request Control Register] */
    unsigned osd_reserved_4;                          /* < 9> [dv:        0x0] [des: ] */
    unsigned osd_vexp_step;                           /* <10> [dv:      0x200] [des: OSD Scaler Vertical Factor] */
    unsigned osd_hexp_step;                           /* <11> [dv:      0x200] [des: OSD Scaler Horizontal Factor] */
    unsigned osd_reserved_4_1;                        /* <12> [dv:        0x0] [des: ] */
    unsigned osd_reserved_5;                          /* <13> [dv:        0x0] [des: reserved] */
    unsigned osd_crc_chksum;                          /* <14> [dv:          0] [des: OSD field-updated CRC Checksum] */
    unsigned osd_status;                              /* <15> [dv:          0] [des: OSD Status Register] */
    unsigned osd_hvld_offset;                         /* <16> [dv:          0] [des:  Horizontal offset index ] */
    unsigned osd_hvld_width;                          /* <17> [dv:      0x2D0] [des:  Horizon valid pixel number ] */
    unsigned osd_vvld_offset;                         /* <18> [dv:          0] [des:  Vertical offset index ] */
    unsigned osd_vvld_height;                         /* <19> [dv:      0x1E0] [des:  Vertical valid line nubmer ] */
    unsigned osd_data_fetch_ctrl;                     /* <20> [dv:     0xff40] [des:  Memory Data Fetch Control] */
    unsigned osd_bist_ctrl;                           /* <21> [dv:        0x0] [des: BIST Pattern] */
    unsigned osd_vexp_init;                           /* <22> [dv:        0x0] [des: OSD Scaler Vertical Initial Phase] */
    unsigned osd_hexp_init;                           /* <23> [dv:        0x0] [des: OSD Scaler Horizontal Initial Phase] */
    unsigned osd_vexp_step_ext;                       /* <24> [dv:        0x0] [des: OSD Scaler Vertical Factor Extension] */
    unsigned osd_hexp_step_ext;                       /* <25> [dv:        0x0] [des: OSD Scaler Horizontal Factor Extension] */
    unsigned osd_hexp_flt_sel;                        /* <26> [dv:        0x8] [des: OSD hexp interpolation method selection] */
    unsigned osd_3d_h_offset;                         /* <27> [dv:        0x0] [des: OSD 3D h offset] */
    unsigned osd_vexp_flt_sel;                        /* <28> [dv:     0x0000] [des: OSD vexp interpolation method selection] */
    unsigned osd_src_decimation_sel;                  /* <29> [dv:        0x0] [des: SRC decimation selection] */
    unsigned osd_lb_info;                             /* <30> [dv:        0x0] [des: ] */
    unsigned osd_mbus_info;                           /* <31> [dv:        0x0] [des: ] */
    // GROUP 214 [osd1_g0]
    unsigned osd_ctrl_1;                              /* < 0> [dv:       0x20] [des: OSD Control Register] */
    unsigned osd_en_1;                                /* < 1> [dv:          0] [des: OSD Enable] */
    unsigned osd_tlink_addr_l_1;                      /* < 2> [dv:     0xffe0] [des: OSD Top Link Register Low] */
    unsigned osd_tlink_addr_h_1;                      /* < 3> [dv:     0xffff] [des: OSD Top Link Register High] */
    unsigned osd_xstart_1;                            /* < 4> [dv:        0xe] [des: osd horizontal start position] */
    unsigned osd_ystart_1;                            /* < 5> [dv:       0x25] [des: osd vertical start position] */
    unsigned osd_reserved_2_1;                        /* < 6> [dv:        0x0] [des: ] */
    unsigned osd_reserved_3_1;                        /* < 7> [dv:        0x0] [des: ] */
    unsigned osd_req_ctrl_1;                          /* < 8> [dv:     0x8010] [des: OSD Request Control Register] */
    unsigned osd_reserved_4_2;                        /* < 9> [dv:        0x0] [des: ] */
    unsigned osd_vexp_step_1;                         /* <10> [dv:      0x200] [des: OSD Scaler Vertical Factor] */
    unsigned osd_hexp_step_1;                         /* <11> [dv:      0x200] [des: OSD Scaler Horizontal Factor] */
    unsigned osd_reserved_4_3;                        /* <12> [dv:        0x0] [des: ] */
    unsigned osd_reserved_5_1;                        /* <13> [dv:        0x0] [des: reserved] */
    unsigned osd_crc_chksum_1;                        /* <14> [dv:          0] [des: OSD field-updated CRC Checksum] */
    unsigned osd_status_1;                            /* <15> [dv:          0] [des: OSD Status Register] */
    unsigned osd_hvld_offset_1;                       /* <16> [dv:          0] [des:  Horizontal offset index ] */
    unsigned osd_hvld_width_1;                        /* <17> [dv:      0x2D0] [des:  Horizon valid pixel number ] */
    unsigned osd_vvld_offset_1;                       /* <18> [dv:          0] [des:  Vertical offset index ] */
    unsigned osd_vvld_height_1;                       /* <19> [dv:      0x1E0] [des:  Vertical valid line nubmer ] */
    unsigned osd_data_fetch_ctrl_1;                   /* <20> [dv:     0xff40] [des:  Memory Data Fetch Control] */
    unsigned osd_bist_ctrl_1;                         /* <21> [dv:        0x0] [des: BIST Pattern] */
    unsigned osd_vexp_init_1;                         /* <22> [dv:        0x0] [des: OSD Scaler Vertical Initial Phase] */
    unsigned osd_hexp_init_1;                         /* <23> [dv:        0x0] [des: OSD Scaler Horizontal Initial Phase] */
    unsigned osd_vexp_step_ext_1;                     /* <24> [dv:        0x0] [des: OSD Scaler Vertical Factor Extension] */
    unsigned osd_hexp_step_ext_1;                     /* <25> [dv:        0x0] [des: OSD Scaler Horizontal Factor Extension] */
    unsigned osd_hexp_flt_sel_1;                      /* <26> [dv:        0x8] [des: OSD hexp interpolation method selection] */
    unsigned osd_3d_h_offset_1;                       /* <27> [dv:        0x0] [des: OSD 3D h offset] */
    unsigned osd_vexp_flt_sel_1;                      /* <28> [dv:     0x0000] [des: OSD vexp interpolation method selection] */
    unsigned osd_src_decimation_sel_1;                /* <29> [dv:        0x0] [des: SRC decimation selection] */
    unsigned osd_lb_info_1;                           /* <30> [dv:        0x0] [des: ] */
    unsigned osd_mbus_info_1;                         /* <31> [dv:        0x0] [des: ] */
    // GROUP 215 [osd2_g0]
    unsigned osd_ctrl_2;                              /* < 0> [dv:       0x20] [des: OSD Control Register] */
    unsigned osd_en_2;                                /* < 1> [dv:          0] [des: OSD Enable] */
    unsigned osd_tlink_addr_l_2;                      /* < 2> [dv:     0xffe0] [des: OSD Top Link Register Low] */
    unsigned osd_tlink_addr_h_2;                      /* < 3> [dv:     0xffff] [des: OSD Top Link Register High] */
    unsigned osd_xstart_2;                            /* < 4> [dv:        0xe] [des: osd horizontal start position] */
    unsigned osd_ystart_2;                            /* < 5> [dv:       0x25] [des: osd vertical start position] */
    unsigned osd_reserved_2_2;                        /* < 6> [dv:        0x0] [des: ] */
    unsigned osd_reserved_3_2;                        /* < 7> [dv:        0x0] [des: ] */
    unsigned osd_req_ctrl_2;                          /* < 8> [dv:     0x8010] [des: OSD Request Control Register] */
    unsigned osd_reserved_4_4;                        /* < 9> [dv:        0x0] [des: ] */
    unsigned osd_vexp_step_2;                         /* <10> [dv:      0x200] [des: OSD Scaler Vertical Factor] */
    unsigned osd_hexp_step_2;                         /* <11> [dv:      0x200] [des: OSD Scaler Horizontal Factor] */
    unsigned osd_reserved_4_5;                        /* <12> [dv:        0x0] [des: ] */
    unsigned osd_reserved_5_2;                        /* <13> [dv:        0x0] [des: reserved] */
    unsigned osd_crc_chksum_2;                        /* <14> [dv:          0] [des: OSD field-updated CRC Checksum] */
    unsigned osd_status_2;                            /* <15> [dv:          0] [des: OSD Status Register] */
    unsigned osd_hvld_offset_2;                       /* <16> [dv:          0] [des:  Horizontal offset index ] */
    unsigned osd_hvld_width_2;                        /* <17> [dv:      0x2D0] [des:  Horizon valid pixel number ] */
    unsigned osd_vvld_offset_2;                       /* <18> [dv:          0] [des:  Vertical offset index ] */
    unsigned osd_vvld_height_2;                       /* <19> [dv:      0x1E0] [des:  Vertical valid line nubmer ] */
    unsigned osd_data_fetch_ctrl_2;                   /* <20> [dv:     0xff40] [des:  Memory Data Fetch Control] */
    unsigned osd_bist_ctrl_2;                         /* <21> [dv:        0x0] [des: BIST Pattern] */
    unsigned osd_vexp_init_2;                         /* <22> [dv:        0x0] [des: OSD Scaler Vertical Initial Phase] */
    unsigned osd_hexp_init_2;                         /* <23> [dv:        0x0] [des: OSD Scaler Horizontal Initial Phase] */
    unsigned osd_vexp_step_ext_2;                     /* <24> [dv:        0x0] [des: OSD Scaler Vertical Factor Extension] */
    unsigned osd_hexp_step_ext_2;                     /* <25> [dv:        0x0] [des: OSD Scaler Horizontal Factor Extension] */
    unsigned osd_hexp_flt_sel_2;                      /* <26> [dv:        0x8] [des: OSD hexp interpolation method selection] */
    unsigned osd_3d_h_offset_2;                       /* <27> [dv:        0x0] [des: OSD 3D h offset] */
    unsigned osd_vexp_flt_sel_2;                      /* <28> [dv:     0x0000] [des: OSD vexp interpolation method selection] */
    unsigned osd_src_decimation_sel_2;                /* <29> [dv:        0x0] [des: SRC decimation selection] */
    unsigned osd_lb_info_2;                           /* <30> [dv:        0x0] [des: ] */
    unsigned osd_mbus_info_2;                         /* <31> [dv:        0x0] [des: ] */
    // GROUP 216 [gscl0_g0_graphic_scaler_group_0]
    unsigned gscl0_config1;                           /* < 0> [dv:     0x0000] [des: GSCL0 Config1 Register] */
    unsigned gscl0_config2;                           /* < 1> [dv:     0x0000] [des: GSCL0 Config2 Register] */
    unsigned new_alpha_protect;                       /* < 2> [dv:     0x0000] [des: ] */
    unsigned reserved_0_42;                           /* < 3> [dv:     0x0000] [des: reserved_3] */
    unsigned gscl0_actrl_i_xlen;                      /* < 4> [dv:     0x0000] [des: ACTRL Input Pixel Register] */
    unsigned gscl0_actrl_i_ylen;                      /* < 5> [dv:     0x0000] [des: ACTRL Input Line Register] */
    unsigned gscl0_actrl_s_xstart;                    /* < 6> [dv:     0x0000] [des: ACTRL start pixel of crop frame] */
    unsigned gscl0_actrl_s_ystart;                    /* < 7> [dv:     0x0000] [des: ACTRL start line of crop frame] */
    unsigned gscl0_actrl_s_xlen;                      /* < 8> [dv:     0x0000] [des: ACTRL Output Pixel Register] */
    unsigned gscl0_actrl_s_ylen;                      /* < 9> [dv:     0x0000] [des: ACTRL Output Line Register] */
    unsigned gscl0_dctrl_o_xlen;                      /* <10> [dv:     0x0000] [des: DCTRL Output Active Pixel Register] */
    unsigned gscl0_dctrl_o_ylen;                      /* <11> [dv:     0x0000] [des: DCTRL Output Active Line Register] */
    unsigned gscl0_dctrl_d_xstart;                    /* <12> [dv:     0x0000] [des: DCTRL Output Active Start Pixel Register] */
    unsigned gscl0_dctrl_d_ystart;                    /* <13> [dv:     0x0000] [des: DCTRL Output Active Start Line Register] */
    unsigned gscl0_dctrl_d_xlen;                      /* <14> [dv:     0x0000] [des: DCTRL Input Pixel Register] */
    unsigned gscl0_dctrl_d_ylen;                      /* <15> [dv:     0x0000] [des: DCTRL Input Line Register] */
    unsigned gscl0_dctrl_bgc_c;                       /* <16> [dv:     0x8080] [des: DCTRL Background Color Chroma Register] */
    unsigned gscl0_dctrl_bgc_y;                       /* <17> [dv:     0x0010] [des: DCTRL Background Color Luma Register] */
    unsigned reserved_1_38;                           /* <18> [dv:     0x0000] [des: reserved_18] */
    unsigned gscl0_hint_ctrl;                         /* <19> [dv:     0x0000] [des: HINT Control Register] */
    unsigned gscl0_hint_hfactor_low;                  /* <20> [dv:     0x0000] [des: HINT Scaling Factor Low Register] */
    unsigned gscl0_hint_hfactor_high;                 /* <21> [dv:     0x0000] [des: HINT Scaling Factor High Register] */
    unsigned gscl0_hint_initf_low;                    /* <22> [dv:     0x0000] [des: HINT Initial Phase Low Register] */
    unsigned gscl0_hint_initf_high;                   /* <23> [dv:     0x0000] [des: HINT Initial Phase High Register] */
    unsigned gscl0_hint_overshoot;                    /* <24> [dv:     0x0000] [des: HINT Overshoot Register] */
    unsigned reserved_2_33;                           /* <25> [dv:     0x0000] [des: Reserved Register] */
    unsigned gscl0_vint_ctrl;                         /* <26> [dv:     0x0000] [des: VINT Control Register] */
    unsigned gscl0_vint_vfactor_low;                  /* <27> [dv:     0x0000] [des: VINT Scaling Factor Low Register] */
    unsigned gscl0_vint_vfactor_high;                 /* <28> [dv:     0x0000] [des: VINT Scaling Factor High Register] */
    unsigned gscl0_vint_initf_low;                    /* <29> [dv:     0x0000] [des: VINT Initial Phase Low Register] */
    unsigned gscl0_vint_initf_high;                   /* <30> [dv:     0x0000] [des: VINT Initial Phase High Register] */
    unsigned grp216_reserved_0;                       /* <31> */
    // GROUP 217 [gscl0_g1_graphic_scaler_group_1]
    unsigned gscl0_vimg_ctrl;                         /* < 0> [dv:     0x0000] [des: GSCL0 VIMG Control Register] */
    unsigned gscl0_vimg_vpeak_lut_1;                  /* < 1> [dv:     0x0000] [des: VIMG VPEAK Gain LUT Register 1] */
    unsigned gscl0_vimg_vpeak_lut_2;                  /* < 2> [dv:     0x0000] [des: VIMG VPEAK Gain LUT Register 2] */
    unsigned gscl0_vimg_vpeak_lut_3;                  /* < 3> [dv:     0x0000] [des: VIMG VPEAK Gain LUT Register 3] */
    unsigned gscl0_vimg_vpeak_lut_4;                  /* < 4> [dv:     0x0000] [des: VIMG VPEAK Gain LUT Register 4] */
    unsigned gscl0_vimg_vpeak_lut_5;                  /* < 5> [dv:     0x0000] [des: VIMG VPEAK Gain LUT Register 5] */
    unsigned gscl0_vimg_vpeak_lut_6;                  /* < 6> [dv:     0x0000] [des: VIMG VPEAK Gain LUT Register 6] */
    unsigned gscl0_vimg_vpeak_config;                 /* < 7> [dv:     0x0000] [des: VIMG VPEAK Config Register] */
    unsigned gscl0_vimg_diag_config_1;                /* < 8> [dv:     0x0000] [des: VIMG Diagonal Filter Config Register 1] */
    unsigned gscl0_vimg_diag_config_2;                /* < 9> [dv:     0x0000] [des: VIMG Diagonal Filter Config Register 2] */
    unsigned reserved_0_43;                           /* <10> [dv:     0x0000] [des: Reserved Register] */
    unsigned gscl0_checksum_select;                   /* <11> [dv:     0x0000] [des: Checksum select Register] */
    unsigned gscl0_checksum_result;                   /* <12> [dv:     0x0000] [des: Checksum Rrsult Register] */
    unsigned reserved_1_39;                           /* <13> [dv:     0x0000] [des: Reserved Register] */
    unsigned gscl0_debug_info;                        /* <14> [dv:     0x0001] [des: Debug Info Register] */
    unsigned reserved_2_34;                           /* <15> [dv:     0x0000] [des: Reserved Register] */
    unsigned gscl0_dr_ctrl;                           /* <16> [dv:     0x0000] [des: Dering control signal] */
    unsigned gscl0_dr_dege_detect1;                   /* <17> [dv:     0x0000] [des: Dering edge detection relative] */
    unsigned gscl0_dr_dege_detect2;                   /* <18> [dv:     0x0000] [des: Dering edge detection relative] */
    unsigned gscl0_dr_clamp_detect;                   /* <19> [dv:     0x0000] [des: Dering clamp value relative] */
    unsigned grp217_reserved_0;                       /* <20> */
    unsigned grp217_reserved_1;                       /* <21> */
    unsigned grp217_reserved_2;                       /* <22> */
    unsigned grp217_reserved_3;                       /* <23> */
    unsigned grp217_reserved_4;                       /* <24> */
    unsigned grp217_reserved_5;                       /* <25> */
    unsigned grp217_reserved_6;                       /* <26> */
    unsigned grp217_reserved_7;                       /* <27> */
    unsigned grp217_reserved_8;                       /* <28> */
    unsigned grp217_reserved_9;                       /* <29> */
    unsigned grp217_reserved_10;                      /* <30> */
    unsigned grp217_reserved_11;                      /* <31> */
    // GROUP 218 [gscl1_g0_graphic_scaler_group_0]
    unsigned gscl1_config1;                           /* < 0> [dv:     0x0000] [des: GSCL1 Config1 Register] */
    unsigned gscl1_config2;                           /* < 1> [dv:     0x0000] [des: GSCL1 Config2 Register] */
    unsigned new_alpha_protect_1;                     /* < 2> [dv:     0x0000] [des: ] */
    unsigned reserved_0_44;                           /* < 3> [dv:     0x0000] [des: reserved_3] */
    unsigned gscl1_actrl_i_xlen;                      /* < 4> [dv:     0x0000] [des: ACTRL Input Pixel Register] */
    unsigned gscl1_actrl_i_ylen;                      /* < 5> [dv:     0x0000] [des: ACTRL Input Line Register] */
    unsigned gscl1_actrl_s_xstart;                    /* < 6> [dv:     0x0000] [des: ACTRL start pixel of crop frame] */
    unsigned gscl1_actrl_s_ystart;                    /* < 7> [dv:     0x0000] [des: ACTRL start line of crop frame] */
    unsigned gscl1_actrl_s_xlen;                      /* < 8> [dv:     0x0000] [des: ACTRL Output Pixel Register] */
    unsigned gscl1_actrl_s_ylen;                      /* < 9> [dv:     0x0000] [des: ACTRL Output Line Register] */
    unsigned gscl1_dctrl_o_xlen;                      /* <10> [dv:     0x0000] [des: DCTRL Output Active Pixel Register] */
    unsigned gscl1_dctrl_o_ylen;                      /* <11> [dv:     0x0000] [des: DCTRL Output Active Line Register] */
    unsigned gscl1_dctrl_d_xstart;                    /* <12> [dv:     0x0000] [des: DCTRL Output Active Start Pixel Register] */
    unsigned gscl1_dctrl_d_ystart;                    /* <13> [dv:     0x0000] [des: DCTRL Output Active Start Line Register] */
    unsigned gscl1_dctrl_d_xlen;                      /* <14> [dv:     0x0000] [des: DCTRL Input Pixel Register] */
    unsigned gscl1_dctrl_d_ylen;                      /* <15> [dv:     0x0000] [des: DCTRL Input Line Register] */
    unsigned gscl1_dctrl_bgc_c;                       /* <16> [dv:     0x8080] [des: DCTRL Background Color Chroma Register] */
    unsigned gscl1_dctrl_bgc_y;                       /* <17> [dv:     0x0010] [des: DCTRL Background Color Luma Register] */
    unsigned reserved_1_40;                           /* <18> [dv:     0x0000] [des: reserved_18] */
    unsigned gscl1_hint_ctrl;                         /* <19> [dv:     0x0000] [des: HINT Control Register] */
    unsigned gscl1_hint_hfactor_low;                  /* <20> [dv:     0x0000] [des: HINT Scaling Factor Low Register] */
    unsigned gscl1_hint_hfactor_high;                 /* <21> [dv:     0x0000] [des: HINT Scaling Factor High Register] */
    unsigned gscl1_hint_initf_low;                    /* <22> [dv:     0x0000] [des: HINT Initial Phase Low Register] */
    unsigned gscl1_hint_initf_high;                   /* <23> [dv:     0x0000] [des: HINT Initial Phase High Register] */
    unsigned gscl1_hint_overshoot;                    /* <24> [dv:     0x0000] [des: HINT Overshoot Register] */
    unsigned reserved_2_35;                           /* <25> [dv:     0x0000] [des: Reserved Register] */
    unsigned gscl1_vint_ctrl;                         /* <26> [dv:     0x0000] [des: VINT Control Register] */
    unsigned gscl1_vint_vfactor_low;                  /* <27> [dv:     0x0000] [des: VINT Scaling Factor Low Register] */
    unsigned gscl1_vint_vfactor_high;                 /* <28> [dv:     0x0000] [des: VINT Scaling Factor High Register] */
    unsigned gscl1_vint_initf_low;                    /* <29> [dv:     0x0000] [des: VINT Initial Phase Low Register] */
    unsigned gscl1_vint_initf_high;                   /* <30> [dv:     0x0000] [des: VINT Initial Phase High Register] */
    unsigned grp218_reserved_0;                       /* <31> */
    // GROUP 219 [gscl1_g1_graphic_scaler_group_1]
    unsigned gscl1_vimg_ctrl;                         /* < 0> [dv:     0x0000] [des: GSCL1 VIMG Control Register] */
    unsigned gscl1_vimg_vpeak_lut_1;                  /* < 1> [dv:     0x0000] [des: VIMG VPEAK Gain LUT Register 1] */
    unsigned gscl1_vimg_vpeak_lut_2;                  /* < 2> [dv:     0x0000] [des: VIMG VPEAK Gain LUT Register 2] */
    unsigned gscl1_vimg_vpeak_lut_3;                  /* < 3> [dv:     0x0000] [des: VIMG VPEAK Gain LUT Register 3] */
    unsigned gscl1_vimg_vpeak_lut_4;                  /* < 4> [dv:     0x0000] [des: VIMG VPEAK Gain LUT Register 4] */
    unsigned gscl1_vimg_vpeak_lut_5;                  /* < 5> [dv:     0x0000] [des: VIMG VPEAK Gain LUT Register 5] */
    unsigned gscl1_vimg_vpeak_lut_6;                  /* < 6> [dv:     0x0000] [des: VIMG VPEAK Gain LUT Register 6] */
    unsigned gscl1_vimg_vpeak_config;                 /* < 7> [dv:     0x0000] [des: VIMG VPEAK Config Register] */
    unsigned gscl1_vimg_diag_config_1;                /* < 8> [dv:     0x0000] [des: VIMG Diagonal Filter Config Register 1] */
    unsigned gscl1_vimg_diag_config_2;                /* < 9> [dv:     0x0000] [des: VIMG Diagonal Filter Config Register 2] */
    unsigned reserved_0_45;                           /* <10> [dv:     0x0000] [des: Reserved Register] */
    unsigned gscl1_checksum_select;                   /* <11> [dv:     0x0000] [des: Checksum select Register] */
    unsigned gscl1_checksum_result;                   /* <12> [dv:     0x0000] [des: Checksum Rrsult Register] */
    unsigned reserved_1_41;                           /* <13> [dv:     0x0000] [des: Reserved Register] */
    unsigned gscl1_debug_info;                        /* <14> [dv:     0x0001] [des: Debug Info Register] */
    unsigned reserved_2_36;                           /* <15> [dv:     0x0000] [des: Reserved Register] */
    unsigned gscl1_dr_ctrl;                           /* <16> [dv:     0x0000] [des: Dering control signal] */
    unsigned gscl1_dr_dege_detect1;                   /* <17> [dv:     0x0000] [des: Dering edge detection relative] */
    unsigned gscl1_dr_dege_detect2;                   /* <18> [dv:     0x0000] [des: Dering edge detection relative] */
    unsigned gscl1_dr_clamp_detect;                   /* <19> [dv:     0x0000] [des: Dering clamp value relative] */
    unsigned grp219_reserved_0;                       /* <20> */
    unsigned grp219_reserved_1;                       /* <21> */
    unsigned grp219_reserved_2;                       /* <22> */
    unsigned grp219_reserved_3;                       /* <23> */
    unsigned grp219_reserved_4;                       /* <24> */
    unsigned grp219_reserved_5;                       /* <25> */
    unsigned grp219_reserved_6;                       /* <26> */
    unsigned grp219_reserved_7;                       /* <27> */
    unsigned grp219_reserved_8;                       /* <28> */
    unsigned grp219_reserved_9;                       /* <29> */
    unsigned grp219_reserved_10;                      /* <30> */
    unsigned grp219_reserved_11;                      /* <31> */
    // GROUP 220 [gscl2_g0_graphic_scaler_group_0]
    unsigned gscl1_config1_1;                         /* < 0> [dv:     0x0000] [des: GSCL1 Config1 Register] */
    unsigned gscl1_config2_1;                         /* < 1> [dv:     0x0000] [des: GSCL1 Config2 Register] */
    unsigned new_alpha_protect_2;                     /* < 2> [dv:     0x0000] [des: ] */
    unsigned reserved_0_46;                           /* < 3> [dv:     0x0000] [des: reserved_3] */
    unsigned gscl1_actrl_i_xlen_1;                    /* < 4> [dv:     0x0000] [des: ACTRL Input Pixel Register] */
    unsigned gscl1_actrl_i_ylen_1;                    /* < 5> [dv:     0x0000] [des: ACTRL Input Line Register] */
    unsigned gscl1_actrl_s_xstart_1;                  /* < 6> [dv:     0x0000] [des: ACTRL start pixel of crop frame] */
    unsigned gscl1_actrl_s_ystart_1;                  /* < 7> [dv:     0x0000] [des: ACTRL start line of crop frame] */
    unsigned gscl1_actrl_s_xlen_1;                    /* < 8> [dv:     0x0000] [des: ACTRL Output Pixel Register] */
    unsigned gscl1_actrl_s_ylen_1;                    /* < 9> [dv:     0x0000] [des: ACTRL Output Line Register] */
    unsigned gscl1_dctrl_o_xlen_1;                    /* <10> [dv:     0x0000] [des: DCTRL Output Active Pixel Register] */
    unsigned gscl1_dctrl_o_ylen_1;                    /* <11> [dv:     0x0000] [des: DCTRL Output Active Line Register] */
    unsigned gscl1_dctrl_d_xstart_1;                  /* <12> [dv:     0x0000] [des: DCTRL Output Active Start Pixel Register] */
    unsigned gscl1_dctrl_d_ystart_1;                  /* <13> [dv:     0x0000] [des: DCTRL Output Active Start Line Register] */
    unsigned gscl1_dctrl_d_xlen_1;                    /* <14> [dv:     0x0000] [des: DCTRL Input Pixel Register] */
    unsigned gscl1_dctrl_d_ylen_1;                    /* <15> [dv:     0x0000] [des: DCTRL Input Line Register] */
    unsigned gscl1_dctrl_bgc_c_1;                     /* <16> [dv:     0x8080] [des: DCTRL Background Color Chroma Register] */
    unsigned gscl1_dctrl_bgc_y_1;                     /* <17> [dv:     0x0010] [des: DCTRL Background Color Luma Register] */
    unsigned reserved_1_42;                           /* <18> [dv:     0x0000] [des: reserved_18] */
    unsigned gscl1_hint_ctrl_1;                       /* <19> [dv:     0x0000] [des: HINT Control Register] */
    unsigned gscl1_hint_hfactor_low_1;                /* <20> [dv:     0x0000] [des: HINT Scaling Factor Low Register] */
    unsigned gscl1_hint_hfactor_high_1;               /* <21> [dv:     0x0000] [des: HINT Scaling Factor High Register] */
    unsigned gscl1_hint_initf_low_1;                  /* <22> [dv:     0x0000] [des: HINT Initial Phase Low Register] */
    unsigned gscl1_hint_initf_high_1;                 /* <23> [dv:     0x0000] [des: HINT Initial Phase High Register] */
    unsigned gscl1_hint_overshoot_1;                  /* <24> [dv:     0x0000] [des: HINT Overshoot Register] */
    unsigned reserved_2_37;                           /* <25> [dv:     0x0000] [des: Reserved Register] */
    unsigned gscl1_vint_ctrl_1;                       /* <26> [dv:     0x0000] [des: VINT Control Register] */
    unsigned gscl1_vint_vfactor_low_1;                /* <27> [dv:     0x0000] [des: VINT Scaling Factor Low Register] */
    unsigned gscl1_vint_vfactor_high_1;               /* <28> [dv:     0x0000] [des: VINT Scaling Factor High Register] */
    unsigned gscl1_vint_initf_low_1;                  /* <29> [dv:     0x0000] [des: VINT Initial Phase Low Register] */
    unsigned gscl1_vint_initf_high_1;                 /* <30> [dv:     0x0000] [des: VINT Initial Phase High Register] */
    unsigned grp220_reserved_0;                       /* <31> */
    // GROUP 221 [gscl2_g1_graphic_scaler_group_1]
    unsigned gscl1_vimg_ctrl_1;                       /* < 0> [dv:     0x0000] [des: GSCL1 VIMG Control Register] */
    unsigned gscl1_vimg_vpeak_lut_1_1;                /* < 1> [dv:     0x0000] [des: VIMG VPEAK Gain LUT Register 1] */
    unsigned gscl1_vimg_vpeak_lut_2_1;                /* < 2> [dv:     0x0000] [des: VIMG VPEAK Gain LUT Register 2] */
    unsigned gscl1_vimg_vpeak_lut_3_1;                /* < 3> [dv:     0x0000] [des: VIMG VPEAK Gain LUT Register 3] */
    unsigned gscl1_vimg_vpeak_lut_4_1;                /* < 4> [dv:     0x0000] [des: VIMG VPEAK Gain LUT Register 4] */
    unsigned gscl1_vimg_vpeak_lut_5_1;                /* < 5> [dv:     0x0000] [des: VIMG VPEAK Gain LUT Register 5] */
    unsigned gscl1_vimg_vpeak_lut_6_1;                /* < 6> [dv:     0x0000] [des: VIMG VPEAK Gain LUT Register 6] */
    unsigned gscl1_vimg_vpeak_config_1;               /* < 7> [dv:     0x0000] [des: VIMG VPEAK Config Register] */
    unsigned gscl1_vimg_diag_config_1_1;              /* < 8> [dv:     0x0000] [des: VIMG Diagonal Filter Config Register 1] */
    unsigned gscl1_vimg_diag_config_2_1;              /* < 9> [dv:     0x0000] [des: VIMG Diagonal Filter Config Register 2] */
    unsigned reserved_0_47;                           /* <10> [dv:     0x0000] [des: Reserved Register] */
    unsigned gscl1_checksum_select_1;                 /* <11> [dv:     0x0000] [des: Checksum select Register] */
    unsigned gscl1_checksum_result_1;                 /* <12> [dv:     0x0000] [des: Checksum Rrsult Register] */
    unsigned reserved_1_43;                           /* <13> [dv:     0x0000] [des: Reserved Register] */
    unsigned gscl1_debug_info_1;                      /* <14> [dv:     0x0001] [des: Debug Info Register] */
    unsigned reserved_2_38;                           /* <15> [dv:     0x0000] [des: Reserved Register] */
    unsigned gscl1_dr_ctrl_1;                         /* <16> [dv:     0x0000] [des: Dering control signal] */
    unsigned gscl1_dr_dege_detect1_1;                 /* <17> [dv:     0x0000] [des: Dering edge detection relative] */
    unsigned gscl1_dr_dege_detect2_1;                 /* <18> [dv:     0x0000] [des: Dering edge detection relative] */
    unsigned gscl1_dr_clamp_detect_1;                 /* <19> [dv:     0x0000] [des: Dering clamp value relative] */
    unsigned grp221_reserved_0;                       /* <20> */
    unsigned grp221_reserved_1;                       /* <21> */
    unsigned grp221_reserved_2;                       /* <22> */
    unsigned grp221_reserved_3;                       /* <23> */
    unsigned grp221_reserved_4;                       /* <24> */
    unsigned grp221_reserved_5;                       /* <25> */
    unsigned grp221_reserved_6;                       /* <26> */
    unsigned grp221_reserved_7;                       /* <27> */
    unsigned grp221_reserved_8;                       /* <28> */
    unsigned grp221_reserved_9;                       /* <29> */
    unsigned grp221_reserved_10;                      /* <30> */
    unsigned grp221_reserved_11;                      /* <31> */
    // GROUP 222
    unsigned grp222_reserved[32];
    // GROUP 223
    unsigned grp223_reserved[32];
    // GROUP 224
    unsigned grp224_reserved[32];
    // GROUP 225
    unsigned grp225_reserved[32];
    // GROUP 226
    unsigned grp226_reserved[32];
    // GROUP 227
    unsigned grp227_reserved[32];
    // GROUP 228
    unsigned grp228_reserved[32];
    // GROUP 229
    unsigned grp229_reserved[32];
    // GROUP 230 [tcon_gm_tcon0]
    unsigned tc_tcon0;                                /* < 0> [dv:       0x6c] [des: TCON control register (1/6)] */
    unsigned tc_tcon1;                                /* < 1> [dv:        0x8] [des: TCON control register (2/6)] */
    unsigned tc_tcon2;                                /* < 2> [dv:       0x80] [des: TCON control register (3/6)] */
    unsigned tc_tcon3;                                /* < 3> [dv:     0x8080] [des: TCON control register (4/6)] */
    unsigned tc_str_line_top;                         /* < 4> [dv:       0x12] [des: TCON Active start line number on TOP field ] */
    unsigned tc_str_line_bot;                         /* < 5> [dv:      0x119] [des: TCON Active start line number on Bottom field ] */
    unsigned tc_end_line_top;                         /* < 6> [dv:      0x102] [des: TCON Active end line number on TOP field ] */
    unsigned tc_end_line_bot;                         /* < 7> [dv:      0x209] [des: TCON Active start line number on Bottom field ] */
    unsigned tc_stv_sline_top;                        /* < 8> [dv:       0x11] [des: TCON User defined TOP STV line number] */
    unsigned tc_stv_sline_bot;                        /* < 9> [dv:       0x11] [des: TCON User defined Bottom STV line number] */
    unsigned tc_oeh_start;                            /* <10> [dv:        0x0] [des: TCON OEH start position] */
    unsigned tc_oeh_end;                              /* <11> [dv:        0x0] [des: TCON OEH end position] */
    unsigned tc_oev_start;                            /* <12> [dv:        0x0] [des: TCON OEV start position] */
    unsigned tc_oev_end;                              /* <13> [dv:        0x0] [des: TCON OEV end position ] */
    unsigned tc_q1h_start;                            /* <14> [dv:        0x0] [des: TCON Q1H start position] */
    unsigned tc_q1h_end;                              /* <15> [dv:        0x0] [des: TCON Q1H end position] */
    unsigned tc_vcom_start;                           /* <16> [dv:        0x0] [des: TCON VCOM start position] */
    unsigned tc_vcom_end;                             /* <17> [dv:        0x0] [des: TCON VCOM end position] */
    unsigned tc_ckv_start;                            /* <18> [dv:        0x0] [des: TCON CKV start position] */
    unsigned tc_ckv_end;                              /* <19> [dv:        0x0] [des: TCON CKV end position] */
    unsigned tc_stvu_start;                           /* <20> [dv:        0x0] [des: TCON STV start position] */
    unsigned tc_stvu_end;                             /* <21> [dv:        0x0] [des: TCON STV end position] */
    unsigned tc_sthl_end;                             /* <22> [dv:        0x0] [des: TCON STH end position] */
    unsigned tc_hsync_start;                          /* <23> [dv:        0x0] [des: DP_HS start position] */
    unsigned tc_hsync_end;                            /* <24> [dv:        0x0] [des: DP_HS end position] */
    unsigned tc_de_hstart;                            /* <25> [dv:        0x0] [des: DP_DE horizontal active start position] */
    unsigned tc_de_hend;                              /* <26> [dv:        0x0] [des: DP_DE horizontal active end position] */
    unsigned tc_de_vstart_top;                        /* <27> [dv:        0x0] [des: DP_DE vertical active start line number on TOP] */
    unsigned tc_de_vend_top;                          /* <28> [dv:        0x0] [des: DP_DE vertical active end line number on TOP] */
    unsigned tc_de_vstart_bot;                        /* <29> [dv:        0x0] [des: DP_DE vertical active start line number on BOT] */
    unsigned tc_de_vend_bot;                          /* <30> [dv:        0x0] [des: DP_DE vertical active end line number on BOT] */
    unsigned tc_sthl_start;                           /* <31> [dv:     0x1FFE] [des: TCON STH start position] */
    // GROUP 231 [tcon_gm_tcon1]
    unsigned tc_gamma0;                               /* < 0> [dv:     0x8000] [des: GAMMA CTRL Register (1/2)] */
    unsigned g231_reserved_0;                         /* < 1> [dv:     0x0000] [des: Reserved register] */
    unsigned g231_reserved_2;                         /* < 2> [dv:     0x0000] [des: Reserved register] */
    unsigned g231_reserved_3;                         /* < 3> [dv:     0x0000] [des: Reserved register] */
    unsigned tc_f_rst_tline;                          /* < 4> [dv:        0x0] [des: TCON User defined VCOUNT reset line number on TOP] */
    unsigned tc_f_rst_bline;                          /* < 5> [dv:        0x0] [des: TCON User defined VCOUNT reset line number on Bottom] */
    unsigned tc_tpg_ctrl;                             /* < 6> [dv:        0x0] [des: TCON Test Pattern Generator: Main Control Register] */
    unsigned tc_tpg_hcount;                           /* < 7> [dv:      0x26f] [des: Test Pattern Generator: total H-size] */
    unsigned tc_tpg_vcount;                           /* < 8> [dv:      0x105] [des: Test Pattern Generator: total V-size] */
    unsigned tc_tpg_hact_count;                       /* < 9> [dv:      0x1df] [des: Test Pattern Generator: Horizontal Active size] */
    unsigned tc_tpg_vact_count;                       /* <10> [dv:       0xf0] [des: Test Pattern Generator: Vertical Active size] */
    unsigned tc_det_bp_lcnt;                          /* <11> [dv:        0x0] [des: Detected output back porch line number] */
    unsigned tc_det_fp_lcnt_t;                        /* <12> [dv:        0x0] [des: Detected output front porch line number on top] */
    unsigned tc_det_fp_lcnt_b;                        /* <13> [dv:        0x0] [des: Detected output front porch line number on bottom] */
    unsigned tc_det_hcount;                           /* <14> [dv:        0x1] [des: Detected output pixel count] */
    unsigned tc_tcon4;                                /* <15> [dv:      0x601] [des: TCON control register (5/6)] */
    unsigned g231_reserved_4;                         /* <16> [dv:     0x0000] [des: Reserved register] */
    unsigned g231_reserved_5;                         /* <17> [dv:     0x0000] [des: Reserved register] */
    unsigned g231_reserved_6;                         /* <18> [dv:     0x0000] [des: Reserved register] */
    unsigned tc_tpg_rgb_data;                         /* <19> [dv:     0x7FFF] [des: Test Pattern Generator: Data Parameters] */
    unsigned tc_dvalid_hstart;                        /* <20> [dv:        0x0] [des: DVALID signal horizontal start point] */
    unsigned tc_dvalid_hend;                          /* <21> [dv:        0x0] [des: DVALID signal horizontal end point] */
    unsigned tc_dither_tvout;                         /* <22> [dv:        0x0] [des: The Enhanced dithering method] */
    unsigned hact_latch;                              /* <23> [dv:        0x1] [des: Detected output horizontal active number] */
    unsigned top_vtotal;                              /* <24> [dv:        0x0] [des: Detected output vertical total number on top] */
    unsigned bot_vtotal;                              /* <25> [dv:        0x0] [des: Detected output vertical total number on bottom] */
    unsigned tc_tcon5;                                /* <26> [dv:        0x0] [des: TCON control register (6/6)] */
    unsigned tc_gamma1;                               /* <27> [dv:        0x0] [des: GAMMA CTRL Register (2/3)] */
    unsigned tc_gamma2;                               /* <28> [dv:        0x0] [des: GAMMA CTRL Register (3/3)] */
    unsigned tc_check_sum;                            /* <29> [dv:        0x0] [des: Tcon check sum] */
    unsigned grp231_reserved_0;                       /* <30> */
    unsigned grp231_reserved_1;                       /* <31> */
    // GROUP 232 [tcon_gmtcon_tcon2]
    unsigned g232_reserved_0;                         /* < 0> [dv:     0x0000] [des: Reserved register] */
    unsigned g232_reserved_1;                         /* < 1> [dv:     0x0000] [des: Reserved register] */
    unsigned g232_reserved_2;                         /* < 2> [dv:     0x0000] [des: Reserved register] */
    unsigned g232_reserved_3;                         /* < 3> [dv:     0x0000] [des: Reserved register] */
    unsigned g232_reserved_4;                         /* < 4> [dv:     0x0000] [des: Reserved register] */
    unsigned g232_reserved_5;                         /* < 5> [dv:     0x0000] [des: Reserved register] */
    unsigned g232_reserved_6;                         /* < 6> [dv:     0x0000] [des: Reserved register] */
    unsigned g232_reserved_7;                         /* < 7> [dv:     0x0000] [des: Reserved register] */
    unsigned g232_reserved_8;                         /* < 8> [dv:     0x0000] [des: Reserved register] */
    unsigned g232_reserved_9;                         /* < 9> [dv:     0x0000] [des: Reserved register] */
    unsigned g232_reserved_10;                        /* <10> [dv:     0x0000] [des: Reserved register] */
    unsigned g232_reserved_11;                        /* <11> [dv:     0x0000] [des: Reserved register] */
    unsigned g232_reserved_12;                        /* <12> [dv:     0x0000] [des: Reserved register] */
    unsigned bit_swap_cfg;                            /* <13> [dv:     0x0000] [des: DOT1/2/3 bit swap enable] */
    unsigned bit_swap_g0;                             /* <14> [dv:     0x7fff] [des: [BIT_SW_ON]bit swap group 0] */
    unsigned bit_swap_g1;                             /* <15> [dv:     0x7fff] [des: [BIT_SW_ON]bit swap group 1] */
    unsigned bit_swap_g2;                             /* <16> [dv:     0x7fff] [des: [BIT_SW_ON]bit swap group 2] */
    unsigned bit_swap_g3;                             /* <17> [dv:     0x7fff] [des: [BIT_SW_ON]bit swap group 3] */
    unsigned bit_swap_g4;                             /* <18> [dv:     0x7fff] [des: [BIT_SW_ON]bit swap group 4] */
    unsigned bit_swap_g5;                             /* <19> [dv:     0x7fff] [des: [BIT_SW_ON]bit swap group 5] */
    unsigned bit_swap_g6;                             /* <20> [dv:     0x7fff] [des: [BIT_SW_ON]bit swap group 6] */
    unsigned bit_swap_g7;                             /* <21> [dv:     0x7fff] [des: [BIT_SW_ON]bit swap group 7] */
    unsigned grp232_reserved_0;                       /* <22> */
    unsigned grp232_reserved_1;                       /* <23> */
    unsigned grp232_reserved_2;                       /* <24> */
    unsigned grp232_reserved_3;                       /* <25> */
    unsigned grp232_reserved_4;                       /* <26> */
    unsigned grp232_reserved_5;                       /* <27> */
    unsigned grp232_reserved_6;                       /* <28> */
    unsigned grp232_reserved_7;                       /* <29> */
    unsigned grp232_reserved_8;                       /* <30> */
    unsigned grp232_reserved_9;                       /* <31> */
    // GROUP 233 [tcon_pwm]
    unsigned pwm_mode0;                               /* < 0> [dv:     0x0001] [des: PWM mode control] */
    unsigned pwm_mode1;                               /* < 1> [dv:     0x0001] [des: PWM_DD count enable] */
    unsigned pwm_dd0;                                 /* < 2> [dv:     0x000a] [des: PWM duty divisor] */
    unsigned pwm_dd1;                                 /* < 3> [dv:     0x000a] [des: PWM duty divisor] */
    unsigned pwm_dd2;                                 /* < 4> [dv:     0x000a] [des: PWM duty divisor] */
    unsigned pwm_dd3;                                 /* < 5> [dv:     0x000a] [des: PWM duty divisor] */
    unsigned pwm1_cfg;                                /* < 6> [dv:     0x0001] [des: PWM1 config] */
    unsigned pwm2_cfg;                                /* < 7> [dv:     0x0001] [des: PWM config] */
    unsigned pwm3_cfg;                                /* < 8> [dv:     0x0001] [des: PWM config] */
    unsigned pwm4_cfg;                                /* < 9> [dv:     0x0001] [des: PWM config] */
    unsigned pwm5_cfg;                                /* <10> [dv:     0x0001] [des: PWM config] */
    unsigned pwm6_cfg;                                /* <11> [dv:     0x0001] [des: PWM config] */
    unsigned pwm7_cfg;                                /* <12> [dv:     0x0001] [des: PWM config] */
    unsigned pwm8_cfg;                                /* <13> [dv:     0x0001] [des: PWM config] */
    unsigned grp233_reserved_0;                       /* <14> */
    unsigned grp233_reserved_1;                       /* <15> */
    unsigned grp233_reserved_2;                       /* <16> */
    unsigned grp233_reserved_3;                       /* <17> */
    unsigned grp233_reserved_4;                       /* <18> */
    unsigned grp233_reserved_5;                       /* <19> */
    unsigned grp233_reserved_6;                       /* <20> */
    unsigned grp233_reserved_7;                       /* <21> */
    unsigned grp233_reserved_8;                       /* <22> */
    unsigned grp233_reserved_9;                       /* <23> */
    unsigned grp233_reserved_10;                      /* <24> */
    unsigned grp233_reserved_11;                      /* <25> */
    unsigned grp233_reserved_12;                      /* <26> */
    unsigned grp233_reserved_13;                      /* <27> */
    unsigned grp233_reserved_14;                      /* <28> */
    unsigned grp233_reserved_15;                      /* <29> */
    unsigned grp233_reserved_16;                      /* <30> */
    unsigned grp233_reserved_17;                      /* <31> */
    // GROUP 234 [lvdsif]
    unsigned lvdsif_r_order0;                         /* < 0> [dv:     0x3210] [des: LVDSIF R CONVERTER 0] */
    unsigned lvdsif_r_order1;                         /* < 1> [dv:     0x7654] [des: LVDSIF R CONVERTER 1] */
    unsigned lvdsif_r_order2;                         /* < 2> [dv:     0x0089] [des: LVDSIF R CONVERTER 2] */
    unsigned lvdsif_g_order0;                         /* < 3> [dv:     0x3210] [des: LVDSIF G CONVERTER 0] */
    unsigned lvdsif_g_order1;                         /* < 4> [dv:     0x7654] [des: LVDSIF G CONVERTER 1] */
    unsigned lvdsif_g_order2;                         /* < 5> [dv:     0x0089] [des: LVDSIF G CONVERTER 2] */
    unsigned lvdsif_b_order0;                         /* < 6> [dv:     0x3210] [des: LVDSIF B CONVERTER 0] */
    unsigned lvdsif_b_order1;                         /* < 7> [dv:     0x7654] [des: LVDSIF B CONVERTER 1] */
    unsigned lvdsif_b_order2;                         /* < 8> [dv:     0x0089] [des: LVDSIF G CONVERTEB 2] */
    unsigned lvds_con_cfg;                            /* < 9> [dv:     0x0000] [des: LVDSIF CONFIG] */
    unsigned lvds_con_di_chsel;                       /* <10> [dv:     0x7fff] [des: LVDSIF DI CHANNEL SEL] */
    unsigned lvds_con_dia_chsel;                      /* <11> [dv:     0x7fff] [des: LVDSIF DIA CHANNEL SEL] */
    unsigned grp234_reserved_0;                       /* <12> */
    unsigned grp234_reserved_1;                       /* <13> */
    unsigned grp234_reserved_2;                       /* <14> */
    unsigned grp234_reserved_3;                       /* <15> */
    unsigned grp234_reserved_4;                       /* <16> */
    unsigned grp234_reserved_5;                       /* <17> */
    unsigned grp234_reserved_6;                       /* <18> */
    unsigned grp234_reserved_7;                       /* <19> */
    unsigned grp234_reserved_8;                       /* <20> */
    unsigned grp234_reserved_9;                       /* <21> */
    unsigned grp234_reserved_10;                      /* <22> */
    unsigned grp234_reserved_11;                      /* <23> */
    unsigned grp234_reserved_12;                      /* <24> */
    unsigned grp234_reserved_13;                      /* <25> */
    unsigned grp234_reserved_14;                      /* <26> */
    unsigned grp234_reserved_15;                      /* <27> */
    unsigned grp234_reserved_16;                      /* <28> */
    unsigned grp234_reserved_17;                      /* <29> */
    unsigned grp234_reserved_18;                      /* <30> */
    unsigned grp234_reserved_19;                      /* <31> */
    // GROUP 235
    unsigned grp235_reserved[32];
    // GROUP 236
    unsigned grp236_reserved[32];
    // GROUP 237
    unsigned grp237_reserved[32];
    // GROUP 238
    unsigned grp238_reserved[32];
    // GROUP 239
    unsigned grp239_reserved[32];
    // GROUP 240
    unsigned grp240_reserved[32];
    // GROUP 241
    unsigned grp241_reserved[32];
    // GROUP 242
    unsigned grp242_reserved[32];
    // GROUP 243
    unsigned grp243_reserved[32];
    // GROUP 244
    unsigned grp244_reserved[32];
    // GROUP 245
    unsigned grp245_reserved[32];
    // GROUP 246
    unsigned grp246_reserved[32];
    // GROUP 247
    unsigned grp247_reserved[32];
    // GROUP 248
    unsigned grp248_reserved[32];
    // GROUP 249
    unsigned grp249_reserved[32];
    // GROUP 250 [video_encoder_dve]
    unsigned dve_vsync_start_top;                     /* < 0> [dv:        0x1] [des: HDMI User Mode Para \#1] */
    unsigned dve_vsync_start_bot;                     /* < 1> [dv:      0x107] [des: HDMI User Mode Para \#2] */
    unsigned dve_vsync_h_point;                       /* < 2> [dv:      0x26b] [des: HDMI User Mode Para \#3] */
    unsigned dve_vsync_pd_cnt;                        /* < 3> [dv:        0x2] [des: HDMI User Mode Para \#4] */
    unsigned dve_hsync_start;                         /* < 4> [dv:      0x5c5] [des: HDMI User Mode Para \#5] */
    unsigned dve_hsync_pd_cnt;                        /* < 5> [dv:       0x7b] [des: HDMI User Mode Para \#6] */
    unsigned dve_vhsync_polar;                        /* < 6> [dv:        0x3] [des: HDMI User Mode Para \#7] */
    unsigned dve_v_vld_top_start;                     /* < 7> [dv:       0x12] [des: HDMI User Mode Para \#8] */
    unsigned dve_v_vld_top_end;                       /* < 8> [dv:      0x102] [des: HDMI User Mode Para \#9] */
    unsigned dve_v_vld_bot_start;                     /* < 9> [dv:      0x119] [des: HDMI User Mode Para \#10] */
    unsigned dve_v_vld_bot_end;                       /* <10> [dv:      0x209] [des: HDMI User Mode Para \#11] */
    unsigned dve_de_h_start;                          /* <11> [dv:      0x6b3] [des: HDMI User Mode Para \#12] */
    unsigned dve_de_h_end;                            /* <12> [dv:      0x59f] [des: HDMI User Mode Para \#13] */
    unsigned dve_mp_tg_line_0_length;                 /* <13> [dv:      0x6b3] [des: HDMI User Mode Para \#14] */
    unsigned dve_mp_tg_frame_0_line;                  /* <14> [dv:      0x20c] [des: HDMI User Mode Para \#15] */
    unsigned dve_mp_tg_act_0_pix;                     /* <15> [dv:      0x59f] [des: HDMI User Mode Para \#16] */
    unsigned dve_hdmi_mode_0;                         /* <16> [dv:        0x1] [des: HDMI Mode Control] */
    unsigned dve_act_0_pix_656;                       /* <17> [dv:      0x2cf] [des: CCIR656 User Mode Para \#1] */
    unsigned dve_line_0_length_656;                   /* <18> [dv:      0x359] [des: CCIR656 User Mode Para \#2] */
    unsigned dve_frame_0_line_656;                    /* <19> [dv:      0x20c] [des: CCIR656 User Mode Para \#3] */
    unsigned dve_noact_end_tl_656;                    /* <20> [dv:        0xf] [des: CCIR656 User Mode Para \#4] */
    unsigned dve_act_end_tl_656;                      /* <21> [dv:      0x103] [des: CCIR656 User Mode Para \#5] */
    unsigned dve_noact_end_bl_656;                    /* <22> [dv:      0x116] [des: CCIR656 User Mode Para \#6] */
    unsigned dve_act_end_bl_656;                      /* <23> [dv:      0x209] [des: CCIR656 User Mode Para \#7] */
    unsigned dve_ccir656_ctrl_0;                      /* <24> [dv:      0x120] [des: CCIR656 Control] */
    unsigned dve_d656_y_range;                        /* <25> [dv:     0xEB10] [des: Value limiter of Luma] */
    unsigned dve_d656_c_range;                        /* <26> [dv:     0xF010] [des: Value limiter of Chroma] */
    unsigned reserved_0_48;                           /* <27> [dv:      0x000] [des: ] */
    unsigned reserved_1_44;                           /* <28> [dv:      0x000] [des: ] */
    unsigned dve_hdmi_sharp;                          /* <29> [dv:        0x1] [des: Sharpness control for HDMI] */
    unsigned dve_config1;                             /* <30> [dv:     0x1000] [des: DVE Config1 Register] */
    unsigned dve_checksum;                            /* <31> [dv:     0x0000] [des: DVE checksum] */
    // GROUP 251 [video_encoder_dve]
    unsigned color_bar_mode;                          /* < 0> [dv:        0x0] [des: Color bar mode control \#1] */
    unsigned color_bar_v_total;                       /* < 1> [dv:      0x20c] [des: user mode V total \#2] */
    unsigned color_bar_v_active;                      /* < 2> [dv:      0x1df] [des: user mode V active \#3] */
    unsigned color_bar_v_active_start;                /* < 3> [dv:       0x11] [des: user mode V active_start \#4] */
    unsigned color_bar_h_total;                       /* < 4> [dv:      0x359] [des: user mode H total \#5] */
    unsigned color_bar_h_active;                      /* < 5> [dv:      0x2cf] [des: user mode H active \#6] */
    unsigned grp251_reserved_0;                       /* < 6> */
    unsigned grp251_reserved_1;                       /* < 7> */
    unsigned grp251_reserved_2;                       /* < 8> */
    unsigned grp251_reserved_3;                       /* < 9> */
    unsigned grp251_reserved_4;                       /* <10> */
    unsigned grp251_reserved_5;                       /* <11> */
    unsigned grp251_reserved_6;                       /* <12> */
    unsigned grp251_reserved_7;                       /* <13> */
    unsigned grp251_reserved_8;                       /* <14> */
    unsigned grp251_reserved_9;                       /* <15> */
    unsigned grp251_reserved_10;                      /* <16> */
    unsigned grp251_reserved_11;                      /* <17> */
    unsigned grp251_reserved_12;                      /* <18> */
    unsigned grp251_reserved_13;                      /* <19> */
    unsigned grp251_reserved_14;                      /* <20> */
    unsigned grp251_reserved_15;                      /* <21> */
    unsigned grp251_reserved_16;                      /* <22> */
    unsigned grp251_reserved_17;                      /* <23> */
    unsigned grp251_reserved_18;                      /* <24> */
    unsigned grp251_reserved_19;                      /* <25> */
    unsigned grp251_reserved_20;                      /* <26> */
    unsigned grp251_reserved_21;                      /* <27> */
    unsigned grp251_reserved_22;                      /* <28> */
    unsigned grp251_reserved_23;                      /* <29> */
    unsigned grp251_reserved_24;                      /* <30> */
    unsigned grp251_reserved_25;                      /* <31> */
    // GROUP 252 [video_encoder_dve]
    unsigned dve_vsync_start_top_1;                   /* < 0> [dv:        0x1] [des: HDMI User Mode Para \#1] */
    unsigned dve_vsync_start_bot_1;                   /* < 1> [dv:      0x107] [des: HDMI User Mode Para \#2] */
    unsigned dve_vsync_h_point_1;                     /* < 2> [dv:      0x26b] [des: HDMI User Mode Para \#3] */
    unsigned dve_vsync_pd_cnt_1;                      /* < 3> [dv:        0x2] [des: HDMI User Mode Para \#4] */
    unsigned dve_hsync_start_1;                       /* < 4> [dv:      0x5c5] [des: HDMI User Mode Para \#5] */
    unsigned dve_hsync_pd_cnt_1;                      /* < 5> [dv:       0x7b] [des: HDMI User Mode Para \#6] */
    unsigned dve_vhsync_polar_1;                      /* < 6> [dv:        0x3] [des: HDMI User Mode Para \#7] */
    unsigned dve_v_vld_top_start_1;                   /* < 7> [dv:       0x12] [des: HDMI User Mode Para \#8] */
    unsigned dve_v_vld_top_end_1;                     /* < 8> [dv:      0x102] [des: HDMI User Mode Para \#9] */
    unsigned dve_v_vld_bot_start_1;                   /* < 9> [dv:      0x119] [des: HDMI User Mode Para \#10] */
    unsigned dve_v_vld_bot_end_1;                     /* <10> [dv:      0x209] [des: HDMI User Mode Para \#11] */
    unsigned dve_de_h_start_1;                        /* <11> [dv:      0x6b3] [des: HDMI User Mode Para \#12] */
    unsigned dve_de_h_end_1;                          /* <12> [dv:      0x59f] [des: HDMI User Mode Para \#13] */
    unsigned dve_mp_tg_line_0_length_1;               /* <13> [dv:      0x6b3] [des: HDMI User Mode Para \#14] */
    unsigned dve_mp_tg_frame_0_line_1;                /* <14> [dv:      0x20c] [des: HDMI User Mode Para \#15] */
    unsigned dve_mp_tg_act_0_pix_1;                   /* <15> [dv:      0x59f] [des: HDMI User Mode Para \#16] */
    unsigned dve_hdmi_mode_0_1;                       /* <16> [dv:        0x1] [des: HDMI Mode Control] */
    unsigned dve_act_0_pix_656_1;                     /* <17> [dv:      0x2cf] [des: CCIR656 User Mode Para \#1] */
    unsigned dve_line_0_length_656_1;                 /* <18> [dv:      0x359] [des: CCIR656 User Mode Para \#2] */
    unsigned dve_frame_0_line_656_1;                  /* <19> [dv:      0x20c] [des: CCIR656 User Mode Para \#3] */
    unsigned dve_noact_end_tl_656_1;                  /* <20> [dv:        0xf] [des: CCIR656 User Mode Para \#4] */
    unsigned dve_act_end_tl_656_1;                    /* <21> [dv:      0x103] [des: CCIR656 User Mode Para \#5] */
    unsigned dve_noact_end_bl_656_1;                  /* <22> [dv:      0x116] [des: CCIR656 User Mode Para \#6] */
    unsigned dve_act_end_bl_656_1;                    /* <23> [dv:      0x209] [des: CCIR656 User Mode Para \#7] */
    unsigned dve_ccir656_ctrl_0_1;                    /* <24> [dv:      0x120] [des: CCIR656 Control] */
    unsigned dve_d656_y_range_1;                      /* <25> [dv:     0xEB10] [des: Value limiter of Luma] */
    unsigned dve_d656_c_range_1;                      /* <26> [dv:     0xF010] [des: Value limiter of Chroma] */
    unsigned reserved_0_49;                           /* <27> [dv:      0x000] [des: ] */
    unsigned reserved_1_45;                           /* <28> [dv:      0x000] [des: ] */
    unsigned dve_hdmi_sharp_1;                        /* <29> [dv:        0x1] [des: Sharpness control for HDMI] */
    unsigned dve_config1_1;                           /* <30> [dv:     0x1000] [des: DVE Config1 Register] */
    unsigned dve_checksum_1;                          /* <31> [dv:     0x0000] [des: DVE checksum] */
    // GROUP 253 [video_encoder_dve]
    unsigned color_bar_mode_1;                        /* < 0> [dv:        0x0] [des: Color bar mode control \#1] */
    unsigned color_bar_v_total_1;                     /* < 1> [dv:      0x20c] [des: user mode V total \#2] */
    unsigned color_bar_v_active_1;                    /* < 2> [dv:      0x1df] [des: user mode V active \#3] */
    unsigned color_bar_v_active_start_1;              /* < 3> [dv:       0x11] [des: user mode V active_start \#4] */
    unsigned color_bar_h_total_1;                     /* < 4> [dv:      0x359] [des: user mode H total \#5] */
    unsigned color_bar_h_active_1;                    /* < 5> [dv:      0x2cf] [des: user mode H active \#6] */
    unsigned grp253_reserved_0;                       /* < 6> */
    unsigned grp253_reserved_1;                       /* < 7> */
    unsigned grp253_reserved_2;                       /* < 8> */
    unsigned grp253_reserved_3;                       /* < 9> */
    unsigned grp253_reserved_4;                       /* <10> */
    unsigned grp253_reserved_5;                       /* <11> */
    unsigned grp253_reserved_6;                       /* <12> */
    unsigned grp253_reserved_7;                       /* <13> */
    unsigned grp253_reserved_8;                       /* <14> */
    unsigned grp253_reserved_9;                       /* <15> */
    unsigned grp253_reserved_10;                      /* <16> */
    unsigned grp253_reserved_11;                      /* <17> */
    unsigned grp253_reserved_12;                      /* <18> */
    unsigned grp253_reserved_13;                      /* <19> */
    unsigned grp253_reserved_14;                      /* <20> */
    unsigned grp253_reserved_15;                      /* <21> */
    unsigned grp253_reserved_16;                      /* <22> */
    unsigned grp253_reserved_17;                      /* <23> */
    unsigned grp253_reserved_18;                      /* <24> */
    unsigned grp253_reserved_19;                      /* <25> */
    unsigned grp253_reserved_20;                      /* <26> */
    unsigned grp253_reserved_21;                      /* <27> */
    unsigned grp253_reserved_22;                      /* <28> */
    unsigned grp253_reserved_23;                      /* <29> */
    unsigned grp253_reserved_24;                      /* <30> */
    unsigned grp253_reserved_25;                      /* <31> */
    // GROUP 254 [tcon_gm_tcon3]
    unsigned tc_adj;                                  /* < 0> [dv:     0x0000] [des: Adjustment CTRL Register (1/2)] */
    unsigned r_adj_cp1;                               /* < 1> [dv:     0x0000] [des: R channel adjust control point 1 register] */
    unsigned r_adj_cp2;                               /* < 2> [dv:     0x5060] [des: R channel djust control point 2 register] */
    unsigned r_adj_cp3;                               /* < 3> [dv:     0xb0a0] [des: R channel adjust control point 1 register] */
    unsigned r_adj_slope0;                            /* < 4> [dv:     0x0100] [des: R channel adjust slope 0 register] */
    unsigned r_adj_slope1;                            /* < 5> [dv:     0x00d5] [des: R channel adjust slope 1 register] */
    unsigned r_adj_slope2;                            /* < 6> [dv:     0x0180] [des: R channel adjust slope 2 register] */
    unsigned r_adj_slope3;                            /* < 7> [dv:     0x00d5] [des: R channel adjust slope 3 register] */
    unsigned g_adj_cp1;                               /* < 8> [dv:     0x0000] [des: G channel adjust control point 1 register] */
    unsigned g_adj_cp2;                               /* < 9> [dv:     0x5060] [des: G channel djust control point 2 register] */
    unsigned g_adj_cp3;                               /* <10> [dv:     0xb0a0] [des: G channel adjust control point 1 register] */
    unsigned g_adj_slope0;                            /* <11> [dv:     0x0100] [des: G channel adjust slope 0 register] */
    unsigned g_adj_slope1;                            /* <12> [dv:     0x00d5] [des: G channel adjust slope 1 register] */
    unsigned g_adj_slope2;                            /* <13> [dv:     0x0180] [des: G channel adjust slope 2 register] */
    unsigned g_adj_slope3;                            /* <14> [dv:     0x00d5] [des: G channel adjust slope 3 register] */
    unsigned b_adj_cp1;                               /* <15> [dv:     0x0000] [des: B channel adjust control point 1 register] */
    unsigned b_adj_cp2;                               /* <16> [dv:     0x5060] [des: B channel djust control point 2 register] */
    unsigned b_adj_cp3;                               /* <17> [dv:     0xb0a0] [des: B channel adjust control point 1 register] */
    unsigned b_adj_slope0;                            /* <18> [dv:     0x0100] [des: B channel adjust slope 0 register] */
    unsigned b_adj_slope1;                            /* <19> [dv:     0x00d5] [des: B channel adjust slope 1 register] */
    unsigned b_adj_slope2;                            /* <20> [dv:     0x0180] [des: B channel adjust slope 2 register] */
    unsigned b_adj_slope3;                            /* <21> [dv:     0x00d5] [des: B channel adjust slope 3 register] */
    unsigned grp254_reserved_0;                       /* <22> */
    unsigned grp254_reserved_1;                       /* <23> */
    unsigned grp254_reserved_2;                       /* <24> */
    unsigned grp254_reserved_3;                       /* <25> */
    unsigned grp254_reserved_4;                       /* <26> */
    unsigned grp254_reserved_5;                       /* <27> */
    unsigned grp254_reserved_6;                       /* <28> */
    unsigned grp254_reserved_7;                       /* <29> */
    unsigned grp254_reserved_8;                       /* <30> */
    unsigned grp254_reserved_9;                       /* <31> */
    // GROUP 255
    unsigned grp255_reserved[32];
    // GROUP 256
    unsigned grp256_reserved[32];
    // GROUP 257
    unsigned grp257_reserved[32];
    // GROUP 258 [mailbox_ca9write_arm926read]
    unsigned mbox0_a926_int_trigger;                  /* < 0> [dv: 0x0000_0000] [des: Trigger A926_INT] */
    unsigned mbox0_writelock_flag;                    /* < 1> [dv: 0x0000_0000] [des: Mailbox0 Writelock Flag Monitor] */
    unsigned mbox0_overwrite_flag;                    /* < 2> [dv: 0x0000_0000] [des: Mailbox0 Overwrite Flag Monitor] */
    unsigned reserved_0_50;                           /* < 3> [dv: 0x0000_0000] [des: Reserved] */
    unsigned mbox0_normal_trans_0;                    /* < 4> [dv: 0x0000_0000] [des: Normal Transaction00 from CA9 to ARM926] */
    unsigned mbox0_normal_trans_1;                    /* < 5> [dv: 0x0000_0000] [des: Normal Transaction01 from CA9 to ARM926] */
    unsigned mbox0_normal_trans_2;                    /* < 6> [dv: 0x0000_0000] [des: Normal Transaction02 from CA9 to ARM926] */
    unsigned mbox0_normal_trans_3;                    /* < 7> [dv: 0x0000_0000] [des: Normal Transaction03 from CA9 to ARM926] */
    unsigned mbox0_normal_trans_4;                    /* < 8> [dv: 0x0000_0000] [des: Normal Transaction04 from CA9 to ARM926] */
    unsigned mbox0_normal_trans_5;                    /* < 9> [dv: 0x0000_0000] [des: Normal Transaction05 from CA9 to ARM926] */
    unsigned mbox0_normal_trans_6;                    /* <10> [dv: 0x0000_0000] [des: Normal Transaction06 from CA9 to ARM926] */
    unsigned mbox0_normal_trans_7;                    /* <11> [dv: 0x0000_0000] [des: Normal Transaction07 from CA9 to ARM926] */
    unsigned mbox0_normal_trans_8;                    /* <12> [dv: 0x0000_0000] [des: Normal Transaction08 from CA9 to ARM926] */
    unsigned mbox0_normal_trans_9;                    /* <13> [dv: 0x0000_0000] [des: Normal Transaction09 from CA9 to ARM926] */
    unsigned mbox0_normal_trans_10;                   /* <14> [dv: 0x0000_0000] [des: Normal Transaction10 from CA9 to ARM926] */
    unsigned mbox0_normal_trans_11;                   /* <15> [dv: 0x0000_0000] [des: Normal Transaction11 from CA9 to ARM926] */
    unsigned mbox0_normal_trans_12;                   /* <16> [dv: 0x0000_0000] [des: Normal Transaction12 from CA9 to ARM926] */
    unsigned mbox0_normal_trans_13;                   /* <17> [dv: 0x0000_0000] [des: Normal Transaction13 from CA9 to ARM926] */
    unsigned mbox0_normal_trans_14;                   /* <18> [dv: 0x0000_0000] [des: Normal Transaction14 from CA9 to ARM926] */
    unsigned mbox0_normal_trans_15;                   /* <19> [dv: 0x0000_0000] [des: Normal Transaction15 from CA9 to ARM926] */
    unsigned mbox0_normal_trans_16;                   /* <20> [dv: 0x0000_0000] [des: Normal Transaction16 from CA9 to ARM926] */
    unsigned mbox0_normal_trans_17;                   /* <21> [dv: 0x0000_0000] [des: Normal Transaction17 from CA9 to ARM926] */
    unsigned mbox0_normal_trans_18;                   /* <22> [dv: 0x0000_0000] [des: Normal Transaction18 from CA9 to ARM926] */
    unsigned mbox0_normal_trans_19;                   /* <23> [dv: 0x0000_0000] [des: Normal Transaction19 from CA9 to ARM926] */
    unsigned mbox0_direct_trans_0;                    /* <24> [dv: 0x0000_0000] [des: Direct Transaction00 from CA9 to ARM926] */
    unsigned mbox0_direct_trans_1;                    /* <25> [dv: 0x0000_0000] [des: Direct Transaction01 from CA9 to ARM926] */
    unsigned mbox0_direct_trans_2;                    /* <26> [dv: 0x0000_0000] [des: Direct Transaction02 from CA9 to ARM926] */
    unsigned mbox0_direct_trans_3;                    /* <27> [dv: 0x0000_0000] [des: Direct Transaction03 from CA9 to ARM926] */
    unsigned mbox0_direct_trans_4;                    /* <28> [dv: 0x0000_0000] [des: Direct Transaction04 from CA9 to ARM926] */
    unsigned mbox0_direct_trans_5;                    /* <29> [dv: 0x0000_0000] [des: Direct Transaction05 from CA9 to ARM926] */
    unsigned mbox0_direct_trans_6;                    /* <30> [dv: 0x0000_0000] [des: Direct Transaction06 from CA9 to ARM926] */
    unsigned mbox0_direct_trans_7;                    /* <31> [dv: 0x0000_0000] [des: Direct Transaction07 from CA9 to ARM926] */
    // GROUP 259 [mailbox_arm926write_ca9read]
    unsigned mbox1_ca9_int_trigger;                   /* < 0> [dv: 0x0000_0000] [des: Trigger CA9_INT] */
    unsigned mbox1_writelock_flag;                    /* < 1> [dv: 0x0000_0000] [des: mailbox1 Writelock Flag Monitor] */
    unsigned mbox1_overwrite_flag;                    /* < 2> [dv: 0x0000_0000] [des: mailbox1 Overwrite Flag Monitor] */
    unsigned reserved_0_51;                           /* < 3> [dv: 0x0000_0000] [des: Reserved] */
    unsigned mbox1_normal_trans_0;                    /* < 4> [dv: 0x0000_0000] [des: Normal Transaction00 from ARM926 to CA9] */
    unsigned mbox1_normal_trans_1;                    /* < 5> [dv: 0x0000_0000] [des: Normal Transaction01 from ARM926 to CA9] */
    unsigned mbox1_normal_trans_2;                    /* < 6> [dv: 0x0000_0000] [des: Normal Transaction02 from ARM926 to CA9] */
    unsigned mbox1_normal_trans_3;                    /* < 7> [dv: 0x0000_0000] [des: Normal Transaction03 from ARM926 to CA9] */
    unsigned mbox1_normal_trans_4;                    /* < 8> [dv: 0x0000_0000] [des: Normal Transaction04 from ARM926 to CA9] */
    unsigned mbox1_normal_trans_5;                    /* < 9> [dv: 0x0000_0000] [des: Normal Transaction05 from ARM926 to CA9] */
    unsigned mbox1_normal_trans_6;                    /* <10> [dv: 0x0000_0000] [des: Normal Transaction06 from ARM926 to CA9] */
    unsigned mbox1_normal_trans_7;                    /* <11> [dv: 0x0000_0000] [des: Normal Transaction07 from ARM926 to CA9] */
    unsigned mbox1_normal_trans_8;                    /* <12> [dv: 0x0000_0000] [des: Normal Transaction08 from ARM926 to CA9] */
    unsigned mbox1_normal_trans_9;                    /* <13> [dv: 0x0000_0000] [des: Normal Transaction09 from ARM926 to CA9] */
    unsigned mbox1_normal_trans_10;                   /* <14> [dv: 0x0000_0000] [des: Normal Transaction10 from ARM926 to CA9] */
    unsigned mbox1_normal_trans_11;                   /* <15> [dv: 0x0000_0000] [des: Normal Transaction11 from ARM926 to CA9] */
    unsigned mbox1_normal_trans_12;                   /* <16> [dv: 0x0000_0000] [des: Normal Transaction12 from ARM926 to CA9] */
    unsigned mbox1_normal_trans_13;                   /* <17> [dv: 0x0000_0000] [des: Normal Transaction13 from ARM926 to CA9] */
    unsigned mbox1_normal_trans_14;                   /* <18> [dv: 0x0000_0000] [des: Normal Transaction14 from ARM926 to CA9] */
    unsigned mbox1_normal_trans_15;                   /* <19> [dv: 0x0000_0000] [des: Normal Transaction15 from ARM926 to CA9] */
    unsigned mbox1_normal_trans_16;                   /* <20> [dv: 0x0000_0000] [des: Normal Transaction16 from ARM926 to CA9] */
    unsigned mbox1_normal_trans_17;                   /* <21> [dv: 0x0000_0000] [des: Normal Transaction17 from ARM926 to CA9] */
    unsigned mbox1_normal_trans_18;                   /* <22> [dv: 0x0000_0000] [des: Normal Transaction18 from ARM926 to CA9] */
    unsigned mbox1_normal_trans_19;                   /* <23> [dv: 0x0000_0000] [des: Normal Transaction19 from ARM926 to CA9] */
    unsigned mbox1_direct_trans_0;                    /* <24> [dv: 0x0000_0000] [des: Direct Transaction00 from ARM926 to CA9] */
    unsigned mbox1_direct_trans_1;                    /* <25> [dv: 0x0000_0000] [des: Direct Transaction01 from ARM926 to CA9] */
    unsigned mbox1_direct_trans_2;                    /* <26> [dv: 0x0000_0000] [des: Direct Transaction02 from ARM926 to CA9] */
    unsigned mbox1_direct_trans_3;                    /* <27> [dv: 0x0000_0000] [des: Direct Transaction03 from ARM926 to CA9] */
    unsigned mbox1_direct_trans_4;                    /* <28> [dv: 0x0000_0000] [des: Direct Transaction04 from ARM926 to CA9] */
    unsigned mbox1_direct_trans_5;                    /* <29> [dv: 0x0000_0000] [des: Direct Transaction05 from ARM926 to CA9] */
    unsigned mbox1_direct_trans_6;                    /* <30> [dv: 0x0000_0000] [des: Direct Transaction06 from ARM926 to CA9] */
    unsigned mbox1_direct_trans_7;                    /* <31> [dv: 0x0000_0000] [des: Direct Transaction07 from ARM926 to CA9] */
    // GROUP 260
    unsigned grp260_reserved[32];
    // GROUP 261
    unsigned grp261_reserved[32];
    // GROUP 262
    unsigned grp262_reserved[32];
    // GROUP 263
    unsigned grp263_reserved[32];
    // GROUP 264 [card_ctl_general_registers]
    unsigned card_mediatype_2;                        /* < 0> [dv:     0x0000] [des: Card Media Type] */
    unsigned reserved_0_52;                           /* < 1> [dv:     0x0000] [des: Reserved] */
    unsigned card_cpu_page_cnt_2;                     /* < 2> [dv:     0xffff] [des: CPU Page Count] */
    unsigned card_ctl_page_cnt_2;                     /* < 3> [dv:     0x0000] [des: CARD_CTL Page Count] */
    unsigned sdram_sector_0_size_2;                   /* < 4> [dv:     0xffff] [des: Length of SDRAM Sector_0] */
    unsigned ring_buffer_on_2;                        /* < 5> [dv:     0x0000] [des: Ring Buffer On] */
    unsigned card_gclk_disable_2;                     /* < 6> [dv:     0x0000] [des: Clock Gated Disable] */
    unsigned sdram_sector_1_addr_2;                   /* < 7> [dv:     0x0000] [des: Start Address of SDRAM sector_1] */
    unsigned sdram_sector_1_size_150_2;               /* < 8> [dv:     0x0000] [des: Length of SDRAM Sector_1] */
    unsigned sdram_sector_2_addr_2;                   /* < 9> [dv:     0x0000] [des: Start Address of SDRAM sector_2] */
    unsigned sdram_sector_2_size_150_2;               /* <10> [dv:     0x0000] [des: Length of SDRAM Sector_2] */
    unsigned sdram_sector_3_addr_2;                   /* <11> [dv:     0x0000] [des: Start Address of SDRAM sector_3] */
    unsigned sdram_sector_3_size_150_2;               /* <12> [dv:     0x0000] [des: Length of SDRAM Sector_3] */
    unsigned sdram_sector_4_addr_2;                   /* <13> [dv:     0x0000] [des: Start Address of SDRAM sector_4] */
    unsigned sdram_sector_4_size_150_2;               /* <14> [dv:     0x0000] [des: Length of SDRAM Sector_4] */
    unsigned sdram_sector_5_addr_2;                   /* <15> [dv:     0x0000] [des: Start Address of SDRAM sector_5] */
    unsigned sdram_sector_5_size_150_2;               /* <16> [dv:     0x0000] [des: Length of SDRAM Sector_5] */
    unsigned sdram_sector_6_addr_2;                   /* <17> [dv:     0x0000] [des: Start Address of SDRAM sector_6] */
    unsigned sdram_sector_6_size_150_2;               /* <18> [dv:     0x0000] [des: Length of SDRAM Sector_6] */
    unsigned sdram_sector_7_addr_2;                   /* <19> [dv:     0x0000] [des: Start Address of SDRAM sector_7] */
    unsigned sdram_sector_7_size_150_2;               /* <20> [dv:     0x0000] [des: Length of SDRAM Sector_7] */
    unsigned sdram_sectro_cnt_2;                      /* <21> [dv:     0x0000] [des: SDRAM Sector Counter] */
    unsigned reserved_1_46;                           /* <22> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_2_39;                           /* <23> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_3_27;                           /* <24> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_4_25;                           /* <25> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_5_23;                           /* <26> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_6_20;                           /* <27> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_7_20;                           /* <28> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_8_19;                           /* <29> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_9_16;                           /* <30> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_10_16;                          /* <31> [dv:     0x0000] [des: Reserved] */
    // GROUP 265 [card_ctl_sd_controller]
    unsigned reserved_0_53;                           /* < 0> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_1_47;                           /* < 1> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_2_40;                           /* < 2> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_3_28;                           /* < 3> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_4_26;                           /* < 4> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_5_24;                           /* < 5> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_6_21;                           /* < 6> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_7_21;                           /* < 7> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_8_20;                           /* < 8> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_9_17;                           /* < 9> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_10_17;                          /* <10> [dv:     0x0000] [des: Reserved] */
    unsigned sd_vol_ctrl_2;                           /* <11> [dv:     0x0003] [des: SD Voltage register] */
    unsigned sd_int_2;                                /* <12> [dv:     0x0000] [des: SD INT Control] */
    unsigned sd_page_num_2;                           /* <13> [dv:     0x0000] [des: SD Page number for this transfer] */
    unsigned sd_config0_2;                            /* <14> [dv:     0x00c0] [des: SD Controller transaction mode select] */
    unsigned sdio_ctrl_2;                             /* <15> [dv:     0x0000] [des: SDIO Controller Reset] */
    unsigned sd_rst_2;                                /* <16> [dv:     0x0000] [des: SD Controller Reset] */
    unsigned sd_config_2;                             /* <17> [dv:     0x3003] [des: SD Controller Type Selection] */
    unsigned sd_ctrl_2;                               /* <18> [dv:     0x0000] [des: SD Controller Control Signal] */
    unsigned sd_status_2;                             /* <19> [dv:     0x0035] [des: SD Controller Status] */
    unsigned sd_state_2;                              /* <20> [dv:     0x4000] [des: SD Controller State Machine] */
    unsigned sd_blocksize_2;                          /* <21> [dv:     0x01ff] [des: SD Controller Data Length] */
    unsigned sd_hwdma_config_2;                       /* <22> [dv:     0x0000] [des: SD HW DMA Configure] */
    unsigned sd_timing_config0_2;                     /* <23> [dv:     0x05ff] [des: SD Controller Response Timer] */
    unsigned sd_timing_config1_2;                     /* <24> [dv:     0x0020] [des: SD Controller CRC Timer] */
    unsigned sd_piodatatx_2;                          /* <25> [dv:     0xffff] [des: SD PIO Mode TX Data] */
    unsigned sd_piodatarx_2;                          /* <26> [dv:     0x0000] [des: SD PIO Mode RX Data] */
    unsigned sd_cmdbuf_0_2;                           /* <27> [dv:     0x00ff] [des: SD Command Buffer0] */
    unsigned sd_cmdbuf_1_2;                           /* <28> [dv:     0x00ff] [des: SD Command Buffer1] */
    unsigned sd_cmdbuf_2_2;                           /* <29> [dv:     0x00ff] [des: SD Command Buffer2] */
    unsigned sd_cmdbuf_3_2;                           /* <30> [dv:     0x00ff] [des: SD Command Buffer3] */
    unsigned sd_cmdbuf_4_2;                           /* <31> [dv:     0x00ff] [des: SD Command Buffer4] */
    // GROUP 266 [card_ctl_sd_controller_and_ms_controller]
    unsigned sd_rspbuf_0_3_2;                         /* < 0> [dv:     0x0000] [des: SD Response Buffer0~3] */
    unsigned sd_rspbuf_4_5_2;                         /* < 1> [dv:     0x0000] [des: SD Response Buffer4~5] */
    unsigned sd_crc16even_0_2;                        /* < 2> [dv:     0x0000] [des: SD CRC16 Buffer0 for Even Dat0(DDR mode)] */
    unsigned sd_crc16even_1_2;                        /* < 3> [dv:     0x0000] [des: SD CRC16 Buffer1 for Even Dat1(DDR mode)] */
    unsigned sd_crc16even_2_2;                        /* < 4> [dv:     0x0000] [des: SD CRC16 Buffer2 for Even Dat2(DDR mode)] */
    unsigned sd_crc16even_3_2;                        /* < 5> [dv:     0x0000] [des: SD CRC16 Buffer3 for Even Dat3(DDR mode)] */
    unsigned sd_crc7buf_2;                            /* < 6> [dv:     0x0001] [des: SD CRC7 Buffer] */
    unsigned sd_crc16buf0_2;                          /* < 7> [dv:     0x0000] [des: SD CRC16 Buffer0] */
    unsigned sd_hw_state_2;                           /* < 8> [dv:     0x0000] [des: Hardware SD State Machine] */
    unsigned sd_crc16buf1_2;                          /* < 9> [dv:     0x0000] [des: SD CRC16 Buffer1] */
    unsigned sd_hw_cmd13_rca_2;                       /* <10> [dv:     0x0000] [des: SD HW DMA RCA] */
    unsigned sd_crc16buf2_2;                          /* <11> [dv:     0x0000] [des: SD CRC16 Buffer2] */
    unsigned sd_tx_dummy_num_2;                       /* <12> [dv:     0x0007] [des: Dummy Clock Number] */
    unsigned sd_crc16buf3_2;                          /* <13> [dv:     0x0000] [des: SD CRC16 Buffer3] */
    unsigned sd_clk_dly_2;                            /* <14> [dv:     0x0002] [des: SD Clock Delay] */
    unsigned reserved_0_54;                           /* <15> [dv:     0x0000] [des: Reserved] */
    unsigned ms_piodmarst_2;                          /* <16> [dv:     0x0000] [des: MS Operation Mode and Reset Signal] */
    unsigned ms_cmd_2;                                /* <17> [dv:     0x0000] [des: MS TPC Code And Data Size] */
    unsigned reserved_1_48;                           /* <18> [dv:     0x0000] [des: Reserved] */
    unsigned ms_hw_state_2;                           /* <19> [dv:     0x0000] [des: Hardware MS State] */
    unsigned ms_modespeed_2;                          /* <20> [dv:     0x00ff] [des: MS Clock Frequency Configure] */
    unsigned ms_timout_2;                             /* <21> [dv:     0x001f] [des: MS Busy Rdy Timer] */
    unsigned ms_state_2;                              /* <22> [dv:     0x0001] [des: MS Controller State Machine] */
    unsigned ms_status_2;                             /* <23> [dv:     0x0000] [des: Debug information of MS Controller] */
    unsigned ms_rddata_0_2;                           /* <24> [dv:     0x0000] [des: Read Data Buffer0] */
    unsigned ms_rddata_1_2;                           /* <25> [dv:     0x0000] [des: Read data Buffer1] */
    unsigned ms_rddata_2_2;                           /* <26> [dv:     0x0000] [des: Read Data Buffer2] */
    unsigned ms_rddata_3_2;                           /* <27> [dv:     0x0000] [des: Read data Buffer3] */
    unsigned ms_crcbuf_70_2;                          /* <28> [dv:     0x0000] [des: Low Byte of MS Data CRC16] */
    unsigned ms_crcbuf_158_2;                         /* <29> [dv:     0x0000] [des: High Byte of MS Data CRC16] */
    unsigned ms_crcerror_2;                           /* <30> [dv:     0x0002] [des: MS CRC Check Result and Busy Rdy TimeOut] */
    unsigned ms_piordy_2;                             /* <31> [dv:     0x0000] [des: MS Controller PIO Ready] */
    // GROUP 267 [card_ctl_ms_controller]
    unsigned ms_wd_data_0_2;                          /* < 0> [dv:     0x0000] [des: MS Controller Write Data Buffer0] */
    unsigned ms_wd_data_1_2;                          /* < 1> [dv:     0x0000] [des: MS Controller Write Data Buffer1] */
    unsigned ms_wd_data_2_2;                          /* < 2> [dv:     0x0000] [des: MS Controller Write Data Buffer2] */
    unsigned ms_wd_data_3_2;                          /* < 3> [dv:     0x0000] [des: MS Controller Write Data Buffer3] */
    unsigned ms_wd_data_4_2;                          /* < 4> [dv:     0x0000] [des: MS Controller Write Data Buffer4] */
    unsigned ms_wd_data_5_2;                          /* < 5> [dv:     0x0000] [des: MS Controller Write Data Buffer5] */
    unsigned ms_wd_data_6_2;                          /* < 6> [dv:     0x0000] [des: MS Controller Write Data Buffer6] */
    unsigned ms_wd_data_7_2;                          /* < 7> [dv:     0x0000] [des: MS Controller Write Data Buffer7] */
    unsigned ms_wd_data_8_2;                          /* < 8> [dv:     0x0000] [des: MS Controller Write Data Buffer8] */
    unsigned ms_wd_data_9_2;                          /* < 9> [dv:     0x0000] [des: MS Controller Write Data Buffer9] */
    unsigned ms_wd_data_10_2;                         /* <10> [dv:     0x0000] [des: MS Controller Write Data Buffer10] */
    unsigned ms_wd_data_11_2;                         /* <11> [dv:     0x0000] [des: MS Controller Write Data Buffer11] */
    unsigned ms_wd_data_12_2;                         /* <12> [dv:     0x0000] [des: MS Controller Write Data Buffer12] */
    unsigned ms_wd_data_13_2;                         /* <13> [dv:     0x0000] [des: MS Controller Write Data Buffer13] */
    unsigned ms_wd_data_14_2;                         /* <14> [dv:     0x0000] [des: MS Controller Write Data Buffer14] */
    unsigned ms_wd_data_15_2;                         /* <15> [dv:     0x0000] [des: MS Controller Write Data Buffer15] */
    unsigned reserved_0_55;                           /* <16> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_1_49;                           /* <17> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_2_41;                           /* <18> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_3_29;                           /* <19> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_4_27;                           /* <20> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_5_25;                           /* <21> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_6_22;                           /* <22> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_7_22;                           /* <23> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_8_21;                           /* <24> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_9_18;                           /* <25> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_10_18;                          /* <26> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_11_11;                          /* <27> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_12_7;                           /* <28> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_13_7;                           /* <29> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_14_7;                           /* <30> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_15_6;                           /* <31> [dv:     0x0000] [des: Reserved] */
    // GROUP 268 [card_ctl_dma_controller_registers]
    unsigned dma_data_2;                              /* < 0> [dv:     0x0000] [des: DMA Write DATA] */
    unsigned dma_srcdst_2;                            /* < 1> [dv:     0x0000] [des: DMA Source and Detination Selection] */
    unsigned dma_size_2;                              /* < 2> [dv:     0x0000] [des: Data Size in DMA Transfer] */
    unsigned dma_hw_stop_rst_2;                       /* < 3> [dv:     0x0000] [des: HW DMA Stop and HW DMA Reset] */
    unsigned dma_ctrl_2;                              /* < 4> [dv:     0x0000] [des: DMA Reset] */
    unsigned dma_base_addr_150_2;                     /* < 5> [dv:     0x0000] [des: DMA Base Address Lower 16 bits] */
    unsigned dma_base_addr_3116_2;                    /* < 6> [dv:     0x0000] [des: DMA Base Address Higher 16 bits] */
    unsigned dma_hw_en_2;                             /* < 7> [dv:     0x0000] [des: HW DMA Enable] */
    unsigned dma_hw_page_addr_0_150_2;                /* < 8> [dv:     0x0000] [des: Lower 16 bits of HW DMA Start Page Address of Block0] */
    unsigned dma_hw_page_addr_0_3116_2;               /* < 9> [dv:     0x0000] [des: Higher 16 bits of HW DMA Start Page Address of Block0] */
    unsigned dma_hw_page_addr_1_150_2;                /* <10> [dv:     0x0000] [des: Lower 16 bits of HW DMA Start Page Address of Block1] */
    unsigned dma_hw_page_addr_1_3116_2;               /* <11> [dv:     0x0000] [des: Higher 16 bits of HW DMA Start Page Address of Block1] */
    unsigned dma_hw_page_addr_2_150_2;                /* <12> [dv:     0x0000] [des: Lower 16 bits of HW DMA Start Page Address of Block2] */
    unsigned dma_hw_page_addr_2_3116_2;               /* <13> [dv:     0x0000] [des: Higher 16 bits of HW DMA Start Page Address of Block2] */
    unsigned dma_hw_page_addr_3_150_2;                /* <14> [dv:     0x0000] [des: Lower 16 bits of HW DMA Start Page Address of Block3] */
    unsigned dma_hw_page_addr_3_3116_2;               /* <15> [dv:     0x0000] [des: Higher 16 bits of HW DMA Start Page Address of Block3] */
    unsigned dma_hw_page_num0_2;                      /* <16> [dv:     0x0000] [des: HW DMA Page Number of Block0] */
    unsigned dma_hw_page_num1_2;                      /* <17> [dv:     0x0000] [des: HW DMA Page Number of Block1] */
    unsigned dma_hw_page_num2_2;                      /* <18> [dv:     0x0000] [des: HW DMA Page Number of Block2] */
    unsigned dma_hw_page_num3_2;                      /* <19> [dv:     0x0000] [des: HW DMA Page Number of Block3] */
    unsigned dma_hw_block_num_2;                      /* <20> [dv:     0x0000] [des: HW DMA Block Number and Block counter] */
    unsigned dma_start_2;                             /* <21> [dv:     0x0000] [des: DMA Start] */
    unsigned dma_hw_page_cnt_2;                       /* <22> [dv:     0x0000] [des: HW DMA Page Counter for Page Number for Each Block] */
    unsigned dma_cmp_2;                               /* <23> [dv:     0x0000] [des: 512 bytes data transfer complete] */
    unsigned dma_int_en_4;                            /* <24> [dv:     0x0000] [des: DMA Interrput Enable] */
    unsigned reserved_0_56;                           /* <25> [dv:     0x0000] [des: Reserved] */
    unsigned dma_hw_wait_num_150_2;                   /* <26> [dv:     0xffff] [des:  Lower 16 Bits of HW Wait Number] */
    unsigned dma_hw_wait_num_3116_2;                  /* <27> [dv:     0xffff] [des: Higher 16 Bits of HW Wait Number] */
    unsigned dma_hw_delay_num_2;                      /* <28> [dv:     0x003f] [des: HW Dealy Number] */
    unsigned reserved_1_50;                           /* <29> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_2_42;                           /* <30> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_3_30;                           /* <31> [dv:     0x0000] [des: Reserved] */
    // GROUP 269
    unsigned grp269_reserved[32];
    // GROUP 270
    unsigned grp270_reserved[32];
    // GROUP 271 [uart4]
    unsigned uart4_data;                              /* < 0> [dv:     0x0000] [des: UART4 Data Port Register] */
    unsigned uart4_lsr;                               /* < 1> [dv:     0x0041] [des: UART4 Line Status Register] */
    unsigned uart4_msr;                               /* < 2> [dv:     0x0000] [des: Modem Status Register] */
    unsigned uart4_lcr;                               /* < 3> [dv:     0x0003] [des: UART4 Line-Control Register] */
    unsigned uart4_mcr;                               /* < 4> [dv:     0x0000] [des: UART4 Modem Control Register] */
    unsigned uart4_div_l;                             /* < 5> [dv:     0x903a] [des: UART4 Clock Divider Low Register] */
    unsigned uart4_div_h;                             /* < 6> [dv:     0x0000] [des: UART4 Clock Divider High Register] */
    unsigned uart4_isc;                               /* < 7> [dv:     0x0000] [des: UART4 Interrupt Status/Control register] */
    unsigned uart4_tx_residue;                        /* < 8> [dv:     0x0000] [des: UART4 TX Residue] */
    unsigned uart4_rx_residue;                        /* < 9> [dv:     0x0000] [des: UART4 RX Residue] */
    unsigned uart4_rx_threshold;                      /* <10> [dv:     0x0000] [des: UART4 RX FIFO Threshold] */
    unsigned grp271_reserved_0;                       /* <11> */
    unsigned grp271_reserved_1;                       /* <12> */
    unsigned grp271_reserved_2;                       /* <13> */
    unsigned grp271_reserved_3;                       /* <14> */
    unsigned grp271_reserved_4;                       /* <15> */
    unsigned grp271_reserved_5;                       /* <16> */
    unsigned grp271_reserved_6;                       /* <17> */
    unsigned grp271_reserved_7;                       /* <18> */
    unsigned grp271_reserved_8;                       /* <19> */
    unsigned grp271_reserved_9;                       /* <20> */
    unsigned grp271_reserved_10;                      /* <21> */
    unsigned grp271_reserved_11;                      /* <22> */
    unsigned grp271_reserved_12;                      /* <23> */
    unsigned grp271_reserved_13;                      /* <24> */
    unsigned grp271_reserved_14;                      /* <25> */
    unsigned grp271_reserved_15;                      /* <26> */
    unsigned grp271_reserved_16;                      /* <27> */
    unsigned grp271_reserved_17;                      /* <28> */
    unsigned grp271_reserved_18;                      /* <29> */
    unsigned grp271_reserved_19;                      /* <30> */
    unsigned grp271_reserved_20;                      /* <31> */
    // GROUP 272 [uart5]
    unsigned uart5_data;                              /* < 0> [dv:     0x0000] [des: UART5 Data Port Register] */
    unsigned uart5_lsr;                               /* < 1> [dv:     0x0041] [des: UART5 Line Status Register] */
    unsigned uart5_msr;                               /* < 2> [dv:     0x0000] [des: Modem Status Register] */
    unsigned uart5_lcr;                               /* < 3> [dv:     0x0003] [des: UART5 Line-Control Register] */
    unsigned uart5_mcr;                               /* < 4> [dv:     0x0000] [des: UART5 Modem Control Register] */
    unsigned uart5_div_l;                             /* < 5> [dv:     0x903a] [des: UART5 Clock Divider Low Register] */
    unsigned uart5_div_h;                             /* < 6> [dv:     0x0000] [des: UART5 Clock Divider High Register] */
    unsigned uart5_isc;                               /* < 7> [dv:     0x0000] [des: UART5 Interrupt Status/Control register] */
    unsigned uart5_tx_residue;                        /* < 8> [dv:     0x0000] [des: UART5 TX Residue] */
    unsigned uart5_rx_residue;                        /* < 9> [dv:     0x0000] [des: UART5 RX Residue] */
    unsigned uart5_rx_threshold;                      /* <10> [dv:     0x0000] [des: UART5 RX FIFO Threshold] */
    unsigned grp272_reserved_0;                       /* <11> */
    unsigned grp272_reserved_1;                       /* <12> */
    unsigned grp272_reserved_2;                       /* <13> */
    unsigned grp272_reserved_3;                       /* <14> */
    unsigned grp272_reserved_4;                       /* <15> */
    unsigned grp272_reserved_5;                       /* <16> */
    unsigned grp272_reserved_6;                       /* <17> */
    unsigned grp272_reserved_7;                       /* <18> */
    unsigned grp272_reserved_8;                       /* <19> */
    unsigned grp272_reserved_9;                       /* <20> */
    unsigned grp272_reserved_10;                      /* <21> */
    unsigned grp272_reserved_11;                      /* <22> */
    unsigned grp272_reserved_12;                      /* <23> */
    unsigned grp272_reserved_13;                      /* <24> */
    unsigned grp272_reserved_14;                      /* <25> */
    unsigned grp272_reserved_15;                      /* <26> */
    unsigned grp272_reserved_16;                      /* <27> */
    unsigned grp272_reserved_17;                      /* <28> */
    unsigned grp272_reserved_18;                      /* <29> */
    unsigned grp272_reserved_19;                      /* <30> */
    unsigned grp272_reserved_20;                      /* <31> */
    // GROUP 273
    unsigned grp273_reserved[32];
    // GROUP 274
    unsigned grp274_reserved[32];
    // GROUP 275 [uadma0]
    unsigned rf_dma0_enable_sel;                      /* < 0> [dv:     0xe080] [des: ] */
    unsigned rf_dma0_start_addr;                      /* < 1> [dv:        0x0] [des: ] */
    unsigned rf_dma0_timeout_set;                     /* < 2> [dv:        0x8] [des: ] */
    unsigned grp275_reserved_0;                       /* < 3> */
    unsigned rf_dma0_wr_adr;                          /* < 4> [dv:        0x0] [des: ] */
    unsigned rf_dma0_rd_adr;                          /* < 5> [dv:        0x0] [des: ] */
    unsigned rf_dma0_length_thr;                      /* < 6> [dv:        0x0] [des: ] */
    unsigned rf_dma0_end_addr;                        /* < 7> [dv:           ] [des: ] */
    unsigned rf_dma0_databytes;                       /* < 8> [dv:           ] [des: ] */
    unsigned rf_dma0_debug_info;                      /* < 9> [dv:           ] [des: ] */
    unsigned grp275_reserved_1;                       /* <10> */
    unsigned grp275_reserved_2;                       /* <11> */
    unsigned grp275_reserved_3;                       /* <12> */
    unsigned grp275_reserved_4;                       /* <13> */
    unsigned grp275_reserved_5;                       /* <14> */
    unsigned grp275_reserved_6;                       /* <15> */
    unsigned rf_dma1_enable_sel;                      /* <16> [dv:     0xf080] [des: ] */
    unsigned rf_dma1_start_addr;                      /* <17> [dv:        0x0] [des: ] */
    unsigned rf_dma1_timeout_set;                     /* <18> [dv:        0x0] [des: ] */
    unsigned grp275_reserved_7;                       /* <19> */
    unsigned rf_dma1_wr_adr;                          /* <20> [dv:           ] [des: ] */
    unsigned rf_dma1_rd_adr;                          /* <21> [dv:           ] [des: 0x0] */
    unsigned rf_dma1_length_thr;                      /* <22> [dv:           ] [des: 0x0] */
    unsigned rf_dma1_end_addr;                        /* <23> [dv:           ] [des: ] */
    unsigned rf_dma1_databytes;                       /* <24> [dv:           ] [des: ] */
    unsigned rf_dma1_debug_info;                      /* <25> [dv:           ] [des: ] */
    unsigned grp275_reserved_8;                       /* <26> */
    unsigned grp275_reserved_9;                       /* <27> */
    unsigned grp275_reserved_10;                      /* <28> */
    unsigned grp275_reserved_11;                      /* <29> */
    unsigned grp275_reserved_12;                      /* <30> */
    unsigned grp275_reserved_13;                      /* <31> */
    // GROUP 276
    unsigned grp276_reserved[32];
    // GROUP 277
    unsigned grp277_reserved[32];
    // GROUP 278
    unsigned grp278_reserved[32];
    // GROUP 279
    unsigned grp279_reserved[32];
    // GROUP 280
    unsigned grp280_reserved[32];
    // GROUP 281
    unsigned grp281_reserved[32];
    // GROUP 282
    unsigned grp282_reserved[32];
    // GROUP 283
    unsigned grp283_reserved[32];
    // GROUP 284
    unsigned grp284_reserved[32];
    // GROUP 285
    unsigned grp285_reserved[32];
    // GROUP 286
    unsigned grp286_reserved[32];
    // GROUP 287
    unsigned grp287_reserved[32];
    // GROUP 288
    unsigned grp288_reserved[32];
    // GROUP 289
    unsigned grp289_reserved[32];
    // GROUP 290
    unsigned grp290_reserved[32];
    // GROUP 291 [temporal_noise_reduction_tnr0]
    unsigned tnr_config1;                             /* < 0> [dv:     0xf621] [des: TNR config register 1] */
    unsigned tnr_config2;                             /* < 1> [dv:     0x0000] [des: TNR config register 2] */
    unsigned motion_th1;                              /* < 2> [dv:     0x0404] [des: YC motion threshold] */
    unsigned motion_th2;                              /* < 3> [dv:     0x0a0c] [des: YC motion threshold] */
    unsigned motion_th3;                              /* < 4> [dv:     0x101c] [des: YC motion threshold] */
    unsigned motion_th4;                              /* < 5> [dv:     0x183c] [des: YC motion threshold] */
    unsigned motion_th5;                              /* < 6> [dv:     0x2062] [des: YC motion threshold] */
    unsigned motion_12_slope;                         /* < 7> [dv:     0x2b20] [des: YC motio slope for tnr weight mapping] */
    unsigned motion_23_slope;                         /* < 8> [dv:     0x2b10] [des: YC motio slope for tnr weight mapping] */
    unsigned motion_34_slope;                         /* < 9> [dv:     0x2008] [des: YC motio slope for tnr weight mapping] */
    unsigned motion_45_slope;                         /* <10> [dv:     0x2007] [des: YC motio slope for tnr weight mapping] */
    unsigned tnr_factor1;                             /* <11> [dv:     0x1414] [des: Data blending factor ] */
    unsigned tnr_factor2;                             /* <12> [dv:     0x1010] [des: Data blending factor ] */
    unsigned tnr_factor3;                             /* <13> [dv:     0x0c0c] [des: Data blending factor ] */
    unsigned tnr_factor4;                             /* <14> [dv:     0x0404] [des: Data blending factor ] */
    unsigned tnr_factor5;                             /* <15> [dv:     0x0000] [des: Data blending factor ] */
    unsigned tnr_color_ystart;                        /* <16> [dv:     0x0000] [des: TNR color mode y minimum value setting] */
    unsigned tnr_color_yend;                          /* <17> [dv:     0x0000] [des: TNR color mode y maximum value setting] */
    unsigned tnr_color_cbstart;                       /* <18> [dv:     0x0000] [des: TNR color mode cb minimum value setting] */
    unsigned tnr_color_cbend;                         /* <19> [dv:     0x0000] [des: TNR color mode cb maximum value setting] */
    unsigned tnr_color_crstart;                       /* <20> [dv:     0x0000] [des: TNR color mode cr minimum value setting] */
    unsigned tnr_color_crend;                         /* <21> [dv:     0x0000] [des: TNR color mode cr maximum value setting] */
    unsigned tnr_color_factor1;                       /* <22> [dv:     0x0000] [des: Color mode blending factor ] */
    unsigned tnr_color_factor2;                       /* <23> [dv:     0x0000] [des: Color mode blending factor ] */
    unsigned tnr_color_factor3;                       /* <24> [dv:     0x0000] [des: Color mode blending factor  ] */
    unsigned tnr_color_factor4;                       /* <25> [dv:     0x0000] [des: Color mode blending factor  ] */
    unsigned tnr_color_factor5;                       /* <26> [dv:     0x0000] [des: Color mode blending factor  ] */
    unsigned clamp_threshold;                         /* <27> [dv:     0x1010] [des: TNR output clamp threshold  ] */
    unsigned clamp_threshold2;                        /* <28> [dv:     0x0404] [des: TNR output clamp threshold 2  ] */
    unsigned tnr_confing3;                            /* <29> [dv:     0x0000] [des: TNR config register 3] */
    unsigned master_xlen;                             /* <30> [dv:        0x0] [des: TNR master mode xlen] */
    unsigned master_ylen;                             /* <31> [dv:        0x0] [des: TNR master mode ylen] */
    // GROUP 292 [temporal_noise_reduction_tnr0]
    unsigned tnr_info;                                /* < 0> [dv:     0x0000] [des: TNR information] */
    unsigned w1_sta_x;                                /* < 1> [dv:     0x0000] [des: Noise meter window] */
    unsigned w1_sta_y;                                /* < 2> [dv:     0x0000] [des: Noise meter window] */
    unsigned w5_sta_x;                                /* < 3> [dv:     0x0000] [des: Noise meter window] */
    unsigned w5_sta_y;                                /* < 4> [dv:     0x0000] [des: Noise meter window] */
    unsigned w_sel;                                   /* < 5> [dv:     0x0000] [des: Noise meter window] */
    unsigned dca_info_yregion;                        /* < 6> [dv:     0x0000] [des: DCA information for vertical region] */
    unsigned dca_info_xregion;                        /* < 7> [dv:     0x0000] [des: DCA information for horizontal region] */
    unsigned dca_max1_weight;                         /* < 8> [dv:     0x0000] [des: DCA first maximum value weight] */
    unsigned dca_max2_weight;                         /* < 9> [dv:     0x0000] [des: DCA second maximum value weight] */
    unsigned dca_min1_weight;                         /* <10> [dv:     0x0000] [des: DCA first minimum value weight] */
    unsigned dca_min2_weight;                         /* <11> [dv:     0x0000] [des: DCA second minimum value weight] */
    unsigned dca_info_config;                         /* <12> [dv:     0x0000] [des: DCA information control ] */
    unsigned tnr_w1_info1;                            /* <13> [dv:     0x0000] [des: TNR window 1 information ] */
    unsigned tnr_w1_info2;                            /* <14> [dv:     0x0000] [des: TNR window 1 information ] */
    unsigned tnr_w2_info1;                            /* <15> [dv:     0x0000] [des: TNR window 2 information ] */
    unsigned tnr_w2_info2;                            /* <16> [dv:     0x0000] [des: TNR window 2 information ] */
    unsigned tnr_w3_info1;                            /* <17> [dv:     0x0000] [des: TNR window 3 information ] */
    unsigned tnr_w3_info2;                            /* <18> [dv:     0x0000] [des: TNR window 3 information ] */
    unsigned tnr_w4_info1;                            /* <19> [dv:     0x0000] [des: TNR window 4 information ] */
    unsigned tnr_w4_info2;                            /* <20> [dv:     0x0000] [des: TNR window 4 information ] */
    unsigned tnr_w5_info1;                            /* <21> [dv:     0x0000] [des: TNR window 5 information ] */
    unsigned tnr_w5_info2;                            /* <22> [dv:     0x0000] [des: TNR window 5 information ] */
    unsigned dca_y_max;                               /* <23> [dv:     0x0000] [des: DCA luma maximum value] */
    unsigned dca_y_min;                               /* <24> [dv:     0x0000] [des: DCA luma minimum value] */
    unsigned dca_y_sum_l;                             /* <25> [dv:     0x0000] [des: DCA luma average value] */
    unsigned dca_y_sum_h;                             /* <26> [dv:     0x0000] [des: DCA luma average value] */
    unsigned chksum_out;                              /* <27> [dv:     0x0000] [des: Check sum value] */
    unsigned grp292_reserved_0;                       /* <28> */
    unsigned grp292_reserved_1;                       /* <29> */
    unsigned grp292_reserved_2;                       /* <30> */
    unsigned grp292_reserved_3;                       /* <31> */
    // GROUP 293 [temporal_noise_reduction_tnr1]
    unsigned tnr_config1_1;                           /* < 0> [dv:     0xf621] [des: TNR config register 1] */
    unsigned tnr_config2_1;                           /* < 1> [dv:     0x0000] [des: TNR config register 2] */
    unsigned motion_th1_1;                            /* < 2> [dv:     0x0404] [des: YC motion threshold] */
    unsigned motion_th2_1;                            /* < 3> [dv:     0x0a0c] [des: YC motion threshold] */
    unsigned motion_th3_1;                            /* < 4> [dv:     0x101c] [des: YC motion threshold] */
    unsigned motion_th4_1;                            /* < 5> [dv:     0x183c] [des: YC motion threshold] */
    unsigned motion_th5_1;                            /* < 6> [dv:     0x2062] [des: YC motion threshold] */
    unsigned motion_12_slope_1;                       /* < 7> [dv:     0x2b20] [des: YC motio slope for tnr weight mapping] */
    unsigned motion_23_slope_1;                       /* < 8> [dv:     0x2b10] [des: YC motio slope for tnr weight mapping] */
    unsigned motion_34_slope_1;                       /* < 9> [dv:     0x2008] [des: YC motio slope for tnr weight mapping] */
    unsigned motion_45_slope_1;                       /* <10> [dv:     0x2007] [des: YC motio slope for tnr weight mapping] */
    unsigned tnr_factor1_1;                           /* <11> [dv:     0x1414] [des: Data blending factor ] */
    unsigned tnr_factor2_1;                           /* <12> [dv:     0x1010] [des: Data blending factor ] */
    unsigned tnr_factor3_1;                           /* <13> [dv:     0x0c0c] [des: Data blending factor ] */
    unsigned tnr_factor4_1;                           /* <14> [dv:     0x0404] [des: Data blending factor ] */
    unsigned tnr_factor5_1;                           /* <15> [dv:     0x0000] [des: Data blending factor ] */
    unsigned tnr_color_ystart_1;                      /* <16> [dv:     0x0000] [des: TNR color mode y minimum value setting] */
    unsigned tnr_color_yend_1;                        /* <17> [dv:     0x0000] [des: TNR color mode y maximum value setting] */
    unsigned tnr_color_cbstart_1;                     /* <18> [dv:     0x0000] [des: TNR color mode cb minimum value setting] */
    unsigned tnr_color_cbend_1;                       /* <19> [dv:     0x0000] [des: TNR color mode cb maximum value setting] */
    unsigned tnr_color_crstart_1;                     /* <20> [dv:     0x0000] [des: TNR color mode cr minimum value setting] */
    unsigned tnr_color_crend_1;                       /* <21> [dv:     0x0000] [des: TNR color mode cr maximum value setting] */
    unsigned tnr_color_factor1_1;                     /* <22> [dv:     0x0000] [des: Color mode blending factor ] */
    unsigned tnr_color_factor2_1;                     /* <23> [dv:     0x0000] [des: Color mode blending factor ] */
    unsigned tnr_color_factor3_1;                     /* <24> [dv:     0x0000] [des: Color mode blending factor  ] */
    unsigned tnr_color_factor4_1;                     /* <25> [dv:     0x0000] [des: Color mode blending factor  ] */
    unsigned tnr_color_factor5_1;                     /* <26> [dv:     0x0000] [des: Color mode blending factor  ] */
    unsigned clamp_threshold_1;                       /* <27> [dv:     0x1010] [des: TNR output clamp threshold  ] */
    unsigned clamp_threshold2_1;                      /* <28> [dv:     0x0404] [des: TNR output clamp threshold 2  ] */
    unsigned tnr_confing3_1;                          /* <29> [dv:     0x0000] [des: TNR config register 3] */
    unsigned master_xlen_1;                           /* <30> [dv:        0x0] [des: TNR master mode xlen] */
    unsigned master_ylen_1;                           /* <31> [dv:        0x0] [des: TNR master mode ylen] */
    // GROUP 294 [temporal_noise_reduction_tnr1]
    unsigned tnr_info_1;                              /* < 0> [dv:     0x0000] [des: TNR information] */
    unsigned w1_sta_x_1;                              /* < 1> [dv:     0x0000] [des: Noise meter window] */
    unsigned w1_sta_y_1;                              /* < 2> [dv:     0x0000] [des: Noise meter window] */
    unsigned w5_sta_x_1;                              /* < 3> [dv:     0x0000] [des: Noise meter window] */
    unsigned w5_sta_y_1;                              /* < 4> [dv:     0x0000] [des: Noise meter window] */
    unsigned w_sel_1;                                 /* < 5> [dv:     0x0000] [des: Noise meter window] */
    unsigned dca_info_yregion_1;                      /* < 6> [dv:     0x0000] [des: DCA information for vertical region] */
    unsigned dca_info_xregion_1;                      /* < 7> [dv:     0x0000] [des: DCA information for horizontal region] */
    unsigned dca_max1_weight_1;                       /* < 8> [dv:     0x0000] [des: DCA first maximum value weight] */
    unsigned dca_max2_weight_1;                       /* < 9> [dv:     0x0000] [des: DCA second maximum value weight] */
    unsigned dca_min1_weight_1;                       /* <10> [dv:     0x0000] [des: DCA first minimum value weight] */
    unsigned dca_min2_weight_1;                       /* <11> [dv:     0x0000] [des: DCA second minimum value weight] */
    unsigned dca_info_config_1;                       /* <12> [dv:     0x0000] [des: DCA information control ] */
    unsigned tnr_w1_info1_1;                          /* <13> [dv:     0x0000] [des: TNR window 1 information ] */
    unsigned tnr_w1_info2_1;                          /* <14> [dv:     0x0000] [des: TNR window 1 information ] */
    unsigned tnr_w2_info1_1;                          /* <15> [dv:     0x0000] [des: TNR window 2 information ] */
    unsigned tnr_w2_info2_1;                          /* <16> [dv:     0x0000] [des: TNR window 2 information ] */
    unsigned tnr_w3_info1_1;                          /* <17> [dv:     0x0000] [des: TNR window 3 information ] */
    unsigned tnr_w3_info2_1;                          /* <18> [dv:     0x0000] [des: TNR window 3 information ] */
    unsigned tnr_w4_info1_1;                          /* <19> [dv:     0x0000] [des: TNR window 4 information ] */
    unsigned tnr_w4_info2_1;                          /* <20> [dv:     0x0000] [des: TNR window 4 information ] */
    unsigned tnr_w5_info1_1;                          /* <21> [dv:     0x0000] [des: TNR window 5 information ] */
    unsigned tnr_w5_info2_1;                          /* <22> [dv:     0x0000] [des: TNR window 5 information ] */
    unsigned dca_y_max_1;                             /* <23> [dv:     0x0000] [des: DCA luma maximum value] */
    unsigned dca_y_min_1;                             /* <24> [dv:     0x0000] [des: DCA luma minimum value] */
    unsigned dca_y_sum_l_1;                           /* <25> [dv:     0x0000] [des: DCA luma average value] */
    unsigned dca_y_sum_h_1;                           /* <26> [dv:     0x0000] [des: DCA luma average value] */
    unsigned chksum_out_1;                            /* <27> [dv:     0x0000] [des: Check sum value] */
    unsigned grp294_reserved_0;                       /* <28> */
    unsigned grp294_reserved_1;                       /* <29> */
    unsigned grp294_reserved_2;                       /* <30> */
    unsigned grp294_reserved_3;                       /* <31> */
    // GROUP 295 [temporal_noise_reduction_image_write_tnriw0]
    unsigned tnriw0_latch_en;                         /* < 0> [dv:     0x0001] [des: tnriw latch enable] */
    unsigned tnriw0_mode_option;                      /* < 1> [dv: 0x000012f3] [des: mode option] */
    unsigned tnriw0_enable;                           /* < 2> [dv: 0x00000030] [des: tnriw enable] */
    unsigned tnriw0_urgent_thd;                       /* < 3> [dv: 0x0000d6d6] [des: tnriw mbus urgent threshold] */
    unsigned tnriw0_cmdq_thd;                         /* < 4> [dv: 0x000001ef] [des: tnriw mbus command queue threshold] */
    unsigned g295_reversed_5;                         /* < 5> [dv:     0x0000] [des: reversed_5] */
    unsigned g295_reversed_6;                         /* < 6> [dv:     0x0000] [des: reversed_6] */
    unsigned g295_reversed_7;                         /* < 7> [dv:     0x0000] [des: reversed_7] */
    unsigned g295_reversed_8;                         /* < 8> [dv:     0x0000] [des: reversed_8] */
    unsigned g295_reversed_9;                         /* < 9> [dv:     0x0000] [des: reversed_9] */
    unsigned tnriw0_luma_iw_base_addr_0;              /* <10> [dv:     0x0000] [des: luma base addr_0] */
    unsigned tnriw0_luma_iw_base_addr_1;              /* <11> [dv:     0x0000] [des: luma base addr for frame_1] */
    unsigned tnriw0_crma_iw_base_addr_0;              /* <12> [dv:     0x0000] [des: chroma base addr _0] */
    unsigned tnriw0_crma_iw_base_addr_1;              /* <13> [dv:     0x0000] [des: chroma base addr _1] */
    unsigned tnriw0_vdo_frame_size;                   /* <14> [dv:     0x0000] [des: video frame size] */
    unsigned tnriw0_vdo_size;                         /* <15> [dv:     0x0000] [des: video size] */
    unsigned tnriw0_debug_mode;                       /* <16> [dv: 0x00000700] [des: debug mode] */
    unsigned tnriw0_chksum_info;                      /* <17> [dv:     0x0000] [des: check sum] */
    unsigned g295_reversed_18;                        /* <18> [dv:     0x0000] [des: reversed_18] */
    unsigned g295_reversed_19;                        /* <19> [dv:     0x0000] [des: reversed_19] */
    unsigned g295_reversed_20;                        /* <20> [dv:     0x0000] [des: reversed_20] */
    unsigned g295_reversed_21;                        /* <21> [dv:     0x0000] [des: reversed_21] */
    unsigned g295_reversed_22;                        /* <22> [dv:     0x0000] [des: reversed_22] */
    unsigned g295_reversed_23;                        /* <23> [dv:     0x0000] [des: reversed_23] */
    unsigned g295_reversed_24;                        /* <24> [dv:     0x0000] [des: reversed_24] */
    unsigned g295_reversed_25;                        /* <25> [dv:     0x0000] [des: reversed_25] */
    unsigned g295_reversed_26;                        /* <26> [dv:     0x0000] [des: reversed_26] */
    unsigned tnriw0_error_flag_info;                  /* <27> [dv:     0x0000] [des: tnriw error flag] */
    unsigned rsdu_data_info;                          /* <28> [dv:     0x0000] [des: RSDU_DATA_INFO] */
    unsigned g295_reversed_29;                        /* <29> [dv:     0x0000] [des: reversed_29] */
    unsigned g295_reversed_30;                        /* <30> [dv:     0x0000] [des: reversed_30] */
    unsigned g295_reversed_31;                        /* <31> [dv:     0x0000] [des: reversed_31] */
    // GROUP 296 [temporal_noise_reduction_image_write_tnriw1]
    unsigned tnriw1_latch_en;                         /* < 0> [dv:     0x0001] [des: tnriw latch enable] */
    unsigned tnriw1_mode_option;                      /* < 1> [dv: 0x000012f3] [des: mode option] */
    unsigned tnriw1_enable;                           /* < 2> [dv: 0x00000030] [des: tnriw enable] */
    unsigned tnriw1_urgent_thd;                       /* < 3> [dv: 0x0000d6d6] [des: tnriw mbus urgent threshold] */
    unsigned tnriw1_cmdq_thd;                         /* < 4> [dv: 0x000001ef] [des: tnriw mbus command queue threshold] */
    unsigned g295_reversed_5_1;                       /* < 5> [dv:     0x0000] [des: reversed_5] */
    unsigned g295_reversed_6_1;                       /* < 6> [dv:     0x0000] [des: reversed_6] */
    unsigned g295_reversed_7_1;                       /* < 7> [dv:     0x0000] [des: reversed_7] */
    unsigned g295_reversed_8_1;                       /* < 8> [dv:     0x0000] [des: reversed_8] */
    unsigned g295_reversed_9_1;                       /* < 9> [dv:     0x0000] [des: reversed_9] */
    unsigned tnriw1_luma_iw_base_addr_0;              /* <10> [dv:     0x0000] [des: luma base addr_0] */
    unsigned tnriw1_luma_iw_base_addr_1;              /* <11> [dv:     0x0000] [des: luma base addr for frame_1] */
    unsigned tnriw1_crma_iw_base_addr_0;              /* <12> [dv:     0x0000] [des: chroma base addr _0] */
    unsigned tnriw1_crma_iw_base_addr_1;              /* <13> [dv:     0x0000] [des: chroma base addr _1] */
    unsigned tnriw1_vdo_frame_size;                   /* <14> [dv:     0x0000] [des: video frame size] */
    unsigned tnriw1_vdo_size;                         /* <15> [dv:     0x0000] [des: video size] */
    unsigned tnriw1_debug_mode;                       /* <16> [dv: 0x00000700] [des: debug mode] */
    unsigned tnriw1_chksum_info;                      /* <17> [dv:     0x0000] [des: check sum] */
    unsigned g295_reversed_18_1;                      /* <18> [dv:     0x0000] [des: reversed_18] */
    unsigned g295_reversed_19_1;                      /* <19> [dv:     0x0000] [des: reversed_19] */
    unsigned g295_reversed_20_1;                      /* <20> [dv:     0x0000] [des: reversed_20] */
    unsigned g295_reversed_21_1;                      /* <21> [dv:     0x0000] [des: reversed_21] */
    unsigned g295_reversed_22_1;                      /* <22> [dv:     0x0000] [des: reversed_22] */
    unsigned g295_reversed_23_1;                      /* <23> [dv:     0x0000] [des: reversed_23] */
    unsigned g295_reversed_24_1;                      /* <24> [dv:     0x0000] [des: reversed_24] */
    unsigned g295_reversed_25_1;                      /* <25> [dv:     0x0000] [des: reversed_25] */
    unsigned g295_reversed_26_1;                      /* <26> [dv:     0x0000] [des: reversed_26] */
    unsigned tnriw1_error_flag_info;                  /* <27> [dv:     0x0000] [des: tnriw error flag] */
    unsigned rsdu_data_info_1;                        /* <28> [dv:     0x0000] [des: RSDU_DATA_INFO] */
    unsigned g295_reversed_29_1;                      /* <29> [dv:     0x0000] [des: reversed_29] */
    unsigned g295_reversed_30_1;                      /* <30> [dv:     0x0000] [des: reversed_30] */
    unsigned g295_reversed_31_1;                      /* <31> [dv:     0x0000] [des: reversed_31] */
    // GROUP 297
    unsigned grp297_reserved[32];
    // GROUP 298 [dynamic_chroma_transient_improvement_dcti01]
    unsigned dcti_config1;                            /* < 0> [dv:     0x7449] [des: DCTI config register 1] */
    unsigned dcti_config2;                            /* < 1> [dv:     0x0031] [des: DCTI config register 2] */
    unsigned dcti_noise;                              /* < 2> [dv:     0x0005] [des: DCTI noise value for smooth region determining] */
    unsigned dcti_gain_weight;                        /* < 3> [dv:     0x00ff] [des: Bandpass output gain weight] */
    unsigned dcti_gain_th;                            /* < 4> [dv:     0xc802] [des: Bandpass output gain threshold] */
    unsigned dcti_bw_th1;                             /* < 5> [dv:     0x000f] [des: Bandwidth calculation threshold 1] */
    unsigned dcti_bw_th2;                             /* < 6> [dv:     0x001e] [des: Bandwidth calculation threshold 2] */
    unsigned dcti_bw_th3;                             /* < 7> [dv:     0x002d] [des: Bandwidth calculation threshold 3] */
    unsigned dcti_h_region;                           /* < 8> [dv:     0x1010] [des: Bandwidth calculation horizontal region] */
    unsigned dcti_v_region;                           /* < 9> [dv:     0x1010] [des: Bandwidth calculation vertical region] */
    unsigned dcti_colorbar;                           /* <10> [dv:     0x0105] [des: DCTI colorbar detection] */
    unsigned dcti_h_size;                             /* <11> [dv:     0x02d0] [des: Frame Width] */
    unsigned dcti_v_size;                             /* <12> [dv:     0x01e0] [des: Frame height] */
    unsigned reverse;                                 /* <13> [dv:        0x0] [des: reverse] */
    unsigned reverse_1;                               /* <14> [dv:        0x0] [des: reverse] */
    unsigned reverse_2;                               /* <15> [dv:        0x0] [des: reverse] */
    unsigned dcti_cb_bw_cal;                          /* <16> [dv:     0x0000] [des: Cb bandwidth value] */
    unsigned dcti_cb_bw_m;                            /* <17> [dv:     0x0000] [des: Calculate bandwidth value and find maxmum  value for Cb] */
    unsigned dcti_cb_bw_m_p;                          /* <18> [dv:     0x0000] [des: Calculate bandwidth value and find maxmum  value for previous frame Cb] */
    unsigned dcti_cr_bw_cal;                          /* <19> [dv:     0x0000] [des: Cr bandwidth value] */
    unsigned dcti_cr_bw_m;                            /* <20> [dv:     0x0000] [des: Calculate bandwidth value and find maxmum  value for Cr] */
    unsigned dcti_cr_bw_m_p;                          /* <21> [dv:     0x0000] [des: Calculate bandwidth value and find maxmum  value for previous frame Cr] */
    unsigned dcti_chksum_out;                         /* <22> [dv:     0x0000] [des: Check sum output] */
    unsigned grp298_reserved_0;                       /* <23> */
    unsigned grp298_reserved_1;                       /* <24> */
    unsigned grp298_reserved_2;                       /* <25> */
    unsigned grp298_reserved_3;                       /* <26> */
    unsigned grp298_reserved_4;                       /* <27> */
    unsigned grp298_reserved_5;                       /* <28> */
    unsigned grp298_reserved_6;                       /* <29> */
    unsigned grp298_reserved_7;                       /* <30> */
    unsigned grp298_reserved_8;                       /* <31> */
    // GROUP 299
    unsigned grp299_reserved[32];
    // GROUP 300 [dynamic_chroma_transient_improvement_dcti11]
    unsigned dcti_config1_1;                          /* < 0> [dv:     0x7449] [des: DCTI config register 1] */
    unsigned dcti_config2_1;                          /* < 1> [dv:     0x0031] [des: DCTI config register 2] */
    unsigned dcti_noise_1;                            /* < 2> [dv:     0x0005] [des: DCTI noise value for smooth region determining] */
    unsigned dcti_gain_weight_1;                      /* < 3> [dv:     0x00ff] [des: Bandpass output gain weight] */
    unsigned dcti_gain_th_1;                          /* < 4> [dv:     0xc802] [des: Bandpass output gain threshold] */
    unsigned dcti_bw_th1_1;                           /* < 5> [dv:     0x000f] [des: Bandwidth calculation threshold 1] */
    unsigned dcti_bw_th2_1;                           /* < 6> [dv:     0x001e] [des: Bandwidth calculation threshold 2] */
    unsigned dcti_bw_th3_1;                           /* < 7> [dv:     0x002d] [des: Bandwidth calculation threshold 3] */
    unsigned dcti_h_region_1;                         /* < 8> [dv:     0x1010] [des: Bandwidth calculation horizontal region] */
    unsigned dcti_v_region_1;                         /* < 9> [dv:     0x1010] [des: Bandwidth calculation vertical region] */
    unsigned dcti_colorbar_1;                         /* <10> [dv:     0x0105] [des: DCTI colorbar detection] */
    unsigned dcti_h_size_1;                           /* <11> [dv:     0x02d0] [des: Frame Width] */
    unsigned dcti_v_size_1;                           /* <12> [dv:     0x01e0] [des: Frame height] */
    unsigned reverse_3;                               /* <13> [dv:        0x0] [des: reverse] */
    unsigned reverse_4;                               /* <14> [dv:        0x0] [des: reverse] */
    unsigned reverse_5;                               /* <15> [dv:        0x0] [des: reverse] */
    unsigned dcti_cb_bw_cal_1;                        /* <16> [dv:     0x0000] [des: Cb bandwidth value] */
    unsigned dcti_cb_bw_m_1;                          /* <17> [dv:     0x0000] [des: Calculate bandwidth value and find maxmum  value for Cb] */
    unsigned dcti_cb_bw_m_p_1;                        /* <18> [dv:     0x0000] [des: Calculate bandwidth value and find maxmum  value for previous frame Cb] */
    unsigned dcti_cr_bw_cal_1;                        /* <19> [dv:     0x0000] [des: Cr bandwidth value] */
    unsigned dcti_cr_bw_m_1;                          /* <20> [dv:     0x0000] [des: Calculate bandwidth value and find maxmum  value for Cr] */
    unsigned dcti_cr_bw_m_p_1;                        /* <21> [dv:     0x0000] [des: Calculate bandwidth value and find maxmum  value for previous frame Cr] */
    unsigned dcti_chksum_out_1;                       /* <22> [dv:     0x0000] [des: Check sum output] */
    unsigned grp300_reserved_0;                       /* <23> */
    unsigned grp300_reserved_1;                       /* <24> */
    unsigned grp300_reserved_2;                       /* <25> */
    unsigned grp300_reserved_3;                       /* <26> */
    unsigned grp300_reserved_4;                       /* <27> */
    unsigned grp300_reserved_5;                       /* <28> */
    unsigned grp300_reserved_6;                       /* <29> */
    unsigned grp300_reserved_7;                       /* <30> */
    unsigned grp300_reserved_8;                       /* <31> */
    // GROUP 301 [dynamic_contrast_adjust_dca]
    unsigned dca_config0;                             /* < 0> [dv:        0x1] [des: DCA config register] */
    unsigned dca_x1x2;                                /* < 1> [dv:        0x0] [des: DCA original luma value] */
    unsigned dca_x3x4;                                /* < 2> [dv:        0x0] [des: DCA original luma value] */
    unsigned dca_x5x6;                                /* < 3> [dv:        0x0] [des: DCA original luma value] */
    unsigned dca_x7x8;                                /* < 4> [dv:        0x0] [des: DCA original luma value] */
    unsigned dca_x9x10;                               /* < 5> [dv:        0x0] [des: DCA original luma value] */
    unsigned dca_x11x12;                              /* < 6> [dv:        0x0] [des: DCA original luma value] */
    unsigned dca_x13x14;                              /* < 7> [dv:        0x0] [des: DCA original luma value] */
    unsigned dca_x15x16;                              /* < 8> [dv:        0x0] [des: DCA original luma value] */
    unsigned dca_y0y1;                                /* < 9> [dv:        0x0] [des: Luma value after DCA curve mapping] */
    unsigned dca_y2y3;                                /* <10> [dv:        0x0] [des: Luma value after DCA curve mapping] */
    unsigned dca_y4y5;                                /* <11> [dv:        0x0] [des: Luma value after DCA curve mapping] */
    unsigned dca_y6y7;                                /* <12> [dv:        0x0] [des: Luma value after DCA curve mapping] */
    unsigned dca_y8y9;                                /* <13> [dv:        0x0] [des: Luma value after DCA curve mapping] */
    unsigned dca_y10y11;                              /* <14> [dv:        0x0] [des: Luma value after DCA curve mapping] */
    unsigned dca_y12y13;                              /* <15> [dv:        0x0] [des: Luma value after DCA curve mapping] */
    unsigned dca_y14y15;                              /* <16> [dv:        0x0] [des: Luma value after DCA curve mapping] */
    unsigned dca_y16y17;                              /* <17> [dv:        0x0] [des: Luma value after DCA curve mapping] */
    unsigned dca_m1m2;                                /* <18> [dv:        0x0] [des: Slope of DCA curve] */
    unsigned dca_m3m4;                                /* <19> [dv:        0x0] [des: Slope of DCA curve] */
    unsigned dca_m5m6;                                /* <20> [dv:        0x0] [des: Slope of DCA curve] */
    unsigned dca_m7m8;                                /* <21> [dv:        0x0] [des: Slope of DCA curve] */
    unsigned dca_m9m10;                               /* <22> [dv:        0x0] [des: Slope of DCA curve] */
    unsigned dca_m11m12;                              /* <23> [dv:        0x0] [des: Slope of DCA curve] */
    unsigned dca_m13m14;                              /* <24> [dv:        0x0] [des: Slope of DCA curve] */
    unsigned dca_m15m16;                              /* <25> [dv:        0x0] [des: Slope of DCA curve] */
    unsigned dca_m17;                                 /* <26> [dv:        0x0] [des: Slope of DCA curve] */
    unsigned grp301_reserved_0;                       /* <27> */
    unsigned grp301_reserved_1;                       /* <28> */
    unsigned grp301_reserved_2;                       /* <29> */
    unsigned grp301_reserved_3;                       /* <30> */
    unsigned grp301_reserved_4;                       /* <31> */
    // GROUP 302 [dynamic_contrast_adjust_dca]
    unsigned dsa_y0y1;                                /* < 0> [dv:        0x0] [des: DSA UV gain] */
    unsigned dsa_y2y3;                                /* < 1> [dv:        0x0] [des: DSA UV gain] */
    unsigned dsa_y4y5;                                /* < 2> [dv:        0x0] [des: DSA UV gain] */
    unsigned dsa_y6y7;                                /* < 3> [dv:        0x0] [des: DSA UV gain] */
    unsigned dsa_y8y9;                                /* < 4> [dv:        0x0] [des: DSA UV gain] */
    unsigned dsa_y10y11;                              /* < 5> [dv:        0x0] [des: DSA UV gain] */
    unsigned dsa_y12y13;                              /* < 6> [dv:        0x0] [des: DSA UV gain] */
    unsigned dsa_y14y15;                              /* < 7> [dv:        0x0] [des: DSA UV gain] */
    unsigned dsa_y16y17;                              /* < 8> [dv:        0x0] [des: DSA UV gain] */
    unsigned dsa_m1m2;                                /* < 9> [dv:        0x0] [des: Slope of DSA UV gain curve] */
    unsigned dsa_m3m4;                                /* <10> [dv:        0x0] [des: Slope of DSA UV gain curve] */
    unsigned dsa_m5m6;                                /* <11> [dv:        0x0] [des: Slope of DSA UV gain curve] */
    unsigned dsa_m7m8;                                /* <12> [dv:        0x0] [des: Slope of DSA UV gain curve] */
    unsigned dsa_m9m10;                               /* <13> [dv:        0x0] [des: Slope of DSA UV gain curve] */
    unsigned dsa_m11m12;                              /* <14> [dv:        0x0] [des: Slope of DSA UV gain curve] */
    unsigned dsa_m13m14;                              /* <15> [dv:        0x0] [des: Slope of DSA UV gain curve] */
    unsigned dsa_m15m16;                              /* <16> [dv:        0x0] [des: Slope of DSA UV gain curve] */
    unsigned dsa_m17;                                 /* <17> [dv:        0x0] [des: Slope of DSA UV gain curve] */
    unsigned dsa_chksum_out;                          /* <18> [dv:        0x0] [des: Check sum output] */
    unsigned grp302_reserved_0;                       /* <19> */
    unsigned grp302_reserved_1;                       /* <20> */
    unsigned grp302_reserved_2;                       /* <21> */
    unsigned grp302_reserved_3;                       /* <22> */
    unsigned grp302_reserved_4;                       /* <23> */
    unsigned grp302_reserved_5;                       /* <24> */
    unsigned grp302_reserved_6;                       /* <25> */
    unsigned grp302_reserved_7;                       /* <26> */
    unsigned grp302_reserved_8;                       /* <27> */
    unsigned grp302_reserved_9;                       /* <28> */
    unsigned grp302_reserved_10;                      /* <29> */
    unsigned grp302_reserved_11;                      /* <30> */
    unsigned grp302_reserved_12;                      /* <31> */
    // GROUP 303 [dynamic_contrast_adjust_dca]
    unsigned dca_config0_1;                           /* < 0> [dv:        0x1] [des: DCA config register] */
    unsigned dca_x1x2_1;                              /* < 1> [dv:        0x0] [des: DCA original luma value] */
    unsigned dca_x3x4_1;                              /* < 2> [dv:        0x0] [des: DCA original luma value] */
    unsigned dca_x5x6_1;                              /* < 3> [dv:        0x0] [des: DCA original luma value] */
    unsigned dca_x7x8_1;                              /* < 4> [dv:        0x0] [des: DCA original luma value] */
    unsigned dca_x9x10_1;                             /* < 5> [dv:        0x0] [des: DCA original luma value] */
    unsigned dca_x11x12_1;                            /* < 6> [dv:        0x0] [des: DCA original luma value] */
    unsigned dca_x13x14_1;                            /* < 7> [dv:        0x0] [des: DCA original luma value] */
    unsigned dca_x15x16_1;                            /* < 8> [dv:        0x0] [des: DCA original luma value] */
    unsigned dca_y0y1_1;                              /* < 9> [dv:        0x0] [des: Luma value after DCA curve mapping] */
    unsigned dca_y2y3_1;                              /* <10> [dv:        0x0] [des: Luma value after DCA curve mapping] */
    unsigned dca_y4y5_1;                              /* <11> [dv:        0x0] [des: Luma value after DCA curve mapping] */
    unsigned dca_y6y7_1;                              /* <12> [dv:        0x0] [des: Luma value after DCA curve mapping] */
    unsigned dca_y8y9_1;                              /* <13> [dv:        0x0] [des: Luma value after DCA curve mapping] */
    unsigned dca_y10y11_1;                            /* <14> [dv:        0x0] [des: Luma value after DCA curve mapping] */
    unsigned dca_y12y13_1;                            /* <15> [dv:        0x0] [des: Luma value after DCA curve mapping] */
    unsigned dca_y14y15_1;                            /* <16> [dv:        0x0] [des: Luma value after DCA curve mapping] */
    unsigned dca_y16y17_1;                            /* <17> [dv:        0x0] [des: Luma value after DCA curve mapping] */
    unsigned dca_m1m2_1;                              /* <18> [dv:        0x0] [des: Slope of DCA curve] */
    unsigned dca_m3m4_1;                              /* <19> [dv:        0x0] [des: Slope of DCA curve] */
    unsigned dca_m5m6_1;                              /* <20> [dv:        0x0] [des: Slope of DCA curve] */
    unsigned dca_m7m8_1;                              /* <21> [dv:        0x0] [des: Slope of DCA curve] */
    unsigned dca_m9m10_1;                             /* <22> [dv:        0x0] [des: Slope of DCA curve] */
    unsigned dca_m11m12_1;                            /* <23> [dv:        0x0] [des: Slope of DCA curve] */
    unsigned dca_m13m14_1;                            /* <24> [dv:        0x0] [des: Slope of DCA curve] */
    unsigned dca_m15m16_1;                            /* <25> [dv:        0x0] [des: Slope of DCA curve] */
    unsigned dca_m17_1;                               /* <26> [dv:        0x0] [des: Slope of DCA curve] */
    unsigned grp303_reserved_0;                       /* <27> */
    unsigned grp303_reserved_1;                       /* <28> */
    unsigned grp303_reserved_2;                       /* <29> */
    unsigned grp303_reserved_3;                       /* <30> */
    unsigned grp303_reserved_4;                       /* <31> */
    // GROUP 304 [dynamic_contrast_adjust_dca]
    unsigned dsa_y0y1_1;                              /* < 0> [dv:        0x0] [des: DSA UV gain] */
    unsigned dsa_y2y3_1;                              /* < 1> [dv:        0x0] [des: DSA UV gain] */
    unsigned dsa_y4y5_1;                              /* < 2> [dv:        0x0] [des: DSA UV gain] */
    unsigned dsa_y6y7_1;                              /* < 3> [dv:        0x0] [des: DSA UV gain] */
    unsigned dsa_y8y9_1;                              /* < 4> [dv:        0x0] [des: DSA UV gain] */
    unsigned dsa_y10y11_1;                            /* < 5> [dv:        0x0] [des: DSA UV gain] */
    unsigned dsa_y12y13_1;                            /* < 6> [dv:        0x0] [des: DSA UV gain] */
    unsigned dsa_y14y15_1;                            /* < 7> [dv:        0x0] [des: DSA UV gain] */
    unsigned dsa_y16y17_1;                            /* < 8> [dv:        0x0] [des: DSA UV gain] */
    unsigned dsa_m1m2_1;                              /* < 9> [dv:        0x0] [des: Slope of DSA UV gain curve] */
    unsigned dsa_m3m4_1;                              /* <10> [dv:        0x0] [des: Slope of DSA UV gain curve] */
    unsigned dsa_m5m6_1;                              /* <11> [dv:        0x0] [des: Slope of DSA UV gain curve] */
    unsigned dsa_m7m8_1;                              /* <12> [dv:        0x0] [des: Slope of DSA UV gain curve] */
    unsigned dsa_m9m10_1;                             /* <13> [dv:        0x0] [des: Slope of DSA UV gain curve] */
    unsigned dsa_m11m12_1;                            /* <14> [dv:        0x0] [des: Slope of DSA UV gain curve] */
    unsigned dsa_m13m14_1;                            /* <15> [dv:        0x0] [des: Slope of DSA UV gain curve] */
    unsigned dsa_m15m16_1;                            /* <16> [dv:        0x0] [des: Slope of DSA UV gain curve] */
    unsigned dsa_m17_1;                               /* <17> [dv:        0x0] [des: Slope of DSA UV gain curve] */
    unsigned dsa_chksum_out_1;                        /* <18> [dv:        0x0] [des: Check sum output] */
    unsigned grp304_reserved_0;                       /* <19> */
    unsigned grp304_reserved_1;                       /* <20> */
    unsigned grp304_reserved_2;                       /* <21> */
    unsigned grp304_reserved_3;                       /* <22> */
    unsigned grp304_reserved_4;                       /* <23> */
    unsigned grp304_reserved_5;                       /* <24> */
    unsigned grp304_reserved_6;                       /* <25> */
    unsigned grp304_reserved_7;                       /* <26> */
    unsigned grp304_reserved_8;                       /* <27> */
    unsigned grp304_reserved_9;                       /* <28> */
    unsigned grp304_reserved_10;                      /* <29> */
    unsigned grp304_reserved_11;                      /* <30> */
    unsigned grp304_reserved_12;                      /* <31> */
    // GROUP 305 [brightness_bri0]
    unsigned img0_bri_en;                             /* < 0> [dv:     0x0000] [des: BRI Enable] */
    unsigned img0_bri_sram_ctrl;                      /* < 1> [dv:     0x0000] [des: SRAM Control Register] */
    unsigned img0_bri_sram_addr;                      /* < 2> [dv:     0x0000] [des: SRAM Address Register] */
    unsigned img0_bri_sram_write_data;                /* < 3> [dv:     0x0000] [des: SRAM Write Data Register] */
    unsigned img0_bri_sram_read_data;                 /* < 4> [dv:     0x0000] [des: SRAM Read Data Register] */
    unsigned img0_bri_latch_en;                       /* < 5> [dv:     0x0001] [des: Register Latch Mode Enable] */
    unsigned grp305_reserved_0;                       /* < 6> */
    unsigned grp305_reserved_1;                       /* < 7> */
    unsigned grp305_reserved_2;                       /* < 8> */
    unsigned grp305_reserved_3;                       /* < 9> */
    unsigned grp305_reserved_4;                       /* <10> */
    unsigned grp305_reserved_5;                       /* <11> */
    unsigned grp305_reserved_6;                       /* <12> */
    unsigned grp305_reserved_7;                       /* <13> */
    unsigned grp305_reserved_8;                       /* <14> */
    unsigned grp305_reserved_9;                       /* <15> */
    unsigned grp305_reserved_10;                      /* <16> */
    unsigned grp305_reserved_11;                      /* <17> */
    unsigned grp305_reserved_12;                      /* <18> */
    unsigned grp305_reserved_13;                      /* <19> */
    unsigned grp305_reserved_14;                      /* <20> */
    unsigned grp305_reserved_15;                      /* <21> */
    unsigned grp305_reserved_16;                      /* <22> */
    unsigned grp305_reserved_17;                      /* <23> */
    unsigned grp305_reserved_18;                      /* <24> */
    unsigned grp305_reserved_19;                      /* <25> */
    unsigned grp305_reserved_20;                      /* <26> */
    unsigned grp305_reserved_21;                      /* <27> */
    unsigned grp305_reserved_22;                      /* <28> */
    unsigned grp305_reserved_23;                      /* <29> */
    unsigned grp305_reserved_24;                      /* <30> */
    unsigned grp305_reserved_25;                      /* <31> */
    // GROUP 306 [brightness_bri1]
    unsigned img0_bri_en_1;                           /* < 0> [dv:     0x0000] [des: BRI Enable] */
    unsigned img0_bri_sram_ctrl_1;                    /* < 1> [dv:     0x0000] [des: SRAM Control Register] */
    unsigned img0_bri_sram_addr_1;                    /* < 2> [dv:     0x0000] [des: SRAM Address Register] */
    unsigned img0_bri_sram_write_data_1;              /* < 3> [dv:     0x0000] [des: SRAM Write Data Register] */
    unsigned img0_bri_sram_read_data_1;               /* < 4> [dv:     0x0000] [des: SRAM Read Data Register] */
    unsigned img0_bri_latch_en_1;                     /* < 5> [dv:     0x0001] [des: Register Latch Mode Enable] */
    unsigned grp306_reserved_0;                       /* < 6> */
    unsigned grp306_reserved_1;                       /* < 7> */
    unsigned grp306_reserved_2;                       /* < 8> */
    unsigned grp306_reserved_3;                       /* < 9> */
    unsigned grp306_reserved_4;                       /* <10> */
    unsigned grp306_reserved_5;                       /* <11> */
    unsigned grp306_reserved_6;                       /* <12> */
    unsigned grp306_reserved_7;                       /* <13> */
    unsigned grp306_reserved_8;                       /* <14> */
    unsigned grp306_reserved_9;                       /* <15> */
    unsigned grp306_reserved_10;                      /* <16> */
    unsigned grp306_reserved_11;                      /* <17> */
    unsigned grp306_reserved_12;                      /* <18> */
    unsigned grp306_reserved_13;                      /* <19> */
    unsigned grp306_reserved_14;                      /* <20> */
    unsigned grp306_reserved_15;                      /* <21> */
    unsigned grp306_reserved_16;                      /* <22> */
    unsigned grp306_reserved_17;                      /* <23> */
    unsigned grp306_reserved_18;                      /* <24> */
    unsigned grp306_reserved_19;                      /* <25> */
    unsigned grp306_reserved_20;                      /* <26> */
    unsigned grp306_reserved_21;                      /* <27> */
    unsigned grp306_reserved_22;                      /* <28> */
    unsigned grp306_reserved_23;                      /* <29> */
    unsigned grp306_reserved_24;                      /* <30> */
    unsigned grp306_reserved_25;                      /* <31> */
    // GROUP 307 [tpiiw_0_tpiiw0]
    unsigned tpiiw0_latch_en;                         /* < 0> [dv:     0x0001] [des: tpiiw latch enable] */
    unsigned tpiiw0_mode_option;                      /* < 1> [dv: 0x000012f3] [des: mode option] */
    unsigned tpiiw0_enable;                           /* < 2> [dv: 0x00000030] [des: tpiiw enable] */
    unsigned tpiiw0_urgent_thd;                       /* < 3> [dv: 0x0000d6d6] [des: tpiiw mbus urgent threshold] */
    unsigned tpiiw0_cmdq_thd;                         /* < 4> [dv: 0x000001ef] [des: tpiiw mbus command queue threshold] */
    unsigned g307_reversed_5;                         /* < 5> [dv:     0x0000] [des: reversed_5] */
    unsigned g307_reversed_6;                         /* < 6> [dv:     0x0000] [des: reversed_6] */
    unsigned g307_reversed_7;                         /* < 7> [dv:     0x0000] [des: reversed_7] */
    unsigned g307_reversed_8;                         /* < 8> [dv:     0x0000] [des: reversed_8] */
    unsigned g307_reversed_9;                         /* < 9> [dv:     0x0000] [des: reversed_9] */
    unsigned tpiiw0_luma_iw_base_addr_0;              /* <10> [dv:     0x0000] [des: luma base addr_0] */
    unsigned tpiiw0_luma_iw_base_addr_1;              /* <11> [dv:     0x0000] [des: luma base addr for frame_1] */
    unsigned tpiiw0_crma_iw_base_addr_0;              /* <12> [dv:     0x0000] [des: chroma base addr _0] */
    unsigned tpiiw0_crma_iw_base_addr_1;              /* <13> [dv:     0x0000] [des: chroma base addr _1] */
    unsigned tpiiw0_vdo_frame_size;                   /* <14> [dv:     0x0000] [des: video frame size] */
    unsigned tpiiw0_vdo_size;                         /* <15> [dv:     0x0000] [des: video size] */
    unsigned tpiiw0_debug_mode;                       /* <16> [dv: 0x00000700] [des: debug mode] */
    unsigned tpiiw0_chksum_info;                      /* <17> [dv:     0x0000] [des: check sum] */
    unsigned irq_line_cnt;                            /* <18> [dv:     0x0000] [des: IRQ_LINE_CNT] */
    unsigned irq_msk;                                 /* <19> [dv:     0x0000] [des: irq_msk] */
    unsigned irq_status;                              /* <20> [dv:     0x0000] [des: irq_status] */
    unsigned time_out_cnt;                            /* <21> [dv:    0x83d60] [des: time_out_cnt] */
    unsigned g307_reversed_22;                        /* <22> [dv:     0x0000] [des: reversed_22] */
    unsigned g307_reversed_23;                        /* <23> [dv:     0x0000] [des: reversed_23] */
    unsigned others_control;                          /* <24> [dv:     0x0005] [des: others_control] */
    unsigned g307_reversed_25;                        /* <25> [dv:     0x0000] [des: reversed_25] */
    unsigned g307_reversed_26;                        /* <26> [dv:     0x0000] [des: reversed_26] */
    unsigned tpiiw0_error_flag_info;                  /* <27> [dv:     0x0000] [des: tpiiw error flag] */
    unsigned rsdu_data_info_2;                        /* <28> [dv:     0x0000] [des: RSDU_DATA_INFO] */
    unsigned g307_reversed_29;                        /* <29> [dv:     0x0000] [des: reversed_29] */
    unsigned g307_reversed_30;                        /* <30> [dv:     0x0000] [des: reversed_30] */
    unsigned g307_reversed_31;                        /* <31> [dv:     0x0000] [des: reversed_31] */
    // GROUP 308 [tpiiw_1_tpiiw1]
    unsigned tpiiw0_latch_en_1;                       /* < 0> [dv:     0x0001] [des: tpiiw latch enable] */
    unsigned tpiiw0_mode_option_1;                    /* < 1> [dv: 0x000012f3] [des: mode option] */
    unsigned tpiiw0_enable_1;                         /* < 2> [dv: 0x00000030] [des: tpiiw enable] */
    unsigned tpiiw0_urgent_thd_1;                     /* < 3> [dv: 0x0000d6d6] [des: tpiiw mbus urgent threshold] */
    unsigned tpiiw0_cmdq_thd_1;                       /* < 4> [dv: 0x000001ef] [des: tpiiw mbus command queue threshold] */
    unsigned g307_reversed_5_1;                       /* < 5> [dv:     0x0000] [des: reversed_5] */
    unsigned g307_reversed_6_1;                       /* < 6> [dv:     0x0000] [des: reversed_6] */
    unsigned g307_reversed_7_1;                       /* < 7> [dv:     0x0000] [des: reversed_7] */
    unsigned g307_reversed_8_1;                       /* < 8> [dv:     0x0000] [des: reversed_8] */
    unsigned g307_reversed_9_1;                       /* < 9> [dv:     0x0000] [des: reversed_9] */
    unsigned tpiiw0_luma_iw_base_addr_0_1;            /* <10> [dv:     0x0000] [des: luma base addr_0] */
    unsigned tpiiw0_luma_iw_base_addr_1_1;            /* <11> [dv:     0x0000] [des: luma base addr for frame_1] */
    unsigned tpiiw0_crma_iw_base_addr_0_1;            /* <12> [dv:     0x0000] [des: chroma base addr _0] */
    unsigned tpiiw0_crma_iw_base_addr_1_1;            /* <13> [dv:     0x0000] [des: chroma base addr _1] */
    unsigned tpiiw0_vdo_frame_size_1;                 /* <14> [dv:     0x0000] [des: video frame size] */
    unsigned tpiiw0_vdo_size_1;                       /* <15> [dv:     0x0000] [des: video size] */
    unsigned tpiiw0_debug_mode_1;                     /* <16> [dv: 0x00000700] [des: debug mode] */
    unsigned tpiiw0_chksum_info_1;                    /* <17> [dv:     0x0000] [des: check sum] */
    unsigned irq_line_cnt_1;                          /* <18> [dv:     0x0000] [des: IRQ_LINE_CNT] */
    unsigned irq_msk_1;                               /* <19> [dv:     0x0000] [des: irq_msk] */
    unsigned irq_status_1;                            /* <20> [dv:     0x0000] [des: irq_status] */
    unsigned time_out_cnt_1;                          /* <21> [dv:    0x83d60] [des: time_out_cnt] */
    unsigned g307_reversed_22_1;                      /* <22> [dv:     0x0000] [des: reversed_22] */
    unsigned g307_reversed_23_1;                      /* <23> [dv:     0x0000] [des: reversed_23] */
    unsigned others_control_1;                        /* <24> [dv:     0x0005] [des: others_control] */
    unsigned g307_reversed_25_1;                      /* <25> [dv:     0x0000] [des: reversed_25] */
    unsigned g307_reversed_26_1;                      /* <26> [dv:     0x0000] [des: reversed_26] */
    unsigned tpiiw0_error_flag_info_1;                /* <27> [dv:     0x0000] [des: tpiiw error flag] */
    unsigned rsdu_data_info_3;                        /* <28> [dv:     0x0000] [des: RSDU_DATA_INFO] */
    unsigned g307_reversed_29_1;                      /* <29> [dv:     0x0000] [des: reversed_29] */
    unsigned g307_reversed_30_1;                      /* <30> [dv:     0x0000] [des: reversed_30] */
    unsigned g307_reversed_31_1;                      /* <31> [dv:     0x0000] [des: reversed_31] */
    // GROUP 309
    unsigned grp309_reserved[32];
    // GROUP 310 [tvd]
    unsigned control0_2;                              /* < 0> [dv:        0x0] [des: ] */
    unsigned control1_2;                              /* < 1> [dv:        0x1] [des: ] */
    unsigned control2_2;                              /* < 2> [dv:       0x4F] [des: ] */
    unsigned yc_separation_control;                   /* < 3> [dv:        0x0] [des: ] */
    unsigned luma_agc_value;                          /* < 4> [dv:       0xDD] [des: ] */
    unsigned noise_threshold_reg;                     /* < 5> [dv:       0x32] [des: ] */
    unsigned adc_swap_vcr_overrides;                  /* < 6> [dv:        0x0] [des: ] */
    unsigned output_control;                          /* < 7> [dv:       0x40] [des: ] */
    unsigned luma_contrast_adjustment;                /* < 8> [dv:       0x80] [des: ] */
    unsigned luma_brightness_adjustment;              /* < 9> [dv:       0x20] [des: ] */
    unsigned chroma_saturation_adjustment;            /* <10> [dv:       0x80] [des: ] */
    unsigned chroma_hue_phase_adjustment;             /* <11> [dv:        0x0] [des: ] */
    unsigned chroma_agc;                              /* <12> [dv:       0x8A] [des: ] */
    unsigned chroma_kill_mode;                        /* <13> [dv:        0x7] [des: ] */
    unsigned grp310_reserved_0;                       /* <14> */
    unsigned chroma_kill_reg;                         /* <15> [dv:        0x1] [des: ] */
    unsigned agc_peak_nominal_reg;                    /* <16> [dv:       0x0A] [des: ] */
    unsigned agc_peak_and_gate_control;               /* <17> [dv:        0x9] [des: ] */
    unsigned blue_screen_y_reg;                       /* <18> [dv:       0x10] [des: ] */
    unsigned blue_screen_cb_reg;                      /* <19> [dv:       0xB4] [des: ] */
    unsigned blue_screen_cr_reg;                      /* <20> [dv:       0x80] [des: ] */
    unsigned hdetect_clamp_level_reg;                 /* <21> [dv:       0x20] [des: ] */
    unsigned lock_count;                              /* <22> [dv:       0x74] [des: ] */
    unsigned hloop_maxstate;                          /* <23> [dv:       0x0B] [des: ] */
    unsigned chroma_dto_increment_h;                  /* <24> [dv:       0x21] [des: ] */
    unsigned chroma_dto_increment_mh;                 /* <25> [dv:       0xF0] [des: ] */
    unsigned chroma_dto_increment_ml;                 /* <26> [dv:       0x7C] [des: ] */
    unsigned chroma_dto_increment_l;                  /* <27> [dv:       0x1F] [des: ] */
    unsigned horizontal_sync_dto_increment_h;         /* <28> [dv:       0x20] [des: ] */
    unsigned horizontal_sync_dto_increment_mh;        /* <29> [dv:        0x0] [des: ] */
    unsigned horizontal_sync_dto_increment_ml;        /* <30> [dv:        0x0] [des: ] */
    unsigned horizontal_sync_dto_increment_l;         /* <31> [dv:        0x0] [des: ] */
    // GROUP 311 [tvd]
    unsigned horizontal_sync_rising_edge_occurrence_time;           /* < 0> [dv:       0x3E] [des: ] */
    unsigned horizontal_sync_phase_offset;                          /* < 1> [dv:       0x3E] [des: ] */
    unsigned horizontal_sync_detect_window_start_time;              /* < 2> [dv:        0x0] [des: ] */
    unsigned horizontal_sync_detect_window_end_time;                /* < 3> [dv:       0x80] [des: ] */
    unsigned clampagc_control;                                      /* < 4> [dv:       0xD3] [des: ] */
    unsigned hsync_width_status;                                    /* < 5> [dv:           ] [des: ] */
    unsigned horizontal_sync_rising_edge_detect_window_start_time;  /* < 6> [dv:       0xED] [des: ] */
    unsigned horizontal_sync_rising_edge_detect_window_end_time;    /* < 7> [dv:       0x5A] [des: ] */
    unsigned dr_freq_reg;                                           /* < 8> [dv:       0x41] [des: ] */
    unsigned db_freq_reg;                                           /* < 9> [dv:       0xEC] [des: ] */
    unsigned hsync_filter_gate_start_time;                          /* <10> [dv:       0xD6] [des: ] */
    unsigned hsync_filter_gate_end_time;                            /* <11> [dv:       0x4E] [des: ] */
    unsigned chroma_burst_gate_start_time;                          /* <12> [dv:       0x32] [des: ] */
    unsigned chroma_burst_gate_end_time;                            /* <13> [dv:       0x46] [des: ] */
    unsigned active_video_horizontal_start_time;                    /* <14> [dv:       0x82] [des: ] */
    unsigned active_video_horizontal_width;                         /* <15> [dv:       0x50] [des: ] */
    unsigned active_video_vertical_start;                           /* <16> [dv:       0x22] [des: ] */
    unsigned active_video_vertical_height;                          /* <17> [dv:       0x61] [des: ] */
    unsigned vsync_h_lockout_start;                                 /* <18> [dv:       0x70] [des: ] */
    unsigned vsync_h_lockout_end;                                   /* <19> [dv:       0x0E] [des: ] */
    unsigned vsync_agc_lockout_start;                               /* <20> [dv:       0x6C] [des: ] */
    unsigned vsync_agc_lockout_end;                                 /* <21> [dv:       0x10] [des: ] */
    unsigned vsync_vbi_lockout_start;                               /* <22> [dv:        0x0] [des: ] */
    unsigned vsync_vbi_lockout_end;                                 /* <23> [dv:       0x23] [des: ] */
    unsigned vsync_cntl_reg;                                        /* <24> [dv:        0x1] [des: ] */
    unsigned vsync_time_constant;                                   /* <25> [dv:        0xA] [des: ] */
    unsigned status_register_1;                                     /* <26> [dv:           ] [des: ] */
    unsigned status_register_2;                                     /* <27> [dv:           ] [des: ] */
    unsigned status_register_3;                                     /* <28> [dv:           ] [des: ] */
    unsigned grp311_reserved_0;                                     /* <29> */
    unsigned grp311_reserved_1;                                     /* <30> */
    unsigned soft_reset_control;                                    /* <31> [dv:        0x0] [des: ] */
    // GROUP 312
    unsigned grp312_reserved[32];
    // GROUP 313 [tvd]
    unsigned grp313_reserved_0;                        /* < 0> */
    unsigned grp313_reserved_1;                        /* < 1> */
    unsigned grp313_reserved_2;                        /* < 2> */
    unsigned grp313_reserved_3;                        /* < 3> */
    unsigned grp313_reserved_4;                        /* < 4> */
    unsigned grp313_reserved_5;                        /* < 5> */
    unsigned grp313_reserved_6;                        /* < 6> */
    unsigned grp313_reserved_7;                        /* < 7> */
    unsigned grp313_reserved_8;                        /* < 8> */
    unsigned grp313_reserved_9;                        /* < 9> */
    unsigned grp313_reserved_10;                       /* <10> */
    unsigned grp313_reserved_11;                       /* <11> */
    unsigned grp313_reserved_12;                       /* <12> */
    unsigned grp313_reserved_13;                       /* <13> */
    unsigned grp313_reserved_14;                       /* <14> */
    unsigned grp313_reserved_15;                       /* <15> */
    unsigned grp313_reserved_16;                       /* <16> */
    unsigned grp313_reserved_17;                       /* <17> */
    unsigned horizontal_sync_dto_increment_status_h;   /* <18> [dv:           ] [des: ] */
    unsigned horizontal_sync_dto_increment_status_mh;  /* <19> [dv:           ] [des: ] */
    unsigned horizontal_sync_dto_increment_status_ml;  /* <20> [dv:           ] [des: ] */
    unsigned horizontal_sync_dto_increment_status_l;   /* <21> [dv:           ] [des: ] */
    unsigned chroma_dto_increment_status_h;            /* <22> [dv:           ] [des: ] */
    unsigned chroma_dto_increment_status_mh;           /* <23> [dv:           ] [des: ] */
    unsigned chroma_dto_increment_status_ml;           /* <24> [dv:           ] [des: ] */
    unsigned chroma_dto_increment_status_l;            /* <25> [dv:           ] [des: ] */
    unsigned agc_gain_status_h;                        /* <26> [dv:        0x0] [des: ] */
    unsigned agc_gain_status_l;                        /* <27> [dv:           ] [des: ] */
    unsigned chroma_magnitude_status;                  /* <28> [dv:           ] [des: ] */
    unsigned chroma_gain_status_h;                     /* <29> [dv:           ] [des: ] */
    unsigned chroma_gain_status_l;                     /* <30> [dv:           ] [des: ] */
    unsigned cordic_frequency_status;                  /* <31> [dv:           ] [des: ] */
    // GROUP 314 [tvd]
    unsigned sync_height_status;                        /* < 0> [dv:           ] [des: ] */
    unsigned noise_status;                              /* < 1> [dv:           ] [des: ] */
    unsigned luma_peaking_control;                      /* < 2> [dv:        0x4] [des: ] */
    unsigned comb_filter_configuration;                 /* < 3> [dv:       0x62] [des: ] */
    unsigned chroma_lock_configuration;                 /* < 4> [dv:       0x3F] [des: ] */
    unsigned chroma_lock_mode;                          /* < 5> [dv:        0x3] [des: ] */
    unsigned color_stripe_detection_control;            /* < 6> [dv:        0x0] [des: ] */
    unsigned chroma_loop_filter_state;                  /* < 7> [dv:       0xCA] [des: ] */
    unsigned chroma_hresampler_control;                 /* < 8> [dv:       0x11] [des: ] */
    unsigned charge_pump_delay_control;                 /* < 9> [dv:       0x07] [des: ] */
    unsigned charge_pump_adjustment;                    /* <10> [dv:       0xC8] [des: ] */
    unsigned charge_pump_delay;                         /* <11> [dv:       0xB9] [des: ] */
    unsigned reg_2d_comb_noise_threshold;               /* <12> [dv:       0x0A] [des: ] */
    unsigned reg_2d_comb_adaptive_gain_control0;        /* <13> [dv:       0xFA] [des: ] */
    unsigned reg_2d_comb_adaptive_gain_control1;        /* <14> [dv:       0xFF] [des: ] */
    unsigned reg_2d_comb_filter_and_notch_filter_gain;  /* <15> [dv:        0x0] [des: ] */
    unsigned grp314_reserved_0;                         /* <16> */
    unsigned chroma_agc_limit_control;                  /* <17> [dv:        0x0] [des: ] */
    unsigned chroma_agc_time_contant_control;           /* <18> [dv:       0x25] [des: ] */
    unsigned chroma_agc_coring_function_control;        /* <19> [dv:       0x55] [des: ] */
    unsigned dcrestore_control;                         /* <20> [dv:       0xD4] [des: ] */
    unsigned dcrestore_accum_width;                     /* <21> [dv:       0x1B] [des: ] */
    unsigned manual_gain_control;                       /* <22> [dv:       0x60] [des: ] */
    unsigned backporch_kill_threshold;                  /* <23> [dv:       0xC0] [des: ] */
    unsigned dcrestore_hsync_midpoint;                  /* <24> [dv:       0xFA] [des: ] */
    unsigned sync_height;                               /* <25> [dv:       0x90] [des: ] */
    unsigned vsync_signal_threshold;                    /* <26> [dv:        0x0] [des: ] */
    unsigned vsync_no_signal_threshold;                 /* <27> [dv:        0x0] [des: ] */
    unsigned vsync_cntl_2;                              /* <28> [dv:        0x1] [des: ] */
    unsigned vsync_polarity_control;                    /* <29> [dv:       0x50] [des: ] */
    unsigned vbi_hdetect_control;                       /* <30> [dv:       0x62] [des: ] */
    unsigned macrovison_pseudo_sync_rising_start;       /* <31> [dv:       0x44] [des: ] */
    // GROUP 315 [tvd]
    unsigned macrovision_pseudo_sync_rising_end;                     /* < 0> [dv:       0x28] [des: ] */
    unsigned macrovision_detection0;                                 /* < 1> [dv:       0x07] [des: ] */
    unsigned macrovision_detection1;                                 /* < 2> [dv:       0x4E] [des: ] */
    unsigned macrovision_color_stripe_status0;                       /* < 3> [dv:           ] [des: ] */
    unsigned macrovision_vbi_status;                                 /* < 4> [dv:           ] [des: ] */
    unsigned grp315_reserved_0;                                      /* < 5> */
    unsigned grp315_reserved_1;                                      /* < 6> */
    unsigned reg_3d_comb_filter_config;                              /* < 7> [dv:       0x50] [des: ] */
    unsigned reg_3d_comb_filter_control1;                            /* < 8> [dv:       0x8F] [des: ] */
    unsigned reg_3d_comb_filter_control2;                            /* < 9> [dv:       0x02] [des: ] */
    unsigned grp315_reserved_2;                                      /* <10> */
    unsigned history_config;                                         /* <11> [dv:       0x05] [des: ] */
    unsigned motion_index_chroma_reject;                             /* <12> [dv:       0x0A] [des: ] */
    unsigned motion_index_high_upper_threshold;                      /* <13> [dv:       0x20] [des: ] */
    unsigned motion_index_high_lower_threshold;                      /* <14> [dv:       0x10] [des: ] */
    unsigned motion_index_low_upper_threshold;                       /* <15> [dv:       0x08] [des: ] */
    unsigned motion_index_low_lower_threshold;                       /* <16> [dv:       0x04] [des: ] */
    unsigned motion_edge_upper_threshold_reg;                        /* <17> [dv:       0x1A] [des: ] */
    unsigned motion_edge_lower_threshold_reg;                        /* <18> [dv:       0x0D] [des: ] */
    unsigned nonstandard_detect_mask_reg;                            /* <19> [dv:       0x29] [des: ] */
    unsigned nonstandard_detect_control;                             /* <20> [dv:        0x4] [des: ] */
    unsigned nonstandard_hysteresis;                                 /* <21> [dv:       0x10] [des: ] */
    unsigned grp315_reserved_3;                                      /* <22> */
    unsigned frame_motion_index_statistic_upper_threshold;           /* <23> [dv:       0x20] [des: ] */
    unsigned frame_motion_index_statistic_lower_threshold;           /* <24> [dv:       0x12] [des: ] */
    unsigned nonstandard_signal_status;                              /* <25> [dv:           ] [des: ] */
    unsigned frame_motion_index_statistic_increment_status_h;        /* <26> [dv:           ] [des: ] */
    unsigned frame_motion_index_statistic_increment_status_mh;       /* <27> [dv:           ] [des: ] */
    unsigned frame_motion_index_statistic_increment_status_ml;       /* <28> [dv:           ] [des: ] */
    unsigned frame_motion_index_statistic_increment_status_l;        /* <29> [dv:           ] [des: ] */
    unsigned frame_motion_pixel_upper_statistic_increment_status_h;  /* <30> [dv:           ] [des: ] */
    unsigned frame_motion_pixel_upper_statistic_increment_status_m;  /* <31> [dv:           ] [des: ] */
    // GROUP 316 [tvd]
    unsigned frame_motion_pixel_upper_statistic_increment_status_l;   /* < 0> [dv:           ] [des: ] */
    unsigned frame_motion_pixel_medium_statistic_increment_status_h;  /* < 1> [dv:           ] [des: ] */
    unsigned frame_motion_pixel_medium_statistic_increment_status_m;  /* < 2> [dv:           ] [des: ] */
    unsigned frame_motion_pixel_medium_statistic_increment_status_l;  /* < 3> [dv:           ] [des: ] */
    unsigned frame_motion_pixel_lower_statistic_increment_status_h;   /* < 4> [dv:           ] [des: ] */
    unsigned frame_motion_pixel_lower_statistic_increment_status_m;   /* < 5> [dv:           ] [des: ] */
    unsigned frame_motion_pixel_lower_statistic_increment_status_l;   /* < 6> [dv:           ] [des: ] */
    unsigned grp316_reserved_0;                                       /* < 7> */
    unsigned grp316_reserved_1;                                       /* < 8> */
    unsigned source_selection_control_4;                              /* < 9> [dv:       0x07] [des: ] */
    unsigned source_selection_control_3;                              /* <10> [dv:       0x08] [des: ] */
    unsigned grp316_reserved_2;                                       /* <11> */
    unsigned source_selection_control_2;                              /* <12> [dv:       0x0E] [des: ] */
    unsigned source_detect_control;                                   /* <13> [dv:       0x00] [des: ] */
    unsigned grp316_reserved_3;                                       /* <14> */
    unsigned grp316_reserved_4;                                       /* <15> */
    unsigned reg_3d_comb_frame_buffer_base_address_h;                 /* <16> [dv:        0x0] [des: ] */
    unsigned reg_3d_comb_frame_buffer_base_address_m;                 /* <17> [dv:        0x0] [des: ] */
    unsigned reg_3d_comb_frame_buffer_base_address_l;                 /* <18> [dv:        0x0] [des: ] */
    unsigned history_frame_buffer_base_address_h;                     /* <19> [dv:        0x4] [des: ] */
    unsigned history_frame_buffer_base_address_m;                     /* <20> [dv:       0x92] [des: ] */
    unsigned history_frame_buffer_base_address_l;                     /* <21> [dv:        0x0] [des: ] */
    unsigned frame_buffer_base_end_address_h;                         /* <22> [dv:        0x5] [des: ] */
    unsigned frame_buffer_base_end_address_m;                         /* <23> [dv:       0x96] [des: ] */
    unsigned frame_buffer_base_end_address_l;                         /* <24> [dv:        0x0] [des: ] */
    unsigned grp316_reserved_5;                                       /* <25> */
    unsigned grp316_reserved_6;                                       /* <26> */
    unsigned grp316_reserved_7;                                       /* <27> */
    unsigned grp316_reserved_8;                                       /* <28> */
    unsigned grp316_reserved_9;                                       /* <29> */
    unsigned client_request_mask_reg;                                 /* <30> [dv:        0x0] [des: ] */
    unsigned sdram_configuration;                                     /* <31> [dv:        0x0] [des: ] */
    // GROUP 317 [tvd]
    unsigned grp317_reserved_0;                       /* < 0> */
    unsigned grp317_reserved_1;                       /* < 1> */
    unsigned sync_control;                            /* < 2> [dv:       0x24] [des: ] */
    unsigned format_configuration;                    /* < 3> [dv:       0x40] [des: ] */
    unsigned grp317_reserved_2;                       /* < 4> */
    unsigned horizontal_position_control;             /* < 5> [dv:       0x30] [des: ] */
    unsigned grp317_reserved_3;                       /* < 6> */
    unsigned grp317_reserved_4;                       /* < 7> */
    unsigned grp317_reserved_5;                       /* < 8> */
    unsigned grp317_reserved_6;                       /* < 9> */
    unsigned grp317_reserved_7;                       /* <10> */
    unsigned grp317_reserved_8;                       /* <11> */
    unsigned grp317_reserved_9;                       /* <12> */
    unsigned grp317_reserved_10;                      /* <13> */
    unsigned grp317_reserved_11;                      /* <14> */
    unsigned grp317_reserved_12;                      /* <15> */
    unsigned grp317_reserved_13;                      /* <16> */
    unsigned reg_2d_comb_peaking_control;             /* <17> [dv:       0x2D] [des: ] */
    unsigned reg_2d_comb_peaking_control_2;           /* <18> [dv:       0x83] [des: ] */
    unsigned reg_2d_comb_peaking_control_3;           /* <19> [dv:       0x66] [des: ] */
    unsigned reg_2d_comb_peaking_control_4;           /* <20> [dv:       0x08] [des: ] */
    unsigned reg_2d_comb_peaking_control_5;           /* <21> [dv:       0x19] [des: ] */
    unsigned grp317_reserved_14;                      /* <22> */
    unsigned grp317_reserved_15;                      /* <23> */
    unsigned grp317_reserved_16;                      /* <24> */
    unsigned grp317_reserved_17;                      /* <25> */
    unsigned grp317_reserved_18;                      /* <26> */
    unsigned grp317_reserved_19;                      /* <27> */
    unsigned grp317_reserved_20;                      /* <28> */
    unsigned grp317_reserved_21;                      /* <29> */
    unsigned version_information;                     /* <30> [dv:           ] [des: ] */
    unsigned grp317_reserved_22;                      /* <31> */
    // GROUP 318 [tvd]
    unsigned automatic_chroma_limter_control;         /* < 0> [dv:       0x02] [des: ] */
    unsigned automatic_chroma_limter_control1;        /* < 1> [dv:       0x14] [des: ] */
    unsigned automatic_chroma_limter_control2;        /* < 2> [dv:       0x7A] [des: ] */
    unsigned automatic_chroma_limter_control3;        /* < 3> [dv:       0x39] [des: ] */
    unsigned automatic_chroma_limter_control4;        /* < 4> [dv:       0x2A] [des: ] */
    unsigned automatic_chroma_limter_control5;        /* < 5> [dv:       0x1F] [des: ] */
    unsigned automatic_chroma_limter_control6;        /* < 6> [dv:       0x1B] [des: ] */
    unsigned automatic_chroma_limter_control7;        /* < 7> [dv:       0x0F] [des: ] */
    unsigned grp318_reserved_0;                       /* < 8> */
    unsigned grp318_reserved_1;                       /* < 9> */
    unsigned grp318_reserved_2;                       /* <10> */
    unsigned grp318_reserved_3;                       /* <11> */
    unsigned grp318_reserved_4;                       /* <12> */
    unsigned grp318_reserved_5;                       /* <13> */
    unsigned grp318_reserved_6;                       /* <14> */
    unsigned color_noise_suppression_control0;        /* <15> [dv:       0x0F] [des: ] */
    unsigned grp318_reserved_7;                       /* <16> */
    unsigned grp318_reserved_8;                       /* <17> */
    unsigned grp318_reserved_9;                       /* <18> */
    unsigned grp318_reserved_10;                      /* <19> */
    unsigned grp318_reserved_11;                      /* <20> */
    unsigned grp318_reserved_12;                      /* <21> */
    unsigned ring_suppress_control1;                  /* <22> [dv:        0x0] [des: ] */
    unsigned ring_suppress_control2;                  /* <23> [dv:       0x98] [des: ] */
    unsigned ring_suppress_control3;                  /* <24> [dv:       0x54] [des: ] */
    unsigned chroma_coring_control;                   /* <25> [dv:       0x02] [des: ] */
    unsigned chroma_edge_control;                     /* <26> [dv:       0xED] [des: ] */
    unsigned chroma_edge_upper_threshold_reg;         /* <27> [dv:       0x20] [des: ] */
    unsigned chroma_edge_lower_threshold_reg;         /* <28> [dv:       0x14] [des: ] */
    unsigned grp318_reserved_13;                      /* <29> */
    unsigned grp318_reserved_14;                      /* <30> */
    unsigned grp318_reserved_15;                      /* <31> */
    // GROUP 319 [tvd]
    unsigned grp319_reserved_0;                             /* < 0> */
    unsigned grp319_reserved_1;                             /* < 1> */
    unsigned grp319_reserved_2;                             /* < 2> */
    unsigned grp319_reserved_3;                             /* < 3> */
    unsigned grp319_reserved_4;                             /* < 4> */
    unsigned grp319_reserved_5;                             /* < 5> */
    unsigned grp319_reserved_6;                             /* < 6> */
    unsigned grp319_reserved_7;                             /* < 7> */
    unsigned grp319_reserved_8;                             /* < 8> */
    unsigned grp319_reserved_9;                             /* < 9> */
    unsigned fb_adc_data;                                   /* <10> [dv:           ] [des: ] */
    unsigned v_frequency_configuration_h_frequency_status;  /* <11> [dv:       0x80] [des: ] */
    unsigned h_frequency_status_2;                          /* <12> [dv:           ] [des: ] */
    unsigned v_frequency_status;                            /* <13> [dv:           ] [des: ] */
    unsigned v_frequency_status_2;                          /* <14> [dv:           ] [des: ] */
    unsigned anti_uv_detect_control;                        /* <15> [dv:       0xC7] [des: ] */
    unsigned anti_uv_detect_threshold;                      /* <16> [dv:       0xD1] [des: ] */
    unsigned grp319_reserved_10;                            /* <17> */
    unsigned interrupt_control;                             /* <18> [dv:        0x1] [des: ] */
    unsigned interrupt_mask_reg;                            /* <19> [dv:       0xFF] [des: ] */
    unsigned nterrupt_duty;                                 /* <20> [dv:       0xFF] [des: ] */
    unsigned interrupt_status;                              /* <21> [dv:        0x0] [des: ] */
    unsigned grp319_reserved_11;                            /* <22> */
    unsigned autosw_format_configuration;                   /* <23> [dv:       0x7F] [des: ] */
    unsigned autosw_chroma_kill_configuration;              /* <24> [dv:       0x3B] [des: ] */
    unsigned autosw_control;                                /* <25> [dv:       0x0A] [des: ] */
    unsigned autosw_stable_period_reg;                      /* <26> [dv:        0x4] [des: ] */
    unsigned autosw_default_mode_configuration;             /* <27> [dv:       0x10] [des: ] */
    unsigned autosw_setup_period;                           /* <28> [dv:       0x21] [des: ] */
    unsigned autosw_hold_period;                            /* <29> [dv:       0x3F] [des: ] */
    unsigned grp319_reserved_12;                            /* <30> */
    unsigned grp319_reserved_13;                            /* <31> */
    // GROUP 320 [tvd]
    unsigned grp320_reserved_0;                       /* < 0> */
    unsigned grp320_reserved_1;                       /* < 1> */
    unsigned grp320_reserved_2;                       /* < 2> */
    unsigned grp320_reserved_3;                       /* < 3> */
    unsigned unhvlock_suppress;                       /* < 4> [dv:        0xF] [des: ] */
    unsigned vsync_cntl_3;                            /* < 5> [dv:        0x1] [des: ] */
    unsigned vsync_cntl_4;                            /* < 6> [dv:       0x75] [des: ] */
    unsigned misc_control;                            /* < 7> [dv:       0x21] [des: ] */
    unsigned addition_vbi_header0;                    /* < 8> [dv:        0x0] [des: ] */
    unsigned addition_vbi_header1;                    /* < 9> [dv:        0x0] [des: ] */
    unsigned addition_vbi_header2;                    /* <10> [dv:        0x0] [des: ] */
    unsigned misc_control_2;                          /* <11> [dv:       0x84] [des: ] */
    unsigned grp320_reserved_4;                       /* <12> */
    unsigned grp320_reserved_5;                       /* <13> */
    unsigned highlight_color;                         /* <14> [dv:        0x0] [des: ] */
    unsigned grp320_reserved_6;                       /* <15> */
    unsigned grp320_reserved_7;                       /* <16> */
    unsigned burst_magnitude_status;                  /* <17> [dv:           ] [des: ] */
    unsigned sdram_bandwidth_status;                  /* <18> [dv:           ] [des: ] */
    unsigned equalizing_vsync_width_status_1;         /* <19> [dv:           ] [des: ] */
    unsigned equalizing_vsync_width_status_2;         /* <20> [dv:           ] [des: ] */
    unsigned grp320_reserved_8;                       /* <21> */
    unsigned grp320_reserved_9;                       /* <22> */
    unsigned grp320_reserved_10;                      /* <23> */
    unsigned grp320_reserved_11;                      /* <24> */
    unsigned grp320_reserved_12;                      /* <25> */
    unsigned grp320_reserved_13;                      /* <26> */
    unsigned grp320_reserved_14;                      /* <27> */
    unsigned grp320_reserved_15;                      /* <28> */
    unsigned grp320_reserved_16;                      /* <29> */
    unsigned grp320_reserved_17;                      /* <30> */
    unsigned vbi_peak_match_hnum_status;              /* <31> [dv:           ] [des: ] */
    // GROUP 321 [tvd]
    unsigned pg_control;                              /* < 0> [dv:        0x0] [des: ] */
    unsigned pg_pattern_configuration;                /* < 1> [dv:        0x0] [des: ] */
    unsigned pg_hue_adjustment;                       /* < 2> [dv:        0x0] [des: ] */
    unsigned pg_saturation_adjustment;                /* < 3> [dv:       0x70] [des: ] */
    unsigned pg_lrmp_control_1;                       /* < 4> [dv:       0x01] [des: ] */
    unsigned pg_lrmp_control_2;                       /* < 5> [dv:       0x05] [des: ] */
    unsigned pg_crmp_control_1;                       /* < 6> [dv:       0x01] [des: ] */
    unsigned pg_crmp_control_2;                       /* < 7> [dv:       0x05] [des: ] */
    unsigned pg_puri_pg_gray_pg_crmp_control_3;       /* < 8> [dv:       0x01] [des: ] */
    unsigned pg_gain;                                 /* < 9> [dv:        0x0] [des: ] */
    unsigned grp321_reserved_0;                       /* <10> */
    unsigned grp321_reserved_1;                       /* <11> */
    unsigned grp321_reserved_2;                       /* <12> */
    unsigned grp321_reserved_3;                       /* <13> */
    unsigned grp321_reserved_4;                       /* <14> */
    unsigned grp321_reserved_5;                       /* <15> */
    unsigned grp321_reserved_6;                       /* <16> */
    unsigned grp321_reserved_7;                       /* <17> */
    unsigned grp321_reserved_8;                       /* <18> */
    unsigned grp321_reserved_9;                       /* <19> */
    unsigned grp321_reserved_10;                      /* <20> */
    unsigned grp321_reserved_11;                      /* <21> */
    unsigned grp321_reserved_12;                      /* <22> */
    unsigned grp321_reserved_13;                      /* <23> */
    unsigned grp321_reserved_14;                      /* <24> */
    unsigned grp321_reserved_15;                      /* <25> */
    unsigned grp321_reserved_16;                      /* <26> */
    unsigned grp321_reserved_17;                      /* <27> */
    unsigned grp321_reserved_18;                      /* <28> */
    unsigned grp321_reserved_19;                      /* <29> */
    unsigned grp321_reserved_20;                      /* <30> */
    unsigned grp321_reserved_21;                      /* <31> */
    // GROUP 322 [tvd]
    unsigned grp322_reserved_0;                       /* < 0> */
    unsigned grp322_reserved_1;                       /* < 1> */
    unsigned grp322_reserved_2;                       /* < 2> */
    unsigned grp322_reserved_3;                       /* < 3> */
    unsigned grp322_reserved_4;                       /* < 4> */
    unsigned grp322_reserved_5;                       /* < 5> */
    unsigned grp322_reserved_6;                       /* < 6> */
    unsigned grp322_reserved_7;                       /* < 7> */
    unsigned grp322_reserved_8;                       /* < 8> */
    unsigned vid_ctrl;                                /* < 9> [dv:       0x30] [des: ] */
    unsigned grp322_reserved_9;                       /* <10> */
    unsigned grp322_reserved_10;                      /* <11> */
    unsigned grp322_reserved_11;                      /* <12> */
    unsigned grp322_reserved_12;                      /* <13> */
    unsigned grp322_reserved_13;                      /* <14> */
    unsigned grp322_reserved_14;                      /* <15> */
    unsigned grp322_reserved_15;                      /* <16> */
    unsigned grp322_reserved_16;                      /* <17> */
    unsigned grp322_reserved_17;                      /* <18> */
    unsigned grp322_reserved_18;                      /* <19> */
    unsigned grp322_reserved_19;                      /* <20> */
    unsigned grp322_reserved_20;                      /* <21> */
    unsigned grp322_reserved_21;                      /* <22> */
    unsigned grp322_reserved_22;                      /* <23> */
    unsigned grp322_reserved_23;                      /* <24> */
    unsigned grp322_reserved_24;                      /* <25> */
    unsigned grp322_reserved_25;                      /* <26> */
    unsigned grp322_reserved_26;                      /* <27> */
    unsigned grp322_reserved_27;                      /* <28> */
    unsigned grp322_reserved_28;                      /* <29> */
    unsigned status_noise_1;                          /* <30> [dv:           ] [des: ] */
    unsigned status_noise_2;                          /* <31> [dv:           ] [des: ] */
    // GROUP 323 [tvd]
    unsigned aux_noisy_status;                        /* < 0> [dv:           ] [des: ] */
    unsigned reg_aux_noise_threshold;                 /* < 1> [dv:       0x32] [des: ] */
    unsigned reg_heavy_noise_threshold;               /* < 2> [dv:       0x1C] [des: ] */
    unsigned reg_light_noise_threshold;               /* < 3> [dv:       0x32] [des: ] */
    unsigned reg_secam_range_max;                     /* < 4> [dv:       0x80] [des: ] */
    unsigned reg_secam_range_min;                     /* < 5> [dv:       0x80] [des: ] */
    unsigned reg_secam_range_max2;                    /* < 6> [dv:       0xE0] [des: ] */
    unsigned reg_secam_range_min2;                    /* < 7> [dv:       0x40] [des: ] */
    unsigned reg_palsw_phase_max;                     /* < 8> [dv:       0x80] [des: ] */
    unsigned reg_palsw_phase_min;                     /* < 9> [dv:       0x80] [des: ] */
    unsigned reg_palsw_phase_max2;                    /* <10> [dv:       0xC0] [des: ] */
    unsigned reg_palsw_phase_min2;                    /* <11> [dv:       0x40] [des: ] */
    unsigned secam_detect_control;                    /* <12> [dv:       0x16] [des: ] */
    unsigned secam_detect_control2;                   /* <13> [dv:       0x08] [des: ] */
    unsigned grp323_reserved_0;                       /* <14> */
    unsigned grp323_reserved_1;                       /* <15> */
    unsigned grp323_reserved_2;                       /* <16> */
    unsigned grp323_reserved_3;                       /* <17> */
    unsigned grp323_reserved_4;                       /* <18> */
    unsigned grp323_reserved_5;                       /* <19> */
    unsigned grp323_reserved_6;                       /* <20> */
    unsigned grp323_reserved_7;                       /* <21> */
    unsigned grp323_reserved_8;                       /* <22> */
    unsigned grp323_reserved_9;                       /* <23> */
    unsigned grp323_reserved_10;                      /* <24> */
    unsigned grp323_reserved_11;                      /* <25> */
    unsigned grp323_reserved_12;                      /* <26> */
    unsigned grp323_reserved_13;                      /* <27> */
    unsigned grp323_reserved_14;                      /* <28> */
    unsigned grp323_reserved_15;                      /* <29> */
    unsigned grp323_reserved_16;                      /* <30> */
    unsigned grp323_reserved_17;                      /* <31> */
    // GROUP 324 [tvd]
    unsigned grp324_reserved_0;                       /* < 0> */
    unsigned grp324_reserved_1;                       /* < 1> */
    unsigned grp324_reserved_2;                       /* < 2> */
    unsigned grp324_reserved_3;                       /* < 3> */
    unsigned grp324_reserved_4;                       /* < 4> */
    unsigned grp324_reserved_5;                       /* < 5> */
    unsigned grp324_reserved_6;                       /* < 6> */
    unsigned grp324_reserved_7;                       /* < 7> */
    unsigned grp324_reserved_8;                       /* < 8> */
    unsigned grp324_reserved_9;                       /* < 9> */
    unsigned grp324_reserved_10;                      /* <10> */
    unsigned grp324_reserved_11;                      /* <11> */
    unsigned grp324_reserved_12;                      /* <12> */
    unsigned grp324_reserved_13;                      /* <13> */
    unsigned grp324_reserved_14;                      /* <14> */
    unsigned grp324_reserved_15;                      /* <15> */
    unsigned grp324_reserved_16;                      /* <16> */
    unsigned grp324_reserved_17;                      /* <17> */
    unsigned grp324_reserved_18;                      /* <18> */
    unsigned grp324_reserved_19;                      /* <19> */
    unsigned private_control_5;                       /* <20> [dv:        0x0] [des: ] */
    unsigned grp324_reserved_20;                      /* <21> */
    unsigned grp324_reserved_21;                      /* <22> */
    unsigned grp324_reserved_22;                      /* <23> */
    unsigned grp324_reserved_23;                      /* <24> */
    unsigned grp324_reserved_24;                      /* <25> */
    unsigned grp324_reserved_25;                      /* <26> */
    unsigned grp324_reserved_26;                      /* <27> */
    unsigned grp324_reserved_27;                      /* <28> */
    unsigned grp324_reserved_28;                      /* <29> */
    unsigned grp324_reserved_29;                      /* <30> */
    unsigned phase_jump_reg;                          /* <31> [dv:       0x10] [des: ] */
    // GROUP 325 [tvd]
    unsigned grp325_reserved_0;                       /* < 0> */
    unsigned grp325_reserved_1;                       /* < 1> */
    unsigned grp325_reserved_2;                       /* < 2> */
    unsigned grp325_reserved_3;                       /* < 3> */
    unsigned dereticular_ctrl1;                       /* < 4> [dv:       0x23] [des: ] */
    unsigned dereticular_ctrl2;                       /* < 5> [dv:       0x27] [des: ] */
    unsigned dereticular_ctrl3;                       /* < 6> [dv:       0x55] [des: ] */
    unsigned burst_detect;                            /* < 7> [dv:       0x7C] [des: ] */
    unsigned grp325_reserved_4;                       /* < 8> */
    unsigned burst_gate_end_ext_reg;                  /* < 9> [dv:       0x0A] [des: ] */
    unsigned anti_deovershoot_threshold;              /* <10> [dv:       0x20] [des: ] */
    unsigned vsync_c_lockout_start;                   /* <11> [dv:       0x70] [des: ] */
    unsigned vsync_c_lockout_end;                     /* <12> [dv:       0x18] [des: ] */
    unsigned dcrestore_control2;                      /* <13> [dv:       0x04] [des: ] */
    unsigned charge_pump_adjustment2;                 /* <14> [dv:       0x48] [des: ] */
    unsigned charge_pump_adjustment3;                 /* <15> [dv:       0x00] [des: ] */
    unsigned status_signal_in_height;                 /* <16> [dv:           ] [des: ] */
    unsigned status_frequency_1;                      /* <17> [dv:           ] [des: ] */
    unsigned status_frequency_2;                      /* <18> [dv:           ] [des: ] */
    unsigned status_frequency_3;                      /* <19> [dv:           ] [des: ] */
    unsigned status_frequency_4;                      /* <20> [dv:           ] [des: ] */
    unsigned agc_peak_nominal_2;                      /* <21> [dv:        0x4] [des: ] */
    unsigned grp325_reserved_5;                       /* <22> */
    unsigned grp325_reserved_6;                       /* <23> */
    unsigned grp325_reserved_7;                       /* <24> */
    unsigned grp325_reserved_8;                       /* <25> */
    unsigned grp325_reserved_9;                       /* <26> */
    unsigned grp325_reserved_10;                      /* <27> */
    unsigned grp325_reserved_11;                      /* <28> */
    unsigned grp325_reserved_12;                      /* <29> */
    unsigned grp325_reserved_13;                      /* <30> */
    unsigned grp325_reserved_14;                      /* <31> */
    // GROUP 326 [tvd]
    unsigned grp326_reserved_0;                       /* < 0> */
    unsigned grp326_reserved_1;                       /* < 1> */
    unsigned grp326_reserved_2;                       /* < 2> */
    unsigned grp326_reserved_3;                       /* < 3> */
    unsigned grp326_reserved_4;                       /* < 4> */
    unsigned grp326_reserved_5;                       /* < 5> */
    unsigned grp326_reserved_6;                       /* < 6> */
    unsigned grp326_reserved_7;                       /* < 7> */
    unsigned grp326_reserved_8;                       /* < 8> */
    unsigned grp326_reserved_9;                       /* < 9> */
    unsigned grp326_reserved_10;                      /* <10> */
    unsigned grp326_reserved_11;                      /* <11> */
    unsigned grp326_reserved_12;                      /* <12> */
    unsigned grp326_reserved_13;                      /* <13> */
    unsigned secam_adaptive_control4;                 /* <14> [dv:       0x33] [des: ] */
    unsigned grp326_reserved_14;                      /* <15> */
    unsigned grp326_reserved_15;                      /* <16> */
    unsigned grp326_reserved_16;                      /* <17> */
    unsigned luma_enhance_control0;                   /* <18> [dv:       0xB7] [des: ] */
    unsigned grp326_reserved_17;                      /* <19> */
    unsigned vertical_cross_luma_control0;            /* <20> [dv:       0x87] [des: ] */
    unsigned grp326_reserved_18;                      /* <21> */
    unsigned grp326_reserved_19;                      /* <22> */
    unsigned grp326_reserved_20;                      /* <23> */
    unsigned grp326_reserved_21;                      /* <24> */
    unsigned grp326_reserved_22;                      /* <25> */
    unsigned grp326_reserved_23;                      /* <26> */
    unsigned grp326_reserved_24;                      /* <27> */
    unsigned grp326_reserved_25;                      /* <28> */
    unsigned grp326_reserved_26;                      /* <29> */
    unsigned oblique_ycsep_control4;                  /* <30> [dv:       0xFA] [des: ] */
    unsigned grp326_reserved_27;                      /* <31> */
    // GROUP 327 [tvd]
    unsigned grp327_reserved_0;                       /* < 0> */
    unsigned grp327_reserved_1;                       /* < 1> */
    unsigned grp327_reserved_2;                       /* < 2> */
    unsigned grp327_reserved_3;                       /* < 3> */
    unsigned grp327_reserved_4;                       /* < 4> */
    unsigned grp327_reserved_5;                       /* < 5> */
    unsigned vertical_chroma_lpf_control1;            /* < 6> [dv:       0x05] [des: ] */
    unsigned vertical_chroma_lpf_control2;            /* < 7> [dv:       0x42] [des: ] */
    unsigned grp327_reserved_6;                       /* < 8> */
    unsigned grp327_reserved_7;                       /* < 9> */
    unsigned grp327_reserved_8;                       /* <10> */
    unsigned grp327_reserved_9;                       /* <11> */
    unsigned grp327_reserved_10;                      /* <12> */
    unsigned grp327_reserved_11;                      /* <13> */
    unsigned grp327_reserved_12;                      /* <14> */
    unsigned grp327_reserved_13;                      /* <15> */
    unsigned grp327_reserved_14;                      /* <16> */
    unsigned grp327_reserved_15;                      /* <17> */
    unsigned grp327_reserved_16;                      /* <18> */
    unsigned grp327_reserved_17;                      /* <19> */
    unsigned grp327_reserved_18;                      /* <20> */
    unsigned field_chroma_statistics_control;         /* <21> [dv:       0x10] [des: ] */
    unsigned field_chroma_statistics_status1_h;       /* <22> [dv:           ] [des: ] */
    unsigned field_chroma_statistics_status1_m;       /* <23> [dv:           ] [des: ] */
    unsigned field_chroma_statistics_status1_l;       /* <24> [dv:           ] [des: ] */
    unsigned field_chroma_statistics_status2_h;       /* <25> [dv:           ] [des: ] */
    unsigned field_chroma_statistics_status2_l;       /* <26> [dv:           ] [des: ] */
    unsigned field_chroma_statistics_status3_h;       /* <27> [dv:           ] [des: ] */
    unsigned field_chroma_statistics_status3_l;       /* <28> [dv:           ] [des: ] */
    unsigned grp327_reserved_19;                      /* <29> */
    unsigned grp327_reserved_20;                      /* <30> */
    unsigned grp327_reserved_21;                      /* <31> */
    // GROUP 328
    unsigned grp328_reserved[32];
    // GROUP 329
    unsigned grp329_reserved[32];
    // GROUP 330 [tvd]
    unsigned grp330_reserved_0;                       /* < 0> */
    unsigned grp330_reserved_1;                       /* < 1> */
    unsigned grp330_reserved_2;                       /* < 2> */
    unsigned grp330_reserved_3;                       /* < 3> */
    unsigned grp330_reserved_4;                       /* < 4> */
    unsigned grp330_reserved_5;                       /* < 5> */
    unsigned grp330_reserved_6;                       /* < 6> */
    unsigned grp330_reserved_7;                       /* < 7> */
    unsigned grp330_reserved_8;                       /* < 8> */
    unsigned grp330_reserved_9;                       /* < 9> */
    unsigned grp330_reserved_10;                      /* <10> */
    unsigned grp330_reserved_11;                      /* <11> */
    unsigned grp330_reserved_12;                      /* <12> */
    unsigned grp330_reserved_13;                      /* <13> */
    unsigned grp330_reserved_14;                      /* <14> */
    unsigned grp330_reserved_15;                      /* <15> */
    unsigned grp330_reserved_16;                      /* <16> */
    unsigned grp330_reserved_17;                      /* <17> */
    unsigned grp330_reserved_18;                      /* <18> */
    unsigned grp330_reserved_19;                      /* <19> */
    unsigned grp330_reserved_20;                      /* <20> */
    unsigned adc_grab_control5;                       /* <21> [dv:       0x40] [des: ] */
    unsigned adc_grab_control6;                       /* <22> [dv:       0x40] [des: ] */
    unsigned adc_grab_control7;                       /* <23> [dv:        0x0] [des: ] */
    unsigned adc_grab_control;                        /* <24> [dv:       0x04] [des: ] */
    unsigned adc_grab_control2;                       /* <25> [dv:       0x2C] [des: ] */
    unsigned adc_grab_control3;                       /* <26> [dv:       0x83] [des: ] */
    unsigned adc_grab_control4;                       /* <27> [dv:        0x0] [des: ] */
    unsigned adc_grab_data0;                          /* <28> [dv:           ] [des: ] */
    unsigned adc_grab_data1;                          /* <29> [dv:           ] [des: ] */
    unsigned adc_grab_data2;                          /* <30> [dv:           ] [des: ] */
    unsigned adc_grab_data3;                          /* <31> [dv:           ] [des: ] */
    // GROUP 331 [tvd]
    unsigned chroma_sdiff_threshold_upper;            /* < 0> [dv:       0x18] [des: ] */
    unsigned chroma_sdiff_threshold_lower;            /* < 1> [dv:       0x10] [des: ] */
    unsigned chroma_tdiff_threshold_upper;            /* < 2> [dv:       0x20] [des: ] */
    unsigned chroma_tdiff_threshold_lower;            /* < 3> [dv:       0x18] [des: ] */
    unsigned chroma_tsdiff_control;                   /* < 4> [dv:       0x2C] [des: ] */
    unsigned grp331_reserved_0;                       /* < 5> */
    unsigned grp331_reserved_1;                       /* < 6> */
    unsigned difference_adaptive_motion_control;      /* < 7> [dv:       0x30] [des: ] */
    unsigned difference_adaptive_motion_control2;     /* < 8> [dv:        0x0] [des: ] */
    unsigned difference_adaptive_motion_control3;     /* < 9> [dv:       0x0C] [des: ] */
    unsigned difference_adaptive_motion_control4;     /* <10> [dv:       0x10] [des: ] */
    unsigned difference_adaptive_motion_control5;     /* <11> [dv:       0x08] [des: ] */
    unsigned difference_adaptive_motion_control6;     /* <12> [dv:       0x15] [des: ] */
    unsigned motion_index_high_upper_threshold2;      /* <13> [dv:       0x2C] [des: ] */
    unsigned motion_index_high_lower_threshold2;      /* <14> [dv:       0x28] [des: ] */
    unsigned motion_index_low_upper_threshold2;       /* <15> [dv:       0x24] [des: ] */
    unsigned motion_index_low_lower_threshold2;       /* <16> [dv:       0x20] [des: ] */
    unsigned grp331_reserved_2;                       /* <17> */
    unsigned grp331_reserved_3;                       /* <18> */
    unsigned grp331_reserved_4;                       /* <19> */
    unsigned grp331_reserved_5;                       /* <20> */
    unsigned grp331_reserved_6;                       /* <21> */
    unsigned grp331_reserved_7;                       /* <22> */
    unsigned grp331_reserved_8;                       /* <23> */
    unsigned grp331_reserved_9;                       /* <24> */
    unsigned grp331_reserved_10;                      /* <25> */
    unsigned grp331_reserved_11;                      /* <26> */
    unsigned grp331_reserved_12;                      /* <27> */
    unsigned grp331_reserved_13;                      /* <28> */
    unsigned grp331_reserved_14;                      /* <29> */
    unsigned grp331_reserved_15;                      /* <30> */
    unsigned grp331_reserved_16;                      /* <31> */
    // GROUP 332 [tvd]
    unsigned grp332_reserved_0;                       /* < 0> */
    unsigned grp332_reserved_1;                       /* < 1> */
    unsigned grp332_reserved_2;                       /* < 2> */
    unsigned grp332_reserved_3;                       /* < 3> */
    unsigned grp332_reserved_4;                       /* < 4> */
    unsigned grp332_reserved_5;                       /* < 5> */
    unsigned grp332_reserved_6;                       /* < 6> */
    unsigned grp332_reserved_7;                       /* < 7> */
    unsigned grp332_reserved_8;                       /* < 8> */
    unsigned grp332_reserved_9;                       /* < 9> */
    unsigned grp332_reserved_10;                      /* <10> */
    unsigned grp332_reserved_11;                      /* <11> */
    unsigned grp332_reserved_12;                      /* <12> */
    unsigned grp332_reserved_13;                      /* <13> */
    unsigned grp332_reserved_14;                      /* <14> */
    unsigned grp332_reserved_15;                      /* <15> */
    unsigned hresampler_lut_prog_control1;            /* <16> [dv:       0x00] [des: ] */
    unsigned hresampler_lut_prog_control2;            /* <17> [dv:       0x00] [des: ] */
    unsigned hresampler_lut_prog_control3;            /* <18> [dv:       0x00] [des: ] */
    unsigned hresampler_lut_prog_control4;            /* <19> [dv:       0x00] [des: ] */
    unsigned hresampler_lut_prog_control5;            /* <20> [dv:       0x00] [des: ] */
    unsigned hresampler_lut_prog_control6;            /* <21> [dv:       0x00] [des: ] */
    unsigned hresampler_lut_prog_control7;            /* <22> [dv:       0x00] [des: ] */
    unsigned hresampler_lut_prog_status1;             /* <23> [dv:           ] [des: ] */
    unsigned hresampler_lut_prog_status2;             /* <24> [dv:           ] [des: ] */
    unsigned hresampler_lut_prog_status3;             /* <25> [dv:           ] [des: ] */
    unsigned hresampler_lut_prog_status4;             /* <26> [dv:           ] [des: ] */
    unsigned hresampler_lut_prog_status5;             /* <27> [dv:           ] [des: ] */
    unsigned grp332_reserved_16;                      /* <28> */
    unsigned grp332_reserved_17;                      /* <29> */
    unsigned grp332_reserved_18;                      /* <30> */
    unsigned grp332_reserved_19;                      /* <31> */
    // GROUP 333
    unsigned grp333_reserved[32];
    // GROUP 334
    unsigned grp334_reserved[32];
    // GROUP 335
    unsigned grp335_reserved[32];
    // GROUP 336 [cvbs_adc_reg]
    unsigned cvbs_clk_ctrl;                           /* < 0> [dv:        0x5] [des: ] */
    unsigned cvbs_r1;                                 /* < 1> [dv:        0x0] [des: ] */
    unsigned cvbs_r2;                                 /* < 2> [dv:        0x0] [des: ] */
    unsigned cvbs_gain;                               /* < 3> [dv:        0xc] [des: ] */
    unsigned cvbs_r4;                                 /* < 4> [dv:     0x8001] [des: ] */
    unsigned cvbs_r_bw;                               /* < 5> [dv:        0x0] [des: ] */
    unsigned cvbs_pwd_ctrl;                           /* < 6> [dv:       0x1c] [des: ] */
    unsigned cvbs_ref;                                /* < 7> [dv:       0x33] [des: ] */
    unsigned cvbs_ibuf;                               /* < 8> [dv:        0xa] [des: ] */
    unsigned cvbs_ipga;                               /* < 9> [dv:        0x3] [des: ] */
    unsigned cvbs_iadc;                               /* <10> [dv:        0x3] [des: ] */
    unsigned cvbs_icmp;                               /* <11> [dv:        0x3] [des: ] */
    unsigned cvbs_midv;                               /* <12> [dv:       0x32] [des: ] */
    unsigned cvbs_r_mx;                               /* <13> [dv:        0x0] [des: ] */
    unsigned cvbs_option;                             /* <14> [dv:        0x0] [des: ] */
    unsigned cvbs_strong;                             /* <15> [dv:        0x0] [des: ] */
    unsigned grp336_reserved_0;                       /* <16> */
    unsigned grp336_reserved_1;                       /* <17> */
    unsigned grp336_reserved_2;                       /* <18> */
    unsigned grp336_reserved_3;                       /* <19> */
    unsigned grp336_reserved_4;                       /* <20> */
    unsigned grp336_reserved_5;                       /* <21> */
    unsigned grp336_reserved_6;                       /* <22> */
    unsigned grp336_reserved_7;                       /* <23> */
    unsigned grp336_reserved_8;                       /* <24> */
    unsigned grp336_reserved_9;                       /* <25> */
    unsigned grp336_reserved_10;                      /* <26> */
    unsigned grp336_reserved_11;                      /* <27> */
    unsigned grp336_reserved_12;                      /* <28> */
    unsigned grp336_reserved_13;                      /* <29> */
    unsigned grp336_reserved_14;                      /* <30> */
    unsigned grp336_reserved_15;                      /* <31> */
    // GROUP 337
    unsigned grp337_reserved[32];
    // GROUP 338
    unsigned grp338_reserved[32];
    // GROUP 339
    unsigned grp339_reserved[32];
    // GROUP 340
    unsigned grp340_reserved[32];
    // GROUP 341
    unsigned grp341_reserved[32];
    // GROUP 342
    unsigned grp342_reserved[32];
    // GROUP 343
    unsigned grp343_reserved[32];
    // GROUP 344
    unsigned grp344_reserved[32];
    // GROUP 345
    unsigned grp345_reserved[32];
    // GROUP 346
    unsigned grp346_reserved[32];
    // GROUP 347
    unsigned grp347_reserved[32];
    // GROUP 348
    unsigned grp348_reserved[32];
    // GROUP 349
    unsigned grp349_reserved[32];
    // GROUP 350
    unsigned grp350_reserved[32];
    // GROUP 351
    unsigned grp351_reserved[32];
    // GROUP 352 [servo_memory_access_agent]
    unsigned servo_sdramif_tbya;                      /* < 0> [dv:     0x0000] [des: Setting track buffer location] */
    unsigned servo_sdramif_regulator_en;              /* < 1> [dv:     0x0000] [des: Traffic Regulator Enable Register] */
    unsigned servo_sdramif_waiting_time;              /* < 2> [dv:     0x0400] [des: Programmed Waiting Time Register] */
    unsigned grp352_reserved_0;                       /* < 3> */
    unsigned grp352_reserved_1;                       /* < 4> */
    unsigned grp352_reserved_2;                       /* < 5> */
    unsigned grp352_reserved_3;                       /* < 6> */
    unsigned grp352_reserved_4;                       /* < 7> */
    unsigned grp352_reserved_5;                       /* < 8> */
    unsigned grp352_reserved_6;                       /* < 9> */
    unsigned grp352_reserved_7;                       /* <10> */
    unsigned grp352_reserved_8;                       /* <11> */
    unsigned grp352_reserved_9;                       /* <12> */
    unsigned grp352_reserved_10;                      /* <13> */
    unsigned grp352_reserved_11;                      /* <14> */
    unsigned grp352_reserved_12;                      /* <15> */
    unsigned grp352_reserved_13;                      /* <16> */
    unsigned grp352_reserved_14;                      /* <17> */
    unsigned grp352_reserved_15;                      /* <18> */
    unsigned grp352_reserved_16;                      /* <19> */
    unsigned grp352_reserved_17;                      /* <20> */
    unsigned grp352_reserved_18;                      /* <21> */
    unsigned grp352_reserved_19;                      /* <22> */
    unsigned grp352_reserved_20;                      /* <23> */
    unsigned grp352_reserved_21;                      /* <24> */
    unsigned grp352_reserved_22;                      /* <25> */
    unsigned grp352_reserved_23;                      /* <26> */
    unsigned grp352_reserved_24;                      /* <27> */
    unsigned grp352_reserved_25;                      /* <28> */
    unsigned grp352_reserved_26;                      /* <29> */
    unsigned grp352_reserved_27;                      /* <30> */
    unsigned grp352_reserved_28;                      /* <31> */
    // GROUP 353 [servo_register_file_access]
    unsigned servo_regif_addr;                        /* < 0> [dv:     0x0000] [des: Servo Address Register] */
    unsigned servo_regif_wdata;                       /* < 1> [dv:     0x0000] [des: Servo Write Data Register] */
    unsigned servo_regif_rdta;                        /* < 2> [dv:     0x0000] [des: Servo Read Data Register] */
    unsigned servo_regif_sample_ctrl;                 /* < 3> [dv:     0x0000] [des: Servo Sample Control Register] */
    unsigned servo_regif_intr_addr;                   /* < 4> [dv:     0x0000] [des: Servo Address Register for Interrupt] */
    unsigned servo_regif_intr_wdata;                  /* < 5> [dv:     0x0000] [des: Servo Write Data Register for Interrupt] */
    unsigned servo_regif_intr_rdata;                  /* < 6> [dv:     0x0000] [des: Servo Read Data Register for Interrupt] */
    unsigned grp353_reserved_0;                       /* < 7> */
    unsigned grp353_reserved_1;                       /* < 8> */
    unsigned grp353_reserved_2;                       /* < 9> */
    unsigned grp353_reserved_3;                       /* <10> */
    unsigned grp353_reserved_4;                       /* <11> */
    unsigned grp353_reserved_5;                       /* <12> */
    unsigned grp353_reserved_6;                       /* <13> */
    unsigned grp353_reserved_7;                       /* <14> */
    unsigned grp353_reserved_8;                       /* <15> */
    unsigned grp353_reserved_9;                       /* <16> */
    unsigned grp353_reserved_10;                      /* <17> */
    unsigned grp353_reserved_11;                      /* <18> */
    unsigned grp353_reserved_12;                      /* <19> */
    unsigned grp353_reserved_13;                      /* <20> */
    unsigned grp353_reserved_14;                      /* <21> */
    unsigned grp353_reserved_15;                      /* <22> */
    unsigned grp353_reserved_16;                      /* <23> */
    unsigned grp353_reserved_17;                      /* <24> */
    unsigned grp353_reserved_18;                      /* <25> */
    unsigned grp353_reserved_19;                      /* <26> */
    unsigned grp353_reserved_20;                      /* <27> */
    unsigned grp353_reserved_21;                      /* <28> */
    unsigned grp353_reserved_22;                      /* <29> */
    unsigned grp353_reserved_23;                      /* <30> */
    unsigned grp353_reserved_24;                      /* <31> */
    // GROUP 354
    unsigned grp354_reserved[32];
    // GROUP 355
    unsigned grp355_reserved[32];
    // GROUP 356
    unsigned grp356_reserved[32];
    // GROUP 357
    unsigned grp357_reserved[32];
    // GROUP 358
    unsigned grp358_reserved[32];
    // GROUP 359
    unsigned grp359_reserved[32];
    // GROUP 360
    unsigned grp360_reserved[32];
    // GROUP 361
    unsigned grp361_reserved[32];
    // GROUP 362
    unsigned grp362_reserved[32];
    // GROUP 363
    unsigned grp363_reserved[32];
    // GROUP 364
    unsigned grp364_reserved[32];
    // GROUP 365
    unsigned grp365_reserved[32];
    // GROUP 366
    unsigned grp366_reserved[32];
    // GROUP 367
    unsigned grp367_reserved[32];
    // GROUP 368
    unsigned grp368_reserved[32];
    // GROUP 369
    unsigned grp369_reserved[32];
    // GROUP 370
    unsigned grp370_reserved[32];
    // GROUP 371
    unsigned grp371_reserved[32];
    // GROUP 372
    unsigned grp372_reserved[32];
    // GROUP 373
    unsigned grp373_reserved[32];
    // GROUP 374
    unsigned grp374_reserved[32];
    // GROUP 375
    unsigned grp375_reserved[32];
    // GROUP 376
    unsigned grp376_reserved[32];
    // GROUP 377
    unsigned grp377_reserved[32];
    // GROUP 378
    unsigned grp378_reserved[32];
    // GROUP 379
    unsigned grp379_reserved[32];
    // GROUP 380
    unsigned grp380_reserved[32];
    // GROUP 381
    unsigned grp381_reserved[32];
    // GROUP 382
    unsigned grp382_reserved[32];
    // GROUP 383
    unsigned grp383_reserved[32];
    // GROUP 384 [h.264_avs_and_realvideo_frame_buffer_base_index_to_reference_index_mapping_group_0]
    unsigned fcv_sram_base_0_0;                       /* < 0> [dv:         na] [des: Picture Buffer 0 to Reference Index Mapping] */
    unsigned fcv_sram_base_0_1;                       /* < 1> [dv:         na] [des: Picture Buffer 1 to Reference Index Mapping] */
    unsigned fcv_sram_base_0_2;                       /* < 2> [dv:         na] [des: Picture Buffer 2 to Reference Index Mapping] */
    unsigned fcv_sram_base_0_3;                       /* < 3> [dv:         na] [des: Picture Buffer 3 to Reference Index Mapping] */
    unsigned fcv_sram_base_0_4;                       /* < 4> [dv:         na] [des: Picture Buffer 4 to Reference Index Mapping] */
    unsigned fcv_sram_base_0_5;                       /* < 5> [dv:         na] [des: Picture Buffer 5 to Reference Index Mapping] */
    unsigned fcv_sram_base_0_6;                       /* < 6> [dv:         na] [des: Picture Buffer 6 to Reference Index Mapping] */
    unsigned fcv_sram_base_0_7;                       /* < 7> [dv:         na] [des: Picture Buffer 7 to Reference Index Mapping] */
    unsigned fcv_sram_base_0_8;                       /* < 8> [dv:         na] [des: Picture Buffer 8 to Reference Index Mapping] */
    unsigned fcv_sram_base_0_9;                       /* < 9> [dv:         na] [des: Picture Buffer 9 to Reference Index Mapping] */
    unsigned fcv_sram_base_0_10;                      /* <10> [dv:         na] [des: Picture Buffer 10 to Reference Index Mapping] */
    unsigned fcv_sram_base_0_11;                      /* <11> [dv:         na] [des: Picture Buffer 11 to Reference Index Mapping] */
    unsigned fcv_sram_base_0_12;                      /* <12> [dv:         na] [des: Picture Buffer 12 to Reference Index Mapping] */
    unsigned fcv_sram_base_0_13;                      /* <13> [dv:         na] [des: Picture Buffer 13 to Reference Index Mapping] */
    unsigned fcv_sram_base_0_14;                      /* <14> [dv:         na] [des: Picture Buffer 14 to Reference Index Mapping] */
    unsigned fcv_sram_base_0_15;                      /* <15> [dv:         na] [des: Picture Buffer 15 to Reference Index Mapping] */
    unsigned fcv_sram_base_0_16;                      /* <16> [dv:         na] [des: Picture Buffer 16 to Reference Index Mapping] */
    unsigned fcv_sram_base_0_17;                      /* <17> [dv:         na] [des: Picture Buffer 17 to Reference Index Mapping] */
    unsigned fcv_sram_base_0_18;                      /* <18> [dv:         na] [des: Picture Buffer 18 to Reference Index Mapping] */
    unsigned fcv_sram_base_0_19;                      /* <19> [dv:         na] [des: Picture Buffer 19 to Reference Index Mapping] */
    unsigned fcv_sram_base_0_20;                      /* <20> [dv:         na] [des: Picture Buffer 20 to Reference Index Mapping] */
    unsigned fcv_sram_base_0_21;                      /* <21> [dv:         na] [des: Picture Buffer 21 to Reference Index Mapping] */
    unsigned fcv_sram_base_0_22;                      /* <22> [dv:         na] [des: Picture Buffer 22 to Reference Index Mapping] */
    unsigned fcv_sram_base_0_23;                      /* <23> [dv:         na] [des: Picture Buffer 23 to Reference Index Mapping] */
    unsigned fcv_sram_base_0_24;                      /* <24> [dv:         na] [des: Picture Buffer 24 to Reference Index Mapping] */
    unsigned fcv_sram_base_0_25;                      /* <25> [dv:         na] [des: Picture Buffer 25 to Reference Index Mapping] */
    unsigned fcv_sram_base_0_26;                      /* <26> [dv:         na] [des: Picture Buffer 26 to Reference Index Mapping] */
    unsigned fcv_sram_base_0_27;                      /* <27> [dv:         na] [des: Picture Buffer 27 to Reference Index Mapping] */
    unsigned fcv_sram_base_0_28;                      /* <28> [dv:         na] [des: Picture Buffer 28 to Reference Index Mapping] */
    unsigned fcv_sram_base_0_29;                      /* <29> [dv:         na] [des: Picture Buffer 29 to Reference Index Mapping] */
    unsigned fcv_sram_base_0_30;                      /* <30> [dv:         na] [des: Picture Buffer 30 to Reference Index Mapping] */
    unsigned fcv_sram_base_0_31;                      /* <31> [dv:         na] [des: Picture Buffer 31 to Reference Index Mapping] */
    // GROUP 385 [h.264_avs_and_realvideo_frame_buffer_base_index_to_reference_index_mapping_group_1]
    unsigned fcv_sram_base_1_0;                       /* < 0> [dv:         na] [des: Picture Buffer 32 to Reference Index Mapping] */
    unsigned fcv_sram_base_1_1;                       /* < 1> [dv:         na] [des: Picture Buffer 33 to Reference Index Mapping] */
    unsigned fcv_sram_base_1_2;                       /* < 2> [dv:         na] [des: Picture Buffer 34 to Reference Index Mapping] */
    unsigned fcv_sram_base_1_3;                       /* < 3> [dv:         na] [des: Picture Buffer 35 to Reference Index Mapping] */
    unsigned fcv_sram_base_1_4;                       /* < 4> [dv:         na] [des: Picture Buffer 36 to Reference Index Mapping] */
    unsigned fcv_sram_base_1_5;                       /* < 5> [dv:         na] [des: Picture Buffer 37 to Reference Index Mapping] */
    unsigned fcv_sram_base_1_6;                       /* < 6> [dv:         na] [des: Picture Buffer 38 to Reference Index Mapping] */
    unsigned fcv_sram_base_1_7;                       /* < 7> [dv:         na] [des: Picture Buffer 39 to Reference Index Mapping] */
    unsigned fcv_sram_base_1_8;                       /* < 8> [dv:         na] [des: Picture Buffer 40 to Reference Index Mapping] */
    unsigned fcv_sram_base_1_9;                       /* < 9> [dv:         na] [des: Picture Buffer 41 to Reference Index Mapping] */
    unsigned fcv_sram_base_1_10;                      /* <10> [dv:         na] [des: Picture Buffer 42 to Reference Index Mapping] */
    unsigned fcv_sram_base_1_11;                      /* <11> [dv:         na] [des: Picture Buffer 43 to Reference Index Mapping] */
    unsigned fcv_sram_base_1_12;                      /* <12> [dv:         na] [des: Picture Buffer 44 to Reference Index Mapping] */
    unsigned fcv_sram_base_1_13;                      /* <13> [dv:         na] [des: Picture Buffer 45 to Reference Index Mapping] */
    unsigned fcv_sram_base_1_14;                      /* <14> [dv:         na] [des: Picture Buffer 46 to Reference Index Mapping] */
    unsigned fcv_sram_base_1_15;                      /* <15> [dv:         na] [des: Picture Buffer 47 to Reference Index Mapping] */
    unsigned fcv_sram_base_1_16;                      /* <16> [dv:         na] [des: Picture Buffer 48 to Reference Index Mapping] */
    unsigned fcv_sram_base_1_17;                      /* <17> [dv:         na] [des: Picture Buffer 49 to Reference Index Mapping] */
    unsigned fcv_sram_base_1_18;                      /* <18> [dv:         na] [des: Picture Buffer 50 to Reference Index Mapping] */
    unsigned fcv_sram_base_1_19;                      /* <19> [dv:         na] [des: Picture Buffer 51 to Reference Index Mapping] */
    unsigned fcv_sram_base_1_20;                      /* <20> [dv:         na] [des: Picture Buffer 52 to Reference Index Mapping] */
    unsigned fcv_sram_base_1_21;                      /* <21> [dv:         na] [des: Picture Buffer 53 to Reference Index Mapping] */
    unsigned fcv_sram_base_1_22;                      /* <22> [dv:         na] [des: Picture Buffer 54 to Reference Index Mapping] */
    unsigned fcv_sram_base_1_23;                      /* <23> [dv:         na] [des: Picture Buffer 55 to Reference Index Mapping] */
    unsigned fcv_sram_base_1_24;                      /* <24> [dv:         na] [des: Picture Buffer 56 to Reference Index Mapping] */
    unsigned fcv_sram_base_1_25;                      /* <25> [dv:         na] [des: Picture Buffer 57 to Reference Index Mapping] */
    unsigned fcv_sram_base_1_26;                      /* <26> [dv:         na] [des: Picture Buffer 58 to Reference Index Mapping] */
    unsigned fcv_sram_base_1_27;                      /* <27> [dv:         na] [des: Picture Buffer 59 to Reference Index Mapping] */
    unsigned fcv_sram_base_1_28;                      /* <28> [dv:         na] [des: Picture Buffer 60 to Reference Index Mapping] */
    unsigned fcv_sram_base_1_29;                      /* <29> [dv:         na] [des: Picture Buffer 61 to Reference Index Mapping] */
    unsigned fcv_sram_base_1_30;                      /* <30> [dv:         na] [des: Picture Buffer 62 to Reference Index Mapping] */
    unsigned fcv_sram_base_1_31;                      /* <31> [dv:         na] [des: Picture Buffer 63 to Reference Index Mapping] */
    // GROUP 386 [reference_index_of_list0_to_frame_buffer_index_mapping_group_0]
    unsigned mr_rb_sram_base[64];
    // GROUP 388 [distscalefactor_group_0]
    unsigned dist_scale_factor_0;                     /* < 0> [dv:         na] [des: Scale Factor 00] */
    unsigned dist_scale_factor_1;                     /* < 1> [dv:         na] [des: Scale Factor 01] */
    unsigned dist_scale_factor_2;                     /* < 2> [dv:         na] [des: Scale Factor 02] */
    unsigned dist_scale_factor_3;                     /* < 3> [dv:         na] [des: Scale Factor 03] */
    unsigned dist_scale_factor_4;                     /* < 4> [dv:         na] [des: Scale Factor 04] */
    unsigned dist_scale_factor_5;                     /* < 5> [dv:         na] [des: Scale Factor 05] */
    unsigned dist_scale_factor_6;                     /* < 6> [dv:         na] [des: Scale Factor 06] */
    unsigned dist_scale_factor_7;                     /* < 7> [dv:         na] [des: Scale Factor 07] */
    unsigned dist_scale_factor_8;                     /* < 8> [dv:         na] [des: Scale Factor 08] */
    unsigned dist_scale_factor_9;                     /* < 9> [dv:         na] [des: Scale Factor 09] */
    unsigned dist_scale_factor_10;                    /* <10> [dv:         na] [des: Scale Factor 10] */
    unsigned dist_scale_factor_11;                    /* <11> [dv:         na] [des: Scale Factor 11] */
    unsigned dist_scale_factor_12;                    /* <12> [dv:         na] [des: Scale Factor 12] */
    unsigned dist_scale_factor_13;                    /* <13> [dv:         na] [des: Scale Factor 13] */
    unsigned dist_scale_factor_14;                    /* <14> [dv:         na] [des: Scale Factor 14] */
    unsigned dist_scale_factor_15;                    /* <15> [dv:         na] [des: Scale Factor 15] */
    unsigned dist_scale_factor_16;                    /* <16> [dv:         na] [des: Scale Factor 16] */
    unsigned dist_scale_factor_17;                    /* <17> [dv:         na] [des: Scale Factor 17] */
    unsigned dist_scale_factor_18;                    /* <18> [dv:         na] [des: Scale Factor 18] */
    unsigned dist_scale_factor_19;                    /* <19> [dv:         na] [des: Scale Factor 19] */
    unsigned dist_scale_factor_20;                    /* <20> [dv:         na] [des: Scale Factor 20] */
    unsigned dist_scale_factor_21;                    /* <21> [dv:         na] [des: Scale Factor 21] */
    unsigned dist_scale_factor_22;                    /* <22> [dv:         na] [des: Scale Factor 22] */
    unsigned dist_scale_factor_23;                    /* <23> [dv:         na] [des: Scale Factor 23] */
    unsigned dist_scale_factor_24;                    /* <24> [dv:         na] [des: Scale Factor 24] */
    unsigned dist_scale_factor_25;                    /* <25> [dv:         na] [des: Scale Factor 25] */
    unsigned dist_scale_factor_26;                    /* <26> [dv:         na] [des: Scale Factor 26] */
    unsigned dist_scale_factor_27;                    /* <27> [dv:         na] [des: Scale Factor 27] */
    unsigned dist_scale_factor_28;                    /* <28> [dv:         na] [des: Scale Factor 28] */
    unsigned dist_scale_factor_29;                    /* <29> [dv:         na] [des: Scale Factor 29] */
    unsigned dist_scale_factor_30;                    /* <30> [dv:         na] [des: Scale Factor 30] */
    unsigned dist_scale_factor_31;                    /* <31> [dv:         na] [des: Scale Factor 31] */
    // GROUP 389 [distscalefactor_group_1]
    unsigned dist_scale_factor_32;                    /* < 0> [dv:         na] [des: Scale Factor 32] */
    unsigned dist_scale_factor_33;                    /* < 1> [dv:         na] [des: Scale Factor 33] */
    unsigned dist_scale_factor_34;                    /* < 2> [dv:         na] [des: Scale Factor 34] */
    unsigned dist_scale_factor_35;                    /* < 3> [dv:         na] [des: Scale Factor 35] */
    unsigned dist_scale_factor_36;                    /* < 4> [dv:         na] [des: Scale Factor 36] */
    unsigned dist_scale_factor_37;                    /* < 5> [dv:         na] [des: Scale Factor 37] */
    unsigned dist_scale_factor_38;                    /* < 6> [dv:         na] [des: Scale Factor 38] */
    unsigned dist_scale_factor_39;                    /* < 7> [dv:         na] [des: Scale Factor 39] */
    unsigned dist_scale_factor_40;                    /* < 8> [dv:         na] [des: Scale Factor 40] */
    unsigned dist_scale_factor_41;                    /* < 9> [dv:         na] [des: Scale Factor 41] */
    unsigned dist_scale_factor_42;                    /* <10> [dv:         na] [des: Scale Factor 42] */
    unsigned dist_scale_factor_43;                    /* <11> [dv:         na] [des: Scale Factor 43] */
    unsigned dist_scale_factor_44;                    /* <12> [dv:         na] [des: Scale Factor 44] */
    unsigned dist_scale_factor_45;                    /* <13> [dv:         na] [des: Scale Factor 45] */
    unsigned dist_scale_factor_46;                    /* <14> [dv:         na] [des: Scale Factor 46] */
    unsigned dist_scale_factor_47;                    /* <15> [dv:         na] [des: Scale Factor 47] */
    unsigned dist_scale_factor_48;                    /* <16> [dv:         na] [des: Scale Factor 48] */
    unsigned dist_scale_factor_49;                    /* <17> [dv:         na] [des: Scale Factor 49] */
    unsigned dist_scale_factor_50;                    /* <18> [dv:         na] [des: Scale Factor 50] */
    unsigned dist_scale_factor_51;                    /* <19> [dv:         na] [des: Scale Factor 51] */
    unsigned dist_scale_factor_52;                    /* <20> [dv:         na] [des: Scale Factor 52] */
    unsigned dist_scale_factor_53;                    /* <21> [dv:         na] [des: Scale Factor 53] */
    unsigned dist_scale_factor_54;                    /* <22> [dv:         na] [des: Scale Factor 54] */
    unsigned dist_scale_factor_55;                    /* <23> [dv:         na] [des: Scale Factor 55] */
    unsigned dist_scale_factor_56;                    /* <24> [dv:         na] [des: Scale Factor 56] */
    unsigned dist_scale_factor_57;                    /* <25> [dv:         na] [des: Scale Factor 57] */
    unsigned dist_scale_factor_58;                    /* <26> [dv:         na] [des: Scale Factor 58] */
    unsigned dist_scale_factor_59;                    /* <27> [dv:         na] [des: Scale Factor 59] */
    unsigned dist_scale_factor_60;                    /* <28> [dv:         na] [des: Scale Factor 60] */
    unsigned dist_scale_factor_61;                    /* <29> [dv:         na] [des: Scale Factor 61] */
    unsigned dist_scale_factor_62;                    /* <30> [dv:         na] [des: Scale Factor 62] */
    unsigned dist_scale_factor_63;                    /* <31> [dv:         na] [des: Scale Factor 63] */
    // GROUP 390 [distscalefactor_group_2]
    unsigned dist_scale_factor_64;                    /* < 0> [dv:         na] [des: Scale Factor 64] */
    unsigned dist_scale_factor_65;                    /* < 1> [dv:         na] [des: Scale Factor 65] */
    unsigned dist_scale_factor_66;                    /* < 2> [dv:         na] [des: Scale Factor 66] */
    unsigned dist_scale_factor_67;                    /* < 3> [dv:         na] [des: Scale Factor 67] */
    unsigned dist_scale_factor_68;                    /* < 4> [dv:         na] [des: Scale Factor 68] */
    unsigned dist_scale_factor_69;                    /* < 5> [dv:         na] [des: Scale Factor 69] */
    unsigned dist_scale_factor_70;                    /* < 6> [dv:         na] [des: Scale Factor 70] */
    unsigned dist_scale_factor_71;                    /* < 7> [dv:         na] [des: Scale Factor 71] */
    unsigned dist_scale_factor_72;                    /* < 8> [dv:         na] [des: Scale Factor 72] */
    unsigned dist_scale_factor_73;                    /* < 9> [dv:         na] [des: Scale Factor 73] */
    unsigned dist_scale_factor_74;                    /* <10> [dv:         na] [des: Scale Factor 74] */
    unsigned dist_scale_factor_75;                    /* <11> [dv:         na] [des: Scale Factor 75] */
    unsigned dist_scale_factor_76;                    /* <12> [dv:         na] [des: Scale Factor 76] */
    unsigned dist_scale_factor_77;                    /* <13> [dv:         na] [des: Scale Factor 77] */
    unsigned dist_scale_factor_78;                    /* <14> [dv:         na] [des: Scale Factor 78] */
    unsigned dist_scale_factor_79;                    /* <15> [dv:         na] [des: Scale Factor 79] */
    unsigned reserved_0_57;                           /* <16> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_1_51;                           /* <17> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_2_43;                           /* <18> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_3_31;                           /* <19> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_4_28;                           /* <20> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_5_26;                           /* <21> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_6_23;                           /* <22> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_7_23;                           /* <23> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_8_22;                           /* <24> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_9_19;                           /* <25> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_10_19;                          /* <26> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_11_12;                          /* <27> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_12_8;                           /* <28> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_13_8;                           /* <29> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_14_8;                           /* <30> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_15_7;                           /* <31> [dv:     0x0000] [des: Reserved] */
    // GROUP 391 [reserved]
    unsigned grp391_reserved_0;                       /* < 0> */
    unsigned grp391_reserved_1;                       /* < 1> */
    unsigned grp391_reserved_2;                       /* < 2> */
    unsigned grp391_reserved_3;                       /* < 3> */
    unsigned grp391_reserved_4;                       /* < 4> */
    unsigned grp391_reserved_5;                       /* < 5> */
    unsigned grp391_reserved_6;                       /* < 6> */
    unsigned grp391_reserved_7;                       /* < 7> */
    unsigned grp391_reserved_8;                       /* < 8> */
    unsigned grp391_reserved_9;                       /* < 9> */
    unsigned grp391_reserved_10;                      /* <10> */
    unsigned grp391_reserved_11;                      /* <11> */
    unsigned grp391_reserved_12;                      /* <12> */
    unsigned grp391_reserved_13;                      /* <13> */
    unsigned grp391_reserved_14;                      /* <14> */
    unsigned grp391_reserved_15;                      /* <15> */
    unsigned grp391_reserved_16;                      /* <16> */
    unsigned grp391_reserved_17;                      /* <17> */
    unsigned grp391_reserved_18;                      /* <18> */
    unsigned grp391_reserved_19;                      /* <19> */
    unsigned grp391_reserved_20;                      /* <20> */
    unsigned grp391_reserved_21;                      /* <21> */
    unsigned grp391_reserved_22;                      /* <22> */
    unsigned grp391_reserved_23;                      /* <23> */
    unsigned grp391_reserved_24;                      /* <24> */
    unsigned grp391_reserved_25;                      /* <25> */
    unsigned grp391_reserved_26;                      /* <26> */
    unsigned grp391_reserved_27;                      /* <27> */
    unsigned grp391_reserved_28;                      /* <28> */
    unsigned grp391_reserved_29;                      /* <29> */
    unsigned grp391_reserved_30;                      /* <30> */
    unsigned grp391_reserved_31;                      /* <31> */
    // GROUP 392 [weighted_prediction_distscalefactor_group_0]
    unsigned mr_wt_sram_base_0_0;                     /* < 0> [dv:         na] [des: Item 0 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_0_1;                     /* < 1> [dv:         na] [des: Item 1 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_0_2;                     /* < 2> [dv:         na] [des: Item 2 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_0_3;                     /* < 3> [dv:         na] [des: Item 3 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_0_4;                     /* < 4> [dv:         na] [des: Item 4 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_0_5;                     /* < 5> [dv:         na] [des: Item 5 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_0_6;                     /* < 6> [dv:         na] [des: Item 6 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_0_7;                     /* < 7> [dv:         na] [des: Item 7 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_0_8;                     /* < 8> [dv:         na] [des: Item 8 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_0_9;                     /* < 9> [dv:         na] [des: Item 9 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_0_10;                    /* <10> [dv:         na] [des: Item 10 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_0_11;                    /* <11> [dv:         na] [des: Item 11 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_0_12;                    /* <12> [dv:         na] [des: Item 12 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_0_13;                    /* <13> [dv:         na] [des: Item 13 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_0_14;                    /* <14> [dv:         na] [des: Item 14 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_0_15;                    /* <15> [dv:         na] [des: Item 15 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_0_16;                    /* <16> [dv:         na] [des: Item 16 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_0_17;                    /* <17> [dv:         na] [des: Item 17 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_0_18;                    /* <18> [dv:         na] [des: Item 18 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_0_19;                    /* <19> [dv:         na] [des: Item 19 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_0_20;                    /* <20> [dv:         na] [des: Item 20 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_0_21;                    /* <21> [dv:         na] [des: Item 21 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_0_22;                    /* <22> [dv:         na] [des: Item 22 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_0_23;                    /* <23> [dv:         na] [des: Item 23 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_0_24;                    /* <24> [dv:         na] [des: Item 24 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_0_25;                    /* <25> [dv:         na] [des: Item 25 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_0_26;                    /* <26> [dv:         na] [des: Item 26 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_0_27;                    /* <27> [dv:         na] [des: Item 27 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_0_28;                    /* <28> [dv:         na] [des: Item 28 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_0_29;                    /* <29> [dv:         na] [des: Item 29 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_0_30;                    /* <30> [dv:         na] [des: Item 30 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_0_31;                    /* <31> [dv:         na] [des: Item 31 for Weighted Prediction/DistScaleFactor] */
    // GROUP 393 [weighted_prediction_distscalefactor_group_1]
    unsigned mr_wt_sram_base_1_0;                     /* < 0> [dv:         na] [des: Item 32 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_1_1;                     /* < 1> [dv:         na] [des: Item 33 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_1_2;                     /* < 2> [dv:         na] [des: Item 34 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_1_3;                     /* < 3> [dv:         na] [des: Item 35 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_1_4;                     /* < 4> [dv:         na] [des: Item 36 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_1_5;                     /* < 5> [dv:         na] [des: Item 37 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_1_6;                     /* < 6> [dv:         na] [des: Item 38 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_1_7;                     /* < 7> [dv:         na] [des: Item 39 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_1_8;                     /* < 8> [dv:         na] [des: Item 40 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_1_9;                     /* < 9> [dv:         na] [des: Item 41 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_1_10;                    /* <10> [dv:         na] [des: Item 42 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_1_11;                    /* <11> [dv:         na] [des: Item 43 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_1_12;                    /* <12> [dv:         na] [des: Item 44 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_1_13;                    /* <13> [dv:         na] [des: Item 45 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_1_14;                    /* <14> [dv:         na] [des: Item 46 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_1_15;                    /* <15> [dv:         na] [des: Item 47 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_1_16;                    /* <16> [dv:         na] [des: Item 48 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_1_17;                    /* <17> [dv:         na] [des: Item 49 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_1_18;                    /* <18> [dv:         na] [des: Item 50 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_1_19;                    /* <19> [dv:         na] [des: Item 51 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_1_20;                    /* <20> [dv:         na] [des: Item 52 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_1_21;                    /* <21> [dv:         na] [des: Item 53 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_1_22;                    /* <22> [dv:         na] [des: Item 54 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_1_23;                    /* <23> [dv:         na] [des: Item 55 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_1_24;                    /* <24> [dv:         na] [des: Item 56 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_1_25;                    /* <25> [dv:         na] [des: Item 57 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_1_26;                    /* <26> [dv:         na] [des: Item 58 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_1_27;                    /* <27> [dv:         na] [des: Item 59 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_1_28;                    /* <28> [dv:         na] [des: Item 60 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_1_29;                    /* <29> [dv:         na] [des: Item 61 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_1_30;                    /* <30> [dv:         na] [des: Item 62 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_1_31;                    /* <31> [dv:         na] [des: Item 63 for Weighted Prediction/DistScaleFactor] */
    // GROUP 394 [weighted_prediction_distscalefactor_group_2]
    unsigned mr_wt_sram_base_2_0;                     /* < 0> [dv:         na] [des: Item 64 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_2_1;                     /* < 1> [dv:         na] [des: Item 65 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_2_2;                     /* < 2> [dv:         na] [des: Item 66 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_2_3;                     /* < 3> [dv:         na] [des: Item 67 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_2_4;                     /* < 4> [dv:         na] [des: Item 68 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_2_5;                     /* < 5> [dv:         na] [des: Item 69 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_2_6;                     /* < 6> [dv:         na] [des: Item 70 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_2_7;                     /* < 7> [dv:         na] [des: Item 71 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_2_8;                     /* < 8> [dv:         na] [des: Item 72 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_2_9;                     /* < 9> [dv:         na] [des: Item 73 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_2_10;                    /* <10> [dv:         na] [des: Item 74 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_2_11;                    /* <11> [dv:         na] [des: Item 75 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_2_12;                    /* <12> [dv:         na] [des: Item 76 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_2_13;                    /* <13> [dv:         na] [des: Item 77 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_2_14;                    /* <14> [dv:         na] [des: Item 78 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_2_15;                    /* <15> [dv:         na] [des: Item 79 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_2_16;                    /* <16> [dv:         na] [des: Item 80 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_2_17;                    /* <17> [dv:         na] [des: Item 81 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_2_18;                    /* <18> [dv:         na] [des: Item 82 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_2_19;                    /* <19> [dv:         na] [des: Item 83 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_2_20;                    /* <20> [dv:         na] [des: Item 84 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_2_21;                    /* <21> [dv:         na] [des: Item 85 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_2_22;                    /* <22> [dv:         na] [des: Item 86 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_2_23;                    /* <23> [dv:         na] [des: Item 87 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_2_24;                    /* <24> [dv:         na] [des: Item 88 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_2_25;                    /* <25> [dv:         na] [des: Item 89 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_2_26;                    /* <26> [dv:         na] [des: Item 90 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_2_27;                    /* <27> [dv:         na] [des: Item 91 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_2_28;                    /* <28> [dv:         na] [des: Item 92 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_2_29;                    /* <29> [dv:         na] [des: Item 93 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_2_30;                    /* <30> [dv:         na] [des: Item 94 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_2_31;                    /* <31> [dv:         na] [des: Item 95 for Weighted Prediction/DistScaleFactor] */
    // GROUP 395 [weighted_prediction_distscalefactor_group_3]
    unsigned mr_wt_sram_base_3_0;                     /* < 0> [dv:         na] [des: Item 96 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_3_1;                     /* < 1> [dv:         na] [des: Item 97 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_3_2;                     /* < 2> [dv:         na] [des: Item 98 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_3_3;                     /* < 3> [dv:         na] [des: Item 99 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_3_4;                     /* < 4> [dv:         na] [des: Item 100 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_3_5;                     /* < 5> [dv:         na] [des: Item 101 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_3_6;                     /* < 6> [dv:         na] [des: Item 102 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_3_7;                     /* < 7> [dv:         na] [des: Item 103 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_3_8;                     /* < 8> [dv:         na] [des: Item 104 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_3_9;                     /* < 9> [dv:         na] [des: Item 105 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_3_10;                    /* <10> [dv:         na] [des: Item 106 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_3_11;                    /* <11> [dv:         na] [des: Item 107 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_3_12;                    /* <12> [dv:         na] [des: Item 108 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_3_13;                    /* <13> [dv:         na] [des: Item 109 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_3_14;                    /* <14> [dv:         na] [des: Item 110 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_3_15;                    /* <15> [dv:         na] [des: Item 111 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_3_16;                    /* <16> [dv:         na] [des: Item 112 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_3_17;                    /* <17> [dv:         na] [des: Item 113 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_3_18;                    /* <18> [dv:         na] [des: Item 114 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_3_19;                    /* <19> [dv:         na] [des: Item 115 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_3_20;                    /* <20> [dv:         na] [des: Item 116 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_3_21;                    /* <21> [dv:         na] [des: Item 117 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_3_22;                    /* <22> [dv:         na] [des: Item 118 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_3_23;                    /* <23> [dv:         na] [des: Item 119 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_3_24;                    /* <24> [dv:         na] [des: Item 120 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_3_25;                    /* <25> [dv:         na] [des: Item 121 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_3_26;                    /* <26> [dv:         na] [des: Item 122 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_3_27;                    /* <27> [dv:         na] [des: Item 123 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_3_28;                    /* <28> [dv:         na] [des: Item 124 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_3_29;                    /* <29> [dv:         na] [des: Item 125 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_3_30;                    /* <30> [dv:         na] [des: Item 126 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_3_31;                    /* <31> [dv:         na] [des: Item 127 for Weighted Prediction/DistScaleFactor] */
    // GROUP 396 [weighted_prediction_distscalefactor_group_4]
    unsigned mr_wt_sram_base_4_0;                     /* < 0> [dv:         na] [des: Item 128 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_4_1;                     /* < 1> [dv:         na] [des: Item 129 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_4_2;                     /* < 2> [dv:         na] [des: Item 130 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_4_3;                     /* < 3> [dv:         na] [des: Item 131 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_4_4;                     /* < 4> [dv:         na] [des: Item 132 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_4_5;                     /* < 5> [dv:         na] [des: Item 133 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_4_6;                     /* < 6> [dv:         na] [des: Item 134 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_4_7;                     /* < 7> [dv:         na] [des: Item 135 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_4_8;                     /* < 8> [dv:         na] [des: Item 136 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_4_9;                     /* < 9> [dv:         na] [des: Item 137 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_4_10;                    /* <10> [dv:         na] [des: Item 138 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_4_11;                    /* <11> [dv:         na] [des: Item 139 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_4_12;                    /* <12> [dv:         na] [des: Item 140 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_4_13;                    /* <13> [dv:         na] [des: Item 141 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_4_14;                    /* <14> [dv:         na] [des: Item 142 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_4_15;                    /* <15> [dv:         na] [des: Item 143 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_4_16;                    /* <16> [dv:         na] [des: Item 144 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_4_17;                    /* <17> [dv:         na] [des: Item 145 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_4_18;                    /* <18> [dv:         na] [des: Item 146 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_4_19;                    /* <19> [dv:         na] [des: Item 147 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_4_20;                    /* <20> [dv:         na] [des: Item 148 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_4_21;                    /* <21> [dv:         na] [des: Item 149 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_4_22;                    /* <22> [dv:         na] [des: Item 150 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_4_23;                    /* <23> [dv:         na] [des: Item 151 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_4_24;                    /* <24> [dv:         na] [des: Item 152 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_4_25;                    /* <25> [dv:         na] [des: Item 153 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_4_26;                    /* <26> [dv:         na] [des: Item 154 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_4_27;                    /* <27> [dv:         na] [des: Item 155 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_4_28;                    /* <28> [dv:         na] [des: Item 156 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_4_29;                    /* <29> [dv:         na] [des: Item 157 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_4_30;                    /* <30> [dv:         na] [des: Item 158 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_4_31;                    /* <31> [dv:         na] [des: Item 159 for Weighted Prediction/DistScaleFactor] */
    // GROUP 397 [weighted_prediction_distscalefactor_group_5]
    unsigned mr_wt_sram_base_5_0;                     /* < 0> [dv:         na] [des: Item 160 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_5_1;                     /* < 1> [dv:         na] [des: Item 161 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_5_2;                     /* < 2> [dv:         na] [des: Item 162 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_5_3;                     /* < 3> [dv:         na] [des: Item 163 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_5_4;                     /* < 4> [dv:         na] [des: Item 164 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_5_5;                     /* < 5> [dv:         na] [des: Item 165 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_5_6;                     /* < 6> [dv:         na] [des: Item 166 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_5_7;                     /* < 7> [dv:         na] [des: Item 167 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_5_8;                     /* < 8> [dv:         na] [des: Item 168 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_5_9;                     /* < 9> [dv:         na] [des: Item 169 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_5_10;                    /* <10> [dv:         na] [des: Item 170 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_5_11;                    /* <11> [dv:         na] [des: Item 171 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_5_12;                    /* <12> [dv:         na] [des: Item 172 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_5_13;                    /* <13> [dv:         na] [des: Item 173 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_5_14;                    /* <14> [dv:         na] [des: Item 174 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_5_15;                    /* <15> [dv:         na] [des: Item 175 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_5_16;                    /* <16> [dv:         na] [des: Item 176 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_5_17;                    /* <17> [dv:         na] [des: Item 177 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_5_18;                    /* <18> [dv:         na] [des: Item 178 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_5_19;                    /* <19> [dv:         na] [des: Item 179 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_5_20;                    /* <20> [dv:         na] [des: Item 180 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_5_21;                    /* <21> [dv:         na] [des: Item 181 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_5_22;                    /* <22> [dv:         na] [des: Item 182 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_5_23;                    /* <23> [dv:         na] [des: Item 183 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_5_24;                    /* <24> [dv:         na] [des: Item 184 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_5_25;                    /* <25> [dv:         na] [des: Item 185 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_5_26;                    /* <26> [dv:         na] [des: Item 186 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_5_27;                    /* <27> [dv:         na] [des: Item 187 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_5_28;                    /* <28> [dv:         na] [des: Item 188 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_5_29;                    /* <29> [dv:         na] [des: Item 189 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_5_30;                    /* <30> [dv:         na] [des: Item 190 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_5_31;                    /* <31> [dv:         na] [des: Item 191 for Weighted Prediction/DistScaleFactor] */
    // GROUP 398 [weighted_prediction_distscalefactor_group_6]
    unsigned mr_wt_sram_base_6_0;                     /* < 0> [dv:         na] [des: Item 192 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_6_1;                     /* < 1> [dv:         na] [des: Item 193 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_6_2;                     /* < 2> [dv:         na] [des: Item 194 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_6_3;                     /* < 3> [dv:         na] [des: Item 195 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_6_4;                     /* < 4> [dv:         na] [des: Item 196 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_6_5;                     /* < 5> [dv:         na] [des: Item 197 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_6_6;                     /* < 6> [dv:         na] [des: Item 198 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_6_7;                     /* < 7> [dv:         na] [des: Item 199 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_6_8;                     /* < 8> [dv:         na] [des: Item 200 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_6_9;                     /* < 9> [dv:         na] [des: Item 201 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_6_10;                    /* <10> [dv:         na] [des: Item 202 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_6_11;                    /* <11> [dv:         na] [des: Item 203 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_6_12;                    /* <12> [dv:         na] [des: Item 204 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_6_13;                    /* <13> [dv:         na] [des: Item 205 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_6_14;                    /* <14> [dv:         na] [des: Item 206 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_6_15;                    /* <15> [dv:         na] [des: Item 207 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_6_16;                    /* <16> [dv:         na] [des: Item 208 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_6_17;                    /* <17> [dv:         na] [des: Item 209 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_6_18;                    /* <18> [dv:         na] [des: Item 210 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_6_19;                    /* <19> [dv:         na] [des: Item 211 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_6_20;                    /* <20> [dv:         na] [des: Item 212 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_6_21;                    /* <21> [dv:         na] [des: Item 213 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_6_22;                    /* <22> [dv:         na] [des: Item 214 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_6_23;                    /* <23> [dv:         na] [des: Item 215 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_6_24;                    /* <24> [dv:         na] [des: Item 216 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_6_25;                    /* <25> [dv:         na] [des: Item 217 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_6_26;                    /* <26> [dv:         na] [des: Item 218 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_6_27;                    /* <27> [dv:         na] [des: Item 219 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_6_28;                    /* <28> [dv:         na] [des: Item 220 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_6_29;                    /* <29> [dv:         na] [des: Item 221 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_6_30;                    /* <30> [dv:         na] [des: Item 222 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_6_31;                    /* <31> [dv:         na] [des: Item 223 for Weighted Prediction/DistScaleFactor] */
    // GROUP 399 [weighted_prediction_distscalefactor_group_7]
    unsigned mr_wt_sram_base_7_0;                     /* < 0> [dv:         na] [des: Item 224 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_7_1;                     /* < 1> [dv:         na] [des: Item 225 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_7_2;                     /* < 2> [dv:         na] [des: Item 226 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_7_3;                     /* < 3> [dv:         na] [des: Item 227 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_7_4;                     /* < 4> [dv:         na] [des: Item 228 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_7_5;                     /* < 5> [dv:         na] [des: Item 229 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_7_6;                     /* < 6> [dv:         na] [des: Item 230 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_7_7;                     /* < 7> [dv:         na] [des: Item 231 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_7_8;                     /* < 8> [dv:         na] [des: Item 232 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_7_9;                     /* < 9> [dv:         na] [des: Item 233 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_7_10;                    /* <10> [dv:         na] [des: Item 234 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_7_11;                    /* <11> [dv:         na] [des: Item 235 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_7_12;                    /* <12> [dv:         na] [des: Item 236 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_7_13;                    /* <13> [dv:         na] [des: Item 237 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_7_14;                    /* <14> [dv:         na] [des: Item 238 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_7_15;                    /* <15> [dv:         na] [des: Item 239 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_7_16;                    /* <16> [dv:         na] [des: Item 240 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_7_17;                    /* <17> [dv:         na] [des: Item 241 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_7_18;                    /* <18> [dv:         na] [des: Item 242 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_7_19;                    /* <19> [dv:         na] [des: Item 243 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_7_20;                    /* <20> [dv:         na] [des: Item 244 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_7_21;                    /* <21> [dv:         na] [des: Item 245 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_7_22;                    /* <22> [dv:         na] [des: Item 246 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_7_23;                    /* <23> [dv:         na] [des: Item 247 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_7_24;                    /* <24> [dv:         na] [des: Item 248 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_7_25;                    /* <25> [dv:         na] [des: Item 249 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_7_26;                    /* <26> [dv:         na] [des: Item 250 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_7_27;                    /* <27> [dv:         na] [des: Item 251 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_7_28;                    /* <28> [dv:         na] [des: Item 252 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_7_29;                    /* <29> [dv:         na] [des: Item 253 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_7_30;                    /* <30> [dv:         na] [des: Item 254 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_7_31;                    /* <31> [dv:         na] [des: Item 255 for Weighted Prediction/DistScaleFactor] */
    // GROUP 400 [weighted_prediction_distscalefactor_group_8]
    unsigned mr_wt_sram_base_8_0;                     /* < 0> [dv:         na] [des: Item 256 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_8_1;                     /* < 1> [dv:         na] [des: Item 257 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_8_2;                     /* < 2> [dv:         na] [des: Item 258 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_8_3;                     /* < 3> [dv:         na] [des: Item 259 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_8_4;                     /* < 4> [dv:         na] [des: Item 260 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_8_5;                     /* < 5> [dv:         na] [des: Item 261 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_8_6;                     /* < 6> [dv:         na] [des: Item 262 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_8_7;                     /* < 7> [dv:         na] [des: Item 263 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_8_8;                     /* < 8> [dv:         na] [des: Item 264 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_8_9;                     /* < 9> [dv:         na] [des: Item 265 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_8_10;                    /* <10> [dv:         na] [des: Item 266 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_8_11;                    /* <11> [dv:         na] [des: Item 267 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_8_12;                    /* <12> [dv:         na] [des: Item 268 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_8_13;                    /* <13> [dv:         na] [des: Item 269 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_8_14;                    /* <14> [dv:         na] [des: Item 270 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_8_15;                    /* <15> [dv:         na] [des: Item 271 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_8_16;                    /* <16> [dv:         na] [des: Item 272 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_8_17;                    /* <17> [dv:         na] [des: Item 273 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_8_18;                    /* <18> [dv:         na] [des: Item 274 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_8_19;                    /* <19> [dv:         na] [des: Item 275 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_8_20;                    /* <20> [dv:         na] [des: Item 276 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_8_21;                    /* <21> [dv:         na] [des: Item 277 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_8_22;                    /* <22> [dv:         na] [des: Item 278 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_8_23;                    /* <23> [dv:         na] [des: Item 279 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_8_24;                    /* <24> [dv:         na] [des: Item 280 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_8_25;                    /* <25> [dv:         na] [des: Item 281 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_8_26;                    /* <26> [dv:         na] [des: Item 282 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_8_27;                    /* <27> [dv:         na] [des: Item 283 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_8_28;                    /* <28> [dv:         na] [des: Item 284 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_8_29;                    /* <29> [dv:         na] [des: Item 285 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_8_30;                    /* <30> [dv:         na] [des: Item 286 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_8_31;                    /* <31> [dv:         na] [des: Item 287 for Weighted Prediction/DistScaleFactor] */
    // GROUP 401 [weighted_prediction_distscalefactor_group_9]
    unsigned mr_wt_sram_base_9_0;                     /* < 0> [dv:         na] [des: Item 288 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_9_1;                     /* < 1> [dv:         na] [des: Item 289 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_9_2;                     /* < 2> [dv:         na] [des: Item 290 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_9_3;                     /* < 3> [dv:         na] [des: Item 291 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_9_4;                     /* < 4> [dv:         na] [des: Item 292 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_9_5;                     /* < 5> [dv:         na] [des: Item 293 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_9_6;                     /* < 6> [dv:         na] [des: Item 294 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_9_7;                     /* < 7> [dv:         na] [des: Item 295 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_9_8;                     /* < 8> [dv:         na] [des: Item 296 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_9_9;                     /* < 9> [dv:         na] [des: Item 297 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_9_10;                    /* <10> [dv:         na] [des: Item 298 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_9_11;                    /* <11> [dv:         na] [des: Item 299 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_9_12;                    /* <12> [dv:         na] [des: Item 300 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_9_13;                    /* <13> [dv:         na] [des: Item 301 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_9_14;                    /* <14> [dv:         na] [des: Item 302 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_9_15;                    /* <15> [dv:         na] [des: Item 303 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_9_16;                    /* <16> [dv:         na] [des: Item 304 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_9_17;                    /* <17> [dv:         na] [des: Item 305 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_9_18;                    /* <18> [dv:         na] [des: Item 306 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_9_19;                    /* <19> [dv:         na] [des: Item 307 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_9_20;                    /* <20> [dv:         na] [des: Item 308 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_9_21;                    /* <21> [dv:         na] [des: Item 309 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_9_22;                    /* <22> [dv:         na] [des: Item 310 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_9_23;                    /* <23> [dv:         na] [des: Item 311 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_9_24;                    /* <24> [dv:         na] [des: Item 312 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_9_25;                    /* <25> [dv:         na] [des: Item 313 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_9_26;                    /* <26> [dv:         na] [des: Item 314 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_9_27;                    /* <27> [dv:         na] [des: Item 315 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_9_28;                    /* <28> [dv:         na] [des: Item 316 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_9_29;                    /* <29> [dv:         na] [des: Item 317 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_9_30;                    /* <30> [dv:         na] [des: Item 318 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_9_31;                    /* <31> [dv:         na] [des: Item 319 for Weighted Prediction/DistScaleFactor] */
    // GROUP 402 [weighted_prediction_distscalefactor_group_10]
    unsigned mr_wt_sram_base_10_0;                    /* < 0> [dv:         na] [des: Item 320 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_10_1;                    /* < 1> [dv:         na] [des: Item 321 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_10_2;                    /* < 2> [dv:         na] [des: Item 322 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_10_3;                    /* < 3> [dv:         na] [des: Item 323 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_10_4;                    /* < 4> [dv:         na] [des: Item 324 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_10_5;                    /* < 5> [dv:         na] [des: Item 325 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_10_6;                    /* < 6> [dv:         na] [des: Item 326 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_10_7;                    /* < 7> [dv:         na] [des: Item 327 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_10_8;                    /* < 8> [dv:         na] [des: Item 328 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_10_9;                    /* < 9> [dv:         na] [des: Item 329 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_10_10;                   /* <10> [dv:         na] [des: Item 330 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_10_11;                   /* <11> [dv:         na] [des: Item 331 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_10_12;                   /* <12> [dv:         na] [des: Item 332 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_10_13;                   /* <13> [dv:         na] [des: Item 333 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_10_14;                   /* <14> [dv:         na] [des: Item 334 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_10_15;                   /* <15> [dv:         na] [des: Item 335 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_10_16;                   /* <16> [dv:         na] [des: Item 336 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_10_17;                   /* <17> [dv:         na] [des: Item 337 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_10_18;                   /* <18> [dv:         na] [des: Item 338 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_10_19;                   /* <19> [dv:         na] [des: Item 339 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_10_20;                   /* <20> [dv:         na] [des: Item 340 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_10_21;                   /* <21> [dv:         na] [des: Item 341 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_10_22;                   /* <22> [dv:         na] [des: Item 342 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_10_23;                   /* <23> [dv:         na] [des: Item 343 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_10_24;                   /* <24> [dv:         na] [des: Item 344 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_10_25;                   /* <25> [dv:         na] [des: Item 345 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_10_26;                   /* <26> [dv:         na] [des: Item 346 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_10_27;                   /* <27> [dv:         na] [des: Item 347 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_10_28;                   /* <28> [dv:         na] [des: Item 348 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_10_29;                   /* <29> [dv:         na] [des: Item 349 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_10_30;                   /* <30> [dv:         na] [des: Item 350 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_10_31;                   /* <31> [dv:         na] [des: Item 351 for Weighted Prediction/DistScaleFactor] */
    // GROUP 403 [weighted_prediction_distscalefactor_group_11]
    unsigned mr_wt_sram_base_11_0;                    /* < 0> [dv:         na] [des: Item 352 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_11_1;                    /* < 1> [dv:         na] [des: Item 353 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_11_2;                    /* < 2> [dv:         na] [des: Item 354 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_11_3;                    /* < 3> [dv:         na] [des: Item 355 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_11_4;                    /* < 4> [dv:         na] [des: Item 356 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_11_5;                    /* < 5> [dv:         na] [des: Item 357 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_11_6;                    /* < 6> [dv:         na] [des: Item 358 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_11_7;                    /* < 7> [dv:         na] [des: Item 359 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_11_8;                    /* < 8> [dv:         na] [des: Item 360 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_11_9;                    /* < 9> [dv:         na] [des: Item 361 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_11_10;                   /* <10> [dv:         na] [des: Item 362 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_11_11;                   /* <11> [dv:         na] [des: Item 363 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_11_12;                   /* <12> [dv:         na] [des: Item 364 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_11_13;                   /* <13> [dv:         na] [des: Item 365 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_11_14;                   /* <14> [dv:         na] [des: Item 366 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_11_15;                   /* <15> [dv:         na] [des: Item 367 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_11_16;                   /* <16> [dv:         na] [des: Item 368 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_11_17;                   /* <17> [dv:         na] [des: Item 369 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_11_18;                   /* <18> [dv:         na] [des: Item 370 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_11_19;                   /* <19> [dv:         na] [des: Item 371 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_11_20;                   /* <20> [dv:         na] [des: Item 372 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_11_21;                   /* <21> [dv:         na] [des: Item 373 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_11_22;                   /* <22> [dv:         na] [des: Item 374 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_11_23;                   /* <23> [dv:         na] [des: Item 375 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_11_24;                   /* <24> [dv:         na] [des: Item 376 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_11_25;                   /* <25> [dv:         na] [des: Item 377 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_11_26;                   /* <26> [dv:         na] [des: Item 378 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_11_27;                   /* <27> [dv:         na] [des: Item 379 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_11_28;                   /* <28> [dv:         na] [des: Item 380 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_11_29;                   /* <29> [dv:         na] [des: Item 381 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_11_30;                   /* <30> [dv:         na] [des: Item 382 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_11_31;                   /* <31> [dv:         na] [des: Item 383 for Weighted Prediction/DistScaleFactor] */
    // GROUP 404 [weighted_prediction_distscalefactor_group_12]
    unsigned mr_wt_sram_base_12_0;                    /* < 0> [dv:         na] [des: Item 384 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_12_1;                    /* < 1> [dv:         na] [des: Item 385 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_12_2;                    /* < 2> [dv:         na] [des: Item 386 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_12_3;                    /* < 3> [dv:         na] [des: Item 387 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_12_4;                    /* < 4> [dv:         na] [des: Item 388 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_12_5;                    /* < 5> [dv:         na] [des: Item 389 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_12_6;                    /* < 6> [dv:         na] [des: Item 390 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_12_7;                    /* < 7> [dv:         na] [des: Item 391 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_12_8;                    /* < 8> [dv:         na] [des: Item 392 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_12_9;                    /* < 9> [dv:         na] [des: Item 393 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_12_10;                   /* <10> [dv:         na] [des: Item 394 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_12_11;                   /* <11> [dv:         na] [des: Item 395 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_12_12;                   /* <12> [dv:         na] [des: Item 396 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_12_13;                   /* <13> [dv:         na] [des: Item 397 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_12_14;                   /* <14> [dv:         na] [des: Item 398 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_12_15;                   /* <15> [dv:         na] [des: Item 399 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_12_16;                   /* <16> [dv:         na] [des: Item 400 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_12_17;                   /* <17> [dv:         na] [des: Item 401 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_12_18;                   /* <18> [dv:         na] [des: Item 402 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_12_19;                   /* <19> [dv:         na] [des: Item 403 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_12_20;                   /* <20> [dv:         na] [des: Item 404 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_12_21;                   /* <21> [dv:         na] [des: Item 405 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_12_22;                   /* <22> [dv:         na] [des: Item 406 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_12_23;                   /* <23> [dv:         na] [des: Item 407 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_12_24;                   /* <24> [dv:         na] [des: Item 408 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_12_25;                   /* <25> [dv:         na] [des: Item 409 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_12_26;                   /* <26> [dv:         na] [des: Item 410 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_12_27;                   /* <27> [dv:         na] [des: Item 411 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_12_28;                   /* <28> [dv:         na] [des: Item 412 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_12_29;                   /* <29> [dv:         na] [des: Item 413 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_12_30;                   /* <30> [dv:         na] [des: Item 414 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_12_31;                   /* <31> [dv:         na] [des: Item 415 for Weighted Prediction/DistScaleFactor] */
    // GROUP 405 [weighted_prediction_distscalefactor_group_13]
    unsigned mr_wt_sram_base_13_0;                    /* < 0> [dv:         na] [des: Item 416 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_13_1;                    /* < 1> [dv:         na] [des: Item 417 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_13_2;                    /* < 2> [dv:         na] [des: Item 418 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_13_3;                    /* < 3> [dv:         na] [des: Item 419 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_13_4;                    /* < 4> [dv:         na] [des: Item 420 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_13_5;                    /* < 5> [dv:         na] [des: Item 421 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_13_6;                    /* < 6> [dv:         na] [des: Item 422 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_13_7;                    /* < 7> [dv:         na] [des: Item 423 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_13_8;                    /* < 8> [dv:         na] [des: Item 424 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_13_9;                    /* < 9> [dv:         na] [des: Item 425 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_13_10;                   /* <10> [dv:         na] [des: Item 426 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_13_11;                   /* <11> [dv:         na] [des: Item 427 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_13_12;                   /* <12> [dv:         na] [des: Item 428 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_13_13;                   /* <13> [dv:         na] [des: Item 429 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_13_14;                   /* <14> [dv:         na] [des: Item 430 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_13_15;                   /* <15> [dv:         na] [des: Item 431 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_13_16;                   /* <16> [dv:         na] [des: Item 432 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_13_17;                   /* <17> [dv:         na] [des: Item 433 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_13_18;                   /* <18> [dv:         na] [des: Item 434 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_13_19;                   /* <19> [dv:         na] [des: Item 435 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_13_20;                   /* <20> [dv:         na] [des: Item 436 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_13_21;                   /* <21> [dv:         na] [des: Item 437 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_13_22;                   /* <22> [dv:         na] [des: Item 438 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_13_23;                   /* <23> [dv:         na] [des: Item 439 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_13_24;                   /* <24> [dv:         na] [des: Item 440 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_13_25;                   /* <25> [dv:         na] [des: Item 441 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_13_26;                   /* <26> [dv:         na] [des: Item 442 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_13_27;                   /* <27> [dv:         na] [des: Item 443 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_13_28;                   /* <28> [dv:         na] [des: Item 444 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_13_29;                   /* <29> [dv:         na] [des: Item 445 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_13_30;                   /* <30> [dv:         na] [des: Item 446 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_13_31;                   /* <31> [dv:         na] [des: Item 447 for Weighted Prediction/DistScaleFactor] */
    // GROUP 406 [weighted_prediction_distscalefactor_group_14]
    unsigned mr_wt_sram_base_14_0;                    /* < 0> [dv:         na] [des: Item 448 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_14_1;                    /* < 1> [dv:         na] [des: Item 449 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_14_2;                    /* < 2> [dv:         na] [des: Item 450 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_14_3;                    /* < 3> [dv:         na] [des: Item 451 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_14_4;                    /* < 4> [dv:         na] [des: Item 452 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_14_5;                    /* < 5> [dv:         na] [des: Item 453 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_14_6;                    /* < 6> [dv:         na] [des: Item 454 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_14_7;                    /* < 7> [dv:         na] [des: Item 455 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_14_8;                    /* < 8> [dv:         na] [des: Item 456 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_14_9;                    /* < 9> [dv:         na] [des: Item 457 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_14_10;                   /* <10> [dv:         na] [des: Item 458 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_14_11;                   /* <11> [dv:         na] [des: Item 459 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_14_12;                   /* <12> [dv:         na] [des: Item 460 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_14_13;                   /* <13> [dv:         na] [des: Item 461 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_14_14;                   /* <14> [dv:         na] [des: Item 462 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_14_15;                   /* <15> [dv:         na] [des: Item 463 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_14_16;                   /* <16> [dv:         na] [des: Item 464 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_14_17;                   /* <17> [dv:         na] [des: Item 465 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_14_18;                   /* <18> [dv:         na] [des: Item 466 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_14_19;                   /* <19> [dv:         na] [des: Item 467 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_14_20;                   /* <20> [dv:         na] [des: Item 468 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_14_21;                   /* <21> [dv:         na] [des: Item 469 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_14_22;                   /* <22> [dv:         na] [des: Item 470 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_14_23;                   /* <23> [dv:         na] [des: Item 471 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_14_24;                   /* <24> [dv:         na] [des: Item 472 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_14_25;                   /* <25> [dv:         na] [des: Item 473 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_14_26;                   /* <26> [dv:         na] [des: Item 474 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_14_27;                   /* <27> [dv:         na] [des: Item 475 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_14_28;                   /* <28> [dv:         na] [des: Item 476 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_14_29;                   /* <29> [dv:         na] [des: Item 477 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_14_30;                   /* <30> [dv:         na] [des: Item 478 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_14_31;                   /* <31> [dv:         na] [des: Item 479 for Weighted Prediction/DistScaleFactor] */
    // GROUP 407 [weighted_prediction_distscalefactor_group_15]
    unsigned mr_wt_sram_base_15_0;                    /* < 0> [dv:         na] [des: Item 480 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_15_1;                    /* < 1> [dv:         na] [des: Item 481 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_15_2;                    /* < 2> [dv:         na] [des: Item 482 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_15_3;                    /* < 3> [dv:         na] [des: Item 483 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_15_4;                    /* < 4> [dv:         na] [des: Item 484 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_15_5;                    /* < 5> [dv:         na] [des: Item 485 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_15_6;                    /* < 6> [dv:         na] [des: Item 486 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_15_7;                    /* < 7> [dv:         na] [des: Item 487 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_15_8;                    /* < 8> [dv:         na] [des: Item 488 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_15_9;                    /* < 9> [dv:         na] [des: Item 489 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_15_10;                   /* <10> [dv:         na] [des: Item 490 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_15_11;                   /* <11> [dv:         na] [des: Item 491 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_15_12;                   /* <12> [dv:         na] [des: Item 492 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_15_13;                   /* <13> [dv:         na] [des: Item 493 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_15_14;                   /* <14> [dv:         na] [des: Item 494 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_15_15;                   /* <15> [dv:         na] [des: Item 495 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_15_16;                   /* <16> [dv:         na] [des: Item 496 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_15_17;                   /* <17> [dv:         na] [des: Item 497 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_15_18;                   /* <18> [dv:         na] [des: Item 498 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_15_19;                   /* <19> [dv:         na] [des: Item 499 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_15_20;                   /* <20> [dv:         na] [des: Item 500 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_15_21;                   /* <21> [dv:         na] [des: Item 501 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_15_22;                   /* <22> [dv:         na] [des: Item 502 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_15_23;                   /* <23> [dv:         na] [des: Item 503 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_15_24;                   /* <24> [dv:         na] [des: Item 504 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_15_25;                   /* <25> [dv:         na] [des: Item 505 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_15_26;                   /* <26> [dv:         na] [des: Item 506 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_15_27;                   /* <27> [dv:         na] [des: Item 507 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_15_28;                   /* <28> [dv:         na] [des: Item 508 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_15_29;                   /* <29> [dv:         na] [des: Item 509 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_15_30;                   /* <30> [dv:         na] [des: Item 510 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_15_31;                   /* <31> [dv:         na] [des: Item 511 for Weighted Prediction/DistScaleFactor] */
    // GROUP 408 [weighted_prediction_distscalefactor_group_16]
    unsigned mr_wt_sram_base_16_0;                    /* < 0> [dv:         na] [des: Item 512 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_16_1;                    /* < 1> [dv:         na] [des: Item 513 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_16_2;                    /* < 2> [dv:         na] [des: Item 514 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_16_3;                    /* < 3> [dv:         na] [des: Item 515 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_16_4;                    /* < 4> [dv:         na] [des: Item 516 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_16_5;                    /* < 5> [dv:         na] [des: Item 517 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_16_6;                    /* < 6> [dv:         na] [des: Item 518 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_16_7;                    /* < 7> [dv:         na] [des: Item 519 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_16_8;                    /* < 8> [dv:         na] [des: Item 520 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_16_9;                    /* < 9> [dv:         na] [des: Item 521 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_16_10;                   /* <10> [dv:         na] [des: Item 522 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_16_11;                   /* <11> [dv:         na] [des: Item 523 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_16_12;                   /* <12> [dv:         na] [des: Item 524 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_16_13;                   /* <13> [dv:         na] [des: Item 525 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_16_14;                   /* <14> [dv:         na] [des: Item 526 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_16_15;                   /* <15> [dv:         na] [des: Item 527 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_16_16;                   /* <16> [dv:         na] [des: Item 528 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_16_17;                   /* <17> [dv:         na] [des: Item 529 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_16_18;                   /* <18> [dv:         na] [des: Item 530 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_16_19;                   /* <19> [dv:         na] [des: Item 531 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_16_20;                   /* <20> [dv:         na] [des: Item 532 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_16_21;                   /* <21> [dv:         na] [des: Item 533 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_16_22;                   /* <22> [dv:         na] [des: Item 534 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_16_23;                   /* <23> [dv:         na] [des: Item 535 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_16_24;                   /* <24> [dv:         na] [des: Item 536 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_16_25;                   /* <25> [dv:         na] [des: Item 537 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_16_26;                   /* <26> [dv:         na] [des: Item 538 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_16_27;                   /* <27> [dv:         na] [des: Item 539 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_16_28;                   /* <28> [dv:         na] [des: Item 540 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_16_29;                   /* <29> [dv:         na] [des: Item 541 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_16_30;                   /* <30> [dv:         na] [des: Item 542 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_16_31;                   /* <31> [dv:         na] [des: Item 543 for Weighted Prediction/DistScaleFactor] */
    // GROUP 409 [weighted_prediction_distscalefactor_group_17]
    unsigned mr_wt_sram_base_17_0;                    /* < 0> [dv:         na] [des: Item 544 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_17_1;                    /* < 1> [dv:         na] [des: Item 545 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_17_2;                    /* < 2> [dv:         na] [des: Item 546 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_17_3;                    /* < 3> [dv:         na] [des: Item 547 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_17_4;                    /* < 4> [dv:         na] [des: Item 548 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_17_5;                    /* < 5> [dv:         na] [des: Item 549 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_17_6;                    /* < 6> [dv:         na] [des: Item 550 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_17_7;                    /* < 7> [dv:         na] [des: Item 551 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_17_8;                    /* < 8> [dv:         na] [des: Item 552 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_17_9;                    /* < 9> [dv:         na] [des: Item 553 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_17_10;                   /* <10> [dv:         na] [des: Item 554 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_17_11;                   /* <11> [dv:         na] [des: Item 555 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_17_12;                   /* <12> [dv:         na] [des: Item 556 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_17_13;                   /* <13> [dv:         na] [des: Item 557 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_17_14;                   /* <14> [dv:         na] [des: Item 558 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_17_15;                   /* <15> [dv:         na] [des: Item 559 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_17_16;                   /* <16> [dv:         na] [des: Item 560 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_17_17;                   /* <17> [dv:         na] [des: Item 561 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_17_18;                   /* <18> [dv:         na] [des: Item 562 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_17_19;                   /* <19> [dv:         na] [des: Item 563 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_17_20;                   /* <20> [dv:         na] [des: Item 564 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_17_21;                   /* <21> [dv:         na] [des: Item 565 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_17_22;                   /* <22> [dv:         na] [des: Item 566 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_17_23;                   /* <23> [dv:         na] [des: Item 567 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_17_24;                   /* <24> [dv:         na] [des: Item 568 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_17_25;                   /* <25> [dv:         na] [des: Item 569 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_17_26;                   /* <26> [dv:         na] [des: Item 570 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_17_27;                   /* <27> [dv:         na] [des: Item 571 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_17_28;                   /* <28> [dv:         na] [des: Item 572 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_17_29;                   /* <29> [dv:         na] [des: Item 573 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_17_30;                   /* <30> [dv:         na] [des: Item 574 for Weighted Prediction/DistScaleFactor] */
    unsigned mr_wt_sram_base_17_31;                   /* <31> [dv:         na] [des: Item 575 for Weighted Prediction/DistScaleFactor] */
    // GROUP 410 [reserved]
    unsigned grp410_reserved_0;                       /* < 0> */
    unsigned grp410_reserved_1;                       /* < 1> */
    unsigned grp410_reserved_2;                       /* < 2> */
    unsigned grp410_reserved_3;                       /* < 3> */
    unsigned grp410_reserved_4;                       /* < 4> */
    unsigned grp410_reserved_5;                       /* < 5> */
    unsigned grp410_reserved_6;                       /* < 6> */
    unsigned grp410_reserved_7;                       /* < 7> */
    unsigned grp410_reserved_8;                       /* < 8> */
    unsigned grp410_reserved_9;                       /* < 9> */
    unsigned grp410_reserved_10;                      /* <10> */
    unsigned grp410_reserved_11;                      /* <11> */
    unsigned grp410_reserved_12;                      /* <12> */
    unsigned grp410_reserved_13;                      /* <13> */
    unsigned grp410_reserved_14;                      /* <14> */
    unsigned grp410_reserved_15;                      /* <15> */
    unsigned grp410_reserved_16;                      /* <16> */
    unsigned grp410_reserved_17;                      /* <17> */
    unsigned grp410_reserved_18;                      /* <18> */
    unsigned grp410_reserved_19;                      /* <19> */
    unsigned grp410_reserved_20;                      /* <20> */
    unsigned grp410_reserved_21;                      /* <21> */
    unsigned grp410_reserved_22;                      /* <22> */
    unsigned grp410_reserved_23;                      /* <23> */
    unsigned grp410_reserved_24;                      /* <24> */
    unsigned grp410_reserved_25;                      /* <25> */
    unsigned grp410_reserved_26;                      /* <26> */
    unsigned grp410_reserved_27;                      /* <27> */
    unsigned grp410_reserved_28;                      /* <28> */
    unsigned grp410_reserved_29;                      /* <29> */
    unsigned grp410_reserved_30;                      /* <30> */
    unsigned grp410_reserved_31;                      /* <31> */
    // GROUP 411 [reserved]
    unsigned grp411_reserved_0;                       /* < 0> */
    unsigned grp411_reserved_1;                       /* < 1> */
    unsigned grp411_reserved_2;                       /* < 2> */
    unsigned grp411_reserved_3;                       /* < 3> */
    unsigned grp411_reserved_4;                       /* < 4> */
    unsigned grp411_reserved_5;                       /* < 5> */
    unsigned grp411_reserved_6;                       /* < 6> */
    unsigned grp411_reserved_7;                       /* < 7> */
    unsigned grp411_reserved_8;                       /* < 8> */
    unsigned grp411_reserved_9;                       /* < 9> */
    unsigned grp411_reserved_10;                      /* <10> */
    unsigned grp411_reserved_11;                      /* <11> */
    unsigned grp411_reserved_12;                      /* <12> */
    unsigned grp411_reserved_13;                      /* <13> */
    unsigned grp411_reserved_14;                      /* <14> */
    unsigned grp411_reserved_15;                      /* <15> */
    unsigned grp411_reserved_16;                      /* <16> */
    unsigned grp411_reserved_17;                      /* <17> */
    unsigned grp411_reserved_18;                      /* <18> */
    unsigned grp411_reserved_19;                      /* <19> */
    unsigned grp411_reserved_20;                      /* <20> */
    unsigned grp411_reserved_21;                      /* <21> */
    unsigned grp411_reserved_22;                      /* <22> */
    unsigned grp411_reserved_23;                      /* <23> */
    unsigned grp411_reserved_24;                      /* <24> */
    unsigned grp411_reserved_25;                      /* <25> */
    unsigned grp411_reserved_26;                      /* <26> */
    unsigned grp411_reserved_27;                      /* <27> */
    unsigned grp411_reserved_28;                      /* <28> */
    unsigned grp411_reserved_29;                      /* <29> */
    unsigned grp411_reserved_30;                      /* <30> */
    unsigned grp411_reserved_31;                      /* <31> */
    // GROUP 412 [reserved]
    unsigned grp412_reserved_0;                       /* < 0> */
    unsigned grp412_reserved_1;                       /* < 1> */
    unsigned grp412_reserved_2;                       /* < 2> */
    unsigned grp412_reserved_3;                       /* < 3> */
    unsigned grp412_reserved_4;                       /* < 4> */
    unsigned grp412_reserved_5;                       /* < 5> */
    unsigned grp412_reserved_6;                       /* < 6> */
    unsigned grp412_reserved_7;                       /* < 7> */
    unsigned grp412_reserved_8;                       /* < 8> */
    unsigned grp412_reserved_9;                       /* < 9> */
    unsigned grp412_reserved_10;                      /* <10> */
    unsigned grp412_reserved_11;                      /* <11> */
    unsigned grp412_reserved_12;                      /* <12> */
    unsigned grp412_reserved_13;                      /* <13> */
    unsigned grp412_reserved_14;                      /* <14> */
    unsigned grp412_reserved_15;                      /* <15> */
    unsigned grp412_reserved_16;                      /* <16> */
    unsigned grp412_reserved_17;                      /* <17> */
    unsigned grp412_reserved_18;                      /* <18> */
    unsigned grp412_reserved_19;                      /* <19> */
    unsigned grp412_reserved_20;                      /* <20> */
    unsigned grp412_reserved_21;                      /* <21> */
    unsigned grp412_reserved_22;                      /* <22> */
    unsigned grp412_reserved_23;                      /* <23> */
    unsigned grp412_reserved_24;                      /* <24> */
    unsigned grp412_reserved_25;                      /* <25> */
    unsigned grp412_reserved_26;                      /* <26> */
    unsigned grp412_reserved_27;                      /* <27> */
    unsigned grp412_reserved_28;                      /* <28> */
    unsigned grp412_reserved_29;                      /* <29> */
    unsigned grp412_reserved_30;                      /* <30> */
    unsigned grp412_reserved_31;                      /* <31> */
    // GROUP 413 [reserved]
    unsigned grp413_reserved_0;                       /* < 0> */
    unsigned grp413_reserved_1;                       /* < 1> */
    unsigned grp413_reserved_2;                       /* < 2> */
    unsigned grp413_reserved_3;                       /* < 3> */
    unsigned grp413_reserved_4;                       /* < 4> */
    unsigned grp413_reserved_5;                       /* < 5> */
    unsigned grp413_reserved_6;                       /* < 6> */
    unsigned grp413_reserved_7;                       /* < 7> */
    unsigned grp413_reserved_8;                       /* < 8> */
    unsigned grp413_reserved_9;                       /* < 9> */
    unsigned grp413_reserved_10;                      /* <10> */
    unsigned grp413_reserved_11;                      /* <11> */
    unsigned grp413_reserved_12;                      /* <12> */
    unsigned grp413_reserved_13;                      /* <13> */
    unsigned grp413_reserved_14;                      /* <14> */
    unsigned grp413_reserved_15;                      /* <15> */
    unsigned grp413_reserved_16;                      /* <16> */
    unsigned grp413_reserved_17;                      /* <17> */
    unsigned grp413_reserved_18;                      /* <18> */
    unsigned grp413_reserved_19;                      /* <19> */
    unsigned grp413_reserved_20;                      /* <20> */
    unsigned grp413_reserved_21;                      /* <21> */
    unsigned grp413_reserved_22;                      /* <22> */
    unsigned grp413_reserved_23;                      /* <23> */
    unsigned grp413_reserved_24;                      /* <24> */
    unsigned grp413_reserved_25;                      /* <25> */
    unsigned grp413_reserved_26;                      /* <26> */
    unsigned grp413_reserved_27;                      /* <27> */
    unsigned grp413_reserved_28;                      /* <28> */
    unsigned grp413_reserved_29;                      /* <29> */
    unsigned grp413_reserved_30;                      /* <30> */
    unsigned grp413_reserved_31;                      /* <31> */
    // GROUP 414 [reserved]
    unsigned grp414_reserved_0;                       /* < 0> */
    unsigned grp414_reserved_1;                       /* < 1> */
    unsigned grp414_reserved_2;                       /* < 2> */
    unsigned grp414_reserved_3;                       /* < 3> */
    unsigned grp414_reserved_4;                       /* < 4> */
    unsigned grp414_reserved_5;                       /* < 5> */
    unsigned grp414_reserved_6;                       /* < 6> */
    unsigned grp414_reserved_7;                       /* < 7> */
    unsigned grp414_reserved_8;                       /* < 8> */
    unsigned grp414_reserved_9;                       /* < 9> */
    unsigned grp414_reserved_10;                      /* <10> */
    unsigned grp414_reserved_11;                      /* <11> */
    unsigned grp414_reserved_12;                      /* <12> */
    unsigned grp414_reserved_13;                      /* <13> */
    unsigned grp414_reserved_14;                      /* <14> */
    unsigned grp414_reserved_15;                      /* <15> */
    unsigned grp414_reserved_16;                      /* <16> */
    unsigned grp414_reserved_17;                      /* <17> */
    unsigned grp414_reserved_18;                      /* <18> */
    unsigned grp414_reserved_19;                      /* <19> */
    unsigned grp414_reserved_20;                      /* <20> */
    unsigned grp414_reserved_21;                      /* <21> */
    unsigned grp414_reserved_22;                      /* <22> */
    unsigned grp414_reserved_23;                      /* <23> */
    unsigned grp414_reserved_24;                      /* <24> */
    unsigned grp414_reserved_25;                      /* <25> */
    unsigned grp414_reserved_26;                      /* <26> */
    unsigned grp414_reserved_27;                      /* <27> */
    unsigned grp414_reserved_28;                      /* <28> */
    unsigned grp414_reserved_29;                      /* <29> */
    unsigned grp414_reserved_30;                      /* <30> */
    unsigned grp414_reserved_31;                      /* <31> */
    // GROUP 415 [reserved]
    unsigned grp415_reserved_0;                       /* < 0> */
    unsigned grp415_reserved_1;                       /* < 1> */
    unsigned grp415_reserved_2;                       /* < 2> */
    unsigned grp415_reserved_3;                       /* < 3> */
    unsigned grp415_reserved_4;                       /* < 4> */
    unsigned grp415_reserved_5;                       /* < 5> */
    unsigned grp415_reserved_6;                       /* < 6> */
    unsigned grp415_reserved_7;                       /* < 7> */
    unsigned grp415_reserved_8;                       /* < 8> */
    unsigned grp415_reserved_9;                       /* < 9> */
    unsigned grp415_reserved_10;                      /* <10> */
    unsigned grp415_reserved_11;                      /* <11> */
    unsigned grp415_reserved_12;                      /* <12> */
    unsigned grp415_reserved_13;                      /* <13> */
    unsigned grp415_reserved_14;                      /* <14> */
    unsigned grp415_reserved_15;                      /* <15> */
    unsigned grp415_reserved_16;                      /* <16> */
    unsigned grp415_reserved_17;                      /* <17> */
    unsigned grp415_reserved_18;                      /* <18> */
    unsigned grp415_reserved_19;                      /* <19> */
    unsigned grp415_reserved_20;                      /* <20> */
    unsigned grp415_reserved_21;                      /* <21> */
    unsigned grp415_reserved_22;                      /* <22> */
    unsigned grp415_reserved_23;                      /* <23> */
    unsigned grp415_reserved_24;                      /* <24> */
    unsigned grp415_reserved_25;                      /* <25> */
    unsigned grp415_reserved_26;                      /* <26> */
    unsigned grp415_reserved_27;                      /* <27> */
    unsigned grp415_reserved_28;                      /* <28> */
    unsigned grp415_reserved_29;                      /* <29> */
    unsigned grp415_reserved_30;                      /* <30> */
    unsigned grp415_reserved_31;                      /* <31> */
    // GROUP 416 [h.264_global_related]
    unsigned mfd_slice_start;                         /* < 0> [dv:     0x0000] [des: MFD Start Slice] */
    unsigned h264_profile_control;                    /* < 1> [dv:     0x0000] [des: H.264 Profile Control] */
    unsigned hsize_mb;                                /* < 2> [dv:     0x0000] [des: H.264/H.265/AVS Picture Horizontal Size in MBs] */
    unsigned vsize_mb;                                /* < 3> [dv:     0x0000] [des: H.264/H.265/AVS Picture Vertical Size in MBs] */
    unsigned h264_chroma_qp_idx_offset;               /* < 4> [dv:     0x0000] [des: H.264/AVS+ Chroma QP Index Offset] */
    unsigned combo_signals;                           /* < 5> [dv:     0x0000] [des: H.264/H.265/AVS+ Combo Signals] */
    unsigned h264_field_pic_flag;                 /* < 6> [dv:     0x0000] [des: H.264/AVS Field Picture Flag; H.265 HSIZE MB REM] */
    unsigned h264_top_field_flag;                 /* < 7> [dv:     0x0000] [des: H.264/AVS Field Parity Flag; H.265 VSIZE MB REM] */
    unsigned h264_mbaff_flag;                         /* < 8> [dv:     0x0000] [des: H.264 Mbaff Frame Flag] */
    unsigned slice_type;                              /* < 9> [dv:     0x0000] [des: H.264/H.265/AVS Slice Type] */
    unsigned motion_vector_base;                      /* <10> [dv:     0x0000] [des: H.264/H.265/AVS Motion Vector Buffer Base] */
    unsigned frame_base;                              /* <11> [dv:     0x0000] [des: H.264/H.265/AVS Frame Buffer Base] */
    unsigned mfd_vlc_irq_reg;                         /* <12> [dv:     0x0000] [des: MFD MP Slice Done Interrupt Pending] */
    unsigned mfd_vlc_irq_mask;                        /* <13> [dv:     0x0000] [des: MFD MP Slice Done Interrupt Mask] */
    unsigned mfd_lf_irq;                           /* <14> [dv:     0x0000] [des: MFD LFBWR Done Interrupt Pending] */
    unsigned mfd_lf_irq_mask;                      /* <15> [dv:     0x0000] [des: MFD LFBWR Done Interrupt Mask] */
    unsigned grp416_reserved_0;                       /* <16> */
    unsigned mfd_soft_reset;                          /* <17> [dv:     0x0000] [des: MFD Soft Reset] */
    unsigned mfd_pic_start;                           /* <18> [dv: 0xdeadc0de] [des: MFD Picture Start] */
    unsigned mfd_status;                              /* <19> [dv:     0x0004] [des: MFD Hardware Status] */
    unsigned sbus_arbiter_reset;                      /* <20> [dv:     0x0000] [des: SBUS Arbiter Reset] */
    unsigned sbus_monitor_reset;                      /* <21> [dv:     0x0000] [des: SBUS Monitor Reset] */
    unsigned sbus_monitor_stall;                      /* <22> [dv:     0x0000] [des: SBUS Monitor Stall] */
    unsigned sbus_monitor_info;                       /* <23> [dv:     0x0000] [des: SBUS Monitor Information] */
    unsigned sbus_monitor_count;                      /* <24> [dv:     0x0000] [des: SBUS Monitor Counter] */
    unsigned sbus_monitor_count2;                     /* <25> [dv:     0x0000] [des: SBUS Monitor Counter 2] */
    unsigned slc_irq_pend;                            /* <26> [dv:     0x0000] [des: MFD LFBWR Slice Done Interrupt Pending] */
    unsigned slc_irq_mask;                            /* <27> [dv:     0x0000] [des: MFD LFBWR Slice Done Interrupt Mask] */
    unsigned grp416_reserved_1;                       /* <28> */
    unsigned grp416_reserved_2;                       /* <29> */
    unsigned grp416_reserved_3;                       /* <30> */
    unsigned grp416_reserved_4;                       /* <31> */
    // GROUP 417 [h.264_h.265_avs_mp_related_group_0]
    unsigned ref_pic_flag;                            /* < 0> [dv:     0x0000] [des: H.264/H.265/AVS Reference Picture Indicator] */
    unsigned entropy_coding_mode_flag;                /* < 1> [dv:     0x0000] [des: H.264/H.265 Entropy Coding Mode Flag] */
    unsigned first_mb_row;                            /* < 2> [dv:     0x0000] [des: H.264/H.265/AVS First MB Row Number for a Slice] */
    unsigned first_mb_col;                            /* < 3> [dv:     0x0000] [des: H.264/H.265/AVS First MB Column Number for a Slice] */
    unsigned h264_direct_spatial_mv_pred_flag;        /* < 4> [dv:     0x0000] [des: H.264 Direct Mode Type] */
    unsigned idx_l0_size;                             /* < 5> [dv:     0x0000] [des: H.264/H.265 Number of Reference Index in List 0] */
    unsigned idx_l1_size;                             /* < 6> [dv:     0x0000] [des: H.264/H.265 Number of Reference Index in List 1] */
    unsigned cabac_init_idc;                          /* < 7> [dv:     0x0000] [des: H.264/H.265 CABAC Context Model Indicator] */
    unsigned slice_init_qp;                           /* < 8> [dv:     0x0000] [des: H.264/H.265/AVS Slice Initial QP] */
    unsigned ref_pic0_type_l1;                        /* < 9> [dv:     0x0000] [des: H.264/H.265/AVS The first Ref Picture Information in List 1] */
    unsigned mfd_dec_mb_pos;                          /* <10> [dv:     0x0000] [des: MFD Current MB Address Parsed by MP] */
    unsigned mfd_mp_status;                           /* <11> [dv:     0x0000] [des: MFD MP Slice Decode Interrupt Status] */
    unsigned mfd_slice_dec_timer;                     /* <12> [dv:     0xffff] [des: MFD Slice Decoding Timer] */
    unsigned mfd_mp_error_check_mask;                 /* <13> [dv:     0x0000] [des: MFD MP Error Check Mask] */
    unsigned h265_luma_ctb_size;                      /* <14> [dv:     0x0000] [des: Luma CTB Size (H.265 Only)] */
    unsigned h265_transform_block_size;               /* <15> [dv:     0x0000] [des: Transform Block Size (H.265 Only)] */
    unsigned h265_max_transform_depth;                /* <16> [dv:     0x0000] [des: Max. Hierarchy Depth for TU (H.265 Only)] */
    unsigned h265_luma_pcm_ctb_size;                  /* <17> [dv:     0x0000] [des: Luma PCM CTB Size (H.265 Only)] */
    unsigned h265_chroma_qp_offset;                   /* <18> [dv:     0x0000] [des: Chroma QP Offset (H.265 Only)] */
    unsigned h265_tile_start_addr;                    /* <19> [dv:     0x0000] [des: Starting Address of Tile (H.265 Only)] */
    unsigned h265_tile_end_addr;                      /* <20> [dv:     0x0000] [des: Ending Address of Tile (H.265 Only)] */
    unsigned h265_mp_misc;                            /* <21> [dv:     0x0000] [des:  Misc. Setting for MP (H.265 Only)] */
    unsigned h265_slice_segment_addr;                 /* <22> [dv:     0x0000] [des: Slice Segment Address (H.265 Only)] */
    unsigned h265_coll_idx;                           /* <23> [dv:     0x0000] [des: Slice Segment Address (H.265 Only)] */
    unsigned h265_is_long_term;                       /* <24> [dv:     0x0000] [des: The Long Term Pictures exist in ListX (H.265 Only)] */
    unsigned h265_num_tile_size;                      /* <25> [dv:     0x0000] [des: The Number of Tile Rows/Columns Partitioning the Picture (H.265 Only)] */
    unsigned h265_cur_tile_idx;                       /* <26> [dv:     0x0000] [des: The Current Slice Segment Located in Which Tile is (H.265 Only)] */
    unsigned h265_pcm_bit_depth;                      /* <27> [dv:     0x0000] [des: The Number of Bits Used to Represent Each of PCM Sample (H.265 Only)] */
    unsigned h265_coll_long_term;                     /* <28> [dv:     0x0000] [des: The Long-Term Pictures Located in the DPB of the Collocated Picture (H.265 Only)] */
    unsigned grp417_reserved_0;                       /* <29> */
    unsigned grp417_reserved_1;                       /* <30> */
    unsigned grp417_reserved_2;                       /* <31> */
    // GROUP 418 [h.264_avs_mp_related_group_1]
    unsigned avs_next_first_mb_row;                   /* < 0> [dv:     0x0000] [des: AVS First MB Row Number for the Next Slice] */
    unsigned avs_next_first_mb_col;                   /* < 1> [dv:     0x0000] [des: AVS First MB Column Number for the Next Slice] */
    unsigned avs_skip_mode_flag;                      /* < 2> [dv:     0x0000] [des: AVS Skip Mode Syntax Flag] */
    unsigned avs_fix_qp_flag;                         /* < 3> [dv:     0x0000] [des: AVS Fixed QP Flag] */
    unsigned avs_slice_weighting_flag;                /* < 4> [dv:     0x0000] [des: AVS Slice Weighting Flag] */
    unsigned avs_mb_weighting_flag;                   /* < 5> [dv:     0x0000] [des: AVS MB-Level Weighting Flag] */
    unsigned avs_block_distance_0;                    /* < 6> [dv:     0x0000] [des: AVS Block Distance 0] */
    unsigned avs_block_distance_1;                    /* < 7> [dv:     0x0000] [des: AVS Block Distance 1] */
    unsigned avs_block_distance_2;                    /* < 8> [dv:     0x0000] [des: AVS Block Distance 2] */
    unsigned avs_block_distance_3;                    /* < 9> [dv:     0x0000] [des: AVS Block Distance 3] */
    unsigned grp418_reserved_0;                       /* <10> */
    unsigned grp418_reserved_1;                       /* <11> */
    unsigned grp418_reserved_2;                       /* <12> */
    unsigned grp418_reserved_3;                       /* <13> */
    unsigned grp418_reserved_4;                       /* <14> */
    unsigned grp418_reserved_5;                       /* <15> */
    unsigned grp418_reserved_6;                       /* <16> */
    unsigned grp418_reserved_7;                       /* <17> */
    unsigned grp418_reserved_8;                       /* <18> */
    unsigned grp418_reserved_9;                       /* <19> */
    unsigned grp418_reserved_10;                      /* <20> */
    unsigned grp418_reserved_11;                      /* <21> */
    unsigned grp418_reserved_12;                      /* <22> */
    unsigned grp418_reserved_13;                      /* <23> */
    unsigned grp418_reserved_14;                      /* <24> */
    unsigned grp418_reserved_15;                      /* <25> */
    unsigned grp418_reserved_16;                      /* <26> */
    unsigned grp418_reserved_17;                      /* <27> */
    unsigned grp418_reserved_18;                      /* <28> */
    unsigned grp418_reserved_19;                      /* <29> */
    unsigned grp418_reserved_20;                      /* <30> */
    unsigned grp418_reserved_21;                      /* <31> */
    // GROUP 419 [h264_h.265_mr]
    unsigned wpred_flag;                              /* < 0> [dv:     0x0000] [des: Weighted Prediction Flag (H.264/H.265)] */
    unsigned wpred_idc;                               /* < 1> [dv:     0x0000] [des: The Default/Explicit/Implicit Weighted Predction Indicator (H.264/H.265)] */
    unsigned luma_log2_wd;                            /* < 2> [dv:     0x0000] [des: The Denominator for All Luma Weighting Factors (H.264/H.265)] */
    unsigned chrma_log2_wd;                           /* < 3> [dv:     0x0000] [des: The Denominator for All Chroma Weighting Factors (H.264/H.265)] */
    unsigned luma_weight_l0_flag;                     /* < 4> [dv:     0x0000] [des: Weighting Factors for The Luma of List 0 Prediction (H.264/H.265)] */
    unsigned chroma_weight_l0_flag;                   /* < 5> [dv:     0x0000] [des: Weighting Factors for The Chroma of List 0 Prediction (H.264/H.265)] */
    unsigned luma_weight_l1_flag;                     /* < 6> [dv:     0x0000] [des: Weighting Factors for The Luma of List 1 Prediction (H.264/H.265)] */
    unsigned chroma_weight_l1_flag;                   /* < 7> [dv:     0x0000] [des: Weighting Factors for The Chroma of List 1 Prediction (H.264/H.265)] */
    unsigned h264_ddat_control;                       /* < 8> [dv:     0x0000] [des: DDAT Control (H.264 Only)] */
    unsigned h264_fmo_mr_slc_cnt;                     /* < 9> [dv:     0x0000] [des: MR Slice Counter (H.264 Only)] */
    unsigned mfd_reserved_0;                          /* <10> [dv:     0x0000] [des: MFD Reserved Register 0 (H.264 Only)] */
    unsigned mfd_reserved_1;                          /* <11> [dv:     0x0000] [des: MFD Reserved Register 1 (H.264 Only)] */
    unsigned grp419_reserved_0;                       /* <12> */
    unsigned grp419_reserved_1;                       /* <13> */
    unsigned grp419_reserved_2;                       /* <14> */
    unsigned grp419_reserved_3;                       /* <15> */
    unsigned grp419_reserved_4;                       /* <16> */
    unsigned grp419_reserved_5;                       /* <17> */
    unsigned grp419_reserved_6;                       /* <18> */
    unsigned grp419_reserved_7;                       /* <19> */
    unsigned grp419_reserved_8;                       /* <20> */
    unsigned grp419_reserved_9;                       /* <21> */
    unsigned grp419_reserved_10;                      /* <22> */
    unsigned grp419_reserved_11;                      /* <23> */
    unsigned grp419_reserved_12;                      /* <24> */
    unsigned grp419_reserved_13;                      /* <25> */
    unsigned grp419_reserved_14;                      /* <26> */
    unsigned grp419_reserved_15;                      /* <27> */
    unsigned grp419_reserved_16;                      /* <28> */
    unsigned grp419_reserved_17;                      /* <29> */
    unsigned grp419_reserved_18;                      /* <30> */
    unsigned grp419_reserved_19;                      /* <31> */
    // GROUP 420 [reserved]
    unsigned grp420_reserved_0;                       /* < 0> */
    unsigned grp420_reserved_1;                       /* < 1> */
    unsigned grp420_reserved_2;                       /* < 2> */
    unsigned grp420_reserved_3;                       /* < 3> */
    unsigned grp420_reserved_4;                       /* < 4> */
    unsigned grp420_reserved_5;                       /* < 5> */
    unsigned grp420_reserved_6;                       /* < 6> */
    unsigned grp420_reserved_7;                       /* < 7> */
    unsigned grp420_reserved_8;                       /* < 8> */
    unsigned grp420_reserved_9;                       /* < 9> */
    unsigned grp420_reserved_10;                      /* <10> */
    unsigned grp420_reserved_11;                      /* <11> */
    unsigned grp420_reserved_12;                      /* <12> */
    unsigned grp420_reserved_13;                      /* <13> */
    unsigned grp420_reserved_14;                      /* <14> */
    unsigned grp420_reserved_15;                      /* <15> */
    unsigned grp420_reserved_16;                      /* <16> */
    unsigned grp420_reserved_17;                      /* <17> */
    unsigned grp420_reserved_18;                      /* <18> */
    unsigned grp420_reserved_19;                      /* <19> */
    unsigned grp420_reserved_20;                      /* <20> */
    unsigned grp420_reserved_21;                      /* <21> */
    unsigned grp420_reserved_22;                      /* <22> */
    unsigned grp420_reserved_23;                      /* <23> */
    unsigned grp420_reserved_24;                      /* <24> */
    unsigned grp420_reserved_25;                      /* <25> */
    unsigned grp420_reserved_26;                      /* <26> */
    unsigned grp420_reserved_27;                      /* <27> */
    unsigned grp420_reserved_28;                      /* <28> */
    unsigned grp420_reserved_29;                      /* <29> */
    unsigned grp420_reserved_30;                      /* <30> */
    unsigned grp420_reserved_31;                      /* <31> */
    // GROUP 421 [reserved]
    unsigned grp421_reserved_0;                       /* < 0> */
    unsigned grp421_reserved_1;                       /* < 1> */
    unsigned grp421_reserved_2;                       /* < 2> */
    unsigned grp421_reserved_3;                       /* < 3> */
    unsigned grp421_reserved_4;                       /* < 4> */
    unsigned grp421_reserved_5;                       /* < 5> */
    unsigned grp421_reserved_6;                       /* < 6> */
    unsigned grp421_reserved_7;                       /* < 7> */
    unsigned grp421_reserved_8;                       /* < 8> */
    unsigned grp421_reserved_9;                       /* < 9> */
    unsigned grp421_reserved_10;                      /* <10> */
    unsigned grp421_reserved_11;                      /* <11> */
    unsigned grp421_reserved_12;                      /* <12> */
    unsigned grp421_reserved_13;                      /* <13> */
    unsigned grp421_reserved_14;                      /* <14> */
    unsigned grp421_reserved_15;                      /* <15> */
    unsigned grp421_reserved_16;                      /* <16> */
    unsigned grp421_reserved_17;                      /* <17> */
    unsigned grp421_reserved_18;                      /* <18> */
    unsigned grp421_reserved_19;                      /* <19> */
    unsigned grp421_reserved_20;                      /* <20> */
    unsigned grp421_reserved_21;                      /* <21> */
    unsigned grp421_reserved_22;                      /* <22> */
    unsigned grp421_reserved_23;                      /* <23> */
    unsigned grp421_reserved_24;                      /* <24> */
    unsigned grp421_reserved_25;                      /* <25> */
    unsigned grp421_reserved_26;                      /* <26> */
    unsigned grp421_reserved_27;                      /* <27> */
    unsigned grp421_reserved_28;                      /* <28> */
    unsigned grp421_reserved_29;                      /* <29> */
    unsigned grp421_reserved_30;                      /* <30> */
    unsigned grp421_reserved_31;                      /* <31> */
    // GROUP 422 [reserved]
    unsigned grp422_reserved_0;                       /* < 0> */
    unsigned grp422_reserved_1;                       /* < 1> */
    unsigned grp422_reserved_2;                       /* < 2> */
    unsigned grp422_reserved_3;                       /* < 3> */
    unsigned grp422_reserved_4;                       /* < 4> */
    unsigned grp422_reserved_5;                       /* < 5> */
    unsigned grp422_reserved_6;                       /* < 6> */
    unsigned grp422_reserved_7;                       /* < 7> */
    unsigned grp422_reserved_8;                       /* < 8> */
    unsigned grp422_reserved_9;                       /* < 9> */
    unsigned grp422_reserved_10;                      /* <10> */
    unsigned grp422_reserved_11;                      /* <11> */
    unsigned grp422_reserved_12;                      /* <12> */
    unsigned grp422_reserved_13;                      /* <13> */
    unsigned grp422_reserved_14;                      /* <14> */
    unsigned grp422_reserved_15;                      /* <15> */
    unsigned grp422_reserved_16;                      /* <16> */
    unsigned grp422_reserved_17;                      /* <17> */
    unsigned grp422_reserved_18;                      /* <18> */
    unsigned grp422_reserved_19;                      /* <19> */
    unsigned grp422_reserved_20;                      /* <20> */
    unsigned grp422_reserved_21;                      /* <21> */
    unsigned grp422_reserved_22;                      /* <22> */
    unsigned grp422_reserved_23;                      /* <23> */
    unsigned grp422_reserved_24;                      /* <24> */
    unsigned grp422_reserved_25;                      /* <25> */
    unsigned grp422_reserved_26;                      /* <26> */
    unsigned grp422_reserved_27;                      /* <27> */
    unsigned grp422_reserved_28;                      /* <28> */
    unsigned grp422_reserved_29;                      /* <29> */
    unsigned grp422_reserved_30;                      /* <30> */
    unsigned grp422_reserved_31;                      /* <31> */
    // GROUP 423 [reserved]
    unsigned grp423_reserved_0;                       /* < 0> */
    unsigned grp423_reserved_1;                       /* < 1> */
    unsigned grp423_reserved_2;                       /* < 2> */
    unsigned grp423_reserved_3;                       /* < 3> */
    unsigned grp423_reserved_4;                       /* < 4> */
    unsigned grp423_reserved_5;                       /* < 5> */
    unsigned grp423_reserved_6;                       /* < 6> */
    unsigned grp423_reserved_7;                       /* < 7> */
    unsigned grp423_reserved_8;                       /* < 8> */
    unsigned grp423_reserved_9;                       /* < 9> */
    unsigned grp423_reserved_10;                      /* <10> */
    unsigned grp423_reserved_11;                      /* <11> */
    unsigned grp423_reserved_12;                      /* <12> */
    unsigned grp423_reserved_13;                      /* <13> */
    unsigned grp423_reserved_14;                      /* <14> */
    unsigned grp423_reserved_15;                      /* <15> */
    unsigned grp423_reserved_16;                      /* <16> */
    unsigned grp423_reserved_17;                      /* <17> */
    unsigned grp423_reserved_18;                      /* <18> */
    unsigned grp423_reserved_19;                      /* <19> */
    unsigned grp423_reserved_20;                      /* <20> */
    unsigned grp423_reserved_21;                      /* <21> */
    unsigned grp423_reserved_22;                      /* <22> */
    unsigned grp423_reserved_23;                      /* <23> */
    unsigned grp423_reserved_24;                      /* <24> */
    unsigned grp423_reserved_25;                      /* <25> */
    unsigned grp423_reserved_26;                      /* <26> */
    unsigned grp423_reserved_27;                      /* <27> */
    unsigned grp423_reserved_28;                      /* <28> */
    unsigned grp423_reserved_29;                      /* <29> */
    unsigned grp423_reserved_30;                      /* <30> */
    unsigned grp423_reserved_31;                      /* <31> */
    // GROUP 424 [get_bit_for_dpfu1]
    unsigned dpfu1_get_bits[32];
    // GROUP 425 [show_bit_for_dpfu1]
    unsigned dpfu1_show_bits[32];
    // GROUP 426 [slice_parsing_group_0]
    unsigned spar_fw_slice_process;                   /* < 0> [dv:     0x0000] [des: Firmware Slice Processing Flag] */
    unsigned spar_fw_slice_parse;                     /* < 1> [dv:     0x0000] [des: Firmware Slice Parsing Flag] */
    unsigned spar_fw_slice_prog_reg;                  /* < 2> [dv:     0x0000] [des: Firmware Slice Registers Programming Flag] */
    unsigned spar_enhancement;                        /* < 3> [dv: 0xdeadc0de] [des: H.264/H.265 Slice Parsing Enhancement] */
    unsigned spar_explicit_weight_parser_enable;      /* < 4> [dv: 0xdeadc0de] [des: H.264/H.265 Explicit Weight Parser Enable] */
    unsigned spar_explicit_weight_parsing_end;        /* < 5> [dv:     0x0000] [des: H.264/H.265 End of Explicit Weight Parsing] */
    unsigned spar_profile;                            /* < 6> [dv: 0xdeadc0de] [des: Profile for H.264/H.265 Slice Parsing] */
    unsigned spar_slice_type;                         /* < 7> [dv: 0xdeadc0de] [des: Slice Type for H.264/H.265 Slice Parsing] */
    unsigned spar_l0_size;                            /* < 8> [dv: 0xdeadc0de] [des: Number of Reference Index in List 0 for H.264/H.265 Slice Parsing] */
    unsigned spar_l1_size;                            /* < 9> [dv: 0xdeadc0de] [des: Number of Reference Index in List 1 for H.264/H.265 Slice Parsing] */
    unsigned spar_weighted_pred_flag;                 /* <10> [dv: 0xdeadc0de] [des: Weighted Prediction Flag for H.264 Slice Parsing (H.264 Only)] */
    unsigned spar_weighted_bipred_idc;                /* <11> [dv: 0xdeadc0de] [des: B-Slice Weighted Prediction Indicator for H.264 Slice Parsing (H.264 Only)] */
    unsigned spar_luma_log2_wd;                       /* <12> [dv:     0x0000] [des: luma_log2_weight_denom Parsed by H.264/H.265 Explicit Weight Parser] */
    unsigned spar_chroma_log2_wd;                     /* <13> [dv:     0x0000] [des: chroma_log2_weight_denom Parsed by H.264/H.265 Explicit Weight Parser] */
    unsigned spar_wpred_defaultf;                     /* <14> [dv:     0x0000] [des: Default Luma Weight Parsed by H.264/H.265 Explicit Weight Parser for Weighted Prediction in List 0] */
    unsigned spar_wpred_defaultfc;                    /* <15> [dv:     0x0000] [des: Default Chroma Weight Parsed by H.264/H.265 Explicit Weight Parser for Weighted Prediction in List 0] */
    unsigned spar_wpred_defaultb;                     /* <16> [dv:     0x0000] [des: Default Luma Weight Parsed by H.264/H.265 Explicit Weight Parser for Weighted Prediction in List 1] */
    unsigned spar_wpred_defaultbc;                    /* <17> [dv:     0x0000] [des: Default Chroma Weight Parsed by H.264/H.265 Explicit Weight Parser for Weighted Prediction in List 1] */
    unsigned spar_use_spmp;                           /* <18> [dv:     0x0000] [des: Use Slice Parsing Micro Processor (SPMP) as Slice Interrupt Handler] */
    unsigned spar_spmp_base_size;                     /* <19> [dv:     0x0000] [des: SPMP Instructions Buffer Base] */
    unsigned spar_spmp_ctrl;                          /* <20> [dv:     0x0001] [des: SPMP Control] */
    unsigned spar_spmp_inst_addr_size;                       /* <21> */
    unsigned spar_spmp_fw_slice_count;                /* <22> [dv:     0x0000] [des: Firmware Parsed Slice Counter] */
    unsigned spar_spmp_hw_slice_count;                /* <23> [dv:     0x0000] [des: SPMP Handled Slice Counter] */
    unsigned spar_spmp_fw_wr_ptr;                     /* <24> [dv:     0x0000] [des: SPMP Instructions Buffer Write Pointer] */
    unsigned spar_spmp_hw_rd_ptr;                     /* <25> [dv:     0x0000] [des: SPMP Instructions Buffer Read Pointer] */
    unsigned spar_spmp_base_size_expwt;               /* <26> [dv:     0x0000] [des: SPMP Buffer Base for H.264/H.265 Slice Parsing] */
    unsigned spar_spmp_fw_wr_ptr_expwt;               /* <27> [dv:     0x0000] [des: SPMP Buffer Write Pointer for H.264/H.265 Slice Parsing] */
    unsigned spar_spmp_status;                        /* <28> [dv:     0x0000] [des: SPMP Processing Status] */
    unsigned spar_spmp_max_inst_num_minus1;           /* <29> [dv:     0x07FF] [des: Maximum Number of SPMP Instructions Minus 1 to be Decoded] */
    unsigned grp426_reserved_1;                       /* <30> */
    unsigned grp426_reserved_2;                       /* <31> */
    // GROUP 427 [slice_parsing_group_1]
    unsigned grp427_reserved_0;                       /* < 0> */
    unsigned grp427_reserved_1;                       /* < 1> */
    unsigned spar_bits_rd_ctrl;                       /* < 2> [dv:     0x0000] [des: Parsing Control for Exp-Golomb Codes] */
    unsigned spar_bits_rd_data;                       /* < 3> [dv:     0x0040] [des: Parsed Data for Exp-Golomb Codes] */
    unsigned grp427_reserved_2;                       /* < 4> */
    unsigned spar_mailbox;                            /* < 5> [dv:     0x0000] [des: Mailbox] */
    unsigned grp427_reserved_3;                       /* < 6> */
    unsigned grp427_reserved_4;                       /* < 7> */
    unsigned spar_soft_rst;                           /* < 8> [dv:     0x0000] [des: Software reset] */
    unsigned grp427_reserved_5;                       /* < 9> */
    unsigned grp427_reserved_6;                       /* <10> */
    unsigned grp427_reserved_7;                       /* <11> */
    unsigned grp427_reserved_8;                       /* <12> */
    unsigned grp427_reserved_9;                       /* <13> */
    unsigned grp427_reserved_10;                      /* <14> */
    unsigned grp427_reserved_11;                      /* <15> */
    unsigned grp427_reserved_12;                      /* <16> */
    unsigned grp427_reserved_13;                      /* <17> */
    unsigned grp427_reserved_14;                      /* <18> */
    unsigned grp427_reserved_15;                      /* <19> */
    unsigned grp427_reserved_16;                      /* <20> */
    unsigned grp427_reserved_17;                      /* <21> */
    unsigned grp427_reserved_18;                      /* <22> */
    unsigned grp427_reserved_19;                      /* <23> */
    unsigned grp427_reserved_20;                      /* <24> */
    unsigned grp427_reserved_21;                      /* <25> */
    unsigned grp427_reserved_22;                      /* <26> */
    unsigned grp427_reserved_23;                      /* <27> */
    unsigned grp427_reserved_24;                      /* <28> */
    unsigned grp427_reserved_25;                      /* <29> */
    unsigned grp427_reserved_26;                      /* <30> */
    unsigned grp427_reserved_27;                      /* <31> */
    // GROUP 428 [start_code_searcher_group_0]
    unsigned reserved_0_58;                           /* < 0> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_1_52;                           /* < 1> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_2_44;                           /* < 2> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_3_32;                           /* < 3> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_4_29;                           /* < 4> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_5_27;                           /* < 5> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_6_24;                           /* < 6> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_7_24;                           /* < 7> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_8_23;                           /* < 8> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_9_20;                           /* < 9> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_10_20;                          /* <10> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_11_13;                          /* <11> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_12_9;                           /* <12> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_13_9;                           /* <13> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_14_9;                           /* <14> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_15_8;                           /* <15> [dv:     0x0000] [des: Reserved] */
    unsigned scs_outbuf_wptr;                         /* <16> [dv:     0x0000] [des: Output Buffer Write Pointer] */
    unsigned reserved_16_3;                           /* <17> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_17_2;                           /* <18> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_18_2;                           /* <19> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_19_2;                           /* <20> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_20_2;                           /* <21> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_21_1;                           /* <22> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_22_1;                           /* <23> [dv:     0x0000] [des: Reserved] */
    unsigned scs_outbuf_rptr;                         /* <24> [dv:     0x0000] [des: Output Buffer Read Pointer] */
    unsigned reserved_23_1;                           /* <25> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_24;                             /* <26> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_25;                             /* <27> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_26;                             /* <28> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_27;                             /* <29> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_28;                             /* <30> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_29;                             /* <31> [dv:     0x0000] [des: Reserved] */
    // GROUP 429 [start_code_searcher_group_1]
    unsigned scs_outbuf_base_y;                       /* < 0> [dv:     0x0000] [des: Output Buffer Base Y] */
    unsigned scs_outbuf_size_y;                       /* < 1> [dv:     0x0000] [des: Output Buffer Size Y] */
    unsigned scs_desbuf_wptr;                         /* < 2> [dv:     0x0000] [des: Descriptor Buffer Write Pointer] */
    unsigned scs_desbuf_rptr;                         /* < 3> [dv:     0x0000] [des: Descriptor Buffer Read Pointer] */
    unsigned scs_desbuf_base_y;                       /* < 4> [dv:     0x0000] [des: Descriptor Buffer Base Y] */
    unsigned scs_desbuf_size;                         /* < 5> [dv:     0x0000] [des: Descriptor Buffer Size] */
    unsigned reserved_0_59;                           /* < 6> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_1_53;                           /* < 7> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_2_45;                           /* < 8> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_3_33;                           /* < 9> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_4_30;                           /* <10> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_5_28;                           /* <11> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_6_25;                           /* <12> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_7_25;                           /* <13> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_8_24;                           /* <14> [dv:     0x0000] [des: Reserved] */
    unsigned scs_outbuf_ctrl_stat;                    /* <15> [dv:     0x0000] [des: Output Buffer Control and Status] */
    unsigned scs_bsif_ctrl_stat;                      /* <16> [dv:     0x3000] [des: Bitstream Interface Control and Status] */
    unsigned scs_bsbuf_wptr;                          /* <17> [dv:     0x0000] [des: Bitstream Buffer Write Pointer] */
    unsigned scs_bsbuf_rptr;                          /* <18> [dv:     0x0000] [des: Bitstream Buffer Read Pointer] */
    unsigned scs_bsbuf_base_y;                        /* <19> [dv:     0x0000] [des: Bitstream Buffer Base Y] */
    unsigned scs_bsbuf_size_y;                        /* <20> [dv:     0x0000] [des: Bitstream Buffer Size Y] */
    unsigned scs_bsbuf_rptr_cont;                     /* <21> [dv:     0x0000] [des: Bitstream Buffer Read Pointer for continuous behavior] */
    unsigned scs_trailing_zero_count;                 /* <22> [dv:     0x0000] [des: Trailing zero count before start code] */
    unsigned reserved_9_21;                           /* <23> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_10_21;                          /* <24> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_11_14;                          /* <25> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_12_10;                          /* <26> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_13_10;                          /* <27> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_14_10;                          /* <28> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_15_9;                           /* <29> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_16_4;                           /* <30> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_17_3;                           /* <31> [dv:     0x0000] [des: Reserved] */
    // GROUP 430 [start_code_searcher_group_2]
    unsigned scs_ctrl;                                /* < 0> [dv:     0x0000] [des: Start Code Searcher Control] */
    unsigned scs_stat;                                /* < 1> [dv:     0x0004] [des: Start Code Searcher Status] */
    unsigned scs_last_bytes;                          /* < 2> [dv:     0x0000] [des: Last four bytes] */
    unsigned scs_last_bytes_cmp;                      /* < 3> [dv:     0x0000] [des: Last four bytes to be compared] */
    unsigned scs_pattern_0;                           /* < 4> [dv:     0x0000] [des: Pattern \#0] */
    unsigned scs_mask_0;                              /* < 5> [dv:     0x0000] [des: Mask \#0] */
    unsigned scs_pattern_1;                           /* < 6> [dv:     0x0000] [des: Pattern \#1] */
    unsigned scs_mask_1;                              /* < 7> [dv:     0x0000] [des: Mask \#1] */
    unsigned scs_pattern_2;                           /* < 8> [dv:     0x0000] [des: Pattern \#2] */
    unsigned scs_mask_2;                              /* < 9> [dv:     0x0000] [des: Mask \#2] */
    unsigned scs_pattern_3;                           /* <10> [dv:     0x0000] [des: Pattern \#3] */
    unsigned scs_mask_3;                              /* <11> [dv:     0x0000] [des: Mask \#3] */
    unsigned scs_chksum;                              /* <12> [dv:     0x0000] [des: Checksum] */
    unsigned scs_in_chksum;                           /* <13> [dv:     0x0000] [des: Bitstream Checksum] */
    unsigned scs_debug;                               /* <14> [dv: 0x00101090] [des: Debug register] */
    unsigned reserved_0_60;                           /* <15> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_1_54;                           /* <16> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_2_46;                           /* <17> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_3_34;                           /* <18> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_4_31;                           /* <19> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_5_29;                           /* <20> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_6_26;                           /* <21> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_7_26;                           /* <22> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_8_25;                           /* <23> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_9_22;                           /* <24> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_10_22;                          /* <25> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_11_15;                          /* <26> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_12_11;                          /* <27> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_13_11;                          /* <28> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_14_11;                          /* <29> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_15_10;                          /* <30> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_16_5;                           /* <31> [dv:     0x0000] [des: Reserved] */
    // GROUP 431 [reserved]
    unsigned grp431_reserved_0;                       /* < 0> */
    unsigned grp431_reserved_1;                       /* < 1> */
    unsigned grp431_reserved_2;                       /* < 2> */
    unsigned grp431_reserved_3;                       /* < 3> */
    unsigned grp431_reserved_4;                       /* < 4> */
    unsigned grp431_reserved_5;                       /* < 5> */
    unsigned grp431_reserved_6;                       /* < 6> */
    unsigned grp431_reserved_7;                       /* < 7> */
    unsigned grp431_reserved_8;                       /* < 8> */
    unsigned grp431_reserved_9;                       /* < 9> */
    unsigned grp431_reserved_10;                      /* <10> */
    unsigned grp431_reserved_11;                      /* <11> */
    unsigned grp431_reserved_12;                      /* <12> */
    unsigned grp431_reserved_13;                      /* <13> */
    unsigned grp431_reserved_14;                      /* <14> */
    unsigned grp431_reserved_15;                      /* <15> */
    unsigned grp431_reserved_16;                      /* <16> */
    unsigned grp431_reserved_17;                      /* <17> */
    unsigned grp431_reserved_18;                      /* <18> */
    unsigned grp431_reserved_19;                      /* <19> */
    unsigned grp431_reserved_20;                      /* <20> */
    unsigned grp431_reserved_21;                      /* <21> */
    unsigned grp431_reserved_22;                      /* <22> */
    unsigned grp431_reserved_23;                      /* <23> */
    unsigned grp431_reserved_24;                      /* <24> */
    unsigned grp431_reserved_25;                      /* <25> */
    unsigned grp431_reserved_26;                      /* <26> */
    unsigned grp431_reserved_27;                      /* <27> */
    unsigned grp431_reserved_28;                      /* <28> */
    unsigned grp431_reserved_29;                      /* <29> */
    unsigned grp431_reserved_30;                      /* <30> */
    unsigned grp431_reserved_31;                      /* <31> */
    // GROUP 432 [h.264_h.265_avs_lf]
    unsigned h264_lf_dis_idc;
    unsigned h264_lf_offa;
    unsigned h264_lf_offb;
    unsigned h264_lf_chr_pfetch;
    unsigned h264_lf_bwr_bypass;
    unsigned g432_reserved_0[27];
    // GROUP 433 [dpfu1]
    unsigned dpfu1_fw_pars_ctrl;                      /* < 0> [dv: 0xdeadc0de] [des: DPFU1 NALU Parsing Control] */
    unsigned dpfu1_sfpar_en;                          /* < 1> [dv:     0x0000] [des: DPFU1 NALU Fetch Enable] */
    unsigned dpfu1_r_addr;                            /* < 2> [dv:     0x0000] [des: DPFU1 NALU Start Address] */
    unsigned dpfu1_r_slice_sz;                        /* < 3> [dv:     0x0000] [des: DPFU1 NALU Size] */
    unsigned grp433_reserved_0;                       /* < 4> */
    unsigned dpfu1_w_addr;                            /* < 5> [dv: 0xffffffc0] [des: Updated DPFU1 NALU Start Address] */
    unsigned dpfu1_w_slice_sz;                        /* < 6> [dv:     0x0004] [des: Updated DPFU1 NALU Size] */
    unsigned grp433_reserved_1;                       /* < 7> */
    unsigned dpfu1_fw_status;                         /* < 8> [dv:     0x0000] [des: DPFU1 NALU Parser Status] */
    unsigned dpfu1_slice_bsize_base;                  /* < 9> [dv:     0x0000] [des: Buffer Base and Size for DPFU1 NALU Parser] */
    unsigned grp433_reserved_2;                       /* <10> */
    unsigned grp433_reserved_3;                       /* <11> */
    unsigned grp433_reserved_4;                       /* <12> */
    unsigned grp433_reserved_5;                       /* <13> */
    unsigned grp433_reserved_6;                       /* <14> */
    unsigned grp433_reserved_7;                       /* <15> */
    unsigned grp433_reserved_8;                       /* <16> */
    unsigned grp433_reserved_9;                       /* <17> */
    unsigned grp433_reserved_10;                      /* <18> */
    unsigned grp433_reserved_11;                      /* <19> */
    unsigned grp433_reserved_12;                      /* <20> */
    unsigned grp433_reserved_13;                      /* <21> */
    unsigned grp433_reserved_14;                      /* <22> */
    unsigned grp433_reserved_15;                      /* <23> */
    unsigned grp433_reserved_16;                      /* <24> */
    unsigned grp433_reserved_17;                      /* <25> */
    unsigned grp433_reserved_18;                      /* <26> */
    unsigned grp433_reserved_19;                      /* <27> */
    unsigned grp433_reserved_20;                      /* <28> */
    unsigned grp433_reserved_21;                      /* <29> */
    unsigned grp433_reserved_22;                      /* <30> */
    unsigned grp433_reserved_23;                      /* <31> */
    // GROUP 434 [dpfu2]
    unsigned dpfu2_hw_pars_ctrl;                      /* < 0> [dv: 0xdeadc0de] [des: DPFU2 NALU Parsing Control] */
    unsigned dpfu2_hdpar_en;                          /* < 1> [dv:     0x0000] [des: DPFU2 NALU Fetch Enable] */
    unsigned dpfu2_r_addr;                            /* < 2> [dv:     0x0000] [des: DPFU2 NALU Start Address] */
    unsigned dpfu2_r_slice_sz;                        /* < 3> [dv:     0x0000] [des: DPFU2 NALU Size] */
    unsigned grp434_reserved_0;                       /* < 4> */
    unsigned dpfu2_w_addr;                            /* < 5> [dv: 0xffffffc0] [des: Updated DPFU2 NALU Start Address] */
    unsigned dpfu2_w_slice_sz;                        /* < 6> [dv:     0x0004] [des: Updated DPFU2 NALU Size] */
    unsigned grp434_reserved_1;                       /* < 7> */
    unsigned dpfu2_hw_status;                         /* < 8> [dv:     0x0000] [des: DPFU2 NALU Parser Status] */
    unsigned dpfu2_hw_slc_bsize_base;                 /* < 9> [dv:     0x0000] [des: Buffer Base and Size for DPFU2 NALU Parser] */
    unsigned grp434_reserved_2;                       /* <10> */
    unsigned grp434_reserved_3;                       /* <11> */
    unsigned grp434_reserved_4;                       /* <12> */
    unsigned grp434_reserved_5;                       /* <13> */
    unsigned grp434_reserved_6;                       /* <14> */
    unsigned grp434_reserved_7;                       /* <15> */
    unsigned grp434_reserved_8;                       /* <16> */
    unsigned grp434_reserved_9;                       /* <17> */
    unsigned grp434_reserved_10;                      /* <18> */
    unsigned grp434_reserved_11;                      /* <19> */
    unsigned grp434_reserved_12;                      /* <20> */
    unsigned grp434_reserved_13;                      /* <21> */
    unsigned grp434_reserved_14;                      /* <22> */
    unsigned grp434_reserved_15;                      /* <23> */
    unsigned grp434_reserved_16;                      /* <24> */
    unsigned grp434_reserved_17;                      /* <25> */
    unsigned grp434_reserved_18;                      /* <26> */
    unsigned grp434_reserved_19;                      /* <27> */
    unsigned grp434_reserved_20;                      /* <28> */
    unsigned grp434_reserved_21;                      /* <29> */
    unsigned grp434_reserved_22;                      /* <30> */
    unsigned grp434_reserved_23;                      /* <31> */
    // GROUP 435 [vc-1_global_related]
    unsigned mfd_dec_format;                          /* < 0> [dv:     0x0000] [des: MFD Decode Format] */
    unsigned vc1_pic_type;                            /* < 1> [dv:     0x0000] [des: VC-1 Picture Type] */
    unsigned vc1_field_pic_flag;                      /* < 2> [dv:     0x0000] [des: VC-1 Field Picture Flag] */
    unsigned vc1_bottom_field;                        /* < 3> [dv:     0x0000] [des: VC-1 Bottom Field Flag] */
    unsigned vc1_bfraction_lh;                        /* < 4> [dv:     0x0000] [des: VC-1 B Picture Fraction] */
    unsigned vc1_interlace;                           /* < 5> [dv:     0x0000] [des: VC-1 Picture Format] */
    unsigned vc1_numref;                              /* < 6> [dv:     0x0000] [des: VC-1 Number of Reference Pictures] */
    unsigned vc1_pquant;                              /* < 7> [dv:     0x0000] [des: VC-1 Picture Level Quantizer] */
    unsigned mfd_qt9421_enhance;                      /* < 8> [dv:     0x0000] [des: VC-1 and MPEG-1/2/4 QT Acceleration Control] */
    unsigned vc1_hsize;                               /* < 9> [dv:     0x0000] [des: VC-1 Horizontal Picture Size in Pixels] */
    unsigned vc1_vsize;                               /* <10> [dv:     0x0000] [des: VC-1 Vertical Picture Size in Pixels] */
    unsigned grp435_reserved_0;                       /* <11> */
    unsigned vc1_bpbase;                              /* <12> [dv:     0x0000] [des: VC-1 Bitplane Buffer Base] */
    unsigned vc1_curbase;                             /* <13> [dv:     0x0000] [des: VC-1 Current Frame Buffer Base] */
    unsigned vc1_refbase;                             /* <14> [dv:     0x0000] [des: VC-1 Reference Frame Buffer Base] */
    unsigned vc1_curmvbase;                           /* <15> [dv:     0x0000] [des: VC-1 Current Motion Vector Buffer Base] */
    unsigned vc1_refmvbase;                           /* <16> [dv:     0x0000] [des: VC-1 Reference Motion Vector Buffer Base] */
    unsigned mfd_mr9421_split_req_size;               /* <17> [dv:     0x009C] [des: VC-1 and MPEG-1/2/4 MR Split Request Size] */
    unsigned mfd_mr_cache_ctrl;                       /* <18> [dv:     0x0001] [des: MFD MR Cache Control] */
    unsigned lf9421_base;                             /* <19> [dv:     0x0000] [des: VC-1 and MPEG-1/2/4 Current Frame Buffer Base for Loop Filter] */
    unsigned grp435_reserved_1;                       /* <20> */
    unsigned grp435_reserved_2;                       /* <21> */
    unsigned grp435_reserved_3;                       /* <22> */
    unsigned grp435_reserved_4;                       /* <23> */
    unsigned grp435_reserved_5;                       /* <24> */
    unsigned grp435_reserved_6;                       /* <25> */
    unsigned grp435_reserved_7;                       /* <26> */
    unsigned grp435_reserved_8;                       /* <27> */
    unsigned grp435_reserved_9;                       /* <28> */
    unsigned grp435_reserved_10;                      /* <29> */
    unsigned grp435_reserved_11;                      /* <30> */
    unsigned grp435_reserved_12;                      /* <31> */
    // GROUP 436 [vc-1_mp_related_group_0]
    unsigned vc1_fastuvmc;                            /* < 0> [dv:     0x0000] [des: VC-1 Fast Chroma Motion Compensation] */
    unsigned vc1_range_reduction;                     /* < 1> [dv:     0x0000] [des: VC-1 Range Reduction] */
    unsigned vc1_second_field;                        /* < 2> [dv:     0x0000] [des: VC-1 Second Field Flag] */
    unsigned vc1_mv_range;                            /* < 3> [dv:     0x0000] [des: VC-1 Motion Vector Range] */
    unsigned vc1_mv_scale;                            /* < 4> [dv:     0x0000] [des: VC-1 Direct Motion Vector Scaler] */
    unsigned vc1_fwd_ref_dist;                        /* < 5> [dv:     0x0000] [des: VC-1 Forward Reference Frame Distance] */
    unsigned vc1_bwd_ref_dist;                        /* < 6> [dv:     0x0000] [des: VC-1 Backward Reference Frame Distance] */
    unsigned vc1_ref_field;                           /* < 7> [dv:     0x0000] [des: VC-1 Reference Field Selection] */
    unsigned vc1_sync_marker;                         /* < 8> [dv:     0x0000] [des: VC-1 Synchronization Marker Flag] */
    unsigned vc1_acpred_bp;                           /* < 9> [dv:     0x0000] [des: VC-1 AC Prediction Bit-Plane] */
    unsigned vc1_fldtx_bp;                            /* <10> [dv:     0x0000] [des: VC-1 Field Transform Bit-Plane] */
    unsigned vc1_mvt_bp;                              /* <11> [dv:     0x0000] [des: VC-1 Motion Vector Type Bit-Plane] */
    unsigned vc1_fwdmb_bp;                            /* <12> [dv:     0x0000] [des: VC-1 Forward MB Bit-Plane] */
    unsigned vc1_quant_ctrl;                          /* <13> [dv:     0x0000] [des: VC-1 Quantization Control] */
    unsigned vc1_altquant;                            /* <14> [dv:     0x0000] [des: VC-1 Alternate Picture Level Quant] */
    unsigned vc1_mix_mv;                              /* <15> [dv:     0x0000] [des: VC-1 Mixed-MV] */
    unsigned vc1_dctab;                               /* <16> [dv:     0x0000] [des: VC-1 Intra Transform DC Table] */
    unsigned vc1_mvtab;                               /* <17> [dv:     0x0000] [des: VC-1 Motion Vector Table] */
    unsigned vc1_2mvbptab;                            /* <18> [dv:     0x0000] [des: VC-1 2-MV Block Pattern Table] */
    unsigned vc1_4mvbptab;                            /* <19> [dv:     0x0000] [des: VC-1 4-MV Block Pattern Table] */
    unsigned vc1_cbptab;                              /* <20> [dv:     0x0000] [des: VC-1 Coded Block Pattern Table] */
    unsigned vc1_actab;                               /* <21> [dv:     0x0000] [des: VC-1 Transform AC Coding Set Index] */
    unsigned vc1_actab_2;                             /* <22> [dv:     0x0000] [des: VC-1 Transform AC Table-2 Index] */
    unsigned vc1_ttmbf;                               /* <23> [dv:     0x0000] [des: VC-1 MB-Level Transform Type Flag] */
    unsigned vc1_ttfrm;                               /* <24> [dv:     0x0000] [des: VC-1 Frame-Level Transform Type] */
    unsigned vc1_first_row;                           /* <25> [dv:     0x0000] [des: VC-1 First MB Row Address of a Slice] */
    unsigned vc1_lastpic_skip;                        /* <26> [dv:     0x0000] [des: VC-1 Last Picture is Skipped] */
    unsigned grp436_reserved_0;                       /* <27> */
    unsigned grp436_reserved_1;                       /* <28> */
    unsigned grp436_reserved_2;                       /* <29> */
    unsigned grp436_reserved_3;                       /* <30> */
    unsigned grp436_reserved_4;                       /* <31> */
    // GROUP 437 [vc-1_mp_mpeg_vld_related_group_1]
    unsigned mfd_gmc_ipa;                             /* < 0> [dv:     0x0000] [des: GMC IPA] */
    unsigned mfd_gmc_ipb;                             /* < 1> [dv:     0x0000] [des: GMC IPB] */
    unsigned mfd_gmc_ipc;                             /* < 2> [dv:     0x0000] [des: GMC IPC] */
    unsigned mfd_gmc_ipd;                             /* < 3> [dv:     0x0000] [des: GMC IPD] */
    unsigned mfd_gmc_ipe;                             /* < 4> [dv:     0x0000] [des: GMC IPE] */
    unsigned mfd_gmc_ipf;                             /* < 5> [dv:     0x0000] [des: GMC IPF] */
    unsigned mfd_gmc_ipp;                             /* < 6> [dv:     0x0000] [des: GMC IPP] */
    unsigned mfd_gmc_ipc_chm;                         /* < 7> [dv:     0x0000] [des: GMC IPC Chroma] */
    unsigned mfd_gmc_ipf_chm;                         /* < 8> [dv:     0x0000] [des: GMC IPF Chroma] */
    unsigned mfd_gmc_idnw_pwr;                        /* < 9> [dv:     0x0000] [des: GMC IDNW PWR] */
    unsigned grp437_reserved_0;                       /* <10> */
    unsigned grp437_reserved_1;                       /* <11> */
    unsigned grp437_reserved_2;                       /* <12> */
    unsigned grp437_reserved_3;                       /* <13> */
    unsigned grp437_reserved_4;                       /* <14> */
    unsigned grp437_reserved_5;                       /* <15> */
    unsigned grp437_reserved_6;                       /* <16> */
    unsigned grp437_reserved_7;                       /* <17> */
    unsigned grp437_reserved_8;                       /* <18> */
    unsigned grp437_reserved_9;                       /* <19> */
    unsigned grp437_reserved_10;                      /* <20> */
    unsigned grp437_reserved_11;                      /* <21> */
    unsigned grp437_reserved_12;                      /* <22> */
    unsigned grp437_reserved_13;                      /* <23> */
    unsigned grp437_reserved_14;                      /* <24> */
    unsigned grp437_reserved_15;                      /* <25> */
    unsigned grp437_reserved_16;                      /* <26> */
    unsigned grp437_reserved_17;                      /* <27> */
    unsigned grp437_reserved_18;                      /* <28> */
    unsigned grp437_reserved_19;                      /* <29> */
    unsigned grp437_reserved_20;                      /* <30> */
    unsigned grp437_reserved_21;                      /* <31> */
    // GROUP 438 [vc1_mr]
    unsigned vc1_bicube;                              /* < 0> [dv:     0x0000] [des: Bi-cubic Filter Control for Motion Compensation Module] */
    unsigned vc1_rcntl;                               /* < 1> [dv:     0x0000] [des: Rounding Control for Motion Compensation Module] */
    unsigned vc1_intt;                                /* < 2> [dv:     0x0000] [des: Intensity Compensation Parameter for Reference Top Field] */
    unsigned vc1_intb;                                /* < 3> [dv:     0x0000] [des: Intensity Compensation Parameter for Reference Bottom Field] */
    unsigned vc1_profile;                             /* < 4> [dv:     0x0000] [des: Profile Indicator] */
    unsigned vc1_qpel;                                /* < 5> [dv:     0x0000] [des: Quarter Pixel Enable for Motion Compensation Module] */
    unsigned grp438_reserved_0;                       /* < 6> */
    unsigned grp438_reserved_1;                       /* < 7> */
    unsigned grp438_reserved_2;                       /* < 8> */
    unsigned grp438_reserved_3;                       /* < 9> */
    unsigned grp438_reserved_4;                       /* <10> */
    unsigned grp438_reserved_5;                       /* <11> */
    unsigned grp438_reserved_6;                       /* <12> */
    unsigned grp438_reserved_7;                       /* <13> */
    unsigned grp438_reserved_8;                       /* <14> */
    unsigned grp438_reserved_9;                       /* <15> */
    unsigned mfd_gmc_frac;                            /* <16> [dv:     0x0000] [des: GMC Calculation Precision] */
    unsigned mfd_gmcs;                                /* <17> [dv:     0x0000] [des: GMC Sprite Accuracy] */
    unsigned mfd_gmcxdx;                              /* <18> [dv:     0x0000] [des: GMC Parameter] */
    unsigned mfd_gmcxdy;                              /* <19> [dv:     0x0000] [des: GMC Parameter] */
    unsigned mfd_gmcydx;                              /* <20> [dv:     0x0000] [des: GMC Parameter] */
    unsigned mfd_gmcydy;                              /* <21> [dv:     0x0000] [des: GMC Parameter] */
    unsigned vc1_pre_intt;                            /* <22> [dv:     0x0000] [des: Intensity Compensation Parameter for Reference Top Field] */
    unsigned vc1_pre_intb;                            /* <23> [dv:     0x0000] [des: Intensity Compensation Parameter for Reference Bottom Field] */
    unsigned vc1_pre2_intt;                           /* <24> [dv:     0x0000] [des: Intensity Compensation Parameter for Reference Top Field] */
    unsigned vc1_pre2_intb;                           /* <25> [dv:     0x0000] [des: Intensity Compensation Parameter for Reference Bottom Field] */
    unsigned grp438_reserved_10;                      /* <26> */
    unsigned grp438_reserved_11;                      /* <27> */
    unsigned grp438_reserved_12;                      /* <28> */
    unsigned grp438_reserved_13;                      /* <29> */
    unsigned grp438_reserved_14;                      /* <30> */
    unsigned grp438_reserved_15;                      /* <31> */
    // GROUP 439 [vc1_mpeg_lf]
    unsigned vc1_mbase;                               /* < 0> [dv:     0x0000] [des: overlap transform most significant 2-bit line buffer base] */
    unsigned vc1_mvext;                               /* < 1> [dv:     0x0000] [des: motion vector extended range flag] */
    unsigned vc1_ovlp;                                /* < 2> [dv:     0x0000] [des: overlapped transform and loop filter flag] */
    unsigned vc1_skipbp;                              /* < 3> [dv:     0x0000] [des: SKIPMB bitplane/raw mode select flag] */
    unsigned vc1_dmbbp;                               /* < 4> [dv:     0x0000] [des: DIRECTMB bitplane/raw mode select flag] */
    unsigned vc1_mvmtab;                              /* < 5> [dv:     0x0000] [des: Macroblock Mode Table] */
    unsigned vc1_buf_ctrl;                            /* < 6> [dv:     0x0000] [des: Buffer control flag] */
    unsigned grp439_reserved_0;                       /* < 7> */
    unsigned grp439_reserved_1;                       /* < 8> */
    unsigned grp439_reserved_2;                       /* < 9> */
    unsigned grp439_reserved_3;                       /* <10> */
    unsigned grp439_reserved_4;                       /* <11> */
    unsigned grp439_reserved_5;                       /* <12> */
    unsigned grp439_reserved_6;                       /* <13> */
    unsigned grp439_reserved_7;                       /* <14> */
    unsigned grp439_reserved_8;                       /* <15> */
    unsigned grp439_reserved_9;                       /* <16> */
    unsigned grp439_reserved_10;                      /* <17> */
    unsigned grp439_reserved_11;                      /* <18> */
    unsigned grp439_reserved_12;                      /* <19> */
    unsigned grp439_reserved_13;                      /* <20> */
    unsigned grp439_reserved_14;                      /* <21> */
    unsigned grp439_reserved_15;                      /* <22> */
    unsigned grp439_reserved_16;                      /* <23> */
    unsigned grp439_reserved_17;                      /* <24> */
    unsigned grp439_reserved_18;                      /* <25> */
    unsigned grp439_reserved_19;                      /* <26> */
    unsigned grp439_reserved_20;                      /* <27> */
    unsigned grp439_reserved_21;                      /* <28> */
    unsigned grp439_reserved_22;                      /* <29> */
    unsigned grp439_reserved_23;                      /* <30> */
    unsigned grp439_reserved_24;                      /* <31> */
    // GROUP 440 [reserved]
    unsigned grp440_reserved_0;                       /* < 0> */
    unsigned grp440_reserved_1;                       /* < 1> */
    unsigned grp440_reserved_2;                       /* < 2> */
    unsigned grp440_reserved_3;                       /* < 3> */
    unsigned grp440_reserved_4;                       /* < 4> */
    unsigned grp440_reserved_5;                       /* < 5> */
    unsigned grp440_reserved_6;                       /* < 6> */
    unsigned grp440_reserved_7;                       /* < 7> */
    unsigned grp440_reserved_8;                       /* < 8> */
    unsigned grp440_reserved_9;                       /* < 9> */
    unsigned grp440_reserved_10;                      /* <10> */
    unsigned grp440_reserved_11;                      /* <11> */
    unsigned grp440_reserved_12;                      /* <12> */
    unsigned grp440_reserved_13;                      /* <13> */
    unsigned grp440_reserved_14;                      /* <14> */
    unsigned grp440_reserved_15;                      /* <15> */
    unsigned grp440_reserved_16;                      /* <16> */
    unsigned grp440_reserved_17;                      /* <17> */
    unsigned grp440_reserved_18;                      /* <18> */
    unsigned grp440_reserved_19;                      /* <19> */
    unsigned grp440_reserved_20;                      /* <20> */
    unsigned grp440_reserved_21;                      /* <21> */
    unsigned grp440_reserved_22;                      /* <22> */
    unsigned grp440_reserved_23;                      /* <23> */
    unsigned grp440_reserved_24;                      /* <24> */
    unsigned grp440_reserved_25;                      /* <25> */
    unsigned grp440_reserved_26;                      /* <26> */
    unsigned grp440_reserved_27;                      /* <27> */
    unsigned grp440_reserved_28;                      /* <28> */
    unsigned grp440_reserved_29;                      /* <29> */
    unsigned grp440_reserved_30;                      /* <30> */
    unsigned grp440_reserved_31;                      /* <31> */
    // GROUP 441 [mpeg_video_variable_length_decoder]
    unsigned vld_ctrl;                                /* < 0> [dv:     0x00c0] [des: VLD Control] */
    unsigned vld_status;                              /* < 1> [dv: 0x00000001] [des: VLD Status] */
    unsigned vld_decode_time;                         /* < 2> [dv:     0x0000] [des: VLD Decode Time] */
    unsigned vld_int_trb_trd;                         /* < 3> [dv:     0x0000] [des: Interlaced Direct Mode TRB/TRD Value] */
    unsigned vld_mon_0;                               /* < 4> [dv: 0x00008001] [des: VLD Moniter Register 0] */
    unsigned vld_mon_1;                               /* < 5> [dv: 0x00000101] [des: VLD Moniter Register 1] */
    unsigned vld_mon_2;                               /* < 6> [dv: 0x00000401] [des: VLD Moniter Register 2] */
    unsigned vld_mon_3;                               /* < 7> [dv:     0x0000] [des: VLD Moniter Register 3] */
    unsigned reserved_0_61;                           /* < 8> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_1_55;                           /* < 9> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_2_47;                           /* <10> [dv:     0x0000] [des: Reserved] */
    unsigned vld_part_decode_tl;                      /* <11> [dv:     0x0000] [des: VLD Partial Decode Top-Left Point] */
    unsigned vld_part_decode_br;                      /* <12> [dv:     0x0000] [des: VLD Partial Decode Bottom-Right Point] */
    unsigned vld_error_mb_threshold;                  /* <13> [dv:     0x0000] [des: Maximum Error MB Threshold] */
    unsigned vld_config;                              /* <14> [dv:     0x0000] [des: VLD Error Configuration] */
    unsigned vld_trb_trd;                             /* <15> [dv:     0x0000] [des: Non-interlaced Direct Mode TRB/TRD Value] */
    unsigned vld_trb_trd_ext;                         /* <16> [dv:     0x0000] [des: Non-interlaced Direct Mode TRB/TRD Value (Extension)] */
    unsigned vld_2trbp_2dp;                           /* <17> [dv:     0x0000] [des: Interlaced Direct Mode (2*TRB+1)/(2*TRD+1) Value] */
    unsigned vld_2trbm_2dm;                           /* <18> [dv:     0x0000] [des: Interlaced Direct Mode (2*TRB-1)/(2*TRD-1) Value] */
    unsigned vld_packet_header;                       /* <19> [dv:     0x0000] [des: MPEG-4 Resync Marker] */
    unsigned vld_vol_header;                          /* <20> [dv:     0x0000] [des: MPEG-4 VOL Layer Syntax] */
    unsigned vld_vop_header;                          /* <21> [dv:     0x0000] [des: MPEG-4 VOP Layer Syntax] */
    unsigned vld_mp4_misc;                            /* <22> [dv:     0x0000] [des: MPEG-4 Misc Value] */
    unsigned vld_mon_4;                               /* <23> [dv: 0x00000001] [des: VLD Moniter Register 4] */
    unsigned vld_mon_5;                               /* <24> [dv:     0x0000] [des: VLD Moniter Register 5] */
    unsigned vld_mon_6;                               /* <25> [dv:     0x0000] [des: VLD Moniter Register 6] */
    unsigned vld_mon_7;                               /* <26> [dv:     0x0000] [des: VLD Moniter Register 7] */
    unsigned vld_mon_8;                               /* <27> [dv:     0x0000] [des: VLD Moniter Register 8] */
    unsigned vld_mon_9;                               /* <28> [dv:     0x0000] [des: VLD Moniter Register 9] */
    unsigned vld_mon_10;                              /* <29> [dv:     0x0000] [des: VLD Moniter Register 10] */
    unsigned reserved_3_35;                           /* <30> [dv:     0x0000] [des: Reserved] */
    unsigned vld_gob_num;                             /* <31> [dv:     0x0000] [des: GOB number] */
    // GROUP 442 [get_bit_for_dpfu2]
    unsigned dpfu2_get_bits[32];
    // GROUP 443 [show_bit_for_dpfu2]
    unsigned dpfu2_show_bits_0;                       /* < 0> [dv:     0x0000] [des: Show 32 Bits] */
    unsigned dpfu2_show_bits_1;                       /* < 1> [dv:     0x0000] [des: Show 1 Bit] */
    unsigned dpfu2_show_bits_2;                       /* < 2> [dv:     0x0000] [des: Show 2 Bits] */
    unsigned dpfu2_show_bits_3;                       /* < 3> [dv:     0x0000] [des: Show 3 Bits] */
    unsigned dpfu2_show_bits_4;                       /* < 4> [dv:     0x0000] [des: Show 4 Bits] */
    unsigned dpfu2_show_bits_5;                       /* < 5> [dv:     0x0000] [des: Show 5 Bits] */
    unsigned dpfu2_show_bits_6;                       /* < 6> [dv:     0x0000] [des: Show 6 Bits] */
    unsigned dpfu2_show_bits_7;                       /* < 7> [dv:     0x0000] [des: Show 7 Bits] */
    unsigned dpfu2_show_bits_8;                       /* < 8> [dv:     0x0000] [des: Show 8 Bits] */
    unsigned dpfu2_show_bits_9;                       /* < 9> [dv:     0x0000] [des: Show 9 Bits] */
    unsigned dpfu2_show_bits_10;                      /* <10> [dv:     0x0000] [des: Show 10 Bits] */
    unsigned dpfu2_show_bits_11;                      /* <11> [dv:     0x0000] [des: Show 11 Bits] */
    unsigned dpfu2_show_bits_12;                      /* <12> [dv:     0x0000] [des: Show 12 Bits] */
    unsigned dpfu2_show_bits_13;                      /* <13> [dv:     0x0000] [des: Show 13 Bits] */
    unsigned dpfu2_show_bits_14;                      /* <14> [dv:     0x0000] [des: Show 14 Bits] */
    unsigned dpfu2_show_bits_15;                      /* <15> [dv:     0x0000] [des: Show 15 Bits] */
    unsigned dpfu2_show_bits_16;                      /* <16> [dv:     0x0000] [des: Show 16 Bits] */
    unsigned dpfu2_show_bits_17;                      /* <17> [dv:     0x0000] [des: Show 17 Bits] */
    unsigned dpfu2_show_bits_18;                      /* <18> [dv:     0x0000] [des: Show 18 Bits] */
    unsigned dpfu2_show_bits_19;                      /* <19> [dv:     0x0000] [des: Show 19 Bits] */
    unsigned dpfu2_show_bits_20;                      /* <20> [dv:     0x0000] [des: Show 20 Bits] */
    unsigned dpfu2_show_bits_21;                      /* <21> [dv:     0x0000] [des: Show 21 Bits] */
    unsigned dpfu2_show_bits_22;                      /* <22> [dv:     0x0000] [des: Show 22 Bits] */
    unsigned dpfu2_show_bits_23;                      /* <23> [dv:     0x0000] [des: Show 23 Bits] */
    unsigned dpfu2_show_bits_24;                      /* <24> [dv:     0x0000] [des: Show 24 Bits] */
    unsigned dpfu2_show_bits_25;                      /* <25> [dv:     0x0000] [des: Show 25 Bits] */
    unsigned dpfu2_show_bits_26;                      /* <26> [dv:     0x0000] [des: Show 26 Bits] */
    unsigned dpfu2_show_bits_27;                      /* <27> [dv:     0x0000] [des: Show 27 Bits] */
    unsigned dpfu2_show_bits_28;                      /* <28> [dv:     0x0000] [des: Show 28 Bits] */
    unsigned dpfu2_show_bits_29;                      /* <29> [dv:     0x0000] [des: Show 29 Bits] */
    unsigned dpfu2_show_bits_30;                      /* <30> [dv:     0x0000] [des: Show 30 Bits] */
    unsigned dpfu2_show_bits_31;                      /* <31> [dv:     0x0000] [des: Show 31 Bits] */
    // GROUP 444 [mpeg_video_inverse_quantization]
    unsigned invq_qmx_par;                            /* < 0> [dv:        n/a] [des: INVQ quantization matrix access register. Use this register to write to INVQ matrix content directly] */
    unsigned invq_mode;                               /* < 1> [dv:     0x0000] [des: INVQ operation mode] */
    unsigned invq_chksum;                             /* < 2> [dv:     0x0000] [des: INVQ check sum] */
    unsigned reserved_0_62;                           /* < 3> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_1_56;                           /* < 4> [dv:     0x0000] [des: Reserved] */
    unsigned invq_vol_header;                         /* < 5> [dv:     0x0000] [des: INVQ VOL header] */
    unsigned invq_qt_rf_ctrl;                         /* < 6> [dv:     0x0000] [des: QT RF Control] */
    unsigned reserved_2_48;                           /* < 7> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_3_36;                           /* < 8> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_4_32;                           /* < 9> [dv:     0x0000] [des: Reserved] */
    unsigned qt_mon_0;                                /* <10> [dv:     0x0201] [des: Debug Register] */
    unsigned qt_mon_1;                                /* <11> [dv:     0x0080] [des: Debug Register] */
    unsigned reserved_5_30;                           /* <12> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_6_27;                           /* <13> [dv:     0x0000] [des: Reserved] */
    unsigned qt_mon_4;                                /* <14> [dv:     0x0005] [des: Debug Register] */
    unsigned reserved_7_27;                           /* <15> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_8_26;                           /* <16> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_9_23;                           /* <17> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_10_23;                          /* <18> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_11_16;                          /* <19> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_12_12;                          /* <20> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_13_12;                          /* <21> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_14_12;                          /* <22> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_15_11;                          /* <23> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_16_6;                           /* <24> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_17_4;                           /* <25> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_18_3;                           /* <26> [dv:     0x0000] [des: Reserved] */
    unsigned invq_qt_turbo_mode_control;              /* <27> [dv:     0x0000] [des: QT turbo mode control register] */
    unsigned invq_vqd_chksum;                         /* <28> [dv:     0x0000] [des: VQD check sum] */
    unsigned invq_spare_1;                            /* <29> [dv:     0x0000] [des: INVQ SPARE REGISTER 1] */
    unsigned invq_spare_2;                            /* <30> [dv:     0x0000] [des: INVQ SPARE REGISTER 2] */
    unsigned reserved_19_3;                           /* <31> [dv:     0x0000] [des: Reserved] */
    // GROUP 445 [mc2sd_for_mpeg124_h.264_and_vc1]
    unsigned mc2sd_ctrl;                              /* < 0> [dv: 0x00000000] [des: MC2SD Control Register] */
    unsigned mc2sd_pic_size;                          /* < 1> [dv: 0x00000000] [des: MC2SD Picture Size] */
    unsigned mc2sd_base;                              /* < 2> [dv: 0x00000000] [des: MC2SD Base Index] */
    unsigned mc2sd_flt_hl_4p;                         /* < 3> [dv: 0x063a3a06] [des: MC2SD Horizontal Luma 4-tap filter coefficient] */
    unsigned mc2sd_flt_hc_4p;                         /* < 4> [dv: 0x13422efd] [des: MC2SD Horizontal Chroma 4-tap filter coefficient] */
    unsigned mc2sd_flt_vl_fm_2p;                      /* < 5> [dv: 0x00404000] [des: MC2SD Vertical Luma Frame mode 2-tap filter coefficient] */
    unsigned mc2sd_flt_vl_fm_4p;                      /* < 6> [dv: 0x033d3d03] [des: MC2SD Vertical Luma Frame mode 4-tap filter coefficient] */
    unsigned mc2sd_flt_vc_fm_2p;                      /* < 7> [dv: 0x00404000] [des: MC2SD Vertical Chroma Frame mode 2-tap filter coefficient] */
    unsigned mc2sd_flt_vc_fm_4p;                      /* < 8> [dv: 0x033d3d03] [des: MC2SD Vertical Chroma Frame mode 4-tap filter coefficient] */
    unsigned mc2sd_flt_vl_fd_2p;                      /* < 9> [dv: 0x00542c00] [des: MC2SD Vertical Luma Field mode 2-tap filter coefficien] */
    unsigned mc2sd_flt_vl_fd_3p;                      /* <10> [dv: 0x0a4b2b00] [des: MC2SD Vertical Luma Field mode 3-tap filter coefficient] */
    unsigned mc2sd_flt_vl_fd_4p;                      /* <11> [dv: 0x0d492cfe] [des: MC2SD Vertical Luma Field mode 4-tap filter coefficient] */
    unsigned mc2sd_flt_vc_fd_2p;                      /* <12> [dv: 0x00542c00] [des: MC2SD Vertical Chroma Field mode 2-tap filter coefficient] */
    unsigned mc2sd_flt_vc_fd_3p;                      /* <13> [dv: 0x0a4b2b00] [des: MC2SD Vertical Chroma Field mode 3-tap filter coefficient] */
    unsigned mc2sd_flt_vc_fd_4p;                      /* <14> [dv: 0x0d492cfe] [des: MC2SD Vertical Chroma Field mode 4-tap filter coefficient] */
    unsigned mc2sd_be_d_chksum;                       /* <15> [dv: 0x00000000] [des: MC2SD Back-end Data Checksum] */
    unsigned mc2sd_fe_d_chksum;                       /* <16> [dv: 0x00000000] [des: MC2SD Front-end Data Checksum] */
    unsigned mc2sd_be_c_chksum;                       /* <17> [dv: 0x00000000] [des: MC2SD Back-end Data Checksum] */
    unsigned mc2sd_pic_end;                           /* <18> [dv: 0x00000001] [des: MC2SD Picture End] */
    unsigned mc2sd_debug;                             /* <19> [dv: 0x00000a01] [des: MC2SD Debug Register] */
    unsigned mc2sd_xy_offset;                         /* <20> [dv: 0x00000000] [des: MC2SD x/y coordinates offset] */
    unsigned mc2sd_drop_filed;                        /* <21> [dv: 0x00000000] [des: MC2SD field drop] */
    unsigned reserved_0_63;                           /* <22> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_1_57;                           /* <23> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_2_49;                           /* <24> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_3_37;                           /* <25> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_4_33;                           /* <26> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_5_31;                           /* <27> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_6_28;                           /* <28> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_7_28;                           /* <29> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_8_27;                           /* <30> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_9_24;                           /* <31> [dv:     0x0000] [des: Reserved] */
    // GROUP 446 [mfd_address_generation_and_dram_controller_for_vld]
    unsigned reserved_0_64_;                           /* < 0> [dv:     0x0000] [des: Reserved] */
    unsigned agdc_vld_read_base_address;              /* < 1> [dv:     0x07D1] [des: VLD read command base address] */
    unsigned reserved_1_58;                           /* < 2> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_2_50;                           /* < 3> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_3_38;                           /* < 4> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_4_34;                           /* < 5> [dv:     0x0000] [des: Reserved] */
    unsigned agdc_vld_read_upper_bound;               /* < 6> [dv:     0x0002] [des: Upper bound of VLD read command address] */
    unsigned reserved_5_32;                           /* < 7> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_6_29;                           /* < 8> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_7_29;                           /* < 9> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_8_28;                           /* <10> [dv:     0x0000] [des: Reserved] */
    unsigned agdc_vld_read_stop_kbyte_offset;         /* <11> [dv:     0x0000] [des: VLD read command stop KByte offset address] */
    unsigned agdc_vld_read_offset;                    /* <12> [dv:        n/a] [des: VLD read command offset address] */
    unsigned agdc_vld_read_ini_kbyte_offset;          /* <13> [dv:     0x0000] [des: VLD read command initial KByte offset address] */
    unsigned agdc_vld_read_ini_word_offset;           /* <14> [dv:     0x0000] [des: VLD read command initial word offset address] */
    unsigned reserved_9_25;                           /* <15> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_10_24;                          /* <16> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_11_17;                          /* <17> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_12_13;                          /* <18> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_13_13;                          /* <19> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_14_13;                          /* <20> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_15_12;                          /* <21> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_16_7;                           /* <22> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_17_5;                           /* <23> [dv:     0x0000] [des: Reserved] */
    unsigned agdc_mvc_base_address;                   /* <24> [dv:     0x0000] [des: Base address of MVC read/write command address] */
    unsigned agdc_acdc_base_address;                  /* <25> [dv:     0x0000] [des: Base address of ACDC read/write command address] */
    unsigned agdc_extend_bits_offset;                 /* <26> [dv:     0x0000] [des: Extend bits of the register bus] */
    unsigned reserved_18_4;                           /* <27> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_19_4;                           /* <28> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_20_3;                           /* <29> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_21_2;                           /* <30> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_22_2;                           /* <31> [dv:     0x0000] [des: Reserved] */
    // GROUP 447 [mfd_buffer_control]
    unsigned mfd_bf_mb_99_mode;                       /* < 0> [dv:     0x0000] [des: MB 99 Mode] */
    unsigned mfd_bf_slow_dec_reset_en;                /* < 1> [dv: 0x00000001] [des: Slow Decode Reset] */
    unsigned mfd_bf_always_interlock_enable;          /* < 2> [dv:     0x0000] [des: Always Interlock Enable] */
    unsigned mfd_bf_slow_decode_en;                   /* < 3> [dv:     0x0000] [des: Slow Decode Enable] */
    unsigned mfd_bf_spare_0;                          /* < 4> [dv:     0x0000] [des: Buffer Control Spare Register 0] */
    unsigned mfd_bf_spare_1;                          /* < 5> [dv:     0x0000] [des: Buffer Control Spare Register 1] */
    unsigned mfd_bf_spare_2;                          /* < 6> [dv:     0x0000] [des: Buffer Control Spare Register 2] */
    unsigned mfd_bf_spare_3;                          /* < 7> [dv:     0x0000] [des: Buffer Control Spare Register 3] */
    unsigned mfd_bf_sloww_dec_sft_reset;              /* < 8> [dv:     0x0000] [des: Slow Decode Software Reset] */
    unsigned reserved_0_65;                           /* < 9> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_1_59;                           /* <10> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_2_51;                           /* <11> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_3_39;                           /* <12> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_4_35;                           /* <13> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_5_33;                           /* <14> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_6_30;                           /* <15> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_7_30;                           /* <16> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_8_29;                           /* <17> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_9_26;                           /* <18> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_10_25;                          /* <19> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_11_18;                          /* <20> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_12_14;                          /* <21> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_13_14;                          /* <22> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_14_14;                          /* <23> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_15_13;                          /* <24> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_16_8;                           /* <25> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_17_6;                           /* <26> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_18_5;                           /* <27> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_19_5;                           /* <28> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_20_4;                           /* <29> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_21_3;                           /* <30> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_22_3;                           /* <31> [dv:     0x0000] [des: Reserved] */
    // GROUP 448 [reserved]
    unsigned grp448_reserved_0;                       /* < 0> */
    unsigned grp448_reserved_1;                       /* < 1> */
    unsigned grp448_reserved_2;                       /* < 2> */
    unsigned grp448_reserved_3;                       /* < 3> */
    unsigned grp448_reserved_4;                       /* < 4> */
    unsigned grp448_reserved_5;                       /* < 5> */
    unsigned grp448_reserved_6;                       /* < 6> */
    unsigned grp448_reserved_7;                       /* < 7> */
    unsigned grp448_reserved_8;                       /* < 8> */
    unsigned grp448_reserved_9;                       /* < 9> */
    unsigned grp448_reserved_10;                      /* <10> */
    unsigned grp448_reserved_11;                      /* <11> */
    unsigned grp448_reserved_12;                      /* <12> */
    unsigned grp448_reserved_13;                      /* <13> */
    unsigned grp448_reserved_14;                      /* <14> */
    unsigned grp448_reserved_15;                      /* <15> */
    unsigned grp448_reserved_16;                      /* <16> */
    unsigned grp448_reserved_17;                      /* <17> */
    unsigned grp448_reserved_18;                      /* <18> */
    unsigned grp448_reserved_19;                      /* <19> */
    unsigned grp448_reserved_20;                      /* <20> */
    unsigned grp448_reserved_21;                      /* <21> */
    unsigned grp448_reserved_22;                      /* <22> */
    unsigned grp448_reserved_23;                      /* <23> */
    unsigned grp448_reserved_24;                      /* <24> */
    unsigned grp448_reserved_25;                      /* <25> */
    unsigned grp448_reserved_26;                      /* <26> */
    unsigned grp448_reserved_27;                      /* <27> */
    unsigned grp448_reserved_28;                      /* <28> */
    unsigned grp448_reserved_29;                      /* <29> */
    unsigned grp448_reserved_30;                      /* <30> */
    unsigned grp448_reserved_31;                      /* <31> */
    // GROUP 449 [reserved]
    unsigned grp449_reserved_0;                       /* < 0> */
    unsigned grp449_reserved_1;                       /* < 1> */
    unsigned grp449_reserved_2;                       /* < 2> */
    unsigned grp449_reserved_3;                       /* < 3> */
    unsigned grp449_reserved_4;                       /* < 4> */
    unsigned grp449_reserved_5;                       /* < 5> */
    unsigned grp449_reserved_6;                       /* < 6> */
    unsigned grp449_reserved_7;                       /* < 7> */
    unsigned grp449_reserved_8;                       /* < 8> */
    unsigned grp449_reserved_9;                       /* < 9> */
    unsigned grp449_reserved_10;                      /* <10> */
    unsigned grp449_reserved_11;                      /* <11> */
    unsigned grp449_reserved_12;                      /* <12> */
    unsigned grp449_reserved_13;                      /* <13> */
    unsigned grp449_reserved_14;                      /* <14> */
    unsigned grp449_reserved_15;                      /* <15> */
    unsigned grp449_reserved_16;                      /* <16> */
    unsigned grp449_reserved_17;                      /* <17> */
    unsigned grp449_reserved_18;                      /* <18> */
    unsigned grp449_reserved_19;                      /* <19> */
    unsigned grp449_reserved_20;                      /* <20> */
    unsigned grp449_reserved_21;                      /* <21> */
    unsigned grp449_reserved_22;                      /* <22> */
    unsigned grp449_reserved_23;                      /* <23> */
    unsigned grp449_reserved_24;                      /* <24> */
    unsigned grp449_reserved_25;                      /* <25> */
    unsigned grp449_reserved_26;                      /* <26> */
    unsigned grp449_reserved_27;                      /* <27> */
    unsigned grp449_reserved_28;                      /* <28> */
    unsigned grp449_reserved_29;                      /* <29> */
    unsigned grp449_reserved_30;                      /* <30> */
    unsigned grp449_reserved_31;                      /* <31> */
    // GROUP 450 [reserved]
    unsigned grp450_reserved_0;                       /* < 0> */
    unsigned grp450_reserved_1;                       /* < 1> */
    unsigned grp450_reserved_2;                       /* < 2> */
    unsigned grp450_reserved_3;                       /* < 3> */
    unsigned grp450_reserved_4;                       /* < 4> */
    unsigned grp450_reserved_5;                       /* < 5> */
    unsigned grp450_reserved_6;                       /* < 6> */
    unsigned grp450_reserved_7;                       /* < 7> */
    unsigned grp450_reserved_8;                       /* < 8> */
    unsigned grp450_reserved_9;                       /* < 9> */
    unsigned grp450_reserved_10;                      /* <10> */
    unsigned grp450_reserved_11;                      /* <11> */
    unsigned grp450_reserved_12;                      /* <12> */
    unsigned grp450_reserved_13;                      /* <13> */
    unsigned grp450_reserved_14;                      /* <14> */
    unsigned grp450_reserved_15;                      /* <15> */
    unsigned grp450_reserved_16;                      /* <16> */
    unsigned grp450_reserved_17;                      /* <17> */
    unsigned grp450_reserved_18;                      /* <18> */
    unsigned grp450_reserved_19;                      /* <19> */
    unsigned grp450_reserved_20;                      /* <20> */
    unsigned grp450_reserved_21;                      /* <21> */
    unsigned grp450_reserved_22;                      /* <22> */
    unsigned grp450_reserved_23;                      /* <23> */
    unsigned grp450_reserved_24;                      /* <24> */
    unsigned grp450_reserved_25;                      /* <25> */
    unsigned grp450_reserved_26;                      /* <26> */
    unsigned grp450_reserved_27;                      /* <27> */
    unsigned grp450_reserved_28;                      /* <28> */
    unsigned grp450_reserved_29;                      /* <29> */
    unsigned grp450_reserved_30;                      /* <30> */
    unsigned grp450_reserved_31;                      /* <31> */
    // GROUP 451 [reserved]
    unsigned grp451_reserved_0;                       /* < 0> */
    unsigned grp451_reserved_1;                       /* < 1> */
    unsigned grp451_reserved_2;                       /* < 2> */
    unsigned grp451_reserved_3;                       /* < 3> */
    unsigned grp451_reserved_4;                       /* < 4> */
    unsigned grp451_reserved_5;                       /* < 5> */
    unsigned grp451_reserved_6;                       /* < 6> */
    unsigned grp451_reserved_7;                       /* < 7> */
    unsigned grp451_reserved_8;                       /* < 8> */
    unsigned grp451_reserved_9;                       /* < 9> */
    unsigned grp451_reserved_10;                      /* <10> */
    unsigned grp451_reserved_11;                      /* <11> */
    unsigned grp451_reserved_12;                      /* <12> */
    unsigned grp451_reserved_13;                      /* <13> */
    unsigned grp451_reserved_14;                      /* <14> */
    unsigned grp451_reserved_15;                      /* <15> */
    unsigned grp451_reserved_16;                      /* <16> */
    unsigned grp451_reserved_17;                      /* <17> */
    unsigned grp451_reserved_18;                      /* <18> */
    unsigned grp451_reserved_19;                      /* <19> */
    unsigned grp451_reserved_20;                      /* <20> */
    unsigned grp451_reserved_21;                      /* <21> */
    unsigned grp451_reserved_22;                      /* <22> */
    unsigned grp451_reserved_23;                      /* <23> */
    unsigned grp451_reserved_24;                      /* <24> */
    unsigned grp451_reserved_25;                      /* <25> */
    unsigned grp451_reserved_26;                      /* <26> */
    unsigned grp451_reserved_27;                      /* <27> */
    unsigned grp451_reserved_28;                      /* <28> */
    unsigned grp451_reserved_29;                      /* <29> */
    unsigned grp451_reserved_30;                      /* <30> */
    unsigned grp451_reserved_31;                      /* <31> */
    // GROUP 452 [reserved]
    unsigned grp452_reserved_0;                       /* < 0> */
    unsigned grp452_reserved_1;                       /* < 1> */
    unsigned grp452_reserved_2;                       /* < 2> */
    unsigned grp452_reserved_3;                       /* < 3> */
    unsigned grp452_reserved_4;                       /* < 4> */
    unsigned grp452_reserved_5;                       /* < 5> */
    unsigned grp452_reserved_6;                       /* < 6> */
    unsigned grp452_reserved_7;                       /* < 7> */
    unsigned grp452_reserved_8;                       /* < 8> */
    unsigned grp452_reserved_9;                       /* < 9> */
    unsigned grp452_reserved_10;                      /* <10> */
    unsigned grp452_reserved_11;                      /* <11> */
    unsigned grp452_reserved_12;                      /* <12> */
    unsigned grp452_reserved_13;                      /* <13> */
    unsigned grp452_reserved_14;                      /* <14> */
    unsigned grp452_reserved_15;                      /* <15> */
    unsigned grp452_reserved_16;                      /* <16> */
    unsigned grp452_reserved_17;                      /* <17> */
    unsigned grp452_reserved_18;                      /* <18> */
    unsigned grp452_reserved_19;                      /* <19> */
    unsigned grp452_reserved_20;                      /* <20> */
    unsigned grp452_reserved_21;                      /* <21> */
    unsigned grp452_reserved_22;                      /* <22> */
    unsigned grp452_reserved_23;                      /* <23> */
    unsigned grp452_reserved_24;                      /* <24> */
    unsigned grp452_reserved_25;                      /* <25> */
    unsigned grp452_reserved_26;                      /* <26> */
    unsigned grp452_reserved_27;                      /* <27> */
    unsigned grp452_reserved_28;                      /* <28> */
    unsigned grp452_reserved_29;                      /* <29> */
    unsigned grp452_reserved_30;                      /* <30> */
    unsigned grp452_reserved_31;                      /* <31> */
    // GROUP 453 [reserved]
    unsigned grp453_reserved_0;                       /* < 0> */
    unsigned grp453_reserved_1;                       /* < 1> */
    unsigned grp453_reserved_2;                       /* < 2> */
    unsigned grp453_reserved_3;                       /* < 3> */
    unsigned grp453_reserved_4;                       /* < 4> */
    unsigned grp453_reserved_5;                       /* < 5> */
    unsigned grp453_reserved_6;                       /* < 6> */
    unsigned grp453_reserved_7;                       /* < 7> */
    unsigned grp453_reserved_8;                       /* < 8> */
    unsigned grp453_reserved_9;                       /* < 9> */
    unsigned grp453_reserved_10;                      /* <10> */
    unsigned grp453_reserved_11;                      /* <11> */
    unsigned grp453_reserved_12;                      /* <12> */
    unsigned grp453_reserved_13;                      /* <13> */
    unsigned grp453_reserved_14;                      /* <14> */
    unsigned grp453_reserved_15;                      /* <15> */
    unsigned grp453_reserved_16;                      /* <16> */
    unsigned grp453_reserved_17;                      /* <17> */
    unsigned grp453_reserved_18;                      /* <18> */
    unsigned grp453_reserved_19;                      /* <19> */
    unsigned grp453_reserved_20;                      /* <20> */
    unsigned grp453_reserved_21;                      /* <21> */
    unsigned grp453_reserved_22;                      /* <22> */
    unsigned grp453_reserved_23;                      /* <23> */
    unsigned grp453_reserved_24;                      /* <24> */
    unsigned grp453_reserved_25;                      /* <25> */
    unsigned grp453_reserved_26;                      /* <26> */
    unsigned grp453_reserved_27;                      /* <27> */
    unsigned grp453_reserved_28;                      /* <28> */
    unsigned grp453_reserved_29;                      /* <29> */
    unsigned grp453_reserved_30;                      /* <30> */
    unsigned grp453_reserved_31;                      /* <31> */
    // GROUP 454 [reserved]
    unsigned grp454_reserved_0;                       /* < 0> */
    unsigned grp454_reserved_1;                       /* < 1> */
    unsigned grp454_reserved_2;                       /* < 2> */
    unsigned grp454_reserved_3;                       /* < 3> */
    unsigned grp454_reserved_4;                       /* < 4> */
    unsigned grp454_reserved_5;                       /* < 5> */
    unsigned grp454_reserved_6;                       /* < 6> */
    unsigned grp454_reserved_7;                       /* < 7> */
    unsigned grp454_reserved_8;                       /* < 8> */
    unsigned grp454_reserved_9;                       /* < 9> */
    unsigned grp454_reserved_10;                      /* <10> */
    unsigned grp454_reserved_11;                      /* <11> */
    unsigned grp454_reserved_12;                      /* <12> */
    unsigned grp454_reserved_13;                      /* <13> */
    unsigned grp454_reserved_14;                      /* <14> */
    unsigned grp454_reserved_15;                      /* <15> */
    unsigned grp454_reserved_16;                      /* <16> */
    unsigned grp454_reserved_17;                      /* <17> */
    unsigned grp454_reserved_18;                      /* <18> */
    unsigned grp454_reserved_19;                      /* <19> */
    unsigned grp454_reserved_20;                      /* <20> */
    unsigned grp454_reserved_21;                      /* <21> */
    unsigned grp454_reserved_22;                      /* <22> */
    unsigned grp454_reserved_23;                      /* <23> */
    unsigned grp454_reserved_24;                      /* <24> */
    unsigned grp454_reserved_25;                      /* <25> */
    unsigned grp454_reserved_26;                      /* <26> */
    unsigned grp454_reserved_27;                      /* <27> */
    unsigned grp454_reserved_28;                      /* <28> */
    unsigned grp454_reserved_29;                      /* <29> */
    unsigned grp454_reserved_30;                      /* <30> */
    unsigned grp454_reserved_31;                      /* <31> */
    // GROUP 455 [reserved]
    unsigned grp455_reserved_0;                       /* < 0> */
    unsigned grp455_reserved_1;                       /* < 1> */
    unsigned grp455_reserved_2;                       /* < 2> */
    unsigned grp455_reserved_3;                       /* < 3> */
    unsigned grp455_reserved_4;                       /* < 4> */
    unsigned grp455_reserved_5;                       /* < 5> */
    unsigned grp455_reserved_6;                       /* < 6> */
    unsigned grp455_reserved_7;                       /* < 7> */
    unsigned grp455_reserved_8;                       /* < 8> */
    unsigned grp455_reserved_9;                       /* < 9> */
    unsigned grp455_reserved_10;                      /* <10> */
    unsigned grp455_reserved_11;                      /* <11> */
    unsigned grp455_reserved_12;                      /* <12> */
    unsigned grp455_reserved_13;                      /* <13> */
    unsigned grp455_reserved_14;                      /* <14> */
    unsigned grp455_reserved_15;                      /* <15> */
    unsigned grp455_reserved_16;                      /* <16> */
    unsigned grp455_reserved_17;                      /* <17> */
    unsigned grp455_reserved_18;                      /* <18> */
    unsigned grp455_reserved_19;                      /* <19> */
    unsigned grp455_reserved_20;                      /* <20> */
    unsigned grp455_reserved_21;                      /* <21> */
    unsigned grp455_reserved_22;                      /* <22> */
    unsigned grp455_reserved_23;                      /* <23> */
    unsigned grp455_reserved_24;                      /* <24> */
    unsigned grp455_reserved_25;                      /* <25> */
    unsigned grp455_reserved_26;                      /* <26> */
    unsigned grp455_reserved_27;                      /* <27> */
    unsigned grp455_reserved_28;                      /* <28> */
    unsigned grp455_reserved_29;                      /* <29> */
    unsigned grp455_reserved_30;                      /* <30> */
    unsigned grp455_reserved_31;                      /* <31> */
    // GROUP 456 [reserved]
    unsigned grp456_reserved_0;                       /* < 0> */
    unsigned grp456_reserved_1;                       /* < 1> */
    unsigned grp456_reserved_2;                       /* < 2> */
    unsigned grp456_reserved_3;                       /* < 3> */
    unsigned grp456_reserved_4;                       /* < 4> */
    unsigned grp456_reserved_5;                       /* < 5> */
    unsigned grp456_reserved_6;                       /* < 6> */
    unsigned grp456_reserved_7;                       /* < 7> */
    unsigned grp456_reserved_8;                       /* < 8> */
    unsigned grp456_reserved_9;                       /* < 9> */
    unsigned grp456_reserved_10;                      /* <10> */
    unsigned grp456_reserved_11;                      /* <11> */
    unsigned grp456_reserved_12;                      /* <12> */
    unsigned grp456_reserved_13;                      /* <13> */
    unsigned grp456_reserved_14;                      /* <14> */
    unsigned grp456_reserved_15;                      /* <15> */
    unsigned grp456_reserved_16;                      /* <16> */
    unsigned grp456_reserved_17;                      /* <17> */
    unsigned grp456_reserved_18;                      /* <18> */
    unsigned grp456_reserved_19;                      /* <19> */
    unsigned grp456_reserved_20;                      /* <20> */
    unsigned grp456_reserved_21;                      /* <21> */
    unsigned grp456_reserved_22;                      /* <22> */
    unsigned grp456_reserved_23;                      /* <23> */
    unsigned grp456_reserved_24;                      /* <24> */
    unsigned grp456_reserved_25;                      /* <25> */
    unsigned grp456_reserved_26;                      /* <26> */
    unsigned grp456_reserved_27;                      /* <27> */
    unsigned grp456_reserved_28;                      /* <28> */
    unsigned grp456_reserved_29;                      /* <29> */
    unsigned grp456_reserved_30;                      /* <30> */
    unsigned grp456_reserved_31;                      /* <31> */
    // GROUP 457 [reserved]
    unsigned grp457_reserved_0;                       /* < 0> */
    unsigned grp457_reserved_1;                       /* < 1> */
    unsigned grp457_reserved_2;                       /* < 2> */
    unsigned grp457_reserved_3;                       /* < 3> */
    unsigned grp457_reserved_4;                       /* < 4> */
    unsigned grp457_reserved_5;                       /* < 5> */
    unsigned grp457_reserved_6;                       /* < 6> */
    unsigned grp457_reserved_7;                       /* < 7> */
    unsigned grp457_reserved_8;                       /* < 8> */
    unsigned grp457_reserved_9;                       /* < 9> */
    unsigned grp457_reserved_10;                      /* <10> */
    unsigned grp457_reserved_11;                      /* <11> */
    unsigned grp457_reserved_12;                      /* <12> */
    unsigned grp457_reserved_13;                      /* <13> */
    unsigned grp457_reserved_14;                      /* <14> */
    unsigned grp457_reserved_15;                      /* <15> */
    unsigned grp457_reserved_16;                      /* <16> */
    unsigned grp457_reserved_17;                      /* <17> */
    unsigned grp457_reserved_18;                      /* <18> */
    unsigned grp457_reserved_19;                      /* <19> */
    unsigned grp457_reserved_20;                      /* <20> */
    unsigned grp457_reserved_21;                      /* <21> */
    unsigned grp457_reserved_22;                      /* <22> */
    unsigned grp457_reserved_23;                      /* <23> */
    unsigned grp457_reserved_24;                      /* <24> */
    unsigned grp457_reserved_25;                      /* <25> */
    unsigned grp457_reserved_26;                      /* <26> */
    unsigned grp457_reserved_27;                      /* <27> */
    unsigned grp457_reserved_28;                      /* <28> */
    unsigned grp457_reserved_29;                      /* <29> */
    unsigned grp457_reserved_30;                      /* <30> */
    unsigned grp457_reserved_31;                      /* <31> */
    // GROUP 458 [reserved]
    unsigned grp458_reserved_0;                       /* < 0> */
    unsigned grp458_reserved_1;                       /* < 1> */
    unsigned grp458_reserved_2;                       /* < 2> */
    unsigned grp458_reserved_3;                       /* < 3> */
    unsigned grp458_reserved_4;                       /* < 4> */
    unsigned grp458_reserved_5;                       /* < 5> */
    unsigned grp458_reserved_6;                       /* < 6> */
    unsigned grp458_reserved_7;                       /* < 7> */
    unsigned grp458_reserved_8;                       /* < 8> */
    unsigned grp458_reserved_9;                       /* < 9> */
    unsigned grp458_reserved_10;                      /* <10> */
    unsigned grp458_reserved_11;                      /* <11> */
    unsigned grp458_reserved_12;                      /* <12> */
    unsigned grp458_reserved_13;                      /* <13> */
    unsigned grp458_reserved_14;                      /* <14> */
    unsigned grp458_reserved_15;                      /* <15> */
    unsigned grp458_reserved_16;                      /* <16> */
    unsigned grp458_reserved_17;                      /* <17> */
    unsigned grp458_reserved_18;                      /* <18> */
    unsigned grp458_reserved_19;                      /* <19> */
    unsigned grp458_reserved_20;                      /* <20> */
    unsigned grp458_reserved_21;                      /* <21> */
    unsigned grp458_reserved_22;                      /* <22> */
    unsigned grp458_reserved_23;                      /* <23> */
    unsigned grp458_reserved_24;                      /* <24> */
    unsigned grp458_reserved_25;                      /* <25> */
    unsigned grp458_reserved_26;                      /* <26> */
    unsigned grp458_reserved_27;                      /* <27> */
    unsigned grp458_reserved_28;                      /* <28> */
    unsigned grp458_reserved_29;                      /* <29> */
    unsigned grp458_reserved_30;                      /* <30> */
    unsigned grp458_reserved_31;                      /* <31> */
    // GROUP 459 [reserved]
    unsigned grp459_reserved_0;                       /* < 0> */
    unsigned grp459_reserved_1;                       /* < 1> */
    unsigned grp459_reserved_2;                       /* < 2> */
    unsigned grp459_reserved_3;                       /* < 3> */
    unsigned grp459_reserved_4;                       /* < 4> */
    unsigned grp459_reserved_5;                       /* < 5> */
    unsigned grp459_reserved_6;                       /* < 6> */
    unsigned grp459_reserved_7;                       /* < 7> */
    unsigned grp459_reserved_8;                       /* < 8> */
    unsigned grp459_reserved_9;                       /* < 9> */
    unsigned grp459_reserved_10;                      /* <10> */
    unsigned grp459_reserved_11;                      /* <11> */
    unsigned grp459_reserved_12;                      /* <12> */
    unsigned grp459_reserved_13;                      /* <13> */
    unsigned grp459_reserved_14;                      /* <14> */
    unsigned grp459_reserved_15;                      /* <15> */
    unsigned grp459_reserved_16;                      /* <16> */
    unsigned grp459_reserved_17;                      /* <17> */
    unsigned grp459_reserved_18;                      /* <18> */
    unsigned grp459_reserved_19;                      /* <19> */
    unsigned grp459_reserved_20;                      /* <20> */
    unsigned grp459_reserved_21;                      /* <21> */
    unsigned grp459_reserved_22;                      /* <22> */
    unsigned grp459_reserved_23;                      /* <23> */
    unsigned grp459_reserved_24;                      /* <24> */
    unsigned grp459_reserved_25;                      /* <25> */
    unsigned grp459_reserved_26;                      /* <26> */
    unsigned grp459_reserved_27;                      /* <27> */
    unsigned grp459_reserved_28;                      /* <28> */
    unsigned grp459_reserved_29;                      /* <29> */
    unsigned grp459_reserved_30;                      /* <30> */
    unsigned grp459_reserved_31;                      /* <31> */
    // GROUP 460 [reserved]
    unsigned grp460_reserved_0;                       /* < 0> */
    unsigned grp460_reserved_1;                       /* < 1> */
    unsigned grp460_reserved_2;                       /* < 2> */
    unsigned grp460_reserved_3;                       /* < 3> */
    unsigned grp460_reserved_4;                       /* < 4> */
    unsigned grp460_reserved_5;                       /* < 5> */
    unsigned grp460_reserved_6;                       /* < 6> */
    unsigned grp460_reserved_7;                       /* < 7> */
    unsigned grp460_reserved_8;                       /* < 8> */
    unsigned grp460_reserved_9;                       /* < 9> */
    unsigned grp460_reserved_10;                      /* <10> */
    unsigned grp460_reserved_11;                      /* <11> */
    unsigned grp460_reserved_12;                      /* <12> */
    unsigned grp460_reserved_13;                      /* <13> */
    unsigned grp460_reserved_14;                      /* <14> */
    unsigned grp460_reserved_15;                      /* <15> */
    unsigned grp460_reserved_16;                      /* <16> */
    unsigned grp460_reserved_17;                      /* <17> */
    unsigned grp460_reserved_18;                      /* <18> */
    unsigned grp460_reserved_19;                      /* <19> */
    unsigned grp460_reserved_20;                      /* <20> */
    unsigned grp460_reserved_21;                      /* <21> */
    unsigned grp460_reserved_22;                      /* <22> */
    unsigned grp460_reserved_23;                      /* <23> */
    unsigned grp460_reserved_24;                      /* <24> */
    unsigned grp460_reserved_25;                      /* <25> */
    unsigned grp460_reserved_26;                      /* <26> */
    unsigned grp460_reserved_27;                      /* <27> */
    unsigned grp460_reserved_28;                      /* <28> */
    unsigned grp460_reserved_29;                      /* <29> */
    unsigned grp460_reserved_30;                      /* <30> */
    unsigned grp460_reserved_31;                      /* <31> */
    // GROUP 461 [reserved]
    unsigned grp461_reserved_0;                       /* < 0> */
    unsigned grp461_reserved_1;                       /* < 1> */
    unsigned grp461_reserved_2;                       /* < 2> */
    unsigned grp461_reserved_3;                       /* < 3> */
    unsigned grp461_reserved_4;                       /* < 4> */
    unsigned grp461_reserved_5;                       /* < 5> */
    unsigned grp461_reserved_6;                       /* < 6> */
    unsigned grp461_reserved_7;                       /* < 7> */
    unsigned grp461_reserved_8;                       /* < 8> */
    unsigned grp461_reserved_9;                       /* < 9> */
    unsigned grp461_reserved_10;                      /* <10> */
    unsigned grp461_reserved_11;                      /* <11> */
    unsigned grp461_reserved_12;                      /* <12> */
    unsigned grp461_reserved_13;                      /* <13> */
    unsigned grp461_reserved_14;                      /* <14> */
    unsigned grp461_reserved_15;                      /* <15> */
    unsigned grp461_reserved_16;                      /* <16> */
    unsigned grp461_reserved_17;                      /* <17> */
    unsigned grp461_reserved_18;                      /* <18> */
    unsigned grp461_reserved_19;                      /* <19> */
    unsigned grp461_reserved_20;                      /* <20> */
    unsigned grp461_reserved_21;                      /* <21> */
    unsigned grp461_reserved_22;                      /* <22> */
    unsigned grp461_reserved_23;                      /* <23> */
    unsigned grp461_reserved_24;                      /* <24> */
    unsigned grp461_reserved_25;                      /* <25> */
    unsigned grp461_reserved_26;                      /* <26> */
    unsigned grp461_reserved_27;                      /* <27> */
    unsigned grp461_reserved_28;                      /* <28> */
    unsigned grp461_reserved_29;                      /* <29> */
    unsigned grp461_reserved_30;                      /* <30> */
    unsigned grp461_reserved_31;                      /* <31> */
    // GROUP 462 [reserved]
    unsigned grp462_reserved_0;                       /* < 0> */
    unsigned grp462_reserved_1;                       /* < 1> */
    unsigned grp462_reserved_2;                       /* < 2> */
    unsigned grp462_reserved_3;                       /* < 3> */
    unsigned grp462_reserved_4;                       /* < 4> */
    unsigned grp462_reserved_5;                       /* < 5> */
    unsigned grp462_reserved_6;                       /* < 6> */
    unsigned grp462_reserved_7;                       /* < 7> */
    unsigned grp462_reserved_8;                       /* < 8> */
    unsigned grp462_reserved_9;                       /* < 9> */
    unsigned grp462_reserved_10;                      /* <10> */
    unsigned grp462_reserved_11;                      /* <11> */
    unsigned grp462_reserved_12;                      /* <12> */
    unsigned grp462_reserved_13;                      /* <13> */
    unsigned grp462_reserved_14;                      /* <14> */
    unsigned grp462_reserved_15;                      /* <15> */
    unsigned grp462_reserved_16;                      /* <16> */
    unsigned grp462_reserved_17;                      /* <17> */
    unsigned grp462_reserved_18;                      /* <18> */
    unsigned grp462_reserved_19;                      /* <19> */
    unsigned grp462_reserved_20;                      /* <20> */
    unsigned grp462_reserved_21;                      /* <21> */
    unsigned grp462_reserved_22;                      /* <22> */
    unsigned grp462_reserved_23;                      /* <23> */
    unsigned grp462_reserved_24;                      /* <24> */
    unsigned grp462_reserved_25;                      /* <25> */
    unsigned grp462_reserved_26;                      /* <26> */
    unsigned grp462_reserved_27;                      /* <27> */
    unsigned grp462_reserved_28;                      /* <28> */
    unsigned grp462_reserved_29;                      /* <29> */
    unsigned grp462_reserved_30;                      /* <30> */
    unsigned grp462_reserved_31;                      /* <31> */
    // GROUP 463 [reserved]
    unsigned grp463_reserved_0;                       /* < 0> */
    unsigned grp463_reserved_1;                       /* < 1> */
    unsigned grp463_reserved_2;                       /* < 2> */
    unsigned grp463_reserved_3;                       /* < 3> */
    unsigned grp463_reserved_4;                       /* < 4> */
    unsigned grp463_reserved_5;                       /* < 5> */
    unsigned grp463_reserved_6;                       /* < 6> */
    unsigned grp463_reserved_7;                       /* < 7> */
    unsigned grp463_reserved_8;                       /* < 8> */
    unsigned grp463_reserved_9;                       /* < 9> */
    unsigned grp463_reserved_10;                      /* <10> */
    unsigned grp463_reserved_11;                      /* <11> */
    unsigned grp463_reserved_12;                      /* <12> */
    unsigned grp463_reserved_13;                      /* <13> */
    unsigned grp463_reserved_14;                      /* <14> */
    unsigned grp463_reserved_15;                      /* <15> */
    unsigned grp463_reserved_16;                      /* <16> */
    unsigned grp463_reserved_17;                      /* <17> */
    unsigned grp463_reserved_18;                      /* <18> */
    unsigned grp463_reserved_19;                      /* <19> */
    unsigned grp463_reserved_20;                      /* <20> */
    unsigned grp463_reserved_21;                      /* <21> */
    unsigned grp463_reserved_22;                      /* <22> */
    unsigned grp463_reserved_23;                      /* <23> */
    unsigned grp463_reserved_24;                      /* <24> */
    unsigned grp463_reserved_25;                      /* <25> */
    unsigned grp463_reserved_26;                      /* <26> */
    unsigned grp463_reserved_27;                      /* <27> */
    unsigned grp463_reserved_28;                      /* <28> */
    unsigned grp463_reserved_29;                      /* <29> */
    unsigned grp463_reserved_30;                      /* <30> */
    unsigned grp463_reserved_31;                      /* <31> */
    // Group 464 ~ Group 465 : Scaling Matrix1
    unsigned h264_sl_8x8_intra_y[64];
    // Group 466 ~ Group 467 : Scaling Matrix2
    unsigned h264_sl_8x8_inter_y[64];
    // Group 468 : Scaling Matrix3
    unsigned h264_sl_4x4_intra_y[16];
    unsigned h264_sl_4x4_intra_cb[16];
    // Group 469 : Scaling Matrix4
    unsigned h264_sl_4x4_intra_cr[16];
    unsigned h264_sl_4x4_inter_y[16];
    // Group 470 : Scaling Matrix5
    unsigned h264_sl_4x4_inter_cb[16];
    unsigned h264_sl_4x4_inter_cr[16];
    // GROUP 471
    unsigned grp471_reserved[32];
    // GROUP 472 [mfd_checksum_module]
    unsigned mfd_version;                             /* < 0> [dv: 0x20140220] [des: MFD Version Register] */
    unsigned mfd_gmv_chksum;                          /* < 1> [dv: 0x00000000] [des: GMV CHECKSUM] */
    unsigned mfd_lmv_chksum;                          /* < 2> [dv: 0x00000000] [des: LMV CHECKSUM] */
    unsigned mfd_cmv_chksum;                          /* < 3> [dv: 0x00000000] [des: CMV CHECKSUM] */
    unsigned mfd_mp_qt_chksum;                        /* < 4> [dv: 0x00000000] [des: MP to QT data checksum] */
    unsigned mfd_mp_mr_chksum;                        /* < 5> [dv: 0x00000000] [des: MP to MR data checksum] */
    unsigned mfd_mp_lf_chksum;                        /* < 6> [dv: 0x00000000] [des: MP to LF data checksum] */
    unsigned mfd_qt_mr_chksum;                        /* < 7> [dv: 0x00000000] [des: QT to MR data checksum] */
    unsigned mfd_mr_lf_chksum;                        /* < 8> [dv: 0x00000000] [des: MR to LF data checksum] */
    unsigned mfd_mr_mc_chksum;                        /* < 9> [dv: 0x00000000] [des: MR to MC data checksum] */
    unsigned mfd_lf_mc_chksum;                        /* <10> [dv: 0x00000000] [des: LF to MC data checksum] */
    unsigned mfd_mon_cur_urgent_count;                /* <11> [dv: 0x000000ff] [des: Current Urgent Count] */
    unsigned mfd_stop_urgent_count;                   /* <12> [dv: 0x00000000] [des: Stop Urgent Count] */
    unsigned mfd_mb_desire_cycle;                     /* <13> [dv: 0x00000000] [des: MB Desired Cycle] */
    unsigned mfd_mon_total_cycle;                     /* <14> [dv: 0x00000000] [des: Total Cycle Count] */
    unsigned mfd_xmb_desire_cycle;                    /* <15> [dv: 0x00000000] [des: Desired Cycles of X MBs] */
    unsigned mfd_measure_mb_count;                    /* <16> [dv: 0x00000007] [des: Cycle count of X MBs] */
    unsigned mfd_sbar_ctrl;                           /* <17> [dv: 0x00000000] [des: MFD SBUS behavior Control Register] */
    unsigned mfd_cycle_cnt;                           /* <18> [dv: 0x00000000] [des: Clock Cycle Count ] */
    unsigned mfd_debug_ctrl0;                         /* <19> [dv: 0x00000000] [des: Debug Control Register 0] */
    unsigned mfd_debug_ctrl1;                         /* <20> [dv: 0x000fffff] [des: Debug Control Register 1] */
    unsigned mfd_mon_misc_1;                          /* <21> [dv: 0x00000045] [des: MISC Monitor Register 1] */
    unsigned mfd_mon_misc_2;                          /* <22> [dv: 0x00002900] [des: MISC Monitor Register 2] */
    unsigned mfd_mon_misc_3;                          /* <23> [dv: 0x00008000] [des: MISC Monitor Register 3] */
    unsigned mfd_mon_misc_4;                          /* <24> [dv: 0x00000000] [des: MISC Monitor Register 4] */
    unsigned mfd_mon_misc_5;                          /* <25> [dv: 0x00000105] [des: MISC Monitor Register 5, in RV mode:default:0x155, others default:0x105] */
    unsigned mfd_lfbwr_mc_sum;                        /* <26> [dv: 0x00000000] [des: LF BWR Checksum] */
    unsigned reserved_0_64;                           /* <27> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_1_58_;                           /* <28> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_2_50_;                           /* <29> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_3_38_;                           /* <30> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_4_34_;                           /* <31> [dv:     0x0000] [des: Reserved] */
    // GROUP 473 [video_bitstream_parameters]
    unsigned mpeg_seq_ext;                            /* < 0> [dv:     0x0000] [des: Sequence Codec Format] */
    unsigned mpeg_h_size;                             /* < 1> [dv:     0x0000] [des: Picture Horizontal Size in Pixel Unit (for VLD)] */
    unsigned mpeg_v_size;                             /* < 2> [dv:     0x0000] [des: Picture Vertical Size in Pixel Unit (for VLD)] */
    unsigned reserved_0_66;                           /* < 3> [dv:     0x0000] [des: Reserved] */
    unsigned mpeg_pic_coding_type;                    /* < 4> [dv:     0x0000] [des: Picture Coding Type] */
    unsigned mpeg_pic_f_code;                         /* < 5> [dv:     0x0000] [des: Motion Vector F Code] */
    unsigned mpeg_pic_coding_ext0;                    /* < 6> [dv:     0x0000] [des: MPEG Picture Coding Extension] */
    unsigned mpeg_pic_coding_ext1;                    /* < 7> [dv:     0x0000] [des: Motion Compensation Frame Buffer Select (for buffer control)] */
    unsigned mpeg_pic_start;                          /* < 8> [dv:     0x0000] [des: Picture Start] */
    unsigned mfd_dis_pic_id;                          /* < 9> [dv:     0x0000] [des: Display Picture ID] */
    unsigned mfd_dis_seq_tag;                         /* <10> [dv:     0x0000] [des: Display and Buffer Control Flag] */
    unsigned mfd_dis_pic_id_2;                        /* <11> [dv:     0x0000] [des: Display Picture ID 2] */
    unsigned reserved_1_60;                           /* <12> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_2_52;                           /* <13> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_3_40;                           /* <14> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_4_36;                           /* <15> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_5_34;                           /* <16> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_6_31;                           /* <17> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_7_31;                           /* <18> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_8_30;                           /* <19> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_9_27;                           /* <20> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_10_26;                          /* <21> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_11_19;                          /* <22> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_12_15;                          /* <23> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_13_15;                          /* <24> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_14_15;                          /* <25> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_15_14;                          /* <26> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_16_9;                           /* <27> [dv:     0x0000] [des: Reserved] */
    unsigned reserved_17_7;                           /* <28> [dv:     0x0000] [des: Reserved] */
    unsigned mpeg_divx_mw_pad;                        /* <29> [dv:     0x0000] [des: ] */
    unsigned mpeg_qpel_ctrl;                          /* <30> [dv: 0x00000002] [des: ] */
    unsigned mpeg_vop_rounding_type;                  /* <31> [dv:     0x0000] [des: ] */
    // GROUP 474 [realvideo_global_related]
    unsigned rv_profile;                              /* < 0> [dv:     0x0000] [des: RealVideo Profile (Version)] */
    unsigned rv_pic_type;                             /* < 1> [dv:     0x0000] [des: RealVideo Picture Type] */
    unsigned rv_quant;                                /* < 2> [dv:     0x0000] [des: RealVideo Quantizer] */
    unsigned rv_hsize;                                /* < 3> [dv:     0x0000] [des: RealVideo Horizontal Picture Size in Pixels] */
    unsigned rv_vsize;                                /* < 4> [dv:     0x0000] [des: RealVideo Vertical Picture Size in Pixels] */
    unsigned grp474_reserved_0;                       /* < 5> */
    unsigned rv_mvbase;                               /* < 6> [dv:     0x0000] [des: RealVideo Motion Vector Buffer Base] */
    unsigned rv_rpmbase;                              /* < 7> [dv:     0x0000] [des: RealVideo Re-sampling Source Frame Buffer Base] */
    unsigned rv_lfbase;                               /* < 8> [dv:     0x0000] [des: RealVideo Current frame Buffer Base] */
    unsigned rv_lf_ctrl;                              /* < 9> [dv:     0x0000] [des: RealVideo Loop Filter Control] */
    unsigned grp474_reserved_1;                       /* <10> */
    unsigned grp474_reserved_2;                       /* <11> */
    unsigned grp474_reserved_3;                       /* <12> */
    unsigned grp474_reserved_4;                       /* <13> */
    unsigned grp474_reserved_5;                       /* <14> */
    unsigned grp474_reserved_6;                       /* <15> */
    unsigned grp474_reserved_7;                       /* <16> */
    unsigned grp474_reserved_8;                       /* <17> */
    unsigned grp474_reserved_9;                       /* <18> */
    unsigned grp474_reserved_10;                      /* <19> */
    unsigned grp474_reserved_11;                      /* <20> */
    unsigned grp474_reserved_12;                      /* <21> */
    unsigned grp474_reserved_13;                      /* <22> */
    unsigned grp474_reserved_14;                      /* <23> */
    unsigned grp474_reserved_15;                      /* <24> */
    unsigned grp474_reserved_16;                      /* <25> */
    unsigned grp474_reserved_17;                      /* <26> */
    unsigned grp474_reserved_18;                      /* <27> */
    unsigned grp474_reserved_19;                      /* <28> */
    unsigned grp474_reserved_20;                      /* <29> */
    unsigned grp474_reserved_21;                      /* <30> */
    unsigned grp474_reserved_22;                      /* <31> */
    // GROUP 475 [realvideo_mp_related]
    unsigned rv_osvquant;                             /* < 0> [dv:     0x0000] [des: RealVideo OSVQuant] */
    unsigned rv_first_mb_addr;                        /* < 1> [dv:     0x0000] [des: RealVideo First MB Address in a Slice] */
    unsigned grp475_reserved_0;                       /* < 2> */
    unsigned grp475_reserved_1;                       /* < 3> */
    unsigned grp475_reserved_2;                       /* < 4> */
    unsigned grp475_reserved_3;                       /* < 5> */
    unsigned grp475_reserved_4;                       /* < 6> */
    unsigned grp475_reserved_5;                       /* < 7> */
    unsigned grp475_reserved_6;                       /* < 8> */
    unsigned grp475_reserved_7;                       /* < 9> */
    unsigned grp475_reserved_8;                       /* <10> */
    unsigned grp475_reserved_9;                       /* <11> */
    unsigned grp475_reserved_10;                      /* <12> */
    unsigned grp475_reserved_11;                      /* <13> */
    unsigned grp475_reserved_12;                      /* <14> */
    unsigned grp475_reserved_13;                      /* <15> */
    unsigned grp475_reserved_14;                      /* <16> */
    unsigned grp475_reserved_15;                      /* <17> */
    unsigned grp475_reserved_16;                      /* <18> */
    unsigned grp475_reserved_17;                      /* <19> */
    unsigned grp475_reserved_18;                      /* <20> */
    unsigned grp475_reserved_19;                      /* <21> */
    unsigned grp475_reserved_20;                      /* <22> */
    unsigned grp475_reserved_21;                      /* <23> */
    unsigned grp475_reserved_22;                      /* <24> */
    unsigned grp475_reserved_23;                      /* <25> */
    unsigned grp475_reserved_24;                      /* <26> */
    unsigned grp475_reserved_25;                      /* <27> */
    unsigned grp475_reserved_26;                      /* <28> */
    unsigned grp475_reserved_27;                      /* <29> */
    unsigned grp475_reserved_28;                      /* <30> */
    unsigned grp475_reserved_29;                      /* <31> */
    // GROUP 476 [realvideo_mr_related]
    unsigned rv_urati;                                /* < 0> [dv:     0x0000] [des: RV Iratio] */
    unsigned rv_rpmsize;                              /* < 1> [dv:     0x0000] [des: RV Re-sampling Source Size] */
    unsigned rv_rpmfill;                              /* < 2> [dv:     0x0000] [des: RV Re-sampling Rounding] */
    unsigned rv_rpmen;                                /* < 3> [dv:     0x0000] [des: RV Re-sampling Enable] */
    unsigned rv_rpmxp;                                /* < 4> [dv:     0x0000] [des: RV Luma Re-sampling H Parameters Low Word Part] */
    unsigned rv_rpmcxp;                               /* < 5> [dv:     0x0000] [des: RV Chroma Re-sampling H Parameters Low Word Part] */
    unsigned rv_rpmyp;                                /* < 6> [dv:     0x0000] [des: RV Luma Re-sampling V Parameters Low Word Part] */
    unsigned rv_rpmcyp;                               /* < 7> [dv:     0x0000] [des: RV Chroma Re-sampling V Parameters Low Word Part] */
    unsigned rv_rpmxp_high;                           /* < 8> [dv:     0x0000] [des: RV Luma Re-sampling H Parameters High Word Part] */
    unsigned rv_rpmcxp_high;                          /* < 9> [dv:     0x0000] [des: RV Chroma Re-sampling H Parameters High Word Part] */
    unsigned rv_rpmyp_high;                           /* <10> [dv:     0x0000] [des: RV Luma Re-sampling V Parameters High Word Part] */
    unsigned rv_rpmcyp_high;                          /* <11> [dv:     0x0000] [des: RV Chroma Re-sampling V Parameters High Word Part] */
    unsigned grp476_reserved_0;                       /* <12> */
    unsigned grp476_reserved_1;                       /* <13> */
    unsigned grp476_reserved_2;                       /* <14> */
    unsigned grp476_reserved_3;                       /* <15> */
    unsigned grp476_reserved_4;                       /* <16> */
    unsigned grp476_reserved_5;                       /* <17> */
    unsigned grp476_reserved_6;                       /* <18> */
    unsigned grp476_reserved_7;                       /* <19> */
    unsigned grp476_reserved_8;                       /* <20> */
    unsigned grp476_reserved_9;                       /* <21> */
    unsigned grp476_reserved_10;                      /* <22> */
    unsigned grp476_reserved_11;                      /* <23> */
    unsigned grp476_reserved_12;                      /* <24> */
    unsigned grp476_reserved_13;                      /* <25> */
    unsigned grp476_reserved_14;                      /* <26> */
    unsigned grp476_reserved_15;                      /* <27> */
    unsigned grp476_reserved_16;                      /* <28> */
    unsigned grp476_reserved_17;                      /* <29> */
    unsigned grp476_reserved_18;                      /* <30> */
    unsigned grp476_reserved_19;                      /* <31> */
    // GROUP 477 [realvideo_lf_related]
    unsigned rv_v8_dstr;                              /* < 0> [dv:     0x0000] [des: RV V8 Deblock Strength Table Selector] */
    unsigned rv_psmall;                               /* < 1> [dv:     0x0000] [des: RV Small Picture Flag] */
    unsigned rv_buf_ctrl;                             /* < 2> [dv:     0x0000] [des: RV Loop Filter Buffer Control] */
    unsigned grp477_reserved_0;                       /* < 3> */
    unsigned grp477_reserved_1;                       /* < 4> */
    unsigned grp477_reserved_2;                       /* < 5> */
    unsigned grp477_reserved_3;                       /* < 6> */
    unsigned grp477_reserved_4;                       /* < 7> */
    unsigned grp477_reserved_5;                       /* < 8> */
    unsigned grp477_reserved_6;                       /* < 9> */
    unsigned grp477_reserved_7;                       /* <10> */
    unsigned grp477_reserved_8;                       /* <11> */
    unsigned grp477_reserved_9;                       /* <12> */
    unsigned grp477_reserved_10;                      /* <13> */
    unsigned grp477_reserved_11;                      /* <14> */
    unsigned grp477_reserved_12;                      /* <15> */
    unsigned grp477_reserved_13;                      /* <16> */
    unsigned grp477_reserved_14;                      /* <17> */
    unsigned grp477_reserved_15;                      /* <18> */
    unsigned grp477_reserved_16;                      /* <19> */
    unsigned grp477_reserved_17;                      /* <20> */
    unsigned grp477_reserved_18;                      /* <21> */
    unsigned grp477_reserved_19;                      /* <22> */
    unsigned grp477_reserved_20;                      /* <23> */
    unsigned grp477_reserved_21;                      /* <24> */
    unsigned grp477_reserved_22;                      /* <25> */
    unsigned grp477_reserved_23;                      /* <26> */
    unsigned grp477_reserved_24;                      /* <27> */
    unsigned grp477_reserved_25;                      /* <28> */
    unsigned grp477_reserved_26;                      /* <29> */
    unsigned grp477_reserved_27;                      /* <30> */
    unsigned grp477_reserved_28;                      /* <31> */
    // GROUP 478 [gclk_free_control_related]
    unsigned mfd_rg_gclk_free;                        /* < 0> [dv:     0x0000] [des: MFD RG GCLK Free Control] */
    unsigned scs_gclk_free;                           /* < 1> [dv:     0x0000] [des: Start Code Search GCLK Free Control] */
    unsigned mp264_gclk_free;                         /* < 2> [dv:     0x0000] [des: H.264 MP GCLK Free Control] */
    unsigned qt264_gclk_free;                         /* < 3> [dv:     0x0000] [des: H.264/RV/AVS QT GCLK Free Control] */
    unsigned mr264_gclk_free;                         /* < 4> [dv:     0x0000] [des: H.264/RV/AVS MR GCLK Free Control] */
    unsigned wp264_gclk_free;                         /* < 5> [dv:     0x0000] [des: H.264 WP GCLK Free Control] */
    unsigned lf264_gclk_free;                         /* < 6> [dv:     0x0000] [des: H.264/AVS LF GCLK Free Control] */
    unsigned mpvc1_gclk_free;                         /* < 7> [dv:     0x0000] [des: VC-1 MP GCLK Free Control] */
    unsigned qt9421_gclk_free;                        /* < 8> [dv:     0x0000] [des: MPEG/VC-1 QT GCLK Free Control] */
    unsigned mr9421_gclk_free;                        /* < 9> [dv:     0x0000] [des: MPEG/VC-1 MR GCLK Free Control] */
    unsigned lf9421_gclk_free;                        /* <10> [dv:     0x0000] [des: MPEG/VC-1 LF GCLK Free Control] */
    unsigned mprv_gclk_free;                          /* <11> [dv:     0x0000] [des: RealVideo MP GCLK Free Control] */
    unsigned lfrv_gclk_free;                          /* <12> [dv:     0x0000] [des: RealVideo LF GCLK Free Control] */
    unsigned mpavs_gclk_free;                         /* <13> [dv:     0x0000] [des: AVS MP GCLK Free Control] */
    unsigned cc_gclk_free;                            /* <14> [dv:     0x0000] [des: MFD MR Cache GCLK Free Control] */
    unsigned lfbwr_gclk_free;                         /* <15> [dv:     0x0000] [des: MFD LF Bandwidth Reduction GCLK Free Control] */
    unsigned mc2sd_gclk_free;                         /* <16> [dv:     0x0000] [des: MC2SD GCLK Free Control] */
    unsigned chksum_gclk_free;                        /* <17> [dv:     0x0000] [des: MFD Check Sum GCLK Free Control] */
    unsigned grp478_reserved_0;                       /* <18> */
    unsigned grp478_reserved_1;                       /* <19> */
    unsigned grp478_reserved_2;                       /* <20> */
    unsigned grp478_reserved_3;                       /* <21> */
    unsigned grp478_reserved_4;                       /* <22> */
    unsigned grp478_reserved_5;                       /* <23> */
    unsigned grp478_reserved_6;                       /* <24> */
    unsigned grp478_reserved_7;                       /* <25> */
    unsigned grp478_reserved_8;                       /* <26> */
    unsigned grp478_reserved_9;                       /* <27> */
    unsigned grp478_reserved_10;                      /* <28> */
    unsigned grp478_reserved_11;                      /* <29> */
    unsigned grp478_reserved_12;                      /* <30> */
    unsigned grp478_reserved_13;                      /* <31> */
    // GROUP 479 [reserved]
    unsigned dpfu0_fw_pars_ctrl;
    unsigned dpfu0_sfpar_en;
    unsigned dpfu0_r_addr;
    unsigned dpfu0_r_slice_sz;
    unsigned g479_reserved_0;
    unsigned dpfu0_w_addr;
    unsigned dpfu0_w_slice_sz;
    unsigned g479_reserved_1;
    unsigned dpfu0_fw_status;
    unsigned dpfu0_slice_bsize_base;
    unsigned g479_reserved_2[22];
    // GROUP 480 [reserved]
    unsigned dpfu0_get_bits[32];
    // GROUP 481 [reserved]
    unsigned dpfu0_show_bits[32];
    // GROUP 482 [reserved]
    unsigned g482_reseved_0[4];
    unsigned spar0_explicit_weight_parser_enable;
    unsigned spar0_explicit_weight_parsing_end;
    unsigned spar0_profile;
    unsigned spar0_slice_type;
    unsigned spar0_l0_size;
    unsigned spar0_l1_size;
    unsigned spar0_weighted_pred_flag;
    unsigned spar0_weighted_bipred_idc;
    unsigned spar0_luma_log2_wd;
    unsigned spar0_chroma_log2_wd;
    unsigned spar0_wpred_defaultf;
    unsigned spar0_wpred_defaultfc;
    unsigned spar0_wpred_defaultb;
    unsigned spar0_wpred_defaultbc;
    unsigned g482_reseved_1[8];
    unsigned spar0_spmp_base_size_expwt;
    unsigned spar0_spmp_fw_wr_ptr_expwt;
    unsigned g482_reserved_0[4];
    // GROUP 483 [reserved]
    unsigned g483_reserved_0[2];
    unsigned spar0_bits_rd_ctrl;
    unsigned spar0_bits_rd_data;
    unsigned g483_reserved_1;
    unsigned spar0_mailbox;
    unsigned g483_reserved_2[2];
    unsigned spar0_soft_rst;
    unsigned g483_reserved_3[23];
    // GROUP 484
    unsigned grp484_reserved[32];
    // GROUP 485
    unsigned grp485_reserved[32];
    // GROUP 486
    unsigned grp486_reserved[32];
    // GROUP 487
    unsigned grp487_reserved[32];
    // GROUP 488
    unsigned grp488_reserved[32];
    // GROUP 489
    unsigned grp489_reserved[32];
    // GROUP 490
    unsigned grp490_reserved[32];
    // GROUP 491
    unsigned grp491_reserved[32];
    // GROUP 492
    unsigned grp492_reserved[32];
    // GROUP 493
    unsigned grp493_reserved[32];
    // GROUP 494
    unsigned grp494_reserved[32];
    // GROUP 495
    unsigned grp495_reserved[32];
    // GROUP 496
    unsigned grp496_reserved[32];
    // GROUP 497
    unsigned grp497_reserved[32];
    // GROUP 498
    unsigned grp498_reserved[32];
    // GROUP 499
    unsigned grp499_reserved[32];
    // GROUP 500 [rbus_monitor]
    unsigned rbus_monitor_control;                    /* < 0> [dv: 0x0000_0000] [des: Configure RBUS Monitor] */
    unsigned rbus_monitor_event;                      /* < 1> [dv: 0x0000_0000] [des: RBUS Event Monitor] */
    unsigned rbus_timeout_cycle;                      /* < 2> [dv: 0x0000_0000] [des: Configure RBUS Timeout cycle] */
    unsigned rbus_terminate_cycle;                    /* < 3> [dv: 0x0000_0000] [des: Configure RBUS Terminate cycle] */
    unsigned rbus_transaction;                        /* < 4> [dv: 0x0000_0000] [des: Record transaction] */
    unsigned rbus_address;                            /* < 5> [dv: 0x0000_0000] [des: Record address of transaction] */
    unsigned rbus_transaction_1;                      /* < 6> [dv: 0x0000_0000] [des: Record transaction remind] */
    unsigned rbus_part07_freeze;                      /* < 7> [dv: 0x0000_0000] [des: Configure RBUS Partition 07] */
    unsigned rbus_part08_freeze;                      /* < 8> [dv: 0x0000_0000] [des: Configure RBUS Partition 08] */
    unsigned rbus_part09_freeze;                      /* < 9> [dv: 0x0000_0000] [des: Configure RBUS Partition 09] */
    unsigned rbus_part10_freeze;                      /* <10> [dv: 0x0000_0000] [des: Configure RBUS Partition 10] */
    unsigned rbus_part11_freeze;                      /* <11> [dv: 0x0000_0000] [des: Configure RBUS Partition 11] */
    unsigned rbus_part12_freeze;                      /* <12> [dv: 0x0000_0000] [des: Configure RBUS Partition 12] */
    unsigned rbus_part13_freeze;                      /* <13> [dv: 0x0000_0000] [des: Configure RBUS Partition 13] */
    unsigned rbus_part14_freeze;                      /* <14> [dv: 0x0000_0000] [des: Configure RBUS Partition 14] */
    unsigned rbus_part15_freeze;                      /* <15> [dv: 0x0000_0000] [des: Configure RBUS Partition 15] */
    unsigned rbus_part16_freeze;                      /* <16> [dv: 0x0000_0000] [des: Configure RBUS Partition 16] */
    unsigned rbus_part17_freeze;                      /* <17> [dv: 0x0000_0000] [des: Configure RBUS Partition 17] */
    unsigned rbus_part18_freeze;                      /* <18> [dv: 0x0000_0000] [des: Configure RBUS Partition 18] */
    unsigned rbus_part19_freeze;                      /* <19> [dv: 0x0000_0000] [des: Configure RBUS Partition 19] */
    unsigned rbus_part20_freeze;                      /* <20> [dv: 0x0000_0000] [des: Configure RBUS Partition 20] */
    unsigned rbus_part21_freeze;                      /* <21> [dv: 0x0000_0000] [des: Configure RBUS Partition 21] */
    unsigned rbus_part22_freeze;                      /* <22> [dv: 0x0000_0000] [des: Configure RBUS Partition 22] */
    unsigned rbus_part23_freeze;                      /* <23> [dv: 0x0000_0000] [des: Configure RBUS Partition 23] */
    unsigned rbus_part24_freeze;                      /* <24> [dv: 0x0000_0000] [des: Configure RBUS Partition 24] */
    unsigned rbus_part25_freeze;                      /* <25> [dv: 0x0000_0000] [des: Configure RBUS Partition 25] */
    unsigned rbus_part26_freeze;                      /* <26> [dv: 0x0000_0000] [des: Configure RBUS Partition 26] */
    unsigned rbus_part27_freeze;                      /* <27> [dv: 0x0000_0000] [des: Configure RBUS Partition 27] */
    unsigned rbus_part28_freeze;                      /* <28> [dv: 0x0000_0000] [des: Configure RBUS Partition 28] */
    unsigned rbus_part29_freeze;                      /* <29> [dv: 0x0000_0000] [des: Configure RBUS Partition 29] */
    unsigned rbus_part30_freeze;                      /* <30> [dv: 0x0000_0000] [des: Configure RBUS Partition 30] */
    unsigned rbus_part31_freeze;                      /* <31> [dv: 0x0000_0000] [des: Configure RBUS Partition 31] */
    // GROUP 501 [rbus_part]
    unsigned rbus_part00_freeze;                      /* < 0> [dv: 0x0000_0000] [des: Configure RBUS Partition 00] */
    unsigned rbus_part01_freeze;                      /* < 1> [dv: 0x0000_0000] [des: Configure RBUS Partition 01] */
    unsigned rbus_part02_freeze;                      /* < 2> [dv: 0x0000_0000] [des: Configure RBUS Partition 02] */
    unsigned rbus_part03_freeze;                      /* < 3> [dv: 0x0000_0000] [des: Configure RBUS Partition 03] */
    unsigned rbus_part04_freeze;                      /* < 4> [dv: 0x0000_0000] [des: Configure RBUS Partition 04] */
    unsigned rbus_part05_freeze;                      /* < 5> [dv: 0x0000_0000] [des: Configure RBUS Partition 05] */
    unsigned rbus_part06_freeze;                      /* < 6> [dv: 0x0000_0000] [des: Configure RBUS Partition 06] */
    unsigned rbus_part07_freeze_1;                    /* < 7> [dv: 0x0000_0000] [des: Configure RBUS Partition 07] */
    unsigned rbus_part08_freeze_1;                    /* < 8> [dv: 0x0000_0000] [des: Configure RBUS Partition 08] */
    unsigned rbus_part09_freeze_1;                    /* < 9> [dv: 0x0000_0000] [des: Configure RBUS Partition 09] */
    unsigned rbus_part10_freeze_1;                    /* <10> [dv: 0x0000_0000] [des: Configure RBUS Partition 10] */
    unsigned rbus_part11_freeze_1;                    /* <11> [dv: 0x0000_0000] [des: Configure RBUS Partition 11] */
    unsigned rbus_part12_freeze_1;                    /* <12> [dv: 0x0000_0000] [des: Configure RBUS Partition 12] */
    unsigned rbus_part13_freeze_1;                    /* <13> [dv: 0x0000_0000] [des: Configure RBUS Partition 13] */
    unsigned rbus_part14_freeze_1;                    /* <14> [dv: 0x0000_0000] [des: Configure RBUS Partition 14] */
    unsigned rbus_part15_freeze_1;                    /* <15> [dv: 0x0000_0000] [des: Configure RBUS Partition 15] */
    unsigned rbus_part16_freeze_1;                    /* <16> [dv: 0x0000_0000] [des: Configure RBUS Partition 16] */
    unsigned rbus_part17_freeze_1;                    /* <17> [dv: 0x0000_0000] [des: Configure RBUS Partition 17] */
    unsigned rbus_part18_freeze_1;                    /* <18> [dv: 0x0000_0000] [des: Configure RBUS Partition 18] */
    unsigned rbus_part19_freeze_1;                    /* <19> [dv: 0x0000_0000] [des: Configure RBUS Partition 19] */
    unsigned rbus_part20_freeze_1;                    /* <20> [dv: 0x0000_0000] [des: Configure RBUS Partition 20] */
    unsigned rbus_part21_freeze_1;                    /* <21> [dv: 0x0000_0000] [des: Configure RBUS Partition 21] */
    unsigned rbus_part22_freeze_1;                    /* <22> [dv: 0x0000_0000] [des: Configure RBUS Partition 22] */
    unsigned rbus_part23_freeze_1;                    /* <23> [dv: 0x0000_0000] [des: Configure RBUS Partition 23] */
    unsigned rbus_part24_freeze_1;                    /* <24> [dv: 0x0000_0000] [des: Configure RBUS Partition 24] */
    unsigned rbus_part25_freeze_1;                    /* <25> [dv: 0x0000_0000] [des: Configure RBUS Partition 25] */
    unsigned rbus_part26_freeze_1;                    /* <26> [dv: 0x0000_0000] [des: Configure RBUS Partition 26] */
    unsigned rbus_part27_freeze_1;                    /* <27> [dv: 0x0000_0000] [des: Configure RBUS Partition 27] */
    unsigned rbus_part28_freeze_1;                    /* <28> [dv: 0x0000_0000] [des: Configure RBUS Partition 28] */
    unsigned rbus_part29_freeze_1;                    /* <29> [dv: 0x0000_0000] [des: Configure RBUS Partition 29] */
    unsigned rbus_part30_freeze_1;                    /* <30> [dv: 0x0000_0000] [des: Configure RBUS Partition 30] */
    unsigned rbus_part31_freeze_1;                    /* <31> [dv: 0x0000_0000] [des: Configure RBUS Partition 31] */
    // GROUP 502
    unsigned grp502_reserved[32];
    // GROUP 503
    unsigned grp503_reserved[32];
    // GROUP 504
    unsigned grp504_reserved[32];
    // GROUP 505
    unsigned grp505_reserved[32];
    // GROUP 506
    unsigned grp506_reserved[32];
    // GROUP 507
    unsigned grp507_reserved[32];

    //unsigned bg_2d1_index[128];

    // GROUP 508
    // unsigned grp508_reserved[32];
    // GROUP 509
    // unsigned grp509_reserved[32];
    // GROUP 510
    // unsigned grp510_reserved[32];
    // GROUP 511
    // unsigned grp511_reserved[32];
} RegisterFile;


#define RGST0_OFFSET     0x9C000000
#define regs0 ((volatile RegisterFile *)RGST0_OFFSET)

#define HWREG_W(reg, value) ((regs0->reg) = (value))
#define HWREG_R(reg)         (regs0->reg)
#define HWREG_ADDR(reg)      (regs0->reg)

#endif // __8388_REGMAP_H__

