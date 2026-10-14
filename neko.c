#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE*
openfile(char** filename)
{
	if (filename == 0x0 || *filename == 0x0) { return 0x0; } /* if pointer null then return NULL*/

	FILE* file = fopen(*filename, "rb"); /* open file with read */
	if (file == 0x0) { return 0x0; } /* if file NULL (does not exist) that return NULL */
	
	return file; /* return file */
}

long
find_size_file(FILE* file)
{
	fseek(file, 0, SEEK_END); /* open the file and look at the very end */
	long size = ftell(file); /* get the number of characters */
	fseek(file, 0, SEEK_SET); /* back to top */
	return size; /* return size */
}
void
help()
{
	printf("no file found! \n neko: \n argument 1: file "); /* help note */
}

int
main(int argc, char **argv) /* entry point */
{
	if (argc < 2 ) { help(); exit(1); } /* if there are not enough arguments then exit */
	for (int i = 1; i < argc; i++) {
		FILE* file = openfile(&argv[i]);
		if (file == 0x0) { fprintf(stderr, "neko, %s: No such file or directory\n", argv[i]); continue;  }

		long size = find_size_file(file); /* find out the size */
		if (size < 0) { fprintf(stderr, "neko: %s: Failed to read size\n", argv[i]); fclose(file); continue; } /* if the file is erroneous*/
		char* content = malloc(size + 1); /* allocate space for characters on the heap */
		if (content == 0x0) { fclose(file); return 1; } /* if there is not enough memory to read it then exit */

		size_t bytes_read = fread(content, sizeof(char), size, file); /* write the characters from the file into the buffer (content) */
		content[bytes_read] = '\0'; /* add a null terminator */

		int line = 1; /* current line */
		printf("%d.  ", line++); /* print line */

		for (size_t j = 0; j < bytes_read; j++) 
		{
			putchar(content[j]); 
			if (content[j] == '\n' && j + 1 < bytes_read)
			{
				printf("%d.  ", line++);
			}
		}

		if (bytes_read > 0 && content[bytes_read - 1] != '\n') {
			printf("\n");
		}
		free(content); /* free up memory */
		fclose(file); /* close file */
	}
	return 0;
}