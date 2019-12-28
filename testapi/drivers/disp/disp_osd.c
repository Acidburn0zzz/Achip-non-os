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

}
