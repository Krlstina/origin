#include "FigureDynamic.h"

int Triangle::getSideA() { return aSide; }
int Triangle::getSideB() { return bSide; }
int Triangle::getSideC() { return cSide; }
int Triangle::getCornerA() { return cornerA; }
int Triangle::getCornerB() { return cornerB; }
int Triangle::getCornerC() { return cornerC; }
std::string Triangle::getName() { return name; };

int Quadrilateral::getSideA() { return aSide; }
int Quadrilateral::getSideB() { return bSide; }
int Quadrilateral::getSideC() { return cSide; }
int Quadrilateral::getSideD() { return dSide; }
int Quadrilateral::getCornerA() { return cornerA; }
int Quadrilateral::getCornerB() { return cornerB; }
int Quadrilateral::getCornerC() { return cornerC; }
int Quadrilateral::getCornerD() { return cornerD; }
std::string Quadrilateral::getName() { return name; };

void print_info(Triangle* triangle)
{
    std::cout << triangle->getName() << ": " << std::endl;
    std::cout << "Стороны: a = " << triangle->getSideA() << ", b = " << triangle->getSideB() << ", c = " << triangle->getSideC() << std::endl;
    std::cout << "Углы: A = " << triangle->getCornerA() << ", B = " << triangle->getCornerB() << ", C = " << triangle->getCornerC() << "\n" << std::endl;
}

void print_info(Quadrilateral* quadrilateral)
{
    std::cout << quadrilateral->getName() << ": " << std::endl;
    std::cout << "Стороны: a = " << quadrilateral->getSideA() << ", b = " << quadrilateral->getSideB() << ", c = " << quadrilateral->getSideC() << ", d = " << quadrilateral->getSideD() << std::endl;
    std::cout << "Углы: A = " << quadrilateral->getCornerA() << ", B = " << quadrilateral->getCornerB() << ", C = " << quadrilateral->getCornerC() << ", D = " << quadrilateral->getCornerD() << "\n" << std::endl;
}