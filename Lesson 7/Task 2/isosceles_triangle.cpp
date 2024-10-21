#include "isosceles_triangle.h"
#include "figure_creation_error.h"

IsoscelesTriangle::IsoscelesTriangle(int sideA, int sideB, int sideC, int cornerA, int cornerB, int cornerC)
    : Triangle(sideA, sideB, sideC, cornerA, cornerB, cornerC, "�������������� �����������")
{
    if (sideA != sideC)
    {
        throw CreationError("������ �������� ������ \"" + name + "\"! �������: ������� � � � �� �����");
    }
    if (cornerA != cornerC)
    {
        throw CreationError("������ �������� ������ \"" + name + "\"! �������: ���� � � � �� �����");
    }
}