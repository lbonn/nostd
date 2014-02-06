#include <sys/syscall.h>
#include <sys/asm/syscall.h>

void exit(int status)
{
    _asm_syscall1(SYS_exit, status);

    /* silence annoying noreturn warning */
    while (1);
}
