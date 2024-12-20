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


void START_READ() {
    // Inisialisasi data yang diperlukan
    barangList = MakeArrayDin();
    userList = MakeList();
    CreateQueue(&antrianQueue);

    // Membaca file konfigurasi default
    printf("Membaca file konfigurasi default...\n");
    STARTFILE("config.txt");
    ADVWORD(); // Membaca kata "Barang"
    int jumlahBarang = arrayToInteger(currentWord.TabWord, currentWord.Length);
    printf("Jumlah barang: %d\n", jumlahBarang);
    ADVWORD(); // Skip newline atau spasi

    // Membaca data barang
    for (int i = 0; i < jumlahBarang; i++) { // Membaca harga barang
        int hargaBarang = arrayToInteger(currentWord.TabWord, currentWord.Length);
        ADV(); // Skip spasi
        SalinKalimat(); // Membaca nama barang
        Kalimat namaBarang;
        copyKalimat(currentLine, &namaBarang);
        //printf("Barang %d: Nama=%s, Harga=%d\n", i + 1, &namaBarang, hargaBarang);
        ADVWORD(); // Skip newline atau spasi
        ArrInsertLast(&barangList, &namaBarang, hargaBarang);
    }

    int jumlahPengguna = arrayToInteger(currentWord.TabWord, currentWord.Length);
    printf("Jumlah pengguna: %d\n", jumlahPengguna);
    ADVWORD(); // Skip newline atau spasi

    // Membaca data pengguna
    for (int i = 0; i < jumlahPengguna; i++) {
         // Membaca saldo pengguna
        int saldoPengguna = arrayToInteger(currentWord.TabWord, currentWord.Length);
        ADVSATUKATA(); // Skip spasi// Membaca nama pengguna
        Kalimat namaPengguna;
        copyKalimat(currentLine, &namaPengguna);
        ADV(); // Skip spasi
        SalinKalimat(); // Membaca password pengguna
        Kalimat passwordPengguna;
        copyKalimat(currentLine, &passwordPengguna);
        //printf("Pengguna %d: Nama=%s, Password=%s, Saldo=%d\n", i + 1, namaPengguna, passwordPengguna, saldoPengguna);
    
        // Inisialisasi ADT lainnya
        Map keranjang;
        Stack riwayatPembelian;
        LinkedList wishlist;
        CreateMapEmpty(&keranjang);
        CreateStackEmpty(&riwayatPembelian);
        CreateLinkedListEmpty(&wishlist);

        ADVWORD(); // Banyaknya riwayat pembelian
        int jumlahRiwayat = arrayToInteger(currentWord.TabWord, currentWord.Length);
        ADVWORD();

        for (int j = 0; j < jumlahRiwayat; j++) {
            int totalBiaya = arrayToInteger(currentWord.TabWord, currentWord.Length);
            ADV();
            SalinKalimat(); // Nama barang
            Kalimat namaBarang;
            copyKalimat(currentLine, &namaBarang);
            //printf("Riwayat %d: Nama=%s, Harga=%d\n", j + 1, namaBarang, totalBiaya);
            ADVWORD(); // Skip newline atau spasi
            // Push(&riwayatPembelian, namaBarang, totalBiaya);
        }

        int jumlahWishlist = arrayToInteger(currentWord.TabWord, currentWord.Length);
        for (int j = 0; j < jumlahWishlist; j++) {
            ADV();
            SalinKalimat(); // Nama barang di wishlist
            Kalimat namaWishlist;
            copyKalimat(currentLine, &namaWishlist);
            //printf("Wishlist %d: Nama=%s\n", j + 1, namaWishlist);

            // AddToWishlist(&wishlist, namaWishlist); 
        }
        ADVWORD(); // Skip newline atau spasi
        //InsertListLast(&userList, saldoPengguna, namaPengguna, passwordPengguna, keranjang, riwayatPembelian, wishlist);
    }

    printf("Konfigurasi aplikasi berhasil dibaca. PURRMART siap digunakan.\n");

//     debugBarang();
//     debugPengguna();
//     debugAntrian();
 }


int main() {
    printf("Memulai program PURRMART...\n");
    START_READ();
    printf("Program selesai.\n");
    return 0;
}
