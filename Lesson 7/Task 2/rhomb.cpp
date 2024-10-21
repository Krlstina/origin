#include "rhomb.h"
#include "figure_creation_error.h"

Rhomb::Rhomb(int sideA, int sideB, int sideC, int sideD)
    : Parallelogram(sideA, sideB, sideC, sideD, 70, 110, 70, 110, "����")
{

    if (aSide != bSide || aSide != cSide || bSide != cSide || bSide != dSide || cSide != dSide || dSide != aSide)
    {
        throw CreationError("������ �������� ������ \"" + name + "\"! �������: ������� a, b, c, d �� �����");
    }
    if (cornerA != cornerC)
    {
        throw CreationError("������ �������� ������ \"" + name + "\"! �������: ���� A, C �� �����");
    }
    else
    {
        if (cornerB != cornerD)
        {
            throw CreationError("������ �������� ������ \"" + name + "\"! �������: ���� B, D �� �����");
        }
    }
}