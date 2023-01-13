
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_input(char **str)
{
    char buffer[100];
    int i = 0;
    char c;
    printf("enter name:");
    
    //read string from user
    for(i = 0; i < 99 && ((c = getchar()) != EOF) && (c != '\n'); i++)
        buffer[i] = c;
    buffer[i] = '\0';

    *str = malloc((strlen(buffer) + 1) * sizeof(char));
    if(*str != NULL)
        memcpy(*str, buffer, strlen(buffer) + 1);
}

int main()
{
    char *arr_str[5];
    
    for(int i = 0; i < 5; i++)
    {
        get_input(&arr_str[i]);
    }

    for(int i = 0; i < 5; i++)
    {
        printf("name %d: %s\n", i, arr_str[i]);    
    }
    
    return 0;
}
