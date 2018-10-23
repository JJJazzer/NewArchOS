/*
 * file name: entry.S
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Thu 18 Oct 2018 03:59:09 PM CST
 */
#include <include/ninix/mmu.h>

#define RELOCATE(x)		((x) - KERNEL_BASE)

.text
.globl _start
_start = RELOCATE(entry) 

.globl entry
entry:
/* We should setting page table at now */
	movl 	$(RELOCATE(entry_pgdir)), %eax
	movl 	%eax, %cr3
	movl 	%cr0, %eax 
	orl 	$(PE_FLAG_ON|PG_FLAG_ON|WP_FLAG_ON), %eax
	movl 	%eax, %cr0 
	
/* We success trun on the paging, now we jump on KERNBASE. */
	
	movl 	$relocated, %eax
	jmp 	*%eax
relocated:
	movl 	$0x0, %ebp
	movl 	$(bootstacktop), %esp
	call 	i386_init
died:
	jmp 	died
.data 
	.p2align PGSHIFT
	.globl   boot_stack
boot_stack:
	.space   KERNEL_STACK

.globl bootstacktop
bootstacktop: 
