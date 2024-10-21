#ifndef RECTANGLE_FIGURE_H
#define RECTANGLE_FIGURE_H

#include "parallelogram.h"

class RectangleFigure :public Parallelogram
{
public:
    RectangleFigure(int sideA = 10, int sideB = 40, int sideC = 10, int sideD = 40, std::string name = "Прямоугольник");
};

#endif