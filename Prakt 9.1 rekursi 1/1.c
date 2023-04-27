#include "stdio.h"

void printNum(int);

int main() {
    int batas;
    printf("Masukkan batas: ");
    scanf("%d", &batas);
    printNum(batas);
}

void printNum(int n) {
    if (n >= 0) {
        printf("%d ", n);
        printNum(n - 1);
    } else {
        return;
    }
}