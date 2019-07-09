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
 * Description :  q channel test
 * ------------------------------------------------------
 * Rev  Date          Author(s)      Status & Comments
 * ======================================================
 * 0.1  2017/09/12    nz.lu          initial version
 */

#include "common_all.h"
#include <string.h>

#include "hal_iop_reg.h"


#define TICKS	(4500-1)	/* 50ms */
#define ENABLE	(1)
#define DISABLE	(0)

#define ON	(1)
#define OFF	(0)

#define RF_GRP(_grp, _reg) ((((_grp) * 32 + (_reg)) * 4) + REG_BASE)

#define CBDMA_TEST_SOURCE      ((void *) 0x00400000)
#define CBDMA_TEST_DESTINATION ((void *) 0x00C00000)
// #define CBDMA_TEST_SIZE        (128 << 10)
#define CBDMA_TEST_SIZE        (8 << 20)

#define CBDMA0_SRAM_ADDRESS (0x9E800000) // 40KB
#define CBDMA1_SRAM_ADDRESS (0x9E820000) // 4KB

#define INTERNAL_BOOT_ROM_ADDRESS (0x9E000000) // 1MB


unsigned int is_cbdma0_done = FALSE;
unsigned int clock_flipflop = 0;
unsigned int flipflop_cnt = 0;
unsigned int cbdma_clock_onoff = FALSE;

// i137
// #define DENY   (1 << 3)
// #define ACTIVE (1 << 2)
// #define ACCEPT (1 << 1)

#define nQCLKEN (1 << 5)
#define QRESET  (1 << 4)

#define REQUEST (1 << 3)
#define DENY    (1 << 2)
#define ACTIVE  (1 << 1)
#define ACCEPT  (1 << 0)



int __attribute__((optimize("O0"))) qch_access_protect_routine(unsigned int qid,unsigned int onoff)
{
	volatile unsigned int *qch = (unsigned int *)RF_GRP(30, 2);
	int retry_cnt = 100, err_code = -1;
	unsigned int status;

	if (onoff == ON) {
		*qch = RF_MASK_V_SET(REQUEST);
		/**
		 * wait until accept bit == 1
		 * |         | ACCEPT | DENY |
		 * |---------|--------|------|
		 * | Default |      0 |    0 |
		 * | Success |      1 |    0 |
		 * | Fail    |      0 |    1 |
		 */
		while (retry_cnt-- > 0) {
			status = *qch;
			if ((status & ACCEPT) != 0) {
				printf("Accept, 0x%x\n", status & 0xF);
				err_code = 0;
				break;
			}
			if ((status & DENY) != 0) {
				printf("Deny\n");
				break;
			}
		}
	} else {
		*qch = RF_MASK_V_CLR(REQUEST);
		/**
		 * wait until accept bit == 0
		 * |         | ACCEPT | DENY |
		 * |---------|--------|------|
		 * | Default |      1 |    0 |
		 * | Success |      0 |    0 |
		 * | Fail    |      0 |    1 |
		 */
		while (retry_cnt-- > 0) {
			status = *qch;
			if ((status & ACCEPT) == 0) {
				printf("Accept\n");
				err_code = 0;
				break;
			}
			if ((status & DENY) != 0) {
				printf("Deny\n");
				break;
			}
		}
	}

	if (retry_cnt <= 0) {
		printf("Wait ACCEPT timeout. 0x%x\n", *qch);
	}

	if (err_code != 0) {
		*qch = (onoff == ON) ? RF_MASK_V_CLR(REQUEST): RF_MASK_V_SET(REQUEST);
	}

	return err_code;
}


void qch_timer_callback(void)
{
	hal_interrupt_acknowledge(154);
	volatile struct moon0_regs *moon0 = MOON0_REG;
	int rtn;

	if (cbdma_clock_onoff == TRUE) {
		if (clock_flipflop) {
			printf("@on (%d)\n", flipflop_cnt);

			// moon0->clken[2] = 0xFFFFFFFF;
			rtn = qch_access_protect_routine(0, ON);
			if (rtn != 0) {
				// disabled cbdma 0
				// moon0->clken[2] = 0xFFFFFFFE;
			}
		} else {
			printf("@off(%d)\n", flipflop_cnt);
			rtn = qch_access_protect_routine(0, OFF);
			if (rtn == 0) {
				// moon0->clken[2] &= 0xFFFFFFFE;
				flipflop_cnt++;
			}
		}

		if (rtn == 0)
			clock_flipflop = ~clock_flipflop;
	}
}


extern const void *__iop_code_start_addr__;
extern const void *__iop_code_end_addr__;

void qch_initial_settings()
{
	// MOON1_REG->sft_cfg[13] = 0x01afffff;	//set sdramA size [22:21], 00:128MB, 01:256MB, 10:512MB, 11:1024MB
	volatile reg_iop_t *iop = iop_regs;
	unsigned int iop_start, iop_end;

	iop_start = (unsigned int) &__iop_code_start_addr__;
	iop_end = (unsigned int) &__iop_code_end_addr__;

	printf("[DBG] iop_start : 0x%08x\n", iop_start);
	printf("[DBG]   iop_end : 0x%08x\n", iop_end);

#if 0
	char idx;
	unsigned char *dptr = (unsigned char *) iop_start;
	printf("dump position: 0x%08x\n", dptr);
	for(idx = 0; idx < 64; idx++)
	{
		if (idx != 0 && idx % 16 == 0)
			printf("\n");
		printf("%02x ", *(dptr + idx ));
	}
	printf("\n");

	iop->iop_ctrl.bits.reset_ctrl       = 1;
	iop->iop_ctrl.bits.dis_sys_rst_iop  = 0;
	iop->iop_ctrl.bits.watch_dog_rst_en = 0;
	iop->base_addr_l                    = iop_start & 0xFFFF;
	iop->base_addr_h                    = iop_start >> 16;
	iop->iop_ctrl.bits.reset_ctrl       = 0;
#endif
}


void qch_test_iop(int test_id)
{
	volatile reg_iop_t *iop = iop_regs;
	unsigned int i, tmp;
	unsigned int retry_cnt = 0;

	iop->iop_data[9] = 1;

	while(iop->iop_data[9] == 1 && retry_cnt < 4096) {
		if (retry_cnt++ % 16 == 0)
			printf(".");
	}
	printf("\n");

	for (i = 0; i < 12; i++) {
		printf("[DBG] iop_data[%d] : 0x%04x\n", i, iop->iop_data[i]);
	}

}


void qch_host_test(int test_id)
{
	volatile struct moon0_regs *moon0 = MOON0_REG;
	volatile unsigned int *qch = (unsigned int *)RF_GRP(30, 2);

	unsigned int repeat_untill_fail = FALSE;
	unsigned int err = 0, retry_cnt = 0, is_timeout = FALSE;
	int repeat_cnt = -1, rtn;
	unsigned int active_bit;

	printf("[DBG] test_id : %d\n", test_id);

	/**
	 * strange, why enable clken before checking ?
	 */
	if ((moon0->clken[2] & 0x1) == 0) {
		moon0->clken[2] = 0x00010001;
	}

	// enable clk , clear reset
	*qch = RF_MASK_V_SET(nQCLKEN|QRESET);
	// *qch = RF_MASK_V_CLR(QRESET);

	printf("[DBG] Now, Qchannel is running state.\n");
	rtn = qch_access_protect_routine(0, ON);
	if (rtn != 0) {
		printf("[DBG] Open CBDMA0 Fail.\n");
		return;
	}

	if (test_id == 0) {
		/**
		 * one shot and flip cbdma0 clock_en
		 * untill copy procedure finished.
.		 */
		cbdma_clock_onoff = TRUE;
	}

	if (test_id == 1) {
		/**
		 * 10 shots without flip cbdma0 clock_en.
		 */
		repeat_cnt = 0;
	}

	if (test_id == 2) {
		/**
		 * N shots and flip cbdma0 clock_en
		 * untill error occurred
		 */
		cbdma_clock_onoff = TRUE;
		repeat_untill_fail = TRUE;
	}

	// case 0
	// set_sequential_pattern((unsigned int *)CBDMA_TEST_SOURCE, TEST_SIZE);

__RETRY__:
	is_cbdma0_done = FALSE;
	clock_flipflop = 0;

	cbdma_memcpy(0, CBDMA_TEST_DESTINATION, CBDMA_TEST_SOURCE, CBDMA_TEST_SIZE);
	g_cbmda_finished = 0;
	cbdma_interrupt_control_mask(0, 1);
	cbdma_kick_go(0);

	timer3_interrupt_control_mask(1);

	is_timeout = FALSE;
	while (g_cbmda_finished == FALSE) {

		active_bit = *qch & 0x2 != 0;
		printf("[DBG] active_bit : %d\n", active_bit);

		if (flipflop_cnt > 32) {
			printf("Time out\n");
			is_timeout = TRUE;
			break;
		}
	}
	timer3_interrupt_control_mask(0);
	cbdma_interrupt_control_mask(0, 0);

	// if (is_timeout == FALSE)
	// 	err = check_sequential_pattern((unsigned int *)CBDMA_TEST_DESTINATION, TEST_SIZE);

	flipflop_cnt = 0;

	if (repeat_untill_fail == TRUE) {
		if (err == 0 && is_timeout != TRUE) {
			retry_cnt++;
			printf("[DBG] retry_cnt : %d\n", retry_cnt);
			goto __RETRY__;
		}
	}

	if (repeat_cnt-- > 0) {
		retry_cnt++;
		printf("[DBG] retry_cnt : %d\n", retry_cnt);
		goto __RETRY__;
	}

	cbdma_clock_onoff = FALSE;

	rtn = qch_access_protect_routine(0, OFF);
	if (rtn != 0) {
		printf("[DBG] Close CBDMA0 Fail.\n");
		return;
	}
	printf("Done~\n");
}

void load_n_byte_from_cbdma_sram(unsigned int load_len)
{
	char idx;
	volatile unsigned char *dptr = (unsigned char *) CBDMA0_SRAM_ADDRESS;
	printf("dump position: 0x%08x\n", dptr);
	for(idx = 0; idx < load_len; idx++)
	{
		if (idx != 0 && idx % 16 == 0)
			printf("\n");
		printf("%02x ", *(dptr + idx ));
	}
	printf("\n");
}



typedef unsigned long long  u64;

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

#define NOC_REG_BASE     0x9C160000
#define noc_cbdma0_m0_amba_ctrl_regs        ((volatile noc_amba_master_ctrl_regs *) (NOC_REG_BASE + 0x0001bc00))


void qch_device_lead_test(int test_id)
{
	int rtn;
	volatile unsigned int *qch = (unsigned int *)RF_GRP(30, 2);

	volatile unsigned int *cpu_cfg = (unsigned int *)0x9c167c20;

	// test for twofish, check auto wakeup
	volatile noc_amba_master_ctrl_regs *noc = noc_cbdma0_m0_amba_ctrl_regs;

	printf("[DBG] noc cbdma0 cfg: 0x%llx, addr 0x%x\n", noc->cfg, (unsigned int)&noc->cfg);
	// noc->cfg = 0;

	printf("[DBG] cpu_cfg : %d @ 0x%x\n", *cpu_cfg, cpu_cfg);

	*cpu_cfg = 0;

	rtn = qch_access_protect_routine(0, OFF);
	if (rtn != 0) {
		printf("[DBG] Close CBDMA0 Fail.\n");
		return;
	}

	// disable cbdma0 qch clken
	// *qch = RF_MASK_V_CLR(nQCLKEN);

	// disable cbdma clock
	MOON0_REG->clken[2] = 0x00010000;

	printf("Disable cbdma clock done.\n");

	// try to access sram in cbdma.
	load_n_byte_from_cbdma_sram(32);

	rtn = qch_access_protect_routine(0, ON);
	if (rtn != 0) {
		printf("[DBG] Close CBDMA0 Fail.\n");
		return;
	}

}



