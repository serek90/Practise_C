#include "circle.h"
//#include "shape.h"



void displayCircle(Circle *circle)
{
    printf("Circle\n");
    printf("Area is: %d", circle->shape.area);
    printf("Permit is: %d", circle->shape.permit);

}

void circleCalcArea(Circle *circle)
{
    circle->shape.area = circle->radius * circle->radius * 3.14f;
}
float circleGetArea(Circle *circle){ return circle->shape.area;}
void circleCalcPerm(Circle *circle)
{
    circle->shape.permiter = 2 * 3.14f * circle->radius;
}
int circleGetPerm(Circle *circle){ return circle->shape.permiter;}



Circle *getCircleInstance(void)
{

    Circle *circle = (Circle*)malloc(sizeof(Circle));
    circle->shape.functions.setX = shapeSetX;
    circle-.shape.functions.getX = shapeGetX;
    circle->shape.functions.setY = shapeSetY;
    circle-.shape.functions.getY = shapeGetY;

    circle->shape.functions.display = displayCircle;
    circle->shape.functions.calcArea = circleCalcArea;
    circle->shape.functions.getArea = circleGetArea;
    circle->shape.functions.calcPerm = circleCalcPerm;
    circle->shape.functions.getPerm = circleGetPerm;

    circle->shape.x = 0;
    circle->shape.y = 0;
    circle->shape.area = 0.0f;
    circle->shape.permiter = 0;
    circle->radius = 0;

    return circle;

}
