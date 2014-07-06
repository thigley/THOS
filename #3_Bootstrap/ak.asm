[bits 32]
kernel:
	mov ebx, HELLOK
	mov ax, 4
	call print_string_pm

	jmp $

HELLOK db "Hello from the asm Kernel!", 0
%include 'methods/pmPrint.asm'
