
---

# Advanced Chat Application in C

## Table of Contents

1. [Server Architecture](#server-architecture)
2. [Client Architecture](#client-architecture)
3. [Additional Features & Summary](#additional-features--summary)

---

## Server Architecture

### Initialization Module
- **`server_init()`**: Handles the overall initialization of the server.
- **`socket_create()`**: Encapsulates the socket creation logic.

### Client Management Module
- **`client_add()`**: Adds a new client and assigns a unique ID.
- **`client_remove()`**: Safely removes a disconnected client.
- **`get_all_clients()`**: Fetches details of all connected clients.

### Non-Blocking Module
- **`set_non_blocking()`**: Sets the non-blocking flags to sockets.
- **`io_multiplex()`**: Uses `poll()` or `epoll` for I/O multiplexing.

### Messaging Module
- **`broadcast()`**: Sends messages to all connected clients.
- **`unicast()`**: Directs messages to a specific client based on the client ID.
- **`protocol_parse()`**: Parses the incoming message according to the defined protocol.

### Security Module
- **`encryption()`**: Encrypts the outgoing messages.
- **`decryption()`**: Decrypts the incoming messages.

### Logging Module
- **`log_error()`**: Logs all error events.
- **`log_activity()`**: Logs general activities for audit trails.

---

## Client Architecture

### Initialization Module
- **`client_init()`**: Takes care of client initialization.
- **`socket_create()`**: Manages client-side socket creation.

### Messaging Module
- **`send_message()`**: Composes and sends messages.
- **`receive_message()`**: Receives and decodes incoming messages.

### User Interface Module
- **`list_all_clients()`**: Lists all connected clients on the server.
- **`select_client()`**: Enables user to select a specific client to chat with.

### Security Module
- **`encryption()`**: Encrypts messages before sending.
- **`decryption()`**: Decrypts received messages.

---

## Additional Features & Summary

### Data Structures
- Server: Utilizes a `struct` and Hash Table for efficient client management.
- Client: Uses a `struct` to manage server connection and client details.

### Message Protocol
- Adheres to a well-defined message protocol for seamless communication.

### Design Patterns
- Follows Modular Design pattern for better scalability and maintainability.

### Security
- Implements basic encryption and decryption for secure communication.

### Under the Hood
- Leverages the power of C's low-level functionalities for high performance.
- Employs I/O multiplexing techniques (`poll()` or `epoll`) to manage multiple clients concurrently.

---

