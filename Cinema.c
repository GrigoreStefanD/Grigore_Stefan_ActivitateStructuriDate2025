//#define _CRT_SECURE_NO_WARNINGS 
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//
//
//struct Sala
//{
//    int numar_sala;
//    int locuri_disponibile;
//    char tip_sala[30]; 
//    int capacitate_maxima;
//};
//
//
//
//struct Cinema 
//{
//    char nume[50];
//    char locatie[100];
//    int numar_sali;
//    struct Sala* sali;
//};
//
//
//
//struct Cinema* creeazaCinema(char* nume, char* locatie, int numar_sali);
//
//void adaugaSala(struct Cinema* cinema, int index, int numar_sala, int locuri_disponibile, char* tip_sala, int capacitate_maxima);
//
//void afiseazaCinema(struct Cinema* cinema);
//
//void elibereazaCinema(struct Cinema* cinema);
//
//
//
//
//
//int* creeazaVector(int dimensiune);
//
//void afiseazaVector(int* vector, int dimensiune);
//
//void elibereazaVector(int* vector);
//
//
//
//
//int** creeazaMatrice(int randuri, int coloane);
//void afiseazaMatrice(int** matrice, int randuri, int coloane);
//void elibereazaMatrice(int** matrice, int randuri);
//
//
//
//struct Nod 
//
//{
//    int date;
//    struct Nod* urmator;
//};
//
//
//
//struct Nod* creeazaNod(int date);
//
//void adaugaNod(struct Nod** cap, int date);
//void afiseazaLista(struct Nod* cap);
//void insereazaLaInceput(struct Nod** cap, int date);
//void stergeNod(struct Nod** cap, int cheie);
//
//
//
//
//struct Cinema* creeazaCinema(char* nume, char* locatie, int numar_sali)
//{
//    struct Cinema* nouCinema = (struct Cinema*)malloc(sizeof(struct Cinema));
//    strcpy(nouCinema->nume, nume);
//    strcpy(nouCinema->locatie, locatie);
//    nouCinema->numar_sali = numar_sali;
//    nouCinema->sali = (struct Sala*)malloc(numar_sali * sizeof(struct Sala));
//    return nouCinema;
//}
//
//
//void adaugaSala(struct Cinema* cinema, int index, int numar_sala, int locuri_disponibile, char* tip_sala, int capacitate_maxima)
//{
//    if (index < cinema->numar_sali) 
//    {
//        struct Sala nouaSala = { numar_sala, locuri_disponibile, "", capacitate_maxima };
//        strcpy(nouaSala.tip_sala, tip_sala);
//        cinema->sali[index] = nouaSala;
//    }
//}
//
//
//
//
//void afiseazaCinema(struct Cinema* cinema) 
//{
//    printf("cinema: %s\n", cinema->nume);
//    printf("locatie: %s\n", cinema->locatie);
//    printf("mr de sala: %d\n", cinema->numar_sali);
//    for (int i = 0; i < cinema->numar_sali; i++)
//    {
//        printf("sala %d: %d loc disponibil, tip: %s, cap max: %d\n", cinema->sali[i].numar_sala, cinema->sali[i].locuri_disponibile, cinema->sali[i].tip_sala, cinema->sali[i].capacitate_maxima);
//    }
//}
//
//
//void elibereazaCinema(struct Cinema* cinema)
//{
//    free(cinema->sali);
//    free(cinema);
//}
//
//
//
//int* creeazaVector(int dimensiune)
//{
//    int* vector = (int*)malloc(dimensiune * sizeof(int));
//    for (int i = 0; i < dimensiune; i++) 
//    {
//        vector[i] = i + 1;
//    }
//    return vector;
//}
//
//void afiseazaVector(int* vector, int dimensiune)
//{
//    printf("Vector: ");
//    for (int i = 0; i < dimensiune; i++) 
//    {
//        printf("%d ", vector[i]);
//    }
//    printf("\n");
//}
//
//void elibereazaVector(int* vector) 
//{
//    free(vector);
//}
//
//
//
//
//int** creeazaMatrice(int randuri, int coloane)
//{
//    int** matrice = (int**)malloc(randuri * sizeof(int*));
//    for (int i = 0; i < randuri; i++) 
//    {
//        matrice[i] = (int*)malloc(coloane * sizeof(int));
//        for (int j = 0; j < coloane; j++) 
//        {
//            matrice[i][j] = i * coloane + j + 1;
//        }
//    }
//    return matrice;
//}
//
//void afiseazaMatrice(int** matrice, int randuri, int coloane)
//{
//    printf("Matrice:\n");
//    for (int i = 0; i < randuri; i++) 
//    {
//        for (int j = 0; j < coloane; j++)
//        {
//            printf("%d ", matrice[i][j]);
//        }
//        printf("\n");
//    }
//}
//
//void elibereazaMatrice(int** matrice, int randuri) 
//
//{
//    for (int i = 0; i < randuri; i++) 
//    {
//        free(matrice[i]);
//    }
//    free(matrice);
//}
//
//
//
//
//struct Nod* creeazaNod(int date) 
//{
//    struct Nod* nouNod = (struct Nod*)malloc(sizeof(struct Nod));
//    nouNod->date = date;
//    nouNod->urmator = NULL;
//    return nouNod;
//}
//
//void adaugaNod(struct Nod** cap, int date) 
//{
//    struct Nod* nouNod = creeazaNod(date);
//    if (*cap == NULL) 
//    {
//        *cap = nouNod;
//        return;
//    }
//
//    struct Nod* temp = *cap;
//    while (temp->urmator != NULL) 
//    {
//
//        temp = temp->urmator;
//    }
//
//    temp->urmator = nouNod;
//}
//
//void afiseazaLista(struct Nod* cap) 
//{
//    struct Nod* temp = cap;
//    while (temp != NULL) {
//        printf("%d -> ", temp->date);
//        temp = temp->urmator;
//    }
//    printf("NULL\n");
//}
//
//void insereazaLaInceput(struct Nod** cap, int date) 
//
//{
//    struct Nod* nouNod = creeazaNod(date);
//    nouNod->urmator = *cap;
//    *cap = nouNod;
//}
//
//void stergeNod(struct Nod** cap, int cheie)
//{
//    struct Nod* temp = *cap;
//    struct Nod* prev = NULL;
//    if (temp != NULL && temp->date == cheie) {
//        *cap = temp->urmator;
//        free(temp);
//        return;
//    }
//    while (temp != NULL && temp->date != cheie) {
//        prev = temp;
//        temp = temp->urmator;
//    }
//    if (temp == NULL) return;
//    prev->urmator = temp->urmator;
//    free(temp);
//}
//
//int main()
//
//{
//
//
//    struct Cinema* cinema = creeazaCinema("veranda", "str obor, buc", 3);
//
//
//    adaugaSala(cinema, 0, 1, 100, "imaxxx", 120);
//    adaugaSala(cinema, 1, 2, 150, "3d", 180);
//    adaugaSala(cinema, 2, 3, 200, "baza", 220);
//
//
//
//    afiseazaCinema(cinema);
//
//
//
//    int dimensiuneVector = 5;
//    int* vector = creeazaVector(dimensiuneVector);
//    afiseazaVector(vector, dimensiuneVector);
//    elibereazaVector(vector);
//
//
//
//
//    int randuri = 3;
//    int coloane = 3;
//    int** matrice = creeazaMatrice(randuri, coloane);
//    afiseazaMatrice(matrice, randuri, coloane);
//    elibereazaMatrice(matrice, randuri);
//
//
//
//    struct Nod* listaSimpla = NULL;
//    adaugaNod(&listaSimpla, 10);
//    adaugaNod(&listaSimpla, 20);
//    adaugaNod(&listaSimpla, 30);
//    printf("lista simpla: ");
//    afiseazaLista(listaSimpla);
//
//    insereazaLaInceput(&listaSimpla, 5);
//    printf("ls dupa inserare la iceput: ");
//    afiseazaLista(listaSimpla);
//
//    stergeNod(&listaSimpla, 20);
//    printf("ls dupa delete nod cu val 20   ");
//    afiseazaLista(listaSimpla);
//
//
//
//    elibereazaCinema(cinema);
//
//    return 0;
//}