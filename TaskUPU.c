//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define NUME_MAX 50
//#define MAX_HEAP_SIZE 100
//
//
//
//
//struct Pacient {
//    char nume[NUME_MAX];
//    int varsta;
//    int gradUrgenta;
//};
//
//
//
//
//
//void swap(struct Pacient* a, struct Pacient* b) {
//    struct Pacient temp = *a;
//    *a = *b;
//    *b = temp;
//}
//
//void heapify(struct Pacient heap[], int n, int i) {
//    int largest = i;
//    int st = 2 * i + 1;
//    int dr = 2 * i + 2;
//
//    if (st < n && heap[st].gradUrgenta > heap[largest].gradUrgenta)
//        largest = st;
//    if (dr < n && heap[dr].gradUrgenta > heap[largest].gradUrgenta)
//        largest = dr;
//
//    if (largest != i) {
//        swap(&heap[i], &heap[largest]);
//        heapify(heap, n, largest);
//    }
//}
//
//void adaugaPacient(struct Pacient heap[], int* dimensiune, struct Pacient p) {
//    if (*dimensiune >= MAX_HEAP_SIZE) {
//        printf("Heap-ul este plin!\n");
//        return;
//    }
//
//    heap[*dimensiune] = p;
//    int i = *dimensiune;
//    (*dimensiune)++;
//
//    while (i > 0 && heap[(i - 1) / 2].gradUrgenta < heap[i].gradUrgenta) {
//        swap(&heap[i], &heap[(i - 1) / 2]);
//        i = (i - 1) / 2;
//    }
//}
//
//struct Pacient extragePacientUrgent(struct Pacient heap[], int* dimensiune) {
//    if (*dimensiune <= 0) {
//        struct Pacient gol = { "Nimeni", 0, -1 };
//        return gol;
//    }
//
//    struct Pacient radacina = heap[0];
//    heap[0] = heap[*dimensiune - 1];
//    (*dimensiune)--;
//
//    heapify(heap, *dimensiune, 0);
//    return radacina;
//}
//
//void afiseazaHeap(struct Pacient heap[], int dimensiune) {
//    printf("\n--- Pacienti in asteptare ---\n");
//    for (int i = 0; i < dimensiune; i++)
//
//    {
//        printf("%s, %d ani, grad urgenta: %d\n",
//            heap[i].nume, heap[i].varsta, heap[i].gradUrgenta);
//    }
//}
//
//
//
//
//
//int main() {
//    struct Pacient heap[MAX_HEAP_SIZE];
//    int dimensiune = 0;
//    int optiune;
//
//
//
//    do {
//        printf("\n_______ MENIU UPU ______\n");
//        printf("1. Adauga pacient\n");
//        printf("2. Preia pacient urgent\n");
//        printf("3. Afiseaza pacienti in asteptare\n");
//        printf("0. Iesire\n");
//        printf("Optiune: ");
//        scanf("%d", &optiune);
//
//        if (optiune == 1) {
//            struct Pacient p;
//            printf("Nume: ");
//            getchar();
//            fgets(p.nume, NUME_MAX, stdin);
//            p.nume[strcspn(p.nume, "\n")] = '\0';
//            printf("varsta: ");
//            scanf("%d", &p.varsta);
//            printf("grad urgenta (1 - 10): ");
//            scanf("%d", &p.gradUrgenta);
//
//            adaugaPacient(heap, &dimensiune, p);
//            printf("Pacient adaugat cu scces\n");
//
//        }
//        else if (optiune == 2) {
//            struct Pacient urgent = extragePacientUrgent(heap, &dimensiune);
//            if (urgent.gradUrgenta == -1) {
//                printf("nu exista pacienti in asteptare\n");
//            }
//            else {
//                printf("PRELUAT: %s, %d ani, grad urgenta: %d\n",
//                    urgent.nume, urgent.varsta, urgent.gradUrgenta);
//            }
//
//        }
//        else if (optiune == 3) {
//            afiseazaHeap(heap, dimensiune);
//        }
//
//    } while (optiune != 0);
//
//
//
//    printf("aplicatia s-a inchis\n");
//    return 0;
//}
