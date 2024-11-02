#ifndef SQUARE_H
#define SQUARE_H

#include "rectangle_figure.h"

class Square :public RectangleFigure
{
public:
    Square(int sideAandBandC = 40)
        : RectangleFigure(sideAandBandC, sideAandBandC)
    {
        name = " вадрат";
    }
};

#endif