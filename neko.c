#include <stdio.h>
#include <stdlib.h>

FILE*
openfile(char* filename)
{
	FILE* file = fopen(filename, "r");
	if (file == 0x0 ) { exit(1); }

	return file;
}

long
find_size_file(FILE* file)
{
	fseek(file, 0, SEEK_END);
	long size = ftell(file);
	fseek(file, 0, SEEK_SET);
	return size;
}

void
help()
{
	printf("no file found! \n neko: \n argv 1: filename");
}

int
main(int argc, char **argv)
{
	if (argc < 2 ) { help(); exit(1); }

	FILE* file = openfile(argv[1]);
	

	long size = find_size_file(file);
	char *content = malloc(size + 1);
	if (content == 0x0) { fclose(file); return 1; }
	fread(content, sizeof(char), size, file);
	content[size] = '\0';
	printf("%s", content);
	free(content);
	fclose(file);
	return 0;
}