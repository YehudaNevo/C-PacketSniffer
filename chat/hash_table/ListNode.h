#ifndef CHAT_LINKEDLIST_H
#define CHAT_LINKEDLIST_H
#include <inttypes.h>


typedef struct ClientInfo{
    int socket_fd;
    char* client_ip;
    uint16_t client_port;
} ClientInfo;


typedef struct ListNode {
    int key;
    struct ClientInfo* info;
    struct ListNode* next;
    struct ListNode* prev;
} ListNode;

void deleteItem(ListNode* node);
void displayNode(const ListNode* node);

#endif //CHAT_LINKEDLIST_H
