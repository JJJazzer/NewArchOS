/*
 * file name: string.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Tue 16 Oct 2018 08:07:17 PM CST
 */

#include <include/ninix/kstring.h>

int strlen(const char *str)
{
	int cnt = 0;
	while (*str++ != '\0') 
		cnt++;
	return cnt;
}
char *strcpy(char *dest, const char *src)
{
	char *ret = dest; 
	while (*src != '\0') {
		*dest++ = *src++;
	}
	return ret;
}
char *strcat(char *dest, const char *src)
{
	int dest_len = strlen(dest);
	(void) strcpy(dest + dest_len, src);
	return dest;
}
int strcmp(const char *str1, const char *str2)
{ 
	int str1_len = strlen(str1);
	int str2_len = strlen(str2);
	int len = str1_len - str2_len;
	if (len < 0)
		return -1;
	else if (len > 0)
		return 1;
	else {
		while (*str1 != '\0') {
			if (*str1 > *str2)
				return 1;
			else if (*str1 < *str2)
				return -1;
			str2++;
			str1++;
		}

	}
	return 0;
}

void *memset(void *src, int c, size_t n)
{
	char *p;
	int m;
	p = src;
	while (n > 0) {
		*p = c;
		p++;
		n--;
	}
	return src;
}
void *memcpy(void *dest, const void *src, size_t n)
{
	char *p_dst = (char*) dest;
	char *p_src = (char*) src;
	while (n > 0) {
		*p_dst = *p_src;
		p_dst++;
		p_src++;
	}
	return dest;
}
