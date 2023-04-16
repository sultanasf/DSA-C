#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul {
    int data;
    Node *next;
};

void allocation();
void beginIns();
void endIns();
void afterIns();
void beforeIns();
void deleteBegin();
void deleteEnd();
void deleteSpecific();
void view();

Node *head, *p;

int main() {
    int pilihanMenu, pilihanSubMenu;
    do {
        printf("\nMenu SLL\n1. Insert\n2. Delete\n3. Keluar");
        printf("\nMasukkan pilihan Anda: ");
        scanf("%i", &pilihanMenu);

        if (pilihanMenu == 1) {
            printf("Menu Insert\n1. Awal\n2. Akhir\n3. Sebelum\n4. Sesudah");
            printf("\nMasukkan pilihan Anda: ");
            scanf("%i", &pilihanSubMenu);

            switch (pilihanSubMenu) {
                case 1:
                    fflush(stdin);
                    allocation();
                    beginIns();
                    break;

                case 2:
                    fflush(stdin);
                    allocation();
                    endIns();
                    break;

                case 3:
                    if (head == NULL)
                        printf("SLL masih kosong, insert awal/akhir dulu");
                    else {
                        fflush(stdin);
                        allocation();
                        beforeIns();
                    }
                    break;

                case 4:
                    if (head == NULL)
                        printf("SLL masih kosong, insert awal/akhir dulu");
                    else {
                        fflush(stdin);
                        allocation();
                        afterIns();
                    }
                    break;
            }
        } else if (pilihanMenu == 2) {
            if (head == NULL) {
                printf("\nSLL masih kosong. Silakan lakukan insert terlebih dahulu!");
            } else {
                printf("Menu Hapus\n1. Awal\n2. Akhir\n3. Tertentu");
                printf("\nMasukkan pilihan Anda: ");
                scanf("%i", &pilihanSubMenu);

                switch (pilihanSubMenu) {
                    case 1:
                        deleteBegin();
                        break;

                    case 2:
                        deleteEnd();
                        break;

                    case 3:
                        fflush(stdin);
                        deleteSpecific();
                        break;
                }
            }
        }
        view();
    } while (pilihanMenu != 3);

    return 0;
}

void allocation() {
    p = (Node *) malloc(sizeof(Node));
    if (p == NULL) {
        printf("Alokasi gagal");
        exit(0);
    } else {
        printf("Masukkan data yang ingin disimpan: ");
        scanf("%i", &p->data);
        p->next = NULL;
    }
}

void beginIns() {
    if (head != NULL) {
        p->next = head;
    }
    head = p;
}

void endIns() {
    Node *tail;
    if (head == NULL) {
        head = p;
    } else {
        tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = p;
        tail = tail->next;
    }
}

void afterIns() {
    Node *after;
    int key;

    printf("Disisipkan setelah node berapa? ");
    scanf("%i", &key);

    after = head;
    while (after->data != key) {
        if (after->next == NULL) {
            printf("%i tidak ada di dalam SLL\n", key);
            exit(0);
        } else {
            after = after->next;
        }
    }
    p->next = after->next;
    after->next = p;
}

void beforeIns() {
    Node *before, *prevbefore;
    int key;
    printf("Disisipkan sebelum node berapa? ");
    scanf("%i", &key);

    before = head;
    if (head->data == key)
        beginIns();
    else {
        while (before->data != key) {
            if (before->next == NULL) {
                printf("%i tidak ada di dalam SLL\n", key);
                exit(0);
            } else {
                prevbefore = before;
                before = before->next;
            }
        }
        p->next = before;
        prevbefore->next = p;
    }
}

void deleteBegin() {
    Node *hapus;

    hapus = head;
    if (head == NULL)
        printf("SLL masih kosong");
    else {
        if (hapus->next == NULL)
            head = NULL;
        else
            head = hapus->next;
        free(hapus);
        hapus = NULL;
    }
}

void deleteEnd() {
    Node *hapus, *phapus;

    if (head == NULL) {
        printf("SLL masih kosong");
    } else {
        hapus = head;
        if (hapus->next == NULL)
            head = NULL;
        else {
            while (hapus->next != NULL) {
                phapus = hapus;
                hapus = hapus->next;
            }
            phapus->next = NULL;
        }
        free(hapus);
        hapus = NULL;
    }
}

void deleteSpecific() {
    Node *hapus, *phapus;
    int key;
    printf("\nData berapa yang ingin dihapus? ");
    scanf("%i", &key);

    if (head == NULL) {
        printf("SLL masih kosong");
    } else {
        hapus = head;
        if (hapus->data == key)
            deleteBegin();
        else {
            while (hapus->data != key) {
                if (hapus->next == NULL) {
                    printf("Data tidak ada di dalam SLL");
                    exit(0);
                } else {
                    phapus = hapus;
                    hapus = hapus->next;
                }
            }
            phapus->next = hapus->next;
            free(hapus);
            hapus = NULL;
        }
    }
}

void view() {
    Node *read;
    read = head;

    printf("\nHasil SLL:\n");
    while (read != NULL) {
        printf("%i\n", read->data);
        read = read->next;
    }
}
