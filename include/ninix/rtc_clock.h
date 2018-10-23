/*
 * file name: clock.h
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Tue 23 Oct 2018 10:18:58 AM CST
 */

#ifndef _CLOCK_H
#define _CLOCK_H

#include "ktypes.h"

#define CMOS_RTC 	0x70

enum {
	NVRAM_BASELSB = 0x15,
	NVRAM_BASEMSB,
	NVRAM_EXTLSB,
	NVRAM_EXTMSB,
	NVRAM_EXT16MLSB = 0x34,
	NVRAM_EXT16MMSB,
};

void i386_find_memory();

#endif
