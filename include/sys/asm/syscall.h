#ifndef _ASM_SYSCALL_H
#define _ASM_SYSCALL_H

#include <stdint.h>

uintptr_t _asm_syscall(uintptr_t arg0, uintptr_t arg1,
        uintptr_t arg2, uintptr_t arg3,
        uintptr_t arg4, uintptr_t arg5, int number);

uintptr_t _asm_syscall0(int number);

uintptr_t _asm_syscall1(int number, uintptr_t arg0);

uintptr_t _asm_syscall2(int number, uintptr_t arg0,
        uintptr_t arg1);

uintptr_t _asm_syscall3(int number, uintptr_t arg0,
        uintptr_t arg1, uintptr_t arg2);

uintptr_t _asm_syscall4(int number, uintptr_t arg0,
        uintptr_t arg1, uintptr_t arg2, uintptr_t arg3);

uintptr_t _asm_syscall5(int number, uintptr_t arg0,
        uintptr_t arg1, uintptr_t arg2, uintptr_t arg3,
        uintptr_t arg4);

#endif
