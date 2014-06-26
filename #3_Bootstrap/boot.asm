[org 0x7c00]
;[org 0]
;	jmp 07c0h:start

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
;%include 'methods/disk_load.asm'
%include 'gdt.asm'
%include 'methods/pmPrint.asm'
%include 'switch.asm'

MSG_REAL	db "Started in 16-bit Real Mode", 0
MSG_LOAD	db "Loading Kernel to memory", 0
MSG_PROT	db "Successfully landed in 32-bit Protected Mode", 0

[bits 32]
BEGIN_PM:

	mov ebx, MSG_PROT
	mov ax, 2
	call print_string_pm
	
	jmp 1000h:0000
	jmp $	

times 510-($-$$) db 0
dw 0xaa55

