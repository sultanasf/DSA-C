#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maks 100

typedef struct
{
    char nama[maks];
    int nilaiTugas, nilaiUts, nilaiUas, nilaiAkhir;
    char grade;
} Biodata;
int n;

void input(Biodata *mhs)
{
    printf("Masukkan banyak mahasiswa : ");
    scanf("%d", &n);
    fflush(stdin);
    for (int i = 0; i < n; i++)
    {
        printf("\nData mahasiswa ke-%d\n", i + 1);
        printf("Nama\t\t: ");
        gets(mhs->nama);
        fflush(stdin);
        printf("Nilai tugas\t: ");
        scanf("%d", &mhs->nilaiTugas);
        fflush(stdin);
        printf("Nilai UTS\t: ");
        scanf("%d", &mhs->nilaiUts);
        fflush(stdin);
        printf("Nilai UAS\t: ");
        scanf("%d", &mhs->nilaiUas);
        fflush(stdin);
        mhs++;
    }
}

void tampil(Biodata *mhs)
{
    printf("\n\t\t\t\tDAFTAR NILAI");
    printf("\n\t\t\tMATAKULIAH KONSEP PEMROGRAMAN");
    printf("\n==================================================================");
    printf("\nNo\tNama Mahasiswa\tTugas\tUTS\tUAS\tAkhir\tGrade");
    printf("\n==================================================================");
    for (int i = 0; i < n; i++)
    {
        mhs->nilaiAkhir = 0.2 * mhs->nilaiTugas + 0.4 * mhs->nilaiUts + 0.4 * mhs->nilaiUas;
        if (mhs->nilaiAkhir >= 80 && mhs->nilaiAkhir < 100)
        {
            mhs->grade = 'A';
        }
        else if (mhs->nilaiAkhir >= 70)
        {
            mhs->grade = 'B';
        }
        else if (mhs->nilaiAkhir >= 60)
        {
            mhs->grade = 'C';
        }
        else if (mhs->nilaiAkhir >= 50)
        {
            mhs->grade = 'D';
        }
        else if (mhs->nilaiAkhir < 50 && mhs->nilaiAkhir >= 0)
        {
            mhs->grade = 'E';
        }
        else
        {
            mhs->grade = '0';
        }
        printf("\n%d\t%s\t\t%d\t%d\t%d\t%d\t%c", i + 1, mhs->nama, mhs->nilaiTugas, mhs->nilaiUts, mhs->nilaiUas, mhs->nilaiAkhir, mhs->grade);
        mhs++;
    }
}

int main()
{
    Biodata mhs[maks];
    input(mhs);
    tampil(mhs);
}