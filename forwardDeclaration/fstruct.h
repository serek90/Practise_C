/*
 *	description: Simple program to show
 *      do member of struct private in C
 *
 *	author: jseroczy
 */

#ifndef FSTRUCT_H
#define FSTRUCT_H

extern struct fstruct_t;

int fstruct_init(struct fstruct_t **fs);
void fstruct_print(struct fstruct_t *fs);

#endif /* !define FSTRUCT */
