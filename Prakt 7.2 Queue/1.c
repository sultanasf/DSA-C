#include "stdio.h"

#define MAX 5
typedef char itemType;
typedef struct {
    itemType data[MAX];
    int front, rear, count;
} Queue;

void initialization(Queue *);

int isFull(Queue *);

int isEmpty(Queue *);

void enqueue(Queue *, itemType);

itemType dequeue(Queue *);

void readQueue(Queue *);

void menu(Queue *);

int main() {
    Queue antrian;
    menu(&antrian);
}

void menu(Queue *q) {
    int option;
    char input;
    initialization(q);
    do {
        puts("\nMenu Queue");
        puts("1. Tambah data (enqueue)");
        puts("2. Hapus data (dequeue)");
        puts("3. Tampilkan data min & max");
        puts("4. Cari data");
        printf("Masukkan pilihan: ");
        scanf("%d", &option);
        fflush(stdin);

        switch (option) {
            case 1:
                printf("Masukkan data: ");
                scanf("%c", &input);
                fflush(stdin);
                enqueue(q, input);
                break;
            case 2:
                printf("Item yang diambil adalah %c\n", dequeue(q));
                break;
            case 3:
                readQueue(q);
                break;
            default:
                break;
        }
    } while (option != 4);
}

void initialization(Queue *q) {
    q->front = 0;
    q->rear = 0;
    q->count = 0;
}

int isFull(Queue *q) {
    return (q->count == MAX) ? 1 : 0;
}

int isEmpty(Queue *q) {
    return (q->count == 0) ? 1 : 0;
}

void enqueue(Queue *q, itemType x) {
    if (isFull(q))
        puts("Queue is full, can't enqueue");
    else {
        q->data[q->rear] = x;
        q->rear = (q->rear + 1);
        if (q->rear == MAX)
            q->rear = 0;
        q->count++;
    }
}

itemType dequeue(Queue *q) {
    itemType temp;
    if (isEmpty(q)) {
        puts("Queue is empty, can't dequeue");
        return ' ';
    } else {
        temp = q->data[q->front];
        q->front = (q->front + 1) % MAX;
        q->count--;
        return temp;
    }
}

void readQueue(Queue *q) {
    int temp;
    temp = q->front;
    puts("isi Queue:");
    for (int i = 0; i < q->count; i++) {
        printf("%c\n", q->data[temp]);
        temp = (temp + 1) % MAX;
    }
}