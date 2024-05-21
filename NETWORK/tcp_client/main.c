#include <arpa/inet.h>
#include <bits/types/struct_timeval.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include <stdio.h>
#include <string.h>

#define SOCKET int

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

    SOCKET sock_peer = socket(peer_info->ai_family, peer_info->ai_socktype, peer_info->ai_protocol);
    if (sock_peer == -1)
    {
        fprintf(stderr, "socket failed with error(%d)\n", errno);
        return 1;
    }

    printf("Connecting to remote...\n");
    if (connect(sock_peer, peer_info->ai_addr, peer_info->ai_addrlen))
    {
        fprintf(stderr, "Connect() failed. (%d)\n", errno);
        return 1;
    }
    freeaddrinfo(peer_info);

    printf("Connected\n");
    printf("To Send Data, enter the text followed by enter.\n");

    for (;;)
    {
        fd_set reads;
        FD_ZERO(&reads);
        FD_SET(sock_peer, &reads);

        struct timeval timeout;
        timeout.tv_sec = 0;
        timeout.tv_usec = 100000;

        if (select(sock_peer + 1, &reads, 0, 0, &timeout) < 0)
        {
            fprintf(stderr, "select() failed. (%d)\n", errno);
            return 1;
        }

        if (FD_ISSET(sock_peer, &reads))
        {
            char read[4096];

            int bytes_received = recv(sock_peer, read, 4096, 0);
            if (bytes_received < 1)
            {
                printf("Connection closed by peer.\n");
                break;
            }
            printf("Received (%d bytes): %.*s", bytes_received, bytes_received, read);
        }

        if (FD_ISSET(0, &reads))
        {
            char read[4096];
            if (!fgets(read, 4096, stdin))
                break;

            printf("Sending: %s", read);
            int bytes_sent = send(sock_peer, read, strlen(read), 0);
            printf("Sent %d bytes. \n", bytes_sent);
        }
    }

    printf("Closing socket\n");
    close(sock_peer);
}
