#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct siswa Node;
struct siswa {
    int no;
    char name[20];
    float score;
    Node *next;
};
Node *head = NULL, *p;

void allocation() {
    int inputNo;
    char inputName[sizeof(p->name)];
    float inputScore;
    printf("no\t:");
    scanf("%d", &inputNo);
    fflush(stdin);
    printf("name\t:");
    gets(inputName);
    fflush(stdin);
    printf("score\t:");
    scanf("%f", &inputScore);
    fflush(stdin);
    p = (Node *) malloc(sizeof(Node));
    if (p == NULL) {
        printf("Allocation failed");
        exit(0);
    } else {
        p->no = inputNo;
        strcpy(p->name, inputName);
        p->score = inputScore;
        p->next = NULL;
    }
}

void endIns() {
    Node *tail;
    tail = head;
    if (head == NULL)
        head = p;
    else {
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = p;
    }
}

void view() {
    Node *read = NULL;
    printf("\nData already Inputted : \n");
    read = head;

    while (read != NULL) {
        printf("no\t: %d\n", read->no);
        printf("name\t: %s\n", read->name);
        printf("score\t: %g\n", read->score);
        read = read->next;
    }
}

void beginningDel() {
    Node *del;
    if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        del = head;
        head = del->next;
        free(del);
        del = NULL;
    }
}

void endDel() {
    Node *del, *pdel;
    if (head->next == NULL)
        beginningDel();
    else {
        del = head;
        while (del->next != NULL) {
            pdel = del;
            del = del->next;
        }
        pdel->next = NULL;
        free(del);
        del = NULL;
    }
}

void certainDel() {
    Node *del, *pdel;
    int key;
    printf("Which number you want to delete : ");
    scanf("%d", &key);
    puts("\nDeleting certain Node..");
    if (head->no == key)
        beginningDel();
    else {
        del = head;
        while (del->no != key) {
            if (del->next == NULL) {
                printf("Data tidak ada");
                exit(0);
            } else {
                pdel = del;
                del = del->next;
            }
        }
        pdel->next = del->next;
        free(del);
        del = NULL;
    }
}

int main() {
    char confirm;
    puts("Single linked list - End Insert");
    do {
        allocation();
        printf("Is there more (y/n) ? ");
        scanf("%c", &confirm);
        endIns();
    } while (confirm == 'y' || confirm == 'Y');
    view();
    certainDel();
    view();
}