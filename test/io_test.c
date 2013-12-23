#include <def.h>
#include <io/base.h>

static size_t strlen(const char *str)
{
    int k = 0;

    while (*str++) {
        k++;
    }

    return k;
}

static void print_line(int fd, const char *str)
{
    write(fd, str, strlen(str));
    write(fd, "\n", 1);
}

int main(int argc, char *argv[])
{
    int k;

    for (k = 0; k < argc; k++) {
        print_line(1, argv[k]);
    }

    return 0;
}
