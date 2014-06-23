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
;KERNEL_OFFSET equ 0x1000	;memoy offset of kernel

;mov [BOOT_DRIVE], dl		;store boot drive for later

mov bp, 0x9000 ;set the stack
mov sp, bp

;clear screen
call clearscreen

;print message in real mode
mov si, MSG_REAL
call println

;call load_kernel

;switch to protected mode
call switch_to_pm

jmp $

;INCLUDE FILES
%include 'methods/printMethods.asm'
;%include 'methods/disk_load.asm'
%include 'gdt.asm'
%include 'methods/pmPrint.asm'
%include 'switch.asm'

;[bits 16]
;load_kernel:
;	mov bx, MSG_KERN
;	call println
;
;	mov bx, KERNEL_OFFSET
;	mov dh, 15
;	mov dl, [BOOT_DRIVE]
;	call disk_load
;	
;	ret

[bits 32]
BEGIN_PM:

	mov ebx, MSG_PROT
	call print_string_pm

;	call KERNEL_OFFSET
	jmp $

;DATA
BOOT_DRIVE	db 0
MSG_REAL	db "Started in 16-bit Real Mode", 0
MSG_PROT	db "Successfully landed in 32-bit Protected Mode", 0
;MSG_KERN	db "Loadint kernel into memory...", 0

times 510 - ($-$$) db 0
dw 0xAA55
