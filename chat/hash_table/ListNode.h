#ifndef CHAT_LINKEDLIST_H
#define CHAT_LINKEDLIST_H

typedef struct ListNode {
    int key;
    int fd;
    struct ListNode* next;
    struct ListNode* prev;
} ListNode;

ListNode* allocateList();
void insertItemToList(ListNode* head, int key, int fd);
void removeItemFromList(ListNode* head);
void deallocateList(ListNode* head);
ListNode* search(const ListNode* head,int key);
void displayList(ListNode* list);
void displayNode(const ListNode* node);

#endif //CHAT_LINKEDLIST_H
