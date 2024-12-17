#ifndef CARTPAY_H
#define CARTPAY_H

#include "../../adt/user2.h"
#include "../../adt/map.h"
#include "../../adt/stack.h"
#include "../../adt/mesinkata.h"

/* *** Fungsi dan Prosedur untuk CART PAY *** */

/* Fungsi untuk menghitung total biaya semua barang dalam keranjang */
int TotalBiayaKeranjang(Map keranjang);

/* Fungsi untuk mencari barang dengan total harga terbesar dalam keranjang */
/* Jika ada harga yang sama, dipilih berdasarkan urutan lexical terbesar */
keytype BarangTermahal(Map keranjang);

/* Prosedur untuk memproses pembelian barang dalam keranjang */
void CART_PAY(User *U);

#endif /* CARTPAY_H */
