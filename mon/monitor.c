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




