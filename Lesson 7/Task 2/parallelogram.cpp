#include "parallelogram.h"
#include "figure_creation_error.h"

Parallelogram::Parallelogram(int sideA, int sideB, int sideC, int sideD, int cornerA, int cornerB, int cornerC, int cornerD, std::string name)
    : Quadrilateral(sideA, sideB, sideC, sideD, cornerA, cornerB, cornerC, cornerD, name)
{
    if (aSide != cSide)
    {
        throw CreationError("������ �������� ������ \"" + name + "\"! �������: ������� a, c �� �����");
    }
    else
    {
        if (bSide != dSide)
        {
            throw CreationError("������ �������� ������ \"" + name + "\"! �������: ������� b, d �� �����");
        }
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