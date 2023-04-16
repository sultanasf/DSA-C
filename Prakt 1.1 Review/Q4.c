#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int d, m, y;
} Date;

int sameDate(Date pertama, Date kedua)
{
    if (pertama.d == kedua.d && pertama.m == kedua.m && pertama.y == kedua.y)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    Date pertama;
    Date kedua;
    printf("Masukkan tanggal pertama[dd/mm/yyyy]\t : ");
    scanf("%d-%d-%d", &pertama.d, &pertama.m, &pertama.y);
    printf("Masukkan tanggal kedua[dd/mm/yyyy]\t : ");
    scanf("%d-%d-%d", &kedua.d, &kedua.m, &kedua.y);
    int isValid = sameDate(pertama, kedua);
    if (isValid)
    {
        printf("Kedua tanggal tsb sama");
    }
    else
    {
        printf("Kedua tanggal tsb tidak sama");
    }
}
