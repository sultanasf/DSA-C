#include "stdio.h"
#include "stdlib.h"

typedef struct simpul Node;
struct simpul {
    int data;
    Node *next;
};
Node *head = NULL, *p, *del, *read;

void allocation();

void push();

void pop();

void view();

void menu();

int main() {
    puts("3122600022-Sultan Argya Safa Firdaus");
    menu();
}

void menu() {
    int opsi;
    do {
        puts("\nMenu stack SLL");
        puts("1. Mengisi stack (push)");
        puts("2. Mengambil isi stack (pop)");
        puts("3. Menampilkan isi stack -> LIFO");
        puts("4. Keluar");
        printf("Pilih menu: ");
        scanf("%d", &opsi);
        switch (opsi) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                view();
                break;
            default:
                break;
        }
    } while (opsi != 4);
}

void allocation() {
    p = (Node *) malloc(sizeof(Node));
    if (p == NULL) {
        printf("Alokasi gagal");
    } else {
        printf("Masukkan datanya: ");
        scanf("%d", &p->data);
        fflush(stdin);
        p->next = NULL;
    }
}

void push() {
    allocation();
    if (head != NULL)
        p->next = head;
    head = p;
}

void pop() {
    if (head == NULL)
        printf("Stack kosong, push dahulu\n");
    else {
        printf("Data yang diambil dari stack = %d\n", head->data);
        if (head->next == NULL) {
            free(head);
            head = NULL;
        } else {
            del = head;
            head = head->next;
            free(del);
            del = NULL;
        }
    }
}

void view() {
    if (head == NULL) {
        puts("Stack kosong");
    } else {
        read = head;
        puts("Isi dari stack :");
        while (read != NULL) {
            printf("%d\n", read->data);
            read = read->next;
        }
    }
}