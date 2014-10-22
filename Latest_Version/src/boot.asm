;****************;
; Kernel OS ;
;****************;
;****************************************
;       Basic Kernel OS
;       - Created by Tyler Higley
;	
;	Slim down assembly and add 
;	functionality to C Kernel
;
;****************************************

[org 0x7c00]
jmp 0x0000:start
start:
	mov [BOOT_DRIVE], dl		;store boot drive for later

	call load_jumps
	
        jmp $				;we never get here


;INCLUDE FILES
%include 'src/asm_files/print.asm'
%include 'src/asm_files/disk_load.asm'

[bits 16]
load_jumps:

	mov bx, 0x0500
	mov dh, 15
	mov dl, [BOOT_DRIVE]
	call disk_load

	jmp 0x0500
	ret

;DATA
BOOT_DRIVE	db 0
times 510 - ($-$$) db 0
dw 0xAA55
