#include <stdio.h>
#include <stdlib.h>
//#include <cstdint.h>

    typedef unsigned short uint16_t;
    typedef signed short int16_t;
    typedef unsigned long uint32_t;
    typedef signed long int32_t;
    typedef unsigned long long uint64_t;
    typedef signed long long int64_t;

int main()
{
    uint16_t zmienna_0 = 0xEEFAAAE;
    uint16_t zmienna_1 = 20;
    int16_t zmienna_2 = 0xF000;
    int16_t zmienna_3 = 20;

    uint16_t zmienna_4 = zmienna_3;
    int16_t zmienna_5 = zmienna_1;


    printf("%d\n", sizeof(uint16_t));

    printf("0 %x %i %d\n", zmienna_0, zmienna_0, zmienna_0);
    printf("1 %x %i %d\n", zmienna_1, zmienna_1, zmienna_1);
    printf("2 %x %i %d\n", zmienna_2, zmienna_2, zmienna_2);
    printf("3 %x %i %d\n", zmienna_3, zmienna_3, zmienna_3);
    printf("4 %x %i %d\n", zmienna_4, zmienna_4, zmienna_4);
    printf("5 %x %i %d\n", zmienna_5, zmienna_5, zmienna_5);

    return 0;
}
