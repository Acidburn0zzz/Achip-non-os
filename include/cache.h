#ifndef CYGONCE_HAL_CACHE_H
#define CYGONCE_HAL_CACHE_H

//=============================================================================
//
//      hal_cache.h
//
//      HAL cache control API
//
//=============================================================================
//####ECOSGPLCOPYRIGHTBEGIN####
// -------------------------------------------
// This file is part of eCos, the Embedded Configurable Operating System.
// Copyright (C) 1998, 1999, 2000, 2001, 2002 Red Hat, Inc.
//
// eCos is free software; you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published by the Free
// Software Foundation; either version 2 or (at your option) any later version.
//
// eCos is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
// for more details.
//
// You should have received a copy of the GNU General Public License along
// with eCos; if not, write to the Free Software Foundation, Inc.,
// 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.
//
// As a special exception, if other files instantiate templates or use macros
// or inline functions from this file, or you compile this file and link it
// with other works to produce a work based on this file, this file does not
// by itself cause the resulting work to be covered by the GNU General Public
// License. However the source code for this file must still be made available
// in accordance with section (3) of the GNU General Public License.
//
// This exception does not invalidate any other reasons why a work based on
// this file might be covered by the GNU General Public License.
//
// Alternative licenses for eCos may be arranged by contacting Red Hat, Inc.
// at http://sources.redhat.com/ecos/ecos-license/
// -------------------------------------------
//####ECOSGPLCOPYRIGHTEND####
//=============================================================================
//#####DESCRIPTIONBEGIN####
//
// Author(s):   gthomas
// Contributors:hmt, jskov
//              Travis C. Furrer <furrer@mit.edu>
// Date:        2000-05-08
// Purpose:     Cache control API
// Description: The macros defined here provide the HAL APIs for handling
//              cache control operations.
// Usage:
//              #include <cyg/hal/hal_cache.h>
//              ...
//
//
//####DESCRIPTIONEND####
//
//=============================================================================
// #include <cyg/infra/cyg_type.h>
// #include <cyg/hal/hal_mmu.h>
// #include <cyg/hal/hal_8388.h>


#define CYG_MACRO_START do {
#define CYG_MACRO_END   } while (0)



//-----------------------------------------------------------------------------
// Cache dimensions
// mrc     p15, 0, r7, c0, c0, 1 @ cache type
// R07=01dd20d2
# define HAL_ICACHE_SIZE                 0x4000 // 8388 16KB
//# define HAL_ICACHE_SIZE               0x1000 // icp 4KB
# define HAL_ICACHE_LINE_SIZE            32
# define HAL_ICACHE_WAYS                 4
# define HAL_ICACHE_SETS (HAL_ICACHE_SIZE/(HAL_ICACHE_LINE_SIZE*HAL_ICACHE_WAYS))

# define HAL_DCACHE_SIZE                 0x4000 // 8388 16KB
//# define HAL_DCACHE_SIZE                 0 //0x10000 // icp 64KB
# define HAL_DCACHE_LINE_SIZE            32
# define HAL_DCACHE_WAYS                 4
# define HAL_DCACHE_SETS (HAL_DCACHE_SIZE/(HAL_DCACHE_LINE_SIZE*HAL_DCACHE_WAYS))

# define HAL_WRITE_BUFFER                64


// FIXME: much of the code below should make better use of
// the definitions from hal_mmu.h

//-----------------------------------------------------------------------------
// Global control of Instruction cache
// FIXME: disable/enable instruction streaming?
// Enable the instruction cache
#define HAL_ICACHE_ENABLE()                                             \
CYG_MACRO_START                                                         \
    asm volatile (                                                      \
        "mrc  p15,0,r1,c1,c0,0;"                                        \
        "orr  r1,r1,#0x1000;" /* [12] 1 = ICache enabled */             \
        "mcr  p15,0,r1,c1,c0,0"                                         \
        :                                                               \
        :                                                               \
        : "r1" /* Clobber list */                                       \
        );                                                              \
CYG_MACRO_END

// Disable the instruction cache (and invalidate it, required semanitcs)
#define HAL_ICACHE_DISABLE()                                            \
CYG_MACRO_START                                                         \
    asm volatile (                                                      \
        "mrc    p15,0,r1,c1,c0,0;"                                      \
        "bic    r1,r1,#0x1000;" /* disable ICache (but not MMU, etc) */ \
        "mcr    p15,0,r1,c1,c0,0;"                                      \
        "mov    r1,#0;"                                                 \
        "mcr    p15,0,r1,c7,c5,0;"  /* flush ICache */                  \
        "nop;" /* next few instructions may be via cache    */          \
        "nop;"                                                          \
        "nop;"                                                          \
        "nop;"                                                          \
        "nop;"                                                          \
        "nop"                                                           \
        :                                                               \
        :                                                               \
        : "r1" /* Clobber list */                                       \
        );                                                              \
CYG_MACRO_END

// Query the state of the instruction cache
#define HAL_ICACHE_IS_ENABLED(_state_)                                   \
CYG_MACRO_START                                                          \
    register cyg_uint32 reg;                                             \
    asm volatile ("mrc  p15,0,%0,c1,c0,0"                                \
                  : "=r"(reg)                                            \
                  :                                                      \
        );                                                               \
    (_state_) = (0 != (0x1000 & reg)); /* Bit 12 is ICache enable */     \
CYG_MACRO_END

// Invalidate the entire cache
#define HAL_ICACHE_INVALIDATE_ALL()                                     \
CYG_MACRO_START                                                         \
    /* this macro can discard dirty cache lines (N/A for ICache) */     \
    asm volatile (                                                      \
        "mov    r1,#0;"                                                 \
        "mcr    p15,0,r1,c7,c5,0;"  /* flush ICache */                  \
        "mcr    p15,0,r1,c8,c5,0;"  /* flush ITLB only */               \
        "nop;" /* next few instructions may be via cache    */          \
        "nop;"                                                          \
        "nop;"                                                          \
        "nop;"                                                          \
        "nop;"                                                          \
        "nop;"                                                          \
        :                                                               \
        :                                                               \
        : "r1" /* Clobber list */                                       \
        );                                                              \
CYG_MACRO_END

// Synchronize the contents of the cache with memory.
// (which includes flushing out pending writes)
#define HAL_ICACHE_SYNC()                                       \
CYG_MACRO_START                                                 \
    HAL_DCACHE_SYNC(); /* ensure data gets to RAM */            \
    HAL_ICACHE_INVALIDATE_ALL(); /* forget all we know */       \
CYG_MACRO_END

// Enable the data cache
#define HAL_DCACHE_ENABLE()                                             \
CYG_MACRO_START                                                         \
    asm volatile (                                                      \
        "mrc  p15,0,r1,c1,c0,0;"                                        \
        "orr  r1,r1,#0x000F;" /* enable DCache (also ensures    */      \
                              /* the MMU, alignment faults, and */      \
                              /* write buffer are enabled)      */      \
        "mcr  p15,0,r1,c1,c0,0"                                         \
        :                                                               \
        :                                                               \
        : "r1" /* Clobber list */                                       \
        );                                                              \
CYG_MACRO_END

/////////////////////////////////////////////////////////////////
// Disable the data cache (and invalidate it, required semanitcs)
#define HAL_DCACHE_DISABLE()                                            \
CYG_MACRO_START                                                         \
    asm volatile (                                                      \
        "mrc  p15,0,r1,c1,c0,0;"                                        \
        "bic  r1,r1,#0x000C;" /* disable DCache AND write buffer  */    \
                              /* but not MMU and alignment faults */    \
        "mcr  p15,0,r1,c1,c0,0;"                                        \
        "mov    r1,#0;"                                                 \
        "mcr  p15,0,r1,c7,c6,0" /* clear data cache */                  \
        :                                                               \
        :                                                               \
        : "r1" /* Clobber list */                                       \
        );                                                              \
CYG_MACRO_END

// Query the state of the data cache
#define HAL_DCACHE_IS_ENABLED(_state_)                                   \
CYG_MACRO_START                                                          \
    register int reg;                                                    \
    asm volatile ("mrc  p15,0,%0,c1,c0,0;"                               \
                  : "=r"(reg)                                            \
                  :                                                      \
        );                                                               \
    (_state_) = (0 != (4 & reg)); /* Bit 2 is DCache enable */           \
CYG_MACRO_END

/////////////////////////////////////////////////////////////////
// Flush the entire dcache (and then both TLBs, just in case)
#define HAL_DCACHE_INVALIDATE_ALL()                                     \
CYG_MACRO_START  /* this macro can discard dirty cache lines. */        \
    asm volatile (                                                      \
  "mov    r0,#0;"                                                 \
        "mcr    p15,0,r0,c7,c6,0;" /* flush d-cache */                  \
        "mcr    p15,0,r0,c8,c7,0;" /* flush i+d-TLBs */                 \
        :                                                               \
        :                                                               \
        : "r0","memory" /* clobber list */);                            \
CYG_MACRO_END

// Synchronize the contents of the cache with memory.
// 8388
#define HAL_DCACHE_SYNC()                                               \
CYG_MACRO_START                                                         \
    asm volatile (                                                      \
        "1: "                   /* clean & invalidate D index */ \
        "mrc    p15, 0, r15, c7, c14, 3;" \
        "bne    1b;" \
        "mcr    p15,0,r0,c7,c10,4;" /* drain the write buffer */        \
        : \
        : \
        : "r0" /* Clobber list */                                       \
        );                                                              \
CYG_MACRO_END


#define HAL_DCACHE_WRITETHRU_MODE       0
#define HAL_DCACHE_WRITEBACK_MODE       1

// Get the current writeback mode - or only writeback mode if fixed
#define HAL_DCACHE_QUERY_WRITE_MODE( _mode_ ) CYG_MACRO_START           \
    _mode_ = HAL_DCACHE_WRITEBACK_MODE;                                 \
CYG_MACRO_END

#define HAL_DCACHE_FLUSH( _base_ , _size_ )     \
CYG_MACRO_START                                 \
    HAL_DCACHE_STORE( _base_ , _size_ );        \
    HAL_DCACHE_INVALIDATE( _base_ , _size_ );   \
CYG_MACRO_END

// Invalidate cache lines in the given range without writing to memory.
#define HAL_DCACHE_INVALIDATE( _base_ , _size_ )                        \
CYG_MACRO_START                                                         \
    register int addr, enda;                                            \
    for ( addr = (~(HAL_DCACHE_LINE_SIZE - 1)) & (int)(_base_),         \
              enda = (int)(_base_) + (_size_);                          \
          addr < enda ;                                                 \
          addr += HAL_DCACHE_LINE_SIZE )                                \
    {                                                                   \
        asm volatile (                                                  \
                      "mcr  p15,0,%0,c7,c6,1;" /* flush entry away */   \
                      :                                                 \
                      : "r"(addr)                                       \
                      : "memory"                                        \
            );                                                          \
    }                                                                   \
CYG_MACRO_END

// Write dirty cache lines to memory for the given address range.
#define HAL_DCACHE_STORE( _base_ , _size_ )                             \
CYG_MACRO_START                                                         \
    register int addr, enda;                                            \
    for ( addr = (~(HAL_DCACHE_LINE_SIZE - 1)) & (int)(_base_),         \
              enda = (int)(_base_) + (_size_);                          \
          addr < enda ;                                                 \
          addr += HAL_DCACHE_LINE_SIZE )                                \
    {                                                                   \
        asm volatile ("mcr  p15,0,%0,c7,c10,1;" /* push entry to RAM */ \
                      :                                                 \
                      : "r"(addr)                                       \
                      : "memory"                                        \
            );                                                          \
    }                                                                   \
    /* and also drain the write buffer */                               \
    asm volatile (                                                      \
        "mov    r1,#0;"                                                 \
        "mcr    p15,0,r1,c7,c10,4;"                                     \
        :                                                               \
        :                                                               \
        : "r1", "memory" /* Clobber list */                             \
    );                                                                  \
CYG_MACRO_END


//-----------------------------------------------------------------------------
// Cache controls for safely disabling/reenabling caches around execution
// of relocated code.

#define HAL_FLASH_CACHES_OFF(_d_, _i_)          \
    CYG_MACRO_START                             \
    HAL_ICACHE_IS_ENABLED(_i_);                 \
    HAL_DCACHE_IS_ENABLED(_d_);                 \
    HAL_ICACHE_INVALIDATE_ALL();                \
    HAL_ICACHE_DISABLE();                       \
    HAL_DCACHE_SYNC();                          \
    HAL_DCACHE_INVALIDATE_ALL();                \
    HAL_DCACHE_DISABLE();                       \
    CYG_MACRO_END

#define HAL_FLASH_CACHES_ON(_d_, _i_)           \
    CYG_MACRO_START                             \
    if (_d_) HAL_DCACHE_ENABLE();               \
    if (_i_) HAL_ICACHE_ENABLE();               \
    CYG_MACRO_END

//-----------------------------------------------------------------------------
#endif // ifndef CYGONCE_HAL_CACHE_H

