#include "stdio.h"
#include "stdlib.h"

typedef char itemType;
typedef struct simpul Node;
typedef struct simpul {
    itemType data;
    Node *next;
} Node;
Node *front = NULL, *p, *read, *del, *rear;

void menu();

void allocation();

void enqueue();

void dequeue();

void view();

int main() {
    menu();
}

void menu() {
    int option;
    do {
        puts("\nMenu Queue Linked List");
        puts("1. Mengisi Queue (enqueue)");
        puts("2. Mengambil Queue (dequeue)");
        puts("3. Menampilkan Queue -> FIFO");
        puts("4. Keluar");
        printf("Masukkan pilihan: ");
        scanf("%d", &option);
        fflush(stdin);

        switch (option) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                view();
                break;
            default:
                break;
        }
    } while (option != 5);
}

void allocation() {
    p = (Node *) malloc(sizeof(Node));
    if (p == NULL) {
        printf("Alokasi Gagal");
        exit(0);
    } else {
        printf("Masukkan data: ");
        scanf("%c", &p->data);
        fflush(stdin);
        p->next = NULL;
    }
}

void enqueue() {
    allocation();
    if (front == NULL) {
        front = p;
    } else {
        rear = front;
        while (rear->next != NULL) {
            rear = rear->next;
        }
        rear->next = p;
    }
}

void dequeue() {
    itemType temp;
    if (front == NULL) {
        puts("Queue kosong, tidak bisa dequeue");
    } else {
        del = front;
        if (front->next == NULL)
            front = NULL;
        else
            front = front->next;
        temp = del->data;
        free(del);
        del = NULL;
        printf("Item yang diambil adalah %c\n", temp);
    }
}

void view() {
    read = front;
    puts("Isi Queue: ");
    while (read != NULL) {
        printf("%c\n", read->data);
        read = read->next;
    }
}