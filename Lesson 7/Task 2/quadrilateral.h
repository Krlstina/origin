#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

#include <string>

class Quadrilateral
{
protected:
    int aSide{}, bSide{}, cSide{}, dSide{};
    int cornerA{}, cornerB{}, cornerC{}, cornerD{};
    std::string name{};

public:
    Quadrilateral(int sideA = 10, int sideB = 20, int sideC = 30, int sideD = 40,
        int cornerA = 100, int cornerB = 60, int cornerC = 150, int cornerD = 50, std::string name = "Четырехугольник");

    int getSideA();
    int getSideB();
    int getSideC();
    int getSideD();
    int getCornerA();
    int getCornerB();
    int getCornerC();
    int getCornerD();
    std::string getName();
};

void print_info(Quadrilateral* quadrilateral);

#endif