//
// Created by mybj2 on 25/10/2023.
//
#include "LinkedList.h"
#include "ListNode.h"
#include <stddef.h>

LinkedList *allocateList() {
    LinkedList* list = (LinkedList *)malloc(sizeof(LinkedList));
    ListNode* head = (ListNode *)malloc(sizeof(ListNode));
    list->head = head;
    head->key = -1;
    head->info = NULL;
    head->next =NULL;
    head->prev = NULL;
    return list;
}

void insertItemToList(LinkedList* list, int key, ClientInfo* info) {
    ListNode *ptr = list->head;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ListNode *node = (ListNode *) malloc(sizeof(ListNode));
    node->key = key;
    node->info = info;
    node->prev = ptr;
    node->next = NULL;
    ptr->next = node;

}

void removeItemFromList(LinkedList* list,int key) {
    ListNode* tmp;
    if ((tmp = search(list, key)) != NULL) {
        deleteItem(tmp);
    }
}

void deallocateList(LinkedList *list){
    ListNode *deleter;
    ListNode *ptr = list->head;
    while(ptr){
        deleter = ptr;
        ptr= ptr->next;
        free(deleter->info);
        free(deleter);
    }
    free(list);
}


ListNode* search(const LinkedList* list, int key){
    ListNode *ptr = (ListNode*)list->head;
    while (ptr) {
        if (ptr->key == key)
            return ptr;
        ptr= ptr->next;
    }
    return NULL;
}

int getValue(LinkedList* list,int key){
    ListNode * tmp;
    if ((tmp = search(list, key)) != NULL)
        return tmp->info->socket_fd;
    return -1;
}
void displayList(LinkedList* list){
    ListNode* tmp = list->head->next;
    while (tmp!=NULL){
        displayNode(tmp);
        tmp = tmp->next;
    }
}