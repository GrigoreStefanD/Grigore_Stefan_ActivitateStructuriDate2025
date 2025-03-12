
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

