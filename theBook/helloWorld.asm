section .data
msg: DB 'Hello World!' , 10
msgSize EQU $ - msg

global start 

section .text

    start:
    mov rax, 4  ; function 4
    mov rbx, 1 ; stdout
    mov rcx, msg ; msg
    mov rdx, msgSize ; size
    int 0x90 
    mov rax, 1
    mov rbx, 0
    int 0x80
    ret 