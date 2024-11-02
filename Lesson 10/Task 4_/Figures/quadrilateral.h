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
        int cornerA = 10, int cornerB = 40, int cornerC = 50, int cornerD = 70, std::string name = "Четырехугольник")
        : aSide{ sideA }, bSide{ sideB }, cSide{ sideC }, dSide{ sideD },
        cornerA{ cornerA }, cornerB{ cornerB }, cornerC{ cornerC }, cornerD{ cornerD }, name{ name }
    {}

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

#endif