#include "stdio.h"
#include "string.h"

#define MAX 5

typedef char itemType;
typedef struct {
    itemType data[MAX];
    int count;
} stack;

void menu(stack *);

void stackPush(stack *);

void stackPop(stack *);

void stackRead(stack *);

void initialization(stack *);

int isFull(stack *);

int isEmpty(stack *);

int main() {
    stack tumpukan;
    puts("~~~Sultan Argya S.F - 3122600022~~~\n");
    menu(&tumpukan);
}

void menu(stack *s) {
    int opsi;
    initialization(s);
    do {
        puts("\nMenu Stack using Array");
        puts("1. Mengisi stack (push)");
        puts("2. Mengambil isi Stack (pop)");
        puts("3. Menampilkan isi stack -> LIFO");
        puts("4. Keluar");
        printf("Masukkan pilihan anda : ");
        scanf("%d", &opsi);
        fflush(stdin);
        switch (opsi) {
            case 1:
                stackPush(s);
                break;
            case 2:
                stackPop(s);
                break;
            case 3:
                stackRead(s);
                break;
            default:
                break;
        }
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

void stackPush(stack *s) {
    itemType input;
    if (isFull(s)) {
        puts("Stack penuh, data tidak bisa disimpan");
    } else {
        printf("Masukkan data yang mau di push : ");
        scanf("%c", &input);
        fflush(stdin);
        s->data[s->count] = input;
        s->count++;
    }
}

void stackPop(stack *s) {
    itemType temp;
    if (isEmpty(s)) {
        puts("Stack sudah kosong");
    } else {
        --s->count;
        temp = s->data[s->count];
        printf("Item yang anda pop adalah %c\n", temp);
    }
}

void stackRead(stack *s) {
    puts("Data yang ada dalam stack: ");
    for (int i = s->count - 1; i >= 0; i--) {
        printf("%c ", s->data[i]);
    }
}