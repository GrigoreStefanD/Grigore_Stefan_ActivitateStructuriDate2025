//
//
//
//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAX 100
//
//
//
//struct Carte {
//    char titlu[50];
//};
//
//
//struct Stiva {
//    struct Carte elemente[MAX];
//    int top;
//};
//
//
//
//void push(struct Stiva* s, char titlu[]) {
//    if (s->top == MAX - 1) {
//        printf("stiva este plina\n");
//        return;
//    }
//    s->top++;
//    strcpy(s->elemente[s->top].titlu, titlu);
//}
//
//
//
//struct Carte pop(struct Stiva* s) {
//    struct Carte carte_goala = { "" };
//    if (s->top == -1) {
//        printf("Stiva este goala\n");
//        return carte_goala;
//    }
//    return s->elemente[s->top--];
//}
//
//
//
//
//
//
//int main() 
//
//{
//    struct Stiva istoric;
//    
//    istoric.top = -1;
//
//
//
//    push(&istoric, "crima si pedeapsa");
//    push(&istoric, "1984");
//    push(&istoric, "Moby Dick");
//
//
//
//    printf("ultima carte citita: %s\n", pop(&istoric).titlu);
//    return 0;
//}
