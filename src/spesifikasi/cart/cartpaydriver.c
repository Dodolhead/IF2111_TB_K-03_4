#include <stdio.h>
#include "cart_pay.h"
#include "../../adt/listuser/listuser.h"
#include "../../adt/map/map.h"
#include "../../adt/stack/stack.h"

int main() {
    // Deklarasi variabel
    User user;
    char name[50], password[50];
    int saldo;

    // Input data user
    printf("=== Selamat Datang di PURRMART ===\n");
    printf("Masukkan nama user: ");
    scanf("%s", name);
    printf("Masukkan password: ");
    scanf("%s", password);
    printf("Masukkan saldo awal: ");
    scanf("%d", &saldo);

    // Inisialisasi user
    CreateUser(&user, name, password, saldo);

    // Menambahkan barang ke keranjang
    AddToKeranjang(&user, "AK47", 200);
    AddToKeranjang(&user, "Lalabu", 200);
    AddToKeranjang(&user, "M16", 120);

    // Menampilkan informasi user
    PrintUserInfo(&user);

    // Proses pembayaran
    CartPay(&user);

    // Informasi user setelah transaksi
    PrintUserInfo(&user);

}
