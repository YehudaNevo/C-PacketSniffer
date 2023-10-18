#include <stdio.h>
#include "HashTable.h"
int main(){
    HashTable* ht = initializeTable();
    insertToTable(ht,334,0);
    insertToTable(ht,19,4);
    insertToTable(ht,5,3);
    insertToTable(ht,204,3);
    insertToTable(ht,403,3);
    insertToTable(ht,1123,0);
    insertToTable(ht,111,0);
    insertToTable(ht,55,55);
    insertToTable(ht,1098,11);
    insertToTable(ht,43,0);
    insertToTable(ht,65,0);
    insertToTable(ht,227,0);
    insertToTable(ht,48,0);
    displayTable(ht);
    removeFromTable(ht,204);
    removeFromTable(ht,403);
    removeFromTable(ht,5);
    displayTable(ht);
    printf("fd for key 1098: %d\n",get(ht,1098));
    printf("fd for key 1099: %d\n",get(ht,1099));
    deallocateTable(ht);
    return 0;
}