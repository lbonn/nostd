typedef unsigned short umode_t;

#define O_ACCMODE	   0003
#define O_RDONLY	     00
#define O_WRONLY	     01
#define O_RDWR		     02
#define O_CREAT		   0100	/* not fcntl */
#define O_EXCL		   0200	/* not fcntl */
#define O_NOCTTY	   0400	/* not fcntl */
#define O_TRUNC		  01000	/* not fcntl */
#define O_APPEND	  02000
#define O_NONBLOCK	  04000
#define O_NDELAY	O_NONBLOCK
#define O_SYNC		 010000
#define O_DIRECT	 040000	/* direct disk access hint - currently ignored */
#define O_LARGEFILE	0100000
#define O_DIRECTORY	0200000	/* must be a directory */
#define O_NOFOLLOW	0400000 /* don't follow links */
#define O_NOATIME	01000000

int open(const char *pathname, int flags, umode_t mode);
ssize_t read(int fd, void *buf, size_t count);
ssize_t write(int fd, const void *buf, size_t count);
int close(int fd);
