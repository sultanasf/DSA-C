#include "stdio.h"

int factorial(int, int);

int main() {
    int input, start = 1;
    printf("Masukkan bilangan: ");
    scanf("%d", &input);
    printf("%d! = %d\n", input, factorial(input, start));
}

int factorial(int n, int sum) {
    if (n == 0)
        return sum;
    else {
        return factorial(n - 1, n * sum);
    }
}