#include <stdio.h>
#include <stdlib.h>

int main()
{
    char tab[] = {0b01000011,
    0b01010100,
    0b01000110,
    0b01111011,
    0b01000010,
    0b01101001,
    0b01110100,
    0b01011111,
    0b01000110,
    0b01101100,
    0b01101001,
    0b01110000,
    0b01110000,
    0b01101001,
    0b01101110,
    0b01111101};

    for(int i = 0; i < sizeof(tab); i++)
    {
        printf("%c",tab[i]);
    }
    return 0;
}
