;****************;
; Interactive OS ;
;****************;
;****************************************
;       Slightly Interactive OS
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
	; CLEAR SCREEN
	xor ah, ah
	mov al, 0x03
	int 0x10

	; PRINT FIRST STRING
	mov ah, 0x0e
	mov si, msg
	call println
	
	; WAIT FOR KEY THEN PRINT 
	; SECOND STRING
	xor ah, ah
	int 0x16
	mov si, msg2
	call println

	; PRINT INPUT FOREVER
repeat:
	call printin
	jmp repeat


; PRINT STRING
%include "methods/println.asm"

; PRINT INPUT
%include "methods/printin.asm"

; DATA
msg db 'Welcome to a typing OS!', 0x0A,0x0D, 0
msg2 db 'Type Away!', 0x0A, 0x0D, 0

times 510 - ($-$$) db 0

db 0x55, 0xAA
