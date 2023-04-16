#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul
{
    int data;
    Node *next;
};
Node *head = NULL, *p;

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

void awal()
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
        awal();
        printf("Apakah anda akan memasukkan nilai lagi (y/t)? ");
        fflush(stdin);
        scanf("%c", &jwb);
        fflush(stdin);
    }
    tampil();
}
