    CurrentWord.Length = 0;
    while (currentChar != BLANK && currentChar != MARK)
    {
        if (CurrentWord.Length < NMax)
        { // jika lebih akan terpotong
            CurrentWord.TabWord[CurrentWord.Length++] = currentChar;
            ADV();
        }
        else
            break;
    }