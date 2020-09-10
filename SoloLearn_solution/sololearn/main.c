#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a[] = { 'A', 'B' , 'C', 'D'};
    char* ppp = &a[0];
    *ppp++;
    printf("%c\n",*++ppp);

    return 0;
}
