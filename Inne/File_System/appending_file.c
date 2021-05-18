#include <stdio.h>
#include <stdlib.h>


int main()
{
	const char *filename = "new_text_file.txt";
	FILE *fileHandler;

	/* Open file and write on the end of this file */
	fileHandler = fopen(filename, "a");
	if(fileHandler == NULL)
	{
		printf("Filed to create file");
		return 1;
	}

	fprintf(fileHandler, "Add some line at the end of the file\n");

	/* Close the file */
	fclose(fileHandler);

	return 0;
}
