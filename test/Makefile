include ../nostd.mk
NOSTD_DIR=..

.PHONY: all clean test

all: start_test hello io_test i syscall

start_test: start_test.o
hello: hello.o
io_test: io_test.o
i: i.o
syscall: syscall.o

test:
	@sh run_test.sh

clean:
	-$(RM) start_test.o start_test
	-$(RM) hello.o hello
	-$(RM) io_test.o io_test
	-$(RM) syscall.o syscall
	-$(RM) i.o i
