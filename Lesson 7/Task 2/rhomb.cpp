#include "rhomb.h"
#include "figure_creation_error.h"

Rhomb::Rhomb(int sideA, int sideB, int sideC, int sideD)
    : Parallelogram(sideA, sideB, sideC, sideD, 70, 110, 70, 110, "Ромб")
{

    if (aSide != bSide || aSide != cSide || bSide != cSide || bSide != dSide || cSide != dSide || dSide != aSide)
    {
        throw CreationError("Ошибка создания фигуры \"" + name + "\"! Причина: стороны a, b, c, d не равны");
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