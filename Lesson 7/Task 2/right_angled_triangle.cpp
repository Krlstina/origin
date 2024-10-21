#include <iostream>
#include <string>

#include "right_angled_triangle.h"
#include "figure_creation_error.h"
#include "triangle.h"

RightAngledTriangle::RightAngledTriangle(int sideA, int sideB, int sideC, int cornerA, int cornerB)
    : Triangle(sideA, sideB, sideC, cornerA, cornerB, 80, "Прямоугольный треугольник")
{
    if (cornerC != 90)
    {
        throw CreationError("Ошибка создания фигуры \"" + name + "\"! Причина: угол С не равен 90");
    }
}