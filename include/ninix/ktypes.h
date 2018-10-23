/*
 * file name: types.h
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Thu 18 Oct 2018 03:27:32 PM CST
 */

#ifndef _K_TYPES_H
#define _K_TYPES_H

typedef unsigned char 	uint8_t;
typedef unsigned short 	uint16_t;
typedef unsigned int 	uint32_t;
typedef _Bool		bool;
typedef char 		int8_t;
typedef short 		int16_t;
typedef int 		int32_t;

typedef uint32_t 	size_t;
typedef int32_t 	ssize_t;

typedef uint8_t 	u8;
typedef uint16_t 	u16;
typedef uint32_t 	u32;

typedef u8* 		u8ptr;
typedef u16*		u16ptr;
typedef u32* 		u32ptr;

typedef uint32_t 	uintptr_t;

/* Elf type */
typedef uint16_t 	Elf32_Half;
typedef uint32_t 	Elf32_Word;
typedef Elf32_Word 	Elf32_Addr;
typedef Elf32_Addr 	Elf32_Off;

/* Page table or directory types */
typedef uint32_t 	pte_t;
typedef uint32_t 	pde_t;
#ifndef TRUE 
#define TRUE 		1
#endif

#ifndef FALSE 
#define FALSE 		0
#endif 

#ifndef NULL 
#define NULL 		((void*)0)
#endif 

#ifndef ARR_SIZE
#define ARR_SIZE(arr) 	(sizeof(arr) / sizeof(arr[0]))
#define length(arr) 	ARR_SIZE(arr)
#endif 

#define MAX(a, b)		\
({				\
	typeof(a) __a = (a); 	\
	typeof(b) __b = (b);	\
	__a >= __b ? __a : __b; \
})

#define MIN(a, b) 		\
({				\
	typeof(a) __a = (a);	\
	typeof(b) __b = (b);	\
	__a <= __b ? __a : __b;	\
})

#endif
