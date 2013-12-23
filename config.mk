CC=gcc
OPTIMS=-Os -flto
CFLAGS=-Wall -Wextra $(OPTIMS) -nostdlib
LDFLAGS=-static -s $(OPTIMS) -nostdlib

%.a:
	$(AR) rcs $@ $^

%: %.o
	$(CC) $(LDFLAGS) $^ -o $@
	@strip -R .comment -R .note.gnu.build-id -R .eh_frame $@
