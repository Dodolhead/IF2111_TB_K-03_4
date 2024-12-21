#ifndef REGISTER_H
#define REGISTER_H

#include "../../spesifikasi/start/start.h"
#include "../../adt/mesinkata/mesinkata.h"
#include "../../adt/mesinkarakter/mesinkarakter.h"
#include "../../adt/listuser/listuser.h"

void REGISTER(List *users);
/* Fungsi untuk mendaftarkan pengguna baru
   I.S. : Array `users` dan jumlah pengguna `jumlahUsers` terdefinisi
   F.S. : Jika username belum terdaftar dan kapasitas belum penuh,
          pengguna baru ditambahkan ke dalam array `users` */

#endif
