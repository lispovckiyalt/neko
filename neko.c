#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE*
openfile(char* filename)
{
	FILE* file = fopen(filename, "r"); /* open file with read */
	if (file == 0x0 ) { exit(1); } /* if file NULL (does not exist) that exit */

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
	FILE* file = openfile(argv[1]); /* get file */
	

	long size = find_size_file(file); /* find out the size */
	char *content = malloc(size + 1); /* allocate space for characters on the heap */
	if (content == 0x0) { fclose(file); return 1; } /* if nullptr then exit */
	fread(content, sizeof(char), size, file); /* write the characters from the file into the buffer (content) */
	content[size] = '\0'; /* add a null terminator */
	printf("%s", content); /* output the buffer contents */
	free(content); /* free up memory */
	content = 0x0; /* reset the pointer to null */
	fclose(file); /* close file */
	return 0;
}