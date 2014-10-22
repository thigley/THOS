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

;;;;;;;;;;;;;;;;;;;;;;;;;;;;
