#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

#include "quadrilateral.h"

class Parallelogram :public Quadrilateral
{
public:
    Parallelogram(int sideA = 5, int sideB = 7, int sideC = 5, int sideD = 7, int cornerA = 60, int cornerB = 120, int cornerC = 60, int cornerD = 120, std::string name = "ֿאנאככוכמדנאלל");
};

#endif