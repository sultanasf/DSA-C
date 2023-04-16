#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maks 100

typedef struct
{
    int d, m, y;
} Date;
typedef struct
{
    int noId;
    char nama[maks], jenisKelamin;
    int gajiBulanan;
    Date birthday;
} Data;
int n;

void input(Data *pegawai)
{
    printf("Masukkan banyak pegawai : ");
    scanf("%d", &n);
    fflush(stdin);
    for (int i = 0; i < n; i++)
    {
        printf("\nData pegawai ke-%d\n", i + 1);
        printf("Nama\t\t\t: ");
        gets(pegawai->nama);
        fflush(stdin);
        printf("Tgl lahir(dd-mm-yyyy)\t: ");
        scanf("%d-%d-%d", &pegawai->birthday.d, &pegawai->birthday.m, &pegawai->birthday.y);
        fflush(stdin);
        printf("Jenis kelamin(L/P)\t: ");
        scanf("%c", &pegawai->jenisKelamin);
        fflush(stdin);
        printf("Gaji/bulan\t\t: ");
        scanf("%d", &pegawai->gajiBulanan);
        fflush(stdin);
        pegawai++;
    }
}

void tampil(Data *pegawai)
{
    int i;
    printf("\n===================================\n");
    printf("\nData pegawai yang telah diinputkan \n");
    for (i = 0; i < n; i++)
    {
        printf("\nData pegawai ke-%d", i + 1);
        printf("\nNama\t\t= %s", pegawai->nama);
        printf("\nTanggal lahir\t= %d-%d-%d", pegawai->birthday.d, pegawai->birthday.m, pegawai->birthday.y);
        if (pegawai->jenisKelamin == 'L' || pegawai->jenisKelamin == 'l')
            printf("\nJenis Kelamin\t= Laki-laki");
        else if (pegawai->jenisKelamin == 'P' || pegawai->jenisKelamin == 'p')
            printf("\nJenis Kelamin\t= Perempuan");
        printf("\nGaji perbulan\t= Rp. %d.00", pegawai->gajiBulanan);
        pegawai++;
    }
}

int main()
{
    Data pegawai[maks];
    input(pegawai);
    tampil(pegawai);
}
