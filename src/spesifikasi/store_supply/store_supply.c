#include <stdio.h>
#include "store_supply.h"

void StoreSupply() {
    char perintah[MAX_LEN];
    char save[MAX_LEN];
    int harga, i = 0;
    boolean finish = false;
    Queue request;

    ArrayDin Info = MakeArrayDin();
    ListBarang(&Info);
        
    CreateQueue(&request);

    while (!finish) {
        printf("Apakah kamu ingin menambahkan barang ");
        i = 0;
        while (HEAD(request).name[i] != '\0') {
            printf("%c",HEAD(request).name[i]);
            i++;
        }
        printf(": ");

        if (perintah[0] == 'T'
        && perintah[1] == 'e'
        && perintah[2] == 'r'
        && perintah[3] == 'i'
        && perintah[4] == 'm'
        && perintah[5] == 'a') {
            printf("Harga barang: ");
            scanf("%d", &harga);
            InsertAt(&Info, HEAD(request).name, harga, Length(Info));
            dequeue(&request, save);
        } else if (perintah[0] == 'T'
        && perintah[1] == 'u'
        && perintah[2] == 'n'
        && perintah[3] == 'd'
        && perintah[4] == 'a') {
            displayQueue(request);
            dequeue(&request, save);
            displayQueue(request);
            enqueue(&request, save);
            displayQueue(request);
            break;
        } else if (perintah[0] == 'T'
        && perintah[1] == 'o'
        && perintah[2] == 'l'
        && perintah[3] == 'a'
        && perintah[4] == 'k') {
            displayQueue(request);
            dequeue(&request, save);
            displayQueue(request);
            break;
        } else if (perintah[0] == 'P'
        && perintah[1] == 'u'
        && perintah[2] == 'r'
        && perintah[3] == 'r'
        && perintah[4] == 'y') {
            finish = true;
            printf("Program selesai");
        } else {
            printf("Input tidak valid");
        }
    }
}
