#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>


#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct
{
	char name[MAX_NAME];
	int age;
	//other information

}person;

unsigned int hash(char *name)
{
	int lenght = strnlen(name, MAX_NAME);
	unsigned int hashVal = 0;

	for(int i = 0; i < lenght; i++)
	{
		hashVal += name[i];
		hashVal = (hashVal * name[i]) % TABLE_SIZE;
	}

	return hashVal;
}

int main()
{
	printf("Jacob => %u\n", hash("Jacob"));
	printf("Natalie => %u\n", hash("Natalie"));
	printf("Klementyna => %u\n", hash("Klementyna"));
	printf("Jacek => %u\n", hash("Jacek"));
	printf("Antoni => %u\n", hash("Antoni"));
	printf("Amelia => %u\n", hash("Amelia"));
	printf("Julia => %u\n", hash("Julia"));

	return 0;
}
