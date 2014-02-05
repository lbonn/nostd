/* syscall.h
 * syscall function declaration and syscall ids
 */

static const int SYS_read = 0;
static const int SYS_write = 1;
static const int SYS_open = 2;
static const int SYS_close = 3;
static const int SYS_stat = 4;
static const int SYS_fstat = 5;
static const int SYS_lstat = 6;
static const int SYS_poll = 7;
static const int SYS_lseek = 8;
static const int SYS_mmap = 9;
static const int SYS_mprotect = 10;
static const int SYS_munmap = 11;
static const int SYS_exit = 60;

int syscall(int number, ...);
