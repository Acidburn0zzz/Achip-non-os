#ifndef __DISP_OSD_H__
#define __DISP_OSD_H__

enum DRV_OsdWindow_e {
	DRV_OSD0 = 0,
	DRV_OSD_MAX
};

enum DRV_OsdRegionFormat_e {
	/* 8 bit/pixel with CLUT */
	DRV_OSD_REGION_FORMAT_8BPP			= 0x2,
	/* 16 bit/pixel YUY2 */
	DRV_OSD_REGION_FORMAT_YUY2			= 0x4,
	/* 16 bit/pixel RGB 5:6:5 */
	DRV_OSD_REGION_FORMAT_RGB_565		= 0x8,
	/* 16 bit/pixel ARGB 1:5:5:5 */
	DRV_OSD_REGION_FORMAT_ARGB_1555		= 0x9,
	/* 16 bit/pixel RGBA 4:4:4:4 */
	DRV_OSD_REGION_FORMAT_RGBA_4444		= 0xA,
	/* 16 bit/pixel ARGB 4:4:4:4 */
	DRV_OSD_REGION_FORMAT_ARGB_4444		= 0xB,
	/* 32 bit/pixel RGBA 8:8:8:8 */
	DRV_OSD_REGION_FORMAT_RGBA_8888		= 0xD,
	/* 32 bit/pixel ARGB 8:8:8:8 */
	DRV_OSD_REGION_FORMAT_ARGB_8888		= 0xE,
};

enum DRV_OsdTransparencyMode_e {
	DRV_OSD_TRANSPARENCY_DISABLED = 0,	/*!< transparency is disabled */
	DRV_OSD_TRANSPARENCY_ALL			/*!< the whole region is transparent */
};

typedef u32 DRV_OsdRegionHandle_t;

enum DRV_OsdBlendMethod_e {
	DRV_OSD_BLEND_REPLACE,		/*!< OSD blend method is region alpha replace */
	DRV_OSD_BLEND_MULTIPLIER,	/*!< OSD blend method is region alpha multiplier */
	MAX_BLEND_METHOD,
};

typedef struct _DRV_Region_Info_t
{
	u32 bufW;
	u32 bufH;
	u32 startX;
	u32 startY;
	u32 actW;
	u32 actH;
} DRV_Region_Info_t;

#ifdef OSD0_API_IMPLEMENT
typedef struct __attribute__ ((packed))
{
  UINT8  config0;
  UINT8  config1;
  UINT8  config2;
  UINT8  config3;
  UINT16 v_size;
  UINT16 h_size;
  UINT16 y;
  UINT16 x;
  UINT16 link_data;
  UINT16 link_next;
} osd_header_t;

typedef struct __attribute__ ((packed))
{
	UINT8	window;
	UINT8	num_buf;
	UINT8	visible;
	UINT8	active;
	UINT16  buf_addr[6];
} osd_info_t;


typedef struct osd_manager_s {
	osd_header_t	*pOSDHdr;
	osd_info_t		*pOSDInfo;
	int				size;
} osd_manager_t;
#endif

void DRV_OSD_Init();
void DRV_OSD_Set_UI_Init(int w,int h, enum DRV_OsdRegionFormat_e fmt);
void osd0_setting(int w, int h, int input_fmt);
void osd0_setting_hdmi(int w, int h, int input_fmt);
void osd0_data_addr_list(void);

#ifdef OSD0_API_IMPLEMENT
int API_OSD_UI_Init(int w, int h, int input_fmt);
int SP_OSD_DrawPixel(int input_fmt, INT16 x, INT16 y, UINT32 color);
int SP_OSD_DrawHorizLine(int input_fmt, INT16 x, INT16 y, UINT16 len, UINT32 color);
int SP_OSD_DrawVertiLine(int input_fmt, INT16 x, INT16 y, UINT16 len, UINT32 color);
int SP_OSD_DrawBorderLine(int input_fmt, INT16 x, INT16 y, UINT16 width, UINT16 height, UINT32 color);
int SP_OSD_FillArea(int input_fmt, INT16 x, INT16 y, UINT16 width, UINT16 height, UINT32 color);
int SP_OSD_DrawFont_Ascii_std(UINT8 *iCode, UINT8 *font_src, int input_fmt, INT16 dstX, INT16 dstY, UINT32 bg_color, UINT32 font_color);
int SP_OSD_DrawString_Ascii_std(UINT8 *pString, int font_type, int input_fmt, INT16 dstX, INT16 dstY, UINT32 bg_color, UINT32 font_color);
int SP_OSD_DrawFont_Big5_com(UINT8 *iCode, UINT8 *font_src, int input_fmt, INT16 dstX, INT16 dstY, UINT32 bg_color, UINT32 font_color);
int SP_OSD_DrawString_Big5_com(UINT8 *pString, int font_type, int input_fmt, INT16 dstX, INT16 dstY, UINT32 bg_color, UINT32 font_color);
int SP_OSD_DrawFont_Big5_ext(UINT8 *iCode, UINT8 *font_src, int input_fmt, INT16 dstX, INT16 dstY, UINT32 bg_color, UINT32 font_color);
int SP_OSD_DrawString_Big5_ext(UINT8 *pString, int font_type, int input_fmt, INT16 dstX, INT16 dstY, UINT32 bg_color, UINT32 font_color);
int SP_OSD_DrawFont_Gb2312_com(UINT8 *iCode, UINT8 *font_src, int input_fmt, INT16 dstX, INT16 dstY, UINT32 bg_color, UINT32 font_color);
int SP_OSD_DrawString_Gb2312_com(UINT8 *pString, int font_type, int input_fmt, INT16 dstX, INT16 dstY, UINT32 bg_color, UINT32 font_color);
int SP_OSD_DrawFont_Gbk_ext(UINT8 *iCode, UINT8 *font_src, int input_fmt, INT16 dstX, INT16 dstY, UINT32 bg_color, UINT32 font_color);
int SP_OSD_DrawString_Gbk_ext(UINT8 *pString, int font_type, int input_fmt, INT16 dstX, INT16 dstY, UINT32 bg_color, UINT32 font_color);
#endif

#endif	//__DISP_OSD_H__

