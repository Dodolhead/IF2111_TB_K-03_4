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

void START_PURRMART() {
    // Inisialisasi data yang diperlukan
    ArrayDin barangList = MakeArrayDin();
    List userList = MakeList();
    Queue antrianQueue;
    CreateQueue(&antrianQueue);

    // Membaca file konfigurasi default
    printf("Membaca file konfigurasi default...\n");
    STARTFILE("config.txt");
    ADVANGKA(); // Mengabaikan jumlah barang
    int jumlahBarang = currentAngka;
    printf("Jumlah barang: %d\n", jumlahBarang);
    ADVWORD(); // Mengabaikan newline
    // Membaca detail barang
    for (int i = 0; i < jumlahBarang; i++) {
        if (!isEndWord()) {
            int hargaBarang = arrayToInteger(currentWord.TabWord, currentWord.Length);
            ADVWORD();
            printf("Harga barang: %d\n", hargaBarang);

            char namaBarang[MAX_LEN];
            CopySentence();
            copyString(namaBarang, currentWord);
            ADVWORD();
            printf("Nama barang: %s\n", namaBarang);

            ArrInsertLast(&barangList, namaBarang, hargaBarang);
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

        InsertListLast(&userList, saldoPengguna, namaPengguna, passwordPengguna, keranjang, riwayatPembelian, wishlist);
    }

    printf("Konfigurasi aplikasi berhasil dibaca. PURRMART siap digunakan.\n");
    
    // Debugging output
    // debugBarang();
    // debugPengguna();
    // debugAntrian();
}

int main() {
    printf("Memulai program PURRMART...\n");
    START_PURRMART();
    printf("Program selesai.\n");
    return 0;
}
