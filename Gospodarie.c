//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define CAPACITATE 10 
//
//char* strdup(const char* s) 
//{
//    char* copy = (char*)malloc(strlen(s) + 1); 
//    if (copy) {
//        strcpy(copy, s); 
//    }
//    return copy;
//}
//
//struct Gospodarie 
//{
//    int nrPostal;
//    char* denumire;
//    int nrAnexe;
//    float* amprenta;
//};
//
//void eliberareGospodarie(struct Gospodarie* g) 
//{
//    free(g->denumire);
//    free(g->amprenta);
//}
//
//void citireGospodarie(struct Gospodarie* g) 
//{
//    printf("Introduceti numarul postal: ");
//    scanf("%d", &g->nrPostal);
//    getchar();
//    printf("Introduceti denumirea: ");
//    g->denumire = (char*)malloc(100 * sizeof(char));
//    if (g->denumire == NULL) {
//        printf("Eroare la alocarea memoriei pt denumire\n");
//        return;
//    }
//    fgets(g->denumire, 100, stdin);
//    g->denumire[strcspn(g->denumire, "\n")] = 0; 
//    printf("Introduceti numarul de anexe: ");
//    scanf("%d", &g->nrAnexe);
//    g->amprenta = (float*)malloc(g->nrAnexe * sizeof(float));
//    if (g->amprenta == NULL) {
//        printf("Eroare la alocarea memoriei pt amprenta\n");
//        free(g->denumire);
//        return;
//    }
//    printf("Introduceti amprentele: ");
//    for (int i = 0; i < g->nrAnexe; i++) {
//        scanf("%f", &g->amprenta[i]);
//    }
//}
//
//void afisareGospodarie(struct Gospodarie g) 
//{
//    printf("Nr Postal: %d\n", g.nrPostal);
//    printf("Denumire: %s\n", g.denumire);
//    printf("Nr Anexe: %d\n", g.nrAnexe);
//    for (int i = 0; i < g.nrAnexe; i++) {
//        printf("Amprenta %d: %.2f\n", i + 1, g.amprenta[i]);
//    }
//}
//
//void modificareGospodarie(struct Gospodarie* g, int nrAnexeNou) 
//{
//    float* temp = (float*)realloc(g->amprenta, nrAnexeNou * sizeof(float));
//    if (temp == NULL) {
//        printf("Eroare realocarea mem\n");
//        return;
//    }
//    g->amprenta = temp;
//    g->nrAnexe = nrAnexeNou;
//    printf("Introduceti noile amprente: ");
//    for (int i = 0; i < nrAnexeNou; i++) {
//        scanf("%f", &g->amprenta[i]);
//    }
//}
//
//void calculMedieAmprente(struct Gospodarie g) 
//{
//    float suma = 0;
//    for (int i = 0; i < g.nrAnexe; i++) {
//        suma += g.amprenta[i];
//    }
//    float medie = suma / g.nrAnexe;
//    printf("Media amprentelor: %.2f\n", medie);
//}
//
//void citireVectorDinFisier(struct Gospodarie* vector, int* n, const char* numeFisier)
//{
//    FILE* f = fopen(numeFisier, "r");
//    if (f == NULL) {
//        printf("Eroare deschiderea fisierului\n");
//        return;
//    }
//    *n = 0;
//    while (1) {
//        struct Gospodarie g;
//        if (fscanf(f, "%d", &g.nrPostal) != 1) break;
//        fgetc(f); // Consume newline left in buffer
//        g.denumire = (char*)malloc(100 * sizeof(char));
//        if (g.denumire == NULL) {
//            printf("Eroare alocarea memoriei pentru denumire\n");
//            continue;
//        }
//        fgets(g.denumire, 100, f);
//        g.denumire[strcspn(g.denumire, "\n")] = 0;
//        fscanf(f, "%d", &g.nrAnexe);
//        g.amprenta = (float*)malloc(g.nrAnexe * sizeof(float));
//        if (g.amprenta == NULL) {
//            printf("Eroare alocarea memoriei pentru amprenta\n");
//            free(g.denumire);
//            continue;
//        }
//        for (int i = 0; i < g.nrAnexe; i++) {
//            fscanf(f, "%f", &g.amprenta[i]);
//        }
//        vector[*n] = g;
//        (*n)++;
//    }
//    fclose(f);
//}
//
//void salvareGospodarieInFisier(struct Gospodarie g, FILE* f) 
//{
//    fprintf(f, "%d\n", g.nrPostal);
//    fprintf(f, "%s\n", g.denumire);
//    fprintf(f, "%d\n", g.nrAnexe);
//    for (int i = 0; i < g.nrAnexe; i++) {
//        fprintf(f, "%.2f\n", g.amprenta[i]);
//    }
//}
//
//void salvareVectorInFisier(struct Gospodarie* vector, int n, const char* numeFisier)
//{
//    FILE* f = fopen(numeFisier, "w");
//    if (f == NULL) {
//        printf("Eroare deschiderea fisierului\n");
//        return;
//    }
//    for (int i = 0; i < n; i++) {
//        salvareGospodarieInFisier(vector[i], f);
//    }
//    fclose(f);
//}
//
//struct Gospodarie* creareVector(int n) {
//    return (struct Gospodarie*)malloc(n * sizeof(struct Gospodarie));
//}
//
//void afisareVector(struct Gospodarie* vector, int n) {
//    for (int i = 0; i < n; i++) {
//        afisareGospodarie(vector[i]);
//    }
//}
//
//struct Muncitor {
//    int id;
//    float salariu;
//    char* functie;
//};
//
//struct HashTable {
//    struct Muncitor* tabela[CAPACITATE];
//};
//
//int functieHash(int salariu) {
//    return (int)salariu % CAPACITATE;
//}
//
//void adaugaMuncitor(struct HashTable* ht, struct Muncitor* m) {
//    int poz = functieHash(m->salariu);
//    ht->tabela[poz] = m;
//}
//
//void afiseazaMuncitoriDinSalariu(struct HashTable* ht, float salariu) {
//    int poz = functieHash(salariu);
//    if (ht->tabela[poz] != NULL) {
//        printf("Muncitor ID: %d, Salariu: %.2f, Functie: %s\n", ht->tabela[poz]->id, ht->tabela[poz]->salariu, ht->tabela[poz]->functie);
//    }
//}
//
//int main() 
//
//{
//    int n = 3;
//
//    struct Gospodarie* vector = creareVector(n);
//
//    for (int i = 0; i < n; i++) {
//        citireGospodarie(&vector[i]);
//    }
//    afisareVector(vector, n);
//
//    salvareVectorInFisier(vector, n, "gospodarii.txt");
//
//    int nCitit = 0;
//    struct Gospodarie* vectorCitit = creareVector(n);
//    citireVectorDinFisier(vectorCitit, &nCitit, "gospodarii.txt");
//
//    afisareVector(vectorCitit, nCitit);
//
//    struct Muncitor* m = (struct Muncitor*)malloc(sizeof(struct Muncitor));
//    if (m == NULL) {
//        printf("Eroare alocarea mem pt muncitor\n");
//        return -1;
//    }
//    m->id = 1;
//    m->salariu = 3000.50;
//    m->functie = _strdup("electrician");
//    if (m->functie == NULL) {
//        printf("Eroare alocarea memorie pt functi3e munncitor\n");
//        free(m);
//        return -1;
//    }
//
//    struct HashTable ht = { 0 }; 
//    adaugaMuncitor(&ht, m);
//    afiseazaMuncitoriDinSalariu(&ht, 3000.50);
//
//    for (int i = 0; i < n; i++) {
//        eliberareGospodarie(&vector[i]);
//    }
//    free(vector);
//    for (int i = 0; i < nCitit; i++) {
//        eliberareGospodarie(&vectorCitit[i]);
//    }
//    free(vectorCitit);
//
//
//    free(m->functie);
//    free(m);
//
//    return 0;
//}