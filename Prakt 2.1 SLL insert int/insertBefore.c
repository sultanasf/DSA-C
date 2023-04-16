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
}

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

void before()
{
    Node *bef, *pbef;
    int key, nilaiBaru;
    printf("Masukkan nilai yang akan disisipkan : ");
    scanf("%d", &nilaiBaru);
    printf("Disisipkan sebelum data berapa : ");
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

    bef = head;
    if (head->data == key)
    {
        awal();
    }

    else
    {
        do
        {
            pbef = bef;
            if (bef->next == NULL)
            {
                puts("Key Tidak Ada");
            }
            else
            {
                bef = bef->next;
            }
        } while (bef->data != key);
        p->next = bef;
        pbef->next = p;
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
    before();
    tampil();
}
