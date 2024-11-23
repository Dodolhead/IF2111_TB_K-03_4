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

    int i = 0;
    while (CurrentWord.TabWord[i] != '\0') {
        filename[i] = CurrentWord.TabWord[i];
        i++;
    }
    filename[i] = '\0';

    copyString(fullpath, folder);
    stringConcat(fullpath, filename);
    stringConcat(fullpath, txt);

    file = fopen(fullpath, "w");

    // Menulis data barang
    fprintf(file, "%d \n", Info.Neff);
    for (i = 0; i < Info.Neff; i++) {
        fprintf(file, "%d ", HargaBarang(Info.A[i]));
        j = 0;
        while (NamaBarang(&(Info.A[i]))[j] != '\0') {
            fprintf(file, "%c", NamaBarang(&(Info.A[i]))[j]);
            j++;
        }
        fprintf(file, " \n");
    }

    // Menulis data user
    fprintf(file, "%d \n", Length(User));
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
        fprintf(file, " \n");
    }

    fclose(file);
}

/*
int main() {
    ArrayDin Info = MakeArrayDin();
    ListBarang(&Info);
    List User = MakeList();

    Save(Info, User);
    return 0;
}
*/
