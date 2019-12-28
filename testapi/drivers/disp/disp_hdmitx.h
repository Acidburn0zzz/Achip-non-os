#ifndef __DISP_HDMITX_H__
#define __DISP_HDMITX_H__

void hdmi_clk_init(int mode);
void DRV_hdmitx_Init(int is_hdmi, int width, int height);
void hdmitx_set_ptg(int enable);
void hdmitx_set_timming(int mode);

#endif	//__DISP_HDMITX_H__
