#include <stdio.h>
#include <stdlib.h>

struct node
{
   int value;
   struct node *next;
};


typedef struct node node_t;


void printList(node_t *head)
{
   node_t *temporary = head;

   while(temporary != NULL)
   {
   printf("%d - ", temporary->value);
   temporary = temporary->next;
   }

}

node_t *create_new_thread(int node_val)
{
   node_t *new_node=malloc(sizeof(node_t));
   new_node->value = node_val;
   new_node->next = NULL;
   return new_node;
}


node_t *add_node_after(node_t *node, int value)
{
   node_t *new_node = malloc(sizeof(node_t));
   new_node->value = value;
   new_node->next = node->next;
   node->next = new_node;

}

node_t *find_node(node_t *head, int value)
{
   node_t *tmp;
   tmp = head;

   while(tmp != NULL)
   {
      if(tmp->value == value) return tmp;
      tmp = tmp->next;
   }
}

int main()
{
   node_t *head = NULL;
   node_t *tmp;
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
