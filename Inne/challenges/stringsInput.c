/*
* Small traning program to test putchar and getchar functions 
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *readString( void );
void writeString(char *string);

int main()
{
	char *firstName, *lastName;

	printf("Please enter your first name:\n");
	firstName = readString();

	printf("Enter your last name:\n");
	lastName = readString();

	puts("\n");
	puts("Your first name is:");
	writeString(firstName);

	puts("\n");
	puts("Your last name is:");
	writeString(lastName);
	puts("\n");
	return 0;
}

char *readString( void )
{
	char buffer[32];
	char *tmp;
	char ch;
	u_int8_t a = 0;

        while((ch = getchar()) != '\n')
        {
		*(buffer + a) = ch;
		if(a == 30)
			break;
		a++;
        }

	buffer[a] = '\0';

	tmp = malloc( sizeof(char) * (strlen(buffer + 1)));

	if(tmp == NULL)
	{
		printf("there is some problem with memory allocstion");
		return NULL;
	}

	strcpy(tmp, buffer);
	return tmp;
}

void writeString(char *string)
{
	char *tmp = string;

	while(*tmp)
	{
		putchar(*tmp);
		tmp++;
	}
}
