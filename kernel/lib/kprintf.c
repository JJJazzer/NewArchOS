/*
 * file name: lib/printf.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Sat 20 Oct 2018 09:49:22 AM CST
 */

#include <include/ninix/kstdio.h>
#include <include/ninix/console.h>
#include <include/usr/stdarg.h>

#define kputchar(c) 	cga_putc(c)

void select_cons_stat(enum cons_stat cs)
{
	switch (cs) {
	case KERN_DEFAULT:
	case KERN_INFO:
		cga_set_attribute(FONT_DEF);
		break;
	case KERN_WARNING:
		cga_set_attribute(FONT_ERR);
		break;
	default:
		cga_set_attribute(FONT_DEF);
		break; 
	}
}
inline int kputs(enum cons_stat cs, const char *s)
{
	select_cons_stat(cs);
	int ret = 0; 
	while (*s != '\0') {
		kputchar(*s);
		s++;
		ret++;
	}
	return ret; 	/* return strlen(puts) */
}

void print_int(int num)
{
	if (num != 0) { 
		print_int(num / 10);
		kputchar((num % 10) + '0');
	}
}
void print_uint(uint32_t num)
{
	if (num != 0) { 
		print_int(num / 10);
		kputchar((num % 10) + '0');
	}
}
int vprintf(const char *fmt, va_list ap)
{
	unsigned int ch; 
	unsigned int cnt = 0;
	while (1) {
		while ((ch = *fmt++) != '%') {
			if (ch == '\0')
				return cnt;
			kputchar(ch); 
			cnt++;
		}

		switch ((ch = *fmt++)) {
		case 'c':
			kputchar(va_arg(ap, int));
			break;
		case 'd':
			print_int(va_arg(ap, int));
			break;
		case 'u':
			print_uint(va_arg(ap, int));
			break;
		}
	}
}
int kprintf(enum cons_stat cs, const char *fmt, ...)
{
	int cnt;
	select_cons_stat(cs);

	va_list ap;
	va_start(ap, fmt);
	cnt = vprintf(fmt, ap); 
	va_end(ap); 

	return cnt;	
}
