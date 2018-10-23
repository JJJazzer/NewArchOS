/*
 * file name: lib/printf.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Sat 20 Oct 2018 09:49:22 AM CST
 */

#include <include/usr/stdio.h>

#define putchar(c) 	cga_putc(c)

inline int puts(const char *s)
{
	int ret = 0; 
	while (*s != '\0') {
		putchar(*s);
		s++;
		ret++;
	}
	return ret; 	/* return strlen(puts) */
}

int printf(const char *fmt, ...)
{
	
}
