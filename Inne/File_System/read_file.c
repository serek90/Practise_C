#include <stdio.h>
#include <stdlib.h>


int main()
{
	char ch;

	const char *filename = "some_file.txt";
	FILE *fileHandler;

	/*open the file only for reading */
	fileHandler = fopen(filename, "r");
	if(fileHandler == NULL)
	{
		printf("Unable to read from %s\n", filename);
		return(1);
	}

	while(1)
	{
		ch = fgetc(fileHandler);
		if (ch == EOF)
			break;
		putchar(ch);
	}

	printf("File '%s' opened\n", filename);

	fclose(fileHandler);

	return 0;
}
