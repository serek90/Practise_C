/*
*Create a array poointer
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *string[10];

	char tmp[100];
	int stringLen;

	for(int i = 0; i < 10; i++)
	{
		printf("Please add %d fruit\n", i + 1);
		//scanf("%s", tmp);
		fgets(tmp, 100, stdin); //fgets get the '\n' at the endo of the string

		stringLen = strlen(tmp);
		string[i] = (char *) malloc(sizeof(char) * (stringLen +1)); //strlen retunr string lenght witouth '/0'
		if(string[i] == NULL)
		{
			printf("Problem with memory allocation\n");
			exit(1);
		}
		strcpy(string[i], tmp);
	}


	printf("I print your fruit table:\n");

	for(int i = 0; i < 10; i++)
	{
		printf("fruit %d - ", i + 1);
		printf("%s\n", string[i]);
	}

	for(int i = 0; i < 10; i++)
		free(string[i]);

	return 0;
}
