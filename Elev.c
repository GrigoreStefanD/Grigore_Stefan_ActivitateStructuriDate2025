//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//
//
//struct Elev 
//{
//    int id;
//    int varsta;
//    char* nume;
//    float nota;
//};
//
//
//struct Elev initializareElev(int id, int varsta, const char* nume, float nota)
//
//{
//    struct Elev e;
//    e.id = id;
//    e.varsta = varsta;
//    e.nume = (char*)malloc((strlen(nume) + 1) * sizeof(char));
//    strcpy_s(e.nume, strlen(nume) + 1, nume);
//    e.nota = nota;
//    return e;
//}
//
//
//
//
//void afisareElev(struct Elev e) 
//{
//    printf("ID: %d, varsta: %d\n", e.id, e.varsta);
//    printf("Nume: %s\n", e.nume);
//    printf("Nota: %.2f\n", e.nota);
//}
//
//
//
//void afisareVectorElevi(struct Elev* vector, int nrElemente) 
//{
//    for (int i = 0; i < nrElemente; i++) 
//    {
//        afisareElev(vector[i]);
//        printf("\n");
//    }
//}
//
//
//float calculNotaMedie(struct Elev* elevi, int nrElemente) 
//{
//    float suma = 0;
//    for (int i = 0; i < nrElemente; i++) 
//    {
//        suma += elevi[i].nota;
//    }
//    return suma / nrElemente;
//}
//
//
//
//
//void inserareInVectorElevi(struct Elev** vector, int* dim, struct Elev e) 
//{
//    struct Elev* aux = (struct Elev*)malloc(sizeof(struct Elev) * ((*dim) + 1));
//    
//    for (int i = 0; i < *dim; i++) 
//    {
//        aux[i] = (*vector)[i];
//    }
//    aux[*dim] = e;
//    aux[*dim].nume = (char*)malloc(strlen(e.nume) + 1);
//    strcpy_s(aux[*dim].nume, strlen(e.nume) + 1, e.nume);
//    free(*vector);
//    *vector = aux;
//    (*dim)++;
//}
//
//
//
//void dezalocareElevi(struct Elev** vector, int* nrElemente) 
//{
//    for (int i = 0; i < *nrElemente; i++) 
//    {
//        free((*vector)[i].nume);
//    }
//    free(*vector);
//    *nrElemente = 0;
//    *vector = NULL;
//}
//
//
//
//
//struct Elev citireElevDinFisier(FILE* f) 
//{
//    struct Elev e;
//    char buffer[100];
//    char* aux;
//    char* next_token = NULL;
//
//    fgets(buffer, 100, f);
//    e.id = atoi(strtok_s(buffer, ",\n", &next_token));
//    e.varsta = atoi(strtok_s(NULL, ",\n", &next_token));
//    aux = strtok_s(NULL, ",\n", &next_token);
//    e.nume = (char*)malloc(strlen(aux) + 1);
//    strcpy_s(e.nume, strlen(aux) + 1, aux);
//    e.nota = atof(strtok_s(NULL, ",\n", &next_token));
//    return e;
//}
//
//
//struct Elev* citireVectorDinFisier(const char* numeFisier, int* dim) 
//{
//    FILE* f = fopen(numeFisier, "r");
//    struct Elev* vector = NULL;
//    *dim = 0;
//   
//    if (f != NULL) 
//    
//    {
//        while (!feof(f)) 
//        {
//            struct Elev e = citireElevDinFisier(f);
//            inserareInVectorElevi(&vector, dim, e);
//        }
//        fclose(f);
//    }
//    return vector;
//}
//
//
//struct Nod 
//{
//    struct Elev elev;
//    struct Nod* next;
//};
//
//
//void inserareListaSfarsit(struct Nod** cap, struct Elev e) 
//{
//    struct Nod* nou = (struct Nod*)malloc(sizeof(struct Nod));
//    nou->elev = e;
//    nou->elev.nume = (char*)malloc(strlen(e.nume) + 1);
//    strcpy_s(nou->elev.nume, strlen(e.nume) + 1, e.nume);
//    nou->next = NULL;
//   
//    if (*cap) 
//    {
//        struct Nod* p = *cap;
//        while (p->next != NULL) {
//            p = p->next;
//        }
//        p->next = nou;
//    }
//    else 
//    {
//        *cap = nou;
//    }
//}
//
//
//
//struct Nod* citireListaDinFisier(const char* numeFisier)
//{
//    struct Nod* cap = NULL;
//    FILE* f = fopen(numeFisier, "r");
//    
//    if (f != NULL) 
//    {
//        while (!feof(f)) 
//        {
//            struct Elev e = citireElevDinFisier(f);
//            inserareListaSfarsit(&cap, e);
//            free(e.nume);
//        }
//        fclose(f);
//    }
//    return cap;
//}
//
//
//
//void afisareLista(struct Nod* cap) 
//
//{
//    while (cap) 
//    {
//        afisareElev(cap->elev);
//        cap = cap->next;
//    }
//}
//
//
//void stergereLista(struct Nod** cap) 
//{
//    while ((*cap) != NULL) 
//    {
//        struct Nod* aux = *cap;
//        (*cap) = (*cap)->next;
//        free(aux->elev.nume);
//        free(aux);
//    }
//}
//
//int main() {
//    
//
//
//
//    struct Elev* elevi = NULL;
//    int nrElevi = 0;
//    elevi = citireVectorDinFisier("elevi.txt", &nrElevi);
//    afisareVectorElevi(elevi, nrElevi);
//
//    printf("nota medie: %.2f\n", calculNotaMedie(elevi, nrElevi));
//
//    
//
//
//    struct Nod* cap = citireListaDinFisier("elevi.txt");
//    afisareLista(cap);
//    stergereLista(&cap);
//    return 0;
//}
