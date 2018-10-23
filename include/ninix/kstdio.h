/*
 * file name: kstdio.h
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Tue 23 Oct 2018 12:51:11 PM CST
 */

#ifndef _K_STDIO_H
#define _K_STDIO_H

#include "console.h"

int kputs(enum cons_stat ks, const char *s);
int kprintf(enum cons_stat ks, const char *fmt, ...);
int kputch(int num);
#endif
