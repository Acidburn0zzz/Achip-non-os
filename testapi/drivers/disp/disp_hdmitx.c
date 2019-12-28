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
 * Description :  display register TGEN for sp7021
 * ------------------------------------------------------
 * Rev  Date          Author(s)      Status & Comments
 * ======================================================
 * 0.1  2019/12/21    hammer.hsieh   initial version
 */

#include <emuio.h>
#include "regmap.h"
#include "reg_disp.h"
#include "disp_hdmitx.h"
#include "display.h"

/**************************************************************************
 *             F U N C T I O N    I M P L E M E N T A T I O N S           *
 **************************************************************************/
void hdmi_clk_init(int mode)
{
    if (mode ==  0) { //720x480 59.94Hz
        MOON4_REG->plltv_ctl[0] = 0xFFFF8001; 	//G4.14
        MOON4_REG->plltv_ctl[1] = 0xFFFF0004; 	//G4.15
        MOON4_REG->plltv_ctl[2] = 0xFFFF010a; 	//G4.16
        MOON4_REG->otp_st = 0x00300000; 		//G4.31
    }
    else if (mode ==  1) { //720x576 50Hz
        ; //TBD
    }
    else if (mode ==  2) { //1280x720 59.94Hz
        MOON4_REG->plltv_ctl[0] = 0xFFFF0001; 	//G4.14
        MOON4_REG->plltv_ctl[1] = 0xFFFF0084; 	//G4.15
        MOON4_REG->plltv_ctl[2] = 0xFFFF010a; 	//G4.16
        MOON4_REG->otp_st = 0x00300000; 		//G4.31
    }
    else {
        ;//TBD , the rest setting
    }
}

void DRV_hdmitx_Init(int is_hdmi, int width, int height)
{
	printf("DRV_hdmitx_Init \n");

	if(is_hdmi) {
		hdmi_clk_init(0);
		hdmitx_set_timming(0);
	}
	else {
		;//TBD , turn off hdmitx if necessary
	}
}

void hdmitx_set_ptg(int enable)
{
	if (enable) {
        G381_HDMITX_REG->g381_reserved[20] = 0x00000017; //HDMITX -- default VIDEO_PAT_GEN1
        //G381_HDMITX_REG->g381_reserved[21] = 0x00000000; //HDMITX -- default VIDEO_PAT_GEN2
        //G381_HDMITX_REG->g381_reserved[22] = 0x00000000; //HDMITX -- default VIDEO_PAT_GEN3
        //G381_HDMITX_REG->g381_reserved[23] = 0x00000000; //HDMITX -- default VIDEO_PAT_GEN4
        //G381_HDMITX_REG->g381_reserved[24] = 0x00000000; //HDMITX -- default VIDEO_PAT_GEN5
        //G381_HDMITX_REG->g381_reserved[25] = 0x00000000; //HDMITX -- default VIDEO_PAT_GEN6
        //G381_HDMITX_REG->g381_reserved[26] = 0x00000000; //HDMITX -- default VIDEO_PAT_GEN7
        //G381_HDMITX_REG->g381_reserved[27] = 0x00000000; //HDMITX -- default VIDEO_PAT_GEN8
        //G381_HDMITX_REG->g381_reserved[28] = 0x00000000; //HDMITX -- default VIDEO_PAT_GEN9
	}
	else {
        G381_HDMITX_REG->g381_reserved[20] = 0x00000016; //HDMITX -- default VIDEO_PAT_GEN1
        //G381_HDMITX_REG->g381_reserved[21] = 0x00000000; //HDMITX -- default VIDEO_PAT_GEN2
        //G381_HDMITX_REG->g381_reserved[22] = 0x00000000; //HDMITX -- default VIDEO_PAT_GEN3
        //G381_HDMITX_REG->g381_reserved[23] = 0x00000000; //HDMITX -- default VIDEO_PAT_GEN4
        //G381_HDMITX_REG->g381_reserved[24] = 0x00000000; //HDMITX -- default VIDEO_PAT_GEN5
        //G381_HDMITX_REG->g381_reserved[25] = 0x00000000; //HDMITX -- default VIDEO_PAT_GEN6
        //G381_HDMITX_REG->g381_reserved[26] = 0x00000000; //HDMITX -- default VIDEO_PAT_GEN7
        //G381_HDMITX_REG->g381_reserved[27] = 0x00000000; //HDMITX -- default VIDEO_PAT_GEN8
        //G381_HDMITX_REG->g381_reserved[28] = 0x00000000; //HDMITX -- default VIDEO_PAT_GEN9		
	}
}

void hdmitx_set_timming(int mode)
{
    if (mode == 0) { //HDMITX 720x480 59.94Hz as default setting
        printf("hdmitx_set_timming.G380 \n");
        //HDMITX G380
        G380_HDMITX_REG->g380_reserved[5] = 0x0000141f; //HDMITX -- default 0x0000140f (TMDSTX_PHY for pwr_down).
        G380_HDMITX_REG->g380_reserved[6] = 0x000000ff; //HDMITX -- default 0x000000e9 (SW_RESET)
        G380_HDMITX_REG->g380_reserved[8] = 0x00001001; //HDMITX -- default 0x00001000 (CTRL1 -- HDMI/DVI)
        G380_HDMITX_REG->g380_reserved[20] = 0x0000a59b; //HDMITX -- default 0x00000000 (Mi12)
        G380_HDMITX_REG->g380_reserved[21] = 0x00007a2d; //HDMITX -- default 0x00000000 (Mi34)
        G380_HDMITX_REG->g380_reserved[22] = 0x00009238; //HDMITX -- default 0x00000000 (Mi56)
        G380_HDMITX_REG->g380_reserved[23] = 0x000016e2; //HDMITX -- default 0x00000000 (Mi78)
        //HDMITX G381
        printf("hdmitx_set_timming.G381 \n");
        G381_HDMITX_REG->g381_reserved[16] = 0x00000140; //HDMITX -- default 0x00000000 (VIDEO_CTRL1)
        //HDMITX G382
        printf("hdmitx_set_timming.G382 \n");
        G382_HDMITX_REG->g382_reserved[12] = 0x00000043; //HDMITX -- default 0x00000000 (vsync_out/hsync_out/color_depth)
        G382_HDMITX_REG->g382_reserved[16] = 0x0000e411; //HDMITX -- default 0x0000e400 (AUDIO_CTRL1)
        G382_HDMITX_REG->g382_reserved[17] = 0x000001b5; //HDMITX -- default 0x000001b4 (AUDIO_CTRL2)
        G382_HDMITX_REG->g382_reserved[18] = 0x0000007e; //HDMITX -- default 0x00000020 (AUDIO_SPDIF_CTRL)
        G382_HDMITX_REG->g382_reserved[26] = 0x00000085; //HDMITX -- default 0x00000004 (ACR_CONFIG1)
        G382_HDMITX_REG->g382_reserved[27] = 0x00001800; //HDMITX -- default 0x00000000 (ACR_VALUE1)
        G382_HDMITX_REG->g382_reserved[28] = 0x00000000; //HDMITX -- default 0x00000000 (ACR_VALUE2)
        //HDMITX G383
        printf("hdmitx_set_timming.G383 \n");
        G383_HDMITX_REG->g383_reserved[1] = 0x00000003; //HDMITX -- default 0x00000000 (INTR0_UNMASK)
        G383_HDMITX_REG->g383_reserved[2] = 0x00000004; //HDMITX -- default 0x00000000 (INTR1_UNMASK)
        G383_HDMITX_REG->g383_reserved[3] = 0x00000000; //HDMITX -- default 0x00000000 (INTR2_UNMASK)
        G383_HDMITX_REG->g383_reserved[7] = 0x00005018; //HDMITX -- default 0x00005000 (DDC_MASTER_SET)
        G383_HDMITX_REG->g383_reserved[8] = 0x000000a0; //HDMITX -- default 0x00000074 (DDC_SLV_DEVICE_ADDR)
        G383_HDMITX_REG->g383_reserved[11] = 0x00000010; //HDMITX -- default 0x00000000 (DDC_DATA_CNT)
        //HDMITX G385
        printf("hdmitx_set_timming.G385 \n");
        G385_HDMITX_REG->g385_reserved[0] = 0x00001a1a; //HDMITX -- default 0x00001010 (InfoFrame CTRL1)
        G385_HDMITX_REG->g385_reserved[1] = 0x0000101a; //HDMITX -- default 0x00001010 (InfoFrame CTRL2)
        G385_HDMITX_REG->g385_reserved[2] = 0x00001010; //HDMITX -- default 0x00001010 (InfoFrame CTRL3)
        G385_HDMITX_REG->g385_reserved[3] = 0x00001010; //HDMITX -- default 0x00001010 (InfoFrame CTRL4)
        G385_HDMITX_REG->g385_reserved[4] = 0x00000010; //HDMITX -- default 0x00000010 (InfoFrame CTRL5)
        G385_HDMITX_REG->g385_reserved[5] = 0x00001010; //HDMITX -- default 0x00001010 (InfoFrame CTRL6)
        G385_HDMITX_REG->g385_reserved[6] = 0x00001c08; //HDMITX -- default 0x00000000 (AVI_InfoFrame01)
        G385_HDMITX_REG->g385_reserved[7] = 0x00000058; //HDMITX -- default 0x00000000 (AVI_InfoFrame23)
        G385_HDMITX_REG->g385_reserved[8] = 0x00000002; //HDMITX -- default 0x00000000 (AVI_InfoFrame45)
        G385_HDMITX_REG->g385_reserved[9] = 0x00000024; //HDMITX -- default 0x00000000 (AVI_InfoFrame67)
        G385_HDMITX_REG->g385_reserved[10] = 0x00000204; //HDMITX -- default 0x00000000 (AVI_InfoFrame89)
        G385_HDMITX_REG->g385_reserved[11] = 0x0000007a; //HDMITX -- default 0x00000000 (AVI_InfoFrame1011)
        G385_HDMITX_REG->g385_reserved[12] = 0x0000034a; //HDMITX -- default 0x00000000 (AVI_InfoFrame1213)
        G385_HDMITX_REG->g385_reserved[13] = 0x00000170; //HDMITX -- default 0x00000000 (AUDIO_InfoFrame01)
        G385_HDMITX_REG->g385_reserved[14] = 0x00000000; //HDMITX -- default 0x00000000 (AUDIO_InfoFrame23)
        G385_HDMITX_REG->g385_reserved[15] = 0x00000000; //HDMITX -- default 0x00000000 (AUDIO_InfoFrame45)
        G385_HDMITX_REG->g385_reserved[16] = 0x00000000; //HDMITX -- default 0x00000000 (AUDIO_InfoFrame67)
        G385_HDMITX_REG->g385_reserved[17] = 0x00000000; //HDMITX -- default 0x00000000 (AUDIO_InfoFrame89)
        G385_HDMITX_REG->g385_reserved[18] = 0x00000000; //HDMITX -- default 0x00000000 (AUDIO_InfoFrame1011)
 
    }
    else if (mode == 1) { //HDMITX 720x576 50Hz as default setting
        ; //TBD
    }
    else if (mode == 2) { //HDMITX 1280x720 59.94Hz as default setting
        printf("hdmitx_set_timming.G380 \n");
        //HDMITX G380
        G380_HDMITX_REG->g380_reserved[5] = 0x0000141f; //HDMITX -- default 0x0000140f (TMDSTX_PHY for pwr_down).
        G380_HDMITX_REG->g380_reserved[6] = 0x000000ff; //HDMITX -- default 0x000000e9 (SW_RESET)
        G380_HDMITX_REG->g380_reserved[8] = 0x00001001; //HDMITX -- default 0x00001000 (CTRL1 -- HDMI/DVI)
        G380_HDMITX_REG->g380_reserved[20] = 0x00005936; //HDMITX -- default 0x00000000 (Mi12)
        G380_HDMITX_REG->g380_reserved[21] = 0x0000e1c0; //HDMITX -- default 0x00000000 (Mi34)
        G380_HDMITX_REG->g380_reserved[22] = 0x0000a52e; //HDMITX -- default 0x00000000 (Mi56)
        G380_HDMITX_REG->g380_reserved[23] = 0x0000c7a6; //HDMITX -- default 0x00000000 (Mi78)
        //HDMITX G381
        printf("hdmitx_set_timming.G381 \n");
        G381_HDMITX_REG->g381_reserved[16] = 0x00000140; //HDMITX -- default 0x00000000 (VIDEO_CTRL1)
        //HDMITX G382
        printf("hdmitx_set_timming.G382 \n");
        G382_HDMITX_REG->g382_reserved[12] = 0x00000040; //HDMITX -- default 0x00000000 (vsync_out/hsync_out/color_depth)
        G382_HDMITX_REG->g382_reserved[16] = 0x0000e411; //HDMITX -- default 0x0000e400 (AUDIO_CTRL1)
        G382_HDMITX_REG->g382_reserved[17] = 0x000001b5; //HDMITX -- default 0x000001b4 (AUDIO_CTRL2)
        G382_HDMITX_REG->g382_reserved[18] = 0x0000007e; //HDMITX -- default 0x00000020 (AUDIO_SPDIF_CTRL)
        G382_HDMITX_REG->g382_reserved[26] = 0x00000085; //HDMITX -- default 0x00000004 (ACR_CONFIG1)
        G382_HDMITX_REG->g382_reserved[27] = 0x00001800; //HDMITX -- default 0x00000000 (ACR_VALUE1)
        G382_HDMITX_REG->g382_reserved[28] = 0x00000000; //HDMITX -- default 0x00000000 (ACR_VALUE2)
        //HDMITX G383
        printf("hdmitx_set_timming.G383 \n");
        G383_HDMITX_REG->g383_reserved[1] = 0x00000003; //HDMITX -- default 0x00000000 (INTR0_UNMASK)
        G383_HDMITX_REG->g383_reserved[2] = 0x00000004; //HDMITX -- default 0x00000000 (INTR1_UNMASK)
        G383_HDMITX_REG->g383_reserved[3] = 0x00000000; //HDMITX -- default 0x00000000 (INTR2_UNMASK)
        G383_HDMITX_REG->g383_reserved[7] = 0x00005018; //HDMITX -- default 0x00005000 (DDC_MASTER_SET)
        G383_HDMITX_REG->g383_reserved[8] = 0x000000a0; //HDMITX -- default 0x00000074 (DDC_SLV_DEVICE_ADDR)
        G383_HDMITX_REG->g383_reserved[11] = 0x00000010; //HDMITX -- default 0x00000000 (DDC_DATA_CNT)
        //HDMITX G385
        printf("hdmitx_set_timming.G385 \n");
        G385_HDMITX_REG->g385_reserved[0] = 0x00001a1a; //HDMITX -- default 0x00001010 (InfoFrame CTRL1)
        G385_HDMITX_REG->g385_reserved[1] = 0x0000101a; //HDMITX -- default 0x00001010 (InfoFrame CTRL2)
        G385_HDMITX_REG->g385_reserved[2] = 0x00001010; //HDMITX -- default 0x00001010 (InfoFrame CTRL3)
        G385_HDMITX_REG->g385_reserved[3] = 0x00001010; //HDMITX -- default 0x00001010 (InfoFrame CTRL4)
        G385_HDMITX_REG->g385_reserved[4] = 0x00000010; //HDMITX -- default 0x00000010 (InfoFrame CTRL5)
        G385_HDMITX_REG->g385_reserved[5] = 0x00001010; //HDMITX -- default 0x00001010 (InfoFrame CTRL6)
        G385_HDMITX_REG->g385_reserved[6] = 0x00001cb6; //HDMITX -- default 0x00000000 (AVI_InfoFrame01)
        G385_HDMITX_REG->g385_reserved[7] = 0x000000a8; //HDMITX -- default 0x00000000 (AVI_InfoFrame23)
        G385_HDMITX_REG->g385_reserved[8] = 0x00000004; //HDMITX -- default 0x00000000 (AVI_InfoFrame45)
        G385_HDMITX_REG->g385_reserved[9] = 0x00000024; //HDMITX -- default 0x00000000 (AVI_InfoFrame67)
        G385_HDMITX_REG->g385_reserved[10] = 0x00000204; //HDMITX -- default 0x00000000 (AVI_InfoFrame89)
        G385_HDMITX_REG->g385_reserved[11] = 0x0000007a; //HDMITX -- default 0x00000000 (AVI_InfoFrame1011)
        G385_HDMITX_REG->g385_reserved[12] = 0x0000034a; //HDMITX -- default 0x00000000 (AVI_InfoFrame1213)
        G385_HDMITX_REG->g385_reserved[13] = 0x00000170; //HDMITX -- default 0x00000000 (AUDIO_InfoFrame01)
        G385_HDMITX_REG->g385_reserved[14] = 0x00000000; //HDMITX -- default 0x00000000 (AUDIO_InfoFrame23)
        G385_HDMITX_REG->g385_reserved[15] = 0x00000000; //HDMITX -- default 0x00000000 (AUDIO_InfoFrame45)
        G385_HDMITX_REG->g385_reserved[16] = 0x00000000; //HDMITX -- default 0x00000000 (AUDIO_InfoFrame67)
        G385_HDMITX_REG->g385_reserved[17] = 0x00000000; //HDMITX -- default 0x00000000 (AUDIO_InfoFrame89)
        G385_HDMITX_REG->g385_reserved[18] = 0x00000000; //HDMITX -- default 0x00000000 (AUDIO_InfoFrame1011)
    }
    else {
		;//TBD , the rest setting
    }
}

