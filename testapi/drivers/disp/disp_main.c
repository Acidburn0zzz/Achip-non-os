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
 * Description :  display register header for sp7021
 * ------------------------------------------------------
 * Rev  Date          Author(s)      Status & Comments
 * ======================================================
 * 0.1  2019/12/21    hammer.hsieh   initial version
 */
#include <emuio.h>
#include "regmap.h"
#include "reg_disp.h"
#include "display.h"

#include "disp_dmix.h"
#include "disp_dve.h"
#include "disp_osd.h"
#include "disp_vpp.h"
#include "disp_tgen.h"
#include "disp_hdmitx.h"

void run_fetch_data_cmd(int disp_path, int input_fmt);

#ifdef DDFCH_FETCH_EN
//#include "vpp_pattern/yuv420_NV12_800x480.h"
//#include "vpp_pattern/yuv422_NV16_800x480.h"
#include "vpp_pattern/yuv422_YUY2_800x480.h"
//#include "vpp_pattern/yuv420_NV12_720x480.h"
//#include "vpp_pattern/yuv422_NV16_720x480.h"
#include "vpp_pattern/yuv422_YUY2_720x480.h"
#endif
#ifdef OSD0_FETCH_EN
//#include "vpp_pattern/tmp1_yuy2.h"
#endif

#ifdef DDFCH_FETCH_EN
void fetch_ddfch_path(int input_fmt);
#endif
#ifdef OSD0_FETCH_EN
void fetch_osd0_path(int input_fmt);
#endif

int disp_init_width = 0; 
int disp_init_height = 0;

void disp_initial_settings()
{
	printf("Initial Disp.\n");
    //TBD , if necessary
	printf("Initial Disp Done.\n");
}

void ttl_pinmux_init(int is_hdmi)
{
    if(!is_hdmi)
        MOON1_REG->sft_cfg[4] = 0x00400040; //enable lcdif
    else 
        MOON1_REG->sft_cfg[4] = 0x00400000; //disable lcdif
}

void ttl_clk_init(int method)
{
    if (method == 0) {
        MOON4_REG->plltv_ctl[0] = 0x80418041; //en pll , clk = 27M //G4.14
        //MOON4_REG->plltv_ctl[1] = 0x00000000; //G4.15
        MOON4_REG->plltv_ctl[2] = 0xFFFF0000; //don't care //G4.16
        MOON4_REG->otp_st = 0x00200020; //clk div4 //G4.31
    }
    else {
        //with  formula ( FVCO = (27/(M+1)) * (N+1) )
        MOON4_REG->plltv_ctl[0] = 0x80020000; //don't bypass //G4.14
        //MOON4_REG->plltv_ctl[1] = 0x00000000; //G4.15
        MOON4_REG->plltv_ctl[2] = 0xFFFF1f27; //en pll , clk = 33.75M //(FVCO= (27/(M+1)) * (N+1) ) M=31,N=39 //G4.16
        MOON4_REG->otp_st = 0x00300000; //clk no div //G4.31
    }
}

void disp_set_output_resolution(int is_hdmi, int width, int height)
{
    int mode = 0;
    DRV_VideoFormat_e fmt;
    DRV_FrameRate_e fps;

	if(is_hdmi) { //hdmitx output
		if((width == 720)&&(height == 480)) {
			mode = 0;
			#ifdef TIMING_SYNC_720P60
			//hdmitx_set_timming(HDMITX_TIMING_480P);
			//hdmitx_enable_display(1);
			#endif
		}
		else if((width == 720)&&(height == 576)) {
			mode = 1;
			#ifdef TIMING_SYNC_720P60
			//hdmitx_set_timming(HDMITX_TIMING_576P);
			//hdmitx_enable_display(1);
			#endif
		}
		else if((width == 1280)&&(height == 720)) {
			mode = 2;
			#ifdef TIMING_SYNC_720P60
			//hdmitx_set_timming(HDMITX_TIMING_720P60);
			//hdmitx_enable_display(1);
			#endif
		}
		else if((width == 1920)&&(height == 1080)) {
			mode = 4;
			#ifdef TIMING_SYNC_720P60
			//hdmitx_set_timming(HDMITX_TIMING_1080P60);
			///hdmitx_enable_display(1);
			#endif
		}
		else {
			mode = 0;
			#ifdef TIMING_SYNC_720P60
			//hdmitx_set_timming(HDMITX_TIMING_480P);
			//hdmitx_enable_display(1);
			#endif
		}
        hdmi_clk_init(mode);
		printf("hdmitx output , mode = %d \n", mode);
	}
	else { //TTL output
		mode = 7;
		printf("TTL output , mode = %d \n", mode);
	}

    DRV_DVE_SetMode(mode);

	switch (mode)
	{
		default:
		case 0:
            printf("hdmitx output , 480P 59.94Hz \n");
			fmt = DRV_FMT_480P;
			fps = DRV_FrameRate_5994Hz;
            hdmitx_set_timming(0);
			break;
		case 1:
			fmt = DRV_FMT_576P;
			fps = DRV_FrameRate_50Hz;
            printf("hdmitx output , 576P 50Hz \n");
            hdmitx_set_timming(1);
			break;
		case 2:
            printf("hdmitx output , 720P 59.94Hz \n");
			fmt = DRV_FMT_720P;
			fps = DRV_FrameRate_5994Hz;
            hdmitx_set_timming(2);
			break;
		case 3:
			fmt = DRV_FMT_720P;
			fps = DRV_FrameRate_50Hz;
			break;
		case 4:
			fmt = DRV_FMT_1080P;
			fps = DRV_FrameRate_5994Hz;
			break;
		case 5:
			fmt = DRV_FMT_1080P;
			fps = DRV_FrameRate_50Hz;
			break;
		case 6:
			fmt = DRV_FMT_1080P;
			fps = DRV_FrameRate_24Hz;
			break;
		case 7:
			fmt = DRV_FMT_USER_MODE;
			fps = DRV_FrameRate_5994Hz;
			printf("set TGEN user mode\n");
			break;
	}

    DRV_TGEN_Set(fmt, fps);

}

void run_disp_init_cmd(int is_hdmi, int width, int height)
{
    //printf("run_init_cmd.\n");

    printf("is_hdmi %d, width %d, height %d \n", is_hdmi, width, height);

    disp_init_width = width; 
    disp_init_height = height;

    ttl_pinmux_init(is_hdmi);
    if(!is_hdmi) {
        ttl_clk_init(1);
    }

	//DMIX must first init
	DRV_DMIX_Init();
	DRV_TGEN_Init(is_hdmi, width, height);
	DRV_DVE_Init(is_hdmi, width, height);
	DRV_VPP_Init();
	DRV_OSD_Init();
    DRV_hdmitx_Init(is_hdmi, width, height);

	// DMIX setting
	/****************************************
	* BG: PTG
	* L1: VPP0
	* L6: OSD0
	*****************************************/
	DRV_DMIX_Layer_Init(DRV_DMIX_BG, DRV_DMIX_AlphaBlend, DRV_DMIX_PTG);
	DRV_DMIX_Layer_Init(DRV_DMIX_L1, DRV_DMIX_Opacity, DRV_DMIX_VPP0);
	DRV_DMIX_Layer_Init(DRV_DMIX_L6, DRV_DMIX_AlphaBlend, DRV_DMIX_OSD0);

    vpost_setting(is_hdmi, 0, 0, width, height, width, height);

    #ifdef DDFCH_FETCH_EN
    #else
	ddfch_setting(0x00120000, 0x00120000 + DISP_ALIGN(width, 128)*height, width, height, 0);
    #endif

    DRV_OSD_Set_UI_Init(width, height, DRV_OSD_REGION_FORMAT_ARGB_8888);

    disp_set_output_resolution(is_hdmi, width, height);

    #ifdef DDFCH_FETCH_EN
    //show ddfch fetch data , if fetch ddfch data on
    //run_fetch_data_cmd(0, 0); //NV12
    //run_fetch_data_cmd(0, 1); //NV16
    //run_fetch_data_cmd(0, 2); //YUY2
    if(is_hdmi) {
	    ddfch_setting(((int)&ddfch_fetch_YUY2_720X480_data00), ((int)&ddfch_fetch_YUY2_720X480_data00) + DISP_ALIGN(width, 128)*height, width, height, 2);
    }
    else {
        ddfch_setting(((int)&ddfch_fetch_YUY2_800X480_data00), ((int)&ddfch_fetch_YUY2_800X480_data00) + DISP_ALIGN(width, 128)*height, width, height, 2);
    } 
    #endif

    #ifdef OSD0_FETCH_EN


    #endif

    #ifdef FETCH_OFF
    //option1, show dve color bar , if fetch ddfch data off
    //DRV_DVE_SetColorbar(1); //enable dve

    //option2, show ddfch color bar , if fetch ddfch data off
    DRV_DVE_SetColorbar(0); //disable dve
    DRV_DMIX_Layer_Set(DRV_DMIX_Opacity, DRV_DMIX_VPP0); //show vpp0 layer
    DRV_DMIX_Layer_Set(DRV_DMIX_Transparent, DRV_DMIX_OSD0); //hide osd0 layer
    G199_VPOST_REG->vpost_config2 = 4; //VPOST
    G185_DDFCH_REG->ddfch_bist = 0x80801013;   
    #endif

}
void run_colorbar_cmd(int sel, int en)
{
    //printf("run_colorbar_cmd.\n");
    if (sel == 0) { //dve
        DRV_DVE_SetColorbar(en);
    }
    else if (sel == 1) { //dmix
        DRV_DVE_SetColorbar(0); //disable dve
        DRV_DMIX_Layer_Set(DRV_DMIX_Transparent, DRV_DMIX_VPP0); //hide vpp0 layer
        DRV_DMIX_Layer_Set(DRV_DMIX_Transparent, DRV_DMIX_OSD0); //hide osd0 layer
        if (en == 0) { //disable
            DRV_DMIX_PTG_ColorBar(DRV_DMIX_TPG_BGC,0xf000f0,0); //background color
        }
        else if (en == 1) { //enable -- color bar vertical
            DRV_DMIX_PTG_ColorBar(DRV_DMIX_TPG_V_COLORBAR,0xf000f0,0); //color bar (vertical)
        }    
        else if (en == 2) { //enable -- color bar horozontal
            DRV_DMIX_PTG_ColorBar(DRV_DMIX_TPG_H_COLORBAR,0xf000f0,0); //color bar (horozontal)
        }
        else if (en == 3) { //enable -- color bar border
            DRV_DMIX_PTG_ColorBar(DRV_DMIX_TPG_BORDER,0xf000f0,0); //color bar (border)
        }
        else if (en == 4) { //enable -- color bar snow 
            DRV_DMIX_PTG_ColorBar(DRV_DMIX_TPG_SNOW,0xf000f0,0); //color bar (snow)
        }        
    }
    else if (sel == 2) { //vpp0
        DRV_DVE_SetColorbar(0); //disable dve
        DRV_DMIX_Layer_Set(DRV_DMIX_Opacity, DRV_DMIX_VPP0); //show vpp0 layer
        DRV_DMIX_Layer_Set(DRV_DMIX_Transparent, DRV_DMIX_OSD0); //hide osd0 layer
        if (en == 0) { //disable
            G199_VPOST_REG->vpost_config2 = 4; //VPOST
        }
        else if (en == 1) { //enable
            G199_VPOST_REG->vpost_config2 = 5; //VPOST colorbar test pattern
        }
    }
    else if (sel == 3) { //ddfch
        DRV_DVE_SetColorbar(0); //disable dve
        DRV_DMIX_Layer_Set(DRV_DMIX_Opacity, DRV_DMIX_VPP0); //show vpp0 layer
        DRV_DMIX_Layer_Set(DRV_DMIX_Transparent, DRV_DMIX_OSD0); //hide osd0 layer
        G199_VPOST_REG->vpost_config2 = 4; //VPOST
        if (en == 0) { //disable
            G185_DDFCH_REG->ddfch_bist = 0x80801002;
        }
        else if (en == 1) { //enable -- color bar
            G185_DDFCH_REG->ddfch_bist = 0x80801013;
        }
        else if (en == 2) { //enable -- half color / half black
            G185_DDFCH_REG->ddfch_bist = 0x80801011;
        }
        else if (en == 3) { //enable -- half black / half white
            G185_DDFCH_REG->ddfch_bist = 0x80801001;
        }
    }
    else if (sel == 4) { //osd0
        DRV_DVE_SetColorbar(0); //disable dve
        DRV_DMIX_Layer_Set(DRV_DMIX_Opacity, DRV_DMIX_VPP0); //show vpp0 layer
        DRV_DMIX_Layer_Set(DRV_DMIX_Opacity, DRV_DMIX_OSD0); //show osd0 layer,vpp0 layer will be hidden
        if (en == 0) { //disable
            G196_OSD0_REG->osd_bist_ctrl = 0; //OSD0
        }
        else if (en == 1) { //enable -- color bar
            G196_OSD0_REG->osd_bist_ctrl = 0x80; //OSD0 (color bar)
        }
        else if (en == 2) { //enable -- border
            G196_OSD0_REG->osd_bist_ctrl = 0xC0; //OSD0 (border)
        }
    }
    else if (sel == 5) { //hdmitx
        if (en == 0) { //disable
            DRV_DVE_SetColorbar(0); //disable dve
            hdmitx_set_ptg(0);      //disable hdmitx ptg
        }
        else if (en == 1) { //enable -- color bar
            DRV_DVE_SetColorbar(1); //enable dve
            hdmitx_set_ptg(1);      //enable hdmitx ptg
        }
    }
}

void run_fetch_data_cmd(int disp_path, int input_fmt)
{
    printf("run_fetch_data_cmd.\n");
    if (disp_path == 0) {
        printf("fetch ddfch data.\n");
        #ifdef DDFCH_FETCH_EN
        DRV_DVE_SetColorbar(0); //disable dve
        DRV_DMIX_Layer_Set(DRV_DMIX_Opacity, DRV_DMIX_VPP0); //show vpp0 layer
        DRV_DMIX_Layer_Set(DRV_DMIX_Transparent, DRV_DMIX_OSD0); //hide osd0 layer
        G199_VPOST_REG->vpost_config2 = 4;          //disable VPOST bist
        G185_DDFCH_REG->ddfch_bist = 0x80801002;    //disable DDFCH bist
        fetch_ddfch_path(input_fmt);
        #else
        printf("fetch ddfch cmd not available.\n");
        #endif
    }
    else if (disp_path == 1) {
        printf("fetch oad0 data.\n");
        #ifdef OSD0_FETCH_EN
        DRV_DVE_SetColorbar(0); //disable dve
        DRV_DMIX_Layer_Set(DRV_DMIX_Opacity, DRV_DMIX_VPP0); //show vpp0 layer
        DRV_DMIX_Layer_Set(DRV_DMIX_Opacity, DRV_DMIX_OSD0); //show osd0 layer,vpp0 layer will be hidden
        G196_OSD0_REG->osd_bist_ctrl = 0; //disable OSD0 bist
        fetch_osd0_path(input_fmt);
        #else
        printf("fetch osd0 cmd not available.\n");
        #endif
    }
    else {
        printf("TBD.\n");
    }
}

#ifdef DDFCH_FETCH_EN
void fetch_ddfch_path(int input_fmt)
{
    if ((disp_init_width!=0) && (disp_init_height!=0)) {
        if (input_fmt == 0) {
            printf("fetch_ddfch_path [NV12].\n");
            if ((disp_init_width==320) && (disp_init_height==240))
                ; //ddfch_setting(((int)&ddfch_fetch_NV12_320X240_data00), ((int)&ddfch_fetch_NV12_320X240_data00 )+ DISP_ALIGN(disp_init_width, 128)*disp_init_height, disp_init_width, disp_init_height, 0);
            else if ((disp_init_width==720) && (disp_init_height==480))
                ; //ddfch_setting(((int)&ddfch_fetch_NV12_720X480_data00), ((int)&ddfch_fetch_NV12_720X480_data00 )+ DISP_ALIGN(disp_init_width, 128)*disp_init_height, disp_init_width, disp_init_height, 0);
            else if ((disp_init_width==800) && (disp_init_height==480))
                ; //ddfch_setting(((int)&ddfch_fetch_NV12_800X480_data00), ((int)&ddfch_fetch_NV12_800X480_data00 )+ DISP_ALIGN(disp_init_width, 128)*disp_init_height, disp_init_width, disp_init_height, 0);
            else if ((disp_init_width==1024) && (disp_init_height==600))
                ; //ddfch_setting(((int)&ddfch_fetch_NV12_1024X600_data00), ((int)&ddfch_fetch_NV12_1024X600_data00 )+ DISP_ALIGN(disp_init_width, 128)*disp_init_height, disp_init_width, disp_init_height, 0);
            else if ((disp_init_width==1280) && (disp_init_height==720))
                ; //ddfch_setting(((int)&ddfch_fetch_NV12_1280X720_data00), ((int)&ddfch_fetch_NV12_1280X720_data00 )+ DISP_ALIGN(disp_init_width, 128)*disp_init_height, disp_init_width, disp_init_height, 0);
        }
        else if (input_fmt == 1) {
            printf("fetch_ddfch_path [NV16].\n");
            if ((disp_init_width==320) && (disp_init_height==240))
                ; //ddfch_setting(((int)&ddfch_fetch_NV16_320X240_data00), ((int)&ddfch_fetch_NV16_320X240_data00 )+ DISP_ALIGN(disp_init_width, 128)*disp_init_height, disp_init_width, disp_init_height, 1);
            else if ((disp_init_width==720) && (disp_init_height==480))
                ; //ddfch_setting(((int)&ddfch_fetch_NV16_720X480_data00), ((int)&ddfch_fetch_NV16_720X480_data00 )+ DISP_ALIGN(disp_init_width, 128)*disp_init_height, disp_init_width, disp_init_height, 1);
            else if ((disp_init_width==800) && (disp_init_height==480))
                ; //ddfch_setting(((int)&ddfch_fetch_NV16_800X480_data00), ((int)&ddfch_fetch_NV16_800X480_data00 )+ DISP_ALIGN(disp_init_width, 128)*disp_init_height, disp_init_width, disp_init_height, 1);
            else if ((disp_init_width==1024) && (disp_init_height==600))
                ; //ddfch_setting(((int)&ddfch_fetch_NV16_1024X600_data00), ((int)&ddfch_fetch_NV16_1024X600_data00 )+ DISP_ALIGN(disp_init_width, 128)*disp_init_height, disp_init_width, disp_init_height, 1);
            else if ((disp_init_width==1280) && (disp_init_height==720))
                ; //ddfch_setting(((int)&ddfch_fetch_NV16_1280X720_data00), ((int)&ddfch_fetch_NV16_1280X720_data00 )+ DISP_ALIGN(disp_init_width, 128)*disp_init_height, disp_init_width, disp_init_height, 1);
        }
        else if (input_fmt == 2) {
            printf("fetch_ddfch_path [YUY2].\n");
            if ((disp_init_width==320) && (disp_init_height==240))
                ; //ddfch_setting(((int)&ddfch_fetch_YUY2_320X240_data00), ((int)&ddfch_fetch_YUY2_320X240_data00 )+ DISP_ALIGN(disp_init_width, 128)*disp_init_height, disp_init_width, disp_init_height, 2);
            else if ((disp_init_width==720) && (disp_init_height==480))
                ddfch_setting(((int)&ddfch_fetch_YUY2_720X480_data00), ((int)&ddfch_fetch_YUY2_720X480_data00 )+ DISP_ALIGN(disp_init_width, 128)*disp_init_height, disp_init_width, disp_init_height, 2);
            else if ((disp_init_width==800) && (disp_init_height==480))
                ddfch_setting(((int)&ddfch_fetch_YUY2_800X480_data00), ((int)&ddfch_fetch_YUY2_800X480_data00 )+ DISP_ALIGN(disp_init_width, 128)*disp_init_height, disp_init_width, disp_init_height, 2);
            else if ((disp_init_width==1024) && (disp_init_height==600))
                ; //ddfch_setting(((int)&ddfch_fetch_YUY2_1024X600_data00), ((int)&ddfch_fetch_YUY2_1024X600_data00 )+ DISP_ALIGN(disp_init_width, 128)*disp_init_height, disp_init_width, disp_init_height, 2);
            else if ((disp_init_width==1280) && (disp_init_height==720))
                ; //ddfch_setting(((int)&ddfch_fetch_YUY2_1280X720_data00), ((int)&ddfch_fetch_YUY2_1280X720_data00 )+ DISP_ALIGN(disp_init_width, 128)*disp_init_height, disp_init_width, disp_init_height, 2);
        }
        else {
            printf("fetch_ddfch_path [undefined].\n");
        }
    }
}
#endif

#ifdef OSD0_FETCH_EN
void fetch_osd0_path(int input_fmt)
{
    ; //TBD
}
#endif
