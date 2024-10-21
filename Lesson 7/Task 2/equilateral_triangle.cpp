#include "equilateral_triangle.h"
#include "figure_creation_error.h"

EquilateralTriangle::EquilateralTriangle(int sideA, int sideB, int sideC, int cornerA, int cornerB, int cornerC)
    : Triangle(sideA, sideB, sideC, cornerA, cornerB, cornerC, "Равносторонний треугольник")
{
    if (aSide != bSide || bSide != cSide || cSide != aSide)
    {
        throw CreationError("Ошибка создания фигуры \"" + name + "\"! Причина: стороны a, b, c не равны");
    }
    if (cornerA != 60 || cornerB != 60 || cornerC != 60)
    {
        throw CreationError("Ошибка создания фигуры \"" + name + "\"! Причина: углы A, B, C не равны 60");
    }
}