#include "stdio.h"

#define MAX 5
typedef int itemType;
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

void minMaxQueue(Queue *);

void searchQueue(Queue *);

void menu(Queue *);

int main() {
    Queue antrian;
    menu(&antrian);
}

void menu(Queue *q) {
    int option, input;
    initialization(q);
    do {
        puts("\nMenu Queue");
        puts("1. Tambah data (enqueue)");
        puts("2. Hapus data (dequeue)");
        puts("3. Tampilkan data min & max");
        puts("4. Cari data");
        puts("5. Cetak isi Queue");
        puts("6. Keluar");
        printf("Masukkan pilihan: ");
        scanf("%d", &option);
        fflush(stdin);

        switch (option) {
            case 1:
                printf("Masukkan data: ");
                scanf("%d", &input);
                fflush(stdin);
                enqueue(q, input);
                break;
            case 2:
                printf("Item yang diambil adalah %d\n", dequeue(q));
                break;
            case 3:
                minMaxQueue(q);
                break;
            case 4:
                searchQueue(q);
                break;
            case 5:
                readQueue(q);
            default:
                break;
        }
    } while (option != 6);
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
        printf("%d\n", q->data[temp]);
        temp = (temp + 1) % MAX;
    }
}

void minMaxQueue(Queue *q) {
    int min, max, temp;
    temp = q->front;
    for (int i = 0; i < q->count; i++) {
        if (i == 0) {
            min = q->data[temp];
            max = q->data[temp];
        } else {
            if (q->data[temp] > max)
                max = q->data[temp];
            if (q->data[temp] < min)
                min = q->data[temp];
        }
        temp = (temp + 1) % MAX;
    }
    printf("Nilai max = %d\nNilai min = %d\n", max, min);
}

void searchQueue(Queue *q) {
    int temp, key, count = 0;
    printf("Cari data berapa: ");
    scanf("%d", &key);
    temp = q->front;
    for (int i = 0; i < q->count; ++i) {
        if (q->data[temp] == key)
            count++;
        temp = (temp + 1) % MAX;
    }
    if (count == 0)
        printf("%d tidak ada dalam queue\n", key);
    else {
        printf("%d ada sebanyak %d\n", key, count);
    }
}