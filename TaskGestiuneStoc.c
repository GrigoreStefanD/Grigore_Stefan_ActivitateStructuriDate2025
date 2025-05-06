#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>
#include <string.h>


struct GestiuneStoc 

{
    int cod;
    char* denumire;
    int nrProduse;
    float* preturi;
};




struct GestiuneStoc citireGestiuneStoc() {
    struct GestiuneStoc gs;
    printf("Introduceti codul gestiunii ");
    scanf("%d", &gs.cod);

    char buffer[100];
    printf("Introduceti denumirea gestiunii ");
    scanf(" %[^\n]", buffer);
    gs.denumire = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(gs.denumire, buffer);

    printf("Introduceti nr prod ");
    scanf("%d", &gs.nrProduse);

    gs.preturi = (float*)malloc(gs.nrProduse * sizeof(float));
    for (int i = 0; i < gs.nrProduse; i++) {
        printf("Pretul produs %d ", i + 1);
        scanf("%f", &gs.preturi[i]);
    }

    return gs;
}




float calculMediePreturi(struct GestiuneStoc gs) {
    float suma = 0;
    for (int i = 0; i < gs.nrProduse; i++) {
        suma += gs.preturi[i];
    }
    return gs.nrProduse > 0 ? suma / gs.nrProduse : 0;
}




void modificaDenumire(struct GestiuneStoc* gs, const char* nouaDenumire) {
    free(gs->denumire);
    gs->denumire = (char*)malloc((strlen(nouaDenumire) + 1) * sizeof(char));
    strcpy(gs->denumire, nouaDenumire);
}




void afisareGestiuneStoc(struct GestiuneStoc gs) {
    printf("Cod   :  %d\n", gs.cod);
    printf("Denumire  :  %s\n", gs.denumire);
    printf("Numar produse :   %d\n", gs.nrProduse);
    printf("Preturi  : ");
    for (int i = 0; i < gs.nrProduse; i++) {
        printf("%.2f ", gs.preturi[i]);
    }
    printf("\n");
}






void elibereazaGestiuneStoc(struct GestiuneStoc* gs) {
    free(gs->denumire);
    free(gs->preturi);
}






struct GestiuneStoc* creareVector(int nrObiecte) {
    struct GestiuneStoc* vector = (struct GestiuneStoc*)malloc(nrObiecte * sizeof(struct GestiuneStoc));
    for (int i = 0; i < nrObiecte; i++) {
        printf("\nCitire gestiune stoc   %d\n", i + 1);
        vector[i] = citireGestiuneStoc();
    }
    return vector;
}






struct GestiuneStoc* filtruObiecte(struct GestiuneStoc* vector, int nrObiecte, int minProduse, int* nrNou) {
    *nrNou = 0;
    for (int i = 0; i < nrObiecte; i++) {
        if (vector[i].nrProduse >= minProduse) (*nrNou)++;
    }

    struct GestiuneStoc* nouVector = (struct GestiuneStoc*)malloc(*nrNou * sizeof(struct GestiuneStoc));
    int index = 0;
    for (int i = 0; i < nrObiecte; i++) {
        if (vector[i].nrProduse >= minProduse) {
            nouVector[index++] = vector[i];
        }
    }
    return nouVector;
}





void afisareVector(struct GestiuneStoc* vector, int nrObiecte) {
    for (int i = 0; i < nrObiecte; i++) {
        printf("\nGestiune Stoc %d:\n", i + 1);
        afisareGestiuneStoc(vector[i]);
    }
}





void salvareObiectFisier(const char* filename, struct GestiuneStoc gs) {
    FILE* file = fopen(filename, "a");
    fprintf(file, "%d %s %d ", gs.cod, gs.denumire, gs.nrProduse);
    for (int i = 0; i < gs.nrProduse; i++) {
        fprintf(file, "%.2f ", gs.preturi[i]);
    }
    fprintf(file, "\n");
    fclose(file);
}




struct GestiuneStoc* citireObiecteFisier(const char* filename, int* nrObiecte) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Eroare deschidere fisier\n");
        return NULL;
    }

    struct GestiuneStoc* vector = (struct GestiuneStoc*)malloc(10 * sizeof(struct GestiuneStoc));
    *nrObiecte = 0;

    while (!feof(file)) {
        struct GestiuneStoc gs;
        char buffer[100];
        fscanf(file, "%d %s %d", &gs.cod, buffer, &gs.nrProduse);
        gs.denumire = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(gs.denumire, buffer);
        gs.preturi = (float*)malloc(gs.nrProduse * sizeof(float));

        for (int i = 0; i < gs.nrProduse; i++) {
            fscanf(file, "%f", &gs.preturi[i]);
        }

        vector[(*nrObiecte)++] = gs;
    }
    fclose(file);
    return vector;
}









int main() {
    
    int nrGestiuni = 3;
    struct GestiuneStoc* gestiuni = creareVector(nrGestiuni);

    
    printf("\nLista gestiunilor initiale:\n");
    afisareVector(gestiuni, nrGestiuni);

    
    for (int i = 0; i < nrGestiuni; i++) {
        printf("Media preturilor pentru gestiunea %d: %.2f\n", i + 1, calculMediePreturi(gestiuni[i]));
    }





    printf("\nModificare denumire gestiune \n");
    modificaDenumire(&gestiuni[0], "Noua Denumire");
    afisareGestiuneStoc(gestiuni[0]);

 


    int nrFiltrate;
    struct GestiuneStoc* gestiuniFiltrate = filtruObiecte(gestiuni, nrGestiuni, 3, &nrFiltrate);
    printf("\nLista gestiunilor filtrate (minim 3 produse):\n");
    afisareVector(gestiuniFiltrate, nrFiltrate);

    


    const char* filename = "gestiuni.txt";
    printf("\nSalvare gestiuni in fisier\n");
    for (int i = 0; i < nrGestiuni; i++) {
        salvareObiectFisier(filename, gestiuni[i]);
    }




    
    int nrCitite;
    struct GestiuneStoc* gestiuniCitite = citireObiecteFisier(filename, &nrCitite);
    printf("\nLista gestiunilor citite din fisier   :\n");
    afisareVector(gestiuniCitite, nrCitite);







    for (int i = 0; i < nrGestiuni; i++) {
        elibereazaGestiuneStoc(&gestiuni[i]);
    }
    free(gestiuni);
    for (int i = 0; i < nrFiltrate; i++) {
        elibereazaGestiuneStoc(&gestiuniFiltrate[i]);
    }
    free(gestiuniFiltrate);
    for (int i = 0; i < nrCitite; i++) {
        elibereazaGestiuneStoc(&gestiuniCitite[i]);
    }
    free(gestiuniCitite);

    return 0;
}
