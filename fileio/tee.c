#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include "tlpi_hdr.h"

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif

typedef int fd_t;

int
main(int argc, char *argv[])
{
    int truncOrAppendFlag, i;
    fd_t inputFd, outputsFd[argc - 1];
    ssize_t numRead;
    mode_t filePerms;
    size_t outputsNum = 1;
    char buf[BUF_SIZE];


    inputFd = STDIN_FILENO;         /* Fd of STDIN is already open! */


    outputsFd[0] = STDOUT_FILENO;   /* Fd of STDOUT is already open! */

    filePerms = S_IRUSR | S_IWUSR |
                S_IRGRP | S_IWGRP |
                S_IROTH | S_IWOTH;  /* rw-rw-rw- */

    truncOrAppendFlag = O_TRUNC;    /* By default, the program overwrites any existing file */

    for (i = 1; i < argc; i++) {
        if (i == 1 && strcmp(argv[i], "-a") == 0)
            truncOrAppendFlag = O_APPEND;
        else if ((outputsFd[outputsNum++] = open(argv[i], O_CREAT | O_WRONLY | truncOrAppendFlag, filePerms)) == -1)
            errExit("opening file %s", argv[i]);
    }

    while ((numRead = read(inputFd, buf, BUF_SIZE)) > 0)
        for(i = 0; i < outputsNum; i++)
            if(write(outputsFd[i], buf, numRead) != numRead)
                fatal("couldn't write whole buffer");
    if (numRead == -1)
        errExit("read");

    if (close(inputFd) == -1)
        errExit("close output");

    for (i = 0; i < outputsNum; i++)
        if (close(outputsFd[i]) == -1)
            errExit("close output");
}
