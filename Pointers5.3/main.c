#include <stdio.h>
#include <stdlib.h>

/**
 *Adding two string second to the end of the first
 */

void strcat(char *s, char *t);
int strend(char *s, char *t);
char strncpy (char* strTo, const char* strFrom, size_t size);

int main()
{
    char lancuch1[20] = "byleco";
    char lancuch2[20] = "dodamto";

    strcat(lancuch1, lancuch2);
    printf("Dodanie jednego na koniec drugiego: %s\n", lancuch1);

    printf("Czy jeden na koncu drugiego? %d\n", strend(lancuch1, lancuch2));


    return 0;
}

void strcat(char *s, char *t) //5.3 Dodanie jednego łańcucha na koniec drugiego
{
    while(*s)
    {
        s++;
    }
    while(*s++ = *t++);
}

int strend(char *s, char *t)  //5.4 Sprawdzenie czy drugi lancuch jest na koncu drugiego
{
    while(*s)
    {
        if(*s++ == *t)t++;
    }
    if(!(*t))return 1;
    else return 0;

}

char strncpy(char *strTo, const char *strFrom, size_t size);  //5.5 Kopiuje okreslona liczne znakow z jednego do drugiego

