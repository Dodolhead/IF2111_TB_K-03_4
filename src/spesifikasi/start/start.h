#ifndef START_H
#define START_H

#define MAX_LEN 100
#define MAX_ITEMS 100
#define MAX_USERS 100

#include "../../adt/barang.h"
#include "../../adt/listuser.h"

void STARTREAD(Barang barang[], int *jumlahBarang, User users[], int *jumlahUsers,char filename[]);
void START_PURRMART();

#endif
