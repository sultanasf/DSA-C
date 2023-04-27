#include <stdio.h>
#include <math.h>

int isPrime(int n, int i) {
    if (n <= 2) {
        return (n == 2) ? 1 : 0;
    }
    if (i > sqrt(n)) {
        return 1;
    }
    if (n % i == 0) {
        return 0;
    }
    return isPrime(n, i + 1);
}

int main() {
    int n;
    printf("Masukkan sebuah bilangan bulat positif: ");
    scanf("%d", &n);
    if (isPrime(n, 2)) {
        printf("%d adalah bilangan prima.\n", n);
    } else {
        printf("%d bukan bilangan prima.\n", n);
    }
    return 0;
}
