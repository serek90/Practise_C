/*
*Program calculates the number of days beetwen two diffrent dates
*
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct date
{
    int day;
    int month;
    int year;
}Date;

int main()
{
    Date first_date;
    Date second_date;
    printf("Enter first date(dd.mm.yyyy):");
    scanf("%i %i %i",&first_date.day, &first_date.month, &first_date.year);

    printf("Enter second date(dd.mm.yyyy):");
    scanf("%i %i %i",&second_date.day, &second_date.month, &second_date.year);
    printf("Days beetwen this two dates is: ");
    printf("%i ", dayCalculate(second_date) - dayCalculate(first_date));

    printf("%i.%i.%i",first_date.day, first_date.month, first_date.year);
    printf("%i.%i.%i",second_date.day, second_date.month, second_date.year);

    return 0;
}

int dayCalculate(Date d)
{
    int N;
    N = 1461 * f(d.year, d.month)/4 +153*g(d.month)/ 5 + d.day;
    return N;
}

int f(int year, int month)
{
    if( month <= 2)
        year--;

    return year;
}

int g(int month)
{
    if( month <= 2)
        month += 13;
    else
        month += 1;

    return month;
}
