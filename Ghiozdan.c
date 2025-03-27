//
//
////// Task  Fisiere matrice si vetori
//
//
//
//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//
//#include <stdlib.h>
//#include <string.h>
//
//
//struct Ghiozdan
//{
//    int cod;
//    char* denumire;
//    int nrRechizite;
//    float* preturi;
//};
//
//
//struct Ghiozdan citireArticol() 
//{
//    struct Ghiozdan g;
//    g.denumire = (char*)malloc(50 * sizeof(char));
//    printf("cod: ");
//    scanf("%d", &g.cod);
//
//    printf("denumire: ");
//    scanf("%s", g.denumire);
//
//    printf("Nr rechizte: ");
//    scanf("%d", &g.nrRechizite);
//    g.preturi = (float*)malloc(g.nrRechizite * sizeof(float));
//
//
//    printf("preturi: ");
//    for (int i = 0; i < g.nrRechizite; i++) {
//        scanf("%f", &g.preturi[i]);
//    }
//
//    return g;
//}
//
//
//float calculeazaMediaPreturilor(struct Ghiozdan g) 
//
//{
//    float suma = 0;
//
//    for (int i = 0; i < g.nrRechizite; i++) 
//    {
//        suma += g.preturi[i];
//    }
//    return suma / g.nrRechizite;
//}
//
//
//void modificaDenumire(struct Ghiozdan* g, char* nouaDenumire) 
//{
//    free(g->denumire);
//
//    g->denumire = (char*)malloc(strlen(nouaDenumire) + 1);
//
//    strcpy(g->denumire, nouaDenumire);
//}
//
//
//void afiseazaArticol(struct Ghiozdan g) {
//    printf("Cod: %d\n", g.cod);
//    
//    printf("denumire: %s\n", g.denumire);
//   
//    printf("Nr rechizite: %d\n", g.nrRechizite);
//    
//    printf("Pret: ");
//    for (int i = 0; i < g.nrRechizite; i++) {
//        printf("%.2f ", g.preturi[i]);
//    }
//
//    printf("\n");
//}
//
//
//void elibereazaArticol(struct Ghiozdan* g) 
//{
//    free(g->denumire);
//    free(g->preturi);
//}
//
//
//
//void salveazaArticolInFisier(FILE* fisier, struct Ghiozdan g) 
//{
//    fprintf(fisier, "%d %s %d ", g.cod, g.denumire, g.nrRechizite);
//
//    for (int i = 0; i < g.nrRechizite; i++) 
//    {
//        fprintf(fisier, "%.2f ", g.preturi[i]);
//    }
//    fprintf(fisier, "\n");
//}
//
//
//struct Ghiozdan* citesteArticoleDinFisier(char* numeFisier, int* numar)
//{
//    FILE* fisier = fopen(numeFisier, "r");
//
//    if (!fisier)
//    {
//        printf("  eroare \n");
//        return NULL;
//    }
//
//    fscanf(fisier, "%d", numar);
//    struct Ghiozdan* vector = (struct Ghiozdan*)malloc((*numar) * sizeof(struct Ghiozdan));
//    for (int i = 0; i < *numar; i++) 
//    
//    {
//        vector[i].denumire = (char*)malloc(50 * sizeof(char));
//        fscanf(fisier, "%d %s %d", &vector[i].cod, vector[i].denumire, &vector[i].nrRechizite);
//        vector[i].preturi = (float*)malloc(vector[i].nrRechizite * sizeof(float));
//        
//        
//        for (int j = 0; j < vector[i].nrRechizite; j++)
//        
//        {
//            fscanf(fisier, "%f", &vector[i].preturi[j]);
//        }
//    }
//
//    fclose(fisier);
//
//
//    return vector;
//}
//
//
//struct Ghiozdan** copieazaInMatrice(struct Ghiozdan* vector, int numar, int* numarLinii) 
//{
//    *numarLinii = numar; 
//
//    struct Ghiozdan** matrice = (struct Ghiozdan**)malloc((*numarLinii) * sizeof(struct Ghiozdan*));
//
//    for (int i = 0; i < *numarLinii; i++) 
//    
//    {
//        matrice[i] = (struct Ghiozdan *)malloc(1 * sizeof(struct Ghiozdan)); 
//
//        matrice[i][0] = vector[i];
//    }
//
//    return matrice;
//}
//
//
//void afiseazaMatrice(struct Ghiozdan** matrice, int numarLinii)
//
//{
//    for (int i = 0; i < numarLinii; i++) 
//    {
//        printf("Linia %d:\n", i + 1);
//        for (int j = 0; j < 1; j++) 
//        
//        {
//            afiseazaArticol(matrice[i][j]);
//        }
//    }
//}
//
//
//int main() {
//    // 5 art
//    int n = 5;
//    struct Ghiozdan* vector = (struct Ghiozdan*)malloc(n * sizeof(struct Ghiozdan));
//
//
//
//    printf(" 5 articole:\n");
//    for (int i = 0; i < n; i++) 
//    {
//        vector[i] = citireArticol();
//    }
//
//
//
//    // fisier
//    FILE* fisier = fopen("articole.txt", "w");
//    fprintf(fisier, "%d\n", n);
//
//    for (int i = 0; i < n; i++) 
//    {
//        salveazaArticolInFisier(fisier, vector[i]);
//    }
//    fclose(fisier);
//
//    
//    int numarArticole;
//
//    struct Ghiozdan* articoleFisier = citesteArticoleDinFisier("articole.txt", &numarArticole);
//
//    int numarLinii;
//
//    struct Ghiozdan** matrice = copieazaInMatrice(articoleFisier, numarArticole, &numarLinii);
//
// 
//    printf("\nmatrice:\n");
//    afiseazaMatrice(matrice, numarLinii);
//
//
//    for (int i = 0; i < numarArticole; i++) 
//    {
//        elibereazaArticol(&articoleFisier[i]);
//    }
//    free(articoleFisier);
//
//
//
//    for (int i = 0; i < numarLinii; i++) 
//    {
//        free(matrice[i]);
//    }
//    free(matrice);
//
//
//
//    for (int i = 0; i < n; i++) 
//    {
//        elibereazaArticol(&vector[i]);
//    }
//    free(vector);
//
//
//
//    return 0;
//}
