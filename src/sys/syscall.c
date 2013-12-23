#include <stdarg.h>
#include <sys/syscall.h>

/* returns the number of argument taken by a particular
 * syscall */
static int arg_count(int number)
{
    switch (number) {
        case __NR_exit:
            return 1;
        default:
            return 0;
      
    }
}

extern long _asm_syscall(long arg0, long arg1,
        long arg2, long arg3, long arg4, long arg5, int number);

int syscall(int number, ...)
{
    int i;
    static long asm_args[6];
    int n_args = arg_count(number);

    va_list args;
    va_start(args, number);

    for (i = 0; i < n_args; i++) {
        asm_args[i] = va_arg(args, long);
    }

    va_end(args);

    return _asm_syscall(asm_args[0], asm_args[1], asm_args[2], asm_args[3],
            asm_args[4], asm_args[5], number);
}
