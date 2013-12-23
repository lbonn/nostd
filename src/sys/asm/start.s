.globl _start

.text

_start:
    popq %rdi       /* argc */
    movq %rsp, %rsi /* argv */
    call main
    movq %rax, %rdi
    call exit
