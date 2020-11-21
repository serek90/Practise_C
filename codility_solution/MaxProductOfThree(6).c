/*A non-empty array A consisting of N integers is given. The product of triplet (P, Q, R) equates to A[P] * A[Q] * A[R] (0 ≤ P < Q < R < N).
*For example, array A such that:
* A[0] = -3
* A[1] = 1
* A[2] = 2
* A[3] = -2
* A[4] = 5
* A[5] = 6
*contains the following example triplets:
*(0, 1, 2), product is −3 * 1 * 2 = −6
*(1, 2, 4), product is 1 * 2 * 5 = 10
*(2, 4, 5), product is 2 * 5 * 6 = 60
*Your goal is to find the maximal product of any triplet.
*Write a function:
*int solution(int A[], int N);
*that, given a non-empty array A, returns the value of the maximal product of any triplet.
*/

#define RANGE_MIN -1001
#define RANGE_MAX  1001

int solution(int A[], int N) 
{
	int theFirst, theSecond, theThird;
	int theLast, theNLast;
	int *ptrA = A;
    
	//afterStart
	theFirst = RANGE_MIN; 
	theSecond = RANGE_MIN; 
	theThird = RANGE_MIN;
	theLast = RANGE_MAX;
	theNLast = RANGE_MAX;
	
	for(int i = 0; i < N; i++)
	{
		//Firt tree elements
		if(*ptrA > theFirst)
        	{
            		theThird = theSecond;
            		theSecond = theFirst;
            		theFirst = *ptrA;
        	}
        	else if(*ptrA > theSecond)
        	{
            		theThird = theSecond;
            		theSecond = *ptrA;
        	}
        	else if(*ptrA > theThird) 
            		theThird = *ptrA;
		
        	//Two smallest elements
        	if(*ptrA < theLast)
        	{
			theNLast = theLast;
			theLast = *ptrA;
		}
		else if(*ptrA < theNLast)
			theNLast = *ptrA;
       
		ptrA++;
	}
    
	//Finish
	if((((theLast * theNLast) > (theThird * theSecond)) || ((theLast * theNLast) > (theThird * theSecond))) && theFirst > 0)
	{
		return theFirst * theLast * theNLast;
	}
  
	return theFirst * theSecond * theThird;
}
