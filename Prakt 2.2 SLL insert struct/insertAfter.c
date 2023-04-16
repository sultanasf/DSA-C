#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maks 20

typedef struct simpul Node;
struct simpul
{
    int no;
    char nama[maks];
    float nilai;
    Node *next;
};
Node *head, *p;

void allocation()
{
    int no;
    float nilai;
    char nama[maks];
    printf("No\t: ");
    scanf("%d", &no);
    fflush(stdin);
    printf("Nama\t: ");
    gets(nama);
    fflush(stdin);
    printf("Nilai\t: ");
    scanf("%f", &nilai);
    fflush(stdin);

    p = (Node *)malloc(sizeof(Node));
    if (p == NULL)
    {
        printf("Allocation failed");
        exit(0);
    }
    else
    {
        p->no = no;
        strcpy(p->nama, nama);
        p->nilai = nilai;
        p->next = NULL;
    }
}

void endIns()
{
    Node *tail;
    if (head == NULL)
    {
        head = p;
    }
    else
    {
        tail = head;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = p;
    }
}

void view()
{
    Node *read;
    read = head;
    puts("Data already inputed :");
    puts("No\tNama\tNilai");
    do
    {
        printf("%d\t%s\t%g\n", read->no, read->nama, read->nilai);
        read = read->next;
    } while (read != NULL);
}

void afterIns()
{
    Node *after;
    int key;
    printf("Insert after which number : ");
    scanf("%d", &key);
    after = head;
    while (after->no != key)
    {
        if (after->next == NULL)
        {
            printf("Number not found");
            break;
        }
        else
        {
            after = after->next;
        }
    }
    p->next = after->next;
    after->next = p;
}

int main()
{
    char jwb = 'Y';
    while (jwb == 'y' || jwb == 'Y')
    {
        allocation();
        endIns();
        printf("Is there more data (y/n) ? ");
        scanf("%c", &jwb);
        fflush(stdin);
    }
    printf("Wanna insert data after (y/n) ? ");
    scanf("%c", &jwb);
    if (jwb == 'y' || jwb == 'Y')
    {
        allocation();
        afterIns();
    }
    view();
}