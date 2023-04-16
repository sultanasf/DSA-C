#include "stdio.h"
#include "stdlib.h"

#include "stdio.h"
#include "stdlib.h"

typedef struct simpul Node;
struct simpul
{
    int data;
    Node *next, *prev;
};
Node *head = NULL, *p, *del;

void allocation()
{
    p = (Node *)malloc(sizeof(Node));
    if (p == NULL)
    {
        printf("Alokasi gagal");
        exit(0);
    }
    else
    {
        printf("Masukkan data: ");
        scanf("%d", &p->data);
        p->next = NULL;
        p->prev = NULL;
    }
}

void insAwal()
{
    if (head == NULL)
    {
        head = p;
    }
    else
    {
        p->next = head;
        p->next->prev = p;
        head = p;
    }
}

void insAkhir()
{
    Node *tail;
    if (head == NULL)
        insAwal();
    else
    {
        tail = head;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        p->prev = tail;
        tail->next = p;
    }
}

void insAfter()
{
    int key;
    Node *after;
    allocation();
    fflush(stdin);
    printf("Sisipkan setelah data berapa: ");
    scanf("%d", &key);

    after = head;
    while (after->data != key)
    {
        if (after->next == NULL)
        {
            printf("Key tidak ada");
            exit(0);
        }
        after = after->next;
    }
    if (after->next == NULL)
    {
        insAkhir();
    }
    else
    {
        p->next = after->next;
        p->prev = after;
        after->next->prev = p;
        after->next = p;
    }
}

void insBefore()
{
    int key;
    Node *bef;
    allocation();
    fflush(stdin);
    printf("Disisipkan sebelum data berapa: ");
    scanf("%d", &key);
    if (head->data == key)
        insAwal();
    else
    {
        bef = head;
        while (bef->data != key)
        {
            if (bef->next == NULL)
            {
                printf("Key tidak ada");
                exit(0);
            }
            bef = bef->next;
        }
        p->next = bef;
        p->prev = bef->prev;
        bef->prev->next = p;
        bef->prev = p;
    }
}

void bebas()
{
    free(del);
    del = NULL;
}

void delAwal()
{
    del = head;
    if (del->next == NULL)
        head = NULL;
    else
    {
        head = head->next;
        head->prev = NULL;
    }
    bebas();
}

void delAkhir()
{
    del = head;
    if (del->next == NULL)
        delAwal();
    else
    {
        while (del->next != NULL)
        {
            del = del->next;
        }
        del->prev->next = NULL;
        bebas();
    }
}

void delTertentu()
{
    int key;
    printf("Data berapa yang mau dihapus: ");
    scanf("%d", &key);
    if (head->data == key)
        delAwal();
    else
    {
        del = head;
        while (del->data != key)
        {
            if (del->next == NULL)
            {
                printf("Key tidak ada");
                exit(0);
            }
            del = del->next;
        }
        if (del->next == NULL)
            delAkhir();
        else
        {
            del->next->prev = del->prev;
            del->prev->next = del->next;
            free(del);
            del = NULL;
        }
    }
}

void view()
{
    Node *read;
    read = head;
    puts("\nIsi DLL: ");
    while (read != NULL)
    {
        printf("%d ", read->data);
        read = read->next;
    }
}

void menuIns()
{
    int jwb;
    puts("Menu Insert");
    puts("1. Insert Awal");
    puts("2. Insert Akhir");
    puts("3. Insert After");
    puts("4. Insert Before");
    printf("Masukkan pilihan insert: ");
    scanf("%d", &jwb);
    fflush(stdin);
    switch (jwb)
    {
    case 1:
        allocation();
        insAwal();
        break;
    case 2:
        allocation();
        insAkhir();
        break;
    case 3:
        if (head == NULL)
        {
            printf("DLL kosong, insert awal/akhir dahulu");
            break;
        }
        else
        {
            insAfter();
            break;
        }
    case 4:
        if (head == NULL)
        {
            printf("DLL kosong, insert awal/akhir dahulu");
            break;
        }
        else
        {
            insBefore();
            break;
        }
    }
}

void menuDel()
{
    int jwb;
    puts("Menu Delete");
    puts("1. Delete Awal");
    puts("2. Delete Akhir");
    puts("3. Delete Tertentu");
    printf("Masukkan pilihan delete: ");
    scanf("%d", &jwb);
    if (head == NULL)
        printf("DLL Kosong");
    else
    {
        switch (jwb)
        {
        case 1:
            delAwal();
            break;
        case 2:
            delAkhir();
            break;
        case 3:
            delTertentu();
            break;
        }
    }
}

void menu()
{
    int jwb;
    do
    {
        puts("\nMenu Utama");
        puts("1. Insert");
        puts("2. Delete");
        puts("3. Keluar");
        printf("Masukkan pilihan: ");
        scanf("%d", &jwb);
        fflush(stdin);
        switch (jwb)
        {
        case 1:
            menuIns();
            break;
        case 2:
            menuDel();
            break;
        default:
            break;
        }
        view();
    } while (jwb != 3);
}

int main()
{
    menu();
}