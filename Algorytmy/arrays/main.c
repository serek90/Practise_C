#include <stdio.h>
#include <stdlib.h>
#include "arr.h"
#include "menu.h"




int (*op)(int N, int A[]);

int A[] = {3, 5, 7, 78, 65, 40, 34, 43, 56};
int N = 9;

int main()
{
char menuKey;

    printMenu();

    menuKey = getchar();
    printf("%d", menuKey);
    switch(menuKey)
    {
    case '1':
        break;

    case '2':
        op = findLargestElement;
        break;

    case '3':
        op = findSmallestElement;
        break;

    case '4':
        op = find2LargestElement;
        break;

    case '5':
        op = averageOfArray;
        break;
    }
    system("cls");

    printf("%d", op(N,A));

    return 0;
}



