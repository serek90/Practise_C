#include <stdio.h>
#include <stdlib.h>

//#include "shape.h"
#include "circle.h"



int main()
{
    Shape *shape1 = getShapeInstance();
  //  Circle *shape2 = getCircleInstance();
        Circle *circle = getCircleInstance();


    shape1->functions.setX(shape1, 4);

    int x = shape1->functions.getX(shape1);
    int y = shape1->functions.getY(shape1);

    shape1->functions.display(shape1);

    //Circle

    circle->shape.functions.setX(circle, 4);

    int x2 = circle->shape.functions.getX(circle);
    int y2 = circle->shape.functions.getY(circle);
    circle->shape.functions.calcArea(circle);
    circle->shape.functions.calcPerm(circle);

    circle->shape.functions.display(circle);


    printf("%d %d", x, y);
    return 0;
}
