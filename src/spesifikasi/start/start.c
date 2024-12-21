#include <stdio.h>
#include "../../adt/mesinkata/mesinkata.h"
#include "../../adt/listuser/listuser.h"
#include "../../adt/arraydinBarang/arraydinBarang.h"
#include "../../adt/queue/queue.h"
#include "../../../utilities.h"
#include "../../adt/mesinkalimat/linemachine.h"

#include "start.h"

// Deklarasi global
ArrayDin barangList;
List userList;
Queue antrianQueue;

void debugBarang() {
    printf("\nDebug Barang Toko:\n");
    for (int i = 0; i < ArrLength(barangList); i++) {
        printf("Barang %d: Nama=%s, Harga=%d\n", i + 1, barangList.A[i].name, barangList.A[i].price);
    }
}

void debugPengguna() {
    printf("\nDebug Daftar Pengguna:\n");
    for (int i = 0; i < ListUserLength(userList); i++) {
        char nama[MAX_LEN], password[MAX_LEN];
        GetName(userList, i, nama);
        GetPassword(userList, i, password);
        printf("Pengguna %d: Nama=%s, Password=%s, Saldo=%d\n", i + 1, nama, password, GetMoney(userList, i));
    }
}

void debugAntrian() {
    printf("\nDebug Antrian Permintaan:\n");
    displayQueue(antrianQueue);
}

void START_READ(char filename[]) {
    // Inisialisasi data yang diperlukan
    barangList = MakeArrayDin();
    MakeList(&userList);
    CreateQueue(&antrianQueue);

    // Membaca file konfigurasi
    printf("Membaca file konfigurasi...\n");
    STARTFILE(filename);

    // Membaca jumlah barang
    ADVWORD(); // Membaca jumlah barang
    int jumlahBarang = arrayToInteger(currentWord.TabWord, currentWord.Length);
    printf("Jumlah barang: %d\n", jumlahBarang);
    ADVWORD(); // Skip newline atau spasi

    // Membaca data barang
    for (int i = 0; i < jumlahBarang; i++) {
        // Membaca harga barang
        int hargaBarang = arrayToInteger(currentWord.TabWord, currentWord.Length);
        ADV(); // Skip spasi

        // Membaca nama barang
        char namaBarang[101]; // Maksimal 100 karakter
        SalinKalimat(); 
        copyString(namaBarang, currentLine.TabLine);

        printf("Barang %d: Nama=%s, Harga=%d\n", i + 1, namaBarang, hargaBarang);

        // Tambahkan barang ke array dinamis
        ArrInsertLast(&barangList, namaBarang, hargaBarang);
        ADVWORD(); // Skip newline atau spasi
    }

    // Membaca jumlah pengguna
    int jumlahPengguna = arrayToInteger(currentWord.TabWord, currentWord.Length);
    printf("Jumlah pengguna: %d\n", jumlahPengguna);
    ADVWORD(); // Skip newline atau spasi

    // Membaca data pengguna
    for (int i = 0; i < jumlahPengguna; i++) {
        // Membaca saldo pengguna
        int saldoPengguna = arrayToInteger(currentWord.TabWord, currentWord.Length);
        ClearBuffer();
        ADVWORD();
        // Membaca nama pengguna
        char namaPengguna[NMax];
        CopyWord();
        copyString(namaPengguna, currentWord.TabWord);
        printf("Pengguna %d: Nama=%s, Saldo=%d\n", i + 1, currentWord.TabWord, saldoPengguna);

        // Membaca password pengguna
        char passwordPengguna[NMax];
        ADVWORD();
        copyString(passwordPengguna, currentWord.TabWord);

        printf("Pengguna %d: Nama=%s, Password=%s, Saldo=%d\n", i + 1, namaPengguna, passwordPengguna, saldoPengguna);

        // Inisialisasi ADT lainnya
        Map keranjang;
        Stack riwayatPembelian;
        LinkedList wishlist;
        CreateMapEmpty(&keranjang);
        CreateStackEmpty(&riwayatPembelian);
        CreateLinkedListEmpty(&wishlist);

        // Membaca riwayat pembelian
        ADVWORD();
        int jumlahRiwayat = arrayToInteger(currentWord.TabWord, currentWord.Length);
        ADVWORD();

        for (int j = 0; j < jumlahRiwayat; j++) {
            int totalBiaya = arrayToInteger(currentWord.TabWord, currentWord.Length);
            ADV();

            // Membaca nama barang di riwayat
            char namaBarang[101];
            SalinKalimat();
            copyString(namaBarang, currentLine.TabLine);
            ADVWORD();

            printf("Riwayat %d: Nama=%s, Harga=%d\n", j + 1, namaBarang, totalBiaya);

            // Tambahkan ke riwayat pembelian
            Push(&riwayatPembelian, namaBarang, totalBiaya);
        }

        // Membaca wishlist

        int jumlahWishlist = arrayToInteger(currentWord.TabWord, currentWord.Length);

        for (int j = 0; j < jumlahWishlist; j++) {
            ADV();

            // Membaca nama wishlist
            char namaWishlist[101];
            SalinKalimat();
            copyString(namaWishlist, currentLine.TabLine);

            printf("Wishlist %d: Nama=%s\n", j + 1, namaWishlist);

            // Tambahkan ke wishlist
            AddToWishlist(&userList.A[i], namaWishlist);
        }

        // Tambahkan pengguna ke list
        InsertListLast(&userList, saldoPengguna, namaPengguna, passwordPengguna, keranjang, riwayatPembelian, wishlist);
        ADVWORD(); // Skip newline atau spasi
    }

    printf("Konfigurasi aplikasi berhasil dibaca. PURRMART siap digunakan.\n");

    // Debugging
    // debugBarang();
    // debugPengguna();
    // debugAntrian();
}

void START_PURRMART() {
    START_READ("config.txt");
}

int main() {
    printf("Memulai program PURRMART...\n");
    START_PURRMART();
    printf("Program selesai.\n");
    return 0;
}
