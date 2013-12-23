#include <sys/syscall.h>
extern int main(int argc, char *argv[]);

void _start(int argc, char *argv[])
{
    syscall(__NR_exit, main(argc, argv));
}
