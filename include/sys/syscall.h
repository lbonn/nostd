/* syscall.h
 * syscall function declaration and syscall ids
 */

#define SYS_read 0
#define SYS_write 1
#define SYS_open 2
#define SYS_close 3
#define SYS_stat 4
#define SYS_fstat 5
#define SYS_lstat 6
#define SYS_poll 7
#define SYS_lseek 8
#define SYS_mmap 9
#define SYS_mprotect 10
#define SYS_munmap 11
#define SYS_exit 60

unsigned long _syscall0(int number);
unsigned long _syscall1(int number, unsigned long arg0);
unsigned long _syscall2(int number, unsigned long arg0,
        unsigned long arg1);
unsigned long _syscall3(int number, unsigned long arg0,
        unsigned long arg1, unsigned long arg2);

int syscall(int number, ...);
