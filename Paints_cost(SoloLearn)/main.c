#include <stdio.h>
#include <stdlib.h>

int main()
{
    int colors;
    double total, tax;

    scanf("%d", &colors);

    total = (double)(colors * 5.00 + 40.00);
    tax = total / 10;
    printf("%g", total + tax);

    scanf("%d", &colors);

}

