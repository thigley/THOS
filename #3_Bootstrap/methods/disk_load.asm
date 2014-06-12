;;;;;;;;;;;;;
; disk_load ;
;;;;;;;;;;;;;
; from Nick Blundell
; load DH sectors to ES:BX from drive DL

disk_load:

	push dx		; Store DX on stack so later we can recall
			; how many sectors were request to be read.
			; even if it is altered in the meantime.

	mov ah, 0x02	; BIOS read sector function
	mov al, dh	; Read DH sectors
	mov ch, 0x00	; Select cylinder 0
	mov dh, 0x00	; Select head 0
	mov cl, 0x02	; Start reading from second sector (i.e.
			; after the boot sector)
	int 0x13	; BIOS interrupt
	pop dx		; Restore DX from the stack
	ret
