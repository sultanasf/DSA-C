#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int d, m, y;
} Date;

int isYounger(Date pertama, Date kedua)
{
    if (pertama.y < kedua.y)
    {
        return 0;
    }
    else if (pertama.y == kedua.y)
    {
        if (pertama.m < kedua.m)
        {
            return 0;
        }
        else if (pertama.m == kedua.m)
        {
            if (pertama.d <= kedua.d)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 1;
    }
}

int main()
{
    Date pertama;
    Date kedua;
    printf("Masukkan tanggal lahir mhs pertama[dd/mm/yyyy]\t : ");
    scanf("%d-%d-%d", &pertama.d, &pertama.m, &pertama.y);
    printf("Masukkan tanggal lahir mhs kedua[dd/mm/yyyy]\t : ");
    scanf("%d-%d-%d", &kedua.d, &kedua.m, &kedua.y);
    int isValid = isYounger(pertama, kedua);
    if (isValid)
    {
        printf("Benar, mahasiswa pertama lebih muda dibanding mahasiswa kedua");
    }
    else
    {
        printf("Salah, mahasiswa pertama tidak lebih muda dibanding mahasiswa kedua");
    }
}
