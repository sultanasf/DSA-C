#include "stdio.h"
#include "stdlib.h"

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
    Node *read = NULL;
    printf("\nData already Inputted : \n");
    read = head;

    while (read != NULL)
    {
        printf("%d\n", read->data);
        read = read->next;
    }
}

void beginningDel()
{
    Node *del;
    puts("\nDeleting the beginning of SLL..");
    del = head;
    if (head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        head = del->next;
    }
    free(del);
    del = NULL;
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
    beginningDel();
    view();
}