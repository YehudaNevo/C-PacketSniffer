#include <stdio.h>
#include "HashTable.h"
int main(){
    HashTable* ht = initializeTable();

    int fd1 = 0;
    int fd2 = 4;
    int fd3 = 3;
    int fd4 = 3;
    int fd5 = 3;
    int fd6 = 0;
    int fd7 = 0;
    int fd8 = 55;
    int fd9 = 11;
    int fd10 = 0;
    int fd11 = 0;
    int fd12 = 0;
    int fd13 = 0;

    char* ip1 = "192.168.1.1"; // Replace with the actual IP addresses
    char* ip2 = "192.168.1.2";
    char* ip3 = "192.168.1.3";
    char* ip4 = "192.168.1.4";
    char* ip5 = "192.168.1.5";
    char* ip6 = "192.168.1.6";
    char* ip7 = "192.168.1.7";
    char* ip8 = "192.168.1.8";
    char* ip9 = "192.168.1.9";
    char* ip10 = "192.168.1.10";
    char* ip11 = "192.168.1.11";
    char* ip12 = "192.168.1.12";
    char* ip13 = "192.168.1.13";

    uint16_t client_port1 = 12345; // Replace with actual values
    uint16_t client_port2 = 54321;

    insertToTable(ht, 334, &fd1, ip1, &client_port1);
    insertToTable(ht, 19, &fd2, ip2, &client_port2);
    insertToTable(ht, 5, &fd3, ip3, &client_port1);
    insertToTable(ht, 204, &fd4, ip4, &client_port2);
    insertToTable(ht, 403, &fd5, ip5, &client_port1);
    insertToTable(ht, 1123, &fd6, ip6, &client_port1);
    insertToTable(ht, 111, &fd7, ip7, &client_port2);
    insertToTable(ht, 55, &fd8, ip8, &client_port1);
    insertToTable(ht, 1098, &fd9, ip9, &client_port2);
    insertToTable(ht, 43, &fd10, ip10, &client_port1);
    insertToTable(ht, 65, &fd11, ip11, &client_port2);
    insertToTable(ht, 227, &fd12, ip12, &client_port1);
    insertToTable(ht, 48, &fd13, ip13, &client_port2);

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