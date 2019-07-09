#ifndef __INC_REGMAP_GEMINI_H
#define __INC_REGMAP_GEMINI_H

struct moon0_regs {
	unsigned int stamp;            // 0.0
	unsigned int g0_reserved_0[3]; // 0.1
	unsigned int clk_sel[2];       // 0.4
	unsigned int pllsys_cfg_sel;   // 0.6
	unsigned int clken[5];         // 0.7
	unsigned int gclken[5];        // 0.12
	unsigned int reset[5];         // 0.17
	unsigned int g0_reserved_2[6]; // 0.22
	unsigned int hw_cfg;           // 0.28
	unsigned int sfg_cfg_func;     // 0.29
	unsigned int g0_reserved_3[2]; // 0.30
};
#define MOON0_REG ((volatile struct moon0_regs *)RF_GRP(0, 0))

struct moon1_regs {
	unsigned int sft_cfg[32];
};
#define MOON1_REG ((volatile struct moon1_regs *)RF_GRP(1, 0))

struct moon2_regs {
	unsigned int sft_cfg[32];
};
#define MOON2_REG ((volatile struct moon2_regs *)RF_GRP(2, 0))

struct hb_gp_regs {
        unsigned int hb_otp_data0;
        unsigned int hb_otp_data1;
        unsigned int hb_otp_data2;
        unsigned int hb_otp_data3;
        unsigned int hb_otp_data4;
        unsigned int hb_otp_data5;
        unsigned int hb_otp_data6;
        unsigned int hb_otp_data7;
        unsigned int hb_otp_ctl;
        unsigned int hb_otp_data;
        unsigned int g7_reserved[22];
};
#define HB_GP_REG ((volatile struct hb_gp_regs *)RF_GRP(350, 0))

struct uart_regs {
        unsigned int dr;  /* data register */
        unsigned int lsr; /* line status register */
        unsigned int msr; /* modem status register */
        unsigned int lcr; /* line control register */
        unsigned int mcr; /* modem control register */
        unsigned int div_l;
        unsigned int div_h;
        unsigned int isc; /* interrupt status/control */
        unsigned int txr; /* tx residue */
        unsigned int rxr; /* rx residue */
        unsigned int thr; /* rx threshold */
};
#define UART0_REG    ((volatile struct uart_regs *)RF_GRP(18, 0))
#define UART1_REG    ((volatile struct uart_regs *)RF_GRP(19, 0))
#define UART2_REG    ((volatile struct uart_regs *)RF_GRP(16, 0))
#define UART3_REG    ((volatile struct uart_regs *)RF_GRP(17, 0))
#define UART4_REG    ((volatile struct uart_regs *)RF_GRP(271, 0))
#define UART5_REG    ((volatile struct uart_regs *)RF_GRP(272, 0))

struct uadma_regs {
        unsigned int rf_dma_enable_sel;
        unsigned int rf_dma_start_addr;
        unsigned int rf_dma_timeout_set;
        unsigned int rf_dma_reserved;  //there is no register
        unsigned int rf_dma_wr_adr;
        unsigned int rf_dma_rd_adr;
        unsigned int rf_dma_length_thr;
        unsigned int rf_dma_end_addr;
        unsigned int rf_dma_databytes;
        unsigned int rf_dma_debug_info;
};
#define UADMA0_REG    ((volatile struct uadma_regs *)RF_GRP(275, 0))
#define UADMA1_REG    ((volatile struct uadma_regs *)RF_GRP(275, 16))

struct i2cm_regs {
        unsigned int control0;                 // 00
        unsigned int control1;                 // 01
        unsigned int control2;                 // 02
        unsigned int control3;                 // 03
        unsigned int control4;                 // 04
        unsigned int control5;                 // 05
        unsigned int i2cm_status0;             // 06
        unsigned int int_status;               // 07
        unsigned int int_en0;                  // 08
        unsigned int i2cm_mode;                // 09
        unsigned int i2cm_status1;             // 10
        unsigned int i2cm_status2;             // 11
        unsigned int control6;                 // 12
        unsigned int int_en1;                  // 13
        unsigned int i2cm_status3;             // 14
        unsigned int i2cm_status4;             // 15
        unsigned int int_en2;                  // 16
        unsigned int control7;                 // 17
        unsigned int reserved[6];              // 18~23
        unsigned int data00_03;                // 24
        unsigned int data04_07;                // 25
        unsigned int data08_11;                // 26
        unsigned int data12_15;                // 27
        unsigned int data16_19;                // 28
        unsigned int data20_23;                // 29
        unsigned int data24_27;                // 30
        unsigned int data28_31;                // 31
};

#define I2CM0_REG       ((volatile struct i2cm_regs *)RF_GRP(57, 0))
#define I2CM1_REG       ((volatile struct i2cm_regs *)RF_GRP(58, 0))

struct i2cddc_regs {
        unsigned int reserved_0[5];            // 00 - 04
        unsigned int i2c_sram_addr;            // 05
        unsigned int reserved_1;               // 06
        unsigned int ddc_finish_flag;          // 07
        unsigned int ddc_ctrl1;                // 08
        unsigned int ddc_slvaddr;              // 09
        unsigned int ddc_ctrl2;                // 0a
        unsigned int ddc_sram_data;            // 0b
        unsigned int ddc_set_sram_addr;        // 0c
        unsigned int ddc_rom_addr;             // 0d
        unsigned int ddc_ddc_addr;             // 0e
        unsigned int ddc_test_data;            // 0f
        unsigned int ddc_ddc_i2cslavefilter;   // 10
        unsigned int ddc_null_msg_source;      // 11
        unsigned int ddc_ddcci_ctrl1;          // 12
        unsigned int ddc_ddcci_ctrl2;          // 13
        unsigned int ddc_ddcci_status;         // 14
        unsigned int ddc_ddcci_ctrl3;          // 15
        unsigned int ddc_ddcci_ctrl0;          // 16
        unsigned int ddc_ddcci_ctrl4;          // 17
        unsigned int ddc_ddcci_ctrl5;          // 18
        unsigned int reserved_2[6];            // 19 - 1e
        unsigned int ddc_sram_prob;            // 1f
  };
#define I2CDDC_REG     ((volatile struct i2cddc_regs *)RF_GRP(55, 0))

struct cbdma_regs {
        unsigned int cbdma_hw_ver;       // 0
        unsigned int cbdma_config;       // 1
        unsigned int cbdma_dma_length;   // 2
        unsigned int cbdma_src_adr;      // 3
        unsigned int cbdma_des_adr;      // 4
        unsigned int cbdma_int_status;   // 5
        unsigned int cbdma_int_en;       // 6
        unsigned int cbdma_memset_value; // 7
        //unsigned int ram;  /* SDRAM config */
        unsigned int cbdma_reserved[2];
        unsigned int cbdma_sg_index;
        unsigned int cbdma_sg_config;
        unsigned int cbdma_sg_dma_length;
        unsigned int cbdma_sg_src_adr;
        unsigned int cbdma_sg_des_adr;
        unsigned int cbdma_sg_memset_value;
        unsigned int cbdma_sg_setting;
};

#define CBDMA0_REG      ((volatile struct cbdma_regs *)RF_GRP(26, 0))
#define CBDMA1_REG      ((volatile struct cbdma_regs *)RF_GRP(27, 0))

#endif /* __INC_REGMAP_GEMINI_H */
