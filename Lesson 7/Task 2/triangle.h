#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <string>

class Triangle
{
protected:
    int aSide{}, bSide{}, cSide{};
    int cornerA{}, cornerB{}, cornerC{};
    std::string name{};
public:
    Triangle(int sideA = 10, int sideB = 22, int sideC = 5,
        int cornerA = 35, int cornerB = 100, int cornerC = 45, std::string name = "Треугольник");

    int getSideA();
    int getSideB();
    int getSideC();
    int getCornerA();
    int getCornerB();
    int getCornerC();
    std::string getName();

};

void print_info(Triangle* triangle);

#endif