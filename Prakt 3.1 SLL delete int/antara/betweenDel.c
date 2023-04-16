#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul
{
    int data;
    Node *next;
};
Node *head = NULL, *p;

void allocation()
{
    int userInput;
    printf("Data wanted to save : ");
    scanf("%d", &userInput);
    fflush(stdin);
    p = (Node *)malloc(sizeof(Node));
    if (p == NULL)
    {
        printf("Allocation failed");
        exit(0);
    }
    else
    {
        p->data = userInput;
        p->next = NULL;
    }
}

void endIns()
{
    Node *tail;
    tail = head;
    if (head == NULL)
        head = p;
    else
    {
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
    printf("\nData already Inputted : \n");
    if (head == NULL)
    {
        printf("Nodata");
    }
    else
    {
        while (read != NULL)
        {
            printf("%d\n", read->data);
            read = read->next;
        }
    }
}

void beginningDel()
{
    Node *del;
    puts("\nDeleting the beginning of SLL..");
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        del = head;
        head = del->next;
        free(del);
        del = NULL;
    }
}

void endDel()
{
    Node *del, *pdel;
    puts("\nDeleting the end of SLL..");
    if (head->next == NULL)
        beginningDel();
    else
    {
        del = head;
        while (del->next != NULL)
        {
            pdel = del;
            del = del->next;
        }
        pdel->next = NULL;
        free(del);
        del = NULL;
    }
}

void certainDel()
{
    Node *del, *pdel;
    int key;
    printf("Which data you want to delete : ");
    scanf("%d", &key);
    puts("\nDeleting certain Node..");
    if (head->data == key)
        beginningDel();
    else
    {
        del = head;
        while (del->data != key)
        {
            if (del->next == NULL)
            {
                printf("Data tidak ada");
                exit(0);
            }
            else
            {
                pdel = del;
                del = del->next;
            }
        }
        pdel->next = del->next;
        free(del);
        del = NULL;
    }
}

int main()
{
    char confirm;
    puts("Single linked list - End Insert");
    do
    {
        allocation();
        printf("Is there more (y/n) ? ");
        scanf("%c", &confirm);
        endIns();
    } while (confirm == 'y' || confirm == 'Y');
    view();
    certainDel();
    view();
}