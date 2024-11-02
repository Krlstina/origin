#ifndef ISOSCELES_TRIANGLE_H
#define ISOSCELES_TRIANGLE_H

#include "triangle.h"

class IsoscelesTriangle :public Triangle
{
public:
    IsoscelesTriangle(int sideAandC = 10, int sideB = 30, int cornerAandC = 60, int cornerB = 40)
        : Triangle(sideAandC, sideB, sideAandC, cornerAandC, cornerB, cornerAandC, "Равнобедренный треугольник")
    {}
};

#endif