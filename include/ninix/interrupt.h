/*
 * file name: include/interrupt.h
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Sun 21 Oct 2018 05:47:23 PM CST
 */

#ifndef _INTERRUPT_H
#define _INTERRUPT_H

#define cli() 	__asm__ volatile ("\n\tcli");
#endif
