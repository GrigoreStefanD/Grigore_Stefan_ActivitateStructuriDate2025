 //Curs din 22.03.2024






#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct StructuraMasina {
    int id;
    int nrUsi;
    float pret;
    char* model;
    char* numeSofer;
    unsigned char serie;
};
typedef struct StructuraMasina Masina;

struct Nod {
    Masina info;
    struct Nod* next;
};
typedef struct Nod Nod;

struct HashTable {
    int dim;
    Nod** vector;
};
typedef struct HashTable HashTable;

Masina citireMasinaDinFisier(FILE* file) {
    char buffer[100];
    char sep[3] = ",\n";
    if (fgets(buffer, sizeof(buffer), file) == NULL) {
        Masina m = { -1, 0, 0.0f, NULL, NULL, 0 };
        return m;  
    }

    Masina m1;
    char* aux = strtok(buffer, sep);
    m1.id = atoi(aux);
    m1.nrUsi = atoi(strtok(NULL, sep));
    m1.pret = atof(strtok(NULL, sep));
    aux = strtok(NULL, sep);
    m1.model = malloc(strlen(aux) + 1);
    if (m1.model != NULL) strcpy_s(m1.model, strlen(aux) + 1, aux);

    aux = strtok(NULL, sep);
    m1.numeSofer = malloc(strlen(aux) + 1);
    if (m1.numeSofer != NULL) strcpy_s(m1.numeSofer, strlen(aux) + 1, aux);

    m1.serie = *strtok(NULL, sep);
    return m1;
}

void afisareMasina(Masina masina) {
    if (masina.id == -1) {
        printf("Masina invalida!\n");
        return;
    }
    printf("Id: %d\n", masina.id);
    printf("Nr. usi : %d\n", masina.nrUsi);
    printf("Pret: %.2f\n", masina.pret);
    printf("Model: %s\n", masina.model);
    printf("Nume sofer: %s\n", masina.numeSofer);
    printf("Serie: %c\n\n", masina.serie);
}

void afisareListaMasini(Nod* cap) {
    while (cap) {
        afisareMasina(cap->info);
        cap = cap->next;
    }
}

void adaugaMasinaInLista(Nod** cap, Masina masinaNoua) {
    Nod* nou = (Nod*)malloc(sizeof(Nod));
    if (nou == NULL) {
        printf("Eroare aloc mem\n");
        exit(1);
    }
    nou->info = masinaNoua;
    nou->next = *cap;
    *cap = nou;
}

HashTable initializareHashTable(int dimensiune) {
    HashTable ht;
    ht.vector = (Nod**)malloc(sizeof(Nod*) * dimensiune);
    if (ht.vector == NULL) {
        printf("Eroare alocarea mem pt tabela dispersie!\n");
        exit(1);
    }
    for (int i = 0; i < dimensiune; i++) {
        ht.vector[i] = NULL;
    }
    ht.dim = dimensiune;
    return ht;
}

int calculeazaHash(const char* numeSofer, int id, int dimensiune) {
    int suma = 0;
    for (int i = 0; i < strlen(numeSofer); i++) {
        suma += numeSofer[i];
    }
    suma *= 17;
    return (dimensiune > 0 ? (suma % dimensiune) : -1);
}

void inserareMasinaInTabela(HashTable hash, Masina masina) {
    int pozitie = calculeazaHash(masina.numeSofer, masina.id, hash.dim);
    if (pozitie >= 0 && pozitie < hash.dim) {
        adaugaMasinaInLista(&(hash.vector[pozitie]), masina);
    }
}

HashTable citireMasiniDinFisier(const char* numeFisier, int dimensiune) {
    HashTable ht = initializareHashTable(dimensiune);
    FILE* file = fopen(numeFisier, "r");
    if (file == NULL) {
        printf("Eroare la deschidefisierului!\n");
        exit(1);
    }

    while (!feof(file)) {
        Masina m = citireMasinaDinFisier(file);
        if (m.id != -1) {
            inserareMasinaInTabela(ht, m);
        }
    }
    fclose(file);
    return ht;
}

void afisareTabelaDeMasini(HashTable ht) {
    for (int i = 0; i < ht.dim; i++) {
        if (ht.vector[i] != NULL) {
            printf("\nCluster %d:\n", i);
            afisareListaMasini(ht.vector[i]);
        }
    }
}

void stergeLista(Nod** cap) {
    while (*cap) {
        Nod* p = *cap;
        *cap = p->next;
        if (p->info.model != NULL) {
            free(p->info.model);
        }
        if (p->info.numeSofer != NULL) {
            free(p->info.numeSofer);
        }
        free(p);
    }
}

void dezalocareTabelaDeMasini(HashTable* ht) {
    for (int i = 0; i < ht->dim; i++) {
        stergeLista(&(ht->vector[i]));
    }
    free(ht->vector);
    ht->vector = NULL;
    ht->dim = 0;
}

float calculeazaPretMediuLista(Nod* cap) {
    if (cap == NULL) return 0.0f;
    float suma = 0;
    int contor = 0;
    while (cap) {
        suma += cap->info.pret;
        contor++;
        cap = cap->next;
    }
    return suma / contor;
}

float** calculeazaPreturiMediiPerClustere(HashTable ht, int* nrClustere) {
    *nrClustere = 0;
    for (int i = 0; i < ht.dim; i++) {
        if (ht.vector[i] != NULL) {
            (*nrClustere)++;
        }
    }

    float** medii = (float**)malloc(sizeof(float*) * 2);
    if (medii == NULL) {
        printf("Eroare la alocarea memoriei pentru matrice!\n");
        exit(1);
    }
    medii[0] = (float*)malloc(sizeof(float) * (*nrClustere));
    medii[1] = (float*)malloc(sizeof(float) * (*nrClustere));
    if (medii[0] == NULL || medii[1] == NULL) {
        printf("Eroare la alocarea memoriei pentru matrice!\n");
        exit(1);
    }

    int index = 0;
    for (int i = 0; i < ht.dim; i++) {
        if (ht.vector[i] != NULL) {
            medii[0][index] = i;
            medii[1][index] = calculeazaPretMediuLista(ht.vector[i]);
            index++;
        }
    }
    return medii;
}

void afisarePreturiMediiImbunatatita(float** matrice, int nrClustere) {
    printf("Cluster Id | Pret Mediu\n");
    for (int i = 0; i < nrClustere; i++) {
        printf("    %d      | %.2f\n", (int)matrice[0][i], matrice[1][i]);
    }
}

void dezalocareMatrice(float*** matrice, int* nrLinii, int* nrColoane) {
    for (int i = 0; i < *nrLinii; i++) {
        free((*matrice)[i]);
    }
    free(*matrice);
    *matrice = NULL;
    *nrLinii = 0;
    *nrColoane = 0;
}

Masina getMasinaDupaSoferSiID(HashTable ht, const char* numeSofer, int id) {
    for (int i = 0; i < ht.dim; i++) {
        Nod* current = ht.vector[i];
        while (current != NULL) {
            if (current->info.id == id && strcmp(current->info.numeSofer, numeSofer) == 0) {
                return current->info;
            }
            current = current->next;
        }
    }
    Masina m = { -1, 0, 0.0f, NULL, NULL, 0 };
    return m;  
}

int main() {
    HashTable ht = citireMasiniDinFisier("masini.txt", 6);
    afisareTabelaDeMasini(ht);

    Masina m = getMasinaDupaID(ht, 6);
    if (m.id != -1) {
        printf("Masina cautata dupa id:\n");
        afisareMasina(m);
    }

    Masina mSofer = getMasinaDupaSoferSiID(ht, "Ionescu", 9);
    if (mSofer.id != -1) {
        printf("\nMasina cautata dupa sofer si ID:\n");
        afisareMasina(mSofer);
    }

    printf("Preturi medii pe clustere:\n");
    int nrClustere = 0;
    float** matrice = calculeazaPreturiMediiPerClustere(ht, &nrClustere);
    afisarePreturiMediiImbunatatita(matrice, nrClustere);

    dezalocareTabelaDeMasini(&ht);
    dezalocareMatrice(&matrice, &nrClustere, &nrClustere);

    return 0;
}