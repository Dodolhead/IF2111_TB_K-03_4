#ifndef LOAD_H
#define LOAD_H

#include "../../spesifikasi/start/start.h"
#include "../../adt/mesinkata/mesinkata.h"
#include "../../adt/mesinkarakter/mesinkarakter.h"
#include "../../adt/mesinangka/mesinangka.h"

#define MAX_LEN 100
#define MAX_ITEMS 100
#define MAX_USERS 100


void LOAD(char filename[], ArrayDin barangList, List userList, Queue antrianQueue);


#endif