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

void beginningIns()
{
    if (head == NULL)
    {
        head = p;
    }
    else
    {
        p->next = head;
        head = p;
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

void beforeIns()
{
    Node *bef, *pbef;
    int key;
    printf("Insert before which number : ");
    scanf("%d", &key);
    bef = head;
    while (bef->no != key)
    {
        if (bef->next == NULL)
        {
            printf("Number not found!!!");
            break;
        }
        else
        {
            pbef = bef;
            bef = bef->next;
        }
    }
    p->next = bef;
    pbef->next = p;
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

void menu(int option)
{
    switch (option)
    {
    case 1:
        allocation();
        beginningIns();
        view();
        break;
    case 2:
        allocation();
        endIns();
        view();
        break;
    case 3:
        if (head == NULL)
        {
            puts("No existed SLL, insert first(end/beginning)");
        }
        else
        {
            allocation();
            afterIns();
            view();
        }
        break;
    case 4:
        if (head == NULL)
        {
            puts("No existed SLL, insert first(end/beginning)");
        }
        else
        {
            allocation();
            beforeIns();
            view();
        }
        break;
    default:
        break;
    }
}

int main()
{
    int option;
    while (option != 5)
    {
        puts("Insertion Menu");
        puts("1. Beginning of SLL");
        puts("2. End of SLL");
        puts("3. After some Node");
        puts("4. Before some Node");
        puts("5. Exit");
        printf("Choose Insertion method : ");
        scanf("%d", &option);
        menu(option);
    }
}