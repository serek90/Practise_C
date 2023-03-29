#include <stdio.h>
#include <stdlib.h>

typedef int queue_item;


typedef struct list
{
        int val;
        struct list *next;

}list_t;

typedef struct queue
{
        list_t *head;
        list_t *tail;
        unsigned int size;
}queue_t;


/*************************************
* queue initialization
*************************************/
queue_t * queue_init()
{
        queue_t *q = calloc(1, sizeof(queue_t));
        if(!q)
        {
                printf("Problem with memory allocation\n");
                exit(EXIT_FAILURE);
        }
        q->head = NULL;
        q->tail = NULL;
        q->size = 0;
}

/*************************************
* destroy queue and clear mem
*************************************/
void queue_clean(queue_t *q)
{
        list_t *tmp = q->head;
        list_t *tmp_l;

        while(tmp)
        {
                tmp_l = tmp;
                tmp = tmp->next;
                free(tmp_l);
                tmp_l = NULL;
        }
}

/*************************************
* check is queue empty
*0 - empty; 1 - not empty
*************************************/
int queue_empty(queue_t *q)
{
        return q->head == NULL;
}

/************************************
*
************************************/
unsigned int queue_size(queue_t *q)
{
        return q->size;
}

/**************************************
*push element to queue
*sucess: 0, failure: -1
*************************************/
int queue_push(queue_t *q, queue_item item)
{
        list_t *tmp;
        if(!q)
        {
                printf("queue not initialized!\n");
                return -1;
        }

        tmp = calloc(1, sizeof(list_t));
        tmp->val = item;
        tmp->next = NULL;

        if(queue_empty(q))
        {
                q->head = tmp;
                q->tail = tmp;
        }
        else
        {
                q->tail->next = tmp;
                q->tail = tmp;
        }
        q->size++;
        return 0;
};

/**************************************
*pop element frmo queue
*return queue item
**************************************/
queue_item queue_pop(queue_t *q)
{
        if(!q)
        {
                printf("queue is not initialized");
                exit(EXIT_FAILURE);
        }

        if(queue_empty(q))
        {
                printf("queue is empty\n");
                return 0;
        }

        list_t *tmp = q->head;
        q->head = q->head->next;

        q->size--;
        queue_item item = tmp->val;
        free(tmp);
        tmp = NULL;
        return item;
}

/*************************************
* printing queue
*
*************************************/
void print_queue(queue_t *q)
{
        if(!q)
        {
                printf("print_queue: there is no queue\n");
                return;
        }
        list_t *tmp = q->head;
        if(!tmp)
                return;
        printf("%d", tmp->val);
        tmp = tmp->next;
        while(tmp)
        {
                printf("->%d", tmp->val);
                tmp = tmp->next;
        }
        printf("\n");
}

int main()
{
        queue_t my_queue;
        queue_push(&my_queue, 5);
        queue_push(&my_queue, 2);
        queue_push(&my_queue, 4);

        print_queue(&my_queue);
        list_t *tmp = my_queue.head;

        int a = queue_pop(&my_queue);
        printf("elem pop: %d\n", a);
        print_queue(&my_queue);
        a = queue_pop(&my_queue);
        printf("elem pop: %d\n", a);
        queue_push(&my_queue, 7);
        print_queue(&my_queue);
        a = queue_pop(&my_queue);
        printf("elem pop: %d\n", a);
        return 0;
}
