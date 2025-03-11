#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Animal
{
    char nume[50];
    int varsta;
    struct Animal* urmator;
    struct Animal* precedent;
};

struct Animal* creareAnimal(char* nume, int varsta)
{
    struct Animal* animal = (struct Animal*)malloc(sizeof(struct Animal));
    strcpy(animal->nume, nume);
    animal->varsta = varsta;
    animal->urmator = NULL;
    animal->precedent = NULL;
    return animal;
}

void afisareListaSimpla(struct Animal* cap)
{
    struct Animal* curent = cap;
    while (curent != NULL)
    {
        printf("nume: %s, varsta: %d\n", curent->nume, curent->varsta);
        curent = curent->urmator;
    }
}

void afisareListaDubla(struct Animal* cap)
{
    struct Animal* curent = cap;
    struct Animal* ultim = NULL;
    printf("inainte:\n");
    while (curent != NULL)
    {
        printf("nume: %s, varsta: %d\n", curent->nume, curent->varsta);
        ultim = curent;
        curent = curent->urmator;
    }
    printf("inapoi:\n");
    while (ultim != NULL)
    {
        printf("nume: %s, varsta: %d\n", ultim->nume, ultim->varsta);
        ultim = ultim->precedent;
    }
}

int main()
{
    struct Animal* ferma[3];
    ferma[0] = creareAnimal("vaca", 5);
    ferma[1] = creareAnimal("oaie", 3);
    ferma[2] = creareAnimal("porc", 2);

    struct Animal* capListaSimpla = ferma[0];
    ferma[0]->urmator = ferma[1];
    ferma[1]->urmator = ferma[2];

    printf("afisare lista simpla:\n");
    afisareListaSimpla(capListaSimpla);

    struct Animal* capListaDubla = ferma[0];
    ferma[0]->urmator = ferma[1];
    ferma[1]->precedent = ferma[0];
    ferma[1]->urmator = ferma[2];
    ferma[2]->precedent = ferma[1];

    printf("\nafisare lista dubla:\n");
    afisareListaDubla(capListaDubla);

    for (int i = 0; i < 3; i++) {
        free(ferma[i]);
    }

    return 0;
}
