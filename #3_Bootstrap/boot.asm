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

	; TEST PRINTHEX
	mov dx, 0x1fb6
	call printhex
	
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


; PRINT Methods
%include "methods/printMethods.asm"

; DATA
msg db 'Welcome to a typing OS!', 0
msg2 db 'Type Away!', 0

times 510 - ($-$$) db 0

db 0x55, 0xAA
