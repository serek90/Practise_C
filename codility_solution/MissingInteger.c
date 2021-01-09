/*
Write a function:
int solution(int A[], int N);
that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.
For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.
Given A = [1, 2, 3], the function should return 4.
Given A = [−1, −3], the function should return 1.
Write an efficient algorithm for the following assumptions:
N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−1,000,000..1,000,000].
*/

int solution(int A[], int N) {
    int *tab = calloc(N, sizeof(int));
    int *tmpPtr, tmp;
    int nSmallest = 1;

    tmpPtr = A;
    for(int i = 0; i < N; i++)
    {
        if(*tmpPtr >= 1 && *tmpPtr <= N)
        {
            tmp = (*tmpPtr - 1);
            *(tab + tmp) = 1;
        }
        tmpPtr++; //resolve this
    }

    tmpPtr = tab;
    for(int i = 0; i < N; i++)
    {
        if(*tmpPtr != 0)  nSmallest++ ;
        else break;
        tmpPtr++;

    }
    
    free(tab);
    return nSmallest;

}
