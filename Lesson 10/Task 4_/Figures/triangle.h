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
    Triangle(int sideA = 10, int sideB = 50, int sideC = 5,
        int cornerA = 30, int cornerB = 10, int cornerC = 45, std::string name = "Треугольник")
        : aSide{ sideA }, bSide{ sideB }, cSide{ sideC },
        cornerA{ cornerA }, cornerB{ cornerB }, cornerC{ cornerC }, name{ name }
    {}
    
    int getSideA();
    int getSideB();
    int getSideC();
    int getCornerA();
    int getCornerB();
    int getCornerC();
    std::string getName();
};

#endif