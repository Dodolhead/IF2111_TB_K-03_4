#include <stdio.h>
#include "store_remove.h"

void StoreRemove(ArrayDin Info) {
    // KAMUS
    boolean foundList = false;
    int select = 0;
    char name[50];
    
    // ALGORITMA
    printf("Nama barang yang akan dihapus: ");
    
    // Membaca kata pertama nama barang
    ADVWORD();
    copyString(name, currentWord.TabWord);

    // Jika nama barang lebih dari satu kata
    while (GetCC() != '\n') {
        ADVWORD();
            name[stringLength(name)] = BLANK;
            stringConcat(name, currentWord.TabWord);
    }

    // Mencetak nama barang
    for (int i = 0; name[i] != '\0'; i++) {
        printf("%c", name[i]);
    }
    printf("\n");

    // Mengecek ketersediaan barang dalam toko
    if (!IsArrDinEmpty(Info)) {
        for (int j = 0; j < ArrLength(Info) && !foundList; j++) {
            if (stringEquals(NamaBarang(&(Info.A[j])), name)) {
                foundList = true;
            }
        }
    } else {
        printf("ERROR: Toko Kosong!");
    }

    if (foundList) {
        for (int k = 0; name[k] != '\0'; k++) {
            printf("%c", name[k]);
        }
        printf(" telah berhasil dihapus.\n");
        ArrDeleteAt(&Info, name);
    } else {
        printf("Toko tidak menjual ");
        for (int a = 0; name[a] != '\0'; a++) {
            printf("%c", name[a]);
        }
        printf("\n");
    }
}


int main() {
    ArrayDin Info = MakeArrayDin();

    char item[] = "Kata";
    ArrInsertLast(&Info, item, 100);

    StoreRemove(Info);

    return 0;
}

