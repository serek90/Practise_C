  GNU nano 4.3                                                                  linkedlist.c                                                                            
#include "linkedlist.h"
#include "stdio.h"
#include "stdlib.h"



int main()
{
   char key;

/*   do
   {
      printf("MENU\n");
      printf("1. Dodaj wezel na koncu\n");
      printf("2. Dodaj wezel za wezle\n");
      printf("3. Znajdz wezel\n");
      printf("2. Odczytaj liste\n");
      printf("'q' Zakoncz\n");

      scanf("%c", &key);
      system("clear");

   }while(key != 'q'); */


   tmp = create_new_thread(45);
   head = tmp;                     //Teraz glowa jest ostatni element

   tmp = create_new_thread(56);
   tmp->next = head;              //Wskazuje na poprzedni element
   head = tmp;                    //Nowy element jako nowa glowa

   tmp = create_new_thread(5555);
   tmp->next = head;
   head = tmp;

   tmp = find_node(head, 56);
   printf("%d", tmp->value);

   printList(head);

  return 0;
}

