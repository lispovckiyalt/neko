#include <stdio.h>

#include "file.h"


int
read_file(FILE* file_d)
{
    int current_char;

    while (1)
    {
        current_char = getc(file_d);
        
        if (current_char == EOF) { break; }

        putchar(current_char);

        if (ferror(file_d)) { return 1; }
    }


    return 0;
}

