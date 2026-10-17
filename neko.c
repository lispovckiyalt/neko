#include <stdio.h>

FILE*
openfile(char** filename)
{
	if (filename == 0x0 || *filename == 0x0) { return 0x0; } /* if pointer null then return NULL*/

	FILE* file = fopen(*filename, "rb"); /* open file with read */
	if (file == 0x0) { return 0x0; } /* if file NULL (does not exist) that return NULL */

	return file; /* return file */
}

void
help()
{
	fprintf(stderr, "no file found! \n neko: \n argument 1: file "); /* help note */
}
int
main(int argc, char **argv) /* entry point */
{
	if (argc < 2 ) { help(); return 1; } /* if there are not enough arguments then exit */
	for (int files = 1 ; files < argc; files++) {

        unsigned long current_line = 1; /* current line */
        int c_char;  /* current char */
        int p_char = '\n'; /* previous char */
		FILE* file = openfile(&argv[files]); /* open file */
		if (file == 0x0 ) {
			fprintf(stderr, "neko: %s: No such file or directory\n", argv[files]); continue;
		}

		while (1) { /* i nfinite cycle (until the file has been read) */
			c_char = getc(file); /* get char */
			if (c_char == EOF) {break;} /* if error break */
			if (p_char == '\n') { printf("%lu.  ", current_line++);  } /* if the previous character was \n, then indicate which line it is on */
			putchar(c_char); /* show symbol */
			p_char = c_char; /* change the previous symbol */
		}
        if (p_char != '\n' && current_line > 1) {
            printf("\n");
        }
        if (ferror(file)) {return -1; }
        fclose(file);
	}
	return 0;
}
