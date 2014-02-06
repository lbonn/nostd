#include <stdarg.h>
#include <sys/asm/syscall.h>
#include <sys/syscall.h>

/* returns the number of argument taken by a particular
 * syscall */
static int arg_count(int number)
{
    switch (number) {
        case SYS_exit: case SYS_close:
            return 1;
        case SYS_open: case SYS_read: case SYS_write:
           return 3;
        default:
            return 0;
    }
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
