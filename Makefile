include nostd.mk

CFLAGS+=-Os -Wall -Wextra
LDFLAGS+=-Os -s

.PHONY: all clean libs test_bin test

all: libs test_bin
libs: lib/libnostdmin.a lib/libnostd.a

UNAME_S := $(shell sh -c 'uname -s')
UNAME_M := $(shell sh -c 'uname -m')
ARCH ?= $(UNAME_S)-$(UNAME_M)
ARCH_SRC := src/arch/$(ARCH)

lib/libnostdmin.a: $(ARCH_SRC)/start.o $(ARCH_SRC)/syscall.o src/sys/syscall.o src/sys/exit.o
lib/libnostd.a: $(ARCH_SRC)/start.o $(ARCH_SRC)/syscall.o src/sys/syscall.o src/sys/exit.o src/io/base.o

test_bin: libs
	@cd test; make

test: test_bin
	@cd test; make test

clean: 
	-$(RM) lib/libnostdmin.a lib/libnostd.a
	-$(RM) $(ARCH_SRC)/{syscall.o,start.o}
	-$(RM) src/sys/{exit.o,syscall.o}
	-$(RM) src/io/base.o
	@cd test; make clean
