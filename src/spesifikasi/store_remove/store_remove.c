#include <stdio.h>
#include "store_remove.h"
#include "store_list.h"

void main() {
    char barang[MAX_LEN];
    boolean foundList = false;
    int select = 0;

    ArrayDin Info = MakeArrayDin();
    ListBarang(&Info);

    printf("Nama barang yang akan dihapus: ");
    scanf("%s", &barang);

    if (!IsEmpty(Info)) {
        while (select < Length(Info) && !foundList) {
            if (!CompareItem(Info.A[select].name, barang)) {
                foundList = true;
            } else {
                select++;
            }
        }
    }

    select = 0;
    if (foundList) {
        StoreList(Info);
        while (barang[select] != '\0') {
            printf("%c", barang[select]);
            select++;
        }
        printf(" telah berhasil dihapus.\n");
        DeleteAt(&Info, barang);
        StoreList(Info);
    } else {
        printf("Toko tidak menjual ");
        while (barang[select] != '\0') {
            printf("%c", barang[select]);
            select++;
        }
        printf("\n");
    }
}
