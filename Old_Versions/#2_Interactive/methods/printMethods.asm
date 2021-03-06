;**************;
; PRINT METHODS;
;**************;

; print
; - prints string at si
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
print:
        lodsb
        or al, al
        jz returnPrint
        mov ah, 0x0e
        mov bx, 0x0007
        int 0x10
        jmp print
returnPrint:
        retn

; println 
; - prints string at si with
;   with newline
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
println:
	call print
	mov al, 0x0A
	int 0x10
	mov al, 0x0D
	int 0x10
	
	ret
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; printhex
; - prints hex at dx
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
HEX_OUT: db '0x0000', 0

printhex:
	mov bx, HEX_OUT
	add bx, 5

	nexthex:
	mov cx, dx
	and cx, 0x000f
	
	cmp cx, 0x000A
	jl normalhex

	mov [bx], byte 'A'
	sub cx, 10
	
	
	normalhex:
	add [bx], cx

	dec bx
	shr dx, 4
	cmp [bx], byte 'x'
	jne nexthex

        mov si, HEX_OUT
        call println
	ret
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; printin
; -prints the next input
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
printin:
        xor ah, ah
        int 0x16
        mov ah, 0x0e
        int 0x10
        mov bl, al
        call checknewline
        mov bl, al
        call checkdelete
        ret

checknewline:           ; add newline if carriage return
        xor bl, 13
        jz newline
        ret

        newline:
        mov al, 10
        int 0x10
        ret

checkdelete:            ; replace with space if backspace
        xor bl, 8
        jz delete
        ret

        delete:
        mov al, 0x20
        int 0x10
        mov al, 8
        int 0x10
        ret
;;;;;;;;;;;;;;;;;;;;;;;;;;;;

