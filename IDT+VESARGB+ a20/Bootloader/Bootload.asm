[ORG 0x7c00]
BITS 16
global _boot_start
_boot_start:
; YÃ¼kleyici

    cli
    mov bx,0x9000
    mov bp,bx
    mov sp,bx
    mov ss,bx
    sti 


    xor ax, ax     
    mov ds, ax       
    mov es, ax


    mov [bootdev], dl


    mov bx, MSG_START       ;
    call print_string


    mov dl, [bootdev]          
    mov dh, 35          
    mov cl, 0x02
    mov bx, 0x1000          
    call disk_load
    mov bx, MSG_YESNO
    call print_string

    call get_yes_no

    mov bx, MSG_BOOT_KERNEL
    call print_string

	
    mov ax, 0x4F02
    mov bx, 11Bh | 0x4000
	
    int 0x10

    lgdt [gdt_descriptor]

    cli

    mov eax , cr0 ; To make the switch to protected mode , we set
    or eax , 0x1 ; the first bit of CR0 , a control register
    mov cr0 , eax ; Update the control register

    jmp CODE_SEG:pm


; Alt fonksiyonlar
;******************************************************************
print_string:       

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
    mov ah, 02h    
    mov al, dh    
    mov ch, 0x00   
    mov dh, 0x00  
    ;mov cl, 0x02   
    int 0x13     
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

    call KERNEL_OFFSET

    jmp $   

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



; DeÄŸiÅŸkenler

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
