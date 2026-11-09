#include <stdio.h>

#include "file.h"



int 
main(int argc, char ** argv)
{

    if (argc < 2) { /* TODO make usage */ return 1; }

    for (int files = 1; files < argc; files++)
    {
        FILE* file = open_file(argv[files]);

        if (!file) { continue; }
        if (read_file(file) != 0) { fclose(file); return 1; }

        fclose(file);
    }

    return 0;
}

