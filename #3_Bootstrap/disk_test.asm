[org 0x7c00]

	mov [BOOT_DRIVE], dl

	mov bp, 0x8000
	mov sp, bp

	mov bx, 0x9000
	mov dh, 5
	mov dl, [BOOT_DRIVE]
	call disk_load

	mov dx, [0x9000]
	call printhex

	mov dx, [0x9000+512]
	call printhex

	jmp $

%include "methods/printMethods.asm"
%include "methods/disk_load.asm"

BOOT_DRIVE: db 0
MSG: db "HERE IS SOMETHING!", 0
times 510-($-$$) db 0
dw 0xaa55

times 256 dw 0xdada
times 256 dw 0xface


