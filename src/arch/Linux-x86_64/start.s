.globl _start

.text

_start:
    popq %rdi       /* argc */
    movq %rsp, %rsi /* argv */
    andq $0xffffffffffffff00, %rsp /* abi alignment */
    call main
    movq %rax, %rdi
    movq $60, %rax
    syscall
