/*
 * file name: boot.S
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Thu 18 Oct 2018 12:44:43 PM CST
 */

.set PE_FLAG_ON, 	0x01

.section .text
.code16
.globl start16
start16:
	xorw 	%ax, %ax
	movw 	%ax, %ds
	movw 	%ax, %es
	movw 	%ax, %ss 

	movb 	$0x00, %bh 
	movb 	$0x03, %ah
	int 	$0x10 
	
	movw 	$0x1301, %ax
	movb 	$0x07, %bl
	movw 	$info_len, %cx
	movw 	$boot_info, %bp
	int 	$0x10
/* Print message end, Next we will enter into protect mode */
	cli 
/* We must enabled A20 address line, before enter into protected mode */
enableA20.1:
	inb 	$0x64, %al
	testb 	$0x2, %al 
	jnz 	enableA20.1
	movb 	$0xd1, %al 
	outb 	%al, $0x64  
enableA20.2:
	inb 	$0x64, %al
	testb 	$0x2, %al
	jnz 	enableA20.1
	movb 	$0xdf, %al 
	outb 	%al, $0x60 		/* 0xdf command word: enable a20 */
/* Enable a20 address line successful, next loading gdtr */
	lgdt 	gdt_48
	movl 	%cr0, %eax
	orl 	$PE_FLAG_ON, %eax
	movl 	%eax, %cr0
	
	ljmp 	$0x08, $start32
.code32 
start32:
	movw 	$0x10, %ax
	movw 	%ax, %ds
	movw 	%ax, %es
	movw 	%ax, %fs
	movw 	%ax, %gs
	movw 	%ax, %ss
	movl 	$start16, %esp 
	call 	setup_kernel 
/* Shouldn't return here */ 
died:
	jmp 	died 	
gdt_48:
	.word   0x17 
	.long 	gdt_desc    
gdt_desc: 
	.word 	0, 0, 0, 0		/* NULL gdt descriptor */
	.quad   0x00cf98000000ffff	/* code gdt descriptor */	
	.quad   0x00cf92000000ffff  	/* data gdt descriptor */
boot_info:
	.string "\r\nBooting the kernel!!\r\n"
	info_len = . - boot_info - 1 
died_info:
	.string "I'm sorry your kernel already died\r\n"
	died_len = . - died_info - 1
