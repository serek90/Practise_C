#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000 /* maksymalna liczba wierszy do sortowania */
char *lineptr[MAXLINES];
int readlines(char *lineptr[], nlines);
void writelines(char * lineptr[], int nlines);

void qsort(char *lineptr[], int nlines);

/*8uporządkuj wiersze wejściowe */
int main()
{
    int nlines; //liczba wczytancyh wierszy

    if((nlines = readlines (lineptr, MAXLINES)) >= 0 )
    {
        qsort(lineptr, 0, nlines - 1);
        writelnes(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("blad za duzo wierszy do sortowania \n");
        return 1;
    }

}
#define MAXLEN 1000 //Maxymalna dlugosc wiersza wejsciowego
int getline(char *, int);
char *alloc(int);

/*readlines wczytaj wiersze z wejscia */
int readlines( char *lineptr[], int maxlines)
{

}

