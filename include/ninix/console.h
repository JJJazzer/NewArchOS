/*
 * file name: ../include/console.h
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Fri 19 Oct 2018 05:03:29 PM CST
 */

#ifndef _CONSOLE_H
#define _CONSOLE_H

#include "ktypes.h" 
#include "inline-asm.h"
#include "mmu.h"

#define CGA_BASE 	0x3d4
#define CGA_BUF 	0xb8000

#define CRT_HEIGHT	25
#define CRT_WIDTH 	80
#define CRT_BUF_SIZE 	(CRT_HEIGHT * CRT_WIDTH)


/* Serial port mode register */
#define COM_PORT	0x3f8		/* Serial port */
#define COM_INT		0x3f9 		/* Interrupt enabled register */
#define COM_FCR 	0x3fa		/* FIFO control register */
#define COM_LCR 	0x3fb 		/* Line control register */
#define COM_MCR 	0x3fc 		/* Modem control register */
#define COM_LSR		0x3fd		/* Line status register */
#define COM_MSR 	0x3fe		/* Modem status register */
#define COM_SCR 	0x3ff 		/* Scratch register */

void console_init(void);
void cga_init(void);
void serial_init(void);

/* little functional ways */
void cga_putc(int c);

#define FONT_ERR 	0x04
#define FONT_DEF 	0x07

void cga_set_attribute(int attr);

enum cons_stat {
	KERN_DEFAULT,
	KERN_WARNING,
	KERN_INFO, 
};
#endif
