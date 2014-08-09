unsigned long _asm_syscall0(int number)
{
    unsigned long ret;

    asm volatile (
            "movq %1, %%rax\n\t"
            "syscall\n\t"
            "movq %%rax, %0\n\t"
            :"=r"(ret)
            :"r"((unsigned long)number)
            :"%rax","%rcx","%r11"
       );

    return ret;
}

unsigned long _asm_syscall1(int number, unsigned long arg0)
{
    unsigned long ret;

    asm volatile (
            "movq %1, %%rax\n\t"
            "movq %2, %%rdi\n\t"
            "syscall\n\t"
            "movq %%rax, %0\n\t"
            :"=r"(ret)
            :"r"((unsigned long)number),"r"(arg0)
            :"%rax","%rdi","%rcx","%r11"
       );

    return ret;
}

unsigned long _asm_syscall2(int number, unsigned long arg0,
        unsigned long arg1)
{
    unsigned long ret;

    asm volatile (
            "movq %1, %%rax\n\t"
            "movq %2, %%rdi\n\t"
            "movq %3, %%rsi\n\t"
            "syscall\n\t"
            "movq %%rax, %0\n\t"
            :"=r"(ret)
            :"r"((unsigned long)number),"r"(arg0),"r"(arg1)
            :"%rax","%rdi","%rsi","%rcx","%r11"
       );

    return ret;
}

unsigned long _asm_syscall3(int number, unsigned long arg0,
        unsigned long arg1, unsigned long arg2)
{
    unsigned long ret;

    asm volatile (
            "movq %1, %%rax\n\t"
            "movq %2, %%rdi\n\t"
            "movq %3, %%rsi\n\t"
            "movq %4, %%rdx\n\t"
            "syscall\n\t"
            "movq %%rax, %0\n\t"
            :"=r"(ret)
            :"r"((unsigned long)number),"r"(arg0),"r"(arg1),"r"(arg2)
            :"%rax","%rdi","%rsi","%rdx","%rcx","%r11"
       );

    return ret;
}

unsigned long _asm_syscall4(int number, unsigned long arg0,
        unsigned long arg1, unsigned long arg2, unsigned long arg3)
{
    unsigned long ret;

    asm volatile (
            "movq %1, %%rax\n\t"
            "movq %2, %%rdi\n\t"
            "movq %3, %%rsi\n\t"
            "movq %4, %%rdx\n\t"
            "movq %5, %%r10\n\t"
            "syscall\n\t"
            "movq %%rax, %0\n\t"
            :"=r"(ret)
            :"r"((unsigned long)number),"r"(arg0),"r"(arg1),"r"(arg2),
            "r"(arg3)
            :"%rax","%rdi","%rsi","%rdx","%r10","%rcx","%r11"
       );

    return ret;
}

unsigned long _asm_syscall5(int number, unsigned long arg0,
        unsigned long arg1, unsigned long arg2, unsigned long arg3,
        unsigned long arg4)
{
    unsigned long ret;

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
            :"r"((unsigned long)number),"r"(arg0),"r"(arg1),"r"(arg2),
            "r"(arg3),"r"(arg4)
            :"%rax","%rdi","%rsi","%rdx","%r10","%r8","%rcx","%r11"
       );

    return ret;
}

unsigned long _asm_syscall6(int number, unsigned long arg0,
        unsigned long arg1, unsigned long arg2, unsigned long arg3,
        unsigned long arg4, unsigned long arg5)
{
    unsigned long ret;

    asm volatile (
            "pushq %r11\n\t"
            "movq %1, %%rax\n\t"
            "movq %2, %%rdi\n\t"
            "movq %3, %%rsi\n\t"
            "movq %4, %%rdx\n\t"
            "movq %5, %%r10\n\t"
            "movq %6, %%r8\n\t"
            "movq %7, %%r9\n\t"
            "syscall\n\t"
            "popq %r11\n\t"
            "movq %%rax, %0\n\t"
            :"=r"(ret)
            :"r"((unsigned long)number),"r"(arg0),"r"(arg1),"r"(arg2),
            "r"(arg3),"r"(arg4),"r"(arg5)
            :"%rax","%rdi","%rsi","%rdx","%r10","%r8","%r9","%rcx"
       );

    return ret;
}
