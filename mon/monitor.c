/*******************************************************************************

Copyright (c) 2012 Sunplus technology co. Ltd.All right reserved!

********************************************************************************
File Name           :   Monitor.c
Version             :               release 0.1
Author              :   henry.liou
Created             :   2015.11.3
Last Modified       :
Description         :
public functions    :

History Information Description
Date                Author              Modification
2015.11.3          henry.liou               Created function
*******************************************************************************/
/*---------------------------------------------------------------------------*
*                        INCLUDE   DECLARATIONS                                     *
*---------------------------------------------------------------------------*/
#include "common_all.h"
#include "monitor.h"
#include <stdarg.h>
#include <string.h>

/*---------------------------------------------------------------------------*
*                            EXTERNAL   REFERENCES                                                                *
*---------------------------------------------------------------------------*/
extern char *mon_readhex(char *p, unsigned int *x);
const char *mon_readstr(char *p, int *x);
void mon_puts(char *s);
/*---------------------------------------------------------------------------*
*                 MACRO  DECLARATIONS                                                       *
*---------------------------------------------------------------------------*/
#define CMD_LENGTH          64
/*---------------------------------------------------------------------------*
*                                GLOBAL   VARIABLES                                                                  *
*---------------------------------------------------------------------------*/
static UINT8 key_trick = 0;
static char mon_prompt[] = "\nMN> ";
static char mon_copyr[] = "" \
 "Simple monitor\n" \
 "Date: " __DATE__ " Time: " __TIME__ "\n" \
 "File: " __FILE__ "\n";
/*---------------------------------------------------------------------------*
*                               FUNCTION   DECLARATIONS                                                        *
*---------------------------------------------------------------------------*/
static void _ew(int argc, char *argv[])
{
	UINT32 base;
	int    i, j;

	mon_readhex(argv[0], &base);    // skip 2-char
	base &= ~3;
	for (i=0; i<CMD_LENGTH;) {
		printf("%08x: ", base+i);
		for (j=0;j<4;j++) {
			printf(" %08x", *((UINT32 *)(base+i)));
			i+=4;
		}
		mon_puts("\n");
	}
}


static void _sw(int argc, char *argv[])
{
	UINT32 base;
	UINT32 val;

	mon_readhex(argv[0], &base);
	mon_readhex(argv[1], &val);

	*(UINT32 *)(base&0xfffffffc) = val;
}


static void _lreg(int argc, char *argv[])
{
	UINT32 i, group, *base;

	mon_readhex(argv[0], &group);
	// if (group >= 0 && group < 512)
	base = (UINT32 *)(RF_GRP(group, 0));

	printf("lreg base addr 0x%x\n",base);
	for (i = 0; i < 32; i++) {
		printf( "group %d[%d] = %08x (%d)\n", group, i, base[i], base[i]);
	}
}

void wreg_r(UINT32 group, UINT32 index, UINT32 value)
{
	UINT32 *base;
	// if (group >= 0 && group < 512)
	base = (UINT32 *)((unsigned int)RGST_BASE + group*128 + index*4);

	printf("wreg base addr 0x%x\n",base);
	*base = value;
	printf( "group %d[%d] = %08x (%d)\n", group, index, *base, *base);
}


static void _wreg(int argc, char *argv[])
{
	UINT32 group, index, value;

	mon_readhex(argv[0], &group);
	mon_readhex(argv[1], &index);
	mon_readhex(argv[2], &value);

	wreg_r(group , index, value);
}


static void _spi_test(int argc, char *argv[])
{
	u8	rx_buf[255];
	u8	tx_buf[255];
	unsigned int test;

	

	sp_spi_master_set_freq_mode(0, 5000000 ,3);      // set clk to 100kHz



	tx_buf[0] = 0x00;
	sp_spi_master_fd_write(0, tx_buf,1);


	sp_spi_master_fd_read(0, rx_buf,1);


	printf("ADXL345 ID :0x%x\n ",rx_buf[0]);

	tx_buf[0] = 0x2D;
	tx_buf[1] = 0x0A;	
	sp_spi_master_fd_write(0, tx_buf ,2);


	printf("check power\n ");


	tx_buf[0] = 0x32;
	sp_spi_master_fd_read_write(0, tx_buf,rx_buf ,2, 1);
	printf("data0 :0x%x\n ",rx_buf[0]);

	tx_buf[0] = 0x33;
	sp_spi_master_fd_read_write(0, tx_buf,&rx_buf[1] ,2, 1);
	printf("data1 :0x%x\n ",rx_buf[1]);


	tx_buf[0] = 0x34;
	sp_spi_master_fd_read_write(0, tx_buf,&rx_buf[2] ,2, 1);
	printf("data2 :0x%x\n ",rx_buf[2]);

	tx_buf[0] = 0x35;
	sp_spi_master_fd_read_write(0, tx_buf,&rx_buf[3] ,2, 1);
	printf("data3 :0x%x\n ",rx_buf[3]);


	tx_buf[0] = 0x36;
	sp_spi_master_fd_read_write(0, tx_buf,&rx_buf[4] ,2, 1);
	printf("data4 :0x%x\n ",rx_buf[4]);

	tx_buf[0] = 0x37;
	sp_spi_master_fd_read_write(0, tx_buf,&rx_buf[5] ,2, 1);
	printf("data5 :0x%x\n ",rx_buf[5]);


	test = rx_buf[0]<<8 | rx_buf[1];

	printf("ACCE_X:%d\n ",test);

	test = rx_buf[2]<<8 | rx_buf[3];

	printf("ACCE_Y:%d\n ",test);	

	test = rx_buf[4]<<8 | rx_buf[5];

	printf("ACCE_Z:%d\n ",test);


	
}



#ifdef NOC_TEST

extern void dump_noc_reg();
extern void write_noc_reg(char *module_name, char *reg_grp, char *reg_name, unsigned int value);
extern void read_noc_regs(char *module_name, char *reg_grp, char *reg_name);
extern void noc_perf(int onoff);
extern void noc_cbdma_test(int case_number);

unsigned int g_is_noc_perf_enable = FALSE;

static void _noc(int argc, char *argv[])
{
	char *cmd;
	char *module_name = NULL, *reg_grp = NULL, *reg_name = NULL;
	unsigned int value, cmd_len;
	int testcase_number = -1; // -1 means all

	// unsigned int idx;
	// int k = argc;
	// printf("[DBG] argc : %d\n", argc);
	// while (k) {
	// 	idx = argc - k;
	// 	printf("[DBG] argv[%d] : %s\n", idx, argv[idx]);
	// 	k--;
	// }

	if (argc >= 1) {
		cmd = argv[0];
		cmd_len = strlen(cmd);
	}
	else {
		printf("help\n");
	}

	if (argc >= 2)
		module_name = argv[1];

	if (argc >= 3)
		reg_grp = argv[2];

	if (argc >= 4)
		reg_name = argv[3];

	if (strncmp(cmd, "dump", cmd_len) == 0) {
		dump_noc_reg();
	}
	else if (strncmp(cmd, "perf", cmd_len) == 0) {
		if (g_is_noc_perf_enable == FALSE) {
			printf("Enalbe NoC performance log.\n");
			noc_perf(1);
			g_is_noc_perf_enable = TRUE;
		}
		else {
			noc_perf(0);
			printf("Disalbe NoC performance log.\n");
			g_is_noc_perf_enable = FALSE;
		}
	} else if (strncmp(cmd, "cbdma", cmd_len) == 0) {
		if (argc >= 2)
			testcase_number = mon_readhex(argv[1], &value);
		noc_cbdma_test(testcase_number);

	} else if (strncmp(cmd, "r", cmd_len) == 0) {
		read_noc_regs(module_name, reg_grp, reg_name);

	} else if (strncmp(cmd, "w", cmd_len) == 0) {

		if (argc >= 5)
			mon_readhex(argv[4], &value);
		else
			printf("Invalid value.\n");

		write_noc_reg(module_name, reg_grp, reg_name, value);

	} else {
		printf("inavlid command\n");
	}

}

#endif


#ifdef QCH_TEST

extern void qch_host_test(int test_id);
extern void qch_device_lead_test(int test_id);
extern void qch_test_iop(int test_id);

static void _qchannel(int argc, char *argv[])
{
	char *cmd;
	unsigned int value, cmd_len;
	int test_id = -1; // -1 means all

	if (argc >= 1) {
		cmd = argv[0];
		cmd_len = strlen(cmd);
	}
	else {
		printf("help\n");
	}

	if (argc >= 2)
		mon_readhex(argv[1], (unsigned int *) &test_id);

	if (strncmp(cmd, "host", cmd_len) == 0) {
		qch_host_test(test_id);
	} else if (strncmp(cmd, "devld", cmd_len) == 0) {
		qch_device_lead_test(test_id);
	} else if (strncmp(cmd, "iop", cmd_len) == 0) {
		qch_test_iop(test_id);
	} else {
		printf("Unknown command.\n");
	}

}

#endif

#ifdef AXI_MON
void _axi(int argc, char *argv[])
{
	char *cmd;
	unsigned int value, cmd_len, timeout_cnt = 1;
	int test_id = -1; // -1 means all

	if (argc >= 1) {
		cmd = argv[0];
		cmd_len = strlen(cmd);
	}
	else {
		printf("help\n");
	}



	if (strncmp(cmd, "ue", cmd_len) == 0) {
		axi_mon_unexcept_access_test();
	} else if (strncmp(cmd, "to", cmd_len) == 0) {
		if (argc >= 2)
			mon_readhex(argv[1], (unsigned int *) &timeout_cnt);
		axi_mon_timeout_test(timeout_cnt);
	} else if (strncmp(cmd, "bw", cmd_len) == 0) {
		axi_mon_bw_test();
	} else {
		printf("Unknown command.\n");
	}
}
#endif

#ifdef DISP_TEST
extern void run_disp_init_cmd(int is_hdmi, int width, int height);
extern void run_colorbar_cmd(int sel, int en);
extern void run_fetch_data_cmd(int disp_path, int input_fmt);
extern void run_draw_init_cmd(int disp_path, int input_fmt);
extern void run_draw_pixel_cmd(int test);
extern void run_draw_line_cmd(int test);
extern void run_draw_font_cmd(int test);
extern void run_draw_clean_cmd(int test);
static void _disp(int argc, char *argv[])
{
	char *cmd, *para1, *para2, *para3;
	unsigned int cmd_len, para1_len, para2_len, para3_len;
	unsigned int value, value1, value2, value3;

	cmd_len = 0;
	para1_len = 0;
	para2_len = 0;
	para3_len = 0;
	value = 0;
	value1 = 0;
	value2 = 0;
	value3 = 0;

	if (argc >= 1) {
		cmd = argv[0];
		para1 = argv[1];
		para2 = argv[2];
		para3 = argv[3];
		cmd_len = _strlen(cmd);
		para1_len = _strlen(para1);
		para2_len = _strlen(para2);
		para3_len = _strlen(para3);
		mon_readhex(argv[0], &value);
		mon_readhex(argv[1], &value1);
		mon_readhex(argv[2], &value2);
		mon_readhex(argv[3], &value3);
		printf("/********************************************************/ \n");
		printf("/* disp command list                                    */ \n");
		printf("/* disp init ttl xx xx --- initial display function.    */ \n");
		printf("/* disp init hdmi xx xx --- initial display function.   */ \n");
		printf("/* disp color --- Bulit-In-Self-Test.                   */ \n");
		printf("/* disp color dve   xx (xx=dis/en).                     */ \n");
		printf("/* disp color dmix  xx (xx=dis/en/hor/bor/snow).        */ \n");
		printf("/* disp color vpp0  xx (xx=dis/en).                     */ \n");
		printf("/* disp color ddfch xx (xx=dis/en/half1/half2).         */ \n");
		printf("/* disp color osd0  xx (xx=dis/en/bor).                 */ \n");
		printf("/* disp color hdmitx xx (xx=dis/en).                    */ \n");
		printf("/* disp fetch ddfch xx (xx=en/nv12/nv16/yuy2).          */ \n");
		printf("/* disp fetch osd0 xx (xx=en/8bpp/yuy2/argb8888).       */ \n");
		printf("/* disp draw init xx (xx=8bpp/rgb565/argb8888).         */ \n");
		printf("/* disp draw pixel xx (xx=test1/test2/test3).           */ \n");
		printf("/* disp draw line xx (xx=test1/test2/test3).            */ \n");
		printf("/* disp draw font xx (xx=test1/test2).                  */ \n");
		printf("/* disp draw clean xx (xx=test1/test2/test3).           */ \n");
		printf("/********************************************************/ \n");
	}
	else {
		printf("help\n");
		printf("cmd %d, para1 %d, para2 %d , para3 %d \n",cmd_len,para1_len,para2_len,para3_len);
		printf("cmd %d, para1 %d, para2 %d , para3 %d \n",value,value1,value2,value3);		
	}

	if (_strncmp(cmd, "init", cmd_len) == 0) {
		//printf("run init command.\n");

		if (_strncmp(para1, "ttl", para1_len) == 0) {
			printf("run init ttl command.\n");
			value1 = 0;
		}
		else if (_strncmp(para1, "hdmi", para1_len) == 0) {
			printf("run init hdmi command.\n");
			value1 = 1;
		}
		if((value2 < 0) || (value2 > 2000))
			value2 = 720;
		if((value3 < 0) || (value3 > 2000))
			value2 = 480;
		run_disp_init_cmd(value1, value2, value3);

	} else if (_strncmp(cmd, "color", cmd_len) == 0) {
		//printf("run color bar command.\n");
		if (_strncmp(para1, "dve", para1_len) == 0) {
			//printf("run dve color bar command.\n");
			value1 = 0;
			if (_strncmp(para2, "en", para2_len) == 0) {
				value2 = 1;
				printf("run dve color bar [en].\n");
			}
			else if (_strncmp(para2, "dis", para2_len) == 0) {
				value2 = 0;
				printf("run dve color bar [dis].\n");
			}
		}
		else if (_strncmp(para1, "dmix", para1_len) == 0) {
			//printf("run dmix color bar command.\n");
			value1 = 1;
			if (_strncmp(para2, "en", para2_len) == 0) {
				value2 = 1;
				printf("run dmix color bar [en].\n");
			}
			else if (_strncmp(para2, "dis", para2_len) == 0) {
				value2 = 0;
				printf("run dmix color bar [dis].\n");
			}
			else if (_strncmp(para2, "hor", para2_len) == 0) {
				value2 = 2;
				printf("run dmix color bar [hor].\n");
			}
			else if (_strncmp(para2, "bor", para2_len) == 0) {
				value2 = 3;
				printf("run dmix color bar [bor].\n");
			}
			else if (_strncmp(para2, "snow", para2_len) == 0) {
				value2 = 4;
				printf("run dmix color bar [snow].\n");
			}
		}
		else if (_strncmp(para1, "vpp0", para1_len) == 0) {
			//printf("run vpp0 color bar command.\n");
			value1 = 2;
			if (_strncmp(para2, "en", para2_len) == 0) {
				value2 = 1;
				printf("run vpp0 color bar [en].\n");
			}
			else if (_strncmp(para2, "dis", para2_len) == 0) {
				value2 = 0;
				printf("run vpp0 color bar [dis].\n");
			}
		}
		else if (_strncmp(para1, "ddfch", para1_len) == 0) {
			//printf("run ddfch color bar command.\n");
			value1 = 3;
			if (_strncmp(para2, "en", para2_len) == 0) {
				value2 = 1;
				printf("run ddfch color bar [en].\n");
			}
			else if (_strncmp(para2, "dis", para2_len) == 0) {
				value2 = 0;
				printf("run ddfch color bar [dis].\n");
			}
			else if (_strncmp(para2, "half1", para2_len) == 0) {
				value2 = 2;
				printf("run ddfch color bar [half1].\n");
			}
			else if (_strncmp(para2, "half2", para2_len) == 0) {
				value2 = 3;
				printf("run ddfch color bar [half2].\n");
			}
		}
		else if (_strncmp(para1, "osd0", para1_len) == 0) {
			//printf("run osd0 color bar command.\n");
			value1 = 4;
			if (_strncmp(para2, "en", para2_len) == 0) {
				value2 = 1;
				printf("run osd0 color bar [en].\n");
			}
			else if (_strncmp(para2, "dis", para2_len) == 0) {
				value2 = 0;
				printf("run osd0 color bar [dis].\n");
			}
			else if (_strncmp(para2, "bor", para2_len) == 0) {
				value2 = 2;
				printf("run osd0 color bar [bor].\n");
			}
		}
		else if (_strncmp(para1, "hdmitx", para1_len) == 0) {
			//printf("run hdmitx color bar command.\n");
			value1 = 5;
			if (_strncmp(para2, "en", para2_len) == 0) {
				value2 = 1;
				printf("run hdmitx color bar [en].\n");
			}
			else if (_strncmp(para2, "dis", para2_len) == 0) {
				value2 = 0;
				printf("run hdmitx color bar [dis].\n");
			}
		}
		run_colorbar_cmd(value1,value2);
	} else if (_strncmp(cmd, "fetch", cmd_len) == 0) {
		printf("run fetch command.\n");
		if (_strncmp(para1, "ddfch", para1_len) == 0) {
			//printf("run fetch ddfch command.\n");
			value1 = 0;
			if (_strncmp(para2, "en", para2_len) == 0) {
				value2 = 2;
				printf("run fetch ddfch [en].\n");
			}			
			else if (_strncmp(para2, "nv12", para2_len) == 0) {
				value2 = 0;
				printf("run fetch ddfch [nv12].\n");
			}
			else if (_strncmp(para2, "nv16", para2_len) == 0) {
				value2 = 1;
				printf("run fetch ddfch [nv16].\n");
			}
			else if (_strncmp(para2, "yuy2", para2_len) == 0) {
				value2 = 2;
				printf("run fetch ddfch [yuy2].\n");
			}
		}
		else if (_strncmp(para1, "osd0", para1_len) == 0) {
			//printf("run fetch osd0 command.\n");
			value1 = 1;
			if (_strncmp(para2, "en", para2_len) == 0) {
				value2 = 4;
				printf("run fetch osd0 [en].\n");
			}			
			else if (_strncmp(para2, "8bpp", para2_len) == 0) {
				value2 = 2;
				printf("run fetch osd0 [8bpp].\n");
			}
			else if (_strncmp(para2, "yuy2", para2_len) == 0) {
				value2 = 4;
				printf("run fetch osd0 [yuy2].\n");
			}
			else if (_strncmp(para2, "rgb565", para2_len) == 0) {
				value2 = 8;
				printf("run fetch osd0 [rgb565].\n");
			}
			else if (_strncmp(para2, "argb1555", para2_len) == 0) {
				value2 = 9;
				printf("run fetch osd0 [argb1555].\n");
			}
			else if (_strncmp(para2, "rgba4444", para2_len) == 0) {
				value2 = 10;
				printf("run fetch osd0 [rgba4444].\n");
			}
			else if (_strncmp(para2, "argb4444", para2_len) == 0) {
				value2 = 11;
				printf("run fetch osd0 [argb4444].\n");
			}
			else if (_strncmp(para2, "rgba8888", para2_len) == 0) {
				value2 = 13;
				printf("run fetch osd0 [rgba8888].\n");
			}
			else if (_strncmp(para2, "argb8888", para2_len) == 0) {
				value2 = 14;
				printf("run fetch osd0 [argb8888].\n");
			}
		}
		run_fetch_data_cmd(value1,value2);
	} else if (_strncmp(cmd, "draw", cmd_len) == 0) {
		printf("run draw command.\n");
		if (_strncmp(para1, "init", para1_len) == 0) {
			//printf("run draw init command.\n");
			value1 = 1;
			if (_strncmp(para2, "en", para2_len) == 0) {
				value2 = 2;
				printf("run draw init osd0 [8bpp].\n");
			}			
			else if (_strncmp(para2, "8bpp", para2_len) == 0) {
				value2 = 2;
				printf("run draw init osd0 [8bpp].\n");
			}
			else if (_strncmp(para2, "yuy2", para2_len) == 0) {
				value2 = 4;
				printf("run draw init osd0 [yuy2].\n");
			}
			else if (_strncmp(para2, "rgb565", para2_len) == 0) {
				value2 = 8;
				printf("run draw init osd0 [rgb565].\n");
			}
			else if (_strncmp(para2, "argb1555", para2_len) == 0) {
				value2 = 9;
				printf("run draw init osd0 [argb1555].\n");
			}
			else if (_strncmp(para2, "rgba4444", para2_len) == 0) {
				value2 = 10;
				printf("run draw init osd0 [rgba4444].\n");
			}
			else if (_strncmp(para2, "argb4444", para2_len) == 0) {
				value2 = 11;
				printf("run draw init osd0 [argb4444].\n");
			}
			else if (_strncmp(para2, "rgba8888", para2_len) == 0) {
				value2 = 13;
				printf("run draw init osd0 [rgba8888].\n");
			}
			else if (_strncmp(para2, "argb8888", para2_len) == 0) {
				value2 = 14;
				printf("run draw init osd0 [argb8888].\n");
			}
			run_draw_init_cmd(value1,value2);
		}
		else if (_strncmp(para1, "pixel", para1_len) == 0) {
			//printf("run draw pixel command.\n");
			if (_strncmp(para2, "test1", para2_len) == 0) {
				value1 = 0;
				printf("run draw pixel osd0 [test1].\n");
			}
			else if (_strncmp(para2, "test2", para2_len) == 0) {
				value1 = 1;
				printf("run draw pixel osd0 [test2].\n");
			}
			else if (_strncmp(para2, "test3", para2_len) == 0) {
				value1 = 2;
				printf("run draw pixel osd0 [test3].\n");
			}
			run_draw_pixel_cmd(value1);
		}
		else if (_strncmp(para1, "line", para1_len) == 0) {
			//printf("run draw line command.\n");
			if (_strncmp(para2, "test1", para2_len) == 0) {
				value1 = 0;
				printf("run draw line osd0 [test1].\n");
			}
			else if (_strncmp(para2, "test2", para2_len) == 0) {
				value1 = 1;
				printf("run draw line osd0 [test2].\n");
			}
			else if (_strncmp(para2, "test3", para2_len) == 0) {
				value1 = 2;
				printf("run draw line osd0 [test3].\n");
			}
			run_draw_line_cmd(value1);
		}
		else if (_strncmp(para1, "font", para1_len) == 0) {
			//printf("run draw font command.\n");
			if (_strncmp(para2, "test1", para2_len) == 0) {
				value1 = 0;
				printf("run draw font osd0 [test1].\n");
			}
			else if (_strncmp(para2, "test2", para2_len) == 0) {
				value1 = 1;
				printf("run draw font osd0 [test2].\n");
			}
			run_draw_font_cmd(value1);
		}
		else if (_strncmp(para1, "clean", para1_len) == 0) {
			//printf("run draw clean command.\n");
			if (_strncmp(para2, "test1", para2_len) == 0) {
				value1 = 0;
				printf("run draw clean osd0 [test1].\n");
			}
			else if (_strncmp(para2, "test2", para2_len) == 0) {
				value1 = 1;
				printf("run draw clean osd0 [test2].\n");
			}
			else if (_strncmp(para2, "test3", para2_len) == 0) {
				value1 = 2;
				printf("run draw clean osd0 [test3].\n");
			}
			run_draw_clean_cmd(value1);
		}
	} else {
		printf("Unknown command.\n");
	}

	//printf("disp function test \n");
}
#endif


static CMD_LIST cmd_list[] =
{
	{"lreg",      _lreg,                "Read Register."},
	{"wreg",      _wreg,                "Write Register."},
	{"ew",        _ew,                  "Read word(4bytes) from mem."},
	{"sw",        _sw,                  "Write word(4bytes) to mem."},

	{"cbdma", cbdma_test, "CBDMA test"	},
	{"timer", timer_test, "Timer test"	},
#ifdef AXI_MON
	{"axi", _axi, "AXI MON test"	},
#endif
#ifdef NOC_TEST
	{"noc",       _noc,                 "Utilities for NoC."},
#endif
#ifdef QCH_TEST
	{"qch",       _qchannel,            "q channel verification."},
#endif
#ifdef DISP_TEST
	{"disp",       _disp,                 "For display function"},
#endif
#ifdef RS485_TEST
	{"485w",      _RS485_write,        "RS485 write."},
    {"485r",	   _RS485_read,		    "RS485 read."},
#endif
#ifdef SPI_NOR_TEST
        {"sf",		FlashCommand,      "spi nor command"},
#endif 
};


//stdlib
int _strlen(const char * str)
{
	const char *start = str;
	while (*str) str++;
	return str - start;
}


int  _strncmp( const char *s1 , const char *s2 , int n)
{
	if (n == 0)
		return 0;
	while (n-- != 0 && *s1 == *s2) {
		if (n == 0 || *s1 == '\0')
			break;
		s1++;
		s2++;
	}
	return (*(unsigned char *) s1) - (*(unsigned char *) s2);
}


//stdlib
 int polling_io(void)
{
	while (UART0_rx_rdy()) {
		int c = UART0_getc();
		if (c == 'm')
			key_trick = 1;
		else if (c == 'o')
			key_trick = (key_trick == 1) ? 2 : 0;
		else if (c == 'n' && key_trick == 2) {
			key_trick = 0;
			return 1;
		}
		else
			key_trick = 0;
	}
	return 0;
}


char *mon_skipspace(char *p)
{
	if (p == NULL) return NULL;

	while (1)
	{
		int c = p[0];
		if (c == ' ' || c == '\t' || c == '\v') p++;
		else break;
	}
	return p;
}


char *mon_readhex(char *p, unsigned int *x)
{
	int base = 10;
	int sign = 0;
	int cnt, retval;

	if (p == NULL) return NULL;
	if (x == NULL) return p;

	p = mon_skipspace(p);

	if (p[0] == '-')
	{
		sign = 1;
		p++;
	}
	if (p[0] == '0' && p[1] == 'x')
	{
		base = 16;
		p += 2;
	}
	if (p[0] == '0' && p[1] == 'o')
	{
		base = 8;
		p += 2;
	}
	if (p[0] == '0' && p[1] == 'b')
	{
		base = 2;
		p += 2;
	}

	retval = 0;

	for (cnt = 0; 1; cnt++)
	{
		int c = *p++;
		int val;

		// translate 0~9, a~z, A~Z
		if (c >= '0' && c <= '9') val = c - '0';
		else if (c >= 'a' && c <= 'z') val = c - 'a' + 10;
		else if (c >= 'A' && c <= 'Z') val = c - 'A' + 10;
		else break;
		if (val >= base) break;

		retval = retval * base + val;
	}

	if (cnt == 0) return NULL;  // no translation is done??

	if (sign) retval = -retval; // change sign
	*(UINT32 *)x = retval;      // store it
	return p;
}

void mon_puts(char *s)
{
	int c;
	while ((c = *s++) != 0)
	{
		UART0_putc(c);
		if (c == 10) UART0_putc(13);
	}
}

static int mon_read(char *buf, int maxl, char *last)
{
	int c;
	int L = 0;

	if (buf == NULL) return 0;

	do {

		if (!UART0_rx_rdy()) {
			//cpu_intr_enable();    // wait a character
			continue;
		}

		c = UART0_getc();           // get input char

		if (c == 27) return -1; // ESC cancel command
		if (c == '\r' || c == '\n') {
			buf[L] = '\0';
			if (L == 0) {
				memcpy(buf, last, maxl);	// Repeat last command
				printf("%s\n", last);
			}
			else
				memcpy(last, buf, maxl);  // Backup last command
			break;
		}
		// BS
		if (c == 0x08) {
			printf("BS\n");
			if (L > 0)
				L--;
		}
		else {
			buf[L++] = c;
		}
		UART0_putc(c);
		buf[L] = '\0';
	}
	while (L < maxl);

	return 0;
}

static char *arg_buf[16];

char *sstrchr(char *s, char c)
{
	for (; *s != '\0' && *s != c; ++s);
	return *s == c ? (char *) s : NULL;
}

void makeargs(char *cmd, int *argc, char ***argv) {
	char *buf = cmd;
	int count = 1;
	char *delim;
	char **_argv = arg_buf;

	if (*buf == '\0') {
		*argc = 0;
		*argv = _argv;
		return;
	}

	memset(arg_buf, 0, sizeof(arg_buf));
	_argv[0] = buf;
	delim = sstrchr(buf, ' ');
	while (delim != NULL) {
		_argv[count] = delim + 1;
		*delim = '\0';
		count++;
		delim = sstrchr(delim + 1, ' ');
	}

	*argc = count;
	*argv = _argv;
}

static char cmdbuf[CMD_LENGTH];
static char last_cmdbuf[CMD_LENGTH];
void monitor()
{
	UINT32 i;
	int argc;
	char **argv;

	mon_puts(mon_copyr);
	while (1) {
		char *pbuf;
		mon_puts(mon_prompt);
		if (mon_read(cmdbuf, CMD_LENGTH, last_cmdbuf) < 0) {
			mon_puts("..\n");
			continue;
		}
		pbuf = mon_skipspace(cmdbuf);
		for (i = 0;i<sizeof(cmd_list)/sizeof(CMD_LIST);i++) {
			if (_strncmp(pbuf, cmd_list[i].cmd, _strlen(cmd_list[i].cmd)) == 0) {
				mon_puts("\n");
				makeargs( pbuf + _strlen(cmd_list[i].cmd) + 1, &argc, &argv);
				cmd_list[i].func_ptr(argc, argv);
				break;
			}
		}
	}
}


void task_dbg(void)
{
	printf("task dbg\n");
	while (1) {
		if (polling_io()) {
			monitor();
		}
	}
}




