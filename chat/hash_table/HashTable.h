#ifndef CHAT_HASHTABLE_H
#define CHAT_HASHTABLE_H


#include <stdint.h>
#include "LinkedList.h"

#define TABLE_SIZE 199

typedef struct {
    LinkedList* hashTable[TABLE_SIZE];
} HashTable;

HashTable* initializeTable();
int hash(int key);
int get(HashTable* ht, int key);
void insertToTable(HashTable* ht, int key, int* fd, char* ip, uint16_t* client_port);
void removeFromTable(HashTable* ht, int key);
void deallocateTable(HashTable* ht);
void displayTable(const HashTable* ht);

#endif
