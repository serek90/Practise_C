/*
*BruXOR on ctflearn.com
*There is a technique called bruteforce. Message: q{vpln'bH_varHuebcrqxetrHOXEj No key! Just brute .. brute .. brute ... :D
*
*Program to find flag of the ctflearn.com problem  BruXOR
*Solution is saved to test.txt file
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

   char text[] = "q{vpln'bH_varHuebcrqxetrHOXEj"; // message
   char textPlik[sizeof(text)+1];
   char key = 0;

   FILE *fp;

   if ((fp=fopen("test.txt", "w"))==NULL)
    {
     printf ("I can't open file!\n");
     exit(1);
    }

    for(int j = 0; j < 256; j++) //Maximum size of char
    {

        for(int i = 0; i < sizeof(text); i ++)
        {
           textPlik[i] = text[i]^j;
           printf("%c", textPlik[i]);
        }

        printf("\n");
        textPlik[sizeof(text)] = '\n';
        fprintf (fp, "%s", textPlik);
    }

    fclose (fp); // close file

    return 0;
}
