include ../nostd.mk
TOP=..

.PHONY: all clean test

all: start_test io_test i

start_test: start_test.o $(LIBMIN)
io_test: io_test.o $(LIBMIN) $(LIBIO)
i: i.o $(LIBMIN) $(LIBIO)

test:
	@sh run_test.sh

clean:
	-$(RM) start_test.o start_test
	-$(RM) io_test.o io_test
	-$(RM) i.o i
