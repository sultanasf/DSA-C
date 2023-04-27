#include <stdio.h>
#include <time.h>

int factorialIterative(int n);

int factorialRecursive(int n);

int factorialRecursiveTail(int n, int result);

void menu();

time_t t1, t2;
long int waktukomputasi;

int main() {
    menu();
}

int factorialIterative(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int factorialRecursive(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorialRecursive(n - 1);
    }
}

int factorialRecursiveTail(int n, int result) {
    if (n == 0) {
        return result;
    } else {
        return factorialRecursiveTail(n - 1, result * n);
    }
}

void menu() {
    int n, choice, hasil;

    printf("Masukkan bilangan n: ");
    scanf("%d", &n);

    do {
        printf("Pilih metode penghitungan faktorial:\n");
        printf("1. Iterasi\n");
        printf("2. Rekursi\n");
        printf("3. Rekursi Tail\n");
        printf("4. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                time(&t1);
                hasil = factorialIterative(n);
                time(&t2);
                waktukomputasi = difftime(t2, t1);
                printf("Hasil faktorial %d menggunakan iterasi: %d\n", n, hasil);
                printf("Dengan waktu komputasi %ld detik\n", waktukomputasi);
                break;
            case 2:
                time(&t1);
                hasil = factorialRecursive(n);
                time(&t2);
                waktukomputasi = difftime(t2, t1);
                printf("Hasil faktorial %d menggunakan rekursi: %d\n", n, hasil);
                printf("Dengan waktu komputasi %ld detik\n", waktukomputasi);
                break;
            case 3:
                time(&t1);
                hasil = factorialRecursiveTail(n, 1);
                time(&t2);
                waktukomputasi = difftime(t2, t1);
                printf("Hasil faktorial %d menggunakan rekursi tail: %d\n", n, hasil);
                printf("Dengan waktu komputasi %ld detik\n", waktukomputasi);
                break;
            default:
                printf("Pilihan tidak valid.\n");
                break;
        }
    } while (choice != 4);
}
