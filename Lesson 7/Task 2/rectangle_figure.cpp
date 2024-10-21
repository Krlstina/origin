#include "rectangle_figure.h"
#include "figure_creation_error.h"

RectangleFigure::RectangleFigure(int sideA, int sideB, int sideC, int sideD, std::string name)
    : Parallelogram(sideA, sideB, sideC, sideD, 90, 90, 90, 90, name)
{
    if (cornerB != 90 || cornerB != 90 || cornerB != 90 || cornerB != 90)
    {
        throw CreationError("Ошибка создания фигуры \"" + name + "\"! Причина: не всес углы A, B, C, D равны 90");
    }
}