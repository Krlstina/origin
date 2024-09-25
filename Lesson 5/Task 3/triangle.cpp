#include <iostream>
#include "triangle.h"

Triangle::Triangle(int sideA, int sideB, int sideC,
    int cornerA, int cornerB, int cornerC, std::string name)
    : aSide{ sideA }, bSide{ sideB }, cSide{ sideC },
    cornerA{ cornerA }, cornerB{ cornerB }, cornerC{ cornerC }, name{ name }
{}

int Triangle::getSideA() { return aSide; }
int Triangle::getSideB() { return bSide; }
int Triangle::getSideC() { return cSide; }
int Triangle::getCornerA() { return cornerA; }
int Triangle::getCornerB() { return cornerB; }
int Triangle::getCornerC() { return cornerC; }
std::string Triangle::getName() { return name; };

void print_info(Triangle* triangle)
{
    std::cout << triangle->getName() << ": " << std::endl;
    std::cout << "Стороны: a = " << triangle->getSideA() << ", b = " << triangle->getSideB() << ", c = " << triangle->getSideC() << std::endl;
    std::cout << "Углы: A = " << triangle->getCornerA() << ", B = " << triangle->getCornerB() << ", C = " << triangle->getCornerC() << "\n" << std::endl;
}