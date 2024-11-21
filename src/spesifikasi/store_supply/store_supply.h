#include "queue.h"
#include "arraydinBarang.h"
#include "boolean.h"

void StoreSupply();
/*
Menambahkan barang baru ke dalam toko berdasarkan antrian permintaan. 
Barang yang berada pada antrian paling depan akan dimasukan ke toko. 
Pengguna dapat menerima, menunda, atau menolak permintaan. 
- Jika diterima, maka program akan meminta harga dari barang dan dimasukan ke toko. 
- Jika ditunda, maka barang akan kembali masuk ke antrian
- Jika ditolak, maka barang akan dihapus dari antrian
Harus terdapat validasi agar harga barang merupakan angka yang valid 
(berupa angka dan bernilai lebih dari nol).

Contoh input:
>> STORE SUPPLY
Apakah kamu ingin menambahkan barang AK47: Terima
Harga barang: 100

Contoh output:
AK47 dengan harga 100 telah ditambahkan ke toko.

Contoh input:
>> STORE SUPPLY
Apakah kamu ingin menambahkan barang AK47: Tunda
Harga barang: 100

Contoh output:
AK47 dengan harga 100 telah ditambahkan ke toko.

Contoh input:
>> STORE SUPPLY
Apakah kamu ingin menambahkan barang AK47: Tolak

Contoh output:
AK47 dihapuskan dari antrian.

Contoh input:
>> STORE SUPPLY
Apakah kamu ingin menambahkan barang AK47: Purry

Contoh output:
< Balik ke menu >
*/
