; printin
; -prints the next input

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

checknewline:		; add newline if carriage return
        xor bl, 13
        jz newline
        ret

        newline:
        mov al, 10
        int 0x10
        ret

checkdelete:		; replace with space if backspace
        xor bl, 8
        jz delete
        ret

        delete:
        mov al, 0x20
        int 0x10
        mov al, 8
        int 0x10
        ret

