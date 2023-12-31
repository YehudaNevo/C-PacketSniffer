#include "HashTable.h"
#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

HashTable *initializeTable() {
    HashTable *tmp = (HashTable *) malloc(sizeof(HashTable));
    for (int index = 0; index < TABLE_SIZE; ++index)
        tmp->hashTable[index] = allocateList();
    return tmp;
}

int get(HashTable *ht, int key) {
    int index = hash(key);
    return getValue(ht->hashTable[index],key);

}

int hash(const int value) { return value % TABLE_SIZE; }

void insertToTable(HashTable *ht, int key, int *fd, char *ip, uint16_t *client_port) {
    int index = hash(key);
    if (search(ht->hashTable[index], key) == NULL) {
        ClientInfo *info = (ClientInfo *) malloc(sizeof(ClientInfo));
        info->socket_fd = *fd;
        info->client_ip = ip;
        info->client_port = *client_port;
        insertItemToList(ht->hashTable[index], key, info);
    }
}

void removeFromTable(HashTable *ht, int key) {
    int index = hash(key);
    removeItemFromList(ht->hashTable[index],key);
}

void displayTable(const HashTable *ht) {
    printf("%s", "Hash Table Contents:\n");
    for (int index = 0; index < TABLE_SIZE; ++index) {
        displayList(ht->hashTable[index]);
    }
}

void deallocateTable(HashTable *ht) {
    for (int index = 0; index < TABLE_SIZE; ++index) {
        deallocateList(ht->hashTable[index]);
    }
    free(ht);
}