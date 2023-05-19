#include <stdlib.h>
#include <stdio.h>
#include "fstruct.h"


struct fstruct_t
{
	int val_a;
	int val_b;
};


/*********************************************
*fstruct initialization
*********************************************/
int fstruct_init(struct fstruct_t **fs)
{
	*fs = malloc(sizeof(struct fstruct_t));

	if(!(*fs))
		return -1;

	(*fs)->val_a = 4;
	(*fs)->val_b = 7;

	return 0;
}

/*********************************************
*fstruct printing
*********************************************/
void fstruct_print(struct fstruct_t *fs)
{
	if(!fs)
		return;

	printf("fstruct->val_a : %d\n", fs->val_a);
        printf("fstruct->val_b : %d\n", fs->val_b);
}
