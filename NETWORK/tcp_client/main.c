#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, " Usage: <hostname> <port>.\n");
        return 1;
    }

    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_socktype = SOCK_STREAM;
    struct addrinfo *peer_info;
    if (getaddrinfo(argv[1], argv[2], &hints, &peer_info))
    {
        fprintf(stderr, "getaddrinfo failed with error(%d)\n", errno);
        return 1;
    }

    printf("Remote addr: ");
    char address_buffer[100];
    char service_buffer[100];

    getnameinfo(peer_info->ai_addr, peer_info->ai_addrlen, address_buffer, sizeof(address_buffer), service_buffer,
                sizeof(service_buffer), NI_NUMERICHOST);

    printf("%s %s\n", address_buffer, service_buffer);
}
