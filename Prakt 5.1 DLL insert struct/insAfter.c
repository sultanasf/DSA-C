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

void insAkhir() {
    Node *tail;
    if (head == NULL)
        insAwal();
    else {
        tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        p->prev = tail;
        tail->next = p;
    }
}

void insAfter() {
    int key;
    Node *after;
    allocation();
    fflush(stdin);
    printf("Sisipkan setelah data berapa: ");
    scanf("%d", &key);

    after = head;
    while (after->data != key) {
        if (after->next == NULL) {
            printf("Key tidak ada");
            exit(0);
        }
        after = after->next;
    }
    if (after->next == NULL) {
        insAkhir();
    } else {
        p->next = after->next;
        p->prev = after;
        after->next->prev = p;
        after->next = p;
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
        insAkhir();
        view();
        fflush(stdin);
        printf("\nMau lagi (y/t)? ");
        jwb = getchar();
    } while (jwb == 'y' || jwb == 'Y');
    insAfter();
    view();
}