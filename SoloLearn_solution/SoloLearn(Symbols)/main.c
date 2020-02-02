#include <stdio.h>
#include <stdlib.h>

int main()
{
    char strIn[50];

    scanf("%s", strIn);
    printf("%s", strIn);

    for( int i = 0; i < 50; i++)
    {

        printf("%d\n", strIn[i]);
    }
    printf("Hello world!\n");
    return 0;
}
