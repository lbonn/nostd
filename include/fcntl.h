#ifndef _FNCTL_H
#define _FNCTL_H

/* fcntl.h
 */

typedef unsigned short umode_t;

static const int O_ACCMODE = 0003;
static const int O_RDONLY = 00;
static const int O_WRONLY = 01;
static const int O_RDWR	= 02;
static const int O_CREAT = 0100;
static const int O_EXCL	= 0200;
static const int O_NOCTTY = 0400;
static const int O_TRUNC = 01000;
static const int O_APPEND = 02000;
static const int O_NONBLOCK	= 04000;
static const int O_NDELAY = 04000;
static const int O_SYNC = 010000;
static const int O_DIRECT = 040000;
static const int O_LARGEFILE = 0100000;
static const int O_DIRECTOR	= 0200000;
static const int O_NOFOLLOW	= 0400000;
static const int O_NOATIME = 01000000;

int open(const char *pathname, int flags, umode_t mode);

#endif
