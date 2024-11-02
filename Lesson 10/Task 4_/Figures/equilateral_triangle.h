#ifndef EQUILATERAL_TRIANGLE_H
#define EQUILATERAL_TRIANGLE_H

#include "triangle.h"

class EquilateralTriangle :public Triangle
{
public:
    EquilateralTriangle(int sideAandBandC = 50, int cornerAandBandC = 60)
        : Triangle(sideAandBandC, sideAandBandC, sideAandBandC, cornerAandBandC, cornerAandBandC, cornerAandBandC, "Равносторонний треугольник")
    {}
};

#endif