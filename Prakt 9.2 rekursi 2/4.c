#include <stdio.h>

void fibonacciIterative(int n) {
    int i, t1 = 0, t2 = 1, nextTerm;
    printf("Deret Fibonacci sebanyak %d:\n", n);
    for (i = 0; i < n; i++) {
        printf("%d ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    printf("\n");
}

int fibonacciRecursive(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
    }
}

int fibonacciTailRecursiveHelper(int n, int t1, int t2) {
    if (n == 0) {
        return t1;
    } else if (n == 1) {
        return t2;
    } else {
        return fibonacciTailRecursiveHelper(n-1, t2, t1+t2);
    }
}

void fibonacciTailRecursive(int n) {
    int result = fibonacciTailRecursiveHelper(n, 0, 1);
    printf("Deret Fibonacci sebanyak %d:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", result);
        result = fibonacciTailRecursiveHelper(i+1, 0, 1);
    }
    printf("\n");
}

void menu() {
    int n, choice;
    do {
        printf("\n");
        printf("Pilih metode perhitungan deret Fibonacci:\n");
        printf("1. Iterasi\n");
        printf("2. Rekursi\n");
        printf("3. Rekursi ekor (tail recursion)\n");
        printf("0. Keluar\n");
        printf("Pilihan anda: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Masukkan jumlah bilangan Fibonacci yang ingin ditampilkan: ");
                scanf("%d", &n);
                fibonacciIterative(n);
                break;
            case 2:
                printf("Masukkan jumlah bilangan Fibonacci yang ingin ditampilkan: ");
                scanf("%d", &n);
                printf("Deret Fibonacci sebanyak %d:\n", n);
                for (int i = 0; i < n; i++) {
                    printf("%d ", fibonacciRecursive(i));
                }
                printf("\n");
                break;
            case 3:
                printf("Masukkan jumlah bilangan Fibonacci yang ingin ditampilkan: ");
                scanf("%d", &n);
                fibonacciTailRecursive(n);
                break;
            case 0:
                printf("Terima kasih!\n");
                break;
            default:
                printf("Pilihan tidak valid, silakan coba lagi.\n");
        }
    } while (choice != 0);
}

int main() {
    menu();

    return 0;
}
