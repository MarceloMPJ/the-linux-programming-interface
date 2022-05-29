#include <sys/stat.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

int
main(int argc, char *argv[])
{
    int fd;

    fd = open("test.txt", O_WRONLY | O_APPEND);
    lseek(fd, 0, SEEK_SET);

    write(fd, "test", 4);

    close(fd);
}
