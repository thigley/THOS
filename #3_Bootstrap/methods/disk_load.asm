;;;;;;;;;;;;;
; disk_load ;
;;;;;;;;;;;;;
; from Nick Blundell
; load DH sectors to ES:BX from drive DL

disk_load:

	push dx		; Store DX on stack so later we can recall
			; how many sectors were request to be read.
			; even if it is altered in the meantime	

	mov ah, 0x02	; BIOS read sector function
	mov al, dh	; Read DH sectors
	mov ch, 0x00	; Select cylinder 0
	mov dh, 0x00	; Select head 0
	mov cl, 0x02	; Start reading from second sector (i.e.
			; after the boot sector)

	int 0x13	; BIOS interrupt

;	jc disk_error	; Jump if error (i.e. carry flag set)

	pop dx		; Restore DX from the stack

	mov bx, dx
	call printhex
	mov bx, ax
	call printhex

	cmp dh, al	; if AL (secotrs read) != DH (sectors expected0
	jne disk_error	;	display error message
	ret

disk_error:
	mov si, DISK_ERROR_MSG
	call println
	jmp $

; Variables
DISK_ERROR_MSG	db "Disk read error!", 0
