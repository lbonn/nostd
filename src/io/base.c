#include <def.h>
#include <sys/syscall.h>
#include <io/base.h>

int open(const char *pathname, int flags, umode_t mode)
{
    return syscall(__NR_open, pathname, flags, mode);
}

ssize_t read(int fd, void *buf, size_t count)
{
    return syscall(__NR_read, fd, buf, count);
}

ssize_t write(int fd, const void *buf, size_t count)
{
    return syscall(__NR_write, fd, buf, count);
}

int close(int fd)
{
    return syscall(__NR_close, fd);
}
