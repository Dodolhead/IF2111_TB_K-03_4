#include <stdio.h>
#include "mesinkata.h"
#include "../../utilities.c"
#include "mesinkarakter.c"
#include "mesinkata.c"
#include "mesinangka.c"

int main(){
    STARTWORD();
    while (!EndWord)
    {
        ADVWORD();
    }
    printf("%s\n", currentWord.TabWord);
    
}