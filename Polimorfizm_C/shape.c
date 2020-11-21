#include "shape.h"


void shapeSetX(Shape *shape, int x){shape->x = x;}
int shapeGetX(Shape *shape){return shape->x;}
void shapeSetY(Shape *shape, int y){shape->y = y;}
int shapeGetY(Shape *shape){return shape->y;}

void shapeDisplay(Shape *shape){printf("Shape\n");}

//virtual function
void shapeCalcArea(Shape *shape){ return 0;}
float shapeGetArea(Shape *shape){ return shape->area;}
void shapeCalcPerm(Shape *shape){ return 0;}
int shapeGetPerm(Shape *shape){ return shape->permiter;}


//constructor
Shape *getShapeInstance()
{
    Shape *shape = (Shape*)malloc(sizeof(Shape));
    shape->functions.setX = shapeSetX;
    shape->functions.getX = shapeGetX;
    shape->functions.setY = shapeSetY;
    shape->functions.getY = shapeGetY;
    shape->functions.display = shapeDisplay;
    shape->functions.calcArea = shapeCalcArea;
    shape->functions.getArea = shapeGetArea;
    shape->functions.calcPerm = shapeCalcPerm;
    shape->functions.getPerm = shapeGetPerm;

    shape->x = 5;
    shape->y = 6;
    shape->area = 0.0f;
    shape->permiter = 0;

    return shape;
}


