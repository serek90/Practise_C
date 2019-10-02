#include <stdio.h>
#include <stdlib.h>

/**
 *Adding two string second to the end of the first
 */

void strcat(char *s, char *t);
int strend(char *s, char *t);
void strncpy (char* strTo, const char* strFrom, int size);// zmianic na funkcje zwracajacą char
void strncat (char* strTo, const char* strFrom, int num);//Funkcja dopisuje pierwsze num znaków z tablicy strFrom na koniec tekstu w tablicy strTo.
int strncmp(const char *s1, const char *s2, size_t n); //Porownuje n znakow z napisow, 0 gdy rowne

int main()
{
    char lancuch1[20] = "byleco";
    char lancuch2[20] = "dodamto";
    char lanDoPor1[20] = "jakimlan";
    char lanDoPor2[20] = "jakislap";

    strcat(lancuch1, lancuch2);
    printf("Dodanie jednego na koniec drugiego: %s\n", lancuch1);

    printf("Czy jeden na koncu drugiego? %d\n", strend(lancuch1, lancuch2));

    //strncat(lancuch1,lancuch2, 4);
    strncpy(lancuch1, lancuch2, 3);
    printf("%s\n", lancuch1);
    printf("%d", strncmp(lanDoPor1, lanDoPor2, 5));

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


void strncat(char *strTo, const char *strFrom, int size)  //5.5 Kopiuje okreslona liczne znakow z jednego na koniec drugiego
{
    while(*strTo)
    {
        strTo++;
    }

    for(int i = 0; i < size; i++)
    {
      if(!(*strTo++ = *strFrom++))return *strTo;
    }
}


void strncpy(char *strTo, const char *strFrom, int size)  //5.5 Kopiuje okreslona liczba znakow z jednoego do druiego a reszta to \0
{
    int i = 1;
   while(*strTo)
   {
       if(i++ <= size)*strTo++ = *strFrom++;
       else *strTo++ = 0;
   }

}


/**************************************************
*Porównuje nie więcej niż początkowe n znaków napisów s1 i s2.
*Funkcja zwraca liczbę całkowitą, która wskazuje na relację między napisami.
*Zwraca 0, gdy napisy są identyczne. Zwraca liczbę dodatnią, gdy na pierwszej pozycji, na której różnią się znaki w napisach s1 i s2, znak w s1 ma większą wartość niż znak w s2.
*Zwraca liczbę ujemną w przeciwnym przypadku
*/

int strncmp(const char *s1,const char *s2, size_t n)
{
    for(int i = 0; i < n; i++, s1++, s2++)
    {
        if(!(*s1))return 0;
        else if(*s1 - *s2)return *s1 - *s2;
    }
}
