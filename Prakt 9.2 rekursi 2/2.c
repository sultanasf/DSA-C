#include "stdio.h"

void fibonacci(int);

int main() {
    int n;
    printf("Masukkan jumlah bilangan dalam deret Fibonacci: ");
    scanf("%d", &n);
    fibonacci(n);
}

void fibonacci(int n) {
    int i, t1 = 0, t2 = 1, next;
    printf("Deret Fibonacci sebanyak %d bilangan:\n", n);
    for (i = 1; i <= n; i++) {
        printf("%d ", t1);
        next = t1 + t2;
        t1 = t2;
        t2 = next;
    }
}