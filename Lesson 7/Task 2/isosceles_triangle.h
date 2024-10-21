#ifndef ISOSCELES_TRIANGLE_H
#define ISOSCELES_TRIANGLE_H

#include "triangle.h"

class IsoscelesTriangle :public Triangle
{
public:
    IsoscelesTriangle(int sideA = 10, int sideB = 50, int sideC = 5, int cornerA = 60, int cornerB = 60, int cornerC = 60);
};

#endif