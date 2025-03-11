

#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

struct Animal
{
    char nume[50];
    int varsta;
    struct Animal* urmator; // pentru lista simpl?
    struct Animal* precedent; // pentru lista dubl?
};

void afisareListaSimpla(struct Animal* cap) {
    struct Animal* curent = cap;
    while (curent != NULL) {
        printf("Nume: %s, varsta: %d\n", curent->nume, curent->varsta);
        curent = curent->urmator;
    }
}



int main()
{

	return 0;
}
