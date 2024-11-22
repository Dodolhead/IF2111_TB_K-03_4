#ifndef LOGIN_H
#define LOGIN_H

#include "..\..\adt\boolean.h"
#include "..\..\adt\array.h"

// Batasan panjang username dan password
#define MAX_USERNAME_LEN 49
#define MIN_PASSWORD_LEN 6
#define MAX_PASSWORD_LEN 18

void login(TabUser list, IdxType *userid, boolean *islogeged);

#endif