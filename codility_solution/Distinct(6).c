/*
*Write a function
*
*int solution(int A[], int N);
*
*that, given an array A consisting of N integers, returns the number of distinct values in array A.
*/


int solution(int A[], int N) {

int *ptrA = A;
int distinctNum = 0;
int *tabPos = calloc(1000001, sizeof(int));
int *tabNeg = calloc(1000000, sizeof(int));
int tmp;

    for(int i =0; i < N; i++)
    {
        tmp = *ptrA;
        if(tmp >= 0)
        {
            if(*(tabPos + tmp) == 0)
            {
               *(tabPos + tmp) += 1;
               distinctNum++;
            }
        }
        else
        {
            tmp *= -1;
            if(*(tabNeg + tmp) == 0)
            {
                *(tabNeg + tmp) += 1;
               distinctNum++;
            }
            
        }

        ptrA++;
    }
    
    free(tabPos);
    free(tabNeg);
    return distinctNum;
}
