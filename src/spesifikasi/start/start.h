#ifndef START_H
#define START_H

#define MAX_LEN 100
#define MAX_ITEMS 100
#define MAX_USERS 100

typedef struct {
    char name[MAX_LEN];
    int price;
} Barang;

typedef struct {
    char name[MAX_LEN];
    char password[MAX_LEN];
    int money;
} User;

void STARTREAD(Barang barang[], int *jumlahBarang, User users[], int *jumlahUsers);
void printBarang(Barang barang[], int jumlahBarang);
void printUsers(User users[], int jumlahUsers);
void STARTFILE(char *filename);

#endif
