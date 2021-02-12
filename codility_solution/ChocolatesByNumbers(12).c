/*
*Two positive integers N and M are given. Integer N represents the number of chocolates arranged in a circle, numbered from 0 to N − 1.
*You start to eat the chocolates. After eating a chocolate you leave only a wrapper.
*You begin with eating chocolate number 0. Then you omit the next M − 1 chocolates or wrappers on the circle, and eat the following one.
*More precisely, if you ate chocolate number X, then you will next eat the chocolate with number (X + M) modulo N (remainder of division).
*You stop eating when you encounter an empty wrapper.
*/

int solution(int N, int M) {
    int NWD;
    int a,b,t;

    a = N;
    b = M;

    /* Wyznaczanie najwiekszego wspolengo dzielnika
    algorytmem Euklidesa */
    while( b )
    {
        t = b;
        b = a % b;
        a = t;
    } 
    NWD = a;

    if(N%M == 0)
        return N/M;
    else if(NWD == 1)
        return N;
    else 
        return N/NWD;
}
