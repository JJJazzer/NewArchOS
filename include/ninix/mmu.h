/*
 * file name: ../include/mmu.h
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Thu 18 Oct 2018 06:06:40 PM CST
 */

#ifndef _MMU_H
#define _MMU_H


#define PGSIZE 		4096	
#define PGSHIFT		12 	
#define KERNEL_STACK 	(PGSIZE * 8)

#define PE_FLAG_ON 	0x00000001
#define MP_FLAG_ON 	0x00000002
#define WP_FLAG_ON 	0x00010000
#define PG_FLAG_ON 	0x80000000

#define KERNEL_BASE 	0xf0000000

#define PDX_SHIFT 	22 

#define PTE_P 		0x001
#define PTE_W 		0x002
#define PTE_U 		0x004

#define PTE_ENTRIES	1024
#define PDE_ENTRIES	1024
#endif
