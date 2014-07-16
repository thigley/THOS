[org 0x0500]
jmp 0x0000:load

load:
	call hide_cursor
	call switch_to_pm
	jmp $

;%include 'src/asm_files/print.asm'
%include 'src/asm_files/gdt.asm'
;%include 'src/asm_files/pmPrint.asm'
%include 'src/asm_files/switch.asm'
%include 'src/asm_files/hide_cursor.asm'

;MSG_PROT        db "32-bit Protected Mode", 0

[bits 32]
BEGIN_PM:

;      	mov ebx, MSG_PROT
;       	mov ax, 9
;       	call print_string_pm

	jmp kernelStart
times 512 - ($-$$) db 0
kernelStart:
