#include "stdio.h"

int factorial(int);

int main() {
    int input;
    printf("Masukkan bilangan: ");
    scanf("%d", &input);
    printf("%d! = %d\n", input, factorial(input));
}

int factorial(int n) {
    int i, fact = 1;
    for (i = n; i > 0; i--) {
        fact *= i;
    }
    return fact;
}