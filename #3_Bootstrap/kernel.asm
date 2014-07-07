[org 0x1000]
jmp 0x0000:main

msg db 'Hello World', 0
%include "methods/printMethods.asm"

main:
	mov si, msg
	call println
	
	call switch_to_pm
loops:
	jmp loops

%include 'gdt.asm'
%include 'methods/pmPrint.asm'
%include 'switch.asm'

MSG_PROT        db "Successfully landed in 32-bit Protected Mode", 0

[bits 32]
BEGIN_PM:

      	mov ebx, MSG_PROT
       	mov ax, 5
       	call print_string_pm
	jmp $

