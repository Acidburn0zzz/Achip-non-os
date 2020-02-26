/********************************************************
 * Copyright (c) 2019 by Sunplus Technology Co., Ltd.
 *    ____               __
 *   / __/_ _____  ___  / /_ _____
 *  _\ \/ // / _ \/ _ \/ / // (_-<
 * /___/\_,_/_//_/ .__/_/\_,_/___/
 *              /_/
 * Sunplus Technology Co., Ltd.19, Innovation First Road,
 * Science-Based Industrial Park, Hsin-Chu, Taiwan, R.O.C.
 * ------------------------------------------------------
 *
 * Description :  display register OSD for sp7021
 * ------------------------------------------------------
 * Rev  Date          Author(s)      Status & Comments
 * ======================================================
 * 0.1  2019/12/21    hammer.hsieh   initial version
 */

#include <emuio.h>
#include "reg_disp.h"
#include "display.h"
#include "disp_osd.h"

#ifdef OSD0_FETCH_EN
#include <cache.h>
#include "osd_pattern/disp_palette.h"
	#ifdef OSD0_FETCH_DATA_8bpp
#include "osd_pattern/ARGB8bpp_800x480.h"
#include "osd_pattern/ARGB8bpp_720x480.h"
	#endif
	#ifdef OSD0_FETCH_DATA_YUY2
#include "osd_pattern/yuv422_YUY2_800x480.h"
#include "osd_pattern/yuv422_YUY2_720x480.h"
	#endif
	#ifdef OSD0_FETCH_DATA_RGB565
#include "osd_pattern/RGB565_800x480.h"
#include "osd_pattern/RGB565_720x480.h"
	#endif
	#ifdef OSD0_FETCH_DATA_ARGB1555
#include "osd_pattern/ARGB1555_800x480.h"
#include "osd_pattern/ARGB1555_720x480.h"
	#endif
	#ifdef OSD0_FETCH_DATA_RGBA4444
#include "osd_pattern/RGBA4444_800x480.h"
#include "osd_pattern/RGBA4444_720x480.h"
	#endif
	#ifdef OSD0_FETCH_DATA_ARGB4444
#include "osd_pattern/ARGB4444_800x480.h"
#include "osd_pattern/ARGB4444_720x480.h"
	#endif
	#ifdef OSD0_FETCH_DATA_RGBA8888
#include "osd_pattern/RGBA8888_800x480.h"
#include "osd_pattern/RGBA8888_720x480.h"
	#endif
	#ifdef OSD0_FETCH_DATA_ARGB8888
//#include "osd_pattern/ARGB8888_800x480_full.h"
#include "osd_pattern/ARGB8888_800x480_half.h"
//#include "osd_pattern/ARGB8888_720x480_full.h"
#include "osd_pattern/ARGB8888_720x480_half.h"
	#endif
#endif

/**************************************************************************
 *                           C O N S T A N T S                            *
 **************************************************************************/
// OSD Header config0
#define OSD_HDR_C0_CULT				0x80
#define OSD_HDR_C0_TRANS			0x40

// OSD Header config1
#define OSD_HDR_C1_BS				0x10
#define OSD_HDR_C1_BL2				0x04
#define OSD_HDR_C1_BL				0x01

// OSD control register
#define OSD_CTRL_COLOR_MODE_YUV		(0 << 10)
#define OSD_CTRL_COLOR_MODE_RGB		(1 << 10)
#define OSD_CTRL_NOT_FETCH_EN		(1 << 8)
#define OSD_CTRL_CLUT_FMT_GBRA		(0 << 7)
#define OSD_CTRL_CLUT_FMT_ARGB		(1 << 7)
#define OSD_CTRL_LATCH_EN			(1 << 5)
#define OSD_CTRL_A32B32_EN			(1 << 4)
#define OSD_CTRL_FIFO_DEPTH			(7 << 0)

/**************************************************************************
 *                              M A C R O S                               *
 **************************************************************************/

/**************************************************************************
 *                          D A T A    T Y P E S                          *
 **************************************************************************/

/**************************************************************************
 *                         G L O B A L    D A T A                         *
 **************************************************************************/
u32 gpOsdHeader_phy[8];
/**************************************************************************
 *             F U N C T I O N    I M P L E M E N T A T I O N S           *
 **************************************************************************/
void DRV_OSD_Init()
{
	printf("DRV_OSD_Init \n");

}

void DRV_OSD_Set_UI_Init(int w,int h, enum DRV_OsdRegionFormat_e fmt)
{
	printf("DRV_OSD_Set_UI_Init w %d h %d fmt %d \n", w, h, fmt);
	#if 0
	//OSD
	G196_OSD0_REG->osd_ctrl = OSD_CTRL_COLOR_MODE_RGB
		| OSD_CTRL_CLUT_FMT_ARGB
		| OSD_CTRL_LATCH_EN
		| OSD_CTRL_A32B32_EN
		| OSD_CTRL_FIFO_DEPTH;
	if (fmt == DRV_OSD_REGION_FORMAT_8BPP)
		gpOsdHeader_phy[0] = SWAP32(0x82001000);
	else
		gpOsdHeader_phy[0] = SWAP32(0x00001000 | (fmt << 24)); //SWAP32(0x82001000);
	gpOsdHeader_phy[1] = SWAP32(w <<16 | h);
	gpOsdHeader_phy[2] = 0;
	gpOsdHeader_phy[3] = 0;
	gpOsdHeader_phy[4] = 0;
	if (fmt == DRV_OSD_REGION_FORMAT_YUY2)
		gpOsdHeader_phy[5] = SWAP32(0x00040000 | w);
	else
		gpOsdHeader_phy[5] = SWAP32(0x00010000 | w);
	gpOsdHeader_phy[6] = SWAP32(0xFFFFFFE0);
	gpOsdHeader_phy[7] = SWAP32(0x1ee00000);

	G196_OSD0_REG->osd_base_addr = (int)&gpOsdHeader_phy;
	G196_OSD0_REG->osd_hvld_offset = 0;
	G196_OSD0_REG->osd_vvld_offset = 0;
	G196_OSD0_REG->osd_hvld_width = w;
	G196_OSD0_REG->osd_vvld_height = h;
	G196_OSD0_REG->osd_bist_ctrl = 0x0;
	G196_OSD0_REG->osd_3d_h_offset = 0x0;
	G196_OSD0_REG->osd_src_decimation_sel = 0x0;

	G196_OSD0_REG->osd_en = 1;

	//GPOST bypass
	G206_GPOST_REG->gpost0_config = 0;
	G206_GPOST_REG->gpost0_master_en = 0;
	G206_GPOST_REG->gpost0_bg1 = 0x8010;
	G206_GPOST_REG->gpost0_bg2 = 0x0080;

	//GPOST PQ disable
	G206_GPOST_REG->gpost0_contrast_config = 0x0;
	#endif
	
}

#ifdef OSD0_FETCH_EN
unsigned char osd0_header_yuy2[32] __attribute__((aligned(1024))) = {
	0x04, 0x00, 0x10, 0x00, 0x01, 0xE0, 0x03, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x03, 0x20, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x3f, 0x18, 0x00
};
unsigned char osd0_header_rgb565[32] __attribute__((aligned(1024))) = {
	0x08, 0x00, 0x10, 0x00, 0x01, 0xE0, 0x03, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x20, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x39, 0x0C, 0x00
};
unsigned char osd0_header_argb1555[32] __attribute__((aligned(1024))) = {
	0x09, 0x00, 0x10, 0x00, 0x01, 0xE0, 0x03, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x20, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x39, 0x0C, 0x00
};
unsigned char osd0_header_rgba4444[32] __attribute__((aligned(1024))) = {
	0x0a, 0x00, 0x10, 0x00, 0x01, 0xE0, 0x03, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x20, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x39, 0x0C, 0x00
};
unsigned char osd0_header_argb4444[32] __attribute__((aligned(1024))) = {
	0x0b, 0x00, 0x10, 0x00, 0x01, 0xE0, 0x03, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x20, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x39, 0x0C, 0x00
};
unsigned char osd0_header_rgba8888[32] __attribute__((aligned(1024))) = {
	0x0d, 0x00, 0x10, 0x00, 0x01, 0xE0, 0x03, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x20, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x39, 0x0C, 0x00
};
unsigned char osd0_header_argb8888_full[32] __attribute__((aligned(1024))) = {
	0x0e, 0x00, 0x10, 0x00, 0x01, 0xE0, 0x03, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x20, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x44, 0xc8, 0x00
};
unsigned char osd0_header_argb8888_half[32] __attribute__((aligned(1024))) = {
	0x0e, 0x00, 0x10, 0x00, 0x01, 0xE0, 0x03, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x20, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x62, 0x40, 0x00
};

unsigned char osd0_header_yuy2_1[32] __attribute__((aligned(1024))) = {
	0x04, 0x00, 0x10, 0x00, 0x01, 0xE0, 0x02, 0xD0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x02, 0xD0, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x7e, 0xf8, 0x00
};
unsigned char osd0_header_rgb565_1[32] __attribute__((aligned(1024))) = {
	0x08, 0x00, 0x10, 0x00, 0x01, 0xE0, 0x02, 0xD0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xD0, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x39, 0x0C, 0x00
};
unsigned char osd0_header_argb1555_1[32] __attribute__((aligned(1024))) = {
	0x09, 0x00, 0x10, 0x00, 0x01, 0xE0, 0x02, 0xD0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xD0, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x39, 0x0C, 0x00
};
unsigned char osd0_header_rgba4444_1[32] __attribute__((aligned(1024))) = {
	0x0a, 0x00, 0x10, 0x00, 0x01, 0xE0, 0x02, 0xD0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xD0, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x39, 0x0C, 0x00
};
unsigned char osd0_header_argb4444_1[32] __attribute__((aligned(1024))) = {
	0x0b, 0x00, 0x10, 0x00, 0x01, 0xE0, 0x02, 0xD0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xD0, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x39, 0x0C, 0x00
};
unsigned char osd0_header_rgba8888_1[32] __attribute__((aligned(1024))) = {
	0x0d, 0x00, 0x10, 0x00, 0x01, 0xE0, 0x02, 0xD0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xD0, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x39, 0x0C, 0x00
};
unsigned char osd0_header_argb8888_full_1[32] __attribute__((aligned(1024))) = {
	0x0e, 0x00, 0x10, 0x00, 0x01, 0xE0, 0x02, 0xD0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xD0, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x44, 0xc8, 0x00
};
unsigned char osd0_header_argb8888_half_1[32] __attribute__((aligned(1024))) = {
	0x0e, 0x00, 0x10, 0x00, 0x01, 0xE0, 0x02, 0xD0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xD0, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x9e, 0x9c, 0x00
};
#endif

void osd0_data_addr_list(void)
{
	#ifdef OSD0_FETCH_EN
	printf("osd0_fetch_ARGB8bpp_800X480_data00=0x%08x \n", osd0_fetch_ARGB8bpp_800X480_data00);	
	printf("osd0_fetch_YUY2_800X480_data00=0x%08x \n", osd0_fetch_YUY2_800X480_data00);	
	//printf("osd0_fetch_ARGB8888_800X480_data00_full=0x%08x \n", osd0_fetch_ARGB8888_800X480_data00_full);
	printf("osd0_fetch_ARGB8888_800X480_data00_half=0x%08x \n", osd0_fetch_ARGB8888_800X480_data00_half);

	printf("osd0_fetch_ARGB8bpp_720X480_data00=0x%08x \n", osd0_fetch_ARGB8bpp_720X480_data00);	
	printf("osd0_fetch_YUY2_720X480_data00=0x%08x \n", osd0_fetch_YUY2_720X480_data00);	
	//printf("osd0_fetch_ARGB8888_720X480_data00_full=0x%08x \n", osd0_fetch_ARGB8888_720X480_data00_full);
	printf("osd0_fetch_ARGB8888_720X480_data00_half=0x%08x \n", osd0_fetch_ARGB8888_720X480_data00_half);

	#if 0
	disp_osd_8bpp_pal_grey[7] = SWAP32(((u32)&osd0_fetch_ARGB8bpp_800X480_data00));
	osd0_header_yuy2[28] = (unsigned char)(((u32)&osd0_fetch_YUY2_800X480_data00)>>24);
	osd0_header_yuy2[29] = (unsigned char)(((u32)&osd0_fetch_YUY2_800X480_data00)>>16);
	osd0_header_yuy2[30] = (unsigned char)(((u32)&osd0_fetch_YUY2_800X480_data00)>>8);
	osd0_header_yuy2[31] = (unsigned char)(((u32)&osd0_fetch_YUY2_800X480_data00)>>0);
	osd0_header_argb8888_half[28] = (unsigned char)(((u32)&osd0_fetch_ARGB8888_800X480_data00_half)>>24);
	osd0_header_argb8888_half[29] = (unsigned char)(((u32)&osd0_fetch_ARGB8888_800X480_data00_half)>>16);
	osd0_header_argb8888_half[30] = (unsigned char)(((u32)&osd0_fetch_ARGB8888_800X480_data00_half)>>8);
	osd0_header_argb8888_half[31] = (unsigned char)(((u32)&osd0_fetch_ARGB8888_800X480_data00_half)>>0);

	disp_osd_8bpp_pal_grey_1[7] = SWAP32(((u32)&osd0_fetch_ARGB8bpp_720X480_data00));
	osd0_header_yuy2_1[28] = (unsigned char)(((u32)&osd0_fetch_YUY2_720X480_data00)>>24);
	osd0_header_yuy2_1[29] = (unsigned char)(((u32)&osd0_fetch_YUY2_720X480_data00)>>16);
	osd0_header_yuy2_1[30] = (unsigned char)(((u32)&osd0_fetch_YUY2_720X480_data00)>>8);
	osd0_header_yuy2_1[31] = (unsigned char)(((u32)&osd0_fetch_YUY2_720X480_data00)>>0);
	osd0_header_argb8888_half_1[28] = (unsigned char)(((u32)&osd0_fetch_ARGB8888_720X480_data00_half)>>24);
	osd0_header_argb8888_half_1[29] = (unsigned char)(((u32)&osd0_fetch_ARGB8888_720X480_data00_half)>>16);
	osd0_header_argb8888_half_1[30] = (unsigned char)(((u32)&osd0_fetch_ARGB8888_720X480_data00_half)>>8);
	osd0_header_argb8888_half_1[31] = (unsigned char)(((u32)&osd0_fetch_ARGB8888_720X480_data00_half)>>0);
	#endif
	#else
	printf("osd0_data_addr_list not support \n");
	#endif
}

void osd0_setting(int w, int h, int input_fmt)
{
#ifdef OSD0_FETCH_EN
	printf("osd0 setting w=%d h=%d \n",w,h);

	if (input_fmt == 2) {
		printf("input_fmt 8bpp \n");

		#ifdef OSD0_FETCH_DATA_8bpp
		printf("disp_osd_8bpp_pal_grey=0x%08x \n", disp_osd_8bpp_pal_grey);
		printf("osd0_fetch_ARGB8bpp_800X480_data00=0x%08x \n", osd0_fetch_ARGB8bpp_800X480_data00);	

		#if 1
		disp_osd_8bpp_pal_grey[7] = SWAP32(((u32)&osd0_fetch_ARGB8bpp_800X480_data00));
		#endif

		HAL_DCACHE_FLUSH(disp_osd_8bpp_pal_grey, 128+1024);
		G196_OSD0_REG->osd_base_addr = (int)&disp_osd_8bpp_pal_grey;

		printf("*** [S] dump disp_osd_8bpp_pal_grey info *** \n");
		printf("0x%08x 0x%08x 0x%08x 0x%08x \n", disp_osd_8bpp_pal_grey[0],disp_osd_8bpp_pal_grey[1],disp_osd_8bpp_pal_grey[2],disp_osd_8bpp_pal_grey[3]);
		printf("0x%08x 0x%08x 0x%08x 0x%08x \n", disp_osd_8bpp_pal_grey[4],disp_osd_8bpp_pal_grey[5],disp_osd_8bpp_pal_grey[6],disp_osd_8bpp_pal_grey[7]);
		printf("0x%08x 0x%08x 0x%08x 0x%08x \n", disp_osd_8bpp_pal_grey[56],disp_osd_8bpp_pal_grey[57],disp_osd_8bpp_pal_grey[58],disp_osd_8bpp_pal_grey[59]);
		printf("0x%08x 0x%08x 0x%08x 0x%08x \n", disp_osd_8bpp_pal_grey[60],disp_osd_8bpp_pal_grey[61],disp_osd_8bpp_pal_grey[62],disp_osd_8bpp_pal_grey[63]);
		printf("*** [E] dump disp_osd_8bpp_pal_grey info *** \n");
		#else
		printf("8bpp not support \n");
		#endif

	}
	else if(input_fmt == 4) {
		printf("input_fmt yuy2 \n");

		#ifdef OSD0_FETCH_DATA_YUY2
		printf("osd0_header_yuy2=0x%08x \n", osd0_header_yuy2);
		printf("osd0_fetch_YUY2_800X480_data00=0x%08x \n", osd0_fetch_YUY2_800X480_data00);		

		#if 1
		osd0_header_yuy2[28] = (unsigned char)(((u32)&osd0_fetch_YUY2_800X480_data00)>>24);
		osd0_header_yuy2[29] = (unsigned char)(((u32)&osd0_fetch_YUY2_800X480_data00)>>16);
		osd0_header_yuy2[30] = (unsigned char)(((u32)&osd0_fetch_YUY2_800X480_data00)>>8);
		osd0_header_yuy2[31] = (unsigned char)(((u32)&osd0_fetch_YUY2_800X480_data00)>>0);
		#endif

		HAL_DCACHE_FLUSH(osd0_header_yuy2, 32);
		G196_OSD0_REG->osd_base_addr = (int)&osd0_header_yuy2;

		printf("*** [S] dump osd0_header_yuy2 info *** \n");
		printf("0x%02x 0x%02x 0x%02x 0x%02x ", osd0_header_yuy2[0],osd0_header_yuy2[1],osd0_header_yuy2[2],osd0_header_yuy2[3]);
		printf("0x%02x 0x%02x 0x%02x 0x%02x \n", osd0_header_yuy2[4],osd0_header_yuy2[5],osd0_header_yuy2[6],osd0_header_yuy2[7]);
		printf("0x%02x 0x%02x 0x%02x 0x%02x ", osd0_header_yuy2[8],osd0_header_yuy2[9],osd0_header_yuy2[10],osd0_header_yuy2[11]);
		printf("0x%02x 0x%02x 0x%02x 0x%02x \n", osd0_header_yuy2[12],osd0_header_yuy2[13],osd0_header_yuy2[14],osd0_header_yuy2[15]);
		printf("0x%02x 0x%02x 0x%02x 0x%02x ", osd0_header_yuy2[16],osd0_header_yuy2[17],osd0_header_yuy2[18],osd0_header_yuy2[19]);
		printf("0x%02x 0x%02x 0x%02x 0x%02x \n", osd0_header_yuy2[20],osd0_header_yuy2[21],osd0_header_yuy2[22],osd0_header_yuy2[23]);
		printf("0x%02x 0x%02x 0x%02x 0x%02x ", osd0_header_yuy2[24],osd0_header_yuy2[25],osd0_header_yuy2[26],osd0_header_yuy2[27]);
		printf("0x%02x 0x%02x 0x%02x 0x%02x \n", osd0_header_yuy2[28],osd0_header_yuy2[29],osd0_header_yuy2[30],osd0_header_yuy2[31]);
		printf("*** [E] dump osd0_header_yuy2 info *** \n");
		#else
		printf("yuy2 not support \n");
		#endif
	}
	else if(input_fmt == 8) {
		printf("input_fmt rgb565 \n");
		
		#ifdef OSD0_FETCH_DATA_RGB565
		printf("osd0_header_rgb565=0x%08x \n", osd0_header_rgb565);
		printf("osd0_fetch_RGB565_800X480_data00=0x%08x \n", osd0_fetch_RGB565_800X480_data00);	

		#if 1
		osd0_header_rgb565[28] = (unsigned char)(((u32)&osd0_fetch_RGB565_800X480_data00)>>24);
		osd0_header_rgb565[29] = (unsigned char)(((u32)&osd0_fetch_RGB565_800X480_data00)>>16);
		osd0_header_rgb565[30] = (unsigned char)(((u32)&osd0_fetch_RGB565_800X480_data00)>>8);
		osd0_header_rgb565[31] = (unsigned char)(((u32)&osd0_fetch_RGB565_800X480_data00)>>0);
		#endif

		HAL_DCACHE_FLUSH(osd0_header_rgb565, 32);
		G196_OSD0_REG->osd_base_addr = (int)&osd0_header_rgb565;
		#else
		printf("rgb565 not support \n");
		#endif
	}
	else if(input_fmt == 9) {
		printf("input_fmt argb1555 \n");
		
		#ifdef OSD0_FETCH_DATA_ARGB1555
		printf("osd0_header_argb1555=0x%08x \n", osd0_header_argb1555);
		printf("osd0_fetch_ARGB1555_800X480_data00=0x%08x \n", osd0_fetch_ARGB1555_800X480_data00);	

		#if 1
		osd0_header_argb1555[28] = (unsigned char)(((u32)&osd0_fetch_ARGB1555_800X480_data00)>>24);
		osd0_header_argb1555[29] = (unsigned char)(((u32)&osd0_fetch_ARGB1555_800X480_data00)>>16);
		osd0_header_argb1555[30] = (unsigned char)(((u32)&osd0_fetch_ARGB1555_800X480_data00)>>8);
		osd0_header_argb1555[31] = (unsigned char)(((u32)&osd0_fetch_ARGB1555_800X480_data00)>>0);
		#endif

		HAL_DCACHE_FLUSH(osd0_header_argb1555, 32);
		G196_OSD0_REG->osd_base_addr = (int)&osd0_header_argb1555;
		#else
		printf("argb1555 not support \n");
		#endif
	}
	else if(input_fmt == 10) {
		printf("input_fmt rgba4444 \n");
		
		#ifdef OSD0_FETCH_DATA_RGBA4444
		printf("osd0_header_rgba4444=0x%08x \n", osd0_header_rgba4444);
		printf("osd0_fetch_RGBA4444_800X480_data00=0x%08x \n", osd0_fetch_RGBA4444_800X480_data00);	

		#if 1
		osd0_header_rgba4444[28] = (unsigned char)(((u32)&osd0_fetch_RGBA4444_800X480_data00)>>24);
		osd0_header_rgba4444[29] = (unsigned char)(((u32)&osd0_fetch_RGBA4444_800X480_data00)>>16);
		osd0_header_rgba4444[30] = (unsigned char)(((u32)&osd0_fetch_RGBA4444_800X480_data00)>>8);
		osd0_header_rgba4444[31] = (unsigned char)(((u32)&osd0_fetch_RGBA4444_800X480_data00)>>0);
		#endif

		HAL_DCACHE_FLUSH(osd0_header_rgba4444, 32);
		G196_OSD0_REG->osd_base_addr = (int)&osd0_header_rgba4444;
		#else
		printf("rgba4444 not support \n");
		#endif
	}
	else if(input_fmt == 11) {
		printf("input_fmt argb4444 \n");
		
		#ifdef OSD0_FETCH_DATA_ARGB4444
		printf("osd0_header_argb4444=0x%08x \n", osd0_header_argb4444);
		printf("osd0_fetch_ARGB4444_800X480_data00=0x%08x \n", osd0_fetch_ARGB4444_800X480_data00);	

		#if 1
		osd0_header_argb4444[28] = (unsigned char)(((u32)&osd0_fetch_ARGB4444_800X480_data00)>>24);
		osd0_header_argb4444[29] = (unsigned char)(((u32)&osd0_fetch_ARGB4444_800X480_data00)>>16);
		osd0_header_argb4444[30] = (unsigned char)(((u32)&osd0_fetch_ARGB4444_800X480_data00)>>8);
		osd0_header_argb4444[31] = (unsigned char)(((u32)&osd0_fetch_ARGB4444_800X480_data00)>>0);
		#endif

		HAL_DCACHE_FLUSH(osd0_header_argb4444, 32);
		G196_OSD0_REG->osd_base_addr = (int)&osd0_header_argb4444;
		#else
		printf("argb4444 not support \n");
		#endif
	}
	else if(input_fmt == 13) {
		printf("input_fmt rgba8888 \n");
		
		#ifdef OSD0_FETCH_DATA_RGBA8888
		printf("osd0_header_rgba8888=0x%08x \n", osd0_header_rgba8888);
		printf("osd0_fetch_RGBA8888_800X480_data00=0x%08x \n", osd0_fetch_RGBA8888_800X480_data00);	

		#if 1
		osd0_header_rgba8888[28] = (unsigned char)(((u32)&osd0_fetch_RGBA8888_800X480_data00)>>24);
		osd0_header_rgba8888[29] = (unsigned char)(((u32)&osd0_fetch_RGBA8888_800X480_data00)>>16);
		osd0_header_rgba8888[30] = (unsigned char)(((u32)&osd0_fetch_RGBA8888_800X480_data00)>>8);
		osd0_header_rgba8888[31] = (unsigned char)(((u32)&osd0_fetch_RGBA8888_800X480_data00)>>0);
		#endif

		HAL_DCACHE_FLUSH(osd0_header_rgba8888, 32);
		G196_OSD0_REG->osd_base_addr = (int)&osd0_header_rgba8888;
		#else
		printf("rgba8888 not support \n");
		#endif
	}
	else if(input_fmt == 14) {
		printf("input_fmt argb8888 \n");

		#ifdef OSD0_FETCH_DATA_ARGB8888
		//printf("osd0_header_argb8888_full=0x%08x \n", osd0_header_argb8888_full);
		printf("osd0_header_argb8888_half=0x%08x \n", osd0_header_argb8888_half);
		//printf("osd0_fetch_ARGB8888_800X480_data00_full=0x%08x \n", osd0_fetch_ARGB8888_800X480_data00_full);
		printf("osd0_fetch_ARGB8888_800X480_data00_half=0x%08x \n", osd0_fetch_ARGB8888_800X480_data00_half);

		#if 1
		osd0_header_argb8888_half[28] = (unsigned char)(((u32)&osd0_fetch_ARGB8888_800X480_data00_half)>>24);
		osd0_header_argb8888_half[29] = (unsigned char)(((u32)&osd0_fetch_ARGB8888_800X480_data00_half)>>16);
		osd0_header_argb8888_half[30] = (unsigned char)(((u32)&osd0_fetch_ARGB8888_800X480_data00_half)>>8);
		osd0_header_argb8888_half[31] = (unsigned char)(((u32)&osd0_fetch_ARGB8888_800X480_data00_half)>>0);
		#endif

		HAL_DCACHE_FLUSH(osd0_header_argb8888_half, 32);
		//G196_OSD0_REG->osd_base_addr = (int)&osd0_header_argb8888_full;
		G196_OSD0_REG->osd_base_addr = (int)&osd0_header_argb8888_half;

		printf("*** [S] dump osd0_header_argb8888_half info *** \n");
		printf("0x%02x 0x%02x 0x%02x 0x%02x ", osd0_header_argb8888_half[0],osd0_header_argb8888_half[1],osd0_header_argb8888_half[2],osd0_header_argb8888_half[3]);
		printf("0x%02x 0x%02x 0x%02x 0x%02x \n", osd0_header_argb8888_half[4],osd0_header_argb8888_half[5],osd0_header_argb8888_half[6],osd0_header_argb8888_half[7]);
		printf("0x%02x 0x%02x 0x%02x 0x%02x ", osd0_header_argb8888_half[8],osd0_header_argb8888_half[9],osd0_header_argb8888_half[10],osd0_header_argb8888_half[11]);
		printf("0x%02x 0x%02x 0x%02x 0x%02x \n", osd0_header_argb8888_half[12],osd0_header_argb8888_half[13],osd0_header_argb8888_half[14],osd0_header_argb8888_half[15]);
		printf("0x%02x 0x%02x 0x%02x 0x%02x ", osd0_header_argb8888_half[16],osd0_header_argb8888_half[17],osd0_header_argb8888_half[18],osd0_header_argb8888_half[19]);
		printf("0x%02x 0x%02x 0x%02x 0x%02x \n", osd0_header_argb8888_half[20],osd0_header_argb8888_half[21],osd0_header_argb8888_half[22],osd0_header_argb8888_half[23]);
		printf("0x%02x 0x%02x 0x%02x 0x%02x ", osd0_header_argb8888_half[24],osd0_header_argb8888_half[25],osd0_header_argb8888_half[26],osd0_header_argb8888_half[27]);
		printf("0x%02x 0x%02x 0x%02x 0x%02x \n", osd0_header_argb8888_half[28],osd0_header_argb8888_half[29],osd0_header_argb8888_half[30],osd0_header_argb8888_half[31]);
		printf("*** [E] dump osd0_header_argb8888_half info *** \n");
		#else
		printf("argb8888 not support \n");
		#endif
	}

	G196_OSD0_REG->osd_ctrl = OSD_CTRL_COLOR_MODE_RGB
		| OSD_CTRL_CLUT_FMT_ARGB
		| OSD_CTRL_LATCH_EN
		| OSD_CTRL_A32B32_EN
		| OSD_CTRL_FIFO_DEPTH;

	G196_OSD0_REG->osd_hvld_offset = 0;
	G196_OSD0_REG->osd_vvld_offset = 0;

	G196_OSD0_REG->osd_hvld_width = w;
	G196_OSD0_REG->osd_vvld_height = h;

	//G196_OSD0_REG->osd_data_fetch_ctrl = 0x0af8;
	G196_OSD0_REG->osd_bist_ctrl = 0x0;
	G196_OSD0_REG->osd_3d_h_offset = 0x0;
	G196_OSD0_REG->osd_src_decimation_sel = 0x0;
	
	G196_OSD0_REG->osd_en = 1;

	//GPOST bypass
	G206_GPOST_REG->gpost0_config = 0;
	G206_GPOST_REG->gpost0_master_en = 0;
	G206_GPOST_REG->gpost0_bg1 = 0x8010;
	G206_GPOST_REG->gpost0_bg2 = 0x0080;

	//GPOST PQ disable
	G206_GPOST_REG->gpost0_contrast_config = 0x0;
#else
	printf("OSD0 FETCH DATA disable \n");
#endif
}

void osd0_setting_hdmi(int w, int h, int input_fmt)
{
#ifdef OSD0_FETCH_EN
	printf("osd0 setting hdmi w=%d h=%d \n",w,h);

	if (input_fmt == 2) {
		printf("input_fmt 8bpp \n");

		#ifdef OSD0_FETCH_DATA_8bpp
		printf("disp_osd_8bpp_pal_grey_1=0x%08x \n", disp_osd_8bpp_pal_grey_1);
		printf("osd0_fetch_ARGB8bpp_720X480_data00=0x%08x \n", osd0_fetch_ARGB8bpp_720X480_data00);	

		#if 1
		disp_osd_8bpp_pal_grey_1[7] = SWAP32(((u32)&osd0_fetch_ARGB8bpp_720X480_data00));
		#endif

		HAL_DCACHE_FLUSH(disp_osd_8bpp_pal_grey_1, 128+1024);
		G196_OSD0_REG->osd_base_addr = (int)&disp_osd_8bpp_pal_grey_1;

		printf("*** [S] dump disp_osd_8bpp_pal_grey info *** \n");
		printf("0x%08x 0x%08x 0x%08x 0x%08x \n", disp_osd_8bpp_pal_grey_1[0],disp_osd_8bpp_pal_grey_1[1],disp_osd_8bpp_pal_grey_1[2],disp_osd_8bpp_pal_grey_1[3]);
		printf("0x%08x 0x%08x 0x%08x 0x%08x \n", disp_osd_8bpp_pal_grey_1[4],disp_osd_8bpp_pal_grey_1[5],disp_osd_8bpp_pal_grey_1[6],disp_osd_8bpp_pal_grey_1[7]);
		printf("0x%08x 0x%08x 0x%08x 0x%08x \n", disp_osd_8bpp_pal_grey_1[56],disp_osd_8bpp_pal_grey_1[57],disp_osd_8bpp_pal_grey_1[58],disp_osd_8bpp_pal_grey_1[59]);
		printf("0x%08x 0x%08x 0x%08x 0x%08x \n", disp_osd_8bpp_pal_grey_1[60],disp_osd_8bpp_pal_grey_1[61],disp_osd_8bpp_pal_grey_1[62],disp_osd_8bpp_pal_grey_1[63]);
		printf("*** [E] dump disp_osd_8bpp_pal_grey info *** \n");
		#else
		printf("8bpp not support \n");
		#endif
	}
	else if(input_fmt == 4) {
		printf("input_fmt yuy2 \n");

		#ifdef OSD0_FETCH_DATA_YUY2
		printf("osd0_header_yuy2_1=0x%08x \n", osd0_header_yuy2_1);
		printf("osd0_fetch_YUY2_720X480_data00=0x%08x \n", osd0_fetch_YUY2_720X480_data00);		

		#if 1
		osd0_header_yuy2_1[28] = (unsigned char)(((u32)&osd0_fetch_YUY2_720X480_data00)>>24);
		osd0_header_yuy2_1[29] = (unsigned char)(((u32)&osd0_fetch_YUY2_720X480_data00)>>16);
		osd0_header_yuy2_1[30] = (unsigned char)(((u32)&osd0_fetch_YUY2_720X480_data00)>>8);
		osd0_header_yuy2_1[31] = (unsigned char)(((u32)&osd0_fetch_YUY2_720X480_data00)>>0);
		#endif

		HAL_DCACHE_FLUSH(osd0_header_yuy2_1, 32);
		G196_OSD0_REG->osd_base_addr = (int)&osd0_header_yuy2_1;

		printf("*** [S] dump osd0_header_yuy2 info *** \n");
		printf("0x%02x 0x%02x 0x%02x 0x%02x ", osd0_header_yuy2_1[0],osd0_header_yuy2_1[1],osd0_header_yuy2_1[2],osd0_header_yuy2_1[3]);
		printf("0x%02x 0x%02x 0x%02x 0x%02x \n", osd0_header_yuy2_1[4],osd0_header_yuy2_1[5],osd0_header_yuy2_1[6],osd0_header_yuy2_1[7]);
		printf("0x%02x 0x%02x 0x%02x 0x%02x ", osd0_header_yuy2_1[8],osd0_header_yuy2_1[9],osd0_header_yuy2_1[10],osd0_header_yuy2_1[11]);
		printf("0x%02x 0x%02x 0x%02x 0x%02x \n", osd0_header_yuy2_1[12],osd0_header_yuy2_1[13],osd0_header_yuy2_1[14],osd0_header_yuy2_1[15]);
		printf("0x%02x 0x%02x 0x%02x 0x%02x ", osd0_header_yuy2_1[16],osd0_header_yuy2_1[17],osd0_header_yuy2_1[18],osd0_header_yuy2_1[19]);
		printf("0x%02x 0x%02x 0x%02x 0x%02x \n", osd0_header_yuy2_1[20],osd0_header_yuy2_1[21],osd0_header_yuy2_1[22],osd0_header_yuy2_1[23]);
		printf("0x%02x 0x%02x 0x%02x 0x%02x ", osd0_header_yuy2_1[24],osd0_header_yuy2_1[25],osd0_header_yuy2_1[26],osd0_header_yuy2_1[27]);
		printf("0x%02x 0x%02x 0x%02x 0x%02x \n", osd0_header_yuy2_1[28],osd0_header_yuy2_1[29],osd0_header_yuy2_1[30],osd0_header_yuy2_1[31]);
		printf("*** [E] dump osd0_header_yuy2 info *** \n");
		#else
		printf("yuy2 not support \n");
		#endif
	}
	else if(input_fmt == 8) {
		printf("input_fmt rgb565 \n");

		#ifdef OSD0_FETCH_DATA_RGB565
		printf("osd0_header_rgb565_1=0x%08x \n", osd0_header_rgb565_1);
		printf("osd0_fetch_RGB565_720X480_data00=0x%08x \n", osd0_fetch_RGB565_720X480_data00);	

		#if 1
		osd0_header_rgb565_1[28] = (unsigned char)(((u32)&osd0_fetch_RGB565_720X480_data00)>>24);
		osd0_header_rgb565_1[29] = (unsigned char)(((u32)&osd0_fetch_RGB565_720X480_data00)>>16);
		osd0_header_rgb565_1[30] = (unsigned char)(((u32)&osd0_fetch_RGB565_720X480_data00)>>8);
		osd0_header_rgb565_1[31] = (unsigned char)(((u32)&osd0_fetch_RGB565_720X480_data00)>>0);
		#endif

		HAL_DCACHE_FLUSH(osd0_header_rgb565_1, 32);
		G196_OSD0_REG->osd_base_addr = (int)&osd0_header_rgb565_1;
		#else
		printf("rgb565 not support \n");
		#endif
	}
	else if(input_fmt == 9) {
		printf("input_fmt argb1555 \n");

		#ifdef OSD0_FETCH_DATA_ARGB1555
		printf("osd0_header_argb1555_1=0x%08x \n", osd0_header_argb1555_1);
		printf("osd0_fetch_ARGB1555_720X480_data00=0x%08x \n", osd0_fetch_ARGB1555_720X480_data00);	

		#if 1
		osd0_header_argb1555_1[28] = (unsigned char)(((u32)&osd0_fetch_ARGB1555_720X480_data00)>>24);
		osd0_header_argb1555_1[29] = (unsigned char)(((u32)&osd0_fetch_ARGB1555_720X480_data00)>>16);
		osd0_header_argb1555_1[30] = (unsigned char)(((u32)&osd0_fetch_ARGB1555_720X480_data00)>>8);
		osd0_header_argb1555_1[31] = (unsigned char)(((u32)&osd0_fetch_ARGB1555_720X480_data00)>>0);
		#endif

		HAL_DCACHE_FLUSH(osd0_header_argb1555_1, 32);
		G196_OSD0_REG->osd_base_addr = (int)&osd0_header_argb1555_1;

		#else
		printf("argb1555 not support \n");
		#endif		
	}
	else if(input_fmt == 10) {
		printf("input_fmt rgba4444 \n");

		#ifdef OSD0_FETCH_DATA_RGBA4444
		printf("osd0_header_rgba4444_1=0x%08x \n", osd0_header_rgba4444_1);
		printf("osd0_fetch_RGBA4444_720X480_data00=0x%08x \n", osd0_fetch_RGBA4444_720X480_data00);	

		#if 1
		osd0_header_rgba4444_1[28] = (unsigned char)(((u32)&osd0_fetch_RGBA4444_720X480_data00)>>24);
		osd0_header_rgba4444_1[29] = (unsigned char)(((u32)&osd0_fetch_RGBA4444_720X480_data00)>>16);
		osd0_header_rgba4444_1[30] = (unsigned char)(((u32)&osd0_fetch_RGBA4444_720X480_data00)>>8);
		osd0_header_rgba4444_1[31] = (unsigned char)(((u32)&osd0_fetch_RGBA4444_720X480_data00)>>0);
		#endif

		HAL_DCACHE_FLUSH(osd0_header_rgba4444_1, 32);
		G196_OSD0_REG->osd_base_addr = (int)&osd0_header_rgba4444_1;
		#else
		printf("rgba4444 not support \n");
		#endif	
	}
	else if(input_fmt == 11) {
		printf("input_fmt argb4444 \n");

		#ifdef OSD0_FETCH_DATA_ARGB4444
		printf("osd0_header_argb4444_1=0x%08x \n", osd0_header_argb4444_1);
		printf("osd0_fetch_ARGB4444_720X480_data00=0x%08x \n", osd0_fetch_ARGB4444_720X480_data00);	

		#if 1
		osd0_header_argb4444_1[28] = (unsigned char)(((u32)&osd0_fetch_ARGB4444_720X480_data00)>>24);
		osd0_header_argb4444_1[29] = (unsigned char)(((u32)&osd0_fetch_ARGB4444_720X480_data00)>>16);
		osd0_header_argb4444_1[30] = (unsigned char)(((u32)&osd0_fetch_ARGB4444_720X480_data00)>>8);
		osd0_header_argb4444_1[31] = (unsigned char)(((u32)&osd0_fetch_ARGB4444_720X480_data00)>>0);
		#endif

		HAL_DCACHE_FLUSH(osd0_header_argb4444_1, 32);
		G196_OSD0_REG->osd_base_addr = (int)&osd0_header_argb4444_1;

		#else
		printf("argb4444 not support \n");
		#endif		
	}
	else if(input_fmt == 13) {
		printf("input_fmt rgba8888 \n");

		#ifdef OSD0_FETCH_DATA_RGBA8888
		printf("osd0_header_rgba8888_1=0x%08x \n", osd0_header_rgba8888_1);
		printf("osd0_fetch_RGBA8888_720X480_data00=0x%08x \n", osd0_fetch_RGBA8888_720X480_data00);	

		#if 1
		osd0_header_rgba8888_1[28] = (unsigned char)(((u32)&osd0_fetch_RGBA8888_720X480_data00)>>24);
		osd0_header_rgba8888_1[29] = (unsigned char)(((u32)&osd0_fetch_RGBA8888_720X480_data00)>>16);
		osd0_header_rgba8888_1[30] = (unsigned char)(((u32)&osd0_fetch_RGBA8888_720X480_data00)>>8);
		osd0_header_rgba8888_1[31] = (unsigned char)(((u32)&osd0_fetch_RGBA8888_720X480_data00)>>0);
		#endif

		HAL_DCACHE_FLUSH(osd0_header_rgba8888_1, 32);
		G196_OSD0_REG->osd_base_addr = (int)&osd0_header_rgba8888_1;
		#else
		printf("rgba8888 not support \n");
		#endif	
	}
	else if(input_fmt == 14) {
		printf("input_fmt argb8888 \n");

		#ifdef OSD0_FETCH_DATA_ARGB8888
		//printf("osd0_header_argb8888_full_1=0x%08x \n", osd0_header_argb8888_full_1);
		printf("osd0_header_argb8888_half_1=0x%08x \n", osd0_header_argb8888_half_1);
		//printf("osd0_fetch_ARGB8888_720X480_data00_full=0x%08x \n", osd0_fetch_ARGB8888_720X480_data00_full);
		printf("osd0_fetch_ARGB8888_720X480_data00_half=0x%08x \n", osd0_fetch_ARGB8888_720X480_data00_half);

		#if 1
		osd0_header_argb8888_half_1[28] = (unsigned char)(((u32)&osd0_fetch_ARGB8888_720X480_data00_half)>>24);
		osd0_header_argb8888_half_1[29] = (unsigned char)(((u32)&osd0_fetch_ARGB8888_720X480_data00_half)>>16);
		osd0_header_argb8888_half_1[30] = (unsigned char)(((u32)&osd0_fetch_ARGB8888_720X480_data00_half)>>8);
		osd0_header_argb8888_half_1[31] = (unsigned char)(((u32)&osd0_fetch_ARGB8888_720X480_data00_half)>>0);
		#endif

		HAL_DCACHE_FLUSH(osd0_header_argb8888_half_1, 32);
		//G196_OSD0_REG->osd_base_addr = (int)&osd0_header_argb8888_full_1;
		G196_OSD0_REG->osd_base_addr = (int)&osd0_header_argb8888_half_1;

		printf("*** [S] dump osd0_header_argb8888_half info *** \n");
		printf("0x%02x 0x%02x 0x%02x 0x%02x ", osd0_header_argb8888_half_1[0],osd0_header_argb8888_half_1[1],osd0_header_argb8888_half_1[2],osd0_header_argb8888_half_1[3]);
		printf("0x%02x 0x%02x 0x%02x 0x%02x \n", osd0_header_argb8888_half_1[4],osd0_header_argb8888_half_1[5],osd0_header_argb8888_half_1[6],osd0_header_argb8888_half_1[7]);
		printf("0x%02x 0x%02x 0x%02x 0x%02x ", osd0_header_argb8888_half_1[8],osd0_header_argb8888_half_1[9],osd0_header_argb8888_half_1[10],osd0_header_argb8888_half_1[11]);
		printf("0x%02x 0x%02x 0x%02x 0x%02x \n", osd0_header_argb8888_half_1[12],osd0_header_argb8888_half_1[13],osd0_header_argb8888_half_1[14],osd0_header_argb8888_half_1[15]);
		printf("0x%02x 0x%02x 0x%02x 0x%02x ", osd0_header_argb8888_half_1[16],osd0_header_argb8888_half_1[17],osd0_header_argb8888_half_1[18],osd0_header_argb8888_half_1[19]);
		printf("0x%02x 0x%02x 0x%02x 0x%02x \n", osd0_header_argb8888_half_1[20],osd0_header_argb8888_half_1[21],osd0_header_argb8888_half_1[22],osd0_header_argb8888_half_1[23]);
		printf("0x%02x 0x%02x 0x%02x 0x%02x ", osd0_header_argb8888_half_1[24],osd0_header_argb8888_half_1[25],osd0_header_argb8888_half_1[26],osd0_header_argb8888_half_1[27]);
		printf("0x%02x 0x%02x 0x%02x 0x%02x \n", osd0_header_argb8888_half_1[28],osd0_header_argb8888_half_1[29],osd0_header_argb8888_half_1[30],osd0_header_argb8888_half_1[31]);
		printf("*** [E] dump osd0_header_argb8888_half info *** \n");
		#else
		printf("argb8888 not support \n");
		#endif	
	}

	G196_OSD0_REG->osd_ctrl = OSD_CTRL_COLOR_MODE_RGB
		| OSD_CTRL_CLUT_FMT_ARGB
		| OSD_CTRL_LATCH_EN
		| OSD_CTRL_A32B32_EN
		| OSD_CTRL_FIFO_DEPTH;

	G196_OSD0_REG->osd_hvld_offset = 0;
	G196_OSD0_REG->osd_vvld_offset = 0;

	G196_OSD0_REG->osd_hvld_width = w;
	G196_OSD0_REG->osd_vvld_height = h;

	//G196_OSD0_REG->osd_data_fetch_ctrl = 0x0af8;
	G196_OSD0_REG->osd_bist_ctrl = 0x0;
	G196_OSD0_REG->osd_3d_h_offset = 0x0;
	G196_OSD0_REG->osd_src_decimation_sel = 0x0;
	
	G196_OSD0_REG->osd_en = 1;

	//GPOST bypass
	G206_GPOST_REG->gpost0_config = 0;
	G206_GPOST_REG->gpost0_master_en = 0;
	G206_GPOST_REG->gpost0_bg1 = 0x8010;
	G206_GPOST_REG->gpost0_bg2 = 0x0080;

	//GPOST PQ disable
	G206_GPOST_REG->gpost0_contrast_config = 0x0;
#else
	printf("OSD0 FETCH DATA disable \n");
#endif
}