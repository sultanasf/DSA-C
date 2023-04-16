#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul
{
    int data;
    Node *next;
};
Node *head = NULL, *p, *tail;

void alokasi()
{
    int nilai;
    printf("Masukkan nilai yang akan disimpan : ");
    scanf("%d", &nilai);
    p = (Node *)malloc(sizeof(Node));
    if (p == NULL)
    {
        printf("Alokasi gagal");
        exit(0);
    }
    else
    {
        p->data = nilai;
        p->next = NULL;
    }
};

void akhir()
{
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

void tampil()
{
    Node *read;
    read = head;
    while (read != NULL)
    {
        printf("%d  ", read->data);
        read = read->next;
    }
}

int main()
{
    char jwb = 'y';
    while (jwb == 'y' || jwb == 'Y')
    {
        alokasi();
        akhir();
        printf("Apakah anda akan memasukkan nilai lagi (y/t)? ");
        fflush(stdin);
        scanf("%c", &jwb);
        fflush(stdin);
    }
    tampil();
}
