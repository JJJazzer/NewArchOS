#######################################################################
# file name: Makefile
# author   : Yu Liu
# email    : <ilhanwnz@hotmail.com>
# time     : Sat 13 Oct 2018 05:09:31 PM CST
#######################################################################

CC     = gcc  
CFLAGS += -O1 -pipe
CFLAGS += -nostdinc
CFLAGS += -fno-builtin
CFLAGS += -MD -fno-tree-ch 
CFLAGS += -I. -gstabs 
CFLAGS += -fno-omit-frame-pointer -fno-pic
CFLAGS += -static -Wall -Wno-format -Wno-unused -Werror -m32 -c  
VPATH  = include

LDFLAGS += -m elf_i386 

OBJS   = Object/boot.o Object/setup.o kernel/lib/*.o kernel/lib/*.d

GDB     := gdb 
GDBOPTS  =
GDBPORT := 26000
QEMU := qemu-system-i386
QEMUOPTS = -drive file=Image/kernel.img,index=0,media=disk,format=raw -m 4G
QEMUDBG += -serial mon:stdio -gdb tcp::$(GDBPORT) -S -D Qemu.Log

all: kernel.img

kern: Image/boot_bin Image/kernel 
include boot/Makebranch
include kernel/Makebranch

kernel.img: kern
	@dd if=/dev/zero of=Image/kernel.img count=10000
	@dd if=Image/boot_bin of=Image/kernel.img conv=notrunc
	@dd if=Image/kernel of=Image/kernel.img seek=1 conv=notrunc
qemu: Image/kernel.img  
	@echo "*************************************"
	@echo "*           OS is running!          *"
	@echo "*************************************"
	$(QEMU) $(QEMUOPTS) 
qemu-gdb: Image/kernel.img 
	@echo "*************************************"
	@echo "* 	   Debug Start             *"
	@echo "*************************************"
	@echo "\n\n"
	$(QEMU) $(QEMUOPTS) $(QEMUDBG)
gdb: Image/kernel
	$(GDB) $(GDBOPTS) 
clean:
	rm -rf $(OBJS) Image Object
