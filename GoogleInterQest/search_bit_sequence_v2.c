/*
 * title: Goole interview question
 * problem: You have N namber of bit's sequences of lenght L
 *	    find the pairs where the two of sequence are
 *          different only for one bite
 *
 *
 * author of solution: jseroczy(serek90-95)
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 60  // number ot the byte sequence
#define L 8   //lenght of bite sequencee

char *test_str[N];


/************************************************
* Function to prepare entrance bit sequance     *
************************************************/
void prepare_bit_seq()
{
	for(int i = 0; i < N; i++)
	{
		test_str[i] = malloc(sizeof(char) * L);
		for(int j = 0; j < L; j++)
		{
			test_str[i][j] = rand()%2 + '0';
		}
		printf("%s\n", test_str[i]);
	}
}


typedef struct node
{
	struct node *next;
	char *str; //pointer to sequence
}node_t;

typedef struct ans
{
	char *str_1;
	char *str_2;
	struct ans *next;

}ans_t;

ans_t *head = NULL;
ans_t *curr = NULL;

/***********************************************
*
***********************************************/
void print_ans()
{
	printf("\n\n\n");
	while(head)
	{
		printf("%s\n%s\n\n", head->str_1, head->str_2);
		head = head->next;
	}
}

int compare_bits(char *str1, char *str2)
{
	int diff = 0;
	for(int i = 0; i < L; i++)
	{
		diff += (str1[i] != str2[i]);
		if(diff > 1) return 0;
	}
	return diff;
}

void add_to_arr(node_t *node, char *str)
{
	node_t *last;
	while(node)
	{
		last = node;
		node = node->next;
	}
	node_t *tmp = calloc(1, sizeof(node_t));
	tmp->next = NULL;
	tmp->str = str;
  	last->next = tmp;
}

/************************************************
*count bits in sequence                         *
*************************************************/
int count_bits(char *str)
{
	int bit_ctr = 0;
	printf("DEBUG: %s\t", str);
	for(int i = 0; i < strlen(str); i++)
	{
		bit_ctr += (str[i] == '1') ? 1 : 0;
	}

	printf("%d\n", bit_ctr);
	return bit_ctr;
}

/************************************************
*Main searching function                        *
*************************************************/
void find_pairs(char *str_arr[])
{
	if( N <= 1 || L <= 0)
		return;

	node_t **arr = calloc(L + 1, sizeof(node_t *));

	/* divide into group */
        for(int i = 1; i < N; i++)
        {
		int bit_ctr = count_bits(test_str[i]);
		if(arr[bit_ctr] == NULL)
		{
			arr[bit_ctr] = calloc(1, sizeof(node_t));
			arr[bit_ctr]->next = NULL;
			arr[bit_ctr]->str = *(test_str + i);
		}
		else
		{
			add_to_arr(arr[bit_ctr], test_str[i]);
		}
	}

	/* find pairs */
	for(int i = 1; i <= L; i++)
	{
		node_t *tmp_1 = arr[i - 1];
		node_t *tmp_2 = arr[i];
		while(tmp_1)
		{
			while(tmp_2)
			{
                		if(compare_bits(tmp_1->str, tmp_2->str))
                		{
                        		ans_t *tmp = calloc(1, sizeof(ans_t));
                        		tmp->next = NULL;
                        		tmp->str_1 = tmp_1->str;
                        		tmp->str_2 = tmp_2->str;
                        		if(!head)
                        		{
                                		head = tmp;
                                		curr = head;
                        		}
                        		else
                        		{
                                		curr->next = tmp;
                                		curr = tmp;
                        		}
                		}
				tmp_2 = tmp_2->next;
			}
			tmp_1 = tmp_1->next;
		}
	}
}



/***************************************
*main function
**************************************/
int main()
{
	prepare_bit_seq();

	find_pairs(test_str);

	print_ans();

	return 0;
}
