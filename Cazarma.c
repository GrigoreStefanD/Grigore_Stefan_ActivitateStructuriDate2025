
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


struct Soldat {
    int id;
    char nume[50];
    int varsta;
};


struct Soldat soldati[100];
int numar_soldati = 0;

void adauga_soldat(int id, char nume[], int varsta) {
    if (numar_soldati < 100) {
        soldati[numar_soldati].id = id;
        strcpy(soldati[numar_soldati].nume, nume);
        soldati[numar_soldati].varsta = varsta;
        numar_soldati++;
    }
    else {
        printf("Cazarma este plina.\n");
    }
}


void afiseaza_soldati() {
    for (int i = 0; i < numar_soldati; i++) {
        printf("ID: %d, nume: %s, varsta: %d\n", soldati[i].id, soldati[i].nume, soldati[i].varsta);
    }
}


void sterge_soldat(int id) {
    for (int i = 0; i < numar_soldati; i++) {
        if (soldati[i].id == id) {
            for (int j = i; j < numar_soldati - 1; j++) {
                soldati[j] = soldati[j + 1];
            }
            numar_soldati--;
            printf("soldatul cu ID %d a fost sters.\n", id);
            return;
        }
    }
    printf("soldatul cu ID %d nu a fost gasit.\n", id);
}


