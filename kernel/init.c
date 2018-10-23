/*
 * file name: init.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Fri 19 Oct 2018 10:06:24 AM CST
 */

#include <include/ninix/kstring.h>
#include <include/ninix/console.h>
#include <include/ninix/kstdio.h>
#include <include/ninix/interrupt.h>
#include <include/ninix/rtc_clock.h>

void kpanic(const char *msg);
void i386_init(void)
{
	extern char edata[], end[];

	memset(edata, 0, end - edata);

	console_init();
#if 0
	/* Shouldn't got here */
	kpanic("Just a debug information, disabled it!\n");
#endif 
	i386_find_memory();
}

void kpanic(const char *msg)
{
	/* Use kprintf or kputs implements */

	cli();
	kputs(KERN_WARNING, msg);
died:
	while (1); 
}
