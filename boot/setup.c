/*
 * file name: setup.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Thu 18 Oct 2018 01:53:32 PM CST
 *
 * This code loading the kernel from hard disk to memory.
 * Then jump into kernel entry.
 * Written by Yu Liu. 
 */
#include <include/ninix/inline-asm.h>
#include <include/ninix/elf.h>

#define wait_disk() 				\
{ 		   			        \
	while((inb(0x1f7) & 0xc0) != 0x40);	\
}
#define SECTOR_SIZE 	(512)
#define ELF_HEADER 	(0x10000)
void read_sector(void *phyaddr, uint32_t nsector, uint32_t offset);
void read_segment(uint32_t phyaddr, uint32_t nsector, uint32_t offset);

void setup_kernel()
{
	struct Elf32_Ehdr *elf_header;
	struct Elf32_Phdr *real_kernel_start, *kernel_end;

	/* First, We reading the kernel of elf-i386 format, 
	 * then we handling kernel became raw binary 
	 */
	elf_header = (struct Elf32_Ehdr*) 0x10000;
	read_segment(ELF_HEADER, 8 * SECTOR_SIZE, 0);

	if (elf_header->e_magic != ELF_HEADER_MAGIC)
		goto died;
	real_kernel_start = (struct Elf32_Phdr*) ((uint8_t*)elf_header + elf_header->e_phoff);
	kernel_end = real_kernel_start + elf_header->e_phnum;
	
	while (real_kernel_start < kernel_end) {
		read_segment(real_kernel_start->p_paddr, 
				real_kernel_start->p_memsz,
				real_kernel_start->p_offset);
		real_kernel_start++;
	}
	((void (*)(void)) (elf_header->e_entry))();
/* Shouldn't return here */
died:
	while(1); 
}

void read_segment(uint32_t phyaddr, uint32_t nsize, uint32_t offset)
{
	uint32_t end_phy;
	end_phy = phyaddr + nsize;
	phyaddr &= ~(SECTOR_SIZE - 1);		/* align 512 byte */
	offset = offset / SECTOR_SIZE + 1;		/* start at 1 sector */

	while (phyaddr < end_phy) {
		read_sector((uint8_t*) phyaddr, 1, offset);	
		phyaddr += SECTOR_SIZE;
		offset++;
	}
}

void read_sector(void* phyaddr, uint32_t nsector, uint32_t offset)
{
	wait_disk();
		
	outb(0x1f2, 1);
	outb(0x1f3, offset);
	outb(0x1f4, offset << 8);
	outb(0x1f5, offset << 16);
	outb(0x1f6, (offset << 24) | 0xe0);
	outb(0x1f7, 0x20);	/* read sector with retry */
		
	wait_disk();
	insl(0x1f0, phyaddr, SECTOR_SIZE / 4);
}
