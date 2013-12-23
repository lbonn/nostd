TOP?=.
OPTIMS=-Os -flto
CFLAGS=-Wall -Wextra $(OPTIMS) -nostdlib
LDFLAGS=-static -s $(OPTIMS) -nostdlib
CFLAGS+=-I$(TOP)/include

# useful variables for user compilation
NOSTDLIB=$(TOP)/lib
LIBMIN=$(NOSTDLIB)/libnostdmin.a
LIBIO=$(NOSTDLIB)/libnostdio.a

%.a:
	$(AR) rcs $@ $^

%: %.o
	$(CC) $(LDFLAGS) $^ -o $@
	@$(TOP)/tools/stripper $@ $(CC)
