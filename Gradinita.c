//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//
//struct Copil 
//{
//    char nume[50];
//    int varsta;
//    char grupa[20];
//    char sex; 
//};
//
//
//struct Gradinita 
//{
//    char* nume;       
//    int nrCopii;
//    struct Copil* copii; 
//};
//
////de la taste
//struct Gradinita citireGradinita()
//
//{
//    struct Gradinita gradinita;
//    char buffer[100];
//
//
//    printf(" numele gradi: ");
//    scanf("%s", buffer);
//    gradinita.nume = (char*)malloc(strlen(buffer) + 1);
//    strcpy(gradinita.nume, buffer);
//
//
//    printf("Introduceti numarul de copii: ");
//    scanf("%d", &gradinita.nrCopii);
//
//
//
//    gradinita.copii = (struct Copil*)malloc(gradinita.nrCopii * sizeof(struct Copil));
//    for (int i = 0; i < gradinita.nrCopii; i++)
//    {
//        printf("Copil %d:\n", i + 1);
//        printf("  Nume: ");
//        scanf("%s", gradinita.copii[i].nume);
//        printf("  Varsta: ");
//        scanf("%d", &gradinita.copii[i].varsta);
//        printf("  Grupa: ");
//        scanf("%s", gradinita.copii[i].grupa);
//        printf("  Sex (m/f): ");
//        scanf(" %c", &gradinita.copii[i].sex); 
//    }
//
//    return gradinita;
//}
//
//
//
//void afiseazaGradinita(struct Gradinita gradinita)
//
//{
//    printf("numele gradi: %s\n", gradinita.nume);
//    printf("Nrr de copii: %d\n", gradinita.nrCopii);
//
//    for (int i = 0; i < gradinita.nrCopii; i++) 
//    
//    {
//        printf("Copil %d -    Nume: %s,  Varsta: %d,  Grupa: %s,  Sex: %c\n",
//            i + 1, gradinita.copii[i].nume, gradinita.copii[i].varsta,
//            gradinita.copii[i].grupa, gradinita.copii[i].sex);
//    }
//}
//
////trebuie m sau f pentru sex 
//void numaraCopiiDupaSex(struct Gradinita gradinita, int* baieti, int* fete) 
//
//{
//    *baieti = 0;
//    *fete = 0;
//   
//    for (int i = 0; i < gradinita.nrCopii; i++) 
//    {
//        if (gradinita.copii[i].sex == 'm') 
//        {
//            (*baieti)++;
//        }
//        
//        else if (gradinita.copii[i].sex == 'f') 
//        {
//            (*fete)++;
//        }
//    }
//}
//
//
//void modificaSexCopil(struct Gradinita* gradinita, int index, char sexNou)
//{
//    if (index >= 0 && index < gradinita->nrCopii) 
//    {
//        gradinita->copii[index].sex = sexNou;
//    }
//
//    else 
//    {
//        printf("nu e bun\n");
//    }
//}
//
//
//void elibereazaGradinita(struct Gradinita* gradinita)
//{
//    free(gradinita->nume);
//    free(gradinita->copii);
//}
//
//
//float calculeazaMediaVarste(struct Gradinita gradinita)
//{
//    int suma = 0;
//
//    for (int i = 0; i < gradinita.nrCopii; i++) 
//    {
//        suma += gradinita.copii[i].varsta;
//    }
//
//    return (float)suma / gradinita.nrCopii;
//}
//
//
//int main()
//
//{
//    struct Gradinita gradinita = citireGradinita();
//
//
//    printf("\nInfo gradi:\n");
//    afiseazaGradinita(gradinita);
//
//
//
//    printf("\nCalculam nr de copii dupa sex:\n");
//    int baieti, fete;
//    numaraCopiiDupaSex(gradinita, &baieti, &fete);
//    printf("Nr de baieti: %d, Nr de fete: %d\n", baieti, fete);
//
//
//    printf("\nCalc mdie varstei copiilor:\n");
//    float media = calculeazaMediaVarste(gradinita);
//    printf("media varstei copiilor: %.2f\n", media);
//
//
//    printf("\nmodificam sexul primului copil:\n");
//    modificaSexCopil(&gradinita, 0, 'F');
//    afiseazaGradinita(gradinita);
//
//
//    elibereazaGradinita(&gradinita);
//
//
//
//    return 0;
//}
