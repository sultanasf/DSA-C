#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maks 100

struct biodata
{
    char nama[maks];
    int nilaiTugas, nilaiUts, nilaiUas, nilaiAkhir;
    char grade;
};
int n;

void input(struct biodata mhs[])
{
    printf("Masukkan banyak mahasiswa : ");
    scanf("%d", &n);
    fflush(stdin);
    for (int i = 0; i < n; i++)
    {
        printf("\nData mahasiswa ke-%d\n", i + 1);
        printf("Nama\t\t: ");
        gets(mhs[i].nama);
        fflush(stdin);
        printf("Nilai tugas\t: ");
        scanf("%d", &mhs[i].nilaiTugas);
        fflush(stdin);
        printf("Nilai UTS\t: ");
        scanf("%d", &mhs[i].nilaiUts);
        fflush(stdin);
        printf("Nilai UAS\t: ");
        scanf("%d", &mhs[i].nilaiUas);
        fflush(stdin);
    }
}

void tampil(struct biodata mhs[])
{
    for (int i = 0; i < n; i++)
    {
        mhs[i].nilaiAkhir = 0.2 * mhs[i].nilaiTugas + 0.4 * mhs[i].nilaiUts + 0.4 * mhs[i].nilaiUas;
        if (mhs[i].nilaiAkhir >= 80 && mhs[i].nilaiAkhir < 100)
        {
            mhs[i].grade = 'A';
        }
        else if (mhs[i].nilaiAkhir >= 70)
        {
            mhs[i].grade = 'B';
        }
        else if (mhs[i].nilaiAkhir >= 60)
        {
            mhs[i].grade = 'C';
        }
        else if (mhs[i].nilaiAkhir >= 50)
        {
            mhs[i].grade = 'D';
        }
        else if (mhs[i].nilaiAkhir < 50 && mhs[i].nilaiAkhir >= 0)
        {
            mhs[i].grade = 'E';
        }
        else
        {
            mhs[i].grade = '0';
        }
    }
    printf("\n\t\t\t\tDAFTAR NILAI");
    printf("\n\t\t\tMATAKULIAH KONSEP PEMROGRAMAN");
    printf("\n==================================================================");
    printf("\nNo\tNama Mahasiswa\tTugas\tUTS\tUAS\tAkhir\tGrade");
    printf("\n==================================================================");
    for (int i = 0; i < n; i++)
    {
        printf("\n%d\t%s\t\t%d\t%d\t%d\t%d\t%c", i + 1, mhs[i].nama, mhs[i].nilaiTugas, mhs[i].nilaiUts, mhs[i].nilaiUas, mhs[i].nilaiAkhir, mhs[i].grade);
    }
}

int main()
{
    struct biodata mhs[maks];
    input(mhs);
    tampil(mhs);
}
