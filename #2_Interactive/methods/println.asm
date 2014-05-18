; println 
; - prints string at si

println:
        lodsb
        or al, al
        jz returnPrintln
        mov ah, 0x0e
        mov bx, 0x0007
        int 0x10
        jmp println
returnPrintln:
        retn

