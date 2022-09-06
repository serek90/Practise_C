/*
* title: Goole interview question
* problem: You have N namber of bit's sequences of lenght L
*	find the pairs where the two of sequence are different only for one bite
*
*
* author of solution: jseroczy(serek90-95)
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 1000  // number ot the byte sequence
#define L 10    //lenght of bite sequencee

char *test_str[N];


/***********************************
* Function to prepare entrance bit sequance
**********************************/
void prepare_bit_seq()
{
	for(int i = 0; i < N; i++)
	{
		test_str[i] = malloc(sizeof(char) * L);
		for(int j = 0; j < L; j++)
		{
			test_str[i][j] = rand()%2 + '0';
		}
//		printf("%s\n", test_str[i]);
	}
}

/*************************************
*Binary tree to search data
*************************************/
struct b_tree
{
	struct b_tree *left;
	struct b_tree *right;
	int num;
	int *same;
};

/***********************************
*Returning struct to linked list and function to fill it
***********************************/
struct out
{
	int arr[2];
	struct out *next;
};

struct out *head = NULL;
struct out *curr = NULL;

void add_entry(int a, int b)
{
	struct out *tmp;
	tmp = calloc(1, sizeof(struct out));
	tmp->arr[0] = a;
	tmp->arr[1] = b;

	if(!head)
	{
		head = curr = tmp;
	}
	else
	{
		curr->next = tmp;
		curr = curr->next;
	}
}

/*****************************************
* Function tom print answer array
****************************************/
void print_ans()
{
	struct out *tmp = head;
	while(tmp)
	{
		printf("[ %d , %d ]\n", tmp->arr[0], tmp->arr[1]);
		tmp = tmp->next;
	}
}

/********************************************************************************************************/
/* Function to find answer and helpful functions                                                        */
void move_right(struct b_tree **ptr, int num)
{
        struct b_tree *tmp =  *ptr;

        if(tmp->right == NULL)
        {
                tmp->right = malloc(sizeof(struct b_tree));
                tmp = tmp->right;
                tmp->left = NULL;
                tmp->right = NULL;
                tmp->num = num;
                *ptr = NULL;
        }
        else
        {
                *ptr = tmp->right;
        }
}

void move_left(struct b_tree **ptr, int num)
{
	struct b_tree *tmp =  *ptr;

	if(tmp->left == NULL)
	{
		tmp->left = malloc(sizeof(struct b_tree));
		tmp = tmp->left;
		tmp->left = NULL;
		tmp->right = NULL;
		tmp->num = num;
		*ptr = NULL;
	}
        else
	{
		*ptr = tmp->left;
	}
}

/***********************************************
*Compare two sequence
***********************************************/
void cmp_seq(int num_1, int num_2, int diff_cnt, int lvl)
{

	for(int k = lvl; k < L; k++)
        {
		if(test_str[num_1][k] != test_str[num_2][k])
                {
			diff_cnt++;
                        if( diff_cnt > 1) break;
                }
        }
        if(diff_cnt == 1)
		add_entry(num_1, num_2);
}

/************************************************
* Check second branch with one diff
************************************************/
void sec_branch_diff(struct b_tree *tmp, int i, int lvl)
{
	if(test_str[i][lvl] == '0')
        {
        	tmp = tmp->right;
        }
        else
        {
		tmp = tmp->left;
        }
	lvl++;

        while(tmp)
        {
		cmp_seq(i, tmp->num, 1, lvl);
		if(lvl < L - 1)
		{
			if(test_str[i][lvl] == '1')
               		{
				tmp = tmp->right;
			}
			else
                	{
				tmp = tmp->left;
      	      		}
			lvl++;
		}
		else
			tmp = tmp->right;

	}
}

/************************************************
*Main searching function
************************************************/
void check_bits(char *str_arr[])
{
	if( N <= 1 || L <= 0)
		return;

	struct b_tree *root = malloc(sizeof(struct b_tree));
	root->left = NULL;
	root->right = NULL;
	root->num = 0;
	struct b_tree *tmp;
	int lvl = 0;

        for(int i = 1; i < N; i++)
        {
		tmp = root;
		lvl = 0;

		while(tmp)
		{
			cmp_seq(i, tmp->num, 0, lvl);
			sec_branch_diff(tmp,i, lvl);

			if(lvl < L - 1)
			{
				if(test_str[i][lvl] == '1')
				{
					move_right(&tmp, i);
				}
				else
				{
					move_left(&tmp, i);
				}
				lvl++;
			}
			else
				move_right(&tmp, i);

		}
	}
}



/***************************************
*main function
**************************************/
int main()
{
	prepare_bit_seq();
	check_bits(test_str);
	print_ans();
//	printf("%d %d", N, L);
	return 0;
}
