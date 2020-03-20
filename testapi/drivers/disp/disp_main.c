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
void run_draw_init_cmd(int disp_path, int input_fmt);

#ifdef DDFCH_FETCH_EN
//#include "vpp_pattern/yuv420_NV12_800x480.h"
//#include "vpp_pattern/yuv422_NV16_800x480.h"
#include "vpp_pattern/yuv422_YUY2_800x480.h"
//#include "vpp_pattern/yuv420_NV12_720x480.h"
//#include "vpp_pattern/yuv422_NV16_720x480.h"
#include "vpp_pattern/yuv422_YUY2_720x480.h"
#endif
#ifdef OSD0_FETCH_EN
//#include "osd_pattern/yuv422_YUY2_800x480.h"
//#include "osd_pattern/yuv422_YUY2_720x480.h"
#endif

#ifdef DDFCH_FETCH_EN
void fetch_ddfch_path(int input_fmt);
#endif
#ifdef OSD0_FETCH_EN
void fetch_osd0_path(int input_fmt);
#endif

int disp_init_width = 0; 
int disp_init_height = 0;
int disp_init_osd0_fmt = 0;

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

    //DRV_OSD_Set_UI_Init(width, height, DRV_OSD_REGION_FORMAT_ARGB_8888);

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
    //osd0_data_addr_list();

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
        //DRV_DMIX_Layer_Set(DRV_DMIX_Opacity, DRV_DMIX_VPP0); //show vpp0 layer
        //DRV_DMIX_Layer_Set(DRV_DMIX_Opacity, DRV_DMIX_OSD0); //show osd0 layer,vpp0 layer will be hidden
        DRV_DMIX_Layer_Set(DRV_DMIX_AlphaBlend, DRV_DMIX_VPP0); //show vpp0 layer
        DRV_DMIX_Layer_Set(DRV_DMIX_AlphaBlend, DRV_DMIX_OSD0); //show osd0 layer
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
    if ((disp_init_width!=0) && (disp_init_height!=0)) {
        if (input_fmt == 2) {
            printf("fetch_osd0_path [8bpp].\n");
            if ((disp_init_width==320) && (disp_init_height==240))
                ; 
            else if ((disp_init_width==720) && (disp_init_height==480))
                osd0_setting_hdmi(disp_init_width, disp_init_height, DRV_OSD_REGION_FORMAT_8BPP);
            else if ((disp_init_width==800) && (disp_init_height==480))
                osd0_setting(disp_init_width, disp_init_height, DRV_OSD_REGION_FORMAT_8BPP); 
            else if ((disp_init_width==1024) && (disp_init_height==600))
                ; 
            else if ((disp_init_width==1280) && (disp_init_height==720))
                ; 
        }
        else if (input_fmt == 4) {
            printf("fetch_osd0_path [YUY2].\n");
            if ((disp_init_width==320) && (disp_init_height==240))
                ; 
            else if ((disp_init_width==720) && (disp_init_height==480))
                osd0_setting_hdmi(disp_init_width, disp_init_height, DRV_OSD_REGION_FORMAT_YUY2); 
            else if ((disp_init_width==800) && (disp_init_height==480))
                osd0_setting(disp_init_width, disp_init_height, DRV_OSD_REGION_FORMAT_YUY2); 
            else if ((disp_init_width==1024) && (disp_init_height==600))
                ; 
            else if ((disp_init_width==1280) && (disp_init_height==720))
                ; 
        }
        else if (input_fmt == 8) {
            printf("fetch_osd0_path [RGB565].\n");
            if ((disp_init_width==320) && (disp_init_height==240))
                ; 
            else if ((disp_init_width==720) && (disp_init_height==480))
                osd0_setting_hdmi(disp_init_width, disp_init_height, DRV_OSD_REGION_FORMAT_RGB_565); 
            else if ((disp_init_width==800) && (disp_init_height==480))
                osd0_setting(disp_init_width, disp_init_height, DRV_OSD_REGION_FORMAT_RGB_565); 
            else if ((disp_init_width==1024) && (disp_init_height==600))
                ; 
            else if ((disp_init_width==1280) && (disp_init_height==720))
                ; 
        }
        else if (input_fmt == 9) {
            printf("fetch_osd0_path [ARGB1555].\n");
            if ((disp_init_width==320) && (disp_init_height==240))
                ; 
            else if ((disp_init_width==720) && (disp_init_height==480))
                osd0_setting_hdmi(disp_init_width, disp_init_height, DRV_OSD_REGION_FORMAT_ARGB_1555); 
            else if ((disp_init_width==800) && (disp_init_height==480))
                osd0_setting(disp_init_width, disp_init_height, DRV_OSD_REGION_FORMAT_ARGB_1555); 
            else if ((disp_init_width==1024) && (disp_init_height==600))
                ; 
            else if ((disp_init_width==1280) && (disp_init_height==720))
                ; 
        }
        else if (input_fmt == 10) {
            printf("fetch_osd0_path [RGBA4444].\n");
            if ((disp_init_width==320) && (disp_init_height==240))
                ; 
            else if ((disp_init_width==720) && (disp_init_height==480))
                osd0_setting_hdmi(disp_init_width, disp_init_height, DRV_OSD_REGION_FORMAT_RGBA_4444); 
            else if ((disp_init_width==800) && (disp_init_height==480))
                osd0_setting(disp_init_width, disp_init_height, DRV_OSD_REGION_FORMAT_RGBA_4444); 
            else if ((disp_init_width==1024) && (disp_init_height==600))
                ; 
            else if ((disp_init_width==1280) && (disp_init_height==720))
                ; 
        }
        else if (input_fmt == 11) {
            printf("fetch_osd0_path [ARGB4444].\n");
            if ((disp_init_width==320) && (disp_init_height==240))
                ; 
            else if ((disp_init_width==720) && (disp_init_height==480))
                osd0_setting_hdmi(disp_init_width, disp_init_height, DRV_OSD_REGION_FORMAT_ARGB_4444);
            else if ((disp_init_width==800) && (disp_init_height==480))
                osd0_setting(disp_init_width, disp_init_height, DRV_OSD_REGION_FORMAT_ARGB_4444); 
            else if ((disp_init_width==1024) && (disp_init_height==600))
                ; 
            else if ((disp_init_width==1280) && (disp_init_height==720))
                ; 
        }
        else if (input_fmt == 13) {
            printf("fetch_osd0_path [RGBA8888].\n");
            if ((disp_init_width==320) && (disp_init_height==240))
                ; 
            else if ((disp_init_width==720) && (disp_init_height==480))
                osd0_setting_hdmi(disp_init_width, disp_init_height, DRV_OSD_REGION_FORMAT_RGBA_8888); 
            else if ((disp_init_width==800) && (disp_init_height==480))
                osd0_setting(disp_init_width, disp_init_height, DRV_OSD_REGION_FORMAT_RGBA_8888); 
            else if ((disp_init_width==1024) && (disp_init_height==600))
                ; 
            else if ((disp_init_width==1280) && (disp_init_height==720))
                ; 
        }
        else if (input_fmt == 14) {
            printf("fetch_osd0_path [ARGB8888].\n");
            if ((disp_init_width==320) && (disp_init_height==240))
                ; 
            else if ((disp_init_width==720) && (disp_init_height==480))
                osd0_setting_hdmi(disp_init_width, disp_init_height, DRV_OSD_REGION_FORMAT_ARGB_8888); 
            else if ((disp_init_width==800) && (disp_init_height==480))
                osd0_setting(disp_init_width, disp_init_height, DRV_OSD_REGION_FORMAT_ARGB_8888); 
            else if ((disp_init_width==1024) && (disp_init_height==600))
                ; 
            else if ((disp_init_width==1280) && (disp_init_height==720))
                ; 
        }
        else {
            printf("fetch_osd0_path [undefined].\n");
        }
    }
}

void run_draw_init_cmd(int disp_path, int input_fmt)
{
    printf("run_draw_init_cmd.\n");
    if (disp_path == 0) {
        printf("draw ddfch init.\n");
        printf("draw ddfch init cmd not available.\n");
    }
    else if (disp_path == 1) {
        printf("draw osd0 init.\n");
        
        #ifdef OSD0_API_IMPLEMENT
        disp_init_osd0_fmt = input_fmt;
        API_OSD_UI_Init(disp_init_width ,disp_init_height, input_fmt);
        #else
        printf("draw osd0 init cmd not available.\n");
        #endif
    }

}

void run_draw_pixel_cmd(int test)
{
    #ifdef OSD0_API_IMPLEMENT
    INT16 x,y;
    UINT32 color;
    int ret;
    printf("run_draw_pixel_cmd.\n");
    if (test == 0) {
        printf("draw pixel test1 \n");
        if(disp_init_osd0_fmt == 0x2)
            color = 128;
        else
            color = SWAP32(0xb35ad1ff); //with swap (BGRA)

        for (x = 300; x < 500 ; x++) {
            for (y = 50; y < 150 ; y++) {
                ret = SP_OSD_DrawPixel(disp_init_osd0_fmt, x, y, color);
                if(ret)
                    printf("draw pixel test1 fail \n");
            }
        }
    }
    else if (test == 1) {
        printf("draw pixel test2 \n");
        if(disp_init_osd0_fmt == 0x2) {
            for (color = 0; color < 256 ; color++) {
                for (x = 100+color*2; x < 102+color*2 ; x++) {
                    for (y = 400; y < 450 ; y++) {
                        ret = SP_OSD_DrawPixel(disp_init_osd0_fmt, x, y, color);
                        if(ret)
                            printf("draw pixel test2 fail \n");
                    }
                }
            }
        }
        else {
            ;
        }
    }
    else if (test == 2) {
        printf("draw pixel test3 \n");
        if(disp_init_osd0_fmt == 0x2) {
            for (color = 0; color < 256 ; color++) {
                for (x = 700; x < 750 ; x++) {
                    for (y = 100+color; y < 101+color ; y++) {
                        ret = SP_OSD_DrawPixel(disp_init_osd0_fmt, x, y, color);
                        if(ret)
                            printf("draw pixel test3 fail \n");
                    }
                }
            }
        }
        else {
            ;
        }
    }
    #else
    printf("run_draw_pixel_cmd not support \n");
    #endif 
}

void run_draw_line_cmd(int test)
{
    #ifdef OSD0_API_IMPLEMENT
    INT16 x,y,len,width,height;
    UINT32 color;
    int ret;
    printf("run_draw_line_cmd.\n");
    if (test == 0) {
        printf("draw line test1 \n");
        x = 20;
        y = 20;
        len = 100;
        if(disp_init_osd0_fmt == 0x2)
            color = 138;
        else
            color = SWAP32(0x54611aff); //with swap (BGRA)

        ret = SP_OSD_DrawHorizLine(disp_init_osd0_fmt, x, y, len, color);
        if(ret)
            printf("draw line test1 fail \n");
    }
    else if (test == 1) {
        printf("draw line test2 \n");
        x = 20;
        y = 20;
        len = 100;
        if(disp_init_osd0_fmt == 0x2)
            color = 148;
        else
            color = SWAP32(0xf2f2eeff); //with swap (BGRA)

        ret = SP_OSD_DrawVertiLine(disp_init_osd0_fmt, x, y, len, color);
        if(ret)
            printf("draw line test2 fail \n");
    }
    else if (test == 2) {
        printf("draw line test3 \n");
        x = 299;
        y = 49;
        width = 202;
        height = 102;
        if(disp_init_osd0_fmt == 0x2)
            color = 158;
        else
            color = SWAP32(0x465213ff); //with swap (BGRA)

        ret = SP_OSD_DrawBorderLine(disp_init_osd0_fmt, x, y, width, height, color);
        if(ret)
            printf("draw line test3 fail \n");
    }
    #else
    printf("run_draw_line_cmd not support \n");
    #endif    
}

//unsigned char draw_font_test0[] = "This is a test for Draw Font,support for 8bpp/yuy2/rgb565/argb1555/rgba4444/argb4444/rgba8888/argb8888";
unsigned char draw_font_test0[] = "Draw Font 10X20";
unsigned char draw_font_test1[] = "Draw Font 20X20";
unsigned char draw_font_test2[] = "Draw Font 12X24";
unsigned char draw_font_test3[] = "Draw Font 24X24";
unsigned char draw_font_test4[] = "Draw Font 16X32";
unsigned char draw_font_test5[] = "Draw Font 32X32";
unsigned char draw_font_test6[] = "Draw Font 24X48";
unsigned char draw_font_test7[] = "Draw Font 48X48";

//OSD0_BIG5_COM_FONT_ARIAL_20X20
unsigned char draw_big5_font_test0[] = {0xA4,0x6A,0xA4,0xAD,0xBD,0x58,0xA1,0x5A,
                                        0xB0,0xF2,0xA5,0xBB,0xA1,0x47,0xA2,0xB1,
                                        0xA2,0xAF,0xA2,0xE6,0xA2,0xB1,0xA2,0xAF,
                                        0xC3,0xB8,0xA6,0x72,0xB4,0xFA,0xB8,0xD5,
                                        0xA1,0x41,0xA2,0xDD,0xA2,0xD9,0xA1,0x49,0x00};
//OSD0_BIG5_EXT_FONT_ARIAL_20X20
unsigned char draw_big5_font_test1[] = {0xA4,0x6A,0xA4,0xAD,0xBD,0x58,0xA1,0x5A,
                                        0xC2,0x58,0xAE,0x69,0xA1,0x47,0xA2,0xB1,
                                        0xA2,0xAF,0xA2,0xE6,0xA2,0xB1,0xA2,0xAF,
                                        0xC3,0xB8,0xA6,0x72,0xB4,0xFA,0xB8,0xD5,
                                        0xA1,0x41,0xA2,0xDD,0xA2,0xD9,0xA1,0x49,0x00};
//OSD0_BIG5_COM_FONT_ARIAL_24X24
unsigned char draw_big5_font_test2[] = {0xA4,0x6A,0xA4,0xAD,0xBD,0x58,0xA1,0x5A,
                                        0xB0,0xF2,0xA5,0xBB,0xA1,0x47,0xA2,0xB1,
                                        0xA2,0xB3,0xA2,0xE6,0xA2,0xB1,0xA2,0xB3,
                                        0xC3,0xB8,0xA6,0x72,0xB4,0xFA,0xB8,0xD5,
                                        0xA1,0x41,0xA2,0xDD,0xA2,0xD9,0xA1,0x49,0x00};
//OSD0_BIG5_EXT_FONT_ARIAL_24X24
unsigned char draw_big5_font_test3[] = {0xA4,0x6A,0xA4,0xAD,0xBD,0x58,0xA1,0x5A,
                                        0xC2,0x58,0xAE,0x69,0xA1,0x47,0xA2,0xB1,
                                        0xA2,0xB3,0xA2,0xE6,0xA2,0xB1,0xA2,0xB3,
                                        0xC3,0xB8,0xA6,0x72,0xB4,0xFA,0xB8,0xD5,
                                        0xA1,0x41,0xA2,0xDD,0xA2,0xD9,0xA1,0x49,0x00};
//OSD0_BIG5_COM_FONT_ARIAL_32X32
unsigned char draw_big5_font_test4[] = {0xA4,0x6A,0xA4,0xAD,0xBD,0x58,0xA1,0x5A,
                                        0xB0,0xF2,0xA5,0xBB,0xA1,0x47,0xA2,0xB2,
                                        0xA2,0xB1,0xA2,0xE6,0xA2,0xB2,0xA2,0xB1,
                                        0xC3,0xB8,0xA6,0x72,0xB4,0xFA,0xB8,0xD5,
                                        0xA1,0x41,0xA2,0xDD,0xA2,0xD9,0xA1,0x49,0x00};
//OSD0_BIG5_EXT_FONT_ARIAL_32X32
unsigned char draw_big5_font_test5[] = {0xA4,0x6A,0xA4,0xAD,0xBD,0x58,0xA1,0x5A,
                                        0xC2,0x58,0xAE,0x69,0xA1,0x47,0xA2,0xB2,
                                        0xA2,0xB1,0xA2,0xE6,0xA2,0xB2,0xA2,0xB1,
                                        0xC3,0xB8,0xA6,0x72,0xB4,0xFA,0xB8,0xD5,
                                        0xA1,0x41,0xA2,0xDD,0xA2,0xD9,0xA1,0x49,0x00};
//OSD0_BIG5_COM_FONT_ARIAL_48X48
unsigned char draw_big5_font_test6[] = {0xA4,0x6A,0xA4,0xAD,0xBD,0x58,0xA1,0x5A,
                                        0xB0,0xF2,0xA5,0xBB,0xA1,0x47,0xA2,0xB3,
                                        0xA2,0xB7,0xA2,0xE6,0xA2,0xB3,0xA2,0xB7,
                                        0xC3,0xB8,0xA6,0x72,0xB4,0xFA,0xB8,0xD5,
                                        0xA1,0x41,0xA2,0xDD,0xA2,0xD9,0xA1,0x49,0x00};
//OSD0_BIG5_EXT_FONT_ARIAL_48X48
unsigned char draw_big5_font_test7[] = {0xA4,0x6A,0xA4,0xAD,0xBD,0x58,0xA1,0x5A,
                                        0xC2,0x58,0xAE,0x69,0xA1,0x47,0xA2,0xB3,
                                        0xA2,0xB7,0xA2,0xE6,0xA2,0xB3,0xA2,0xB7,
                                        0xC3,0xB8,0xA6,0x72,0xB4,0xFA,0xB8,0xD5,
                                        0xA1,0x41,0xA2,0xDD,0xA2,0xD9,0xA1,0x49,0x00};
//OSD0_GB2312_COM_FONT_ARIAL_20X20
unsigned char draw_gb2312_font_test0[] = {0xBA,0xBA,0xD7,0xD6,0xC4,0xDA,0xC2,0xEB,
                                        0xBB,0xF9,0xB1,0xBE,0xA3,0xBA,0xA3,0xB2,
                                        0xA3,0xB0,0xA3,0xD8,0xA3,0xB2,0xA3,0xB0,
                                        0xBB,0xE6,0xD7,0xD6,0xB2,0xE2,0xCA,0xD4,
                                        0xA3,0xAC,0xA3,0xCF,0xA3,0xCB,0xA3,0xA1,0x00};
//OSD0_GBK_EXT_FONT_ARIAL_20X20
unsigned char draw_gb2312_font_test1[] = {0xBA,0xBA,0xD7,0xD6,0xC4,0xDA,0xC2,0xEB,
                                        0xC0,0xA9,0xD5,0xB9,0xA3,0xBA,0xA3,0xB2,
                                        0xA3,0xB0,0xA3,0xD8,0xA3,0xB2,0xA3,0xB0,
                                        0xBB,0xE6,0xD7,0xD6,0xB2,0xE2,0xCA,0xD4,
                                        0xA3,0xAC,0xA3,0xCF,0xA3,0xCB,0xA3,0xA1,
                                        0xC0,0x4C,0xD7,0xD6,0x9C,0x79,0xD4,0x87,0x00};
//OSD0_GB2312_COM_FONT_ARIAL_24X24
unsigned char draw_gb2312_font_test2[] = {0xBA,0xBA,0xD7,0xD6,0xC4,0xDA,0xC2,0xEB,
                                        0xBB,0xF9,0xB1,0xBE,0xA3,0xBA,0xA3,0xB2,
                                        0xA3,0xB4,0xA3,0xD8,0xA3,0xB2,0xA3,0xB4,
                                        0xBB,0xE6,0xD7,0xD6,0xB2,0xE2,0xCA,0xD4,
                                        0xA3,0xAC,0xA3,0xCF,0xA3,0xCB,0xA3,0xA1,0x00};
//OSD0_GBK_EXT_FONT_ARIAL_24X24
unsigned char draw_gb2312_font_test3[] = {0xBA,0xBA,0xD7,0xD6,0xC4,0xDA,0xC2,0xEB,
                                        0xC0,0xA9,0xD5,0xB9,0xA3,0xBA,0xA3,0xB2,
                                        0xA3,0xB4,0xA3,0xD8,0xA3,0xB2,0xA3,0xB4,
                                        0xBB,0xE6,0xD7,0xD6,0xB2,0xE2,0xCA,0xD4,
                                        0xA3,0xAC,0xA3,0xCF,0xA3,0xCB,0xA3,0xA1,
                                        0xC0,0x4C,0xD7,0xD6,0x9C,0x79,0xD4,0x87,0x00};
//OSD0_GB2312_COM_FONT_ARIAL_32X32
unsigned char draw_gb2312_font_test4[] = {0xBA,0xBA,0xD7,0xD6,0xC4,0xDA,0xC2,0xEB,
                                        0xBB,0xF9,0xB1,0xBE,0xA3,0xBA,0xA3,0xB3,
                                        0xA3,0xB2,0xA3,0xD8,0xA3,0xB3,0xA3,0xB2,
                                        0xBB,0xE6,0xD7,0xD6,0xB2,0xE2,0xCA,0xD4,
                                        0xA3,0xAC,0xA3,0xCF,0xA3,0xCB,0xA3,0xA1,0x00};
//OSD0_GBK_EXT_FONT_ARIAL_32X32
unsigned char draw_gb2312_font_test5[] = {0xBA,0xBA,0xD7,0xD6,0xC4,0xDA,0xC2,0xEB,
                                        0xC0,0xA9,0xD5,0xB9,0xA3,0xBA,0xA3,0xB3,
                                        0xA3,0xB2,0xA3,0xD8,0xA3,0xB3,0xA3,0xB2,
                                        0xBB,0xE6,0xD7,0xD6,0xB2,0xE2,0xCA,0xD4,
                                        0xA3,0xAC,0xA3,0xCF,0xA3,0xCB,0xA3,0xA1,
                                        0xC0,0x4C,0xD7,0xD6,0x9C,0x79,0xD4,0x87,0x00};
//OSD0_GB2312_COM_FONT_ARIAL_48X48
unsigned char draw_gb2312_font_test6[] = {0xBA,0xBA,0xD7,0xD6,0xC4,0xDA,0xC2,0xEB,
                                        0xBB,0xF9,0xB1,0xBE,0xA3,0xBA,0xA3,0xB4,
                                        0xA3,0xB8,0xA3,0xD8,0xA3,0xB4,0xA3,0xB8,
                                        0xBB,0xE6,0xD7,0xD6,0xB2,0xE2,0xCA,0xD4,
                                        0xA3,0xAC,0xA3,0xCF,0xA3,0xCB,0xA3,0xA1,0x00};
//OSD0_GBK_EXT_FONT_ARIAL_48X48
unsigned char draw_gb2312_font_test7[] = {0xBA,0xBA,0xD7,0xD6,0xC4,0xDA,0xC2,0xEB,
                                        0xC0,0xA9,0xD5,0xB9,0xA3,0xBA,0xA3,0xB4,
                                        0xA3,0xB8,0xA3,0xD8,0xA3,0xB4,0xA3,0xB8,
                                        0xBB,0xE6,0xD7,0xD6,0xB2,0xE2,0xCA,0xD4,
                                        0xA3,0xAC,0xA3,0xCF,0xA3,0xCB,0xA3,0xA1,
                                        0xC0,0x4C,0xD7,0xD6,0x9C,0x79,0xD4,0x87,0x00};

void run_draw_font_cmd(int test)
{
    #ifdef OSD0_API_IMPLEMENT
    int ret;
    int x,y;
    int font_type;
    UINT32 bg_color,font_color;

    printf("run_draw_font_cmd.\n");
    if (test == 0) {
        printf("draw font test1 \n");

        if (disp_init_osd0_fmt == 0x2) {
            bg_color = 255;
            font_color = 128;
        }
        else {
            bg_color = 0xff30fc9e; //with swap (ARGB)
            font_color = SWAP32(0xb35ad1ff); //with swap (BGRA)            
        }

        font_type = 0;

        if ((disp_init_width==720) && (disp_init_height==480))
            x=0;
        else
            x=50;
        y=20;
        ret = SP_OSD_DrawString_Ascii_std(draw_font_test0, font_type, disp_init_osd0_fmt, x, y, bg_color, font_color);
        if(ret)
            printf("draw font test1 fail1 \n");

        font_type = 1;
        //x=100;
        y+=(30);
        ret = SP_OSD_DrawString_Ascii_std(draw_font_test1, font_type, disp_init_osd0_fmt, x, y, bg_color, font_color);
        if(ret)
            printf("draw font test1 fail1 \n");

        font_type = 2;
        //x=100;
        y+=(30);
        ret = SP_OSD_DrawString_Ascii_std(draw_font_test2, font_type, disp_init_osd0_fmt, x, y, bg_color, font_color);
        if(ret)
            printf("draw font test1 fail1 \n");

        font_type = 3;
        //x=100;
        y+=(34);
        ret = SP_OSD_DrawString_Ascii_std(draw_font_test3, font_type, disp_init_osd0_fmt, x, y, bg_color, font_color);
        if(ret)
            printf("draw font test1 fail1 \n");

        font_type = 4;
        //x=100;
        y+=(34);
        ret = SP_OSD_DrawString_Ascii_std(draw_font_test4, font_type, disp_init_osd0_fmt, x, y, bg_color, font_color);
        if(ret)
            printf("draw font test1 fail1 \n");

        font_type = 5;
        //x=100;
        y+=(42);
        ret = SP_OSD_DrawString_Ascii_std(draw_font_test5, font_type, disp_init_osd0_fmt, x, y, bg_color, font_color);
        if(ret)
            printf("draw font test1 fail1 \n");

        font_type = 6;
        //x=100;
        y+=(42);
        ret = SP_OSD_DrawString_Ascii_std(draw_font_test6, font_type, disp_init_osd0_fmt, x, y, bg_color, font_color);
        if(ret)
            printf("draw font test1 fail1 \n");

        font_type = 7;
        //x=100;
        y+=(58);
        ret = SP_OSD_DrawString_Ascii_std(draw_font_test7, font_type, disp_init_osd0_fmt, x, y, bg_color, font_color);
        if(ret)
            printf("draw font test1 fail1 \n");

    }
    else if (test == 1) {
        printf("draw font test2 \n");

        if (disp_init_osd0_fmt == 0x2) {
            bg_color = 255;
            font_color = 128;
        }
        else {
            bg_color = 0xff30fc9e; //with swap (ARGB)
            font_color = SWAP32(0xb35ad1ff); //with swap (BGRA)            
        }

        font_type = 0;

        if ((disp_init_width==720) && (disp_init_height==480))
            x=0;
        else
            x=50;
        if (font_type == 3) x=0;

        y=20;
        if (font_type == 0) {
            ret = SP_OSD_DrawString_Big5_com(draw_big5_font_test0, font_type, disp_init_osd0_fmt, x, y, bg_color, font_color);

            y+=50;
            ret = SP_OSD_DrawString_Big5_ext(draw_big5_font_test1, font_type, disp_init_osd0_fmt, x, y, bg_color, font_color);

            y+=50;
            ret = SP_OSD_DrawString_Gb2312_com(draw_gb2312_font_test0, font_type, disp_init_osd0_fmt, x, y, bg_color, font_color);

            y+=50;
            ret = SP_OSD_DrawString_Gbk_ext(draw_gb2312_font_test1, font_type, disp_init_osd0_fmt, x, y, bg_color, font_color);
        }
        else if (font_type == 1) {
            ret = SP_OSD_DrawString_Big5_com(draw_big5_font_test2, font_type, disp_init_osd0_fmt, x, y, bg_color, font_color);

            y+=60;
            ret = SP_OSD_DrawString_Big5_ext(draw_big5_font_test3, font_type, disp_init_osd0_fmt, x, y, bg_color, font_color);

            y+=60;
            ret = SP_OSD_DrawString_Gb2312_com(draw_gb2312_font_test2, font_type, disp_init_osd0_fmt, x, y, bg_color, font_color);

            y+=60;
            ret = SP_OSD_DrawString_Gbk_ext(draw_gb2312_font_test3, font_type, disp_init_osd0_fmt, x, y, bg_color, font_color);            
        }
        else if (font_type == 2) {
            ret = SP_OSD_DrawString_Big5_com(draw_big5_font_test4, font_type, disp_init_osd0_fmt, x, y, bg_color, font_color);

            y+=75;
            ret = SP_OSD_DrawString_Big5_ext(draw_big5_font_test5, font_type, disp_init_osd0_fmt, x, y, bg_color, font_color);

            y+=75;
            ret = SP_OSD_DrawString_Gb2312_com(draw_gb2312_font_test4, font_type, disp_init_osd0_fmt, x, y, bg_color, font_color);

            y+=75;
            ret = SP_OSD_DrawString_Gbk_ext(draw_gb2312_font_test5, font_type, disp_init_osd0_fmt, x, y, bg_color, font_color);            
        }
        else if (font_type == 3) {
            ret = SP_OSD_DrawString_Big5_com(draw_big5_font_test6, font_type, disp_init_osd0_fmt, x, y, bg_color, font_color);

            y+=105;
            ret = SP_OSD_DrawString_Big5_ext(draw_big5_font_test7, font_type, disp_init_osd0_fmt, x, y, bg_color, font_color);

            y+=105;
            ret = SP_OSD_DrawString_Gb2312_com(draw_gb2312_font_test6, font_type, disp_init_osd0_fmt, x, y, bg_color, font_color);

            y+=105;
            ret = SP_OSD_DrawString_Gbk_ext(draw_gb2312_font_test7, font_type, disp_init_osd0_fmt, x, y, bg_color, font_color);            
        }
        if(ret)
            printf("draw font test2 fail1 \n");

    }
    #else
    printf("run_draw_font_cmd not support \n");
    #endif
}

void run_draw_clean_cmd(int test)
{
    #ifdef OSD0_API_IMPLEMENT
    UINT32 color;
    int ret;
    printf("run_draw_clean_cmd.\n");
    if (test == 0) {
        printf("draw clean test1 \n");

        if(disp_init_osd0_fmt == 0x2)
            color = 200;
        else
            color = 0xff30fc9e; //with swap (ARGB)

        ret = SP_OSD_FillArea(disp_init_osd0_fmt, 0, 0, disp_init_width, disp_init_height, color);
        if(ret)
            printf("draw clean test1 fail \n");
    }
    else if (test == 1) {
        printf("draw clean test2 \n");

        if(disp_init_osd0_fmt == 0x2)
            color = 220;
        else
            color = SWAP32(0x262a0aff); //with swap (BGRA)

        ret = SP_OSD_FillArea(disp_init_osd0_fmt, 0, 0, disp_init_width, disp_init_height, color);
        if(ret)
            printf("draw clean test2 fail \n");
    }
    else if (test == 2) {
        printf("draw clean test3 \n");

        if(disp_init_osd0_fmt == 0x2)
            color = 0;
        else
            color = SWAP32(0x00000000); //with swap (BGRA)

        ret = SP_OSD_FillArea(disp_init_osd0_fmt, 0, 0, disp_init_width, disp_init_height, color);
        if(ret)
            printf("draw clean test3 fail \n");
    }
    #else
    printf("run_draw_clean_cmd not support \n");
    #endif
}

#endif
