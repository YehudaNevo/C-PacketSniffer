#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include "server.h"

int server_socket; // Global server socket descriptor.

void server_init(void) {

    struct sockaddr_in server_address;
    int opt = 1;
    int flags;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Server: Failed to create socket");
        exit(1);
    }

    // Set the socket to be reusable.
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        perror("Server: Set sock opt error");
        close(server_socket);
        exit(1);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    server_address.sin_addr.s_addr = inet_addr(SERVER_IP);
    memset(server_address.sin_zero, '\0', sizeof server_address.sin_zero); // TODO ?

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Server: Failed to bind");
        close(server_socket);
        exit(1);
    }

    if (listen(server_socket, BACKLOG) == -1) {
        perror("Server: Failed to listen");
        close(server_socket);
        exit(1);
    }

    // Optionally, set the server socket to be non-blocking. // todo ?
    flags = fcntl(server_socket, F_GETFL, 0);
    fcntl(server_socket, F_SETFL, flags | O_NONBLOCK);

    printf("Server initialized on %s:%d\n", SERVER_IP, SERVER_PORT);

}
