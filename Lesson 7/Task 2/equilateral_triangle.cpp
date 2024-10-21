#include "equilateral_triangle.h"
#include "figure_creation_error.h"

EquilateralTriangle::EquilateralTriangle(int sideA, int sideB, int sideC, int cornerA, int cornerB, int cornerC)
    : Triangle(sideA, sideB, sideC, cornerA, cornerB, cornerC, "�������������� �����������")
{
    if (aSide != bSide || bSide != cSide || cSide != aSide)
    {
        throw CreationError("������ �������� ������ \"" + name + "\"! �������: ������� a, b, c �� �����");
    }
    if (cornerA != 60 || cornerB != 60 || cornerC != 60)
    {
        throw CreationError("������ �������� ������ \"" + name + "\"! �������: ���� A, B, C �� ����� 60");
    }
}