#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c, nl,tab, space;

    nl = 0;
    tab = 0;
    space = 0;

    while((c = getchar()) != EOF)  //EOF Ctrl + z aby wywołać EOF z klawiatury
     {
         if(c == '\n')++nl;
         else if( c == ' ')space++;
         else if( c == '\t')tab++;
     }

    printf("Liczba konca linii: %d\n", nl);
    printf("Liczba spacji: %d\n", space);
    printf("Liczba tabulacji: %d\n", tab);

    return 0;
}
