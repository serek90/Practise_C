/*
*Prosty algorytm do szuaknia połączeń między węzłami z kursu uniwersytetu Prinston
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int *id;
int N; //rozmiar tablicy
void tabInitialize(int N);
void unia(int p, int q);
bool conected(int p, int q);

int main()
{
    int x;
    int q, p;

    printf("Ile elementow ma zawierac tablica?\n");

    scanf("%d", &N);
    tabInitialize(N);
    system("cls");

    while(1)
    {
        printf("Wybierz operacje:\n");
        printf("1. Dodaj elementy polaczone\n");
        printf("2. sprawdz czy polaczone\n");
        printf("3. Koniec programu\n");

        scanf("%d", &x);


        switch(x)
        {
        case 1:
            scanf("%d", &q);
            scanf("%d", &p);
            unia(p,q);

            break;

        case 2:
            scanf("%d", &q);
            scanf("%d", &p);
            if(conected(p,q)) printf("Tak jest polaczenie pomiedzy tymi punktami\n");
            else printf("Brak polaczenia pomiedzy tymi punktami\n");
            scanf("%d", &x);
            break;

        case 3:
            printf("KONIEC");
            return 0;
            break;

        }
      system("cls");


    }



    return 0;
}


// Inicjalizowanie tablicy
void tabInitialize(int N)
{
    id = (int*)malloc(sizeof(id) * N);

    for(int i = 0; i < N; i++)
    {
        id[i] = i;
        //printf("%d", id[i]);
    }
}

//Sprawdzanie czy punkty maja polaczenie
bool conected(int p, int q)
{
    return (id[p] == id[q]);
}

//Algorytm tworzacy polaczenia pomiedzy punktami
void unia(int p, int q)
{
  int pid = id[p];
  int qid = id[q];

  for(int i = 0; i < N; i++) //Znajdź wszystkie połączone do węzła i zamień je na index źródła
  {
      if(id[i] == pid) id[i] = qid;
  }
}




