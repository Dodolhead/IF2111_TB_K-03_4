#include <stdio.h>
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
    printf("[DEBUG] Memulai START_READ dengan file: %s\n", filename);

    // Inisialisasi data yang diperlukan
    barangList = MakeArrayDin();
    printf("[DEBUG] barangList berhasil dibuat.\n");
    MakeList(&userList);
    printf("[DEBUG] userList berhasil dibuat.\n");
    CreateQueue(&antrianQueue);
    printf("[DEBUG] antrianQueue berhasil dibuat.\n");

    // Membaca file konfigurasi
    printf("[DEBUG] Membaca file konfigurasi...\n");
    STARTFILE(filename);

    // Membaca jumlah barang
    ADVWORD(); // Membaca jumlah barang
    int jumlahBarang = arrayToInteger(currentWord.TabWord, currentWord.Length);
    printf("[DEBUG] Jumlah barang: %d\n", jumlahBarang);
    ADVWORD(); // Skip newline atau spasi

    // Membaca data barang
    for (int i = 0; i < jumlahBarang; i++) {
        printf("[DEBUG] Membaca barang ke-%d...\n", i + 1);
        int hargaBarang = arrayToInteger(currentWord.TabWord, currentWord.Length);
        ADV(); // Skip spasi

        char namaBarang[101]; // Maksimal 100 karakter
        SalinKalimat();
        copyString(namaBarang, currentLine.TabLine);

        printf("[DEBUG] Barang %d: Nama=%s, Harga=%d\n", i + 1, namaBarang, hargaBarang);

        // Tambahkan barang ke array dinamis
        ArrInsertLast(&barangList, namaBarang, hargaBarang);
        printf("[DEBUG] Barang ke-%d berhasil ditambahkan ke barangList.\n", i + 1);
        ADVWORD(); // Skip newline atau spasi
    }

    // Membaca jumlah pengguna
    int jumlahPengguna = arrayToInteger(currentWord.TabWord, currentWord.Length);
    printf("[DEBUG] Jumlah pengguna: %d\n", jumlahPengguna);
    ADVWORD(); // Skip newline atau spasi

    // Membaca data pengguna
    for (int i = 0; i < jumlahPengguna; i++) {
        printf("[DEBUG] Membaca pengguna ke-%d...\n", i + 1);
        int saldoPengguna = arrayToInteger(currentWord.TabWord, currentWord.Length);
        ClearBuffer();
        ADVWORD();

        // Membaca nama pengguna
        char namaPengguna[NMax];
        CopyWord();
        copyString(namaPengguna, currentWord.TabWord);
        printf("[DEBUG] Pengguna %d: Nama=%s, Saldo=%d\n", i + 1, currentWord.TabWord, saldoPengguna);

        // Membaca password pengguna
        char passwordPengguna[NMax];
        ADVWORD();
        copyString(passwordPengguna, currentWord.TabWord);

        printf("[DEBUG] Pengguna %d: Nama=%s, Password=%s, Saldo=%d\n", i + 1, namaPengguna, passwordPengguna, saldoPengguna);

        // Inisialisasi ADT lainnya
        Map keranjang;
        Stack riwayatPembelian;
        LinkedList wishlist;
        CreateMapEmpty(&keranjang);
        printf("[DEBUG] Keranjang berhasil diinisialisasi.\n");
        CreateStackEmpty(&riwayatPembelian);
        printf("[DEBUG] Riwayat pembelian berhasil diinisialisasi.\n");
        CreateLinkedListEmpty(&wishlist);
        printf("[DEBUG] Wishlist berhasil diinisialisasi.\n");

        // Membaca riwayat pembelian
        ADVWORD();
        int jumlahRiwayat = arrayToInteger(currentWord.TabWord, currentWord.Length);
        printf("[DEBUG] Jumlah riwayat pembelian pengguna ke-%d: %d\n", i + 1, jumlahRiwayat);
        ADVWORD();

        for (int j = 0; j < jumlahRiwayat; j++) {
            printf("[DEBUG] Membaca riwayat pembelian ke-%d untuk pengguna ke-%d...\n", j + 1, i + 1);
            int totalBiaya = arrayToInteger(currentWord.TabWord, currentWord.Length);
            ADV();

            // Membaca nama barang di riwayat
            char namaBarang[101];
            SalinKalimat();
            copyString(namaBarang, currentLine.TabLine);
            ADVWORD();

            printf("[DEBUG] Riwayat %d: Nama=%s, Harga=%d\n", j + 1, namaBarang, totalBiaya);

            // Tambahkan ke riwayat pembelian
            Push(&riwayatPembelian, namaBarang, totalBiaya);
            printf("[DEBUG] Riwayat ke-%d berhasil ditambahkan ke riwayat pembelian.\n", j + 1);
        }

        // Membaca wishlist
        int jumlahWishlist = arrayToInteger(currentWord.TabWord, currentWord.Length);
        ADV(); // Skip newline atau spasi
        printf("[DEBUG] Jumlah wishlist pengguna ke-%d: %d\n", i + 1, jumlahWishlist);

        // Initialize wishlist
        CreateLinkedListEmpty(&wishlist);

        for (int j = 0; j < jumlahWishlist; j++) {
            
            ClearBuffer();
            // Membaca nama wishlist
            char namaWishlist[101];
            SalinKalimat();
            
            printf ("[DEBUG] Wishlist: %s\n", currentLine.TabLine);
            copyString(namaWishlist, currentLine.TabLine);

            printf("[DEBUG] Wishlist %d: Nama=%s\n", j + 1, namaWishlist);
            ADV();
            // Tambahkan ke wishlist
            AddToWishlist(&userList.A[i], namaWishlist);
            printf("[DEBUG] Wishlist ke-%d berhasil ditambahkan.\n", j + 1);


        }

        // Tambahkan pengguna ke list
        InsertListLast(&userList, saldoPengguna, namaPengguna, passwordPengguna, keranjang, riwayatPembelian, wishlist);
        printf("[DEBUG] Pengguna ke-%d berhasil ditambahkan ke userList.\n", i + 1);
        ADVWORD(); // Skip newline atau spasi
    }

    printf("[DEBUG] Konfigurasi aplikasi berhasil dibaca.\n");
}

void START_PURRMART() {
    printf("[DEBUG] Memulai START_PURRMART...\n");
    START_READ("config.txt");
}
void START_PURRMART(char filename[]) {
    START_READ(filename);
}

// int main() {
//     printf("[DEBUG] Memulai program PURRMART...\n");
//     START_PURRMART();
//     printf("[DEBUG] Program selesai.\n");
//     return 0;
// }
