;****************;
; BOOTSTRAPIN OS ;
;****************;
;****************************************
;       Basic Bootstrap OS
;       - Created by Tyler Higley
;
; This version prints a string, waits
; for input, prints another string, then
; echos all further input. This file also
; uses code from other files.
;
;****************************************


org 0x7c00

start:
	mov ax, 1000h
	mov es, ax
	mov bx, 0

	mov ah, 2
	mov al, 5
	mov ch, 0
	mov cl, 2
	mov dh, 0
	mov dl, 0
	int 13h
	mov si, msg
	call println
	jmp 1000h:0000

;INCLUDE FILES
%include 'methods/printMethods.asm'

;DATA
msg	db 'Hello'
msg2	db 'World'
msg3	db '!'

times 510 - ($-$$) db 0
dw 0AA55h

mov si, msg2
call println

mov si, msg3
call println

jmp $
