#include <stdio.h>
#include <string.h>
#include <errno.h>

FILE*
openfile(char* filename)
{  
	FILE* file = fopen(filename, "rb"); /* open file with read */
	if (file == 0x0) { return 0x0; } /* if file NULL (does not exist) that return NULL */

	return file; /* return file */
}

void
usage(void)
{
    fprintf(stderr, "usage: neko file\n");
} 
int
main(int argc, char **argv) /* entry point */
{
    int status = 0;

	if (argc < 2 ) { usage(); return 1; } /* if there are not enough arguments then exit */
	for (int files = 1 ; files < argc; files++) {

        unsigned long current_line = 1;
        int c_char; 
        int p_char = '\n'; /* we start with '\n' so that the first line also gets a number  */
		FILE* file = openfile(argv[files]); 


        if (file == 0x0) {
        	fprintf(stderr, "neko: %s: %s\n", argv[files], strerror(errno));
    	    status = 1;
    	    continue;
        }
		while (1) { /* infinite cycle (until the file has been read) */
			c_char = getc(file); /* get a character from a file in order to output it */
			if (c_char == EOF) {break;}
			if (p_char == '\n') { printf("%lu.  ", current_line++);  } /* if the previous character was \n, then indicate which line it is on */
			putchar(c_char); 
			p_char = c_char; 
		}
        if (p_char != '\n') {  /* if the file doesn’t end with ‘\n’, add one */
            printf("\n");
        }
        if (ferror(file)) {status = 1; }
        fclose(file);
	}
	return status;
}
