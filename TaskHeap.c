#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP 100

struct Pacient {
    int id;
    int prioritate;
};




struct MinHeap {
    struct Pacient date[MAX_HEAP];
    int dimensiune;
};





void swap(struct Pacient* x, struct Pacient* y) {
    struct Pacient temp = *x;
    *x = *y;
    *y = temp;
}




void heapify(struct MinHeap* heap, int index) {
    int cel_mai_mic = index;
    int stanga = 2 * index + 1;
    int dreapta = 2 * index + 2;

    if (stanga < heap->dimensiune && heap->date[stanga].prioritate < heap->date[cel_mai_mic].prioritate)
        cel_mai_mic = stanga;
    if (dreapta < heap->dimensiune && heap->date[dreapta].prioritate < heap->date[cel_mai_mic].prioritate)
        cel_mai_mic = dreapta;
    if (cel_mai_mic != index) {
        swap(&heap->date[index], &heap->date[cel_mai_mic]);
        heapify(heap, cel_mai_mic);
    }
}

void insereaza(struct MinHeap* heap, int id, int prioritate) {
    if (heap->dimensiune >= MAX_HEAP) {
        printf("Spital plin\n");
        return;
    }
    int index = heap->dimensiune++;
    heap->date[index].id = id;
    heap->date[index].prioritate = prioritate;

    while (index > 0 && heap->date[(index - 1) / 2].prioritate > heap->date[index].prioritate) {
        swap(&heap->date[index], &heap->date[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

struct Pacient extrageMin(struct MinHeap* heap) {
    struct Pacient pacient_invalid = { -1, -1 };
    if (heap->dimensiune <= 0) return pacient_invalid;

    struct Pacient pacient = heap->date[0];
    heap->date[0] = heap->date[--heap->dimensiune];
    heapify(heap, 0);
    return pacient;
}

int main() {
    struct MinHeap spital = { .dimensiune = 0 };
    insereaza(&spital, 101, 2);
    insereaza(&spital, 102, 1);
    insereaza(&spital, 103, 3);
    printf("Pacient tratat: ID %d, Prioritate %d\n", extrageMin(&spital).id, extrageMin(&spital).prioritate);
    return 0;
}
