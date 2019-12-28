
#define REG_BASE                0x9c000000
#define RGST_BASE               REG_BASE
#define STACK_SRAM              (0x100000)   /* down-grow stack */

#define RF_GRP(_grp, _reg) ((((_grp) * 32 + (_reg)) * 4) + REG_BASE)

// I141 (A Chip)
#define REG_BASE_A				0x9ec00000
#define RF_GRP_A(_grp, _reg) ((((_grp) * 32 + (_reg)) * 4) + REG_BASE_A)

#define RF_MASK_V(_mask, _val)       (((_mask) << 16) | (_val))
#define RF_MASK_V_SET(_mask)         (((_mask) << 16) | (_mask))
#define RF_MASK_V_CLR(_mask)         (((_mask) << 16) | 0)

//FIXME
//#define PLATFORM_3502  // enable to build 3502-compatible version
