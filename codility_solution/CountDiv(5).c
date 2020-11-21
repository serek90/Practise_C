/*Write a function:
that, given three integers A, B and K, returns the number of integers within the range [A..B] that are divisible by K, i.e.:
{ i : A ≤ i ≤ B, i mod K = 0 }
For example, for A = 6, B = 11 and K = 2, your function should return 3, 
because there are three numbers divisible by 2 within the range [6..11], namely 6, 8 and 10.
*/

int solution(int A, int B, int K) {
    
    int minMod , maxMod, divNum;
    
    minMod = A;
    
    if(A%K)minMod = A +(K - (A%K));
    maxMod = B - (B%K);
    
    divNum = (maxMod - minMod) / K + 1;
    
    return divNum;
    
}
