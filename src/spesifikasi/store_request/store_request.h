#include "queue.h"
#include "arraydinBarang.h"
#include "boolean.h"

void StoreRequest();
/*
Meminta penambahan barang baru ke dalam toko.
Barang-barang yang diminta akan disimpan di dalam sebuah antrian dan akan dimasukkan ke toko menggunakan command selanjutnya. 
Nama barang yang masuk tidak boleh sama dengan nama barang yang sudah ada di toko atau di antrian.

Contoh input:
STORE REQUEST
Nama barang yang diminta: AK47

Contoh output:
Barang berhasil ditambahkan ke toko

Contoh input:
STORE REQUEST
Nama barang yang diminta: Adaditoko

Contoh output:
Barang dengan nama yang sama sudah ada di toko!

Contoh input:
STORE REQUEST
Nama barang yang diminta: Adadiantrian

Contoh output:
Barang dengan nama yang sama sudah ada di antrian!
*/
