#include <stdio.h>
#include "../../adt/mesinkata/mesinkata.h"
#include "../../adt/listuser/listuser.h"
#include "../../adt/arraydinBarang/arraydinBarang.h"
#include "../../adt/queue/queue.h"

// Deklarasi global
ArrayDin barangToko;
List daftarPengguna;
Queue antrianPermintaan;

void debugBarang() {
    printf("\nDebug Barang Toko:\n");
    for (int i = 0; i < ArrLength(barangToko); i++) {
        printf("Barang %d: Nama=%s, Harga=%d\n", i + 1, barangToko.A[i].name, barangToko.A[i].price);
    }
}

void debugPengguna() {
    printf("\nDebug Daftar Pengguna:\n");
    for (int i = 0; i < ListUserLength(daftarPengguna); i++) {
        char nama[MAX_LEN], password[MAX_LEN];
        GetName(daftarPengguna, i, nama);
        GetPassword(daftarPengguna, i, password);
        printf("Pengguna %d: Nama=%s, Password=%s, Saldo=%d\n", i + 1, nama, password, GetMoney(daftarPengguna, i));
    }
}

void debugAntrian() {
    printf("\nDebug Antrian Permintaan:\n");
    displayQueue(antrianPermintaan);
}

void START() {
    // Inisialisasi data yang diperlukan
    barangToko = MakeArrayDin();
    daftarPengguna = MakeList();
    CreateQueue(&antrianPermintaan);

    // Membaca file konfigurasi default
    printf("Membaca file konfigurasi default...\n");
    STARTWORD("default.txt");

    // Membaca jumlah barang
    int jumlahBarang = 0;
    if (!isEndWord()) {
        jumlahBarang = arrayToInteger(currentWord.TabWord, currentWord.Length);
        ADVWORD();
    }

    // Membaca detail barang
    for (int i = 0; i < jumlahBarang; i++) {
        if (!isEndWord()) {
            int hargaBarang = arrayToInteger(currentWord.TabWord, currentWord.Length);
            ADVWORD();

            char namaBarang[MAX_LEN];
            copyString(namaBarang, currentWord.TabWord);
            ADVWORD();

            ArrInsertLast(&barangToko, namaBarang, hargaBarang);
        }
    }

    // Membaca jumlah pengguna
    int jumlahPengguna = 0;
    if (!isEndWord()) {
        jumlahPengguna = arrayToInteger(currentWord.TabWord, currentWord.Length);
        ADVWORD();
    }

    // Membaca detail pengguna
    for (int i = 0; i < jumlahPengguna; i++) {
        char namaPengguna[MAX_LEN];
        char passwordPengguna[MAX_LEN];
        int saldoPengguna = 0;

        if (!isEndWord()) {
            saldoPengguna = arrayToInteger(currentWord.TabWord, currentWord.Length);
            ADVWORD();
        }

        if (!isEndWord()) {
            copyString(namaPengguna, currentWord.TabWord);
            ADVWORD();
        }

        if (!isEndWord()) {
            copyString(passwordPengguna, currentWord.TabWord);
            ADVWORD();
        }

        Map keranjang;
        Stack riwayatPembelian;
        LinkedList wishlist;
        
        CreateMapEmpty(&keranjang);
        CreateStackEmpty(&riwayatPembelian);
        CreateLinkedListEmpty(&wishlist);

        InsertListLast(&daftarPengguna, saldoPengguna, namaPengguna, passwordPengguna, keranjang, riwayatPembelian, wishlist);
    }

    printf("Konfigurasi aplikasi berhasil dibaca. PURRMART siap digunakan.\n");
    
    // Debugging output
    debugBarang();
    debugPengguna();
    debugAntrian();
}

int main() {
    printf("Memulai program PURRMART...\n");
    START();
    printf("Program selesai.\n");
    return 0;
}
