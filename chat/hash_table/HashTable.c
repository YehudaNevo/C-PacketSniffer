#include "HashTable.h"
#include <stdlib.h>
#include <stdio.h>
HashTable* initializeTable(){
    HashTable* tmp = (HashTable*)malloc(sizeof(HashTable));
    for (int index = 0; index < TABLE_SIZE; ++index)
        tmp->hashTable[index]=allocateList();
    tmp->size = TABLE_SIZE;
    tmp->count = 0;
    return tmp;
}
int get(HashTable* ht, int key){
    int index = hash(key);
    ListNode* tmp;
    if((tmp= search(ht->hashTable[index],key))!=NULL)
        return tmp->fd;
    return -1;
}

int hash(const int value){ return value%TABLE_SIZE;}

void insertToTable(const HashTable* ht, const int key,const int value){
    int index = hash(key);
    if(search(ht->hashTable[index],key)==NULL) {
        insertItemToList(ht->hashTable[index], key, value);
        ht->count++;
    }
}

void removeFromTable(const HashTable* ht, int key) {
    int index = hash(key);
    ListNode* tmp;
    if ((tmp = search(ht->hashTable[index], key)) != NULL) {
        removeItemFromList(tmp);
        ht->count--;
    }
}

void displayTable(const HashTable* ht){
    printf("%s","Hash Table Contents:\n");
    for (int index = 0; index < TABLE_SIZE; ++index) {
        displayList(ht->hashTable[index]);
    }
}
void deallocateTable(HashTable* ht){
    for (int index = 0; index < TABLE_SIZE; ++index) {
        deallocateList(ht->hashTable[index]);
    }
    free(ht);
}