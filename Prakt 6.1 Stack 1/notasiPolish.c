#include "stdio.h"
#include "string.h"

#define MAX 100

typedef char itemType;
typedef struct {
    int count;
    itemType data[MAX];
} stack;

void menu();

void inisialisasiStuck(stack *);

int isFull(stack *);

int isEmpty(stack *);

void stackPush(itemType, stack *);

itemType stackPop(stack *);

void polish(char[], stack *);

int checkHierarchyOperator(char);

int compareOperator(char, char);

int main() {
    menu();
}

void menu() {
    char notasiInfix[100];
    stack tumpukan;
    char opsi;
    inisialisasiStuck(&tumpukan);
    printf("MENGUBAH NOTASI INFLIX MENJADI POSTFIX\nDENGAN MEMANFAATKAN STRUKTUR STUCK\n");
    do {
        printf("Masukkan ekspresi dalam notasi infix : ");
        fflush(stdin);
        scanf("%s", notasiInfix);
        polish(notasiInfix, &tumpukan);
        printf("Coba lagi (y/t) ? ");
        fflush(stdin);
        scanf("%c", &opsi);
    } while (opsi != 't' && opsi != 'T');
}

void inisialisasiStuck(stack *tumpukan) {
    tumpukan->count = 0;
}

int isFull(stack *tumpukan) {
    return tumpukan->count == MAX ? 1 : 0;
}

int isEmpty(stack *tumpukan) {
    return tumpukan->count == 0 ? 1 : 0;
}

void stackPush(itemType dataPush, stack *tumpukan) {
    if (isFull(tumpukan)) {
        printf("stack penuh, tidak bisa PUSH");
        return;
    }
    tumpukan->data[tumpukan->count] = dataPush;
    tumpukan->count++;
}

itemType stackPop(stack *tumpukan) {
    itemType temp;
    if (isEmpty(tumpukan)) {
        printf("stack kosong, tidak bisa POP");
        return ' ';
    }
    --tumpukan->count;
    temp = tumpukan->data[tumpukan->count];
    return temp;
}

int checkHierarchyOperator(char operator) {
    if (operator == '^')
        return 3;
    else if (operator == '*' || operator == '/')
        return 2;
    else if (operator == '+' || operator == '-')
        return 1;
    else {
        return 0;
    }
}

int compareOperator(char firstOperator, char secondOperator) {
    int derajatFirstOperator, derajatSecondOperator;
    derajatFirstOperator = checkHierarchyOperator(firstOperator);
    derajatSecondOperator = checkHierarchyOperator(secondOperator);
    if (derajatFirstOperator > derajatSecondOperator)
        return 1;
    else
        return 0;
}

void polish(char notasiInfix[], stack *tumpukan) {
    for (int i = 0; i < strlen(notasiInfix); i++) {
        char currentChar = notasiInfix[i];
        if (currentChar == '(') {
            stackPush(currentChar, tumpukan);
        } else if (currentChar == ')') {
            itemType currentItemInStuck = tumpukan->data[tumpukan->count - 1];
            while (currentItemInStuck != '(') {
                currentItemInStuck = stackPop(tumpukan);
                if (currentItemInStuck != '(') {
                    printf("%c", currentItemInStuck);
                }
            }
        } else if (currentChar == '^' || currentChar == '*' || currentChar == '/' || currentChar == '+' ||
                   currentChar == '-') {
            if (isEmpty(tumpukan) || compareOperator(currentChar, tumpukan->data[tumpukan->count - 1]))
                stackPush(currentChar, tumpukan);
            else {
                while (!compareOperator(currentChar, tumpukan->data[tumpukan->count - 1])) {
                    printf("%c", stackPop(tumpukan));
                }
                stackPush(currentChar, tumpukan);
            }
        } else {
            printf("%c", currentChar);
        }
    }
    while (tumpukan->count > 0) {
        printf("%c", stackPop(tumpukan));
    }
    printf("\n");
}