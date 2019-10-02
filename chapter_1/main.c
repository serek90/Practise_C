#include <stdio.h>
#include <stdlib.h>

/* Wypisz zestawienie temperatur Farenheita - Celsjusza
dla fahr = 0, 20, ... 300
*/
int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;     //dolna granica temperatur
    upper = 300;   //gorna granica temperatur
    step = 20;     //rozmiar kroku

    fahr = lower;
     while(fahr < upper)
     {
         celsius = (5.0/9.0) - (fahr * 32.0);
         printf("%3.0f %6.1f\n", fahr, celsius);
         fahr = fahr + step;
     }

    return 0;
}
