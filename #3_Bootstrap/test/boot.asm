[org 0]

	jmp reset
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

	jmp 1000h:0000

times 510-($-$$) db 0
dw 0xaa55
