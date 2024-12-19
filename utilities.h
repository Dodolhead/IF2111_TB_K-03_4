#include <stdio.h>
#include "src/adt/boolean/boolean.h"
#include "src/adt/mesinkarakter/mesinkarakter.h"
#include "src/adt/mesinangka/mesinangka.h"
#include "src/adt/mesinkata/mesinkata.h"

boolean stringEquals(char* str1, char* str2);
int stringLength(char* str);
void stringConcat(char* dest, char* src);
void copyString(char* dest, const char* src);
int arrayToInteger(char arr[], int length);