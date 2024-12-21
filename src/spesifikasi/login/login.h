#ifndef LOGIN_H
#define LOGIN_H

#include "../../adt/mesinkata/mesinkata.h"
#include "../../adt/mesinkarakter/mesinkarakter.h"
#include "../../adt/mesinangka/mesinangka.h"
#include <stdio.h>
#include "../../spesifikasi/start/start.h"
#include "../../../utilities.h"
#include "../../adt/listuser/listuser.h"

// Fungsi untuk login
int LOGIN(List users, int *loggedInUserIndex);

#endif
