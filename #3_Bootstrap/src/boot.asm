;****************;
; BOOTSTRAPIN OS ;
;****************;
;****************************************
;       Basic Bootstrap OS
;       - Created by Tyler Higley
;	
;	Switches from 16 bit to 32 bit mode
; Under construction...
;
;****************************************

[org 0x7c00]
jmp 0x0000:start
start:
	mov [BOOT_DRIVE], dl		;store boot drive for later
	
	call clearscreen

	mov si, MSG_REAL
	call println

	call load_jumps
	
        jmp $				;we never get here


;INCLUDE FILES
%include 'src/methods/printMethods.asm'
%include 'src/methods/clearscreen.asm'
%include 'src/methods/disk_load.asm'

[bits 16]
load_jumps:
	mov si, MSG_KERN
	call print

	mov bx, 0x0500
	mov dh, 5
	mov dl, [BOOT_DRIVE]
	call disk_load

;	mov bx, 0x1000
;	mov dh, 5
;	mov dl, [BOOT_DRIVE+512]

	jmp 0x0500

	ret

;DATA
BOOT_DRIVE	db 0
MSG_REAL	db "Started in 16-bit Real Mode", 0
MSG_PROT	db "Successfully landed in 32-bit Protected Mode", 0
MSG_KERN	db "Loading kernel into memory...", 0

times 510 - ($-$$) db 0
dw 0xAA55
