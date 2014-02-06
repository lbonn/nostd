NOSTD_DIR?=.
OPT_LEVEL=-Os
CFLAGS=-Wall -Wextra $(OPT_LEVEL) -flto -nostdlib
LDFLAGS=-static -s $(OPT_LEVEL) -flto -nostdlib
CFLAGS+=-I$(NOSTD_DIR)/include

# useful variables for user compilation
LIBNOSTD=$(NOSTD_DIR)/lib/libnostd.a

%.a:
	$(AR) rcs $@ $^

%: %.o
	$(CC) $(LDFLAGS) $^ $(LIBNOSTD) -o $@
	@$(NOSTD_DIR)/tools/stripper $@ $(CC)
