/*
 * file name: elf.h
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Sun 14 Oct 2018 10:38:06 AM CST
 */

#ifndef _ELF_H
#define _ELF_H

#include "ktypes.h"
/* little-endian, "FLE 0x7f"
 * 		  "0x46 0x4c 0x45 0x7f"
 */ 
#define ELF_HEADER_MAGIC 	0x464c457f 	
#define EI_NIDENT 	(16 - sizeof(uint32_t))
/* standard elf struct header */
struct Elf32_Ehdr {
	uint32_t e_magic; 	/* Magic number */
	uint8_t  e_ident[EI_NIDENT]; 
	Elf32_Half e_type;	/* Object file type */
	Elf32_Half e_machine;	/* Specifies architecture */
	Elf32_Word e_version;	/* Object file version */
	Elf32_Addr e_entry;	/* Entry address */
	Elf32_Off e_phoff;	/* Program header table's file offset */
	Elf32_Off e_shoff;	/* Section header table's file offset */
	Elf32_Word e_flags;	/* Processor-specific flags */
	Elf32_Half e_ehsize;	/* ELF header's size */	
	Elf32_Half e_phentsize;	/* Program header table's size(1 entry) */
	Elf32_Half e_phnum;	/* Program header table's number of entry*/
	Elf32_Half e_shentsize;	/* Section header table's size(1 entry) */
	Elf32_Half e_shnum;	/* Section header table's number of entry*/
	Elf32_Half e_shstrndx; 	/* Section header table's index */
};

struct Elf32_Shdr {
	Elf32_Word sh_name;
	Elf32_Word sh_type;
	Elf32_Word sh_flags;
	Elf32_Addr sh_addr;
	Elf32_Off sh_offset;
	Elf32_Word sh_size;
	Elf32_Word sh_link;
	Elf32_Word sh_info;
	Elf32_Word sh_addralign;
	Elf32_Word sh_entsize;
};
struct Elf32_Phdr {
	Elf32_Word p_type;
	Elf32_Off p_offset;
	Elf32_Addr p_vaddr;
	Elf32_Addr p_paddr;
	Elf32_Word p_filesz;
	Elf32_Word p_memsz;
	Elf32_Word p_flags;
	Elf32_Word p_align;
};

#define ELF32_HT_NONE 		0		/* no file type */
#define ELF32_HT_REL 		1		/* relocatable file */
#define ELF32_HT_EXEC 		2		/* executable file */	
#define ELF32_HT_DYN 		3 	 	/* shared object file */
#define ELF32_HT_CORE 		4		/* Core file */
#define ELF32_HT_LOPROC    0xff00		/* Processor-specific */
#define ELF32_HT_HIPROC    0xffff 		/* Processor-specific */

/* sh_name of elf32_section_hdr */
#define ELF32_SHT_UNDEF 	0 

/* sh_type of elf32_section_hdr */
#define ELF32_SHT_NULL 		0
#define ELF32_SHT_PROGBITS 	1
#define ELF32_SHT_SYMTAB 	2
#define ELF32_SHT_STRTAB	3
#define ELF32_SHT_RELA 		4
#define ELF32_SHT_HASH 		5
#define ELF32_SHT_DYNAMIC		6
#define ELF32_SHT_NOTE 		7
#define ELF32_SHT_NOBITS 		8
#define ELF32_SHT_REL 		9
#define ELF32_SHT_SHLIB		10
#define ELF32_SHT_DYNSYM 		11
#define ELF32_SHT_LOPROC 		0x70000000
#define ELF32_SHT_HIPROC 		0x7fffffff
#define ELF32_SHT_LOUSER		0x80000000
#define ELF32_SHT_HIUSER		0xffffffff 

/* p_type of elf32_prog_hdr */
#define ELF32_PT_NULL		0
#define ELF32_PT_LOAD		1

/* p_flag of elf32_prog_hdr */
#define ELF32_PF_X		0x1 
#define ELF32_PF_W 		0x2
#define ELF32_PF_R 		0x4 
#define ELF32_PF_MASKPROC 	0xf0000000

#endif 
