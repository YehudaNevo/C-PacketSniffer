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


ListNode* allocateList();
void insertItemToList(ListNode* head, int key,ClientInfo* info );
void removeItemFromList(ListNode* head);
void deallocateList(ListNode* head);
ListNode* search(const ListNode* head,int key);
void displayList(ListNode* list);
void displayNode(const ListNode* node);

#endif //CHAT_LINKEDLIST_H
