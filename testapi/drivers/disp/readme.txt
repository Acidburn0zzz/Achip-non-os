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
 * Description :  dispplay register header for sp7021
 * ------------------------------------------------------
 * Rev  Date          Author(s)      Status & Comments
 * ======================================================
 * 0.1  2019/12/21    hammer.hsieh   initial version
 */

Create display test command.
	disp init ttl 800 480 	; init 800x480 TTL pannel
	disp init hdmi 720 480 	; init 720x480 HDMI Monitor

	disp color dve en		; enable dve color bar
	disp color dmix en		; enable dmix color bar
	disp color vpp0 en		; enable vpp0 color bar
	disp color ddfch en		; enable ddfch color bar
	disp color osd0 en		; enable osd0 color bar
	disp color hdmitx en	; enable hdmitx color bar

	disp fetch ddfch en		; enable vpp0 path fetch data
	disp fetch osd0 en		; TBD
