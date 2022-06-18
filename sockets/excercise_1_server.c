#include <sys/un.h>
#include <sys/socket.h>
#include "tlpi_hdr.h"

#define SOCK_NAME "xyz"

#define BUF_SIZE 50

int
main(int argc, char * argv[])
{
    struct sockaddr_un addr, claddr;
    int sfd;
    socklen_t len;
    ssize_t numRead;
    char buf[BUF_SIZE];

    sfd = socket(AF_UNIX, SOCK_DGRAM, 0);
    if (sfd == -1)
        errExit("socket");

    memset(&addr, 0, sizeof(struct sockaddr_un));
    addr.sun_family = AF_UNIX;

    strncpy(&addr.sun_path[1], SOCK_NAME, sizeof(struct sockaddr_un) - 2);

    if (bind(sfd, (struct sockaddr *) &addr, sizeof(struct sockaddr_un)) == -1)
        errExit("bind");

    while(TRUE) {
        len = sizeof(struct sockaddr_un);

        while(TRUE);
        numRead = recvfrom(sfd, buf, BUF_SIZE, 0, (struct sockaddr *) &claddr, &len);

        if (numRead == -1)
            errExit("recvfrom");

        write(STDOUT_FILENO, buf, BUF_SIZE);
    }
}
