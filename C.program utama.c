
#include <stdio.h>

float hitungAsuransi(int jenisLadang, float nilaiTanggungan) {
    float biayaStandar;
    float biayaAsuransi;

    biayaStandar = nilaiTanggungan * 3.5 / 100;

    if (jenisLadang == 1) {
        biayaAsuransi = biayaStandar * 2;
    } else {
        biayaAsuransi = biayaStandar * 1.5;
    }

    return biayaAsuransi;
}

int main() {
    char nama[50];
    int jumlahLadang;
    int jenisLadang;
    float nilaiPerHektar;
    float luas;
    float nilaiTanggungan;
    float biayaAsuransi;
    float totalAsuransi = 0;

    printf("Masukkan nama petani: ");
    scanf(" %49[^\n]", nama);

    printf("Masukkan jumlah jenis ladang (1-3): ");
    scanf("%d", &jumlahLadang);

    if (jumlahLadang < 1 || jumlahLadang > 3) {
        printf("Jumlah jenis ladang tidak valid.\n");
        return 0;
    }

    printf("\n===== SLIP PEMBAYARAN ASURANSI =====\n");
    printf("Nama petani: %s\n", nama);

    for (int i = 1; i <= jumlahLadang; i++) {
        printf("\nLADANG KE-%d\n", i);
        printf("1. Kelompok dengan tarif 2 kali standar\n");
        printf("2. Kelompok dengan tarif 1.5 kali standar\n");

        printf("Pilih jenis ladang: ");
        scanf("%d", &jenisLadang);

        if (jenisLadang != 1 && jenisLadang != 2) {
            printf("Jenis ladang tidak valid.\n");
            return 0;
        }

        printf("Nilai tanggungan per hektar (Rp): ");
        scanf("%f", &nilaiPerHektar);

        printf("Luas ladang (hektar): ");
        scanf("%f", &luas);

        nilaiTanggungan = nilaiPerHektar * luas;

        biayaAsuransi = hitungAsuransi(
            jenisLadang, nilaiTanggungan
        );

        printf("Nilai tanggungan total: Rp %.2f\n",
               nilaiTanggungan);
        printf("Biaya asuransi ladang ke-%d: Rp %.2f\n",
               i, biayaAsuransi);

        totalAsuransi = totalAsuransi + biayaAsuransi;
    }

    printf("\n====================================\n");
    printf("SLIP PEMBAYARAN\n");
    printf("Nama petani: %s\n", nama);
    printf("Jumlah jenis ladang: %d\n", jumlahLadang);
    printf("Total biaya asuransi: Rp %.2f\n", totalAsuransi);
    printf("====================================\n");

    return 0;
}
