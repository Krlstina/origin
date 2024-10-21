#ifndef EQUILATERAL_TRIANGLE_H
#define EQUILATERAL_TRIANGLE_H

#include "triangle.h"

class EquilateralTriangle :public Triangle
{
public:
    EquilateralTriangle(int sideA = 5, int sideB = 5, int sideC = 5, int cornerA = 60, int cornerB = 60, int cornerC = 60);
};

#endif