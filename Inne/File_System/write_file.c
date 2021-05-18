#include <stdio.h>
#include <stdlib.h>


int main()
{
	const char *filename = "new_text_file.txt";
	FILE *fileHandler;

	/* Open file to write if it not exist create it */
	fileHandler = fopen(filename, "w");
	if(fileHandler == NULL)
	{
		printf("Filed to create file");
		return 1;
	}

	fprintf(fileHandler, "Print some line to file\n");

	for(char a ='A'; a <='Z'; a++)
		fputc(a,fileHandler);
	fputc('\n', fileHandler);

	/* Close the file */
	fclose(fileHandler);

	return 0;
}
