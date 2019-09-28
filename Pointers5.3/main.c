#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
/**
 *Add two string second int the end of the first
 */

void strcat(char *s, char *t);
int main()
{
    char lancuch1[20] = "byleco";
    char lancuch2[20] = "dodamto";
    strcat(lancuch1, lancuch2);
    printf("%s", lancuch1);
    return 0;
}

void strcat(char *s, char *t)
{
    while(*s)
    {
       s++;
    }
    while(*s++ = *t++);
}




