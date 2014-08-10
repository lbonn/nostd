#include <stdlib.h>
#include <stdint.h>
#include <sys/asm/syscall.h>
#include <sys/syscall.h>
#include <fcntl.h>

int open(const char *pathname, int flags, umode_t mode)
{
    return _asm_syscall3(SYS_open, (uintptr_t)pathname,
            (uintptr_t)flags, (uintptr_t)mode);
}

ssize_t read(int fd, void *buf, size_t count)
{
    return _asm_syscall3(SYS_read, (uintptr_t)fd,
            (uintptr_t)buf, (uintptr_t)count);
}

ssize_t write(int fd, const void *buf, size_t count)
{
    return _asm_syscall3(SYS_write, (uintptr_t)fd,
            (uintptr_t)buf, (uintptr_t)count);
}

int close(int fd)
{
    return _asm_syscall1(SYS_close, (uintptr_t)fd);
}
