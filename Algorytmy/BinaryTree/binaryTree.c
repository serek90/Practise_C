#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode
{
	int value;
	struct treeNode *right;
	struct treeNode *left;

}treeNode;

/************************************************
*function to create nwe tree node
*return: new tree node
************************************************/
treeNode *create_tree_node(int value)
{
	treeNode *tmp = malloc(sizeof (treeNode));

	if(tmp != NULL)
	{
		tmp->value = value;
		tmp->right = NULL;
		tmp->left  = NULL;
	}
	return tmp;
}

void print_tabs(int tabs_num)
{

	for(int i = 0; i < tabs_num; i++)
		printf("\t");
}
/***********************************************
*Function to print binary tree
************************************************/

void print_binary_tree_rec(treeNode *root, int level)
{
	if(root == NULL)
	{
		printf("----Empyt tree ----\n");
		return;
	}

	print_tabs(level);
	printf("value = %d\n", root->value);

	print_tabs(level);
	printf("Right node:");
	print_binary_tree_rec(root->right, level + 1);

	print_tabs(level);
	printf("Left node");
	print_binary_tree_rec(root->left, level + 1);

	print_tabs(level);
	printf("done\n");

}

void print_binary_tree(treeNode* root)
{
	print_binary_tree_rec( root, 0);
}

int main()
{
	treeNode *node1 = create_tree_node(10);
	treeNode *node2 = create_tree_node(11);
    treeNode *node3 = create_tree_node(12);
    treeNode *node4 = create_tree_node(13);
    treeNode *node5 = create_tree_node(24);
    treeNode *node6 = create_tree_node(25);

	node1->right = node2;
	node1->left  = node3;

	node2->right = node4;
	node2->left  = node5;

	print_binary_tree(node1);
	
	//Free every element from the heap;
	free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(node5);
    free(node6);

}
