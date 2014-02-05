TOP?=.
OPT_LEVEL=-Os
CFLAGS=-Wall -Wextra $(OPT_LEVEL) -flto -nostdlib
LDFLAGS=-static -s $(OPT_LEVEL) -flto -nostdlib
CFLAGS+=-I$(TOP)/include

# useful variables for user compilation
LIBNOSTD=$(TOP)/lib/libnostd.a

%.a:
	$(AR) rcs $@ $^

%: %.o
	$(CC) $(LDFLAGS) $^ $(LIBNOSTD) -o $@
	@$(TOP)/tools/stripper $@ $(CC)
