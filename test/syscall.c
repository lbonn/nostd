#include <sys/syscall.h>

int main()
{
    syscall(SYS_exit, 0);
    return 0;
}
