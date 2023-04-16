#include "stdio.h"

#define MAX 50

typedef int itemType;
typedef struct {
    itemType data[MAX];
    int count;
} stack;

void stackPush(stack *, itemType);

itemType stackPop(stack *);

void stackRead(stack *);

void initialization(stack *);

int isFull(stack *);

int isEmpty(stack *);

void binary(int, stack *);

void octal(int, stack *);

void hexa(int, stack *);

void menu(stack *);

int main() {
    stack tumpukan;
    menu(&tumpukan);
}

void menu(stack *s) {
    int opsi, dec;
    printf("Masukkan bilangan desimal : ");
    scanf("%d", &dec);
    initialization(s);
    do {
        puts("\nMenu Konversi");
        puts("1. Biner");
        puts("2. Oktal");
        puts("3. Heksadesimal");
        puts("4. Keluar");
        printf("Pilih menu : ");
        scanf("%d", &opsi);
        switch (opsi) {
            case 1:
                binary(dec, s);
                printf("Hasil konversi %d ke biner adalah ", dec);
                break;
            case 2:
                octal(dec, s);
                printf("Hasil konversi %d ke oktal adalah ", dec);
                break;
            case 3:
                hexa(dec, s);
                printf("Hasil konversi %d ke heksadesimal adalah ", dec);
                break;
            default:
                break;
        }
        stackRead(s);
    } while (opsi != 4);
}

void initialization(stack *s) {
    s->count = 0;
}

int isEmpty(stack *s) {
    return ((s->count == 0) ? 1 : 0);
}

int isFull(stack *s) {
    return ((s->count == MAX) ? 1 : 0);
}

void stackPush(stack *s, itemType input) {
    if (isFull(s)) {
        puts("Stack penuh, data tidak bisa disimpan");
    } else {
        s->data[s->count] = input;
        s->count++;
    }
}

itemType stackPop(stack *s) {
    itemType temp;
    if (isEmpty(s)) {
        return ' ';
    } else {
        --s->count;
        temp = s->data[s->count];
        return temp;
    }
}

void binary(int dec, stack *s) {
    int result;
    while (dec > 0) {
        result = dec % 2;
        dec = dec / 2;
        stackPush(s, result + '0');
    }
}

void octal(int dec, stack *s) {
    int result;
    while (dec > 0) {
        result = dec % 8;
        dec = dec / 8;
        stackPush(s, result + '0');
    }
}

void hexa(int dec, stack *s) {
    int result;
    while (dec > 0) {
        result = dec % 16;
        dec = dec / 16;
        if (result > 9) {
            stackPush(s, result + 55);
        } else {
            stackPush(s, result + '0');
        }
    }
}

void stackRead(stack *s) {
    while (s->count > 0) {
        printf("%c", stackPop(s));
    }
}
