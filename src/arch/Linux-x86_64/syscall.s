.globl _asm_syscall
.globl _asm_syscall0
.globl _asm_syscall1
.globl _asm_syscall2
.globl _asm_syscall3
.globl _asm_syscall4
.globl _asm_syscall5

.text

/* HOWTO:
 * _asm_syscall(arg0, arg1, arg2, arg3, arg4, arg5, number)
 * _asm_syscall0(number)
 * _asm_syscall1(
*/

_asm_syscall:
    movq 8(%rsp), %rax
    syscall
    retq

_asm_syscall0:
    movq %rdi, %rax
    syscall
    retq

_asm_syscall1:
    movq %rdi, %rax
    movq %rsi, %rdi
    syscall
    retq

_asm_syscall2:
    movq %rdi, %rax
    movq %rsi, %rdi
    movq %rdx, %rsi
    syscall
    retq

_asm_syscall3:
    movq %rdi, %rax
    movq %rsi, %rdi
    movq %rdx, %rsi
    movq %rcx, %rdx
    syscall
    retq

_asm_syscall4:
    movq %rdi, %rax
    movq %rsi, %rdi
    movq %rdx, %rsi
    movq %rcx, %rdx
    movq %r8, %r10
    syscall
    retq

_asm_syscall5:
    movq %rdi, %rax
    movq %rsi, %rdi
    movq %rdx, %rsi
    movq %rcx, %rdx
    movq %r8, %r10
    movq %r9, %r8
    syscall
    retq

