#include <sys/syscall.h>

void exit(int status) 
{
    syscall(__NR_exit, status);
}
