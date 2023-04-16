#include "stdio.h"
#include "string.h"

#define MAX 50

typedef char itemType;
typedef struct
{
    itemType data[MAX];
    int count;
} stack;

void stackPush(stack *, itemType);

itemType stackPop(stack *);

void stackRead(stack *);

void initialization(stack *);

int isPalindrom(stack *, itemType[]);

int isFull(stack *);

int isEmpty(stack *);

void menu(stack *);

int main()
{
    stack tumpukan;
    menu(&tumpukan);
}

void menu(stack *s)
{
    itemType input[MAX], jwb;
    do
    {
        printf("Masukkan string untuk di cek: ");
        gets(input);
        fflush(stdin);
        if (isPalindrom(s, input))
        {
            printf("%s adalah Palindrom\n", input);
        }
        else
        {
            printf("%s Bukan Palindrom\n", input);
        }
        printf("Mau lagi (y/t): ");
        jwb = getchar();
        fflush(stdin);
    } while (jwb == 'y' || jwb == 'Y');
}

void initialization(stack *s)
{
    s->count = 0;
}

int isPalindrom(stack *s, itemType input[])
{
    int i = 0;
    int flag = 0;
    initialization(s);
    while (input[i] != '\0')
    {
        stackPush(s, input[i]);
        i++;
    }
    for (i = 0; input[i] != '\0'; i++)
    {
        if (input[i] != stackPop(s))
        {
            flag = 1;
        }
    }
    return ((flag == 0) ? 1 : 0);
}

int isEmpty(stack *s)
{
    return ((s->count == 0) ? 1 : 0);
}

int isFull(stack *s)
{
    return ((s->count == MAX) ? 1 : 0);
}

void stackPush(stack *s, itemType input)
{
    if (isFull(s))
    {
        puts("Stack penuh, data tidak bisa disimpan");
    }
    else
    {
        s->data[s->count] = input;
        s->count++;
    }
}

itemType stackPop(stack *s)
{
    itemType temp;
    if (isEmpty(s))
    {
        return ' ';
    }
    else
    {
        --s->count;
        temp = s->data[s->count];
        return temp;
    }
}