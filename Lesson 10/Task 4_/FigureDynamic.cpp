#include "FigureDynamic.h"

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