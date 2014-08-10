#include <sys/asm/syscall.h>

uintptr_t _asm_syscall0(int number)
{
    uintptr_t ret;

    asm volatile (
            "movq %1, %%rax\n\t"
            "syscall\n\t"
            "movq %%rax, %0\n\t"
            :"=r"(ret)
            :"r"((uintptr_t)number)
            :"%rax","%rcx","%r11"
       );

    return ret;
}

uintptr_t _asm_syscall1(int number, uintptr_t arg0)
{
    uintptr_t ret;

    asm volatile (
            "movq %1, %%rax\n\t"
            "movq %2, %%rdi\n\t"
            "syscall\n\t"
            "movq %%rax, %0\n\t"
            :"=r"(ret)
            :"r"((uintptr_t)number),"r"(arg0)
            :"%rax","%rdi","%rcx","%r11"
       );

    return ret;
}

uintptr_t _asm_syscall2(int number, uintptr_t arg0,
        uintptr_t arg1)
{
    uintptr_t ret;

    asm volatile (
            "movq %1, %%rax\n\t"
            "movq %2, %%rdi\n\t"
            "movq %3, %%rsi\n\t"
            "syscall\n\t"
            "movq %%rax, %0\n\t"
            :"=r"(ret)
            :"r"((uintptr_t)number),"r"(arg0),"r"(arg1)
            :"%rax","%rdi","%rsi","%rcx","%r11"
       );

    return ret;
}

uintptr_t _asm_syscall3(int number, uintptr_t arg0,
        uintptr_t arg1, uintptr_t arg2)
{
    uintptr_t ret;

    asm volatile (
            "movq %1, %%rax\n\t"
            "movq %2, %%rdi\n\t"
            "movq %3, %%rsi\n\t"
            "movq %4, %%rdx\n\t"
            "syscall\n\t"
            "movq %%rax, %0\n\t"
            :"=r"(ret)
            :"r"((uintptr_t)number),"r"(arg0),"r"(arg1),"r"(arg2)
            :"%rax","%rdi","%rsi","%rdx","%rcx","%r11"
       );

    return ret;
}

uintptr_t _asm_syscall4(int number, uintptr_t arg0,
        uintptr_t arg1, uintptr_t arg2, uintptr_t arg3)
{
    uintptr_t ret;

    asm volatile (
            "movq %1, %%rax\n\t"
            "movq %2, %%rdi\n\t"
            "movq %3, %%rsi\n\t"
            "movq %4, %%rdx\n\t"
            "movq %5, %%r10\n\t"
            "syscall\n\t"
            "movq %%rax, %0\n\t"
            :"=r"(ret)
            :"r"((uintptr_t)number),"r"(arg0),"r"(arg1),"r"(arg2),
            "r"(arg3)
            :"%rax","%rdi","%rsi","%rdx","%r10","%rcx","%r11"
       );

    return ret;
}

uintptr_t _asm_syscall5(int number, uintptr_t arg0,
        uintptr_t arg1, uintptr_t arg2, uintptr_t arg3,
        uintptr_t arg4)
{
    uintptr_t ret;

    asm volatile (
            "movq %1, %%rax\n\t"
            "movq %2, %%rdi\n\t"
            "movq %3, %%rsi\n\t"
            "movq %4, %%rdx\n\t"
            "movq %5, %%r10\n\t"
            "movq %6, %%r8\n\t"
            "syscall\n\t"
            "movq %%rax, %0\n\t"
            :"=r"(ret)
            :"r"((uintptr_t)number),"r"(arg0),"r"(arg1),"r"(arg2),
            "r"(arg3),"r"(arg4)
            :"%rax","%rdi","%rsi","%rdx","%r10","%r8","%rcx","%r11"
       );

    return ret;
}

uintptr_t _asm_syscall6(int number, uintptr_t arg0,
        uintptr_t arg1, uintptr_t arg2, uintptr_t arg3,
        uintptr_t arg4, uintptr_t arg5)
{
    uintptr_t ret;

    asm volatile (
            "pushq %%r11\n\t"
            "movq %1, %%rax\n\t"
            "movq %2, %%rdi\n\t"
            "movq %3, %%rsi\n\t"
            "movq %4, %%rdx\n\t"
            "movq %5, %%r10\n\t"
            "movq %6, %%r8\n\t"
            "movq %7, %%r9\n\t"
            "syscall\n\t"
            "popq %%r11\n\t"
            "movq %%rax, %0\n\t"
            :"=r"(ret)
            :"r"((uintptr_t)number),"r"(arg0),"r"(arg1),"r"(arg2),
            "r"(arg3),"r"(arg4),"r"(arg5)
            :"%rax","%rdi","%rsi","%rdx","%r10","%r8","%r9","%rcx"
       );

    return ret;
}
