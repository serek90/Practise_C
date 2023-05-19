#include <stdio.h>
#include <stdlib.h>
#include "fstruct.h"


int main()
{
	struct fstruct_t *fstruct;

	fstruct_init(&fstruct);
	fstruct_print(fstruct);
	free(fstruct);

	return 0;
}
