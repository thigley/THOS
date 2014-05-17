;****************;
; Interactive OS ;
;****************;

org 0x7c00

start:
	; CLEAR SCREEN
	xor ah, ah
	mov al, 0x03
	int 0x10

	; PRINT FIRST STRING
	mov ah, 0x0e
	mov si, msg
	call putstr
	
	; WAIT FOR KEY THEN PRINT 
	; SECOND STRING
	xor ah, ah
	int 0x16
	mov si, msg2
	call putstr

	; PRINT INPUT FOREVER
repeat:
	call printInput
	jmp repeat


; PRINT STRING
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

; PRINT INPUT
printInput:
	xor ah, ah
	int 0x16
	mov ah, 0x0e
	int 0x10
	mov bl, al
	call checknewline
	mov bl, al
	call checkdelete
	ret

checknewline:
	xor bl, 13
	jz newline
	ret
	
	newline:
	mov al, 10
	int 0x10
	ret

checkdelete:
	xor bl, 8
	jz delete
	ret

	delete:
	mov al, 0x20
	int 0x10
	mov al, 8
	int 0x10
	ret

; DATA
msg db 'Welcome to a typing OS!', 0x0A,0x0D, 0
msg2 db 'Type Away!', 0x0A, 0x0D, 0

times 510 - ($-$$) db 0

db 0x55, 0xAA
