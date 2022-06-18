#include <sys/un.h>
#include <sys/socket.h>
#include "tlpi_hdr.h"

#define SOCK_NAME "xyz"

#define BUF_SIZE 50

int
main(int argc, char *argv[])
{
    struct sockaddr_un svaddr;
    int sfd;
    char buf[BUF_SIZE];

    sfd = socket(AF_UNIX, SOCK_DGRAM, 0);
    if (sfd == -1)
        errExit("socket");

    memset(&svaddr, 0, sizeof(struct sockaddr_un));
    memset(&buf, 'A', BUF_SIZE);

    svaddr.sun_family = AF_UNIX;

    strncpy(&svaddr.sun_path[1], SOCK_NAME, sizeof(struct sockaddr_un) - 2);

    while(TRUE)
    {
        if (sendto(sfd, buf, BUF_SIZE, 0, (struct sockaddr *) &svaddr, sizeof(struct sockaddr_un)) != BUF_SIZE)
            fatal("sendto");

        write(STDOUT_FILENO, "Passei\n", 7);
    }

    exit(EXIT_SUCCESS);
}
