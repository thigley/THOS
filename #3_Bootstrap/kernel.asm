[org 0x1000]
jmp 0x0000:main

msg db 'Hello World', 0
%include "methods/printMethods.asm"

main:
	mov si, msg
	call println
	
;	mov ebx, msg
;	mov ax, 4
;	call print_string_pm

loops:
	jmp loops
