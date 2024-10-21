#include "isosceles_triangle.h"
#include "figure_creation_error.h"

IsoscelesTriangle::IsoscelesTriangle(int sideA, int sideB, int sideC, int cornerA, int cornerB, int cornerC)
    : Triangle(sideA, sideB, sideC, cornerA, cornerB, cornerC, "Равнобедренный треугольник")
{
    if (sideA != sideC)
    {
        throw CreationError("Ошибка создания фигуры \"" + name + "\"! Причина: стороны а и с не равны");
    }
    if (cornerA != cornerC)
    {
        throw CreationError("Ошибка создания фигуры \"" + name + "\"! Причина: углы А и С не равны");
    }
}