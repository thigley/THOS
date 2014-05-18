;****************************************
;	Hello World Operating System
;	- Basic Bootloader
;	- Created by Tyler Higley
;	- brokenthorn.com Tutorial
;
; This version simply loads and prints
; a message.
;****************************************

org	0x7c00				; The BIOS loads at location 0x7c00.
					; This instruction insures all addresses will be relative to 0x7c00

bits	16				; Must start in 16 bit mode

Start:
	mov bx, LoadMSG
	call printString

	cli				; Clears interupts
	hlt				; Halts the system

LoadMSG:
	db 'Hello Operating System', 0

printString:
	pusha
	mov ah, 0x0e

	loop:
	mov al, [bx]
	cmp al, 0
	je end

	int 0x10
	inc bx
	jmp loop
	end:

	popa
	ret

times 510 - ($-$$) db 0			; Pad extra space with zeros
					; $ - current address, $$ - address of first instruction

dw 0xAA55				; Boot Signature
