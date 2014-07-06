;clearscreen
; -clears the screen
;;;;;;;;;;;;;;;;;;;;;;;;;;;;
clearscreen:
        pusha
        xor ah, ah
        mov al, 0x03
        int 0x10
        popa
        ret
;;;;;;;;;;;;;;;;;;;;;;;;;;;;

