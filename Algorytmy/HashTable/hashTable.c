#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>


#define MAX_NAME 256
#define TABLE_SIZE 10

/**********************************
*/
typedef struct
{
	char name[MAX_NAME];
	int age;
	//other information

}person;

/**********************************/
person *hashTable[TABLE_SIZE];

/***********************************
*hash function
*return: place in hash table
*********************************/
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

/******************************
*Init hash table
*return:noting
********************************/

void initHashTable(void)
{
	for(int i = 0; i < TABLE_SIZE; i++)
	{
		hashTable[i] = NULL;
	}
}

/********************************
*print hash table
********************************/
void printHashTable(void)
{
	printf("START HASH TABLE\n");
	for(int i = 0; i < TABLE_SIZE; i++)
	{
		if(hashTable[i] == NULL)
		{
			printf("\t%i\t---\n", i);
		}
		else
		{
			printf("\t%i\t%s\n", i, hashTable[i]->name);
		}
	}
	printf("END HASH TABLE\n");
}

/************************************
*insert element to hash table*******
*
*
************************************/
bool hashTableInsert(person *p)
{
	if(p == NULL) return false;
	int index = hash(p->name);
	if(hashTable[index] != NULL) return false; //is not empty

	hashTable[index] = p;
	return true;
}

/************************************
*main function
************************************/
int main()
{
	initHashTable();
	printHashTable();

	person Jakub = {.name = "Jakub", .age = 25};
	person Natalia = {.name = "Natalia", .age = 29};
	person Julia = {.name = "Julia", .age = 24};

	hashTableInsert(&Jakub);
	hashTableInsert(&Natalia);
	hashTableInsert(&Julia);

	printHashTable();
	/*printf("Jacob => %u\n", hash("Jacob"));
	printf("Natalie => %u\n", hash("Natalie"));
	printf("Klementyna => %u\n", hash("Klementyna"));
	printf("Jacek => %u\n", hash("Jacek"));
	printf("Antoni => %u\n", hash("Antoni"));
	printf("Amelia => %u\n", hash("Amelia"));
	printf("Julia => %u\n", hash("Julia"));
	*/
	return 0;
}
