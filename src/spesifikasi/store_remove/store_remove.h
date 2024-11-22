#include "..\..\adt\arraydinBarang.h"
#include "..\..\adt\boolean.h"

void StoreRemove(ArrayDin Info);
/*
Menghapus barang yang ada di toko. 
Akan dilakukan input akan barang yang akan dihapus. 
Beri tahu apabila proses berhasil (barang terdapat pada toko dan berhasil dihapus) 
ataupun tidak (barang tidak terdapat di toko). 

Contoh input:
>> STORE REMOVE
Nama barang yang akan dihapus: Sticky Web Gun

Contoh output:
Sticky Web Gun telah berhasil dihapus.

Contoh input:
>> STORE REMOVE
Nama barang yang akan dihapus: Inator Neutralizer

Contoh output:
Toko tidak menjual Inator Neutralizer
*/
