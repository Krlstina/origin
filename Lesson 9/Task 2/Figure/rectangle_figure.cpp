#include "rectangle_figure.h"

RectangleFigure::RectangleFigure(int sideAandC, int sideBandD)
    : Parallelogram(sideAandC, sideBandD, 90, 90)
{
    name = "Прямоугольник";
}