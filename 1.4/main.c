#include <stdio.h>
#include <stdlib.h>

int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;     //dolna granica temperatur
    upper = 300;   //gorna granica temperatur
    step = 20;     //rozmiar kroku

    celsius = lower;
    printf("Zestawienie temperatur:\n\n\n");
    printf("celsius fahr\n");
     while(celsius < upper)
     {
         fahr = celsius *(9.0/5.0) - 32.0;
         printf("%3.0f   %6.1f\n", celsius, fahr);
         celsius = celsius + step;
     }

    return 0;
}
