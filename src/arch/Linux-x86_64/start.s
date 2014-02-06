.globl _start

.text

_start:
    popq %rdi       /* argc */
    movq %rsp, %rsi /* argv */
    call main
    movq %rax, %rdi
    movq $60, %rax
    syscall
