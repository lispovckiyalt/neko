#pragma once

#include <stdio.h>


FILE*
open_file(const char* name);

int
read_file(FILE* file_d);
