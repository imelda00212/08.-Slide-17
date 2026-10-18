
#include <stdio.h>

float hitungAsuransi(int jenisLadang, float nilaiTanggungan) {
    float biayaStandar;
    float biayaAsuransi;

    biayaStandar = nilaiTanggungan * 3.5 / 100;

    if (jenisLadang == 1) {
        biayaAsuransi = biayaStandar * 2;
    } else if (jenisLadang == 2) {
        biayaAsuransi = biayaStandar * 1.5;
    } else {
        biayaAsuransi = 0;
    }

    return biayaAsuransi;
}

int main() {
    int jenisLadang;
    float nilaiTanggungan;
    float biayaAsuransi;

    printf("Jenis Ladang:\n");
    printf("1. Cabai, kentang, atau bawang merah\n");
    printf("2. Padi, singkong, atau jagung\n");
    printf("Masukkan pilihan jenis ladang: ");
    scanf("%d", &jenisLadang);

    printf("Masukkan nilai tanggungan kerugian tanah: Rp ");
    scanf("%f", &nilaiTanggungan);

    biayaAsuransi = hitungAsuransi(jenisLadang, nilaiTanggungan);

    if (jenisLadang == 1 || jenisLadang == 2) {
        printf("Biaya asuransi: Rp %.2f\n", biayaAsuransi);
    } else {
        printf("Jenis ladang tidak valid.\n");
    }

    return 0;
}
