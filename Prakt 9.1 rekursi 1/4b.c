#include "stdio.h"

int factorial(int);

int main() {
    int input;
    printf("Masukkan bilangan: ");
    scanf("%d", &input);
    printf("%d! = %d\n", input, factorial(input));
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}