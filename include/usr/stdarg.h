/*
 * file name: include/usr/stdarg.h
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Tue 23 Oct 2018 07:01:12 PM CST
 */

#ifndef _STDARG_H
#define _STDARG_H

typedef __builtin_va_list 	va_list;
#define va_start(ap, last)	__builtin_va_start(ap, last)
#define va_arg(ap, type) 	__builtin_va_arg(ap, type)
#define va_end(ap) 		__builtin_va_end(ap)

#endif
