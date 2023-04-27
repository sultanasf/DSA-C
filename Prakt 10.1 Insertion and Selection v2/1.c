#include "stdio.h"

#define max 10
int move, cmp, swap;

void selectionSort(int []);

void selectionSwap(int *, int *);

void view(int []);

int main() {
    int arr[max] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    puts("Before sort: ");
    view(arr);
    selectionSort(arr);
    puts("\nAfter sort: ");
    view(arr);
    printf("\nm=%d  c=%d  s=%d", move, cmp, swap);
}

void view(int a[]) {
    for (int i = 0; i < max; ++i) {
        printf("%d ", a[i]);
    }
}

void selectionSort(int a[]) {
    int minIndex;
    for (int i = 0; i < max - 1; ++i) {
        minIndex = i;
        for (int j = i + 1; j < max; ++j) {
            if (a[j] < a[minIndex])
                minIndex = j;
            cmp++;
        }
        selectionSwap(&a[i], &a[minIndex]);
        swap++;
        move = move + 3;
    }
}

void selectionSwap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}