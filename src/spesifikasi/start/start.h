#ifndef START_H
#define START_H

#include "../../adt/mesinkata/mesinkata.h"
#include "../../adt/listuser/listuser.h"
#include "../../adt/arraydinBarang/arraydinBarang.h"
#include "../../adt/queue/queue.h"
#include "../../adt/mesinkalimat/linemachine.h"
#include "../../../utilities.h"

// Deklarasi global
extern ArrayDin barangList;
extern List userList;
extern Queue antrianQueue;

// Fungsi untuk debugging
void debugBarang();
void debugPengguna();
void debugAntrian();

// Fungsi utama untuk membaca konfigurasi
void START_READ(char filename[]);
void START_PURRMART();

#endif
