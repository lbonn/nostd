nostd
=====

Program in C with bare system calls on Linux x86\_64.

No libc and really tiny executables (thanks to lto)!

    $ cat hello.c
      #include <stdlib.h>
      #include <fcntl.h>
      #include <unistd.h>

      int main()
      {
          static const char hello[] = "hello world\n";
          write(1, hello, sizeof(hello));
          return 0;
      }
    $ make hello
      cc -Wall -Wextra -Os -flto -nostdlib -I../include   -c -o hello.o hello.c
      cc -static -s -Os -flto -nostdlib hello.o ../lib/libnostd.a -o hello
    $ ./hello
      hello world
    $ wc -c hello
      944 hello
    $ ../tools/stripper
      624 hello
    $ gcc -o hello hello.c
    $ wc -c hello
    $ 6762 hello


*Beware*: highly unportable and incomplete (you'll have to do with ```open```,
```read```, ```write```, ```exit``` and ```close``` for now)


Project
-------

The goal is to generate very compact statically linked executables with extensive inlining when compiled with ```-Os -flto```.

The omission of libc's high level functions (```stdio.h``` for example) is intentional. If some of its feature are needed, they must be coded by the user from POSIX.

I'll add more useful system calls later!


Issues
------

* very few system calls
* gcc generates ugly code for variadic ```syscall(...)```


Useful docs
-----------

[https://www.kernel.org/doc/man-pages](https://www.kernel.org/doc/man-pages)
[http://man7.org/linux/man-pages/man2/syscall.2.html#NOTES](http://man7.org/linux/man-pages/man2/syscall.2.html#NOTES)

