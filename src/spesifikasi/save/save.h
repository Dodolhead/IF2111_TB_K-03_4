#include "../../adt/boolean/boolean.h"
#include "../../../utilities.h"
#include "../../adt/listuser/listuser.h"
#include "../../adt/arraydinBarang/arraydinBarang.h"

void Save(ArrayDin Info, List ListUser, char* filename);
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
