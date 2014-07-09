[org 0x0500]
jmp 0x0000:load

load:
	mov si, MSG_JUMP
	call println
	
	call switch_to_pm
loops:
	jmp loops

%include 'src/methods/printMethods.asm'
%include 'src/gdt.asm'
%include 'src/methods/pmPrint.asm'
%include 'src/methods/switch.asm'

MSG_JUMP	db "Successfully jumped to memory", 0
MSG_PROT        db "Successfully landed in 32-bit Protected Mode", 0

[bits 32]
BEGIN_PM:

      	mov ebx, MSG_PROT
       	mov ax, 3
       	call print_string_pm

	jmp kernelStart
times 512 - ($-$$) db 0
kernelStart:
