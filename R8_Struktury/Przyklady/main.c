/*
* programik oblicza jutrzejszą date
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct date
{
    int day;
    int month;
    int year;
}Date;


int numberOfDays(Date d);
bool isLeapYear(Date d);
Date dayUpdate(Date today);


int main()
{
    Date thisDay, nextDay; // lub struct date today;

    printf("podaj dzisiejszą date(dd mm rok):");
    scanf("%i %i %i", &thisDay.day, &thisDay.month, &thisDay.year);
    nextDay = dayUpdate(thisDay);

    printf("Jutro bedzie %.2i.%i.%ir", nextDay.day, nextDay.month, nextDay.year);
    return 0;
}

Date dayUpdate(Date today)
{
    Date tomorrow;

    if(today.day != numberOfDays(today))
    {
        tomorrow.day = today.day + 1;
        tomorrow.month = today.month;
        tomorrow.year = today.year;

    }
    else if(today.month == 12 ) // Koniec roku zaczynamy od stycznia
    {
        tomorrow.day = 1;
        tomorrow.month = 1;
        tomorrow.year = today.year + 1;
    }
    else  // Koniec miesiac wiec zaczynamy kolejny
    {

        tomorrow.day = 1;
        tomorrow.month = today.month + 1;
        tomorrow.year = today.year;
    }

    return tomorrow;
}

// Funkcja zwracając liczbe dni w danym miesiącu
int numberOfDays(Date d)
{
    const int dayPerMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if((d.month == 2) && (isLeapYear(d) == true))
        return 29;
    else
        return dayPerMonth[d.month - 1];

}

// Funkcja okreslajaca czy dany rok jest przestepny
bool isLeapYear(Date d)
{

    if(((d.year%4 == 0) && (d.year%100 != 0)) || (d.year%400 == 0))
        return true;
    else
        return false;
}
