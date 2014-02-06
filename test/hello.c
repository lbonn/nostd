#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    static const char hello[] = "hello world\n";
  
    write(1, hello, sizeof(hello));

    return 0;
}
