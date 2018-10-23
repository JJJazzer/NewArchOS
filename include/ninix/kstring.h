/*
 * file name: string.h
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Tue 16 Oct 2018 08:01:11 PM CST
 */

#ifndef _K_STRING_H
#define _K_STRING_H

#include "ktypes.h"

int 	strlen(const char *str);
char   *strcpy(char *dest, const char *src);
char   *strcat(char *dest, const char *src);
int 	strcmp(const char *str1, const char *str2);

void   *memset(void *dest, int c, size_t len);
void   *memcpy(void *dest, const void *src, size_t len);

#endif
