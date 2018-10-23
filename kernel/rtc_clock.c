/*
 * file name: clock.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Tue 23 Oct 2018 10:21:03 AM CST
 */

#include <include/ninix/rtc_clock.h>
#include <include/ninix/kstdio.h>

unsigned long mc146818_read(unsigned reg)
{
	unsigned long ret; 
	outb(CMOS_RTC, reg);
	ret = (unsigned long) inb(CMOS_RTC + 1);
	return ret;
}

unsigned long mc146818_write(unsigned reg, unsigned data)
{
	int mag = 0x1234;
	outb(CMOS_RTC, reg);
	outb(CMOS_RTC + 1, data);
	return mag;
}
uint32_t nvram_read(int reg) 
{
	uint32_t ret;
	ret = mc146818_read(reg) | (mc146818_read(reg + 1) << 8);
	return ret; 
}
void i386_find_memory(void)
{
	uint32_t base_memory, ext_memory, ext16M_memory, total_memory;
	base_memory = nvram_read(NVRAM_BASELSB);
	ext_memory  = nvram_read(NVRAM_EXTLSB);
	ext16M_memory = nvram_read(NVRAM_EXT16MLSB);
	ext16M_memory *= 64; 	/* 64K block */
	if (ext16M_memory)
		total_memory = 16 * 1024 + ext16M_memory;
	else 
		total_memory = ext_memory ? (1024 + ext_memory) : base_memory;
	kprintf(KERN_INFO, "physical memory: %dK,\n"
			"base memory: %dK, extend memory = %dK.\n"
			,total_memory, base_memory, 
			total_memory - base_memory);	
}

