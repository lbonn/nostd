#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

static int stdout_fd = 1;

static size_t strlen(const char *str)
{
    int k = 0;

    while (*str++) {
        k++;
    }

    return k;
}

static void print_str(const char *str)
{
    write(stdout_fd, str, strlen(str));
}

static void print_char(char c)
{
    write(stdout_fd, &c, 1);
}

static unsigned char digit_char(unsigned char c)
{
    if (c < 10) {
        return c + '0';
    }
    return (c-10) + 'a';
}

static void print_ull(unsigned long long l, unsigned long base)
{
    unsigned char buf[sizeof(unsigned long long)*8+1];
    int k = 0;

    do {
        buf[k] = digit_char(l%base);
        l = l/base;
        k++;
    } while(l >0);

    k--;

    for (;k >= 0;k--) {
        print_char(buf[k]);
    }
}

static void print_it(unsigned long long l)
{
    print_ull(l, 10);
    print_str(" 0x");
    print_ull(l, 16);
    print_str(" 0");
    print_ull(l, 8);
    if (l >= 0x20 && l <= 0x7E) {
        print_str(" '");
        print_char((unsigned char)l);
        print_char('\'');
    }
    print_char('\n');
}

static int digit_from_char(char c, long base, char *digit)
{
    if (c >= '0' && c <= '9') {
        *digit = c - '0';
        return (*digit < base);
    }

    if (base <= 10) {
        return 0;
    }

    char p;
    if (c >= 'A' && c <= 'Z') {
        p = c - 'A';
    } else if (c >= 'a' && c <= 'z') {
        p = c - 'a';
    } else {
        return 0;
    }
    *digit = p + 10;

    return (p < base);
}

static unsigned long long strtoull(const char *nptr)
{
    char c;
    char digit;
    long base;
    unsigned long long l;

    /* skip spaces */
    while (*nptr == ' ') {
        nptr++;
    };

    if (nptr[0] == '0' && nptr[1] == 'x') {
        /* hex */
        base = 16;
        nptr += 2;
    } else if (nptr[0] == '0') {
        /* oct */
        base = 8;
        nptr += 1;
    } else {
        /* dec */
        base = 10;
    }

    l = 0;
    while (digit_from_char(c = *nptr, base, &digit)) {
        l = l*base + digit;
        nptr++;
    }

    return l;
}

int main(int argc, char**argv)
{
    int k;
    for (k = 1; k < argc; k++) {
        unsigned long long l;
        char *cc = argv[k];

        if ((l = strtoull(cc)) || *cc == '0') {
            print_it(l);
            continue;
        }

        while (*cc) {
            print_it(*cc++);
        }
    }

    return 0;
}
