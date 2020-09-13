/*
You are given N counters, initially set to 0, and you have two possible operations on them:

increase(X) − counter X is increased by 1,
max counter − all counters are set to the maximum value of any counter.
A non-empty array A of M integers is given. This array represents consecutive operations:

if A[K] = X, such that 1 ≤ X ≤ N, then operation K is increase(X),
if A[K] = N + 1 then operation K is max counter.

*/

struct Results solution(int N, int A[], int M) {
    struct Results result;
    
    int count_max = 0;
    int max_stop = 0;
    int *ptr = calloc(N, sizeof(*ptr));
    int *ptrA = A;
    int zmienna;
    
    for( int i =0; i < M; i++)
    {
        if(*ptrA == (N + 1)) max_stop = count_max;
		
        else
        {
            if(*(ptr + *ptrA - 1) < max_stop) *(ptr + *ptrA - 1) = max_stop;
            *(ptr + *ptrA - 1) += 1;
            zmienna = *(ptr + (*ptrA - 1));
            count_max = (zmienna > count_max) ? zmienna : count_max;
        }
    
        ptrA++;
    }
    
    for(int j = 0; j < N; j++)
    {
           if(*(ptr + j) < max_stop) *(ptr + j) = max_stop;
    }
    
    result.C = ptr;
    result.L = N;
    return result;
}