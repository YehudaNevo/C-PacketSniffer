#include "server.h"
#include "hash_table/HashTable.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>  // For inet_ntoa()
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

// Global hash table for client management
HashTable* clientTable;
int current_uid = 1;

void server_init(void) {
    printf("Initializing server...\n");
    clientTable = initializeTable();
    printf("Client table initialized.\n");
}

int socket_create(int port) {
    int server_socket;
    struct sockaddr_in server_addr;

    printf("Creating server socket...\n");

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        log_error("Failed to create socket");
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        log_error("Failed to bind socket");
        close(server_socket);
        return -1;
    }

    if (listen(server_socket, BACKLOG) == -1) {
        log_error("Failed to listen on socket");
        close(server_socket);
        return -1;
    }

    printf("Server socket created and listening on port %d.\n", port);
    return server_socket;
}

int client_add(int client_socket, struct sockaddr_in *client_addr) {
    ClientInfo client_info;
    client_info.socket_fd = client_socket;
    client_info.client_id = current_uid++;
    strncpy(client_info.client_ip, inet_ntoa(client_addr->sin_addr), sizeof(client_info.client_ip) - 1);
    client_info.client_ip[sizeof(client_info.client_ip) - 1] = '\0';  // Ensure null termination
    client_info.client_port = ntohs(client_addr->sin_port);

    insertToTable(clientTable, client_info.client_id, client_socket);
    printf("Added client with UID %d and IP %s:%d to the hash table.\n", client_info.client_id, client_info.client_ip, client_info.client_port);

    return client_info.client_id;
}

void client_remove(int client_id) {
    removeFromTable(clientTable, client_id);
    printf("Removed client with ID %d from the hash table.\n", client_id);
}

void get_all_clients(ClientInfo **clients, int *num_clients) {
    // This function should populate the clients array with all connected clients.
    // For simplicity, we're not implementing this now.
    printf("Fetching all connected clients...\n");
}

void set_non_blocking(int server_socket) {
    int flags = fcntl(server_socket, F_GETFL, 0);
    if (flags == -1) {
        log_error("Failed to get socket flags");
        return;
    }
    if (fcntl(server_socket, F_SETFL, flags | O_NONBLOCK) == -1) {
        log_error("Failed to set socket to non-blocking mode");
    }
}

void io_multiplex(void) {
    // This function should handle I/O multiplexing using poll() or epoll().
    // For simplicity, we're not implementing this now.
    printf("Setting up I/O multiplexing...\n");
}

void broadcast(const char *message) {
    printf("Broadcasting message: %s\n", message);
    // Send the message to all connected clients.
}

void unicast(int client_id, const char *message) {
    printf("Sending message to client with ID %d: %s\n", client_id, message);
    // Send the message to the specified client.
}

void protocol_parse(const char *received_data, char **parsed_data) {
    printf("Parsing received data...\n");
    // Parse the received data according to the defined protocol.
}

char* encryption(const char *plain_text) {
    printf("Encrypting message...\n");
    // Encrypt the message.
    return NULL; // Placeholder
}

char* decryption(const char *cipher_text) {
    printf("Decrypting message...\n");
    // Decrypt the message.
    return NULL; // Placeholder
}

void log_error(const char *error_message) {
    printf("[ERROR] %s\n", error_message);
}

void log_activity(const char *activity_message) {
    printf("[INFO] %s\n", activity_message);
}

void display_server_status(int signum) {
    printf("\n--- Server Status ---\n");
    printf("Server running...\n");
    displayTable(clientTable);
    printf("----------------------\n");
    alarm(10); // Schedule the next status display in 10 seconds
}



int main() {
    server_init();
    int server_socket = socket_create(SERVER_PORT);
    if (server_socket == -1) {
        return -1;
    }

    // Set up the signal handler for displaying server status every 10 seconds
    signal(SIGALRM, display_server_status);
    alarm(10);

    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    while (1) {

        int client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_len);
        if (client_socket == -1) {
            log_error("Failed to accept client connection");
            continue;
        }
        client_add(client_socket, &client_addr);
    }

    deallocateTable(clientTable);
    return 0;

}
