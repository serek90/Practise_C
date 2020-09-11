/*
Codility task:

Write a function:

struct Results solution(int A[], int N, int K);

that, given an array A consisting of N integers and an integer K, returns the array A rotated K times.

For example, given

    A = [3, 8, 9, 7, 6]
    K = 3
the function should return [9, 7, 6, 3, 8]. Three rotations were made:

    [3, 8, 9, 7, 6] -> [6, 3, 8, 9, 7]
    [6, 3, 8, 9, 7] -> [7, 6, 3, 8, 9]
    [7, 6, 3, 8, 9] -> [9, 7, 6, 3, 8]

*/

struct Results solution(int A[], int N, int K) {
    struct Results result;
    
    int *tab = malloc(N * sizeof(*tab));
    int *ptrA = A, *ptrB = tab;
    int shift;

    for(int i = 0; i < N; i++)
    {
            
        shift = K%N;
        if((i - K) < 0) shift = K - N;
        *ptrB = *(ptrA - shift);
        ptrB++;
        ptrA++;
    }
    
    result.A = tab;
    result.N = N;
    return result;
}