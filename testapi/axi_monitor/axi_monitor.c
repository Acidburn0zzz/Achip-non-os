/********************************************************
 * Copyright (c) 2018 by Sunplus Technology Co., Ltd.
 *    ____               __
 *   / __/_ _____  ___  / /_ _____
 *  _\ \/ // / _ \/ _ \/ / // (_-<
 * /___/\_,_/_//_/ .__/_/\_,_/___/
 *              /_/
 * Sunplus Technology Co. 19, Innovation First Road,
 * Science-Based Industrial Park, Hsin-Chu, Taiwan, R.O.C.
 * ------------------------------------------------------
 *
 * Description :  simple axi monitor driver and test code
 * ------------------------------------------------------
 * Rev  Date          Author(s)      Status & Comments
 * ======================================================
 * 0.1  2018/06/28    nz.lu          initial version
 */
#include "common_all.h"
#include "sp_interrupt.h"
#include "hal_axi_monitor_reg.h"
#include "hal_axi_monitor_sub_reg.h"


void axi_mon_interrupt_control_mask(int enable)
{
	if (enable != 0) {
		/* enable axi mon interrupt */
		hal_interrupt_unmask(103);
	} else {
		hal_interrupt_mask(103);
	}
}


void axi_mon_isr_cfg()
{
	printf("[CFG] AXI MONITOR\n");
	// axi_monitor_regs
	hal_interrupt_configure(103, 0, 1);
}


void axi_mon_callback(void)
{
	reg_axi_monitor_t *axi = axi_monitor_regs;
	reg_axi_monitor_sub_t *axi_sub;
	unsigned int record;

	hal_interrupt_acknowledge(103);

	printf("[AXI] device_id : %d\n", axi->global_monitor_config.bits.device_id);

	switch(axi->global_monitor_config.bits.device_id)
	{
		case 4:
			axi_sub = axi_mon_sub_cbdma0_regs;
			printf("-CBDMA 0:\n");
			break;
		case 5:
			printf("-CBDMA 1:\n");
			axi_sub = axi_mon_sub_cbdma1_regs;
			break;
		case 49:
			printf("-DRAM:\n");
			axi_sub = axi_mon_sub_sd0_regs;
			break;
		default:
			axi_sub = NULL;
			printf("Unknown device id\n");
			break;
	}

	if (axi_sub != NULL) {
		// printf("[AXI] master id record : %d\n", axi_sub->event_info_record.bits.master_id_record);

		if (axi_sub->event_info_record.bits.incomplete_wcmd_flag != 0)
			printf("\t<incomplete_wcmd_flag>\n");
		if (axi_sub->event_info_record.bits.incomplete_rcmd_flag != 0)
			printf("\t<incomplete_rcmd_flag>\n");
		if (axi_sub->event_info_record.bits.special_data != 0)
			printf("\t<special_data>\n");
		if (axi_sub->event_info_record.bits.unexpect_access != 0)
			printf("\t<unexpect_access>\n");
		if (axi_sub->event_info_record.bits.timeout_rdata_ready_N != 0)
			printf("\t<timeout_rdata_ready_N>\n");
		if (axi_sub->event_info_record.bits.timeout_wdata_valid_N != 0)
			printf("\t<timeout_wdata_valid_N>\n");
		if (axi_sub->event_info_record.bits.timout_cmd_wdata_ready_N != 0)
			printf("\t<timout_cmd_wdata_ready_N>\n");
		if (axi_sub->event_info_record.bits.timout_rdata_valid_N != 0)
			printf("\t<timout_rdata_valid_N>\n");

		if (axi->global_monitor_config.bits.bw_mon_start == 1) {
			printf("\tread_bw_ratio  : %d\n", axi_sub->bw_info_record.bits.read_bw_ratio);
			printf("\twrite_bw_ratio : %d\n", axi_sub->bw_info_record.bits.write_bw_ratio);
		}

		if (axi->global_monitor_config.bits.latency_mon_start == 1) {
			printf("          latency_info_wcmd_cnt : %d\n", axi_sub->latency_info_wcmd_cnt);
			printf("latency_info_wcmd_execute_cycle : %d\n", axi_sub->latency_info_wcmd_execute_cycle);
			printf("          latency_info_rcmd_cnt : %d\n", axi_sub->latency_info_rcmd_cnt);
			printf("latency_info_rcmd_execute_cycle : %d\n", axi_sub->latency_info_rcmd_execute_cycle);
		}
	}

	axi->global_monitor_config.bits.event_clear = 1;
	axi_sub->ip_monitor_control.bits.monitor_enable = 0;
}


void axi_mon_test_init()
{
	static interrupt_operation axi_mon_opt;

	memcpy(axi_mon_opt.dev_name, "AXI_MON", strlen("AXI_MON"));
	axi_mon_opt.vector = 103;
	axi_mon_opt.device_config = axi_mon_isr_cfg;
	axi_mon_opt.interrupt_handler = axi_mon_callback;
	interrupt_register(&axi_mon_opt);
}

void axi_mon_unexcept_access_test()
{
	reg_axi_monitor_t *axi = axi_monitor_regs;
	reg_axi_monitor_sub_t *axi_sub = axi_mon_sub_sd0_regs;

	axi->valid_address_start_msb.bits.valid_start_addr_msb = 0x0000;
	axi->valid_address_end_msb.bits.valid_end_addr_msb = 0x0040;

	// bug
	// axi->special_data_config = 0xDEADBEEF;

	axi->global_monitor_config.bits.event_clear = 1;
	// axi->global_monitor_config.bits.latency_mon_start = 1;
	// axi->global_monitor_config.bits.bw_mon_start = 1;

	// axi_sub->ip_monitor_control.bits.monitor_special_data = 1;

	axi_sub->ip_monitor_control.bits.monitor_ue_access = 1;
	axi_sub->ip_monitor_control.bits.monitor_enable = 1;

	axi_mon_interrupt_control_mask(1);
}


#define CBDMA0_SRAM_ADDRESS (0x9E800000) // 40KB
#define CBDMA1_SRAM_ADDRESS (0x9E820000) // 4KB

void axi_mon_timeout_test(unsigned int timeout_cnt)
{
	unsigned int *p = (unsigned int *) CBDMA0_SRAM_ADDRESS;

	reg_axi_monitor_t *axi = axi_monitor_regs;
	reg_axi_monitor_sub_t *axi_cbdma0 = axi_mon_sub_cbdma0_regs;
	reg_axi_monitor_sub_t *axi_dram = axi_mon_sub_sd0_regs;

	// about 4.95ns
	axi->timeout_cycle_config.bits.timeout_cycle = timeout_cnt;
	axi->valid_address_start_msb.bits.valid_start_addr_msb = 0x0000;
	axi->valid_address_end_msb.bits.valid_end_addr_msb = 0xFFFF;

	// about 83ms
	axi->global_monitor_config.bits.bw_update_period = 4;
	axi->global_monitor_config.bits.bw_mon_start = 1;

	axi_cbdma0->ip_monitor_control.bits.monitor_timeout = 1;
	axi_cbdma0->ip_monitor_control.bits.monitor_enable = 1;

	axi_dram->ip_monitor_control.bits.monitor_enable = 1;
	axi_mon_interrupt_control_mask(1);

	cbdma_test();
	printf("\tread_bw_ratio  : %d\n", axi_cbdma0->bw_info_record.bits.read_bw_ratio);
	printf("\twrite_bw_ratio : %d\n", axi_cbdma0->bw_info_record.bits.write_bw_ratio);

	printf("\tread_bw_ratio  : %d\n", axi_dram->bw_info_record.bits.read_bw_ratio);
	printf("\twrite_bw_ratio : %d\n", axi_dram->bw_info_record.bits.write_bw_ratio);

	// disabled cbdma 0
	// MOON0_REG->clken[2] = 0xFFFFFFFE;
	// printf("Try to access CBDMA0 buf by CBDMA1\n");
	// *p = 0xdeadbeef;


}


void axi_mon_bw_test()
{
	reg_axi_monitor_t *axi = axi_monitor_regs;
	reg_axi_monitor_sub_t *axi_cbdma0 = axi_mon_sub_cbdma0_regs;
	reg_axi_monitor_sub_t *axi_dram = axi_mon_sub_sd0_regs;

	printf("[AXI]       event_clear : %d\n", axi->global_monitor_config.bits.event_clear);
	printf("[AXI]      bw_mon_start : %d\n", axi->global_monitor_config.bits.bw_mon_start);
	printf("[AXI] latency_mon_start : %d\n", axi->global_monitor_config.bits.latency_mon_start);
	printf("[AXI]  bw_update_period : %d\n", axi->global_monitor_config.bits.bw_update_period);
	printf("[AXI]         device_id : %d\n", axi->global_monitor_config.bits.device_id);

	printf("[AXI] timeout_cycle : %d\n", axi->timeout_cycle_config.bits.timeout_cycle);

	cbdma_test();

	printf("-CBDMA 0:\n");
	printf("\tread_bw_ratio  : %d\n", axi_cbdma0->bw_info_record.bits.read_bw_ratio);
	printf("\twrite_bw_ratio : %d\n", axi_cbdma0->bw_info_record.bits.write_bw_ratio);

	printf("-DRAM 0:\n");
	printf("\tread_bw_ratio  : %d\n", axi_dram->bw_info_record.bits.read_bw_ratio);
	printf("\twrite_bw_ratio : %d\n", axi_dram->bw_info_record.bits.write_bw_ratio);
}

