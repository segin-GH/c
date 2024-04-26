#include <stdio.h>
#include <string.h>
#include <time.h>

#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

int main()
{
    printf("Configuring local address...\n");

    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    struct addrinfo *bind_addr;
    getaddrinfo(0, "8080", &hints, &bind_addr);

    printf("Creating Sockets...\n");
    int socket_listen = socket(bind_addr->ai_family, bind_addr->ai_socktype, bind_addr->ai_protocol);
    if (socket_listen <= 0)
    {
        fprintf(stderr, "socket() failed. (%d)\n", errno);
        return 1;
    }

    printf("binding socket to local host...\n");
    if (bind(socket_listen, bind_addr->ai_addr, bind_addr->ai_addrlen))
    {
        fprintf(stderr, "bind() failed. (%d)\n", errno);
        return 2;
    }
    freeaddrinfo(bind_addr);

    printf("listening...\n");
    if (listen(socket_listen, 10) < 0)
    {
        fprintf(stderr, "listen() failed. (%d) \n", errno);
        return 3;
    }

    printf("waiting for connection...\n");
    struct sockaddr_storage client_address;
    socklen_t client_len = sizeof(client_address);
    int socket_client = accept(socket_listen, (struct sockaddr *)&client_address, &client_len);
    if (socket_client <= 0)
    {
        fprintf(stderr, "accept() failed. (%d)\n", errno);
        return 4;
    }

    printf("Client Connected...\n");
    char addr_buffer[100];
    getnameinfo((struct sockaddr *)&client_address, client_len, addr_buffer, sizeof(addr_buffer), 0, 0, NI_NUMERICHOST);
    printf("%s\n", addr_buffer);

    printf("Reading request...\n");
    char request[1024];

    int bytes_received = recv(socket_client, request, 1024, 0);
    printf("received %d bytes\n", bytes_received);
    printf("%.*s", bytes_received, request);

    printf("Sending response....\n");
    const char *response =
        "HTTP/1.1 200 OK\r\n"
        "Connection: close\r\n"
        "Content-Type: text/plain\r\n\r\n"
        "Local time is: ";

    int bytes_sent = send(socket_client, response, strlen(response), 0);
    printf("Sent %d of %d bytes.\n", bytes_sent, (int)strlen(response));

    time_t timer;
    time(&timer);
    printf("Sending Local time is: %s", ctime(&timer));
    char *time_msg = ctime(&timer);

    bytes_sent = send(socket_client, time_msg, strlen(time_msg), 0);
    printf("Sent %d of %d bytes.\n", bytes_sent, (int)strlen(time_msg));

    printf("Closing connection....\n");
    close(socket_client);

    return 0;
}
