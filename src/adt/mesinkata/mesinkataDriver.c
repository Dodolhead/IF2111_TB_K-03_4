#include <stdio.h>
#include "mesinkata.h"
#include "../../../utilities.c"
#include "../mesinkarakter/mesinkarakter.c"
#include "../mesinkata/mesinkata.c"
#include "../mesinangka/mesinangka.c"

int main(){
    char filename[] = "config.txt";
    STARTWORD(filename);
    while (!endWord)
    {
        ADVWORD();
    }
    printf("%s\n", currentWord.TabWord);
    
}