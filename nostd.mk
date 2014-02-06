NOSTD_DIR?=.
CFLAGS+=-flto -nostdlib -I$(NOSTD_DIR)/include
LDFLAGS+=-static -flto -nostdlib

# useful variables for user compilation
LIBNOSTD=$(NOSTD_DIR)/lib/libnostd.a

%.a:
	$(AR) rcs $@ $^

%: %.o
	$(CC) $(LDFLAGS) $^ $(LIBNOSTD) -o $@
	@$(NOSTD_DIR)/tools/stripper $@ $(CC)

