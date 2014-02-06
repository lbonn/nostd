#include <sys/syscall.h>

void exit(int status)
{
    _syscall1(SYS_exit, status);

    /* silence annoying noreturn warning */
    while (1);
}
