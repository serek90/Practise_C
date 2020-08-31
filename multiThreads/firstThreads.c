
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int v=5;
void*  myTurn(void *arg)
{

   int *ptr = (int *)arg;
    while(1)
    {
       (*ptr)++;
       printf("My turn!\n");
       printf("%d", *ptr);
       sleep(1);
    }

    return NULL;
}


void yourTurn()
{
    while(1)
    {

        printf("Your turn\n");
        printf("%d", v);
       // v++;
        sleep(2);

    }
}

int main()
{

    pthread_t  firstThread;
    printf("Lests start thread");
    pthread_create(&firstThread, NULL, myTurn, &v);
    yourTurn();

return 0;
}
