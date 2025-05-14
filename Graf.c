//#include <stdio.h>
//
//#define V 5
//
//struct Graf {
//    int matrice[V][V];
//};
//
//void afiseazaMatrice(struct Graf* g) {
//    for (int i = 0; i < V; i++) {
//        for (int j = 0; j < V; j++)
//            printf("%d ", g->matrice[i][j]);
//        printf("\n");
//    }
//}
//
//int main() {
//    struct Graf librarie = { {{0, 1, 0, 0, 1},
//                             {1, 0, 1, 1, 0},
//                             {0, 1, 0, 1, 1},
//                             {0, 1, 1, 0, 1},
//                             {1, 0, 1, 1, 0}} };
//
//    printf("Relatii autori-carti:\n");
//    afiseazaMatrice(&librarie);
//    return 0;
//}
