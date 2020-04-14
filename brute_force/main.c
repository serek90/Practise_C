#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char text[] = "q{vpln'bH_varHuebcrqxetrHOXEj";
    char key = 0;

   FILE *fp; /* używamy metody wysokopoziomowej - musimy mieć zatem identyfikator pliku, uwaga na gwiazdkę! */
   char textPlik[sizeof(text)+1];

   if ((fp=fopen("test.txt", "w"))==NULL)
    {
     printf ("Nie mogę otworzyć pliku test.txt do zapisu!\n");
     exit(1);
    }

    for(int j = 0; j < 256; j++)
    {

        for(int i = 0; i < sizeof(text); i ++)
        {
           textPlik[i] = text[i]^j;
           printf("%c", textPlik[i]);
        }
        printf("\n");
        textPlik[sizeof(text)] = '\n';
        fprintf (fp, "%s", textPlik); /* zapisz nasz łańcuch w pliku */
    }
    fclose (fp); /* zamknij plik */

    return 0;
}
