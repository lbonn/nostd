nostd
=====

Program in C with bare system calls on Linux x86\_64.

No libc and really tiny executables (thanks to lto)!

    $ gcc --version
      gcc (GCC) 4.8.2 20131219 (prerelease)
      Copyright (C) 2013 Free Software Foundation, Inc.
      This is free software; see the source for copying conditions.  There is NO
      warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

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
    $ ../tools/stripper hello
    $ wc -c hello
      624 hello
    $ gcc -Os -s -o hello hello.c
    $ wc -c hello
    $ 4400 hello


**Beware**: highly unportable and incomplete (you'll have to do with ```open```,
```read```, ```write```, ```exit``` and ```close``` for now)


Project
-------

The goal is to generate very compact statically linked executables with extensive inlining when compiled with ```-Os -flto```.

The omission of libc's high level functions (```stdio.h``` for example) is intentional. If some of its features are needed, code them from POSIX!

I'll add more useful system calls later.


Issues and notes
----------------

* very few system calls
* gcc generates ugly code for variadic ```syscall(...)```
* gcc 4.9 needs AR=gcc-ar to compile static libraries with lto


Useful docs
-----------

[https://www.kernel.org/doc/man-pages](https://www.kernel.org/doc/man-pages)

[http://man7.org/linux/man-pages/man2/syscall.2.html#NOTES](http://man7.org/linux/man-pages/man2/syscall.2.html#NOTES)

