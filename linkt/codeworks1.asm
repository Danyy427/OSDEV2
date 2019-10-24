
;**************************************************
;*                                                *
;*                      v0.1                      *
;*     Özgür Güzeldereli-Yarkýn Alpmen Akyosun    *
;*      © Telif Hakký, Bütün haklarý saklýdýr     *
;*                                                *
;**************************************************

; iþletim sisteminin ilk sektörü (512 byte)
; CD'den kerneli yükler, çalýþtýrýr ve
; diske yazar

; Tanýmlamalar
[ORG 0x7c00]
BITS 16
global _boot_start

_boot_start:
; Yükleyici
	
	cli
    mov bx,0x9000
	mov bp,bx
	mov sp,bx
	mov ss,bx
	sti 
	
	pusha
	xor ax, ax     ; ds sýfýr olsun ki  adresimizin
	mov ds, ax         ; 0000:7c00 olduðuna emin olalým
	mov es, ax
	popa
	
	mov [bootdev], dl
	
	
	mov bx, MSG_START       ; baþlangýç mesajý
	call print_string
	
	
	mov dl, [bootdev]             ; disk numarasý
	mov dh, 1               ; bir sektör oku
	mov bx, 0x1000          ; okuduklarýný RAM'de 0x1000'e koy
	call disk_load
	mov bx, MSG_YESNO
	call print_string
	
	call get_yes_no
	
	mov bx, MSG_BOOT_KERNEL
	call print_string
	
	
	
	lgdt [gdt_descriptor]
	
	mov eax , cr0 ; To make the switch to protected mode , we set
	or eax , 0x1 ; the first bit of CR0 , a control register
	mov cr0 , eax ; Update the control register
	
	jmp CODE_SEG:pm
	
	
; Alt fonksiyonlar
;******************************************************************
print_string:		; bx'yi ekrana bas

.loop:
    mov al,[bx]
	cmp al,0
	je return
	push bx
	mov ah,0Eh
	
	int 10h
	pop bx
	inc bx
	jmp .loop
	
return:
	ret	

;******************************************************************
get_yes_no:
	pusha 
.loop:
	mov ah, 00h
	int 16h
	cmp ah, 15h
	je .yes
	cmp ah, 31h
	je .no
	jmp .loop
	ret
.no:
	mov bx, No
	call print_string
    mov ah, 00h
	int 13h	
	jmp $
.yes:	
	mov bx, Yes
	call print_string
	jmp .done
.done:
	popa
	ret	
;******************************************************************
disk_load:
	push dx
	mov ah, 02h    ; BIOS okuyucu
	mov al, dh     ; DH kadar sektör oku
	mov ch, 0x00   ; silindir 0
	mov dh, 0x00   ; baþlýk 0
	mov cl, 0x02   ; ve ikinci sektörden baþla
	int 0x13       ; ve çaðýrdýk
	pop dx
	jc disk_error 
	cmp dh, al 
	jne disk_error_double
	mov bx,MSG_LOAD_SUCC
	call print_string
	ret	

disk_error:
	mov bx,MSG_LOAD_FAIL 
	call print_string
	jmp $
disk_error_double:
	mov bx,MSG_LOAD_FAIL_C
	call print_string
	jmp $

	
	
; Geri kalan yükleyici
	
BITS 32
	
	pm:
	
	
	mov ax , DATA_SEG ; Now in PM , our old segments are meaningless ,
	mov ds , ax 
	mov ss , ax 
	mov es , ax
	mov fs , ax
	mov gs , ax
	
	mov ebp , 0x90000 
	mov esp , ebp
	
	call beg_pm
	
	beg_pm:
	
	mov ebx,MSG_BOOT_32
	call print_string_pm
	
	call KERNEL_OFFSET
	
	jmp $	
	
;******************************************************************
print_string_pm :
	pusha
	mov edx , VIDEO_MEMORY ; Set edx to the start of vid mem.
	.print_string_pm_loop :
	mov al , [ ebx ] ; Store the char at EBX in AL
	mov ah , WHITE_ON_BLACK ; Store the attributes in AH
	cmp al , 0 ; if (al == 0), at end of string , so
	je .print_string_pm_done ; jump to done
	mov [edx], ax ; Store char and attributes at current
	; character cell.
	add ebx , 1 ; Increment EBX to the next char in string.
	add edx , 2 ; Move to next character cell in vid mem.
	jmp .print_string_pm_loop ; loop around to print the next char.
	.print_string_pm_done :
	popa
	ret	
	
; Global Descriptor table
; GDT
gdt_start :
gdt_null : ; the mandatory null descriptor
dd 0x0 ; 'dd ' means define double word ( i.e. 4 bytes )
dd 0x0
gdt_code : 
dw 0xffff ; Limit ( bits 0 -15)
dw 0x0 ; Base ( bits 0 -15)
db 0x0 ; Base ( bits 16 -23)
db 10011010b ; 1st flags , type flags
db 11001111b ; 2nd flags , Limit ( bits 16 -19)
db 0x0 ; Base ( bits 24 -31)
gdt_data : 
dw 0xffff ; Limit ( bits 0 -15)
dw 0x0 ; Base ( bits 0 -15)
db 0x0 ; Base ( bits 16 -23)
db 10010010b ; 1st flags , type flags
db 11001111b ; 2nd flags , Limit ( bits 16 -19)
db 0x0 ; Base ( bits 24 -31)
gdt_end : 

gdt_descriptor :
dw gdt_end - gdt_start - 1 
dd gdt_start 

CODE_SEG equ gdt_code - gdt_start
DATA_SEG equ gdt_data - gdt_start	
	
	
	
; Deðiþkenler

MSG_START DB ">",13,10,0
MSG_LOAD_SUCC DB "> Succesfully loaded",13,10,0
MSG_LOAD_FAIL DB "> Failed to load Please try to restart the system",13,10,0
MSG_LOAD_FAIL_C DB "> Error while loading",13,10,0
MSG_YESNO DB "> Do you want to boot up in kernel mode Y/N :",0
MSG_BOOT_KERNEL DB 13,10,"> Booting in kernel mode",0
MSG_BOOT_32 DB "32 bit pm",13,10,0
Yes db "Y",0
No db "N",0
bootdev: db 0
KERNEL_OFFSET equ 0x1000 
VIDEO_MEMORY equ 0xb8000
WHITE_ON_BLACK equ 0x0f

times 510-($-$$) db 0
dw 0xaa55
