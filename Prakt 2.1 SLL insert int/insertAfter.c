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

void awal()
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

void after()
{
    Node *after;
    int key, nilaiBaru;
    printf("Masukkan nilai yang akan disisipkan : ");
    scanf("%d", &nilaiBaru);
    printf("Disisipkan setelah data berapa : ");
    scanf("%d", &key);

    p = (Node *)malloc(sizeof(Node));
    if (p == NULL)
    {
        printf("Alokasi gagal");
        exit(0);
    }
    else
    {
        p->data = nilaiBaru;
        p->next = NULL;
    }

    after = head;
    while (after->data != key)
    {
        if (after->next == NULL)
        {
            printf("Key tidak ada");
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
    after();
    tampil();
}
