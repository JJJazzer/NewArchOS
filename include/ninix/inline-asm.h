/*
 * file name: inline-asm.h
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Thu 18 Oct 2018 03:25:17 PM CST
 */

#include "ktypes.h"

static inline 
void outb(int port, uint8_t data)
{
	__asm__ volatile("\n\toutb %1, %w0"
			: 
			: "d"(port), "a"(data));
}
static inline 
void outw(int port, uint16_t data)
{
	__asm__ volatile("\n\toutw %1, %w0"
			:
			: "d"(port), "a"(data));
}
static inline
void outl(int port, uint32_t data)
{
	__asm__ volatile("\n\toutl %1, %w0"
			:
			: "d"(port), "a"(data));
}
static inline
uint8_t inb(int port)
{
	uint8_t data; 
	__asm__ volatile("\n\tinb %w1, %0"
			: "=a"(data) 
			: "d"(port));
	return data;
}
static inline
uint16_t inw(int port)
{
	uint16_t data;
	__asm__ volatile("\n\tinw %w1, %0"
			: "=a"(data)
			: "d"(port));
	return data;
}
static inline
uint32_t inl(int port)
{
	uint32_t data;
	__asm__ volatile("\n\tinl %w1, %0"
			: "=a"(data)
			: "d"(port));
	return data; 
}
static inline 
void insb(int port, void *addr, int cnt)
{
	__asm__ volatile("\n\tcld"
			 "\n\trepne"
			 "\n\tinsb"
			 : "=D"(addr), "=c"(cnt)
			 : "d"(port),  "0"(addr), "1"(cnt)
			 : "memory", "cc");
}
static inline
void insw(int port, void *addr, int cnt)
{
	__asm__ volatile("\n\tcld"
			 "\n\trepne"
			 "\n\tinsw"
			 : "=D"(addr), "=c"(cnt)
			 : "d"(port), "0"(addr), "1"(cnt)
			 : "memory", "cc");
}
static inline
void insl(int port, void *addr, int cnt)
{
	__asm__ volatile("\n\tcld"
			 "\n\trepne"
			 "\n\tinsl"
			 : "=D"(addr), "=c"(cnt)
			 : "d"(port), "0"(addr), "1"(cnt)
			 : "memory", "cc");
}
