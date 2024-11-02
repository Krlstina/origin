#ifndef RECTANGLE_FIGURE_H
#define RECTANGLE_FIGURE_H

#include "parallelogram.h"

class RectangleFigure :public Parallelogram
{
public:
    RectangleFigure(int sideAandC = 10, int sideBandD = 40)
        : Parallelogram(sideAandC, sideBandD, 90, 90)
    {
        name = "Прямоугольник";
    }
};

#endif