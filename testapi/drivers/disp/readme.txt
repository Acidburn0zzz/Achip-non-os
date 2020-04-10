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
	disp fetch ddfch yuy2	; enable vpp0 path fetch data with fmt yuy2

	disp fetch osd0 en			; enable osd0 path fetch data
	disp fetch osd0 8bpp		; enable osd0 path fetch data with fmt 8bpp
	disp fetch osd0 yuy2		; enable osd0 path fetch data with fmt yuy2
	disp fetch osd0 argb8888	; enable osd0 path fetch data with fmt argb8888

	disp draw init 8bpp			; init draw function fmt with 8bpp

	disp draw pixel test1		; draw pixel function test1
	disp draw pixel test2		; draw pixel function test2 (only for fmt = 8bpp)
	disp draw pixel test3		; draw pixel function test3 (only for fmt = 8bpp)

	disp draw line test1		; draw line function test1
	disp draw line test2		; draw line function test2
	disp draw line test3		; draw line function test3

	disp draw font test1		; draw font function test1 (ascii code)
	disp draw font test2		; draw font function test2 (big5 / gb2312 / gbk code)

	disp draw clean test1		; draw clean function test1 (color1)
	disp draw clean test2		; draw clean function test2 (color2)
	disp draw clean test3		; draw clean function test3 (clean to 0)
