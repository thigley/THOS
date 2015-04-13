;;kernel.asm
bits 32						;32 bit protected mode
section .text
	;multiboot spec
	align 4
	dd 0x1BADB002				;magic
	dd 0x00					;flags
	dd -(0x1BADB002 + 0x00) 		;checksum. m+f+c = 0

global start
extern kmain					;kmain defined in c file

start:
	cli					;block interrupts
	call kmain
	hlt					;halt CPU
