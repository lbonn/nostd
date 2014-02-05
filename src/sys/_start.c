#include <sys/syscall.h>
extern int main(int argc, char *argv[]);

void _start(int argc, char *argv[])
{
    syscall(SYS_exit, main(argc, argv));
}
