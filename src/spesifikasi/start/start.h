#ifndef START_H
#define START_H
#include "../../adt/mesinkata/mesinkata.h"
#include "../../adt/listuser/listuser.h"
#include "../../adt/arraydinBarang/arraydinBarang.h"
#include "../../adt/queue/queue.h"
#include "../../adt/mesinkalimat/linemachine.h"
#include "../../../utilities.h"

// Fungsi untuk debugging
void debugBarang();
void debugPengguna();
void debugAntrian();

// Fungsi utama untuk membaca konfigurasi
void START_READ(char filename[], ArrayDin barangList, List userList, Queue antrianQueue);
void START_PURRMART( ArrayDin barangList, List userList, Queue antrianQueue);

#endif