#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Gospodarie {
    int nrPostal;
    char* denumire;
    int nrAnexe;
    float* amprenta;
};

struct Gospodarie citireGospodarie() {
    struct Gospodarie g;
    printf("Nr postal: ");
    scanf("%d", &g.nrPostal);
    g.denumire = (char*)malloc(100 * sizeof(char));
    printf("denumirea: ");
    scanf(" %[^\n]", g.denumire);
    printf("nr de anexe: ");
    scanf("%d", &g.nrAnexe);
    g.amprenta = (float*)malloc(g.nrAnexe * sizeof(float));
    for (int i = 0; i < g.nrAnexe; i++) {
        printf("amprenta pt anexa %d: ", i + 1);
        scanf("%f", &g.amprenta[i]);
    }
    return g;
}

void afisareGospodarie(struct Gospodarie g) {
    printf("Nr postal: %d\n", g.nrPostal);
    printf("denumire: %s\n", g.denumire);
    printf("Nr anexe: %d\n", g.nrAnexe);
    for (int i = 0; i < g.nrAnexe; i++) {
        printf("amprenta anexa %d: %.2f\n", i + 1, g.amprenta[i]);
    }
}

float calculareMedieAmprenta(struct Gospodarie g) {
    float suma = 0;
    for (int i = 0; i < g.nrAnexe; i++) {
        suma += g.amprenta[i];
    }
    return suma / g.nrAnexe;
}

struct Gospodarie* creareVector(int n) {
    struct Gospodarie* vector = (struct Gospodarie*)malloc(n * sizeof(struct Gospodarie));
    return vector;
}

void citireVector(struct Gospodarie* vector, int n) {
    for (int i = 0; i < n; i++) {
        printf("Gospodaria %d:\n", i + 1);
        vector[i] = citireGospodarie();
    }
}

void afisareVector(struct Gospodarie* vector, int n) {
    for (int i = 0; i < n; i++) {
        printf("Gospodaria %d:\n", i + 1);
        afisareGospodarie(vector[i]);
    }
}

struct Gospodarie* filtrareVector(struct Gospodarie* vector, int* n, float valoare) {
    struct Gospodarie* filtrat = (struct Gospodarie*)malloc(*n * sizeof(struct Gospodarie));
    int k = 0;

    for (int i = 0; i < *n; i++) {
        float media = calculareMedieAmprenta(vector[i]);
        if (media > valoare) {
            filtrat[k++] = vector[i];
        }
    }

    *n = k;
    return filtrat;
}

void salvareGospodarieInFisier(struct Gospodarie g, FILE* f) {
    fprintf(f, "%d\n", g.nrPostal);
    fprintf(f, "%s\n", g.denumire);
    fprintf(f, "%d\n", g.nrAnexe);
    for (int i = 0; i < g.nrAnexe; i++) {
        fprintf(f, "%.2f\n", g.amprenta[i]);
    }
}

void salvareVectorInFisier(struct Gospodarie* vector, int n, const char* numeFisier) {
    FILE* f = fopen(numeFisier, "w");
    if (f == NULL) {
        printf("Eroare deschis\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        salvareGospodarieInFisier(vector[i], f);
    }
    fclose(f);
}

struct Gospodarie citireGospodarieDinFisier(FILE* f) {
    struct Gospodarie g;
    fscanf(f, "%d\n", &g.nrPostal);
    g.denumire = (char*)malloc(100 * sizeof(char));
    fscanf(f, "%[^\n]\n", g.denumire);
    fscanf(f, "%d\n", &g.nrAnexe);
    g.amprenta = (float*)malloc(g.nrAnexe * sizeof(float));
    for (int i = 0; i < g.nrAnexe; i++) {
        fscanf(f, "%f\n", &g.amprenta[i]);
    }
    return g;
}

void citireVectorDinFisier(struct Gospodarie* vector, int* n, const char* numeFisier) {
    FILE* f = fopen(numeFisier, "r");
    if (f == NULL) {
        printf("Eroare deschis\n");
        return;
    }

    *n = 0;
    while (!feof(f)) {
        vector[*n] = citireGospodarieDinFisier(f);
        (*n)++;
    }
    fclose(f);
}

int main() {
    int n = 5;
    struct Gospodarie* vector = creareVector(n);

    citireVector(vector, n);
    afisareVector(vector, n);

    salvareVectorInFisier(vector, n, "gospodarii.txt");

    struct Gospodarie* vectorCitit = creareVector(n);
    citireVectorDinFisier(vectorCitit, &n, "gospodarii.txt");

    afisareVector(vectorCitit, n);

    float valoare;
    printf("valoarea pt filtrare: ");
    scanf("%f", &valoare);

    struct Gospodarie* vectorFiltrat = filtrareVector(vector, &n, valoare);
    printf("Vec filtrat:\n");
    afisareVector(vectorFiltrat, n);

    free(vector);
    free(vectorCitit);
    free(vectorFiltrat);

    return 0;
}
