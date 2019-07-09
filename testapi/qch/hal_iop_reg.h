/********************************************************
 *    ____               __
 *   / __/_ _____  ___  / /_ _____
 *  _\ \/ // / _ \/ _ \/ / // (_-<
 * /___/\_,_/_//_/ .__/_/\_,_/___/
 *              /_/
 * Sunplus Technology Co., Ltd.19, Innovation First Road,
 * Science-Based Industrial Park, Hsin-Chu, Taiwan, R.O.C.
 * ------------------------------------------------------
 * Description  : iop register file.
 * Create Date  : 2018-07-05 18:59:17 auto generated.
 */

#ifndef __REG_IOP_H__
#define __REG_IOP_H__


typedef struct reg_iop_s
{
    union {
        struct {
            u32 reset_ctrl                :1;                  /* [RW]:<0x1> */
            u32 is_iop_stall              :1;                  /* [RW]:<0x0> */
            u32 break_point_en            :1;                  /* [RW]:<0x0> */
            u32 is_iop_stop_at_break_point:1;                  /* [RW]:<0x0> */
            u32 nmif                      :1;                  /* [RW]:<0x1> */
            u32 nmir                      :1;                  /* [RW]:<0x0> */
            u32 risc_int_a                :1;                  /* [RW]:<0x0> */
            u32 risc_int_b                :1;                 /* [W1C]:<0x0> */
            u32 sstl_rst_en_0             :1;                  /* [RW]:<0x0> */
            u32 watch_dog_rst_en          :1;                  /* [RW]:<0x0> */
            u32 sstl_ret_en_1             :1;                  /* [RW]:<0x0> */
            u32 fast_resume_mode          :1;                  /* [RW]:<0x0> */
            u32 :1;
            u32 en_clr_valid              :1;                  /* [RW]:<0x1> */
            u32 :1;
            u32 dis_sys_rst_iop           :1;                  /* [RW]:<0x0> */
            u32 :16;
        } bits;
        u32 reg_v;
    } iop_ctrl;                                              /* group 8.0    */

    u32 reserved_0;
    u32 break_address;                                       /* group 8.2    */
    u32 reg_sel;                                             /* group 8.3    */
    u32 reg_out;                                             /* group 8.4    */
    u32 reserved_1;
    u32 resume_pc_l;                                         /* group 8.6    */
    u32 resume_pc_h;                                         /* group 8.7    */
    u32 iop_data[12];
    u32 base_addr_l;                                         /* group 8.20   */
    u32 base_addr_h;                                         /* group 8.21   */
    union {
        struct {
            u32 mem_risc_en:1;                                 /* [RW]:<0x0> */
            u32 mem_iop_en :1;                                 /* [RO]:<0x0> */
            u32 :30;
        } bits;
        u32 reg_v;
    } mem_bridge_ctrl;                                       /* group 8.22   */

    u32 remap_addr_l;                                        /* group 8.23   */
    u32 remap_addr_h;                                        /* group 8.24   */
    u32 direct_addr;                                         /* group 8.25   */
    u32 reserved_2[6];

} reg_iop_t;

#define IOP_REGISTER_OFFSET (0x9C000000 + 0x400)
#define iop_regs ((volatile reg_iop_t *) IOP_REGISTER_OFFSET)

#endif // end of #ifndef __REG_IOP_H__