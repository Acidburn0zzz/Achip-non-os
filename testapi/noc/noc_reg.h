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
 * Description :  noc register header for i137
 * ------------------------------------------------------
 * Rev  Date          Author(s)      Status & Comments
 * ======================================================
 * 0.1  2017/05/18    nz.lu          initial version
 */
#ifndef __NOC_REG_H__
#define __NOC_REG_H__

// #ifndef __HAS_LONG_LONG__
typedef unsigned long long  u64;
// #endif

typedef unsigned int  u32;

#ifndef RGST0_OFFSET
#define RGST0_OFFSET     0x9C160000
#endif

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                 struct define                                                            //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// AHB2AXI Converter Registers
typedef struct st_noc_ahbm_regs {
	u64 ctl;            // [RW] Control Register
	u64 sts;            // [WZC] Status Register
	u64 im;             // [RW] Interrupt Mask Register
} noc_ahbm_regs;

// NO USE
// AXI2AHB Converter Registers
// typedef struct st_noc_ahbs_regs {
//     u64 ctl;            // [RW] Control Register
//     u64 sts;            // [WZC] Status Register
//     u64 im;             // [RW] Interrupt Mask Register
// } noc_ahbs_regs;

typedef struct st_noc_router_regs {
	u64 re;             // [WZC] Router Event Interrupt Status
	u64 rem;            // [RW] Router Event Interrupt Mask
	u64 reserved_0[2];  // -
	u64 id;             // [R] Router ID
	u64 reserved_1;     // -
	u64 rcgo;           // [RW] Router Clock Gating Override
} noc_router_regs;

typedef struct st_noc_bridge_regs {
	u64 p[4];           // [RW] QoS Profile Data
	u64 reserved_0[4];  // -
	u64 txe;            // [WZC]
	u64 txem;           // [RW]
	u64 reserved_1;     // -
	u64 btus[2];        // [R] Bridge Tx Upsizer Status
	u64 reserved_2[2];  // -
	u64 txid;           // [R] Tx Bridge ID
	u64 btrl[4];        // [RW] Streaming TX Rate Limiter
	u64 reserved_3;     // -
	u64 btperr;         // [WZC] Credit parity error on each layer
	u64 btperrm;        // [RW] Interrupt Mask Credit parity error on each layer
	u64 reserved_4[13]; // -
	u64 rxe;            // [WZC]
	u64 rxem;           // [RW]
	u64 brs[16];        // [R] Bridge Receive FIFO Status
	u64 brus;           // [R] Bridge Rx Upsizer Status
	u64 rxid;           // [R] Rx Bridge ID
	u64 reserved_5[2];  // -
	u64 brperr[2];      // [WZC] Receive layer ECC/Parity errors
	u64 brperrm[2];     // [RW] Receive layer ECC/Parity errors Masks
} noc_bridge_regs;

typedef struct st_noc_bridge_no_pf_regs {
	u64 btus[2];        // [R] Bridge Tx Upsizer Status
	u64 reserved_2[2];  // -
	u64 txid;           // [R] Tx Bridge ID
	u64 btrl[4];        // [RW] Streaming TX Rate Limiter
	u64 reserved_3;     // -
	u64 btperr;         // [WZC] Credit parity error on each layer
	u64 btperrm;        // [RW] Interrupt Mask Credit parity error on each layer
	u64 reserved_4[13]; // -
	u64 rxe;            // [WZC]
	u64 rxem;           // [RW]
	u64 brs[16];        // [R] Bridge Receive FIFO Status
	u64 brus;           // [R] Bridge Rx Upsizer Status
	u64 rxid;           // [R] Rx Bridge ID
	u64 reserved_5[2];  // -
	u64 brperr[2];      // [WZC] Receive layer ECC/Parity errors
	u64 brperrm[2];     // [RW] Receive layer ECC/Parity errors Masks
} noc_bridge_no_pf_regs;

typedef struct st_noc_amba_master_addr_regs {
	struct {
		u64 adbase;     // [RW] Base Address Register
		u64 admask;     // [RW] Address Mask Register
		u64 reserved[2];
	} amba_addr[16];
} noc_amba_master_addr_regs;

typedef struct st_noc_amba_master_ctrl_regs {
	u64 tocfg;           // [RW] Timeout Configuration Register
	u64 osslv;           // [RW] Check Outstanding to Specified Slave Register
	u64 cgc;             // [RW] Clock Gating Hysteresis Counter Register
	u64 cgo;             // [RW] Clock Gating Override Register
	u64 cfg;             // [RW] Configurations Register
	u64 reserved_0[27];  // -
	u64 sts;             // [R] Status Flags Register
	u64 bridge_id;       // [R] Bridge ID Register
	u64 reserved_1[30];  // -
	u64 err;             // [WZC] Status and Error Register
	u64 toslvid;         // [R] Slave ID of Timed Out Requests Register
	u64 era;             // [R] Local Read Decode Error Address Register
	u64 ewa;             // [R] Local Write Decode Error Address Register
	u64 reserved_2[4];   // -
	u64 intm;            // [RW] Interrupt Mask Register
	u64 reserved_3[23];  // -
	u64 caddr;           // [RW] Address Capture Value Register
	u64 caddrmsk;        // [RW] Address Capture Mask Register
	struct noc_cmd_cap { //
		u64 ccmd;        // [RW] Command Capture Control Register
		u64 ccmdmsk;     // [RW] Command Capture Mask Register
		u64 cntr;        // [RW] Count of Captured Events Register
		u64 latnum;      // [RW] Number of Captured Commands over which Latency is to be Measured Register
	} cmd_cap[2];        //
	u64 reserved_4[2];   // -
	u64 arovrd;          // [RW] AR Overrides
	u64 awovrd;          // [RW] AW Overrides
} noc_amba_master_ctrl_regs;

typedef struct st_noc_amba_slave_ctrl_regs {
	u64 cgc;            // [RW] Clock Gating Hysteresis Counter Register
	u64 cgo;            // [RW] Clock Gating Override Register
	u64 reserved_0[28]; // -
	u64 sts;            // [R] Status Flags Register
	u64 bridge_id;      // [R] Bridge ID Register
	u64 reserved_1[30]; // -
	u64 err;            // [WZC] Status and Error Register
	u64 reserved_2[7];  // -
	u64 intm;           // [RW] Interrupt Mask Register
	u64 reserved_3[23]; // -
	u64 ccmd;           // [RW] Command Capture Control Register
	u64 ccmdmsk;        // [RW] Command Capture Mask Register
	u64 cntr;           // [RW] Count of Captured Events Register
	u64 arovrd;         // [RW] AR Overrides
	u64 awovrd;         // [RW] AW Overrides
} noc_amba_slave_ctrl_regs;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                 routers                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * ALL ROUTERS
 * router_0_34, router_0_37, router_0_54, router_0_55, router_0_57, router_0_65, router_0_77, router_2_54
 * router_2_55, router_2_56, router_2_57, router_2_65, router_2_77
 */

#define noc_router_router_0_34_regs         ((volatile noc_router_regs *) (RGST0_OFFSET + 0x54080))
#define noc_router_router_0_37_regs         ((volatile noc_router_regs *) (RGST0_OFFSET + 0x58080))
#define noc_router_router_0_54_regs         ((volatile noc_router_regs *) (RGST0_OFFSET + 0x5C080))
#define noc_router_router_0_55_regs         ((volatile noc_router_regs *) (RGST0_OFFSET + 0x60080))
#define noc_router_router_0_57_regs         ((volatile noc_router_regs *) (RGST0_OFFSET + 0x64080))
#define noc_router_router_0_65_regs         ((volatile noc_router_regs *) (RGST0_OFFSET + 0x68080))
#define noc_router_router_0_77_regs         ((volatile noc_router_regs *) (RGST0_OFFSET + 0x6C080))
#define noc_router_router_2_54_regs         ((volatile noc_router_regs *) (RGST0_OFFSET + 0x70080))
#define noc_router_router_2_55_regs         ((volatile noc_router_regs *) (RGST0_OFFSET + 0x74080))
#define noc_router_router_2_56_regs         ((volatile noc_router_regs *) (RGST0_OFFSET + 0x78080))
#define noc_router_router_2_57_regs         ((volatile noc_router_regs *) (RGST0_OFFSET + 0x7C080))
#define noc_router_router_2_65_regs         ((volatile noc_router_regs *) (RGST0_OFFSET + 0x80080))
#define noc_router_router_2_77_regs         ((volatile noc_router_regs *) (RGST0_OFFSET + 0x84080))


/**
 * ALL BRIDGES
 * a926_d0, a926_i0, cbdma0_m0, cbdma0_s0, disp_ddfch, ioctrl_m0, sib2_m, iop_m0
 * pbus0_m0, sib1_m, sdctrl_sd0, spi_br_br, spi_br_rb, spi_br_s0, u3f_m0, usb_m0
 * usb_m1, sib3_m, rbm_m
 */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                              master bridges                                              //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * ALL MASTER BRIDGES
 * a926_d0, a926_i0, cbdma0_m0, disp_ddfch, ioctrl_m0, sib2_m, iop_m0, pbus0_m0
 * sib1_m, u3f_m0, usb_m0, usb_m1, sib3_m, rbm_m
 */

// a926_d0
#define noc_a926_d0_ahbm_regs               ((volatile noc_ahbm_regs *)             (RGST0_OFFSET + 0x8200))
#define noc_a926_d0_amba_addr_regs          ((volatile noc_amba_master_addr_regs *) (RGST0_OFFSET + 0x4400))
#define noc_a926_d0_amba_ctrl_regs          ((volatile noc_amba_master_ctrl_regs *) (RGST0_OFFSET + 0x7C00))
#define noc_a926_d0_brdg_regs               ((volatile noc_bridge_regs *)           (RGST0_OFFSET + 0x4000))

// a926_i0
#define noc_a926_i0_ahbm_regs               ((volatile noc_ahbm_regs *)             (RGST0_OFFSET + 0x10200))
#define noc_a926_i0_amba_addr_regs          ((volatile noc_amba_master_addr_regs *) (RGST0_OFFSET + 0xC400))
#define noc_a926_i0_amba_ctrl_regs          ((volatile noc_amba_master_ctrl_regs *) (RGST0_OFFSET + 0xFC00))
#define noc_a926_i0_brdg_regs               ((volatile noc_bridge_regs *)           (RGST0_OFFSET + 0xC000))

// cbdma0_m0
#define noc_cbdma0_m0_amba_addr_regs        ((volatile noc_amba_master_addr_regs *) (RGST0_OFFSET + 0x14400))
#define noc_cbdma0_m0_amba_ctrl_regs        ((volatile noc_amba_master_ctrl_regs *) (RGST0_OFFSET + 0x17C00))
#define noc_cbdma0_m0_brdg_regs             ((volatile noc_bridge_regs *)           (RGST0_OFFSET + 0x14000))

// disp_ddfch
#define noc_disp_ddfch_amba_addr_regs       ((volatile noc_amba_master_addr_regs *) (RGST0_OFFSET + 0x1C400))
#define noc_disp_ddfch_amba_ctrl_regs       ((volatile noc_amba_master_ctrl_regs *) (RGST0_OFFSET + 0x1FC00))
#define noc_disp_ddfch_brdg_regs            ((volatile noc_bridge_regs *)           (RGST0_OFFSET + 0x1C000))

// ioctrl_m0
#define noc_ioctrl_m0_amba_addr_regs        ((volatile noc_amba_master_addr_regs *) (RGST0_OFFSET + 0x20400))
#define noc_ioctrl_m0_amba_ctrl_regs        ((volatile noc_amba_master_ctrl_regs *) (RGST0_OFFSET + 0x23C00))
#define noc_ioctrl_m0_brdg_regs             ((volatile noc_bridge_regs *)           (RGST0_OFFSET + 0x20000))

// sib2_m
#define noc_sib2_m_amba_addr_regs           ((volatile noc_amba_master_addr_regs *) (RGST0_OFFSET + 0x34400))
#define noc_sib2_m_amba_ctrl_regs           ((volatile noc_amba_master_ctrl_regs *) (RGST0_OFFSET + 0x37C00))
#define noc_sib2_m_brdg_regs                ((volatile noc_bridge_regs *)           (RGST0_OFFSET + 0x34000))

// iop_m0
#define noc_iop_m0_amba_addr_regs           ((volatile noc_amba_master_addr_regs *) (RGST0_OFFSET + 0x24400))
#define noc_iop_m0_amba_ctrl_regs           ((volatile noc_amba_master_ctrl_regs *) (RGST0_OFFSET + 0x27C00))
#define noc_iop_m0_brdg_regs                ((volatile noc_bridge_regs *)           (RGST0_OFFSET + 0x24000))

// pbus0_m0
#define noc_pbus0_m0_amba_addr_regs         ((volatile noc_amba_master_addr_regs *) (RGST0_OFFSET + 0x28400))
#define noc_pbus0_m0_amba_ctrl_regs         ((volatile noc_amba_master_ctrl_regs *) (RGST0_OFFSET + 0x2BC00))
#define noc_pbus0_m0_brdg_regs              ((volatile noc_bridge_regs *)           (RGST0_OFFSET + 0x28000))

// sib1_m
#define noc_sib1_m_amba_addr_regs           ((volatile noc_amba_master_addr_regs *) (RGST0_OFFSET + 0x30400))
#define noc_sib1_m_amba_ctrl_regs           ((volatile noc_amba_master_ctrl_regs *) (RGST0_OFFSET + 0x33C00))
#define noc_sib1_m_brdg_regs                ((volatile noc_bridge_regs *)           (RGST0_OFFSET + 0x30000))

// u3f_m0
#define noc_u3f_m0_amba_addr_regs           ((volatile noc_amba_master_addr_regs *) (RGST0_OFFSET + 0x48400))
#define noc_u3f_m0_amba_ctrl_regs           ((volatile noc_amba_master_ctrl_regs *) (RGST0_OFFSET + 0x4BC00))
#define noc_u3f_m0_brdg_regs                ((volatile noc_bridge_regs *)           (RGST0_OFFSET + 0x48000))

// usb_m0
#define noc_usb_m0_amba_addr_regs           ((volatile noc_amba_master_addr_regs *) (RGST0_OFFSET + 0x4C400))
#define noc_usb_m0_amba_ctrl_regs           ((volatile noc_amba_master_ctrl_regs *) (RGST0_OFFSET + 0x4FC00))
#define noc_usb_m0_brdg_regs                ((volatile noc_bridge_regs *)           (RGST0_OFFSET + 0x4C000))

// usb_m1
#define noc_usb_m1_amba_addr_regs           ((volatile noc_amba_master_addr_regs *) (RGST0_OFFSET + 0x50400))
#define noc_usb_m1_amba_ctrl_regs           ((volatile noc_amba_master_ctrl_regs *) (RGST0_OFFSET + 0x53C00))
#define noc_usb_m1_brdg_regs                ((volatile noc_bridge_regs *)           (RGST0_OFFSET + 0x50000))

// sib3_m
#define noc_sib3_m_amba_addr_regs           ((volatile noc_amba_master_addr_regs *) (RGST0_OFFSET + 0x38400))
#define noc_sib3_m_amba_ctrl_regs           ((volatile noc_amba_master_ctrl_regs *) (RGST0_OFFSET + 0x3BC00))
#define noc_sib3_m_brdg_regs                ((volatile noc_bridge_regs *)           (RGST0_OFFSET + 0x38000))

// rbm_m
#define noc_rbm_m_amba_ctrl_regs            ((volatile noc_amba_master_ctrl_regs *) (RGST0_OFFSET + 0x3C00))
#define noc_rbm_m_brdg_regs                 ((volatile noc_bridge_no_pf_regs *)     (RGST0_OFFSET + 0x58))



//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                              slave bridges                                               //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * ALL SLAVE BRIDGES
 * cbdma0_s0, sdctrl_sd0, spi_br_br, spi_br_rb, spi_br_s0
 */

// cbdma0_s0
#define noc_cbdma0_s0_amba_ctrl_regs        ((volatile noc_amba_slave_ctrl_regs *) (RGST0_OFFSET + 0x19C10))
#define noc_cbdma0_s0_brdg_regs             ((volatile noc_bridge_regs *)          (RGST0_OFFSET + 0x18000))

// sdctrl_sd0
#define noc_sdctrl_sd0_amba_ctrl_regs       ((volatile noc_amba_slave_ctrl_regs *) (RGST0_OFFSET + 0x2DC10))
#define noc_sdctrl_sd0_brdg_regs            ((volatile noc_bridge_regs *)          (RGST0_OFFSET + 0x2C000))

// spi_br_br
#define noc_spi_br_br_amba_ctrl_regs        ((volatile noc_amba_slave_ctrl_regs *) (RGST0_OFFSET + 0x3DC10))
#define noc_spi_br_br_brdg_regs             ((volatile noc_bridge_regs *)          (RGST0_OFFSET + 0x3C000))

// spi_br_rb
#define noc_spi_br_rb_amba_ctrl_regs        ((volatile noc_amba_slave_ctrl_regs *) (RGST0_OFFSET + 0x41C10))
#define noc_spi_br_rb_brdg_regs             ((volatile noc_bridge_regs *)          (RGST0_OFFSET + 0x40000))

// spi_br_s0
#define noc_spi_br_s0_amba_ctrl_regs        ((volatile noc_amba_slave_ctrl_regs *) (RGST0_OFFSET + 0x45C10))
#define noc_spi_br_s0_brdg_regs             ((volatile noc_bridge_regs *)          (RGST0_OFFSET + 0x44000))



//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                       AMBA address base enumerate                                        //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

enum a926_d0_addr_index_list {
	A926_D0_ADDR_MEM_CBDMA0_S0_CBDMA0_RANGE_0,
	A926_D0_ADDR_MEM_SDCTRL_SD0_DRAM_RANGE_0,
	A926_D0_ADDR_MEM_SPI_BR_BR_BR_RANGE0_0,
	A926_D0_ADDR_MEM_SPI_BR_BR_BR_RANGE1_0,
	A926_D0_ADDR_MEM_SPI_BR_RB_RBUS_RANGE_0,
	A926_D0_ADDR_MEM_SPI_BR_S0_SPI_RANG_0,
	A926_D0_ADDR_INDEX_MAX
};

enum a926_i0_addr_index_list {
	A926_I0_ADDR_MEM_CBDMA0_S0_CBDMA0_RANGE_0,
	A926_I0_ADDR_MEM_SDCTRL_SD0_DRAM_RANGE_0,
	A926_I0_ADDR_MEM_SPI_BR_BR_BR_RANGE0_0,
	A926_I0_ADDR_MEM_SPI_BR_BR_BR_RANGE1_0,
	A926_I0_ADDR_MEM_SPI_BR_RB_RBUS_RANGE_0,
	A926_I0_ADDR_MEM_SPI_BR_S0_SPI_RANG_0,
	A926_I0_ADDR_INDEX_MAX
};

enum cbdma0_m0_addr_index_list {
	CBDMA0_M0_ADDR_MEM_SDCTRL_SD0_DRAM_RANGE_0,
	CBDMA0_M0_ADDR_INDEX_MAX
};

enum disp_ddfch_addr_index_list {
	DISP_DDFCH_ADDR_MEM_SDCTRL_SD0_DRAM_RANGE_0,
	DISP_DDFCH_ADDR_INDEX_MAX
};

enum ioctrl_m0_addr_index_list {
	IOCTRL_M0_ADDR_MEM_SDCTRL_SD0_DRAM_RANGE_0,
	IOCTRL_M0_ADDR_INDEX_MAX
};

enum sib2_m_addr_index_list {
	SIB2_M_ADDR_MEM_CBDMA0_S0_CBDMA0_RANGE_0,
	SIB2_M_ADDR_MEM_SDCTRL_SD0_DRAM_RANGE_0,
	SIB2_M_ADDR_MEM_SPI_BR_BR_BR_RANGE0_0,
	SIB2_M_ADDR_MEM_SPI_BR_BR_BR_RANGE1_0,
	SIB2_M_ADDR_MEM_SPI_BR_RB_RBUS_RANGE_0,
	SIB2_M_ADDR_MEM_SPI_BR_S0_SPI_RANG_0,
	SIB2_M_ADDR_INDEX_MAX
};

enum iop_m0_addr_index_list {
	IOP_M0_ADDR_MEM_CBDMA0_S0_CBDMA0_RANGE_0,
	IOP_M0_ADDR_MEM_SDCTRL_SD0_DRAM_RANGE_0,
	IOP_M0_ADDR_MEM_SPI_BR_BR_BR_RANGE0_0,
	IOP_M0_ADDR_MEM_SPI_BR_BR_BR_RANGE1_0,
	IOP_M0_ADDR_MEM_SPI_BR_RB_RBUS_RANGE_0,
	IOP_M0_ADDR_MEM_SPI_BR_S0_SPI_RANG_0,
	IOP_M0_ADDR_INDEX_MAX
};

enum pbus0_m0_addr_index_list {
	PBUS0_M0_ADDR_MEM_SDCTRL_SD0_DRAM_RANGE_0,
	PBUS0_M0_ADDR_INDEX_MAX
};

enum sib1_m_addr_index_list {
	SIB1_M_ADDR_MEM_SDCTRL_SD0_DRAM_RANGE_0,
	SIB1_M_ADDR_INDEX_MAX
};

enum u3f_m0_addr_index_list {
	U3F_M0_ADDR_MEM_CBDMA0_S0_CBDMA0_RANGE_0,
	U3F_M0_ADDR_MEM_SDCTRL_SD0_DRAM_RANGE_0,
	U3F_M0_ADDR_MEM_SPI_BR_BR_BR_RANGE0_0,
	U3F_M0_ADDR_MEM_SPI_BR_BR_BR_RANGE1_0,
	U3F_M0_ADDR_MEM_SPI_BR_RB_RBUS_RANGE_0,
	U3F_M0_ADDR_MEM_SPI_BR_S0_SPI_RANG_0,
	U3F_M0_ADDR_INDEX_MAX
};

enum usb_m0_addr_index_list {
	USB_M0_ADDR_MEM_SDCTRL_SD0_DRAM_RANGE_0,
	USB_M0_ADDR_INDEX_MAX
};

enum usb_m1_addr_index_list {
	USB_M1_ADDR_MEM_CBDMA0_S0_CBDMA0_RANGE_0,
	USB_M1_ADDR_MEM_SDCTRL_SD0_DRAM_RANGE_0,
	USB_M1_ADDR_INDEX_MAX
};

enum sib3_m_addr_index_list {
	SIB3_M_ADDR_MEM_SDCTRL_SD0_DRAM_RANGE_0,
	SIB3_M_ADDR_INDEX_MAX
};

#endif // #ifndef __NOC_REG_H__
