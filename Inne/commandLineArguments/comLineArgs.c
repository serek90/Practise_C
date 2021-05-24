#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
	printf("This program has name: %s\n", *argv);

	if(argc < 2)
		printf("User don't specifes any argument\n");

	for(int i = 0; i < argc; i++)
	{
		printf("\t %d. %s\n", i, *(argv + i));
	}

	return 0;
}
