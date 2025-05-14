#define  _CRT_SECURE_NO_WARNINGS



#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct Student {
    char nume[50];
    struct Student* stanga, * dreapta;
};





struct Student* creeazaStudent(char nume[]) {
    struct Student* nou = (struct Student*)malloc(sizeof(struct Student));
    strcpy(nou->nume, nume);
    nou->stanga = nou->dreapta = NULL;
    return nou;
}




struct Student* insereaza(struct Student* radacina, char nume[]) 
{
    if (radacina == NULL)
        return creeazaStudent(nume);
    if (strcmp(nume, radacina->nume) < 0)
        radacina->stanga = insereaza(radacina->stanga, nume);
    else if (strcmp(nume, radacina->nume) > 0)
        radacina->dreapta = insereaza(radacina->dreapta, nume);
    return radacina;
}




void inordine(struct Student* radacina) 
{
    if (radacina != NULL) {
        inordine(radacina->stanga);
        printf("%s ", radacina->nume);
        inordine(radacina->dreapta);
    }
}

int main() 
{
    struct Student* radacina = NULL;
    radacina = insereaza(radacina, "Ana");
    insereaza(radacina, "Bogdan");
    insereaza(radacina, "Cristina");
    insereaza(radacina, "David");


    printf("Studenti ordonati: ");

    inordine(radacina);
    printf("\n");

    return 0;
}
