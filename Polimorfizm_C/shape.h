#ifndef SHAPE_H

#include <stdio.h>
#include <stdlib.h>


typedef void (*fptrSet)(void*, int);
typedef int (*fptrGet)(void*);
typedef void (*fptrDisplay)(void*);
typedef void (*fptrSetArea)(void*);
typedef float (*fptrGetArea)(void*);
typedef void (*fptrSetPermiter)(void*);
typedef int (*fptrGetPermiter)(void*);

typedef struct _functions
{
    fptrSet setX;             // it is the same as  void (*setX)(void *, int);
    fptrGet getX;             // int (*getX)(void *);
    fptrSet setY;             // void (*setY)(void *, int);
    fptrGet getY;             // int (*getY)(void *);
    fptrDisplay display;      // void (*display)();
    fptrSetArea calcArea;     // void (*calcArea)(void*);
    fptrGetArea getArea;      // int (*getArea)(void*);
    fptrSetPermiter calcPerm;
    fptrGetPermiter getPerm;

}vFunctions;



typedef struct _shape
{
    //public:
    vFunctions functions;

    //private:
    int x;
    int y;
    float area;
    int permiter;

}Shape;

Shape *getShapeInstance();

#endif // SHAPE_H
