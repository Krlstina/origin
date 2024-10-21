#include <iostream>
#include "quadrilateral.h"
#include "figure_creation_error.h"

Quadrilateral::Quadrilateral(int sideA, int sideB, int sideC, int sideD,
    int cornerA, int cornerB, int cornerC, int cornerD, std::string name)
    : aSide{ sideA }, bSide{ sideB }, cSide{ sideC }, dSide{ sideD },
    cornerA{ cornerA }, cornerB{ cornerB }, cornerC{ cornerC }, cornerD{ cornerD }, name{ name }
{
    std::cout << "C������� ������ \"" << name << "\"..." << std::endl;
    if (aSide == 0 || bSide == 0 || cSide == 0 || dSide == 0)
    {
        throw CreationError("������ �������� ������ \"" + name + "\"! �������: ���������� ������ �� ����� 4");
    }
    if (cornerA + cornerB + cornerC + cornerD != 360)
    {
        throw CreationError("������ �������� ������ \"" + name + "\"! �������: ����� ����� �� ����� 360");
    }
}

int Quadrilateral::getSideA() { return aSide; }
int Quadrilateral::getSideB() { return bSide; }
int Quadrilateral::getSideC() { return cSide; }
int Quadrilateral::getSideD() { return dSide; }
int Quadrilateral::getCornerA() { return cornerA; }
int Quadrilateral::getCornerB() { return cornerB; }
int Quadrilateral::getCornerC() { return cornerC; }
int Quadrilateral::getCornerD() { return cornerD; }
std::string Quadrilateral::getName() { return name; };

void print_info(Quadrilateral* quadrilateral)
{
    std::cout << "������ \"" << quadrilateral->getName() << "\" �������: " << std::endl;
    std::cout << "�������: a = " << quadrilateral->getSideA() << ", b = " << quadrilateral->getSideB() << ", c = " << quadrilateral->getSideC() << ", d = " << quadrilateral->getSideD() << std::endl;
    std::cout << "����: A = " << quadrilateral->getCornerA() << ", B = " << quadrilateral->getCornerB() << ", C = " << quadrilateral->getCornerC() << ", D = " << quadrilateral->getCornerD() << "\n" << std::endl;
}