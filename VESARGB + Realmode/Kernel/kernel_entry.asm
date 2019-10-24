extern _kmain
bits 16
global _second
global vbe_info_structure


_second:
	
	mov ax, 0
	mov es, ax
	mov ax, [vbe_info_structure]
	mov di, ax
	
	mov ax, 0x4f00
	
	int 0x10
	
	

	lgdt [gdt_descriptor]

    cli

    mov eax , cr0 ; To make the switch to protected mode , we set
    or eax , 0x1 ; the first bit of CR0 , a control register
    mov cr0 , eax ; Update the control register

    jmp CODE_SEG:pm

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





    call _kmain
    ret
	
	
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



vbe_info_structure:
	.signature		db "VESA"	; indicate support for VBE 2.0+
	.table_data:		resb 256-4	; reserve space for the table below




	
