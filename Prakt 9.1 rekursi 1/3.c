#include "stdio.h"
#include "string.h"

#define MAX 30

void printChar(int, char []);

int main() {
    char input[MAX];
    printf("Masukkan string: ");
    gets(input);
    fflush(stdin);
    printChar(strlen(input), input);
}

void printChar(int index, char str[]) {
    if (index < 0)
        return;
    else {
        printf("%c", str[index]);
        printChar(index - 1, str);
    }
}