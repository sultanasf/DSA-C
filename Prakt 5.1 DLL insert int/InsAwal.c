#include "stdio.h"
#include "stdlib.h"

typedef struct simpul Node;
struct simpul {
    int data;
    Node *next, *prev;
};
Node *head = NULL, *p;

void allocation() {
    p = (Node *) malloc(sizeof(Node));
    if (p == NULL) {
        printf("Alokasi gagal");
        exit(0);
    } else {
        printf("Masukkan data: ");
        scanf("%d", &p->data);
        p->next = NULL;
        p->prev = NULL;
    }
}

void insAwal() {
    if (head == NULL) {
        head = p;
    } else {
        p->next = head;
        p->next->prev = p;
        head = p;
    }
}

void view() {
    Node *read;
    read = head;
    while (read != NULL) {
        printf("%d ", read->data);
        read = read->next;
    }
}

int main() {
    char jwb;
    do {
        allocation();
        insAwal();
        view();
        fflush(stdin);
        printf("\nMau lagi (y/t)? ");
        jwb = getchar();
    } while (jwb == 'y' || jwb == 'Y');
}