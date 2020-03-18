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
 * Description :  nonos spi nor function
 * ------------------------------------------------------
 * Rev  Date          Author(s)      Status & Comments
 * ======================================================
 * 0.1  2020/03/13    chingchouhuang   initial version
 */
#include <stdarg.h>
#include <string.h>
#include <common_all.h>
#include "drivers/sp_spi_nor.h"

UINT8 cmd_buf[CMD_BUF_LEN];
static UINT32 cmd_len;
UINT8 data_pool[SPI_DATA64_MAX_LEN];

//int AV1_GetStc32(void)
//{
	//TBD
//	return 0;
//}

static void spi_nor_io_CUST_config(UINT8 cmd_b, UINT8 addr_b, UINT8 data_b, SPI_ENHANCE enhance,UINT8 dummy)
{
	UINT32 config;

	if (enhance.enhance_en == 1) {
		config = SPI_CTRL_REG->spi_cfg[0]  & CLEAR_ENHANCE_DATA;
		if (enhance.enhance_bit == 4) {
			config &= ~(1<<18);
		} else if (enhance.enhance_bit == 8) {
			config |= (1<<18);
		}
		SPI_CTRL_REG->spi_cfg[0] = config | ENHANCE_DATA(enhance.enhance_data);
	}

	config = 0;
	switch (cmd_b) {
	case 4:
		config |= SPI_CMD_4b | SPI_CMD_OEN_4b;
		break;
	case 2:
		config |= SPI_CMD_2b | SPI_CMD_OEN_2b;
		break;
	case 1:
		config |= SPI_CMD_1b | SPI_CMD_OEN_1b;
		break;
	case 0:
	default:
		config |= SPI_CMD_NO | SPI_CMD_OEN_NO;
		break;
	}

	switch (addr_b) {
	case 4:
		config |= SPI_ADDR_4b | SPI_ADDR_OEN_4b;
		break;
	case 2:
		config |= SPI_ADDR_2b | SPI_ADDR_OEN_2b;
		break;
	case 1:
		config |= SPI_ADDR_1b | SPI_ADDR_OEN_1b;
		break;
	case 0:
	default:
		config |= SPI_ADDR_NO | SPI_ADDR_OEN_NO;
		break;
	}

	switch (data_b) {
	case 4:
		config |= SPI_DATA_4b | SPI_DATA_OEN_4b;
		break;
	case 2:
		config |= SPI_DATA_2b | SPI_DATA_OEN_2b;
		break;
	case 1:
		config |= SPI_DATA_1b | SPI_DATA_OEN_1b | SPI_DATA_IEN_DQ1;
		break;
	case 0:
	default:
		config |= SPI_DATA_NO | SPI_DATA_OEN_NO;
		break;
	}

	switch (enhance.enhance_bit_mode) {
	case 4:
		config |= SPI_ENHANCE_4b;
		break;
	case 2:
		config |= SPI_ENHANCE_2b;
		break;
	case 1:
		config |= SPI_ENHANCE_1b;
		break;
	case 0:
	default:
		config |= SPI_ENHANCE_NO;
		break;
	}

	SPI_CTRL_REG->spi_cfg[1] = config | SPI_DUMMY_CYC(dummy);
	SPI_CTRL_REG->spi_cfg[2] = config | SPI_DUMMY_CYC(dummy);
}

#if (SP_SPINOR_DMA)
static void spi_readcmd_set(UINT8 cmd)
{
	SPI_ENHANCE enhance;

	enhance.enhance_en = 0;
	enhance.enhance_bit_mode = 0;
	diag_printf("%s\n",__FUNCTION__);

	switch (cmd) {
	case 0x0B:
		spi_nor_io_CUST_config(CMD_1,ADDR_1,DATA_1,enhance,DUMMY_CYCLE(8));
		break;
	case 0x3B:
		spi_nor_io_CUST_config(CMD_1,ADDR_1,DATA_2,enhance,DUMMY_CYCLE(8));
		break;
	case 0x6B:
		spi_nor_io_CUST_config(CMD_1,ADDR_1,DATA_4,enhance,DUMMY_CYCLE(8));
		break;
	case 0xBB:
		spi_nor_io_CUST_config(CMD_1,ADDR_2,DATA_2,enhance,DUMMY_CYCLE(4));
		break;
	case 0xEB:
		spi_nor_io_CUST_config(CMD_1,ADDR_4,DATA_4,enhance,DUMMY_CYCLE(6));
		break;
	case 0x32:
		spi_nor_io_CUST_config(CMD_1,ADDR_1,DATA_4,enhance,DUMMY_CYCLE(0));
		break;
	default:
		spi_nor_io_CUST_config(CMD_1,ADDR_1,DATA_1,enhance,DUMMY_CYCLE(0));
		break;
	}
}

static int spi_flash_xfer_DMAread(struct sp_spi_nor_priv *priv,UINT8 *cmd, UINT32 cmd_len, void *data, UINT32 data_len)
{
	UINT32 addr_temp = 0;
	UINT8 *data_in = data;
	UINT32 time = 0;
	UINT32 ctrl = 0;
	UINT32 autocfg = 0;
	UINT32 temp_len = 0;
	int value = 0;
	struct spinorbufdesc *desc_r = &priv->rchain;
	ulong data_end;

	diag_printf("%s\n",__FUNCTION__);
	msg_printf("DMA read :data length 0x%x cmd_len 0x%x, cmd[0] 0x%x\n",data_len, cmd_len, cmd[0]);
	while ((SPI_CTRL_REG->spi_auto_cfg & DMA_TRIGGER) ||  (SPI_CTRL_REG->spi_ctrl & SPI_CTRL_BUSY)) {
		time++;
		if (time > 0x30000) {
			 msg_printf("##busy check time out: spi_auto_cfg 0x%x spi_ctrl 0x%x\n", SPI_CTRL_REG->spi_auto_cfg, SPI_CTRL_REG->spi_ctrl);
			 break;
		}
	}

	data_end = desc_r->phys + CFG_BUFF_MAX;
	msg_printf("data length %d buff size 0x%x\n",data_len, desc_r->size);

	spi_readcmd_set(cmd[0]);

	ctrl = SPI_CTRL_REG->spi_ctrl & (CLEAR_CUST_CMD & (~(1<<19)));
	ctrl |= (READ | BYTE_0 | ADDR_0B);

	//SPI_CTRL_REG->spi_page_addr = 0;
	SPI_CTRL_REG->spi_data = 0;
	if (cmd_len > 1) {
		addr_temp = (cmd[1] << 16) | (cmd[2] << 8) | cmd[3];
		ctrl |= ADDR_3B;
	}

	SPI_CTRL_REG->spi_ctrl = ctrl;
	msg_printf("data ctrl 0x%x\n",ctrl);
	SPI_CTRL_REG->spi_page_size = 0x100<<4;
	do {
		SPI_CTRL_REG->spi_page_addr = addr_temp;
		if (data_len > CFG_BUFF_MAX) {
			temp_len = CFG_BUFF_MAX;
			data_len -= CFG_BUFF_MAX;
		} else {
			temp_len = data_len;
			data_len = 0;
		}
		msg_printf("remain len  0x%x\n", data_len);

		value =  (SPI_CTRL_REG->spi_cfg[0] & CLEAR_DATA64_LEN) |  temp_len | DATA64_EN;
		if (cmd[0] == 5)//need to check
			value |= (1<<19);
		SPI_CTRL_REG->spi_cfg[0] = value;

		SPI_CTRL_REG->spi_mem_data_addr = desc_r->phys;
		msg_printf("dma addr 0x%x\n", SPI_CTRL_REG->spi_mem_data_addr);
		msg_printf("spi_auto_cfg  0x%x\n", SPI_CTRL_REG->spi_auto_cfg);

		autocfg =  (cmd[0]<<24)|(1<<20)| DMA_TRIGGER;
		value = (SPI_CTRL_REG->spi_auto_cfg &(~(0xff<<24))) | autocfg;

		SPI_CTRL_REG->spi_intr_msk = (0x2<<1);
		SPI_CTRL_REG->spi_intr_sts = 0x07;

		SPI_CTRL_REG->spi_auto_cfg = value;

		while (( SPI_CTRL_REG->spi_intr_sts & 0x2) == 0x0);

		SPI_CTRL_REG->spi_intr_sts |= 0x02;
		SPI_CTRL_REG->spi_intr_msk = 0;
		time = 0;
		while ((SPI_CTRL_REG->spi_ctrl & SPI_CTRL_BUSY)!=0) {
			time++;
			if (time > 0x20000) {
				msg_printf("##busy check time out: spi_auto_cfg 0x%x spi_ctrl 0x%x\n", SPI_CTRL_REG->spi_auto_cfg, SPI_CTRL_REG->spi_ctrl);
				data_len = 0;
				break;
			}
		}

		/* Invalidate received data */
		invalidate_dcache_range(rounddown(desc_r->phys, ARCH_DMA_MINALIGN), roundup(data_end,ARCH_DMA_MINALIGN));
		memcpy(data_in, (void *)desc_r->phys, temp_len);
		addr_temp += CFG_BUFF_MAX;
		data_in += CFG_BUFF_MAX;
	} while (data_len != 0);

	SPI_CTRL_REG->spi_cfg[0] &= (DATA64_DIS & (~ (1<<19)));
	SPI_CTRL_REG->spi_auto_cfg  &= ~autocfg;
	spi_readcmd_set(0);
	return 0;
}

static int spi_flash_xfer_DMAwrite(struct sp_spi_nor_priv *priv, UINT8 *cmd, UINT32 cmd_len, const void *data, UINT32 data_len)
{
	UINT32 temp_len = data_len;
	UINT32 addr_temp = 0;
	UINT8 *data_in = (UINT8 *)data;
	UINT32 time = 0;
	UINT32 ctrl = 0;
	UINT32 autocfg = 0;
	int value = 0;
	struct spinorbufdesc *desc_w = &priv->wchain;

	ulong data_end = desc_w->phys + roundup(CFG_BUFF_MAX, ARCH_DMA_MINALIGN);

	diag_printf("%s\n",__FUNCTION__);
	msg_printf("DMA write : wdata length %d, cmd 0x%x\n",data_len, cmd[0]);

	while ((SPI_CTRL_REG->spi_auto_cfg & DMA_TRIGGER) ||  (SPI_CTRL_REG->spi_ctrl & SPI_CTRL_BUSY)) {
		time++;
		if (time > 0x30000) {
			 msg_printf("##busy check time out: spi_auto_cfg 0x%x spi_ctrl 0x%x\n", SPI_CTRL_REG->spi_auto_cfg, SPI_CTRL_REG->spi_ctrl);
			 break;
		}
	}

	spi_readcmd_set(cmd[0]);
	ctrl = SPI_CTRL_REG->spi_ctrl & (CLEAR_CUST_CMD & (~(1<<19)));
	ctrl |= (WRITE | BYTE_0 | ADDR_0B | (1<<19));
	if (cmd[0] == 6)//need to check
		ctrl &= ~(1<<19);

	SPI_CTRL_REG->spi_page_addr = 0;
	SPI_CTRL_REG->spi_data = 0;
	if (cmd_len > 1) {
		addr_temp = (cmd[1] << 16) | (cmd[2] << 8) | cmd[3];
		ctrl |= ADDR_3B;
	}

	SPI_CTRL_REG->spi_ctrl = ctrl;
	SPI_CTRL_REG->spi_page_size = 0x100<<4;
	do {
		SPI_CTRL_REG->spi_page_addr = addr_temp;
		if (data_len > CFG_BUFF_MAX) {
			temp_len = CFG_BUFF_MAX;
			data_len -= CFG_BUFF_MAX;
		} else {
			temp_len = data_len;
			data_len = 0;
		}

		if (temp_len > 0) {
			memcpy((void *)desc_w->phys, data_in, temp_len); // copy data to dma
			/* Flush data to be sent */
			flush_dcache_range(desc_w->phys, data_end);
		}

		value =  SPI_CTRL_REG->spi_cfg[0];
		SPI_CTRL_REG->spi_cfg[0] = (value & CLEAR_DATA64_LEN) | temp_len;//| DATA64_EN;

		SPI_CTRL_REG->spi_mem_data_addr = desc_w->phys;

		autocfg = DMA_TRIGGER | (cmd[0]<<8) | (1);
		value = (SPI_CTRL_REG->spi_auto_cfg & (~(0xff<<8))) | autocfg;

		SPI_CTRL_REG->spi_intr_msk = (0x2<<1);
		SPI_CTRL_REG->spi_intr_sts = 0x07;

		SPI_CTRL_REG->spi_auto_cfg =  value;

		while (( SPI_CTRL_REG->spi_intr_sts & 0x2) == 0x0);

		SPI_CTRL_REG->spi_intr_sts |= 0x02;
		SPI_CTRL_REG->spi_intr_msk = 0;
		time = 0;

		while ((SPI_CTRL_REG->spi_ctrl & SPI_CTRL_BUSY) != 0) {
			time++;
			if (time > 0x30000) {
				msg_printf("##busy check time out: spi_auto_cfg 0x%x spi_ctrl 0x%x\n", SPI_CTRL_REG->spi_auto_cfg, SPI_CTRL_REG->spi_ctrl);
				data_len = 0;
				break;
			}
		}

		addr_temp += CFG_BUFF_MAX;
		data_in += CFG_BUFF_MAX;
	} while (data_len != 0);

	SPI_CTRL_REG->spi_cfg[0] &= DATA64_DIS;
	SPI_CTRL_REG->spi_auto_cfg  &= ~autocfg;
	spi_readcmd_set(0);
	return 0;
}
#else
static void spi_fast_read_enable(void)
{
	SPI_ENHANCE enhance;

	enhance.enhance_en = 0;
	enhance.enhance_bit_mode = 0;
	diag_printf("%s\n",__FUNCTION__);

	while ((SPI_CTRL_REG->spi_ctrl & SPI_CTRL_BUSY) != 0) {
		msg_printf("wait SPI_CTRL_REG->spi_ctrl 0x%x\n",SPI_CTRL_REG->spi_ctrl);
	}

	SPI_CTRL_REG->spi_ctrl = A_CHIP | SPI_CLK_D_16;
	spi_nor_io_CUST_config(CMD_1,ADDR_1,DATA_1,enhance,DUMMY_CYCLE(8));
}

static void spi_fast_read_disable(void)
{
	SPI_ENHANCE enhance;

	enhance.enhance_en = 0;
	enhance.enhance_bit_mode = 0;
	diag_printf("%s\n",__FUNCTION__);

	while ((SPI_CTRL_REG->spi_ctrl & SPI_CTRL_BUSY) != 0) {
		msg_printf("wait SPI_CTRL_REG->spi_ctrl 0x%x\n",SPI_CTRL_REG->spi_ctrl);
	}

	SPI_CTRL_REG->spi_ctrl = A_CHIP | SPI_CLK_D_32;
	spi_nor_io_CUST_config(CMD_1,ADDR_1,DATA_1,enhance,DUMMY_CYCLE(0));
}

static UINT8 spi_nor_read_status1(void)
{
	UINT32 ctrl;

	diag_printf("%s\n",__FUNCTION__);

	ctrl = SPI_CTRL_REG->spi_ctrl & CLEAR_CUST_CMD;
	ctrl = ctrl | READ | BYTE_0 | ADDR_0B | CUST_CMD(0x05);
	while ((SPI_CTRL_REG->spi_ctrl & SPI_CTRL_BUSY) != 0) {
		msg_printf("wait SPI_CTRL_REG->spi_ctrl 0x%x\n",SPI_CTRL_REG->spi_ctrl);
	}

	SPI_CTRL_REG->spi_data = 0;
	SPI_CTRL_REG->spi_ctrl = ctrl;
	SPI_CTRL_REG->spi_auto_cfg |= PIO_TRIGGER;
	while ((SPI_CTRL_REG->spi_auto_cfg & PIO_TRIGGER) != 0) {
		msg_printf("wait PIO_TRIGGER\n");
	}

	msg_printf("SPI_CTRL_REG->spi_status 0x%x\n",SPI_CTRL_REG->spi_status);
	return (SPI_CTRL_REG->spi_status&0xff);
}

static int spi_flash_xfer_read(UINT8 *cmd, UINT32 cmd_len, void *data, UINT32 data_len)
{
	diag_printf("%s\n",__FUNCTION__);
	UINT32 total_count = data_len;
	UINT32 data_count;
	UINT32 addr_offset = 0;
	UINT32 addr_temp = 0;
	UINT8 *data_in = (UINT8 *)data;
	UINT32 data_temp = 0;
	//UINT8 addr_len = 0;
	UINT32 timeout = 0;
	UINT32 time = 0;
	UINT32 ctrl = 0;
	int fast_read = 0;

	msg_printf("data length %d data_in 0x%x\n",data_len, data_in);
	while (total_count > 0) {
		if (total_count > SPI_DATA64_MAX_LEN) {
			total_count = total_count - SPI_DATA64_MAX_LEN;
			data_count = SPI_DATA64_MAX_LEN;
		} else {
			data_count = total_count;
			total_count = 0;
		}

		while ((SPI_CTRL_REG->spi_ctrl & SPI_CTRL_BUSY) != 0) {
			msg_printf("wait SPI_CTRL_REG->spi_ctrl 0x%x\n",SPI_CTRL_REG->spi_ctrl);
		}

		ctrl = SPI_CTRL_REG->spi_ctrl & CLEAR_CUST_CMD;
		ctrl = ctrl | READ | BYTE_0 | ADDR_0B | CUST_CMD(cmd[0]);
		SPI_CTRL_REG->spi_cfg[0] = (SPI_CTRL_REG->spi_cfg[0] & CLEAR_DATA64_LEN) | data_count | DATA64_EN;
		SPI_CTRL_REG->spi_page_addr = 0;
		SPI_CTRL_REG->spi_buf_addr = DATA64_READ_ADDR(0) | DATA64_WRITE_ADDR(0);

		if (cmd_len > 1) {
			addr_temp = (cmd[1] << 16) | (cmd[2] << 8) | cmd[3];
			addr_temp = addr_temp + addr_offset * SPI_DATA64_MAX_LEN;
			SPI_CTRL_REG->spi_page_addr = addr_temp;
			ctrl = ctrl | ADDR_3B ;
			msg_printf("addr 0x%x\n", SPI_CTRL_REG->spi_page_addr);
		}

		if (cmd[0] == CMD_FAST_READ) {
			spi_fast_read_enable();
			fast_read = 1;
		}

		SPI_CTRL_REG->spi_data = 0;
		SPI_CTRL_REG->spi_ctrl = ctrl;
		SPI_CTRL_REG->spi_auto_cfg |= PIO_TRIGGER;
		//msg_printf("SPI_CTRL_REG->spi_ctrl 0x%x\n", SPI_CTRL_REG->spi_ctrl);
		//msg_printf("SPI_CTRL_REG->spi_page_addr 0x%x\n", SPI_CTRL_REG->spi_page_addr);
		//msg_printf("SPI_CTRL_REG->spi_cfg[0] 0x%x\n", SPI_CTRL_REG->spi_cfg[0]);

		if (cmd[0] == CMD_READ_STATUS) {
			data_in[0] = SPI_CTRL_REG->spi_status& 0xff;
			data_count = 0;
		}

		while (data_count > 0) {
			if ((data_count / 4) > 0) {
				//time = AV1_GetStc32();
				while ((SPI_CTRL_REG->spi_status_2 & SPI_SRAM_ST ) == SRAM_EMPTY) {
					//timeout = AV1_GetStc32();
					if ((timeout - time) > SPI_TIMEOUT) {
						msg_printf("timeout \n");
						break;
					}
				}

				data_temp = SPI_CTRL_REG->spi_data_64;
				//msg_printf("data_temp 0x%x\n",data_temp);
				data_in[0] = data_temp & 0xff;
				data_in[1] = ((data_temp & 0xff00) >> 8);
				data_in[2] = ((data_temp & 0xff0000) >> 16);
				data_in[3] = ((data_temp & 0xff000000) >> 24);
				data_in = data_in + 4;
				data_count = data_count - 4;
			} else {
				//time = AV1_GetStc32();
				while ((SPI_CTRL_REG->spi_status_2 & SPI_SRAM_ST ) == SRAM_EMPTY) {
					//timeout = AV1_GetStc32();
					if ((timeout - time) > SPI_TIMEOUT) {
						msg_printf("timeout \n");
						break;
					}
				}

				data_temp = SPI_CTRL_REG->spi_data_64;
				//msg_printf("data_temp 0x%x\n",data_temp);
				if (data_count%4 == 3) {
					data_in[0] = data_temp & 0xff;
					data_in[1] = ((data_temp & 0xff00) >> 8);
					data_in[2] = ((data_temp & 0xff0000) >> 16);
					data_count = data_count-3;
				} else if (data_count%4 == 2) {
					data_in[0] = data_temp & 0xff;
					data_in[1] = ((data_temp & 0xff00) >> 8);
					data_count = data_count-2;
				} else if (data_count%4 == 1) {
					data_in[0] = data_temp & 0xff;
					data_count = data_count-1;
				}
			}
		}

		addr_offset = addr_offset + 1;
		while ((spi_nor_read_status1() & 0x01) != 0) {
			msg_printf("wait DEVICE busy\n");
		}
	}

	while ((SPI_CTRL_REG->spi_auto_cfg & PIO_TRIGGER) != 0) {
		msg_printf("wait PIO_TRIGGER\n");
	}

	while ((SPI_CTRL_REG->spi_ctrl & SPI_CTRL_BUSY) != 0) {
		msg_printf("wait SPI_CTRL_REG->spi_ctrl 0x%x\n",SPI_CTRL_REG->spi_ctrl);
	}

	SPI_CTRL_REG->spi_cfg[0] &= DATA64_DIS;
	if (fast_read == 1) {
		spi_fast_read_disable();
	}
	return 0;
}

static int spi_flash_xfer_write(UINT8 *cmd, UINT32 cmd_len, const void *data, UINT32 data_len)
{
	diag_printf("%s\n",__FUNCTION__);
	UINT32 total_count = data_len;
	UINT32 data_count = 0;
	UINT32 addr_offset = 0;
	UINT32 addr_temp = 0;
	UINT8 *data_in = (UINT8 *) data;
	UINT32 data_temp = 0;
	//UINT8 addr_len = 0;
	UINT32 timeout = 0;
	UINT32 time = 0;
	UINT32 ctrl = 0;

        msg_printf("data_in 0x%x\n", data_in);
	msg_printf("data length %d data_in 0x%x 0x%x 0x%x 0x%x\n",data_len, data_in[0], data_in[1], data_in[2], data_in[3]);
	if (total_count == 0) {
		while ((SPI_CTRL_REG->spi_ctrl & SPI_CTRL_BUSY) != 0) {
			msg_printf("wait SPI_CTRL_REG->spi_ctrl 0x%x\n",SPI_CTRL_REG->spi_ctrl);
		}

		ctrl = SPI_CTRL_REG->spi_ctrl & CLEAR_CUST_CMD;
		ctrl = ctrl | WRITE | BYTE_0 | ADDR_0B | CUST_CMD(cmd[0]);
		SPI_CTRL_REG->spi_cfg[0] = (SPI_CTRL_REG->spi_cfg[0] & CLEAR_DATA64_LEN) | data_count | DATA64_EN;
		SPI_CTRL_REG->spi_buf_addr = DATA64_READ_ADDR(0) | DATA64_WRITE_ADDR(0);

		if (cmd_len > 1) {
			addr_temp = (cmd[1] << 16) | (cmd[2] << 8) | cmd[3];
			SPI_CTRL_REG->spi_page_addr = addr_temp;
			ctrl = ctrl | ADDR_3B ;
			msg_printf("addr 0x%x\n", SPI_CTRL_REG->spi_page_addr);
		}

		SPI_CTRL_REG->spi_data = 0;
		SPI_CTRL_REG->spi_ctrl = ctrl;
		SPI_CTRL_REG->spi_auto_cfg |= PIO_TRIGGER;
		//msg_printf("SPI_CTRL_REG->spi_ctrl 0x%x\n", SPI_CTRL_REG->spi_ctrl);
		//msg_printf("SPI_CTRL_REG->spi_page_addr 0x%x\n", SPI_CTRL_REG->spi_page_addr);
		//msg_printf("SPI_CTRL_REG->spi_cfg[0] 0x%x\n", SPI_CTRL_REG->spi_cfg[0]);
	}

	while (total_count > 0) {
		if (total_count > SPI_DATA64_MAX_LEN) {
			total_count = total_count - SPI_DATA64_MAX_LEN;
			data_count = SPI_DATA64_MAX_LEN;
		} else {
			data_count = total_count;
			total_count = 0;
		}

		while ((SPI_CTRL_REG->spi_ctrl & SPI_CTRL_BUSY) != 0) {
			msg_printf("wait SPI_CTRL_REG->spi_ctrl 0x%x\n",SPI_CTRL_REG->spi_ctrl);
		}

		ctrl = SPI_CTRL_REG->spi_ctrl & CLEAR_CUST_CMD;
		ctrl = ctrl | WRITE | BYTE_0 | ADDR_0B | CUST_CMD(cmd[0]);
		SPI_CTRL_REG->spi_cfg[0] = (SPI_CTRL_REG->spi_cfg[0] & CLEAR_DATA64_LEN) | data_count | DATA64_EN;
		SPI_CTRL_REG->spi_buf_addr = DATA64_READ_ADDR(0) | DATA64_WRITE_ADDR(0);
		if (cmd_len > 1) {
			addr_temp = (cmd[1] << 16) | (cmd[2] << 8) | cmd[3];
			addr_temp = addr_temp + addr_offset * SPI_DATA64_MAX_LEN;
			SPI_CTRL_REG->spi_page_addr = addr_temp;
			ctrl = ctrl | ADDR_3B ;
			msg_printf("addr 0x%x\n", SPI_CTRL_REG->spi_page_addr);
		}

		SPI_CTRL_REG->spi_data = 0;
		SPI_CTRL_REG->spi_ctrl = ctrl;
		SPI_CTRL_REG->spi_auto_cfg |= PIO_TRIGGER;
		//msg_printf("SPI_CTRL_REG->spi_ctrl 0x%x\n", SPI_CTRL_REG->spi_ctrl);
		//msg_printf("SPI_CTRL_REG->spi_page_addr 0x%x\n", SPI_CTRL_REG->spi_page_addr);
		//msg_printf("SPI_CTRL_REG->spi_cfg[0] 0x%x\n", SPI_CTRL_REG->spi_cfg[0]);

		while (data_count > 0) {
			if ((data_count / 4) > 0) {
				if ((SPI_CTRL_REG->spi_status_2 & SPI_SRAM_ST) == SRAM_FULL) {
					//time = AV1_GetStc32();
					while ((SPI_CTRL_REG->spi_status_2 & SPI_SRAM_ST) != SRAM_EMPTY) {
						//timeout = AV1_GetStc32();
						if ((timeout - time) > SPI_TIMEOUT) {
							msg_printf("timeout \n");
							break;
						}
					}
				}

				data_temp = (data_in[3] << 24) | (data_in[2] << 16) | (data_in[1] << 8) | data_in[0];
				SPI_CTRL_REG->spi_data_64 = data_temp;
				data_in = data_in + 4;
				data_count = data_count - 4;
			} else {
				if ((SPI_CTRL_REG->spi_status_2 & SPI_SRAM_ST) == SRAM_FULL) {
					//time = AV1_GetStc32();
					while ((SPI_CTRL_REG->spi_status_2 & SPI_SRAM_ST) != SRAM_EMPTY) {
						//timeout = AV1_GetStc32();
						if ((timeout - time) > SPI_TIMEOUT) {
							msg_printf("timeout \n");
							break;
						}
					}
				}

				//data_temp = data_in[0] & 0xff;
				if ((data_count%4) == 3) {
					data_temp = (data_in[2] << 16) | (data_in[1] << 8) | data_in[0];
					data_count = data_count-3;
				} else if ((data_count%4) == 2) {
					data_temp =  (data_in[1] << 8) | data_in[0];
					data_count = data_count-2;
				} else if ((data_count%4) == 1) {
					data_temp = data_in[0];
					data_count = data_count-1;
				}
				SPI_CTRL_REG->spi_data_64 = data_temp;
			}
		}
		addr_offset = addr_offset + 1;

		while ((spi_nor_read_status1() & 0x01) != 0) {
			msg_printf("wait DEVICE busy\n");
		}
	}

	while ((SPI_CTRL_REG->spi_auto_cfg & PIO_TRIGGER) != 0) {
		msg_printf("wait PIO_TRIGGER\n");
	}

	while ((SPI_CTRL_REG->spi_ctrl & SPI_CTRL_BUSY) != 0) {
		msg_printf("wait SPI_CTRL_REG->spi_ctrl 0x%x\n",SPI_CTRL_REG->spi_ctrl);
	}

	SPI_CTRL_REG->spi_cfg[0] &= DATA64_DIS;
	return 0;
}
#endif

int sp_spi_nor_claim_bus(unsigned int clock)
{
	//set pinmux
	UINT32 *grp1_sft_cfg = (UINT32 *) 0x9c000080;
	int value = 0;
        
        
	diag_printf("%s\n",__FUNCTION__);
	grp1_sft_cfg[1] = RF_MASK_V(0xf, (2 << 2) | 2);

	//if (plat->chipsel == 0)
		value = A_CHIP;
	//else
	//	value = B_CHIP;

	switch (clock) {
	case 100000000:
		value |= SPI_CLK_D_2;
		break;
	case 50000000:
		value |= SPI_CLK_D_4;
		break;
	case 33000000:
		value |= SPI_CLK_D_6;
		break;
	case 25000000:
		value |= SPI_CLK_D_8;
		break;
	case 12000000:
		value |= SPI_CLK_D_16;
		break;
	case  8000000:
		value |= SPI_CLK_D_24;
		break;
	case  6000000:
	default:
		value |= SPI_CLK_D_32;
		break;
	}

#if (SP_SPINOR_DMA)
	SPI_CTRL_REG->spi_ctrl = value;
	//value = SPI_CTRL_REG->spi_timing;
	SPI_CTRL_REG->spi_timing = (2<<22) | (0x16<<16) | (1<<1);
	msg_printf("ctrl 0x%x spi_timing 0x%x\n",SPI_CTRL_REG->spi_ctrl, SPI_CTRL_REG->spi_timing);
#else
	SPI_CTRL_REG->spi_ctrl = value;//SPI_CLK_D_16 = 62M
#endif
	SPI_CTRL_REG->spi_cfg[1] = SPI_CMD_OEN_1b | SPI_ADDR_OEN_1b | SPI_DATA_OEN_1b | SPI_CMD_1b | SPI_ADDR_1b |
			    SPI_DATA_1b | SPI_ENHANCE_NO | SPI_DUMMY_CYC(0) | SPI_DATA_IEN_DQ1;
	SPI_CTRL_REG->spi_auto_cfg &= ~(AUTO_RDSR_EN);

	return 0;
}

static int sp_spi_nor_readID(void)
{
        // read id
	data_pool[0] = 0x9f;
	//cmd_buf[0] = 8;
	sp_spi_nor_xfer(8, data_pool, NULL, SPI_XFER_BEGIN);
	//cmd_buf[0] = 48;
	sp_spi_nor_xfer(48, NULL, data_pool, SPI_XFER_END);
	diag_printf("## %s data_pool[0] %x data_pool[1] %x data_pool[2] %x\n", __FUNCTION__, data_pool[0], data_pool[1], data_pool[2]);	
	return 0;
}
int sp_spi_nor_xfer(unsigned int bitlen, const void *dout, void *din, unsigned long flags)
{
#if (SP_SPINOR_DMA)
	struct udevice *bus = dev->parent;
	//struct sp_spi_nor_platdata *pdata = dev_get_platdata(bus);
	struct sp_spi_nor_priv *priv = dev_get_priv(bus);
#endif
	unsigned int len;
	int flc = 0;

	diag_printf("%s\n", __FUNCTION__);
	if (bitlen == 0)
		goto out;

	if (bitlen % 8)
		goto out;

	len = bitlen / 8;

	if (flags & SPI_XFER_BEGIN) {
		if (len > 0 && dout) {
			cmd_len = len;
			memset(cmd_buf, 0, CMD_BUF_LEN);
			memcpy(cmd_buf, dout, len);
			msg_printf("cmd %x\n", cmd_buf[0]);
			msg_printf("addr 0x%x\n", cmd_buf[1] << 16 | cmd_buf[2] << 8 | cmd_buf[3]);
			msg_printf("cmd len %d, flags %d\n", len, flags);
		}

		if (!(flags & SPI_XFER_END))
			goto out;
		else
			flc = 1;
	}

	if (!dout) {
		// read
		msg_printf("read\n");
#if (SP_SPINOR_DMA)
		if (cmd_buf[0] == 0x0B)
			cmd_buf[0] = 0xEB;

		spi_flash_xfer_DMAread(priv, cmd_buf, cmd_len, din, len);
#else
		spi_flash_xfer_read(cmd_buf, cmd_len, din, len);
#endif
	} else if ((!din) | (flags & SPI_XFER_END)) {
		// write
#if (SP_SPINOR_DMA)
		if (cmd_buf[0] == 0x06)
			goto out;
		if (cmd_buf[0] == 0x02)
			cmd_buf[0] = 0x32;

		msg_printf("write\n");
		if (flc == 1)
			spi_flash_xfer_DMAwrite(priv, cmd_buf, cmd_len, NULL, 0);
		else
			spi_flash_xfer_DMAwrite(priv, cmd_buf, cmd_len, dout, len);
#else
		msg_printf("write\n");
		if (flc == 1)
			spi_flash_xfer_write(cmd_buf, cmd_len, NULL, 0);
		else
			spi_flash_xfer_write(cmd_buf, cmd_len, dout, len);
#endif
	}

out:
	return 0;
}

#if 0
static int sp_spi_nor_set_speed(struct udevice *bus, uint speed)
{
	struct sp_spi_nor_platdata *plat = bus->platdata;
	struct sp_spi_nor_priv *priv = dev_get_priv(bus);

	diag_printf("%s %d\n",__FUNCTION__, speed);

	if (speed > plat->clock)
		speed = plat->clock;

	//set spi nor clock
	priv->clock = speed;
	printf("%s: regs=%p, speed=%d\n", __func__, priv->regs, priv->clock);

	return 0;
}
#endif
void sp_spi_nor_init()
{	
	diag_printf("## %s \n", __FUNCTION__);
	sp_spi_nor_claim_bus(50000000);
	sp_spi_nor_readID();
	msg_printf("## %s data_pool[0] %x data_pool[1] %x data_pool[2] %x\n", __FUNCTION__, data_pool[0], data_pool[1], data_pool[2]);
	//ret = memcmp(data_pool, &nor_id, 3);
	//msg_printf("## ret 0x%x\n", ret);	
}
/*
probe flow
1.ofdata_to_platdata
2.set_speed
3.set_mode
4.claim bus
*/
