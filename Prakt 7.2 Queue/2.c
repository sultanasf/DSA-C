#include "stdio.h"
#include "stdlib.h"

typedef char itemType;
typedef struct queue antrian;
struct queue {
    antrian *next;
    itemType item;
    int prio;
};
antrian *head = NULL, *q;

void menu();

void initialization(itemType, int);

void enqueue();

itemType dequeue();

void readQueue();

int main() {
    menu();
    return 0;
}

void menu() {
    int option, priority;
    itemType data;

    do {
        puts("Menu Priority Queue Using SLL");
        printf("1. Mengisi Queue\n2. Ambil Isi Queue\n3. Tampilkan Isi Queue\n4. keluar\n");
        printf("Masukkan pilihan = ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                fflush(stdin);
                printf("Masukkan data: ");
                scanf("%c", &data);
                fflush(stdin);
                printf("Masukkan priority: ");
                scanf("%d", &priority);
                fflush(stdin);
                initialization(data, priority);
                enqueue();
                break;
            case 2:
                printf("Item yang anda ambil = %c\n", dequeue());
                break;
            case 3:
                readQueue();
                break;
            case 4:
                break;
            default:
                puts("Opsi Invalid");
                break;
        }
    } while (option != 4);
}

void initialization(itemType x, int p) {
    q = (antrian *) malloc(sizeof(antrian));
    if (q == NULL) {
        puts("Gagal Inisialisasi Queue");
        exit(0);
    } else {
        q->item = x;
        q->prio = p;
        q->next = NULL;
    }
}

void enqueue() {
    antrian *ptr;
    if (head == NULL || q->prio < head->prio) {
        if (head != NULL) {
            q->next = head;
        }
        head = q;
    } else {
        ptr = head;
        while (ptr->next != NULL && q->prio > ptr->next->prio) {
            ptr = ptr->next;
        }
        q->next = ptr->next;
        ptr->next = q;
    }
}

itemType dequeue() {
    itemType temp;
    antrian *del;
    if (head == NULL) {
        puts("Queue Kosong");
        return (' ');
    } else {
        if (head->next == NULL) {
            temp = head->item;
            free(head);
            head = NULL;
        } else {
            temp = head->item;
            del = head;
            head = head->next;
            free(del);
            del = NULL;
        }
        return temp;
    }
}

void readQueue() {
    antrian *read;
    read = head;
    printf("Isi Queue Saat Ini Adalah:\n");
    printf("Data\t\tpriority\n");
    while (read != NULL) {
        printf("%c\t\t%d\n", read->item, read->prio);
        read = read->next;
    }
    printf("\n");
}