#ifndef CIRCLE_H
#define CIRCLE_H

#include <stdio.h>
#include <stdlib.h>
#include "shape.h"

typedef struct _circle
{
    Shape shape;
    int radius;

}Circle;

Circle *getCircleInstance();


#endif // CIRCLE_H_INCLUDED
