#include "stdio.h"

int fpb(int, int);

int main() {
    int a, b;
    char repeat;
    do {
        printf("Input bilangan pertama: ");
        scanf("%d", &a);
        printf("Input bilangan kedua: ");
        scanf("%d", &b);
        int result = fpb(a, b);
        printf("FPB dari %d dan %d adalah %d\n", a, b, result);
        printf("Apakah ingin mengulang? (y/t) ");
        scanf(" %c", &repeat);
        fflush(stdin);
    } while (repeat == 'y' || repeat == 'Y');
}

int fpb(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return fpb(b, a % b);
    }
}