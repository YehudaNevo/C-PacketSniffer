#ifndef C_PACKETSNIFFER_LINKEDLIST_H
#define C_PACKETSNIFFER_LINKEDLIST_H

#include "ListNode.h"

typedef struct LinkedList {
    struct ListNode* head;
} LinkedList;

LinkedList* allocateList();
void insertItemToList(LinkedList* list, int key,ClientInfo* info );
void removeItemFromList(LinkedList* list,int key);
void deallocateList(LinkedList* list);
ListNode* search(const LinkedList* head,int key);
int getValue(LinkedList* head,int key);
void displayList(LinkedList* list);
#endif //C_PACKETSNIFFER_LINKEDLIST_H
