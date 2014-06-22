;****************;
; BOOTSTRAPIN OS ;
;****************;
;****************************************
;       Basic Bootstrap OS
;       - Created by Tyler Higley
;
; Under construction...
;
;****************************************


[org 0x7c00]

mov bp, 0x9000
mov sp, bp

mov si, MSG_REAL
call println

call switch_to_pm

jmp $

;start:
;	mov ax, 1000h
;	mov es, ax
;	mov bx, 0
;
;	mov ah, 2
;	mov al, 5
;	mov ch, 0
;	mov cl, 2
;	mov dh, 0
;	mov dl, 0
;	int 13h
;	mov si, msg
;	call println
;	jmp 1000h:0000

;INCLUDE FILES
%include 'methods/printMethods.asm'
%include 'gdt.asm'
%include 'methods/pmPrint.asm'
%include 'switch.asm'

[bits 32]
BEGIN_PM:
	mov ebx, MSG_PROT
	call print_string_pm
	jmp $

;DATA
MSG_REAL	db "Started in 16-bit Real Mode", 0
MSG_PROT	db "Successfully landed in 32-bit Protected Mode", 0

times 510 - ($-$$) db 0
dw 0xAA55
