


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




int main()
{

    return 0;
}