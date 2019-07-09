/********************************************************
 * Copyright (c) 2017 by Sunplus Technology Co., Ltd.
 *    ____               __
 *   / __/_ _____  ___  / /_ _____
 *  _\ \/ // / _ \/ _ \/ / // (_-<
 * /___/\_,_/_//_/ .__/_/\_,_/___/
 *              /_/
 * Sunplus Technology Co. 19, Innovation First Road,
 * Science-Based Industrial Park, Hsin-Chu, Taiwan, R.O.C.
 * ------------------------------------------------------
 *
 * Description :  cpu utilities, porting from ecos kernel
 * ------------------------------------------------------
 * Rev  Date          Author(s)      Status & Comments
 * ======================================================
 * 0.1  2017/09/27    nz.lu          initial version
 */
#include "stdio.h"
#include "cache.h"
#include "var_mmu.h"

#include "mmu.inc"

void mmu_init(void)
{
    unsigned int domain_access_mode = 0xFFFFFFFF;
    unsigned int ttb_base = (unsigned int) &mmu_table;

    // Set the TTB registers
    asm volatile ("mcr p15, 0, %0, c2, c0, 0" : : "r"(ttb_base));
    // Set the Domain Access Control to manager mode
    asm volatile ("mcr p15, 0, %0, c3, c0, 0" : : "r"(domain_access_mode));

    // Enable mmu
    asm volatile ("mrc p15, #0, r0, c1, c0, #0");
    asm volatile ("orr r0, r0, #0x00000001");
    asm volatile ("mcr p15, #0, r0, c1, c0, #0");
}

