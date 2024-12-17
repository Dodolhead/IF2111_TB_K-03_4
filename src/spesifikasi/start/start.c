#include "start.h"
#include "../../adt/mesinkata.h" 
#include "../../adt/mesinkarakter.h"
#include "../../spesifikasi/login/login.h"
#include "../../adt/mesinangka.h" 
#include "../../../utilities.h"
#include "../../adt/arraydinBarang.h"
#include <stdio.h>

void START_PURRMART(ArrayDin Informasi, List InfoUser){
    // KAMUS
    /* Barang */
    int baris, i;
    int items = 0, baris, harga = 0, panjang; 
    /* User */
    int user = 0, uang = 0;
    // ALGORITMA
    STARTWORD("src/data/config.txt");

    // Mengecek jumlah barang di toko
    for (i = 0; i < CurrentWord.Length; i++) {
        items = items * 10 + ((CurrentWord.TabWord[i]) - '0');
    }

    // Membaca barang dan menyimpan di dalam list
    if (items > 0) {
        // Membaca tiap baris (harga dan nama)
        for (baris = 1; baris <= items; i++) {
            harga = 0;

            // Menyalin harga barang
            ADVWORD();
            for (i = 0; i < CurrentWord.Length; i++) {
                if (CurrentWord.TabWord[i] >= '0' && CurrentWord.TabWord[i] <= '9') {
                    harga = harga * 10 + ((CurrentWord.TabWord[i]) - '0');
                }
            }

            // Mengecek ruang kosong
            if (!IsArrFull(Informasi)) {
                Informasi.A[baris-1].price = harga;
            }

            // Menyalin kata pertama dari nama barang
            ADVWORD();
            if (!IsArrFull(Informasi)) {
                for (i = 0; i < CurrentWord.Length; i++) {
                    Informasi.A[baris-1].name[i] = CurrentWord.TabWord[i];
                }
                panjang = CurrentWord.Length;
            }

            // Menyalin barang yang memiliki lebih dari satu kata
            while (GetCC() != '\n') {
                ADVWORD();

                if (!IsArrFull(Informasi)) {
                    Informasi.A[baris].name[panjang] = BLANK;
                    panjang++;

                    for (j = 0; j < CurrentWord.Length; j++) {
                        Informasi.A[baris].name[j+panjang] = CurrentWord.TabWord[j];
                    }
                    panjang = panjang + CurrentWord.Length;

                    Informasi.A[baris].name[panjang] = '\0';
                }
            }
        }
    }

    ADVWORD();

    // Mengecek jumlah user di toko
    for (i = 0; i < CurrentWord.Length; i++) {
        user = user * 10 + ((CurrentWord.TabWord[i]) - '0');
    }

    if (user > 0) {
        // Membaca tiap baris
        for (baris = 1; baris <= user; i++) {
            uang = 0;

            // Menyalin uang pengguna
            ADVWORD();
            for (i = 0; i < CurrentWord.Length; i++) {
                if (CurrentWord.TabWord[i] >= '0' && CurrentWord.TabWord[i] <= '9') {
                    uang = uang * 10 + ((CurrentWord.TabWord[i]) - '0');
                }
            }

            // Mengecek ruang kosong
                InfoUser.ElList[baris-1].money = uang;

            // Menyalin username
            ADVWORD();
                for (i = 0; i < CurrentWord.Length; i++) {
                    InfoUser.ElList[baris-1].name[i] = CurrentWord.TabWord[i];
                }
                InfoUser.ElList[baris-1].name[i] = '\0'

            // Menyalin password
            ADVWORD();
                for (i = 0; i < CurrentWord.Length; i++) {
                    InfoUser.ElList[baris-1].password[i] = CurrentWord.TabWord[i];
                }
                InfoUser.ElList[baris-1].password[i] = '\0'
        }
    }
    
    printf("File konfigurasi aplikasi berhasil dibaca. PURRMART berhasil dijalankan.\n");
}
