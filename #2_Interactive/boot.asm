;print string from  joelgompert.com

org 0x7c00

start:
	mov ah, 0x0e
	mov si, msg
	call putstr
repeat:
	xor ah, ah
	int 0x16
	
	mov si, msg2
	call putstr

	jmp repeat

putstr:
	lodsb
	or al, al
	jz putstrd
	mov ah, 0x0e
	mov bx, 0x0007
	int 0x10
	jmp putstr
putstrd:
	retn

msg db 'Press a key!', 0x0A,0x0D, 0
msg2 db 'AWESOME!!!', 0x0A, 0x0D, 0

times 510 - ($-$$) db 0

db 0x55, 0xAA
