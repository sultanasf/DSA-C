#include "stdio.h"

void printNum(int, int);

int main() {
    int batas, start = 0;
    printf("Masukkan batas: ");
    scanf("%d", &batas);
    printNum(start, batas);
}

void printNum(int num, int n) {
    if (num <= n) {
        printf("%d ", num);
        printNum(num + 1, n);
    } else {
        return;
    }
}