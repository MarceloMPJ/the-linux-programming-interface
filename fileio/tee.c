#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include "tlpi_hdr.h"

typedef int fd_t;

int
main(int argc, char *argv[])
{
  size_t filesNum;
  fd_t writer, writers[filesNum];
  int openFlags, i;

  filesNum = argc - 1;

  writers[0] = STDOUT_FILENO;

  openFlags = O_CREATE | O_WRONLY | O_TRUNC;

  for(i = 1; i < argc; i++) {
    writer = open(argv[i], );
  }
}
