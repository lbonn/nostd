#include <stdlib.h>
#include <sys/syscall.h>
#include <fcntl.h>

int open(const char *pathname, int flags, umode_t mode)
{
    return syscall(SYS_open, pathname, flags, mode);
}

ssize_t read(int fd, void *buf, size_t count)
{
    return syscall(SYS_read, fd, buf, count);
}

ssize_t write(int fd, const void *buf, size_t count)
{
    return syscall(SYS_write, fd, buf, count);
}

int close(int fd)
{
    return syscall(SYS_close, fd);
}
