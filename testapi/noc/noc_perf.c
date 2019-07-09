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
 * Description :  noc register simple test for i137
 * ------------------------------------------------------
 * Rev  Date          Author(s)      Status & Comments
 * ======================================================
 * 0.1  2017/05/18    nz.lu          initial version
 */

#include <emuio.h>
#include <string.h>
#include "noc_reg.h"
#include "sp_interrupt.h"

#define TICKS	(4500-1)	/* 50ms */
#define ENABLE	(1)
#define DISABLE	(0)

extern const unsigned char longlonglong_table[];

void timer_intr_onoff(int onoff)
{
	if (onoff == ENABLE) {
		/* enable timer0 interrupt */
		hal_interrupt_unmask(154);
	} else {
		hal_interrupt_mask(154);
	}
}


void fs_intr_onoff(int onoff)
{
	if (onoff == ENABLE) {
		hal_interrupt_unmask(0);
	} else {
		hal_interrupt_mask(0);
	}
}


void noc_perf_fs(void)
{
	hal_interrupt_acknowledge(0);
	printf("@\n");
	return;
}

void noc_perf_log(void)
{
	hal_interrupt_acknowledge(154);
	printf("@timer\n");
	return;
}


void noc_perf(int onoff)
{
	if (onoff == ENABLE) {
		noc_disp_ddfch_amba_ctrl_regs->caddr = (unsigned)longlonglong_table;
		noc_disp_ddfch_amba_ctrl_regs->caddrmsk = 0x2FFFF;
		// typ:bit 32, 0 count captured command
		noc_disp_ddfch_amba_ctrl_regs->cmd_cap[0].ccmdmsk = 0x0;
		noc_disp_ddfch_amba_ctrl_regs->cmd_cap[0].ccmd    = 0x121000000;
		noc_disp_ddfch_amba_ctrl_regs->cmd_cap[0].ccmdmsk = 0x01000000;
		noc_disp_ddfch_amba_ctrl_regs->cmd_cap[0].cntr = 0;

		noc_sdctrl_sd0_amba_ctrl_regs->ccmd    = 0x31000000;
		noc_sdctrl_sd0_amba_ctrl_regs->ccmdmsk = 0x01000000;
		noc_sdctrl_sd0_amba_ctrl_regs->cntr = 0;

		// timer_intr_onoff(ENABLE);
		printf("Start ...\n");
	} else {
		fs_intr_onoff(DISABLE);
		timer_intr_onoff(DISABLE);
		noc_disp_ddfch_amba_ctrl_regs->cmd_cap[0].ccmdmsk = 0x0;
	}

	// typ:bit 32, 1 count response latency
	// noc_disp_ddfch_amba_ctrl_regs->cmd_cap[1].ccmd = 0x123FFF33F;
	// noc_disp_ddfch_amba_ctrl_regs->cmd_cap[1].ccmdmsk = 0x03FFF33F;
}



#define CBDMA_TEST_SOURCE      (0x0300000)
#define CBDMA_TEST_DESTINATION (0x1300000)

unsigned int is_cbdma0_done = FALSE;



void noc_cbdma_test(int case_number)
{
	unsigned int status;

	noc_cbdma0_m0_amba_ctrl_regs->caddr = (unsigned)longlonglong_table;
	noc_cbdma0_m0_amba_ctrl_regs->caddrmsk = 0xFFFFFF;
	// typ:bit 32, 0 count captured command
	noc_cbdma0_m0_amba_ctrl_regs->cmd_cap[0].ccmdmsk = 0x0;
	noc_cbdma0_m0_amba_ctrl_regs->cmd_cap[0].ccmd    = 0x23FFF33F;
	noc_cbdma0_m0_amba_ctrl_regs->cmd_cap[0].ccmdmsk = 0x03FFF33F;
	noc_cbdma0_m0_amba_ctrl_regs->cmd_cap[0].cntr = 0;

	MOON1_REG->sft_cfg[13] = 0x01afffff;	//set sdramA size [22:21], 00:128MB, 01:256MB, 10:512MB, 11:1024MB

	STC_REG->timer3_ctl = 0x7;
	STC_REG->timer3_pres_val = 0;
	STC_REG->timer3_reload = 63000 - 1;
	STC_REG->timer3_cnt = 63000 - 1;

	cbdma0_intr_onoff(ENABLE);

	is_cbdma0_done = FALSE;
	// case 0
	cbdma_cfg_memcpy(0, CBDMA_TEST_DESTINATION, CBDMA_TEST_SOURCE, 16<<20);
	cbdma_kick_go(0);

}





