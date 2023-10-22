#ifndef SERVER_H
#define SERVER_H

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8080
#define BACKLOG 10
#define BUFF_SIZE 1024


#include <stdint.h>

/* Initialization Module */
// Initialize the server.
void server_init(void);

// Create server socket.
int socket_create(int port);

/* Client Management Module */
// Add a new client and assign a unique ID.
int client_add(int client_socket);

// Remove a disconnected client.
void client_remove(int client_id);

// Retrieve details of all connected clients.
void get_all_clients(void);

/* Non-Blocking Module */
// Apply non-blocking flags to server socket.
void set_non_blocking(int server_socket);

// Employ I/O multiplexing for handling multiple clients.
void io_multiplex(void);

/* Messaging Module */
// Send messages to all connected clients.
void broadcast(const char *message);

// Direct message to a specific client based on client ID.
void unicast(int client_id, const char *message);

// Parse incoming messages to adhere to protocol.
void protocol_parse(const char *received_data);

/* Security Module */
// Encrypt outgoing messages.
char* encryption(const char *plain_text);

// Decrypt incoming messages.
char* decryption(const char *cipher_text);

/* Logging Module */
// Log errors to file or console.
void log_error(const char *error_message);

// Log general activities for auditing.
void log_activity(const char *activity_message);

#endif // SERVER_H
