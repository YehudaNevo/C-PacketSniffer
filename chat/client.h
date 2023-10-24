#ifndef CLIENT_H
#define CLIENT_H

#include <stdint.h>

// Type definitions
typedef struct {
    int socket_fd;
    char server_ip[16];
    uint16_t server_port;
} ServerInfo;

/* Initialization Module */
// Initialize the client.
void client_init(void);

// Create client socket and establish connection.
int socket_create(const char *server_ip, int server_port, ServerInfo *server_info);

/* Messaging Module */
// Compose and send messages to server.
void send_message(const char *message, ServerInfo *server_info);

// Receive and decode incoming messages from server.
void receive_message(char **received_data, ServerInfo *server_info);

/* User Interface Module */
// Display a list of all connected clients on the server.
void list_all_clients(void);

// Choose a specific client to chat with.
void select_client(int client_id);

/* Security Module */
// Encrypt messages before sending to server.
char* encryption(const char *plain_text);

// Decrypt received messages.
char* decryption(const char *cipher_text);

#endif // CLIENT_H
