#include <sys/syscall.h>

void exit(int status)
{
    syscall(SYS_exit, status);

    /* silence annoying noreturn warning */
    while (1);
}
