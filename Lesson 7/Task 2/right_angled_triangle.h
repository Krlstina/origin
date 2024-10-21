#ifndef RIGHT_ANGLED_TRIANGLE_H
#define RIGHT_ANGLED_TRIANGLE_H

#include "triangle.h"

class RightAngledTriangle :public Triangle
{
public:
    
    RightAngledTriangle(int sideA = 10, int sideB = 50, int sideC = 5, int cornerA = 50, int cornerB = 50);
};

#endif