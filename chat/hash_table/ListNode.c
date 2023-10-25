#include <stdlib.h>
#include <stdio.h>
#include "ListNode.h"



void displayNode(const ListNode* node){
    printf("Value of Key: %d\n", node->key);
    printf("File Descriptor number: %d\n",node->info->socket_fd);
    printf("IP address: %s\n",node->info->client_ip);
    printf("Port Number: %PRIu16\n",node->info->client_port);
}

void deleteItem(ListNode *node) {
    node->prev->next = node->next;
    if(node->next!=NULL)
        node->next->prev = node->prev;
    free(node->info);
    free(node);
}