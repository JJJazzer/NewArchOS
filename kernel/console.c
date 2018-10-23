/*
 * file name: console.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Fri 19 Oct 2018 04:26:12 PM CST
 */

#include <include/ninix/console.h>

static uint8_t font_attr = 0;
void console_init(void)
{
	cga_init();

}

void cga_set_attribute(int attr)
{
	font_attr = attr;	
}
uint16_t *crt_buf;
uint16_t crt_pos;
unsigned addr_6845;

void cga_init()
{
	volatile uint16_t *cb;
	addr_6845 = CGA_BASE;

	outb(addr_6845, 14);
	crt_pos = inb(addr_6845 + 1) << 8;
	outb(addr_6845, 15);
	crt_pos |= inb(addr_6845 + 1);

	cb = (uint16_t*) (KERNEL_BASE + CGA_BUF);
	crt_buf = (uint16_t*) cb;
}
void cga_putc(int c)
{
	/* Current only used default attribute */

	if (!(font_attr & 0xff))
		c |= 0x0700;
	else
		c |= (font_attr << 8);
	switch (c & 0xff) {
	case '\t':
		crt_pos += 4;
		break;
	case '\r':
	case '\n':
		crt_pos += (CRT_WIDTH - crt_pos % CRT_WIDTH);
		break;
	default:
		crt_buf[crt_pos++] = c;
		break;
	}
	/* Check isn't enter into next page */
	/* reserve */

	/* Update postition */
	outb(addr_6845, 14);
	outb(addr_6845 + 1, crt_pos >> 8);
	outb(addr_6845, 15);
	outb(addr_6845 + 1, crt_pos);
}
