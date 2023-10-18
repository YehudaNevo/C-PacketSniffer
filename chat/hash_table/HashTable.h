#ifndef CHAT_HASHTABLE_H
#define CHAT_HASHTABLE_H
#include "ListNode.h"
#define TABLE_SIZE 199

typedef struct {
    ListNode* hashTable[TABLE_SIZE];
    int size;
    int count;
}HashTable;

HashTable* initializeTable();
int hash(int key);
int get(HashTable* ht, int  key);
void insertToTable(const HashTable* ht,int key,int value);
void removeFromTable(const HashTable* ht, int key);
void deallocateTable(HashTable* ht);
void displayTable(const HashTable* ht);
#endif //CHAT_HASHTABLE_H
