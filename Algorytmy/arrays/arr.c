#include <stdio.h>
#include <stdlib.h>
#include "arr.h"


/*********************************************************
/*Funkcja losujaca N elementów i zapełniająca nimi tablice
*********************************************************/
int losuj(int N, int A[])
{
    for(int i = 0; i < N; i++)
    {
        A[i] = rand()%3200;
    }
}

/*********************************************************
/*Znajduje największy element w tablicy*******************
*********************************************************/
int findLargestElement(int N, int A[])
{
   int largestElement = 0;
   int *arrPtr;
   arrPtr = A;

   for(int i = 0; i < N; i++)
   {
      if(A[i] > largestElement)largestElement = A[i];
      arrPtr++;
   }
   return largestElement;
}

/*********************************************************
/*Znajduje najmniejszy element w tablicy******************
*********************************************************/
int findSmallestElement(int N, int A[])
{
   int smallestElement;
   int *arrPtr;
   arrPtr = A;
   smallestElement = A[0];

   for(int i = 0; i < N; i++)
   {
      if(A[i] < smallestElement)smallestElement = A[i];
      arrPtr++;
   }
   return smallestElement;
}


/*********************************************************
/*Znajduje 2 największe elementy w tablicy****************
*********************************************************/
int find2LargestElement(int N, int A[])
{
   int largestElement = 0;
   int secondElement = 0;
   int *arrPtr;
   arrPtr = A;

   for(int i = 0; i < N; i++)
   {
      if(A[i] > largestElement)largestElement = A[i];
      else if(A[i] > secondElement)secondElement = A[i];
      arrPtr++;
   }
   return secondElement;
}

/*********************************************************
/*Srednia z elementow tablicy*****************************
*********************************************************/
//Maybe float?
int averageOfArray(int N, int A[])
{
   int sum = 0;
   int *arrPtr;
   arrPtr = A;

   for(int i = 0; i < N; i++)
   {
      sum += *arrPtr;
      arrPtr++;
   }

   return sum/N;
}

/*********************************************************
/*Print all maxima in array*******************************
*********************************************************/
int averageOfArray(int N, int A[])
{
   int before = 0, beforebefore = 0, nextMaxima = 0;
   int maximaTab[N];
   int *arrPtr;
   arrPtr = A;

   for(int i = 0; i < N; i++)
   {
      if(((before > *arrPtr) && (beforebefore < before)) || ((before  > *arrPtr) && (i == N - 1)))
      {
        maximaTab[naxtMaxima]  = before;
        nextMaxima++;
      }

      before = beforebefore;
      arrPtr++;
   }

   for(int i =0; i <= nestMaxima; i++ )
   {
       printf("%d",maximaTab[i]);
   }

   return 0;
}
