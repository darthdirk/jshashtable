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

} person;

person *hash_table[TABLE_SIZE];

unsigned int hash(char *name) {
    int length = strnlen(name, MAX_NAME);  
    unsigned int hash_value = 0; // declare var to start sum at 0
    for (int i=0; i < length; i++) {
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;// adds more randomization
    }

    return hash_value;
}

bool init_hash_table() {
    for (int i=0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
    // table is empty
}

void print_table() {
    printf("Start\n");
    for (int i=0; i < TABLE_SIZE; i++) {
        if (hash_table[i] == NULL) {
            printf("\t%i\t---\n",i);
        } else {
            printf("\t%i\t%s\n",i, hash_table[i]->name);
        }
    }
    printf("End\n");
}


bool hash_table_insert(person *p) {
    if (p == NULL) return false;
    int index = hash(p->name);
    if (hash_table[index] != NULL) {
        return false;
    }
    hash_table[index] = p;
    return true;
}

int main() {

    init_hash_table();
    print_table();
    
    person greg = {.name="Greg", .age=16};
    person gigi = {.name="Gigi", .age=1};
    person kyla = {.name="Kyla", .age=5};

    hash_table_insert(&greg);
    hash_table_insert(&gigi);
    hash_table_insert(&kyla);
    print_table();



    /*printf("Greg => %u\n", hash("Greg"));
    printf("Samson => %u\n", hash("Samson"));
    printf("Orion => %u\n", hash("Orion"));
    printf("Frodo => %u\n", hash("Frodo"));
    printf("Kyla => %u\n", hash("Kyla"));
    printf("Gigi => %u\n", hash("Gigi"));
    printf("Deb => %u\n", hash("Deb"));
    printf("Dale => %u\n", hash("Dale"));
    printf("Elsa => %u\n", hash("Elsa"));
    printf("Dan => %u\n", hash("Dan"));
    printf("Kelly => %u\n", hash("Kelly"));
    printf("Weston => %u\n", hash("Weston"));
    printf("Cameron => %u\n", hash("Cameron"));
    printf("Shelby => %u\n", hash("Shelby"));
    printf("Nanea => %u\n", hash("Nanea"));
    printf("Logan => %u\n", hash("Logan"));
    printf("Nolan => %u\n", hash("Nolan"));
    printf("Kaiser => %u\n", hash("Kaiser"));
    printf("Carson => %u\n", hash("Carson"));
    printf("Bart => %u\n", hash("Bart"));
    */
    return 0;
    
}