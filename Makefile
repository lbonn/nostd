include nostd.mk

.PHONY: all clean libs test_bin test

all: libs test_bin
libs: lib/libnostdmin.a lib/libnostdio.a
test_bin: lib/libnostdmin.a lib/libnostdio.a

lib/libnostdmin.a: src/sys/asm/start.o src/sys/asm/syscall.o src/sys/exit.o
lib/libnostdio.a: src/io/base.o src/sys/asm/syscall.o

test_bin: libs
	@cd test; make

test: test_bin
	@cd test; make test

clean: 
	-$(RM) lib/libnostdmin.a lib/libnostdio.a
	-$(RM) src/sys/asm/{syscall.o,start.o}
	-$(RM) src/sys/exit.o
	-$(RM) src/io/base.o
	@cd test; make clean
