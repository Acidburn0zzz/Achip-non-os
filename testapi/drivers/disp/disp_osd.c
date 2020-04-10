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

#ifdef	OSD0_ASCII_FONT_ARIAL_20X20		//BOLD Full-Width
#include "fontdb/SP7021_FONT_ASCII_ARIAL_20X20.c"
#endif
#ifdef	OSD0_ASCII_FONT_ARIAL_10X20		//BOLD Half-Width
#include "fontdb/SP7021_FONT_ASCII_ARIAL_10X20.c"
#endif
#ifdef	OSD0_ASCII_FONT_ARIAL_24X24		//BOLD Full-Width
#include "fontdb/SP7021_FONT_ASCII_ARIAL_24X24.c"
#endif
#ifdef	OSD0_ASCII_FONT_ARIAL_12X24		//BOLD Half-Width
#include "fontdb/SP7021_FONT_ASCII_ARIAL_12X24.c"
#endif
#ifdef	OSD0_ASCII_FONT_ARIAL_32X32		//BOLD Full-Width
#include "fontdb/SP7021_FONT_ASCII_ARIAL_32X32.c"
#endif
#ifdef	OSD0_ASCII_FONT_ARIAL_16X32		//BOLD Half-Width
#include "fontdb/SP7021_FONT_ASCII_ARIAL_16X32.c"
#endif
#ifdef	OSD0_ASCII_FONT_ARIAL_48X48		//BOLD Full-Width
#include "fontdb/SP7021_FONT_ASCII_ARIAL_48X48.c"
#endif
#ifdef	OSD0_ASCII_FONT_ARIAL_24X48		//BOLD Half-Width
#include "fontdb/SP7021_FONT_ASCII_ARIAL_24X48.c"
#endif

#ifdef	OSD0_BIG5_COM_FONT_ARIAL_20X20	//BOLD Full-Width
#include "fontdb/SP7021_FONT_BIG5_COM_20X20.c"
#endif
#ifdef	OSD0_BIG5_COM_FONT_ARIAL_24X24	//BOLD Full-Width
#include "fontdb/SP7021_FONT_BIG5_COM_24X24.c"
#endif
#ifdef	OSD0_BIG5_COM_FONT_ARIAL_32X32	//BOLD Full-Width
#include "fontdb/SP7021_FONT_BIG5_COM_32X32.c"
#endif
#ifdef	OSD0_BIG5_COM_FONT_ARIAL_48X48	//BOLD Full-Width
#include "fontdb/SP7021_FONT_BIG5_COM_48X48.c"
#endif

#ifdef	OSD0_BIG5_EXT_FONT_ARIAL_20X20	//BOLD Full-Width
#include "fontdb/SP7021_FONT_BIG5_EXT_20X20.c"
#endif
#ifdef	OSD0_BIG5_EXT_FONT_ARIAL_24X24	//BOLD Full-Width
#include "fontdb/SP7021_FONT_BIG5_EXT_24X24.c"
#endif
#ifdef	OSD0_BIG5_EXT_FONT_ARIAL_32X32	//BOLD Full-Width
#include "fontdb/SP7021_FONT_BIG5_EXT_32X32.c"
#endif
#ifdef	OSD0_BIG5_EXT_FONT_ARIAL_48X48	//BOLD Full-Width
#include "fontdb/SP7021_FONT_BIG5_EXT_48X48.c"
#endif

#ifdef	OSD0_GB2312_COM_FONT_ARIAL_20X20	//BOLD Full-Width
#include "fontdb/SP7021_FONT_GB2312_COM_20X20.c"
#endif
#ifdef	OSD0_GB2312_COM_FONT_ARIAL_24X24	//BOLD Full-Width
#include "fontdb/SP7021_FONT_GB2312_COM_24X24.c"
#endif
#ifdef	OSD0_GB2312_COM_FONT_ARIAL_32X32	//BOLD Full-Width
#include "fontdb/SP7021_FONT_GB2312_COM_32X32.c"
#endif
#ifdef	OSD0_GB2312_COM_FONT_ARIAL_48X48	//BOLD Full-Width
#include "fontdb/SP7021_FONT_GB2312_COM_48X48.c"
#endif

#ifdef	OSD0_GBK_EXT_FONT_ARIAL_20X20	//BOLD Full-Width
#include "fontdb/SP7021_FONT_GBK_EXT_20X20.c"
#endif
#ifdef	OSD0_GBK_EXT_FONT_ARIAL_24X24	//BOLD Full-Width
#include "fontdb/SP7021_FONT_GBK_EXT_24X24.c"
#endif
#ifdef	OSD0_GBK_EXT_FONT_ARIAL_32X32	//BOLD Full-Width
#include "fontdb/SP7021_FONT_GBK_EXT_32X32.c"
#endif
#ifdef	OSD0_GBK_EXT_FONT_ARIAL_48X48	//BOLD Full-Width
#include "fontdb/SP7021_FONT_GBK_EXT_48X48.c"
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

#ifdef OSD0_API_IMPLEMENT
unsigned char osd0_fetch_data00[OSD0_MAX_WIDTH*OSD0_MAX_HEIGHT*4] __attribute__((aligned(1024))) = {0xFF};
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
			#ifdef OSD0_8BPP_PALETTE_GREY
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
			#endif
			#ifdef OSD0_8BPP_PALETTE_COLOR
		printf("disp_osd_8bpp_pal_color=0x%08x \n", disp_osd_8bpp_pal_color);
		printf("osd0_fetch_ARGB8bpp_800X480_data00=0x%08x \n", osd0_fetch_ARGB8bpp_800X480_data00);	

		#if 1
		disp_osd_8bpp_pal_color[7] = SWAP32(((u32)&osd0_fetch_ARGB8bpp_800X480_data00));
		#endif

		HAL_DCACHE_FLUSH(disp_osd_8bpp_pal_color, 128+1024);
		G196_OSD0_REG->osd_base_addr = (int)&disp_osd_8bpp_pal_color;

		printf("*** [S] dump disp_osd_8bpp_pal_color info *** \n");
		printf("0x%08x 0x%08x 0x%08x 0x%08x \n", disp_osd_8bpp_pal_color[0],disp_osd_8bpp_pal_color[1],disp_osd_8bpp_pal_color[2],disp_osd_8bpp_pal_color[3]);
		printf("0x%08x 0x%08x 0x%08x 0x%08x \n", disp_osd_8bpp_pal_color[4],disp_osd_8bpp_pal_color[5],disp_osd_8bpp_pal_color[6],disp_osd_8bpp_pal_color[7]);
		printf("0x%08x 0x%08x 0x%08x 0x%08x \n", disp_osd_8bpp_pal_color[56],disp_osd_8bpp_pal_color[57],disp_osd_8bpp_pal_color[58],disp_osd_8bpp_pal_color[59]);
		printf("0x%08x 0x%08x 0x%08x 0x%08x \n", disp_osd_8bpp_pal_color[60],disp_osd_8bpp_pal_color[61],disp_osd_8bpp_pal_color[62],disp_osd_8bpp_pal_color[63]);
		printf("*** [E] dump disp_osd_8bpp_pal_color info *** \n");
			#endif			
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
			#ifdef OSD0_8BPP_PALETTE_GREY
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
			#endif
			#ifdef OSD0_8BPP_PALETTE_COLOR
		printf("disp_osd_8bpp_pal_color_1=0x%08x \n", disp_osd_8bpp_pal_color_1);
		printf("osd0_fetch_ARGB8bpp_720X480_data00=0x%08x \n", osd0_fetch_ARGB8bpp_720X480_data00);	

		#if 1
		disp_osd_8bpp_pal_color_1[7] = SWAP32(((u32)&osd0_fetch_ARGB8bpp_720X480_data00));
		#endif

		HAL_DCACHE_FLUSH(disp_osd_8bpp_pal_color_1, 128+1024);
		G196_OSD0_REG->osd_base_addr = (int)&disp_osd_8bpp_pal_color_1;

		printf("*** [S] dump disp_osd_8bpp_pal_color_1 info *** \n");
		printf("0x%08x 0x%08x 0x%08x 0x%08x \n", disp_osd_8bpp_pal_color_1[0],disp_osd_8bpp_pal_color_1[1],disp_osd_8bpp_pal_color_1[2],disp_osd_8bpp_pal_color_1[3]);
		printf("0x%08x 0x%08x 0x%08x 0x%08x \n", disp_osd_8bpp_pal_color_1[4],disp_osd_8bpp_pal_color_1[5],disp_osd_8bpp_pal_color_1[6],disp_osd_8bpp_pal_color_1[7]);
		printf("0x%08x 0x%08x 0x%08x 0x%08x \n", disp_osd_8bpp_pal_color_1[56],disp_osd_8bpp_pal_color_1[57],disp_osd_8bpp_pal_color_1[58],disp_osd_8bpp_pal_color_1[59]);
		printf("0x%08x 0x%08x 0x%08x 0x%08x \n", disp_osd_8bpp_pal_color_1[60],disp_osd_8bpp_pal_color_1[61],disp_osd_8bpp_pal_color_1[62],disp_osd_8bpp_pal_color_1[63]);
		printf("*** [E] dump disp_osd_8bpp_pal_color_1 info *** \n");
			#endif
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

#ifdef OSD0_API_IMPLEMENT

int API_OSD_UI_Init(int w, int h, int input_fmt)
{
	UINT32 UI_width = w;
	UINT32 UI_height = h;

	printf("API_OSD_UI_Init \n");

	if(input_fmt == DRV_OSD_REGION_FORMAT_8BPP)
		osd0_header[0] = SWAP32(0x82001000);
	else
		osd0_header[0] = SWAP32(0x00001000 | (input_fmt << 24));

	osd0_header[1] = SWAP32((UI_height << 16) | UI_width);
	osd0_header[2] = 0;
	osd0_header[3] = 0;
	osd0_header[4] = 0;
	if (input_fmt == DRV_OSD_REGION_FORMAT_YUY2)
		osd0_header[5] = SWAP32(0x00040000 | UI_width);
	else
		osd0_header[5] = SWAP32(0x00010000 | UI_width);
	osd0_header[6] = SWAP32(0xFFFFFFE0);
	osd0_header[7] = SWAP32(((u32)&osd0_fetch_data00));

	G196_OSD0_REG->osd_en = 0;

	HAL_DCACHE_FLUSH(osd0_header, 128+1024); //Update osd0_header

	G196_OSD0_REG->osd_base_addr = (int)&osd0_header;

	G196_OSD0_REG->osd_ctrl = OSD_CTRL_COLOR_MODE_RGB
		| OSD_CTRL_CLUT_FMT_ARGB
		| OSD_CTRL_LATCH_EN
		| OSD_CTRL_A32B32_EN
		| OSD_CTRL_FIFO_DEPTH;

	G196_OSD0_REG->osd_hvld_offset = 0;
	G196_OSD0_REG->osd_vvld_offset = 0;

	G196_OSD0_REG->osd_hvld_width = UI_width;
	G196_OSD0_REG->osd_vvld_height = UI_height;

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

	return 0;
}

extern int disp_init_width;
extern int disp_init_height;
int SP_OSD_DrawPixel(int input_fmt, INT16 x, INT16 y, UINT32 color)
{
	INT16 UI_width = disp_init_width;
	INT16 UI_height = disp_init_height;
	int ptr = 0;

	if (input_fmt == 0x2) {
		ptr = ( x + y * UI_width );
		osd0_fetch_data00[ptr] = (color & 0x000000ff) >> 0;
		HAL_DCACHE_FLUSH(osd0_fetch_data00, UI_width*UI_height);
	}
	else if (input_fmt == 0x4) {
		#if 1
		ptr = ( x + y * UI_width )*2;
		osd0_fetch_data00[ptr] = (color & 0x000000ff) >> 0;
		HAL_DCACHE_FLUSH(osd0_fetch_data00, UI_width*UI_height*2);
		#else
		printf("DrawPixel not support for yuy2 \n");
		#endif
	}
	else if (input_fmt == 0x8) {
		ptr = ( x + y * UI_width )*2;
		osd0_fetch_data00[ptr+0] = (color & 0x00001C00) >> (8-3) | (color & 0x000000f8) >> (0+3);
		osd0_fetch_data00[ptr+1] = (color & 0x00f80000) >> (16+0) | (color & 0x0000E000) >> (8+5);
		HAL_DCACHE_FLUSH(osd0_fetch_data00, UI_width*UI_height*2);
	}
	else if (input_fmt == 0x9) {
		ptr = ( x + y * UI_width )*2;
		osd0_fetch_data00[ptr+0] = (color & 0x00003800) >> (8-2) | (color & 0x000000f8) >> (0+3);
		osd0_fetch_data00[ptr+1] = (color & 0x80000000) >> (24+0) | (color & 0x00f80000) >> (16+1) | (color & 0x0000C000) >> (8+6);
		HAL_DCACHE_FLUSH(osd0_fetch_data00, UI_width*UI_height*2);
	}
	else if (input_fmt == 0xa) {
		ptr = ( x + y * UI_width )*2;
		osd0_fetch_data00[ptr+0] = (color & 0x000000f0) >> (0+0) | (color & 0xf0000000) >> (24+4);
		osd0_fetch_data00[ptr+1] = (color & 0x00f00000) >> (16+0) |(color & 0x0000f000) >> (8+4);
		HAL_DCACHE_FLUSH(osd0_fetch_data00, UI_width*UI_height*2);
	}
	else if (input_fmt == 0xb) {
		ptr = ( x + y * UI_width )*2;
		osd0_fetch_data00[ptr+0] = (color & 0x0000f000) >> (8+0) | (color & 0x000000f0) >> (0+4);
		osd0_fetch_data00[ptr+1] = (color & 0xf0000000) >> (24+0) | (color & 0x00f00000) >> (16+4);
		HAL_DCACHE_FLUSH(osd0_fetch_data00, UI_width*UI_height*2);
	}
	else if (input_fmt == 0xd) {
		ptr = ( x + y * UI_width )*4;
		osd0_fetch_data00[ptr+0] = (color & 0xff000000) >> 24;
		osd0_fetch_data00[ptr+1] = (color & 0x000000ff) >> 0;
		osd0_fetch_data00[ptr+2] = (color & 0x0000ff00) >> 8;
		osd0_fetch_data00[ptr+3] = (color & 0x00ff0000) >> 16;
		HAL_DCACHE_FLUSH(osd0_fetch_data00, UI_width*UI_height*4);
	}
	else if (input_fmt == 0xe) {
		ptr = ( x + y * UI_width )*4;
		osd0_fetch_data00[ptr+0] = (color & 0x000000ff) >> 0;
		osd0_fetch_data00[ptr+1] = (color & 0x0000ff00) >> 8;
		osd0_fetch_data00[ptr+2] = (color & 0x00ff0000) >> 16;
		osd0_fetch_data00[ptr+3] = (color & 0xff000000) >> 24;
		HAL_DCACHE_FLUSH(osd0_fetch_data00, UI_width*UI_height*4);
	}

	return 0;
}

int SP_OSD_DrawHorizLine(int input_fmt, INT16 x, INT16 y, UINT16 len, UINT32 color)
{
	int i;
	INT16 UI_width = disp_init_width;
	INT16 UI_height = disp_init_height;

	if (input_fmt == 0x2) {
		for (i = x; i < x + len ; i++) {
			osd0_fetch_data00[i + y * UI_width] = (color & 0x000000ff) >> 0;
		}
		HAL_DCACHE_FLUSH(osd0_fetch_data00, UI_width*UI_height);
	}
	else if (input_fmt == 0x4) {
		#if 1
		for (i = x; i < x + len ; i++) {
			osd0_fetch_data00[i*2 + y * UI_width*2] = (color & 0x000000ff) >> 0;
		}
		HAL_DCACHE_FLUSH(osd0_fetch_data00, UI_width*UI_height*2);
		#else
		printf("DrawHorizLine not support for yuy2 \n");
		#endif
	}
	else if (input_fmt == 0x8) {
		for (i = x; i < x + len ; i++) {
			osd0_fetch_data00[i*2 + 0 + y * UI_width*2] = (color & 0x00001C00) >> (8-3) | (color & 0x000000f8) >> (0+3);
			osd0_fetch_data00[i*2 + 1 + y * UI_width*2] = (color & 0x00f80000) >> (16+0) | (color & 0x0000E000) >> (8+5);
		}
		HAL_DCACHE_FLUSH(osd0_fetch_data00, UI_width*UI_height*2);
	}
	else if (input_fmt == 0x9) {
		for (i = x; i < x + len ; i++) {
			osd0_fetch_data00[i*2 + 0 + y * UI_width*2] = (color & 0x00003800) >> (8-2) | (color & 0x000000f8) >> (0+3);
			osd0_fetch_data00[i*2 + 1 + y * UI_width*2] = (color & 0x80000000) >> (24+0) | (color & 0x00f80000) >> (16+1) | (color & 0x0000C000) >> (8+6);
		}
		HAL_DCACHE_FLUSH(osd0_fetch_data00, UI_width*UI_height*2);
	}
	else if (input_fmt == 0xa) {
		for (i = x; i < x + len ; i++) {
			osd0_fetch_data00[i*2 + 0 + y * UI_width*2] = (color & 0x000000f0) >> (0+0) | (color & 0xf0000000) >> (24+4);
			osd0_fetch_data00[i*2 + 1 + y * UI_width*2] = (color & 0x00f00000) >> (16+0) |(color & 0x0000f000) >> (8+4);
		}
		HAL_DCACHE_FLUSH(osd0_fetch_data00, UI_width*UI_height*2);
	}
	else if (input_fmt == 0xb) {
		for (i = x; i < x + len ; i++) {
			osd0_fetch_data00[i*2 + 0 + y * UI_width*2] = (color & 0x0000f000) >> (8+0) | (color & 0x000000f0) >> (0+4);
			osd0_fetch_data00[i*2 + 1 + y * UI_width*2] = (color & 0xf0000000) >> (24+0) | (color & 0x00f00000) >> (16+4);
		}
		HAL_DCACHE_FLUSH(osd0_fetch_data00, UI_width*UI_height*2);
	}
	else if (input_fmt == 0xd) {
		for (i = x; i < x + len ; i++) {
			osd0_fetch_data00[i*4 + 0 + y * UI_width*4] = (color & 0xff000000) >> 24;
			osd0_fetch_data00[i*4 + 1 + y * UI_width*4] = (color & 0x000000ff) >> 0;
			osd0_fetch_data00[i*4 + 2 + y * UI_width*4] = (color & 0x0000ff00) >> 8;
			osd0_fetch_data00[i*4 + 3 + y * UI_width*4] = (color & 0x00ff0000) >> 16;
		}
		HAL_DCACHE_FLUSH(osd0_fetch_data00, UI_width*UI_height*4);
	}
	else if (input_fmt == 0xe) {
		for (i = x; i < x + len ; i++) {
			osd0_fetch_data00[i*4 + 0 + y * UI_width*4] = (color & 0x000000ff) >> 0;
			osd0_fetch_data00[i*4 + 1 + y * UI_width*4] = (color & 0x0000ff00) >> 8;
			osd0_fetch_data00[i*4 + 2 + y * UI_width*4] = (color & 0x00ff0000) >> 16;
			osd0_fetch_data00[i*4 + 3 + y * UI_width*4] = (color & 0xff000000) >> 24;
		}
		HAL_DCACHE_FLUSH(osd0_fetch_data00, UI_width*UI_height*4);
	}
	#if 0
	printf("color BYTE0 0x000000ff %d \n",(color & 0x000000ff) >> 0);
	printf("color BYTE1 0x0000ff00 %d \n",(color & 0x0000ff00) >> 8);
	printf("color BYTE2 0x00ff0000 %d \n",(color & 0x00ff0000) >> 16);
	printf("color BYTE3 0xff000000 %d \n",(color & 0xff000000) >> 24);
	#endif

	return 0;
}

int SP_OSD_DrawVertiLine(int input_fmt, INT16 x, INT16 y, UINT16 len, UINT32 color)
{
	int i;
	INT16 UI_width = disp_init_width;
	INT16 UI_height = disp_init_height;

	if (input_fmt == 0x2) {
		for (i = y; i < y + len ; i++) {
			osd0_fetch_data00[x + i * UI_width] = (color & 0x000000ff) >> 0;
		}
		HAL_DCACHE_FLUSH(osd0_fetch_data00, UI_width*UI_height);
	}
	else if (input_fmt == 0x4) {
		#if 1
		for (i = y; i < y + len ; i++) {
			osd0_fetch_data00[x*2 + i * UI_width*2] = (color & 0x000000ff) >> 0;
		}
		HAL_DCACHE_FLUSH(osd0_fetch_data00, UI_width*UI_height*2);
		#else
		printf("DrawVertiLine not support for yuy2 \n");
		#endif
	}
	else if (input_fmt == 0x8) {
		for (i = y; i < y + len ; i++) {
			osd0_fetch_data00[x*2 + 0 + i * UI_width*2] = (color & 0x00001C00) >> (8-3) | (color & 0x000000f8) >> (0+3);
			osd0_fetch_data00[x*2 + 1 + i * UI_width*2] = (color & 0x00f80000) >> (16+0) | (color & 0x0000E000) >> (8+5);
		}
		HAL_DCACHE_FLUSH(osd0_fetch_data00, UI_width*UI_height*2);
	}
	else if (input_fmt == 0x9) {
		for (i = y; i < y + len ; i++) {
			osd0_fetch_data00[x*2 + 0 + i * UI_width*2] = (color & 0x00003800) >> (8-2) | (color & 0x000000f8) >> (0+3);
			osd0_fetch_data00[x*2 + 1 + i * UI_width*2] = (color & 0x80000000) >> (24+0) | (color & 0x00f80000) >> (16+1) | (color & 0x0000C000) >> (8+6);
		}
		HAL_DCACHE_FLUSH(osd0_fetch_data00, UI_width*UI_height*2);
	}
	else if (input_fmt == 0xa) {
		for (i = y; i < y + len ; i++) {
			osd0_fetch_data00[x*2 + 0 + i * UI_width*2] = (color & 0x000000f0) >> (0+0) | (color & 0xf0000000) >> (24+4);
			osd0_fetch_data00[x*2 + 1 + i * UI_width*2] = (color & 0x00f00000) >> (16+0) |(color & 0x0000f000) >> (8+4);
		}
		HAL_DCACHE_FLUSH(osd0_fetch_data00, UI_width*UI_height*2);
	}
	else if (input_fmt == 0xb) {
		for (i = y; i < y + len ; i++) {
			osd0_fetch_data00[x*2 + 0 + i * UI_width*2] = (color & 0x0000f000) >> (8+0) | (color & 0x000000f0) >> (0+4);
			osd0_fetch_data00[x*2 + 1 + i * UI_width*2] = (color & 0xf0000000) >> (24+0) | (color & 0x00f00000) >> (16+4);
		}
		HAL_DCACHE_FLUSH(osd0_fetch_data00, UI_width*UI_height*2);
	}
	else if (input_fmt == 0xd) {
		for (i = y; i < y + len ; i++) {
			osd0_fetch_data00[x*4 + 0 + i * UI_width*4] = (color & 0xff000000) >> 24;
			osd0_fetch_data00[x*4 + 1 + i * UI_width*4] = (color & 0x000000ff) >> 0;
			osd0_fetch_data00[x*4 + 2 + i * UI_width*4] = (color & 0x0000ff00) >> 8;
			osd0_fetch_data00[x*4 + 3 + i * UI_width*4] = (color & 0x00ff0000) >> 16;
		}
		HAL_DCACHE_FLUSH(osd0_fetch_data00, UI_width*UI_height*4);	
	}
	else if (input_fmt == 0xe) {
		for (i = y; i < y + len ; i++) {
			osd0_fetch_data00[x*4 + 0 + i * UI_width*4] = (color & 0x000000ff) >> 0;
			osd0_fetch_data00[x*4 + 1 + i * UI_width*4] = (color & 0x0000ff00) >> 8;
			osd0_fetch_data00[x*4 + 2 + i * UI_width*4] = (color & 0x00ff0000) >> 16;
			osd0_fetch_data00[x*4 + 3 + i * UI_width*4] = (color & 0xff000000) >> 24;
		}
		HAL_DCACHE_FLUSH(osd0_fetch_data00, UI_width*UI_height*4);
	}
	#if 0
	printf("color BYTE0 0x000000ff %d \n",(color & 0x000000ff) >> 0);
	printf("color BYTE1 0x0000ff00 %d \n",(color & 0x0000ff00) >> 8);
	printf("color BYTE2 0x00ff0000 %d \n",(color & 0x00ff0000) >> 16);
	printf("color BYTE3 0xff000000 %d \n",(color & 0xff000000) >> 24);
	#endif

	return 0;
}

int SP_OSD_DrawBorderLine(int input_fmt, INT16 x, INT16 y, UINT16 width, UINT16 height, UINT32 color)
{
	int i;
	INT16 UI_width = disp_init_width;
	INT16 UI_height = disp_init_height;

	if (input_fmt == 0x2) {
		for (i = x; i < x + width ; i++) {
			osd0_fetch_data00[i + y * UI_width] = (color & 0x000000ff) >> 0;
			osd0_fetch_data00[i + (y+height) * UI_width] = (color & 0x000000ff) >> 0;
		}
		for (i = y; i < y + height ; i++) {
			osd0_fetch_data00[x + i * UI_width] = (color & 0x000000ff) >> 0;
			osd0_fetch_data00[(x+width) + i * UI_width] = (color & 0x000000ff) >> 0;
		}
		HAL_DCACHE_FLUSH(osd0_fetch_data00, UI_width*UI_height);
	}
	else if (input_fmt == 0x4) {
		#if 1
		for (i = x; i < x + width ; i++) {
			osd0_fetch_data00[i*2 + y * UI_width*2] = (color & 0x000000ff) >> 0;
			osd0_fetch_data00[i*2 + (y+height) * UI_width*2] = (color & 0x000000ff) >> 0;
		}
		for (i = y; i < y + height ; i++) {
			osd0_fetch_data00[x*2 + i * UI_width*2] = (color & 0x000000ff) >> 0;
			osd0_fetch_data00[(x+width)*2 + i * UI_width*2] = (color & 0x000000ff) >> 0;
		}
		HAL_DCACHE_FLUSH(osd0_fetch_data00, UI_width*UI_height*2);
		#else
		printf("DrawBorderLine not support for yuy2 \n");
		#endif
	}
	else if (input_fmt == 0x8) {
		for (i = x; i < x + width ; i++) {
			osd0_fetch_data00[i*2 + 0 + y * UI_width*2] = (color & 0x00001C00) >> (8-3) | (color & 0x000000f8) >> (0+3);
			osd0_fetch_data00[i*2 + 1 + y * UI_width*2] = (color & 0x00f80000) >> (16+0) | (color & 0x0000E000) >> (8+5);

			osd0_fetch_data00[i*2 + 0 + (y+height) * UI_width*2] = (color & 0x00001C00) >> (8-3) | (color & 0x000000f8) >> (0+3);
			osd0_fetch_data00[i*2 + 1 + (y+height) * UI_width*2] = (color & 0x00f80000) >> (16+0) | (color & 0x0000E000) >> (8+5);
		}
		for (i = y; i < y + height ; i++) {
			osd0_fetch_data00[x*2 + 0 + i * UI_width*2] = (color & 0x00001C00) >> (8-3) | (color & 0x000000f8) >> (0+3);
			osd0_fetch_data00[x*2 + 1 + i * UI_width*2] = (color & 0x00f80000) >> (16+0) | (color & 0x0000E000) >> (8+5);

			osd0_fetch_data00[(x+width)*2 + 0 + i * UI_width*2] = (color & 0x00001C00) >> (8-3) | (color & 0x000000f8) >> (0+3);
			osd0_fetch_data00[(x+width)*2 + 1 + i * UI_width*2] = (color & 0x00f80000) >> (16+0) | (color & 0x0000E000) >> (8+5);
		}
		HAL_DCACHE_FLUSH(osd0_fetch_data00, UI_width*UI_height*2);
	}
	else if (input_fmt == 0x9) {
		for (i = x; i < x + width ; i++) {
			osd0_fetch_data00[i*2 + 0 + y * UI_width*2] = (color & 0x00003800) >> (8-2) | (color & 0x000000f8) >> (0+3);
			osd0_fetch_data00[i*2 + 1 + y * UI_width*2] = (color & 0x80000000) >> (24+0) | (color & 0x00f80000) >> (16+1) | (color & 0x0000C000) >> (8+6);

			osd0_fetch_data00[i*2 + 0 + (y+height) * UI_width*2] = (color & 0x00003800) >> (8-2) | (color & 0x000000f8) >> (0+3);
			osd0_fetch_data00[i*2 + 1 + (y+height) * UI_width*2] = (color & 0x80000000) >> (24+0) | (color & 0x00f80000) >> (16+1) | (color & 0x0000C000) >> (8+6);
		}
		for (i = y; i < y + height ; i++) {
			osd0_fetch_data00[x*2 + 0 + i * UI_width*2] = (color & 0x00003800) >> (8-2) | (color & 0x000000f8) >> (0+3);
			osd0_fetch_data00[x*2 + 1 + i * UI_width*2] = (color & 0x80000000) >> (24+0) | (color & 0x00f80000) >> (16+1) | (color & 0x0000C000) >> (8+6);

			osd0_fetch_data00[(x+width)*2 + 0 + i * UI_width*2] = (color & 0x00003800) >> (8-2) | (color & 0x000000f8) >> (0+3);
			osd0_fetch_data00[(x+width)*2 + 1 + i * UI_width*2] = (color & 0x80000000) >> (24+0) | (color & 0x00f80000) >> (16+1) | (color & 0x0000C000) >> (8+6);
		}
		HAL_DCACHE_FLUSH(osd0_fetch_data00, UI_width*UI_height*2);
	}
	else if (input_fmt == 0xa) {
		for (i = x; i < x + width ; i++) {
			osd0_fetch_data00[i*2 + 0 + y * UI_width*2] = (color & 0x000000f0) >> (0+0) | (color & 0xf0000000) >> (24+4);
			osd0_fetch_data00[i*2 + 1 + y * UI_width*2] = (color & 0x00f00000) >> (16+0) |(color & 0x0000f000) >> (8+4);

			osd0_fetch_data00[i*2 + 0 + (y+height) * UI_width*2] = (color & 0x000000f0) >> (0+0) | (color & 0xf0000000) >> (24+4);
			osd0_fetch_data00[i*2 + 1 + (y+height) * UI_width*2] = (color & 0x00f00000) >> (16+0) |(color & 0x0000f000) >> (8+4);
		}
		for (i = y; i < y + height ; i++) {
			osd0_fetch_data00[x*2 + 0 + i * UI_width*2] = (color & 0x000000f0) >> (0+0) | (color & 0xf0000000) >> (24+4);
			osd0_fetch_data00[x*2 + 1 + i * UI_width*2] = (color & 0x00f00000) >> (16+0) |(color & 0x0000f000) >> (8+4);

			osd0_fetch_data00[(x+width)*2 + 0 + i * UI_width*2] = (color & 0x000000f0) >> (0+0) | (color & 0xf0000000) >> (24+4);
			osd0_fetch_data00[(x+width)*2 + 1 + i * UI_width*2] = (color & 0x00f00000) >> (16+0) |(color & 0x0000f000) >> (8+4);
		}
		HAL_DCACHE_FLUSH(osd0_fetch_data00, UI_width*UI_height*2);
	}
	else if (input_fmt == 0xb) {
		for (i = x; i < x + width ; i++) {
			osd0_fetch_data00[i*2 + 0 + y * UI_width*2] = (color & 0x0000f000) >> (8+0) | (color & 0x000000f0) >> (0+4);
			osd0_fetch_data00[i*2 + 1 + y * UI_width*2] = (color & 0xf0000000) >> (24+0) | (color & 0x00f00000) >> (16+4);

			osd0_fetch_data00[i*2 + 0 + (y+height) * UI_width*2] = (color & 0x0000f000) >> (8+0) | (color & 0x000000f0) >> (0+4);
			osd0_fetch_data00[i*2 + 1 + (y+height) * UI_width*2] = (color & 0xf0000000) >> (24+0) | (color & 0x00f00000) >> (16+4);
		}
		for (i = y; i < y + height ; i++) {
			osd0_fetch_data00[x*2 + 0 + i * UI_width*2] = (color & 0x0000f000) >> (8+0) | (color & 0x000000f0) >> (0+4);
			osd0_fetch_data00[x*2 + 1 + i * UI_width*2] = (color & 0xf0000000) >> (24+0) | (color & 0x00f00000) >> (16+4);

			osd0_fetch_data00[(x+width)*2 + 0 + i * UI_width*2] = (color & 0x0000f000) >> (8+0) | (color & 0x000000f0) >> (0+4);
			osd0_fetch_data00[(x+width)*2 + 1 + i * UI_width*2] = (color & 0xf0000000) >> (24+0) | (color & 0x00f00000) >> (16+4);
		}
		HAL_DCACHE_FLUSH(osd0_fetch_data00, UI_width*UI_height*2);		
	}
	else if (input_fmt == 0xd) {
		for (i = x; i < x + width ; i++) {
			osd0_fetch_data00[i*4 + 0 + y * UI_width*4] = (color & 0xff000000) >> 24;
			osd0_fetch_data00[i*4 + 1 + y * UI_width*4] = (color & 0x000000ff) >> 0;
			osd0_fetch_data00[i*4 + 2 + y * UI_width*4] = (color & 0x0000ff00) >> 8;
			osd0_fetch_data00[i*4 + 3 + y * UI_width*4] = (color & 0x00ff0000) >> 16;

			osd0_fetch_data00[i*4 + 0 + (y+height) * UI_width*4] = (color & 0xff000000) >> 24;
			osd0_fetch_data00[i*4 + 1 + (y+height) * UI_width*4] = (color & 0x000000ff) >> 0;
			osd0_fetch_data00[i*4 + 2 + (y+height) * UI_width*4] = (color & 0x0000ff00) >> 8;
			osd0_fetch_data00[i*4 + 3 + (y+height) * UI_width*4] = (color & 0x00ff0000) >> 16;
		}
		for (i = y; i < y + height ; i++) {
			osd0_fetch_data00[x*4 + 0 + i * UI_width*4] = (color & 0xff000000) >> 24;
			osd0_fetch_data00[x*4 + 1 + i * UI_width*4] = (color & 0x000000ff) >> 0;
			osd0_fetch_data00[x*4 + 2 + i * UI_width*4] = (color & 0x0000ff00) >> 8;
			osd0_fetch_data00[x*4 + 3 + i * UI_width*4] = (color & 0x00ff0000) >> 16;

			osd0_fetch_data00[(x+width)*4 + 0 + i * UI_width*4] = (color & 0xff000000) >> 24;
			osd0_fetch_data00[(x+width)*4 + 1 + i * UI_width*4] = (color & 0x000000ff) >> 0;
			osd0_fetch_data00[(x+width)*4 + 2 + i * UI_width*4] = (color & 0x0000ff00) >> 8;
			osd0_fetch_data00[(x+width)*4 + 3 + i * UI_width*4] = (color & 0x00ff0000) >> 16;
		}
		HAL_DCACHE_FLUSH(osd0_fetch_data00, UI_width*UI_height*4);			
	}
	else if (input_fmt == 0xe) {
		for (i = x; i < x + width ; i++) {
			osd0_fetch_data00[i*4 + 0 + y * UI_width*4] = (color & 0x000000ff) >> 0;
			osd0_fetch_data00[i*4 + 1 + y * UI_width*4] = (color & 0x0000ff00) >> 8;
			osd0_fetch_data00[i*4 + 2 + y * UI_width*4] = (color & 0x00ff0000) >> 16;
			osd0_fetch_data00[i*4 + 3 + y * UI_width*4] = (color & 0xff000000) >> 24;

			osd0_fetch_data00[i*4 + 0 + (y+height) * UI_width*4] = (color & 0x000000ff) >> 0;
			osd0_fetch_data00[i*4 + 1 + (y+height) * UI_width*4] = (color & 0x0000ff00) >> 8;
			osd0_fetch_data00[i*4 + 2 + (y+height) * UI_width*4] = (color & 0x00ff0000) >> 16;
			osd0_fetch_data00[i*4 + 3 + (y+height) * UI_width*4] = (color & 0xff000000) >> 24;
		}
		for (i = y; i < y + height ; i++) {
			osd0_fetch_data00[x*4 + 0 + i * UI_width*4] = (color & 0x000000ff) >> 0;
			osd0_fetch_data00[x*4 + 1 + i * UI_width*4] = (color & 0x0000ff00) >> 8;
			osd0_fetch_data00[x*4 + 2 + i * UI_width*4] = (color & 0x00ff0000) >> 16;
			osd0_fetch_data00[x*4 + 3 + i * UI_width*4] = (color & 0xff000000) >> 24;

			osd0_fetch_data00[(x+width)*4 + 0 + i * UI_width*4] = (color & 0x000000ff) >> 0;
			osd0_fetch_data00[(x+width)*4 + 1 + i * UI_width*4] = (color & 0x0000ff00) >> 8;
			osd0_fetch_data00[(x+width)*4 + 2 + i * UI_width*4] = (color & 0x00ff0000) >> 16;
			osd0_fetch_data00[(x+width)*4 + 3 + i * UI_width*4] = (color & 0xff000000) >> 24;
		}
		HAL_DCACHE_FLUSH(osd0_fetch_data00, UI_width*UI_height*4);
	}
	#if 0
	printf("color BYTE0 0x000000ff %d \n",(color & 0x000000ff) >> 0);
	printf("color BYTE1 0x0000ff00 %d \n",(color & 0x0000ff00) >> 8);
	printf("color BYTE2 0x00ff0000 %d \n",(color & 0x00ff0000) >> 16);
	printf("color BYTE3 0xff000000 %d \n",(color & 0xff000000) >> 24);
	#endif

	return 0;
}

int SP_OSD_FillArea(int input_fmt, INT16 x, INT16 y, UINT16 width, UINT16 height, UINT32 color)
{
	int i,j;
	INT16 UI_width = disp_init_width;
	INT16 UI_height = disp_init_height;

	if (input_fmt == 0x2) {
		for (i = x; i < x + width ; i++) {
			for (j = y; j < y + height ; j++) {
				osd0_fetch_data00[i + j * UI_width] = (color & 0x000000ff) >> 0;
			}
		}
		HAL_DCACHE_FLUSH(osd0_fetch_data00, UI_width*UI_height);
	}
	else if (input_fmt == 0x4) {
		#if 1
		for (i = x; i < x + width ; i++) {
			for (j = y; j < y + height ; j++) {
				osd0_fetch_data00[i*2 + j * UI_width*2] = (color & 0x000000ff) >> 0;
			}
		}
		HAL_DCACHE_FLUSH(osd0_fetch_data00, UI_width*UI_height*2);
		#else
		printf("FillArea not support for yuy2 \n");
		#endif
	}
	else if (input_fmt == 0x8) {
		for (i = x; i < x + width ; i++) {
			for (j = y; j < y + height ; j++) {
				osd0_fetch_data00[i*2 + 0 + j * UI_width*2] = (color & 0x00001C00) >> (8-3) | (color & 0x000000f8) >> (0+3);
				osd0_fetch_data00[i*2 + 1 + j * UI_width*2] = (color & 0x00f80000) >> (16+0) | (color & 0x0000E000) >> (8+5);
			}
		}
		HAL_DCACHE_FLUSH(osd0_fetch_data00, UI_width*UI_height*2);
	}
	else if (input_fmt == 0x9) {
		for (i = x; i < x + width ; i++) {
			for (j = y; j < y + height ; j++) {
				osd0_fetch_data00[i*2 + 0 + j * UI_width*2] = (color & 0x00003800) >> (8-2) | (color & 0x000000f8) >> (0+3);
				osd0_fetch_data00[i*2 + 1 + j * UI_width*2] = (color & 0x80000000) >> (24+0) | (color & 0x00f80000) >> (16+1) | (color & 0x0000C000) >> (8+6);
			}
		}
		HAL_DCACHE_FLUSH(osd0_fetch_data00, UI_width*UI_height*2);
	}
	else if (input_fmt == 0xa) {
		for (i = x; i < x + width ; i++) {
			for (j = y; j < y + height ; j++) {
				osd0_fetch_data00[i*2 + 0 + j * UI_width*2] = (color & 0x000000f0) >> (0+0) | (color & 0xf0000000) >> (24+4);
				osd0_fetch_data00[i*2 + 1 + j * UI_width*2] = (color & 0x00f00000) >> (16+0) |(color & 0x0000f000) >> (8+4);
			}
		}
		HAL_DCACHE_FLUSH(osd0_fetch_data00, UI_width*UI_height*2);
	}
	else if (input_fmt == 0xb) {
		for (i = x; i < x + width ; i++) {
			for (j = y; j < y + height ; j++) {
				osd0_fetch_data00[i*2 + 0 + j * UI_width*2] = (color & 0x0000f000) >> (8+0) | (color & 0x000000f0) >> (0+4);
				osd0_fetch_data00[i*2 + 1 + j * UI_width*2] = (color & 0xf0000000) >> (24+0) | (color & 0x00f00000) >> (16+4);
			}
		}
		HAL_DCACHE_FLUSH(osd0_fetch_data00, UI_width*UI_height*2);
	}
	else if (input_fmt == 0xd) {
		for (i = x; i < x + width ; i++) {
			for (j = y; j < y + height ; j++) {
				osd0_fetch_data00[i*4 + 0 + j * UI_width*4] = (color & 0xff000000) >> 24;
				osd0_fetch_data00[i*4 + 1 + j * UI_width*4] = (color & 0x000000ff) >> 0;
				osd0_fetch_data00[i*4 + 2 + j * UI_width*4] = (color & 0x0000ff00) >> 8;
				osd0_fetch_data00[i*4 + 3 + j * UI_width*4] = (color & 0x00ff0000) >> 16;
			}
		}
		HAL_DCACHE_FLUSH(osd0_fetch_data00, UI_width*UI_height*4);
	}
	else if (input_fmt == 0xe) {
		for (i = x; i < x + width ; i++) {
			for (j = y; j < y + height ; j++) {
				osd0_fetch_data00[i*4 + 0 + j * UI_width*4] = (color & 0x000000ff) >> 0;
				osd0_fetch_data00[i*4 + 1 + j * UI_width*4] = (color & 0x0000ff00) >> 8;
				osd0_fetch_data00[i*4 + 2 + j * UI_width*4] = (color & 0x00ff0000) >> 16;
				osd0_fetch_data00[i*4 + 3 + j * UI_width*4] = (color & 0xff000000) >> 24;
			}
		}
		HAL_DCACHE_FLUSH(osd0_fetch_data00, UI_width*UI_height*4);
	}
	#if 0
	printf("color BYTE0 0x000000ff %d \n",(color & 0x000000ff) >> 0);
	printf("color BYTE1 0x0000ff00 %d \n",(color & 0x0000ff00) >> 8);
	printf("color BYTE2 0x00ff0000 %d \n",(color & 0x00ff0000) >> 16);
	printf("color BYTE3 0xff000000 %d \n",(color & 0xff000000) >> 24);
	#endif

	return 0;
}

#define MAX_CHAR_PER_LINE 16

int SP_OSD_DrawString_Ascii_std(UINT8 *pString, int font_type, int input_fmt, INT16 dstX, INT16 dstY, UINT32 bg_color, UINT32 font_color)
{
	int i, str_len, str_cnt_x, str_cnt_y, ret;
	int x, y, width, height;
	UINT8 *pu8String = NULL;

	printf("SP_OSD_DrawString_Ascii_std \n");

	if (pString == NULL) {
		printf("pString NULL \n");
		return 0;
	}
	printf("OSD0 fmt = %d \n", input_fmt);
	printf("Font coordinate ( x , y ) = (%d , %d) \n", dstX, dstY);
	printf("Font color ( bg , font ) = (%08x , %08x) \n", bg_color, font_color);
	str_len = strlen(pString);
	printf("pString length %d \n",str_len);
	pu8String = pString;

	if (font_type == 0) {
		width = FONT_ASCII_ARIAL_10X20[2];
		height = FONT_ASCII_ARIAL_10X20[3];
	}
	else if (font_type == 1) {
		width = FONT_ASCII_ARIAL_20X20[2];
		height = FONT_ASCII_ARIAL_20X20[3];
	}
	else if (font_type == 2) {
		width = FONT_ASCII_ARIAL_12X24[2];
		height = FONT_ASCII_ARIAL_12X24[3];
	}
	else if (font_type == 3) {
		width = FONT_ASCII_ARIAL_24X24[2];
		height = FONT_ASCII_ARIAL_24X24[3];
	}
	else if (font_type == 4) {
		width = FONT_ASCII_ARIAL_16X32[2];
		height = FONT_ASCII_ARIAL_16X32[3];
	}
	else if (font_type == 5) {
		width = FONT_ASCII_ARIAL_32X32[2];
		height = FONT_ASCII_ARIAL_32X32[3];
	}
	else if (font_type == 6) {
		width = FONT_ASCII_ARIAL_24X48[2];
		height = FONT_ASCII_ARIAL_24X48[3];
	}
	else if (font_type == 7) {
		width = FONT_ASCII_ARIAL_48X48[2];
		height = FONT_ASCII_ARIAL_48X48[3];
	}

	str_cnt_x = 0;
	str_cnt_y = 0;
	for (i = 0 ; i < str_len ; i++) {
		if((i % MAX_CHAR_PER_LINE)==0) {
			str_cnt_y++;
		}
		str_cnt_x = i - MAX_CHAR_PER_LINE * (str_cnt_y-1);	
		x = dstX+width*str_cnt_x;
		y = dstY+height*(str_cnt_y-1);	

		if (font_type == 0) {
			ret = SP_OSD_DrawFont_Ascii_std(pu8String, FONT_ASCII_ARIAL_10X20, input_fmt, x, y, bg_color, font_color);
		}
		else if (font_type == 1) {
			ret = SP_OSD_DrawFont_Ascii_std(pu8String, FONT_ASCII_ARIAL_20X20, input_fmt, x, y, bg_color, font_color);
		}
		else if (font_type == 2) {
			ret = SP_OSD_DrawFont_Ascii_std(pu8String, FONT_ASCII_ARIAL_12X24, input_fmt, x, y, bg_color, font_color);
		}
		else if (font_type == 3) {
			ret = SP_OSD_DrawFont_Ascii_std(pu8String, FONT_ASCII_ARIAL_24X24, input_fmt, x, y, bg_color, font_color);
		}
		else if (font_type == 4) {
			ret = SP_OSD_DrawFont_Ascii_std(pu8String, FONT_ASCII_ARIAL_16X32, input_fmt, x, y, bg_color, font_color);
		}
		else if (font_type == 5) {
			ret = SP_OSD_DrawFont_Ascii_std(pu8String, FONT_ASCII_ARIAL_32X32, input_fmt, x, y, bg_color, font_color);
		}
		else if (font_type == 6) {
			ret = SP_OSD_DrawFont_Ascii_std(pu8String, FONT_ASCII_ARIAL_24X48, input_fmt, x, y, bg_color, font_color);
		}
		else if (font_type == 7) {
			ret = SP_OSD_DrawFont_Ascii_std(pu8String, FONT_ASCII_ARIAL_48X48, input_fmt, x, y, bg_color, font_color);
		}
        if(ret)
            printf("draw font test1 fail \n");
		
		#if 1
		pu8String += 1;
		#else
		printf("pString[%d] = 0x%02x \n", i, *(pu8String++));
		#endif
	}

	return 0;
}

int SP_OSD_DrawFont_Ascii_std(UINT8 *iCode, UINT8 *font_src, int input_fmt, INT16 dstX, INT16 dstY, UINT32 bg_color, UINT32 font_color)
{
	int i,j,count, str_val, char_start;
	UINT32 offset_cur;
	UINT8 mode;
    INT16 width,height;
    int ret;
	#if 0
	printf("SP_OSD_DrawFont_Ascii_std \n");
	printf("OSD0 fmt = %d \n", input_fmt);
	printf("iCode = 0x%02x \n", *(iCode));
	printf("font_src list \n");
	printf("** font_src ** \n");
	printf("** font_src[0] %d \n", font_src[0]); //font header ver.
	printf("** font_src[1] %d \n", font_src[1]); //font header size
	printf("** font_src[2] %d \n", font_src[2]); //font width
	printf("** font_src[3] %d \n", font_src[3]); //font height
	printf("** font_src[4][5] %x %x \n", font_src[4],font_src[5]); //char low code
	printf("** font_src[6][7] %x %x \n", font_src[6],font_src[7]); //char high code
	printf("** font_src[8][9] %x %x \n", font_src[8],font_src[9]); //code page
	printf("** font_src[10] %d \n", font_src[10]); //font data type (fixed / variable)
	printf("** font_src[11] %d \n", font_src[11]); // font bm type & bitmap type
	printf("** font_src[12][13] %x %x \n", font_src[12],font_src[13]); //font total no.
	printf("** font_src[14][15] %x %x \n", font_src[14],font_src[15]); //font total area
	//font bm area info
	printf("** font_src[16][17][18][19] %x %x %x %x \n", font_src[16],font_src[17],font_src[18],font_src[19]);
	#endif
	//printf("Font coordinate ( x , y ) = (%d , %d) \n", dstX, dstY);
	//printf("Font color ( bg , font ) = (%08x , %08x) \n", bg_color, font_color);

	str_val =  *(iCode);
	offset_cur = 	(UINT32)font_src[0x10+0x4+3*(str_val-0x20)+0]<<16 | 
					(UINT32)font_src[0x10+0x4+3*(str_val-0x20)+1]<<8 |
					(UINT32)font_src[0x10+0x4+3*(str_val-0x20)+2]<<0;
	//offset_nxt = 	(UINT32)font_src[0x10+0x4+3*(str_val-0x20)+3]<<16 | 
	//				(UINT32)font_src[0x10+0x4+3*(str_val-0x20)+4]<<8 | 
	//				(UINT32)font_src[0x10+0x4+3*(str_val-0x20)+5]<<0;
	//printf("** offset1 offset2 %d %d \n", offset_cur,offset_nxt);

	mode = font_src[offset_cur + 0x10 + 0x4 + 0x60*3];
	//printf("** mode %d \n", mode);

	width = font_src[2];
	height = font_src[3];

	ret = SP_OSD_FillArea(input_fmt, dstX, dstY, width, height, bg_color);
	if(ret)
		printf("FillArea fail \n");

	count = 0;
	if ((((width - mode) % 2 ) == 0) || ((width-mode) == 1))
		char_start = dstX + (width-mode)/2;
	else
		char_start = dstX + (width-mode)/2 + 1;

	for (j = dstY; j < dstY + height ; j++) {
		for (i = char_start; i < char_start + mode ; i++) {
			if(font_src[offset_cur + (count/8) + 1 + 0x10 + 0x4 + 0x60*3]&(0x80 >> (count%8))) {
				ret = SP_OSD_DrawPixel(input_fmt, i, j, font_color);
				if(ret)
					printf("DrawPixel fail \n");
			}
			count++;
		}
	}

	return 0;

}

int SP_OSD_DrawString_Big5_com(UINT8 *pString, int font_type, int input_fmt, INT16 dstX, INT16 dstY, UINT32 bg_color, UINT32 font_color)
{
	int i, str_len, str_cnt_x, str_cnt_y, ret;
	int x, y, width, height;
	UINT8 *pu8String = NULL;

	printf("SP_OSD_DrawString_Big5_com \n");

	if (pString == NULL) {
		printf("pString NULL \n");
		return 0;
	}
	printf("OSD0 fmt = %d \n", input_fmt);
	printf("Font coordinate ( x , y ) = (%d , %d) \n", dstX, dstY);
	printf("Font color ( bg , font ) = (%08x , %08x) \n", bg_color, font_color);
	str_len = strlen(pString);
	printf("pString length %d \n",str_len);
	pu8String = pString;

	if (font_type == 0) {
		width = FONT_BIG5_COM_ARIAL_20X20[2];
		height = FONT_BIG5_COM_ARIAL_20X20[3];
	}
	#ifdef OSD0_BIG5_COM_FONT_ARIAL_24X24
	else if (font_type == 1) {
		width = FONT_BIG5_COM_ARIAL_24X24[2];
		height = FONT_BIG5_COM_ARIAL_24X24[3];
	}
	#endif
	#ifdef OSD0_BIG5_COM_FONT_ARIAL_32X32
	else if (font_type == 2) {
		width = FONT_BIG5_COM_ARIAL_32X32[2];
		height = FONT_BIG5_COM_ARIAL_32X32[3];
	}
	#endif
	#ifdef OSD0_BIG5_COM_FONT_ARIAL_48X48
	else if (font_type == 3) {
		width = FONT_BIG5_COM_ARIAL_48X48[2];
		height = FONT_BIG5_COM_ARIAL_48X48[3];
	}
	#endif

	str_cnt_x = 0;
	str_cnt_y = 0;
	for (i = 0 ; i < str_len ; i+=2) {
		if(((i/2) % MAX_CHAR_PER_LINE)==0) {
			str_cnt_y++;
		}
		str_cnt_x = (i/2) - (MAX_CHAR_PER_LINE) * (str_cnt_y-1);	
		x = dstX+width*str_cnt_x;
		y = dstY+height*(str_cnt_y-1);	

		if (font_type == 0) {
			ret = SP_OSD_DrawFont_Big5_com(pu8String, FONT_BIG5_COM_ARIAL_20X20, input_fmt, x, y, bg_color, font_color);
		}
		#ifdef OSD0_BIG5_COM_FONT_ARIAL_24X24
		else if (font_type == 1) {
			ret = SP_OSD_DrawFont_Big5_com(pu8String, FONT_BIG5_COM_ARIAL_24X24, input_fmt, x, y, bg_color, font_color);
		}
		#endif
		#ifdef OSD0_BIG5_COM_FONT_ARIAL_32X32
		else if (font_type == 2) {
			ret = SP_OSD_DrawFont_Big5_com(pu8String, FONT_BIG5_COM_ARIAL_32X32, input_fmt, x, y, bg_color, font_color);
		}
		#endif
		#ifdef OSD0_BIG5_COM_FONT_ARIAL_48X48
		else if (font_type == 3) {
			ret = SP_OSD_DrawFont_Big5_com(pu8String, FONT_BIG5_COM_ARIAL_48X48, input_fmt, x, y, bg_color, font_color);
		}
		#endif
        if(ret)
            printf("draw font test2 fail \n");

		#if 1
		pu8String += 2;
		#else
		printf("pString[%d] = 0x%02x \n", i, *(pu8String++));
		printf("pString[%d] = 0x%02x \n", i+1, *(pu8String++));
		#endif
	}

	return 0;

}


int SP_OSD_DrawFont_Big5_com(UINT8 *iCode, UINT8 *font_src, int input_fmt, INT16 dstX, INT16 dstY, UINT32 bg_color, UINT32 font_color)
{

	int i,j,count;
	//UINT32 page_index, page_count,str_val, char_start;
	UINT32 page_count,str_val, char_start;
	UINT32 cur_end_val, cur_start_val, nxt_start_val;
	UINT32 max_code_val,min_code_val;
    UINT32 width,height;
	UINT32 total_area;
	UINT8 str_val_1, str_val_2;

    int ret;
	#if 0
	printf("SP_OSD_DrawFont_Big5_com \n");
	printf("OSD0 fmt = %d \n", input_fmt);
	//printf("iCode0 = 0x%02x \n", *(iCode));
	//printf("iCode1 = 0x%02x \n", *(iCode+1));
	printf("font_src list \n");
	printf("** font_src ** \n");
	printf("** font_src[0] %d \n", font_src[0]); //font header ver.
	printf("** font_src[1] %d \n", font_src[1]); //font header size
	printf("** font_src[2] %d \n", font_src[2]); //font width
	printf("** font_src[3] %d \n", font_src[3]); //font height
	printf("** font_src[4][5] %x %x \n", font_src[4],font_src[5]); //char low code
	printf("** font_src[6][7] %x %x \n", font_src[6],font_src[7]); //char high code
	printf("** font_src[8][9] %x %x \n", font_src[8],font_src[9]); //code page
	printf("** font_src[10] %d \n", font_src[10]); //font data type (fixed / variable)
	printf("** font_src[11] %d \n", font_src[11]); // font bm type & bitmap type
	printf("** font_src[12][13] %x %x \n", font_src[12],font_src[13]); //font total no.
	printf("** font_src[14][15] %x %x \n", font_src[14],font_src[15]); //font total area
	//font bm area info
	printf("** font_src[16][17][18][19] %x %x %x %x \n", font_src[16],font_src[17],font_src[18],font_src[19]);
	#endif
	//printf("Font coordinate ( x , y ) = (%d , %d) \n", dstX, dstY);
	//printf("Font color ( bg , font ) = (%08x , %08x) \n", bg_color, font_color);

	max_code_val = (UINT32)font_src[6] * 256 + (UINT32)font_src[7];
	min_code_val = (UINT32)font_src[4] * 256 + (UINT32)font_src[5];
	//printf("code range = ( %d , %d ) \n", min_code_val, max_code_val);

	total_area = (UINT32)font_src[14] * 256 + (UINT32)font_src[15];
	//printf("total_area = %d \n", total_area);

	width = font_src[2];
	height = font_src[3];

	str_val_1 =  *(iCode);
	str_val_2 =  *(iCode+1);
	//printf("iCode[0][1] color = (%02x , %02x) \n", str_val_1, str_val_2);

	str_val = (UINT32)str_val_1 * 256 + (UINT32)str_val_2;
	//printf("str_val = %d \n", str_val);

	if ((str_val >= min_code_val) && (str_val <= max_code_val)) {
		;//printf("code in range , search... \n");
	}
	else {
		;//printf("code out of range , set blank char! \n");
		ret = SP_OSD_FillArea(input_fmt, dstX, dstY, width, height, bg_color);
		if(ret)
			printf("FillArea fail \n");
		return 0;
	}

	page_count = 0;
	for (i=0;i<total_area;i++) {
		cur_end_val = (UINT32)font_src[0x10+i*4+2] * 256 + (UINT32)font_src[0x10+i*4+3];
		cur_start_val = (UINT32)font_src[0x10+i*4+0] * 256 + (UINT32)font_src[0x10+i*4+1];
		if (i < (total_area - 1))
			nxt_start_val = (UINT32)font_src[0x10+i*4+4] * 256 + (UINT32)font_src[0x10+i*4+5];
		else 
			nxt_start_val = max_code_val;

		if ((str_val > cur_end_val) && (str_val < nxt_start_val) && (i < (total_area - 1))) {
			//printf("code not exist \n");
			ret = SP_OSD_FillArea(input_fmt, dstX, dstY, width, height, bg_color);
			if(ret)
				printf("FillArea fail \n");
			return 0;			
		}
		else if ((str_val >= cur_start_val) && (str_val <= cur_end_val)) {
			//printf("match code found %d \n", i);
			//page_index = i;
			page_count += (str_val - cur_start_val + 1);
			break;
		}
		else {
			//printf("search next rank \n");
			page_count += (cur_end_val - cur_start_val + 1);
		}
	}
	//printf("page_index %d , page_count %d \n", page_index, page_count);

	char_start = 0x10+total_area*4+(page_count-1)*width*height/8;
	//printf("char_start %d \n", char_start);

	#if 0
	printf("Data %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x \n", 
		font_src[char_start+0],font_src[char_start+1],font_src[char_start+2],font_src[char_start+3],
		font_src[char_start+4],font_src[char_start+5],font_src[char_start+6],font_src[char_start+7],
		font_src[char_start+8],font_src[char_start+9]);
	printf("Data %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x \n", 
		font_src[char_start+10],font_src[char_start+11],font_src[char_start+12],font_src[char_start+13],
		font_src[char_start+14],font_src[char_start+15],font_src[char_start+16],font_src[char_start+17],
		font_src[char_start+18],font_src[char_start+19]);
	printf("Data %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x \n", 
		font_src[char_start+20],font_src[char_start+21],font_src[char_start+22],font_src[char_start+23],
		font_src[char_start+24],font_src[char_start+25],font_src[char_start+26],font_src[char_start+27],
		font_src[char_start+28],font_src[char_start+29]);
	printf("Data %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x \n", 
		font_src[char_start+30],font_src[char_start+31],font_src[char_start+32],font_src[char_start+33],
		font_src[char_start+34],font_src[char_start+35],font_src[char_start+36],font_src[char_start+37],
		font_src[char_start+38],font_src[char_start+39]);
	printf("Data %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x \n", 
		font_src[char_start+40],font_src[char_start+41],font_src[char_start+42],font_src[char_start+43],
		font_src[char_start+44],font_src[char_start+45],font_src[char_start+46],font_src[char_start+47],
		font_src[char_start+48],font_src[char_start+49]);
	#endif

	ret = SP_OSD_FillArea(input_fmt, dstX, dstY, width, height, bg_color);
	if(ret)
		printf("FillArea fail \n");

	count = 0;
	for (j = dstY; j < dstY + height ; j++) {
		for (i = dstX; i < dstX + width ; i++) {
			if(font_src[char_start + (count/8)]&(0x80 >> (count%8))) {
				ret = SP_OSD_DrawPixel(input_fmt, i, j, font_color);
				if(ret)
					printf("DrawPixel fail \n");
			}
			count++;
		}
	}

	return 0;

}

int SP_OSD_DrawString_Big5_ext(UINT8 *pString, int font_type, int input_fmt, INT16 dstX, INT16 dstY, UINT32 bg_color, UINT32 font_color)
{
	int i, str_len, str_cnt_x, str_cnt_y, ret;
	int x, y, width, height;
	UINT8 *pu8String = NULL;

	printf("SP_OSD_DrawString_Big5_ext \n");

	if (pString == NULL) {
		printf("pString NULL \n");
		return 0;
	}
	printf("OSD0 fmt = %d \n", input_fmt);
	printf("Font coordinate ( x , y ) = (%d , %d) \n", dstX, dstY);
	printf("Font color ( bg , font ) = (%08x , %08x) \n", bg_color, font_color);
	str_len = strlen(pString);
	printf("pString length %d \n",str_len);
	pu8String = pString;

	if (font_type == 0) {
		width = FONT_BIG5_EXT_ARIAL_20X20[2];
		height = FONT_BIG5_EXT_ARIAL_20X20[3];
	}
	#ifdef OSD0_BIG5_EXT_FONT_ARIAL_24X24
	else if (font_type == 1) {
		width = FONT_BIG5_EXT_ARIAL_24X24[2];
		height = FONT_BIG5_EXT_ARIAL_24X24[3];
	}
	#endif
	#ifdef OSD0_BIG5_EXT_FONT_ARIAL_32X32
	else if (font_type == 2) {
		width = FONT_BIG5_EXT_ARIAL_32X32[2];
		height = FONT_BIG5_EXT_ARIAL_32X32[3];
	}
	#endif
	#ifdef OSD0_BIG5_EXT_FONT_ARIAL_48X48
	else if (font_type == 3) {
		width = FONT_BIG5_EXT_ARIAL_48X48[2];
		height = FONT_BIG5_EXT_ARIAL_48X48[3];
	}
	#endif

	str_cnt_x = 0;
	str_cnt_y = 0;
	for (i = 0 ; i < str_len ; i+=2) {
		if(((i/2) % MAX_CHAR_PER_LINE)==0) {
			str_cnt_y++;
		}
		str_cnt_x = (i/2) - (MAX_CHAR_PER_LINE) * (str_cnt_y-1);	
		x = dstX+width*str_cnt_x;
		y = dstY+height*(str_cnt_y-1);	

		if (font_type == 0) {
			ret = SP_OSD_DrawFont_Big5_ext(pu8String, FONT_BIG5_EXT_ARIAL_20X20, input_fmt, x, y, bg_color, font_color);
		}
		#ifdef OSD0_BIG5_EXT_FONT_ARIAL_24X24
		else if (font_type == 1) {
			ret = SP_OSD_DrawFont_Big5_ext(pu8String, FONT_BIG5_EXT_ARIAL_24X24, input_fmt, x, y, bg_color, font_color);
		}
		#endif
		#ifdef OSD0_BIG5_EXT_FONT_ARIAL_32X32
		else if (font_type == 2) {
			ret = SP_OSD_DrawFont_Big5_ext(pu8String, FONT_BIG5_EXT_ARIAL_32X32, input_fmt, x, y, bg_color, font_color);
		}
		#endif
		#ifdef OSD0_BIG5_EXT_FONT_ARIAL_48X48		
		else if (font_type == 3) {
			ret = SP_OSD_DrawFont_Big5_ext(pu8String, FONT_BIG5_EXT_ARIAL_48X48, input_fmt, x, y, bg_color, font_color);
		}
		#endif
        if(ret)
            printf("draw font test2 fail \n");

		#if 1
		pu8String += 2;
		#else		
		printf("pString[%d] = 0x%02x \n", i, *(pu8String++));
		printf("pString[%d] = 0x%02x \n", i+1, *(pu8String++));
		#endif
	}

	return 0;

}


int SP_OSD_DrawFont_Big5_ext(UINT8 *iCode, UINT8 *font_src, int input_fmt, INT16 dstX, INT16 dstY, UINT32 bg_color, UINT32 font_color)
{

	int i,j,count;
	//UINT32 page_index, page_count,str_val, char_start;
	UINT32 page_count,str_val, char_start;
	UINT32 cur_end_val, cur_start_val, nxt_start_val;
	UINT32 max_code_val,min_code_val;
    UINT32 width,height;
	UINT32 total_area;
	UINT8 str_val_1, str_val_2;

    int ret;
	#if 0
	printf("SP_OSD_DrawFont_Big5_ext \n");
	printf("OSD0 fmt = %d \n", input_fmt);
	//printf("iCode0 = 0x%02x \n", *(iCode));
	//printf("iCode1 = 0x%02x \n", *(iCode+1));
	printf("font_src list \n");
	printf("** font_src ** \n");
	printf("** font_src[0] %d \n", font_src[0]); //font header ver.
	printf("** font_src[1] %d \n", font_src[1]); //font header size
	printf("** font_src[2] %d \n", font_src[2]); //font width
	printf("** font_src[3] %d \n", font_src[3]); //font height
	printf("** font_src[4][5] %x %x \n", font_src[4],font_src[5]); //char low code
	printf("** font_src[6][7] %x %x \n", font_src[6],font_src[7]); //char high code
	printf("** font_src[8][9] %x %x \n", font_src[8],font_src[9]); //code page
	printf("** font_src[10] %d \n", font_src[10]); //font data type (fixed / variable)
	printf("** font_src[11] %d \n", font_src[11]); // font bm type & bitmap type
	printf("** font_src[12][13] %x %x \n", font_src[12],font_src[13]); //font total no.
	printf("** font_src[14][15] %x %x \n", font_src[14],font_src[15]); //font total area
	//font bm area info
	printf("** font_src[16][17][18][19] %x %x %x %x \n", font_src[16],font_src[17],font_src[18],font_src[19]);
	#endif
	//printf("Font coordinate ( x , y ) = (%d , %d) \n", dstX, dstY);
	//printf("Font color ( bg , font ) = (%08x , %08x) \n", bg_color, font_color);

	max_code_val = (UINT32)font_src[6] * 256 + (UINT32)font_src[7];
	min_code_val = (UINT32)font_src[4] * 256 + (UINT32)font_src[5];
	//printf("code range = ( %d , %d ) \n", min_code_val, max_code_val);

	total_area = (UINT32)font_src[14] * 256 + (UINT32)font_src[15];
	//printf("total_area = %d \n", total_area);

	width = font_src[2];
	height = font_src[3];

	str_val_1 =  *(iCode);
	str_val_2 =  *(iCode+1);
	//printf("iCode[0][1] color = (%02x , %02x) \n", str_val_1, str_val_2);

	str_val = (UINT32)str_val_1 * 256 + (UINT32)str_val_2;
	//printf("str_val = %d \n", str_val);

	if ((str_val >= min_code_val) && (str_val <= max_code_val)) {
		;//printf("code in range , search... \n");
	}
	else {
		;//printf("code out of range , set blank char! \n");
		ret = SP_OSD_FillArea(input_fmt, dstX, dstY, width, height, bg_color);
		if(ret)
			printf("FillArea fail \n");
		return 0;
	}

	page_count = 0;
	for (i=0;i<total_area;i++) {
		cur_end_val = (UINT32)font_src[0x10+i*4+2] * 256 + (UINT32)font_src[0x10+i*4+3];
		cur_start_val = (UINT32)font_src[0x10+i*4+0] * 256 + (UINT32)font_src[0x10+i*4+1];
		if (i < (total_area - 1))
			nxt_start_val = (UINT32)font_src[0x10+i*4+4] * 256 + (UINT32)font_src[0x10+i*4+5];
		else 
			nxt_start_val = max_code_val;

		if ((str_val > cur_end_val) && (str_val < nxt_start_val) && (i < (total_area - 1))) {
			//printf("code not exist \n");
			ret = SP_OSD_FillArea(input_fmt, dstX, dstY, width, height, bg_color);
			if(ret)
				printf("FillArea fail \n");
			return 0;			
		}
		else if ((str_val >= cur_start_val) && (str_val <= cur_end_val)) {
			//printf("match code found %d \n", i);
			//page_index = i;
			page_count += (str_val - cur_start_val + 1);
			break;
		}
		else {
			//printf("search next rank \n");
			page_count += (cur_end_val - cur_start_val + 1);
		}
	}
	//printf("page_index %d , page_count %d \n", page_index, page_count);

	char_start = 0x10+total_area*4+(page_count-1)*width*height/8;
	//printf("char_start %d \n", char_start);

	#if 0
	printf("Data %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x \n", 
		font_src[char_start+0],font_src[char_start+1],font_src[char_start+2],font_src[char_start+3],
		font_src[char_start+4],font_src[char_start+5],font_src[char_start+6],font_src[char_start+7],
		font_src[char_start+8],font_src[char_start+9]);
	printf("Data %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x \n", 
		font_src[char_start+10],font_src[char_start+11],font_src[char_start+12],font_src[char_start+13],
		font_src[char_start+14],font_src[char_start+15],font_src[char_start+16],font_src[char_start+17],
		font_src[char_start+18],font_src[char_start+19]);
	printf("Data %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x \n", 
		font_src[char_start+20],font_src[char_start+21],font_src[char_start+22],font_src[char_start+23],
		font_src[char_start+24],font_src[char_start+25],font_src[char_start+26],font_src[char_start+27],
		font_src[char_start+28],font_src[char_start+29]);
	printf("Data %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x \n", 
		font_src[char_start+30],font_src[char_start+31],font_src[char_start+32],font_src[char_start+33],
		font_src[char_start+34],font_src[char_start+35],font_src[char_start+36],font_src[char_start+37],
		font_src[char_start+38],font_src[char_start+39]);
	printf("Data %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x \n", 
		font_src[char_start+40],font_src[char_start+41],font_src[char_start+42],font_src[char_start+43],
		font_src[char_start+44],font_src[char_start+45],font_src[char_start+46],font_src[char_start+47],
		font_src[char_start+48],font_src[char_start+49]);
	#endif

	ret = SP_OSD_FillArea(input_fmt, dstX, dstY, width, height, bg_color);
	if(ret)
		printf("FillArea fail \n");

	count = 0;
	for (j = dstY; j < dstY + height ; j++) {
		for (i = dstX; i < dstX + width ; i++) {
			if(font_src[char_start + (count/8)]&(0x80 >> (count%8))) {
				ret = SP_OSD_DrawPixel(input_fmt, i, j, font_color);
				if(ret)
					printf("DrawPixel fail \n");
			}
			count++;
		}
	}

	return 0;

}

int SP_OSD_DrawString_Gb2312_com(UINT8 *pString, int font_type, int input_fmt, INT16 dstX, INT16 dstY, UINT32 bg_color, UINT32 font_color)
{
	int i, str_len, str_cnt_x, str_cnt_y, ret;
	int x, y, width, height;
	UINT8 *pu8String = NULL;

	printf("SP_OSD_DrawString_Gb2312_com \n");

	if (pString == NULL) {
		printf("pString NULL \n");
		return 0;
	}
	printf("OSD0 fmt = %d \n", input_fmt);
	printf("Font coordinate ( x , y ) = (%d , %d) \n", dstX, dstY);
	printf("Font color ( bg , font ) = (%08x , %08x) \n", bg_color, font_color);
	str_len = strlen(pString);
	printf("pString length %d \n",str_len);
	pu8String = pString;

	if (font_type == 0) {
		width = FONT_GB2312_COM_ARIAL_20X20[2];
		height = FONT_GB2312_COM_ARIAL_20X20[3];
	}
	#ifdef OSD0_GB2312_COM_FONT_ARIAL_24X24
	else if (font_type == 1) {
		width = FONT_GB2312_COM_ARIAL_24X24[2];
		height = FONT_GB2312_COM_ARIAL_24X24[3];
	}
	#endif
	#ifdef OSD0_GB2312_COM_FONT_ARIAL_32X32
	else if (font_type == 2) {
		width = FONT_GB2312_COM_ARIAL_32X32[2];
		height = FONT_GB2312_COM_ARIAL_32X32[3];
	}
	#endif
	#ifdef OSD0_GB2312_COM_FONT_ARIAL_48X48
	else if (font_type == 3) {
		width = FONT_GB2312_COM_ARIAL_48X48[2];
		height = FONT_GB2312_COM_ARIAL_48X48[3];
	}
	#endif

	str_cnt_x = 0;
	str_cnt_y = 0;
	for (i = 0 ; i < str_len ; i+=2) {
		if(((i/2) % MAX_CHAR_PER_LINE)==0) {
			str_cnt_y++;
		}
		str_cnt_x = (i/2) - (MAX_CHAR_PER_LINE) * (str_cnt_y-1);	
		x = dstX+width*str_cnt_x;
		y = dstY+height*(str_cnt_y-1);	

		if (font_type == 0) {
			ret = SP_OSD_DrawFont_Gb2312_com(pu8String, FONT_GB2312_COM_ARIAL_20X20, input_fmt, x, y, bg_color, font_color);
		}
		#ifdef OSD0_GB2312_COM_FONT_ARIAL_24X24
		else if (font_type == 1) {
			ret = SP_OSD_DrawFont_Gb2312_com(pu8String, FONT_GB2312_COM_ARIAL_24X24, input_fmt, x, y, bg_color, font_color);
		}
		#endif
		#ifdef OSD0_GB2312_COM_FONT_ARIAL_32X32
		else if (font_type == 2) {
			ret = SP_OSD_DrawFont_Gb2312_com(pu8String, FONT_GB2312_COM_ARIAL_32X32, input_fmt, x, y, bg_color, font_color);
		}
		#endif
		#ifdef OSD0_GB2312_COM_FONT_ARIAL_48X48
		else if (font_type == 3) {
			ret = SP_OSD_DrawFont_Gb2312_com(pu8String, FONT_GB2312_COM_ARIAL_48X48, input_fmt, x, y, bg_color, font_color);
		}
		#endif
        if(ret)
            printf("draw font test2 fail \n");

		#if 1
		pu8String += 2;
		#else
		printf("pString[%d] = 0x%02x \n", i, *(pu8String++));
		printf("pString[%d] = 0x%02x \n", i+1, *(pu8String++));
		#endif
	}

	return 0;

}


int SP_OSD_DrawFont_Gb2312_com(UINT8 *iCode, UINT8 *font_src, int input_fmt, INT16 dstX, INT16 dstY, UINT32 bg_color, UINT32 font_color)
{

	int i,j,count;
	//UINT32 page_index, page_count,str_val, char_start;
	UINT32 page_count,str_val, char_start;
	UINT32 cur_end_val, cur_start_val, nxt_start_val;
	UINT32 max_code_val,min_code_val;
    UINT32 width,height;
	UINT32 total_area;
	UINT8 str_val_1, str_val_2;

    int ret;
	#if 0
	printf("SP_OSD_DrawFont_Gb2312_com \n");
	printf("OSD0 fmt = %d \n", input_fmt);
	//printf("iCode0 = 0x%02x \n", *(iCode));
	//printf("iCode1 = 0x%02x \n", *(iCode+1));
	printf("font_src list \n");
	printf("** font_src ** \n");
	printf("** font_src[0] %d \n", font_src[0]); //font header ver.
	printf("** font_src[1] %d \n", font_src[1]); //font header size
	printf("** font_src[2] %d \n", font_src[2]); //font width
	printf("** font_src[3] %d \n", font_src[3]); //font height
	printf("** font_src[4][5] %x %x \n", font_src[4],font_src[5]); //char low code
	printf("** font_src[6][7] %x %x \n", font_src[6],font_src[7]); //char high code
	printf("** font_src[8][9] %x %x \n", font_src[8],font_src[9]); //code page
	printf("** font_src[10] %d \n", font_src[10]); //font data type (fixed / variable)
	printf("** font_src[11] %d \n", font_src[11]); // font bm type & bitmap type
	printf("** font_src[12][13] %x %x \n", font_src[12],font_src[13]); //font total no.
	printf("** font_src[14][15] %x %x \n", font_src[14],font_src[15]); //font total area
	//font bm area info
	printf("** font_src[16][17][18][19] %x %x %x %x \n", font_src[16],font_src[17],font_src[18],font_src[19]);
	#endif
	//printf("Font coordinate ( x , y ) = (%d , %d) \n", dstX, dstY);
	//printf("Font color ( bg , font ) = (%08x , %08x) \n", bg_color, font_color);

	max_code_val = (UINT32)font_src[6] * 256 + (UINT32)font_src[7];
	min_code_val = (UINT32)font_src[4] * 256 + (UINT32)font_src[5];
	//printf("code range = ( %d , %d ) \n", min_code_val, max_code_val);

	total_area = (UINT32)font_src[14] * 256 + (UINT32)font_src[15];
	//printf("total_area = %d \n", total_area);

	width = font_src[2];
	height = font_src[3];

	str_val_1 =  *(iCode);
	str_val_2 =  *(iCode+1);
	//printf("iCode[0][1] color = (%02x , %02x) \n", str_val_1, str_val_2);

	str_val = (UINT32)str_val_1 * 256 + (UINT32)str_val_2;
	//printf("str_val = %d \n", str_val);

	if ((str_val >= min_code_val) && (str_val <= max_code_val)) {
		;//printf("code in range , search... \n");
	}
	else {
		//printf("code out of range , set blank char! \n");
		ret = SP_OSD_FillArea(input_fmt, dstX, dstY, width, height, bg_color);
		if(ret)
			printf("FillArea fail \n");
		return 0;
	}

	page_count = 0;
	for (i=0;i<total_area;i++) {
		cur_end_val = (UINT32)font_src[0x10+i*4+2] * 256 + (UINT32)font_src[0x10+i*4+3];
		cur_start_val = (UINT32)font_src[0x10+i*4+0] * 256 + (UINT32)font_src[0x10+i*4+1];
		if (i < (total_area - 1))
			nxt_start_val = (UINT32)font_src[0x10+i*4+4] * 256 + (UINT32)font_src[0x10+i*4+5];
		else 
			nxt_start_val = max_code_val;

		if ((str_val > cur_end_val) && (str_val < nxt_start_val) && (i < (total_area - 1))) {
			//printf("code not exist \n");
			ret = SP_OSD_FillArea(input_fmt, dstX, dstY, width, height, bg_color);
			if(ret)
				printf("FillArea fail \n");
			return 0;			
		}
		else if ((str_val >= cur_start_val) && (str_val <= cur_end_val)) {
			//printf("match code found %d \n", i);
			//page_index = i;
			page_count += (str_val - cur_start_val + 1);
			break;
		}
		else {
			//printf("search next rank \n");
			page_count += (cur_end_val - cur_start_val + 1);
		}
	}
	//printf("page_index %d , page_count %d \n", page_index, page_count);

	char_start = 0x10+total_area*4+(page_count-1)*width*height/8;
	//printf("char_start %d \n", char_start);

	#if 0
	printf("Data %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x \n", 
		font_src[char_start+0],font_src[char_start+1],font_src[char_start+2],font_src[char_start+3],
		font_src[char_start+4],font_src[char_start+5],font_src[char_start+6],font_src[char_start+7],
		font_src[char_start+8],font_src[char_start+9]);
	printf("Data %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x \n", 
		font_src[char_start+10],font_src[char_start+11],font_src[char_start+12],font_src[char_start+13],
		font_src[char_start+14],font_src[char_start+15],font_src[char_start+16],font_src[char_start+17],
		font_src[char_start+18],font_src[char_start+19]);
	printf("Data %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x \n", 
		font_src[char_start+20],font_src[char_start+21],font_src[char_start+22],font_src[char_start+23],
		font_src[char_start+24],font_src[char_start+25],font_src[char_start+26],font_src[char_start+27],
		font_src[char_start+28],font_src[char_start+29]);
	printf("Data %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x \n", 
		font_src[char_start+30],font_src[char_start+31],font_src[char_start+32],font_src[char_start+33],
		font_src[char_start+34],font_src[char_start+35],font_src[char_start+36],font_src[char_start+37],
		font_src[char_start+38],font_src[char_start+39]);
	printf("Data %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x \n", 
		font_src[char_start+40],font_src[char_start+41],font_src[char_start+42],font_src[char_start+43],
		font_src[char_start+44],font_src[char_start+45],font_src[char_start+46],font_src[char_start+47],
		font_src[char_start+48],font_src[char_start+49]);
	#endif

	ret = SP_OSD_FillArea(input_fmt, dstX, dstY, width, height, bg_color);
	if(ret)
		printf("FillArea fail \n");

	count = 0;
	for (j = dstY; j < dstY + height ; j++) {
		for (i = dstX; i < dstX + width ; i++) {
			if(font_src[char_start + (count/8)]&(0x80 >> (count%8))) {
				ret = SP_OSD_DrawPixel(input_fmt, i, j, font_color);
				if(ret)
					printf("DrawPixel fail \n");
			}
			count++;
		}
	}

	return 0;

}

int SP_OSD_DrawString_Gbk_ext(UINT8 *pString, int font_type, int input_fmt, INT16 dstX, INT16 dstY, UINT32 bg_color, UINT32 font_color)
{
	int i, str_len, str_cnt_x, str_cnt_y, ret;
	int x, y, width, height;
	UINT8 *pu8String = NULL;

	printf("SP_OSD_DrawString_Gbk_ext \n");

	if (pString == NULL) {
		printf("pString NULL \n");
		return 0;
	}
	printf("OSD0 fmt = %d \n", input_fmt);
	printf("Font coordinate ( x , y ) = (%d , %d) \n", dstX, dstY);
	printf("Font color ( bg , font ) = (%08x , %08x) \n", bg_color, font_color);
	str_len = strlen(pString);
	printf("pString length %d \n",str_len);
	pu8String = pString;

	if (font_type == 0) {
		width = FONT_GBK_EXT_ARIAL_20X20[2];
		height = FONT_GBK_EXT_ARIAL_20X20[3];
	}
	#ifdef OSD0_GBK_EXT_FONT_ARIAL_24X24
	else if (font_type == 1) {
		width = FONT_GBK_EXT_ARIAL_24X24[2];
		height = FONT_GBK_EXT_ARIAL_24X24[3];
	}
	#endif
	#ifdef OSD0_GBK_EXT_FONT_ARIAL_32X32
	else if (font_type == 2) {
		width = FONT_GBK_EXT_ARIAL_32X32[2];
		height = FONT_GBK_EXT_ARIAL_32X32[3];
	}
	#endif
	#ifdef OSD0_GBK_EXT_FONT_ARIAL_48X48
	else if (font_type == 3) {
		width = FONT_GBK_EXT_ARIAL_48X48[2];
		height = FONT_GBK_EXT_ARIAL_48X48[3];
	}
	#endif

	str_cnt_x = 0;
	str_cnt_y = 0;
	for (i = 0 ; i < str_len ; i+=2) {
		if(((i/2) % MAX_CHAR_PER_LINE)==0) {
			str_cnt_y++;
		}
		str_cnt_x = (i/2) - (MAX_CHAR_PER_LINE) * (str_cnt_y-1);	
		x = dstX+width*str_cnt_x;
		y = dstY+height*(str_cnt_y-1);	

		if (font_type == 0) {
			ret = SP_OSD_DrawFont_Gb2312_com(pu8String, FONT_GBK_EXT_ARIAL_20X20, input_fmt, x, y, bg_color, font_color);
		}
		#ifdef OSD0_GBK_EXT_FONT_ARIAL_24X24
		else if (font_type == 1) {
			ret = SP_OSD_DrawFont_Gb2312_com(pu8String, FONT_GBK_EXT_ARIAL_24X24, input_fmt, x, y, bg_color, font_color);
		}
		#endif
		#ifdef OSD0_GBK_EXT_FONT_ARIAL_32X32
		else if (font_type == 2) {
			ret = SP_OSD_DrawFont_Gb2312_com(pu8String, FONT_GBK_EXT_ARIAL_32X32, input_fmt, x, y, bg_color, font_color);
		}
		#endif
		#ifdef OSD0_GBK_EXT_FONT_ARIAL_48X48
		else if (font_type == 3) {
			ret = SP_OSD_DrawFont_Gb2312_com(pu8String, FONT_GBK_EXT_ARIAL_48X48, input_fmt, x, y, bg_color, font_color);
		}
		#endif
        if(ret)
            printf("draw font test2 fail \n");
		
		#if 1
		pu8String += 2;
		#else
		printf("pString[%d] = 0x%02x \n", i, *(pu8String++));
		printf("pString[%d] = 0x%02x \n", i+1, *(pu8String++));
		#endif
	}

	return 0;

}


int SP_OSD_DrawFont_Gbk_ext(UINT8 *iCode, UINT8 *font_src, int input_fmt, INT16 dstX, INT16 dstY, UINT32 bg_color, UINT32 font_color)
{

	int i,j,count;
	//UINT32 page_index, page_count,str_val, char_start;
	UINT32 page_count,str_val, char_start;
	UINT32 cur_end_val, cur_start_val, nxt_start_val;
	UINT32 max_code_val,min_code_val;
    UINT32 width,height;
	UINT32 total_area;
	UINT8 str_val_1, str_val_2;

    int ret;
	#if 0
	printf("SP_OSD_DrawFont_Gbk_ext \n");
	printf("OSD0 fmt = %d \n", input_fmt);
	//printf("iCode0 = 0x%02x \n", *(iCode));
	//printf("iCode1 = 0x%02x \n", *(iCode+1));
	printf("font_src list \n");
	printf("** font_src ** \n");
	printf("** font_src[0] %d \n", font_src[0]); //font header ver.
	printf("** font_src[1] %d \n", font_src[1]); //font header size
	printf("** font_src[2] %d \n", font_src[2]); //font width
	printf("** font_src[3] %d \n", font_src[3]); //font height
	printf("** font_src[4][5] %x %x \n", font_src[4],font_src[5]); //char low code
	printf("** font_src[6][7] %x %x \n", font_src[6],font_src[7]); //char high code
	printf("** font_src[8][9] %x %x \n", font_src[8],font_src[9]); //code page
	printf("** font_src[10] %d \n", font_src[10]); //font data type (fixed / variable)
	printf("** font_src[11] %d \n", font_src[11]); // font bm type & bitmap type
	printf("** font_src[12][13] %x %x \n", font_src[12],font_src[13]); //font total no.
	printf("** font_src[14][15] %x %x \n", font_src[14],font_src[15]); //font total area
	//font bm area info
	printf("** font_src[16][17][18][19] %x %x %x %x \n", font_src[16],font_src[17],font_src[18],font_src[19]);
	#endif
	//printf("Font coordinate ( x , y ) = (%d , %d) \n", dstX, dstY);
	//printf("Font color ( bg , font ) = (%08x , %08x) \n", bg_color, font_color);

	max_code_val = (UINT32)font_src[6] * 256 + (UINT32)font_src[7];
	min_code_val = (UINT32)font_src[4] * 256 + (UINT32)font_src[5];
	//printf("code range = ( %d , %d ) \n", min_code_val, max_code_val);

	total_area = (UINT32)font_src[14] * 256 + (UINT32)font_src[15];
	//printf("total_area = %d \n", total_area);

	width = font_src[2];
	height = font_src[3];

	str_val_1 =  *(iCode);
	str_val_2 =  *(iCode+1);
	//printf("iCode[0][1] color = (%02x , %02x) \n", str_val_1, str_val_2);

	str_val = (UINT32)str_val_1 * 256 + (UINT32)str_val_2;
	//printf("str_val = %d \n", str_val);

	if ((str_val >= min_code_val) && (str_val <= max_code_val)) {
		;//printf("code in range , search... \n");
	}
	else {
		//printf("code out of range , set blank char! \n");
		ret = SP_OSD_FillArea(input_fmt, dstX, dstY, width, height, bg_color);
		if(ret)
			printf("FillArea fail \n");
		return 0;
	}

	page_count = 0;
	for (i=0;i<total_area;i++) {
		cur_end_val = (UINT32)font_src[0x10+i*4+2] * 256 + (UINT32)font_src[0x10+i*4+3];
		cur_start_val = (UINT32)font_src[0x10+i*4+0] * 256 + (UINT32)font_src[0x10+i*4+1];
		if (i < (total_area - 1))
			nxt_start_val = (UINT32)font_src[0x10+i*4+4] * 256 + (UINT32)font_src[0x10+i*4+5];
		else 
			nxt_start_val = max_code_val;

		if ((str_val > cur_end_val) && (str_val < nxt_start_val) && (i < (total_area - 1))) {
			//printf("code not exist \n");
			ret = SP_OSD_FillArea(input_fmt, dstX, dstY, width, height, bg_color);
			if(ret)
				printf("FillArea fail \n");
			return 0;			
		}
		else if ((str_val >= cur_start_val) && (str_val <= cur_end_val)) {
			//printf("match code found %d \n", i);
			//page_index = i;
			page_count += (str_val - cur_start_val + 1);
			break;
		}
		else {
			//printf("search next rank \n");
			page_count += (cur_end_val - cur_start_val + 1);
		}
	}
	//printf("page_index %d , page_count %d \n", page_index, page_count);

	char_start = 0x10+total_area*4+(page_count-1)*width*height/8;
	//printf("char_start %d \n", char_start);

	#if 0
	printf("Data %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x \n", 
		font_src[char_start+0],font_src[char_start+1],font_src[char_start+2],font_src[char_start+3],
		font_src[char_start+4],font_src[char_start+5],font_src[char_start+6],font_src[char_start+7],
		font_src[char_start+8],font_src[char_start+9]);
	printf("Data %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x \n", 
		font_src[char_start+10],font_src[char_start+11],font_src[char_start+12],font_src[char_start+13],
		font_src[char_start+14],font_src[char_start+15],font_src[char_start+16],font_src[char_start+17],
		font_src[char_start+18],font_src[char_start+19]);
	printf("Data %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x \n", 
		font_src[char_start+20],font_src[char_start+21],font_src[char_start+22],font_src[char_start+23],
		font_src[char_start+24],font_src[char_start+25],font_src[char_start+26],font_src[char_start+27],
		font_src[char_start+28],font_src[char_start+29]);
	printf("Data %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x \n", 
		font_src[char_start+30],font_src[char_start+31],font_src[char_start+32],font_src[char_start+33],
		font_src[char_start+34],font_src[char_start+35],font_src[char_start+36],font_src[char_start+37],
		font_src[char_start+38],font_src[char_start+39]);
	printf("Data %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x \n", 
		font_src[char_start+40],font_src[char_start+41],font_src[char_start+42],font_src[char_start+43],
		font_src[char_start+44],font_src[char_start+45],font_src[char_start+46],font_src[char_start+47],
		font_src[char_start+48],font_src[char_start+49]);
	#endif

	ret = SP_OSD_FillArea(input_fmt, dstX, dstY, width, height, bg_color);
	if(ret)
		printf("FillArea fail \n");

	count = 0;
	for (j = dstY; j < dstY + height ; j++) {
		for (i = dstX; i < dstX + width ; i++) {
			if(font_src[char_start + (count/8)]&(0x80 >> (count%8))) {
				ret = SP_OSD_DrawPixel(input_fmt, i, j, font_color);
				if(ret)
					printf("DrawPixel fail \n");
			}
			count++;
		}
	}

	return 0;

}

#endif

