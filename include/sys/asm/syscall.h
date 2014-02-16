#ifndef _ASM_SYSCALL_H
#define _ASM_SYSCALL_H
unsigned long _asm_syscall(unsigned long arg0, unsigned long arg1,
        unsigned long arg2, unsigned long arg3,
        unsigned long arg4, unsigned long arg5, int number);

unsigned long _asm_syscall0(int number);

unsigned long _asm_syscall1(int number, unsigned long arg0);

unsigned long _asm_syscall2(int number, unsigned long arg0,
        unsigned long arg1);

unsigned long _asm_syscall3(int number, unsigned long arg0,
        unsigned long arg1, unsigned long arg2);

unsigned long _asm_syscall4(int number, unsigned long arg0,
        unsigned long arg1, unsigned long arg2, unsigned long arg3);

unsigned long _asm_syscall5(int number, unsigned long arg0,
        unsigned long arg1, unsigned long arg2, unsigned long arg3,
        unsigned long arg4);

#endif
