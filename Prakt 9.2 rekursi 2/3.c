#include "stdio.h"

int fibonacci(int);

int main() {
    int n, i;
    printf("Masukkan jumlah bilangan Fibonacci yang ingin ditampilkan: ");
    scanf("%d", &n);
    printf("Deret bilangan Fibonacci sebanyak %d:\n", n);
    for (i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
    return 0;
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}