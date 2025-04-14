#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef struct Cladire {
    int id;
    int anConstruire;
    char nume[50];
    struct Cladire* next;
} Cladire;

typedef struct HashTable {
    Cladire* table[SIZE];
} HashTable;

HashTable* creareTabela() {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    for (int i = 0; i < SIZE; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}

int hashFunction(int anConstruire) {
    return anConstruire % SIZE;
}

void adaugaCladire(HashTable* ht, int id, int anConstruire, const char* nume) {
    int index = hashFunction(anConstruire);
    Cladire* cladireNoua = (Cladire*)malloc(sizeof(Cladire));
    cladireNoua->id = id;
    cladireNoua->anConstruire = anConstruire;
    strcpy(cladireNoua->nume, nume);
    cladireNoua->next = ht->table[index];
    ht->table[index] = cladireNoua;
}

void afiseazaCladiriDinCluster(HashTable* ht, int anConstruire) {
    int index = hashFunction(anConstruire);
    Cladire* current = ht->table[index];
    while (current) {
        if (current->anConstruire == anConstruire) {
            printf("ID: %d, Nume: %s, An: %d\n", current->id, current->nume, current->anConstruire);
        }
        current = current->next;
    }
}

void stergeCladireIDAn(HashTable* ht, int id, int anConstruire) {
    int index = hashFunction(anConstruire);
    Cladire* current = ht->table[index];
    Cladire* prev = NULL;
    while (current) {
        if (current->id == id && current->anConstruire == anConstruire) {
            if (prev) {
                prev->next = current->next;
            }
            else {
                ht->table[index] = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

void stergeCladireID(HashTable* ht, int id) {
    for (int i = 0; i < SIZE; i++) {
        Cladire* current = ht->table[i];
        Cladire* prev = NULL;
        while (current) {
            if (current->id == id) {
                if (prev) {
                    prev->next = current->next;
                }
                else {
                    ht->table[i] = current->next;
                }
                free(current);
                return;
            }
            prev = current;
            current = current->next;
        }
    }
}

Cladire** salveazaCladiriDinAn(HashTable* ht, int anConstruire, int* numarCladiri) {
    int index = hashFunction(anConstruire);
    Cladire* current = ht->table[index];
    *numarCladiri = 0;
    while (current) {
        if (current->anConstruire == anConstruire) {
            (*numarCladiri)++;
        }
        current = current->next;
    }
    Cladire** vector = (Cladire**)malloc((*numarCladiri) * sizeof(Cladire*));
    current = ht->table[index];
    int idx = 0;
    while (current) {
        if (current->anConstruire == anConstruire) {
            vector[idx] = (Cladire*)malloc(sizeof(Cladire));
            *vector[idx] = *current;
            idx++;
        }
        current = current->next;
    }
    return vector;
}

void modificaAnulConstruirii(HashTable* ht, int id, int vechiAn, int nouAn) {
    stergeCladireIDAn(ht, id, vechiAn);
    adaugaCladire(ht, id, nouAn, "Cladire mod");
}

int main() {
    HashTable* ht = creareTabela();
    adaugaCladire(ht, 1, 1980, "Cladire1");
    adaugaCladire(ht, 2, 1980, "Cladire2");
    adaugaCladire(ht, 3, 1990, "Cladire3");

    printf("Cladiri din anul 1980:\n");
    afiseazaCladiriDinCluster(ht, 1980);

    printf("Stergere Cladire 1  an 1980:\n");
    stergeCladireIDAn(ht, 1, 1980);
    afiseazaCladiriDinCluster(ht, 1980);

    printf("Modifica an construc pt Cladire 2:\n");
    modificaAnulConstruirii(ht, 2, 1980, 2000);
    afiseazaCladiriDinCluster(ht, 1980);
    afiseazaCladiriDinCluster(ht, 2000);

    int numarCladiri;
    Cladire** vector = salveazaCladiriDinAn(ht, 1990, &numarCladiri);
    printf("Cladiri an 1990 salvate intr-un vector:\n");
    for (int i = 0; i < numarCladiri; i++) {
        printf("ID: %d, Nume: %s, An: %d\n", vector[i]->id, vector[i]->nume, vector[i]->anConstruire);
        free(vector[i]);        
    }
    free(vector);

    free(ht);
    return 0;
}
