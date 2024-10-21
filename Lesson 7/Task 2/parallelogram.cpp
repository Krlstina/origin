#include "parallelogram.h"
#include "figure_creation_error.h"

Parallelogram::Parallelogram(int sideA, int sideB, int sideC, int sideD, int cornerA, int cornerB, int cornerC, int cornerD, std::string name)
    : Quadrilateral(sideA, sideB, sideC, sideD, cornerA, cornerB, cornerC, cornerD, name)
{
    if (aSide != cSide)
    {
        throw CreationError("Ошибка создания фигуры \"" + name + "\"! Причина: стороны a, c не равны");
    }
    else
    {
        if (bSide != dSide)
        {
            throw CreationError("Ошибка создания фигуры \"" + name + "\"! Причина: стороны b, d не равны");
        }
    }
    if (cornerA != cornerC)
    {
        throw CreationError("Ошибка создания фигуры \"" + name + "\"! Причина: углы A, C не равны");
    }
    else
    {
        if (cornerB != cornerD)
        {
            throw CreationError("Ошибка создания фигуры \"" + name + "\"! Причина: углы B, D не равны");
        }
    }
}