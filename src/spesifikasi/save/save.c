#include <stdio.h>
#include <stdlib.h>
#include "save.h"

void Save(ArrayDin Info, List User) {
    // KAMUS
    int i, j;
    FILE *file;
    char folder[] = "../../data/";
    char filename[100] = "";
    char fullpath[150] = "";
    char txt[] = ".txt";

    // ALGORITMA
    STARTWORD();

    // Membaca nama file dari CurrentWord
    i = 0;
    while (CurrentWord.TabWord[i] != '\0') {
        filename[i] = CurrentWord.TabWord[i];
        i++;
    }
    filename[i] = '\0';

    // Membuat fullpath
    copyString(fullpath, folder);
    stringConcat(fullpath, filename);
    stringConcat(fullpath, txt);

    // Membuka file untuk penulisan
    file = fopen(fullpath, "w");
    if (file == NULL) {
        printf("Error: Tidak dapat membuka file %s untuk penulisan.\n", fullpath);
        return;
    }

    // Menulis data barang
    fprintf(file, "%d\n", Info.Neff); 
    for (i = 0; i < Info.Neff; i++) {
        fprintf(file, "%d ", HargaBarang(Info.A[i]));
        j = 0;
        while (NamaBarang(&(Info.A[i]))[j] != '\0') {
            fprintf(file, "%c", NamaBarang(&(Info.A[i]))[j]); 
            j++;
        }
        fprintf(file, "\n"); 
    }

    // Menulis data user
    fprintf(file, "%d\n", Length(User));
    for (i = 0; i < Length(User); i++) {
        fprintf(file, "%d ", GetMoney(User, i));
        j = 0;
        while (User.A[i].name[j] != '\0') {
            fprintf(file, "%c", User.A[i].name[j]);
            j++;
        }
        fprintf(file, " ");
        j = 0;
        while (User.A[i].password[j] != '\0') {
            fprintf(file, "%c", User.A[i].password[j]); 
            j++;
        }
        fprintf(file, "\n"); 
    }

    // Menutup file
    if (fclose(file) != 0) {
        printf("Error: Gagal menutup file %s dengan benar.\n", fullpath);
        return;
    }

    // Notifikasi keberhasilan
    printf("Save file berhasil disimpan di %s.\n", fullpath);
}
