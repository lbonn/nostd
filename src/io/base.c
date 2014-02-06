#include <stdlib.h>
#include <sys/asm/syscall.h>
#include <sys/syscall.h>
#include <fcntl.h>

int open(const char *pathname, int flags, umode_t mode)
{
    return _asm_syscall3(SYS_open, (unsigned long)pathname,
            (unsigned long)flags, (unsigned long)mode);
}

ssize_t read(int fd, void *buf, size_t count)
{
    return _asm_syscall3(SYS_read, (unsigned long)fd,
            (unsigned long)buf, (unsigned long)count);
}

ssize_t write(int fd, const void *buf, size_t count)
{
    return _asm_syscall3(SYS_write, (unsigned long)fd,
            (unsigned long)buf, (unsigned long)count);
}

int close(int fd)
{
    return _asm_syscall1(SYS_close, (unsigned long)fd);
}
