//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//#include<stdlib.h>
//
//#define MAX_PRODUSE 100
//#define MAX_NUME 50
//
//struct Produs
//{
//    char nume[MAX_NUME];
//    double pret;
//    int stoc;
//};
//
//struct Magazin
//{
//    struct Produs produse[MAX_PRODUSE];
//    int numarProduse;
//};
//
//void adaugaProdus(struct Magazin* magazin, const char* nume, double pret, int stoc)
//{
//    if (magazin->numarProduse < MAX_PRODUSE)
//    {
//        struct Produs produsNou;
//        strncpy_s(produsNou.nume, MAX_NUME, nume, _TRUNCATE);
//        produsNou.pret = pret;
//        produsNou.stoc = stoc;
//
//        magazin->produse[magazin->numarProduse] = produsNou;
//        magazin->numarProduse++;
//        printf("Prod '%s' adaugat\n", nume);
//    }
//    else
//    {
//        printf("Magazin full\n");
//    }
//}
//
//void afiseazaProduse(const struct Magazin* magazin)
//{
//    printf("Prod magazin:\n");
//    for (int i = 0; i < magazin->numarProduse; i++)
//    {
//        printf("%d: %s - %.2f lei - Stoc: %d\n", i + 1, magazin->produse[i].nume, magazin->produse[i].pret, magazin->produse[i].stoc);
//    }
//}
//
//struct Produs* gasesteProdusDupaNume(struct Magazin* magazin, const char* nume) {
//    for (int i = 0; i < magazin->numarProduse; i++) {
//        if (strcmp(magazin->produse[i].nume, nume) == 0) {
//            return &magazin->produse[i];
//        }
//    }
//    return NULL;
//}
//
//void actualizeazaStoc(struct Magazin* magazin, const char* nume, int stocNou)
//{
//    struct Produs* produs = gasesteProdusDupaNume(magazin, nume);
//    if (produs != NULL)
//    {
//        produs->stoc = stocNou;
//        printf("Stocul produsului '%s' a fost actualizat la %d.\n", nume, stocNou);
//    }
//    else
//    {
//        printf("Produsul '%s' nu a fost găsit.\n", nume);
//    }
//}
//
//int main()
//{
//    struct Magazin magazin = { .numarProduse = 0 };
//    adaugaProdus(&magazin, "lapte", 5.99, 10);
//    adaugaProdus(&magazin, "pita", 3.49, 20);
//    adaugaProdus(&magazin, "oua", 12.99, 15);
//
//    afiseazaProduse(&magazin);
//
//    printf("\nCaut produsul 'pita':\n");
//    struct Produs* paine = gasesteProdusDupaNume(&magazin, "pita");
//    if (paine != NULL) {
//        printf("prod : %s - %.2f lei - Stoc: %d\n", paine->nume, paine->pret, paine->stoc);
//    }
//
//    return 0;
//}