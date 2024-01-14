#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct {
    char name[MAX_NAME];
    int age;
    // .. add other stuff here

}; person;

unsigned int hash(char *name) {
    return 5;
}

int main() {
    printf("Greg => %u\n", hash("Greg"));
    printf("Samson => %u\n", hash("Samson"));
    printf("Orion => %u\n", hash("Orion"));
    printf("Frodo => %u\n", hash("Frodo"));
    printf("Kyla => %u\n", hash("Kyla"));
    printf("Gigi => %u\n", hash("Gigi"));
    return 0;
    
}