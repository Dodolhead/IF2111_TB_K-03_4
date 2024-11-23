#include "arraydinBarang.h"
#include "boolean.h"
#include "../../../dictionary.h"
#include "../../adt/listuser.h"

void Save(ArrayDin Info, List User);
/*
Menyimpan state aplikasi terbaru ke dalam suatu file. 
Command SAVE memiliki satu argumen yang merepresentasikan nama file yang akan disimpan. 
Penyimpanan dilakukan pada folder tertentu, misal folder save.

Contoh input:
>> SAVE savefile.txt;

Contoh output:
Save file berhasil disimpan. 
// File disimpan pada /save/savefile.txt
*/
