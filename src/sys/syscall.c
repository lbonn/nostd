#include <stdarg.h>
#include <sys/syscall.h>

/* returns the number of argument taken by a particular
 * syscall */
static int arg_count(int number)
{
    switch (number) {
        case SYS_exit:
            return 1;
        case SYS_open: case SYS_read: case SYS_write:
           return 3;
        default:
            return 0;
      
    }
}

extern unsigned long _asm_syscall(unsigned long arg0, unsigned long arg1,
        unsigned long arg2, unsigned long arg3,
        unsigned long arg4, unsigned long arg5, int number);

extern unsigned long _asm_syscall0(int number);
extern unsigned long _asm_syscall1(int number, unsigned long arg0);
extern unsigned long _asm_syscall2(int number, unsigned long arg0,
        unsigned long arg1);
extern unsigned long _asm_syscall3(int number, unsigned long arg0,
        unsigned long arg1, unsigned long arg2);
extern unsigned long _asm_syscall4(int number, unsigned long arg0,
        unsigned long arg1, unsigned long arg2, unsigned long arg3);
extern unsigned long _asm_syscall5(int number, unsigned long arg0,
        unsigned long arg1, unsigned long arg2, unsigned long arg3,
        unsigned long arg4);

unsigned long _syscall0(int number)
{
    return _asm_syscall0(number);
}

unsigned long _syscall1(int number, unsigned long arg0)
{
    return _asm_syscall1(number, arg0);
}

unsigned long _syscall2(int number, unsigned long arg0,
        unsigned long arg1)
{
    return _asm_syscall2(number, arg0, arg1);
}

unsigned long _syscall3(int number, unsigned long arg0,
        unsigned long arg1, unsigned long arg2)
{
    return _asm_syscall3(number, arg0, arg1, arg2);
}

int syscall(int number, ...)
{
    const int n_args = arg_count(number);
    unsigned long ret;

    va_list args;
    va_start(args, number);

    switch (n_args) {
        case 0:
            ret = _asm_syscall0(number);
            break;
        case 1:
            ret = _asm_syscall1(number, va_arg(args, unsigned long));
            break;
        case 2:
            ret = _asm_syscall2(number, va_arg(args, unsigned long),
                    va_arg(args, unsigned long));
            break;
        case 3:
            ret = _asm_syscall3(number, va_arg(args, unsigned long),
                    va_arg(args, unsigned long), va_arg(args, unsigned long));
            break;
        case 4:
            ret = _asm_syscall4(number, va_arg(args, unsigned long),
                    va_arg(args, unsigned long), va_arg(args, unsigned long),
                    va_arg(args, unsigned long));
            break;
        case 5:
            ret = _asm_syscall5(number, va_arg(args, unsigned long),
                    va_arg(args, unsigned long), va_arg(args, unsigned long),
                    va_arg(args, unsigned long), va_arg(args, unsigned long));
            break;
    }

    va_end(args);

    return ret;
}

