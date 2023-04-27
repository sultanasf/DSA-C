#include <stdio.h>

int factorial(int n);

int permutation(int n, int r);

int combination(int n, int r);

int main() {
    int n, r;
    printf("Masukkan bilangan n: ");
    scanf("%d", &n);
    printf("Masukkan bilangan r: ");
    scanf("%d", &r);
    printf("%dP%d = %d\n", n, r, permutation(n, r));
    printf("%dC%d = %d\n", n, r, combination(n, r));
    return 0;
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int permutation(int n, int r) {
    return factorial(n) / factorial(n - r);
}

int combination(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}
