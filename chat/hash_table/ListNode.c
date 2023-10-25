#include <stdlib.h>
#include <stdio.h>
#include "ListNode.h"


ListNode *allocateList() {
    ListNode *head = (ListNode *) malloc(sizeof(ListNode));
    head->key = -1;
    head->info = NULL;
    head->next =NULL;
    head->prev = NULL;
    return head;
}

void insertItemToList(ListNode *list, int key, ClientInfo* info) {
    ListNode *ptr = list;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ListNode *node = (ListNode *) malloc(sizeof(ListNode));
    node->key = key;
    node->info = info;
    node->prev = ptr;
    node->next = NULL;
    ptr->next = node;

}

void removeItemFromList(ListNode *node) {
    node->prev->next = node->next;
    if(node->next!=NULL)
        node->next->prev = node->prev;
    free(node->info);
    free(node);
}

void deallocateList(ListNode *list){
    ListNode *deleter;
    ListNode *ptr = list;
    while(ptr){
        deleter = ptr;
        ptr= ptr->next;
        free(deleter->info);
        free(deleter);
    }
}


ListNode* search(const ListNode* list, int key){
    ListNode *ptr = (ListNode*)list;
    while (ptr) {
        if (ptr->key == key)
            return ptr;
        ptr= ptr->next;
    }
    return NULL;
}
void displayList(ListNode* head){
    ListNode* tmp = head->next;
    while (tmp!=NULL){
        displayNode(tmp);
        tmp = tmp->next;
    }
}
void displayNode(const ListNode* node){
    printf("Value of Key: %d\n", node->key);
    printf("File Descriptor number: %d\n",node->info->socket_fd);
    printf("IP address: %s\n",node->info->client_ip);
    printf("Port Number: %PRIu16\n",node->info->client_port);
}