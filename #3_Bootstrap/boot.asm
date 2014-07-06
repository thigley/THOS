<<<<<<< HEAD
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
KERNEL_OFFSET equ 0x1000	;memoy offset of kernel

mov [BOOT_DRIVE], dl		;store boot drive for later
=======
[org 0x7c00]
;[org 0]
;	jmp 07c0h:start
>>>>>>> 9daf38df3d6c86b72b2294bf9ef75bd8276fcdd4

start:
	call clearscreen

	mov si, MSG_REAL
	call println

	call load_kernel
	call switch_to_pm
	
        jmp $

load_kernel:
reset:
        mov ax,0
        mov dl, 0
        int 13h
        jc reset

floppy:
        mov ax, 1000h
        mov es, ax
        mov bx, 0

        mov ah, 2
        mov al, 1
        mov ch, 0
        mov cl, 2
        mov dh, 0
        mov dl, 0
        int 13h

        jc floppy
	
	mov si, MSG_LOAD
	call println
;	jmp 1000h:0000
ret


;INCLUDE FILES
%include 'methods/printMethods.asm'
<<<<<<< HEAD
%include 'methods/clearscreen.asm'
%include 'methods/disk_load.asm'
=======
;%include 'methods/disk_load.asm'
>>>>>>> 9daf38df3d6c86b72b2294bf9ef75bd8276fcdd4
%include 'gdt.asm'
%include 'methods/pmPrint.asm'
%include 'switch.asm'

<<<<<<< HEAD
[bits 16]
load_kernel:
	mov si, MSG_KERN
	call println

	;mov ah, 0
	;int 13h

	;mov ax,0
	;mov es, ax
	mov bx, KERNEL_OFFSET
	mov dh, 15
	mov dl, [BOOT_DRIVE]
	call disk_load
	
	ret
=======
MSG_REAL	db "Started in 16-bit Real Mode", 0
MSG_LOAD	db "Loading Kernel to memory", 0
MSG_PROT	db "Successfully landed in 32-bit Protected Mode", 0
>>>>>>> 9daf38df3d6c86b72b2294bf9ef75bd8276fcdd4

[bits 32]
BEGIN_PM:

	mov ebx, MSG_PROT
	mov ax, 2
	call print_string_pm
	
	jmp 1000h:0000
	jmp $	

<<<<<<< HEAD
;	jmp CODE_SEG:0x1000
	jmp KERNEL_OFFSET
	jmp $

;DATA
BOOT_DRIVE	db 0
MSG_REAL	db "Started in 16-bit Real Mode", 0
MSG_PROT	db "Successfully landed in 32-bit Protected Mode", 0
MSG_KERN	db "Loading kernel into memory...", 0
times 510 - ($-$$) db 0
dw 0xAA55
=======
times 510-($-$$) db 0
dw 0xaa55

>>>>>>> 9daf38df3d6c86b72b2294bf9ef75bd8276fcdd4
