#ifndef BARANG_H
#define BARANG_H

#define MAX_LEN 100
#define NULL -1

typedef struct {
        char name[MAX_LEN];
        int price;
} Barang;

#endif