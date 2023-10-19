#ifndef CLIENT_H
#define CLIENT_H

#include <stdint.h>

/* Initialization Module */
// Initialize the client.
void client_init(void);

// Create client socket and establish connection.
int socket_create(const char *server_ip, int server_port);

/* Messaging Module */
// Compose and send messages to server.
void send_message(const char *message);

// Receive and decode incoming messages from server.
void receive_message(void);

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
