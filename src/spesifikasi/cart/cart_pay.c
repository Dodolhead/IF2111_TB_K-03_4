#include "cart_pay.h"
#include <stdio.h>
int TotalBiayaKeranjang(Map keranjang) {
    int total = 0;
    for (int i = 0; i < keranjang.Count; i++) {
        if (keranjang.Elements[i].Value < 0) { // Harga invalid
            printf("Error: Harga barang '%s' tidak valid!\n", keranjang.Elements[i].Key);
            return -1; // Return kode error
        }
        total += keranjang.Elements[i].Value;
    }
    return total;
}

keytype BarangTermahal(Map keranjang) {
    keytype barangMax = keranjang.Elements[0].Key;
    int hargaMax = keranjang.Elements[0].Value;

    for (int i = 1; i < keranjang.Count; i++) {
        if (keranjang.Elements[i].Value > hargaMax ||
           (keranjang.Elements[i].Value == hargaMax &&
            stringEquals(keranjang.Elements[i].Key, barangMax) != 0)) {
            barangMax = keranjang.Elements[i].Key;
            hargaMax = keranjang.Elements[i].Value;
        }
    }
    return barangMax;
}

void CartPay(User *U) {
    if (IsMapEmpty(&U->keranjang)) {
        printf("Error: Keranjang kamu kosong!\n");
        return;
    }

    int totalBiaya = TotalBiayaKeranjang(U->keranjang);
    if (totalBiaya == -1) { // Harga invalid
        printf("Error: Proses pembayaran dihentikan karena harga barang tidak valid.\n");
        return;
    }

    printf("Kamu akan membeli barang-barang berikut:\n");
    for (int i = 0; i < U->keranjang.Count; i++) {
        printf("%s - Total: %d\n", U->keranjang.Elements[i].Key, U->keranjang.Elements[i].Value);
    }
    printf("Total biaya yang harus dikeluarkan adalah %d.\n", totalBiaya);
    printf("Apakah jadi dibeli? (Ya/Tidak): ");

    STARTWORD();
    if (stringEquals(currentWord.TabWord, "Ya")) {
        if (U->money >= totalBiaya) {
            U->money -= totalBiaya;
            keytype barangMax = BarangTermahal(U->keranjang);
            Push(&(U->riwayat_pembelian), barangMax, U->keranjang.Count);
            CreateMapEmpty(&(U->keranjang));
            printf("Selamat! Kamu telah membeli barang-barang tersebut!\n");
        } else {
            printf("Error: Uang kamu hanya %d, tidak cukup untuk membeli keranjang!\n", U->money);
        }
    } else if (stringEquals(currentWord.TabWord, "Tidak")) {
        printf("Pembelian dibatalkan!\n");
    } else {
        printf("Error: Input tidak valid! Harap masukkan 'Ya' atau 'Tidak'.\n");
    }
}
