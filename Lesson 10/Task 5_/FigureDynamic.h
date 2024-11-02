#ifndef FIGUREDYNAMIC_H
#define FIGUREDYNAMIC_H

#include <iostream>
#include <string>

//треугольники
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

class EquilateralTriangle :public Triangle
{
public:
    EquilateralTriangle(int sideAandBandC = 50, int cornerAandBandC = 60)
        : Triangle(sideAandBandC, sideAandBandC, sideAandBandC, cornerAandBandC, cornerAandBandC, cornerAandBandC, "Равносторонний треугольник")
    {}
};

class IsoscelesTriangle :public Triangle
{
public:
    IsoscelesTriangle(int sideAandC = 10, int sideB = 30, int cornerAandC = 60, int cornerB = 40)
        : Triangle(sideAandC, sideB, sideAandC, cornerAandC, cornerB, cornerAandC, "Равнобедренный треугольник")
    {}
};

class RightAngledTriangle :public Triangle
{
public:
    RightAngledTriangle(int sideA = 10, int sideB = 50, int sideC = 5, int cornerA = 30, int cornerB = 60)
        : Triangle(sideA, sideB, sideC, cornerA, cornerB, 90, "Прямоугольный треугольник")
    {}
};


//четырехугольники
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

class Parallelogram :public Quadrilateral
{
public:
    Parallelogram(int sideAandC = 50, int sideBandD = 40, int cornerAandC = 30, int cornerBandD = 70)
        : Quadrilateral(sideAandC, sideBandD, sideAandC, sideBandD, cornerAandC, cornerBandD, cornerAandC, cornerBandD, "Параллелограмм")
    { }
};

class RectangleFigure :public Parallelogram
{
public:
    RectangleFigure(int sideAandC = 10, int sideBandD = 40)
        : Parallelogram(sideAandC, sideBandD, 90, 90)
    {
        name = "Прямоугольник";
    }
};

class Rhomb :public Parallelogram
{
public:
    Rhomb(int sideAandBandC = 60, int cornerAandC = 70, int cornerBandD = 55)
        : Parallelogram(sideAandBandC, sideAandBandC, cornerAandC, cornerBandD)
    {
        name = "Ромб";
    }
};

class Square :public RectangleFigure
{
public:
    Square(int sideAandBandC = 40)
        : RectangleFigure(sideAandBandC, sideAandBandC)
    {
        name = "Квадрат";
    }
};

void print_info(Triangle* triangle);
void print_info(Quadrilateral* quadrilateral);

#endif