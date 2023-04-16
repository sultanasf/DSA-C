#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul
{
    int data;
    Node *next;
};
Node *head = NULL, *p, *tail, *bef, *pbef;

void alokasi();
void awal();
void akhir();
void tampil();
void after();
void before();
void proses(int);

int main()
{
    int opsi;
    do
    {
        puts("Menu Insert");
        puts("1. Awal");
        puts("2. Akhir");
        puts("3. After");
        puts("4. Before");
        puts("5. Keluar");
        printf("Masukkan pilihan anda : ");
        scanf("%d", &opsi);
        proses(opsi);
    } while (opsi != 5);
}

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
    printf("\nData yang ada dalam SLL\n");
    Node *read;
    read = head;
    while (read != NULL)
    {
        printf("%d\n", read->data);
        read = read->next;
    }
    printf("\n");
}

void after()
{
    Node *after;
    int key;
    alokasi();
    printf("Disisipkan setelah data berapa : ");
    scanf("%d", &key);
    after = head;
    while (after->data != key)
    {
        if (after->next == NULL)
        {
            printf("Key tidak ada");
            exit(0);
        }
        else
        {
            after = after->next;
        }
    }
    p->next = after->next;
    after->next = p;
}

void before()
{
    int key;
    alokasi();
    printf("Disisipkan sebelum data berapa : ");
    scanf("%d", &key);
    if (head->data == key)
    {
        awal();
    }
    else
    {
        bef = head;
        do
        {
            pbef = bef;
            if (bef->next == NULL)
            {
                puts("Key Tidak Ada");
                break;
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

void proses(int opsi)
{
    switch (opsi)
    {
    case 1:
        alokasi();
        awal();
        tampil();
        break;
    case 2:
        alokasi();
        akhir();
        tampil();
        break;
    case 3:
        if (head == NULL)
        {
            printf("SLL masih kosong, tidak bisa insert after\n");
            tampil();
        }
        else
        {
            after();
            tampil();
        }
        break;
    case 4:
        if (head == NULL)
        {
            printf("SLL masih kosong, tidak bisa insert before\n");
            tampil();
        }
        else
        {
            before();
            tampil();
        }
        break;
    default:
        break;
    }
}