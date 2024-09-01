#include <iostream>
#include <Windows.h>
#include <string>

class Triangle
{
protected:
    int aSide{}, bSide{}, cSide{};
    int cornerA{}, cornerB{}, cornerC{};
    std::string name{ "Треугольник" };
public:
    int getSideA() { return aSide; }
    int getSideB() { return bSide; }
    int getSideC() { return cSide; }
    int getCornerA() { return cornerA; }
    int getCornerB() { return cornerB; }
    int getCornerC() { return cornerC; }
    std::string getName() { return name; };

    
    Triangle(int sideA = 10, int sideB = 50, int sideC = 5,
        int cornerA = 30, int cornerB = 10, int cornerC = 45, std::string name = "Треугольник")
        : aSide{ sideA }, bSide{ sideB }, cSide{ sideC },
        cornerA{ cornerA }, cornerB{ cornerB }, cornerC{ cornerC }, name{name}
    {}
};


class RightAngledTriangle :public Triangle
{
public:
    RightAngledTriangle(int sideA = 10, int sideB = 50, int sideC = 5, int cornerA = 30, int cornerB = 60)
        : Triangle(sideA, sideB, sideC, cornerA, cornerB, 90, "Прямоугольный треугольник")
    {}
};

class IsoscelesTriangle :public Triangle
{
public:
    IsoscelesTriangle(int sideAandC = 10, int sideB = 30, int cornerAandC = 60, int cornerB = 40)
        : Triangle(sideAandC, sideB, sideAandC, cornerAandC, cornerB, cornerAandC, "Равнобедренный треугольник")
    {}
};

class EquilateralTriangle :public Triangle
{
public:
    EquilateralTriangle(int sideAandBandC = 50, int cornerAandBandC = 60)
        : Triangle(sideAandBandC, sideAandBandC, sideAandBandC, cornerAandBandC, cornerAandBandC, cornerAandBandC, "Равносторонний треугольник")
    {}
};

class Quadrilateral
{
protected:
    int aSide{}, bSide{}, cSide{}, dSide{};
    int cornerA{}, cornerB{}, cornerC{}, cornerD{};
    std::string name{ "Quadrilateral" };
public:
    int getSideA() { return aSide; }
    int getSideB() { return bSide; }
    int getSideC() { return cSide; }
    int getSideD() { return dSide; }
    int getCornerA() { return cornerA; }
    int getCornerB() { return cornerB; }
    int getCornerC() { return cornerC; }
    int getCornerD() { return cornerD; }
    std::string getName() { return name; };

    Quadrilateral(int sideA = 10, int sideB = 20, int sideC = 30, int sideD = 40,
        int cornerA = 10, int cornerB = 40, int cornerC = 50, int cornerD = 70, std::string name = "Четырехугольник")
        : aSide{ sideA }, bSide{ sideB }, cSide{ sideC }, dSide{ sideD },
        cornerA{ cornerA }, cornerB{ cornerB }, cornerC{ cornerC }, cornerD{ cornerD }, name{ name }
    {}
};

class Parallelogram :public Quadrilateral
{
public:
    
    Parallelogram(int sideAandC = 50, int sideBandD = 40,
        int cornerAandC = 30, int cornerBandD = 70)
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

class Square :public RectangleFigure
{
public:
    Square(int sideAandBandC = 40)
        : RectangleFigure(sideAandBandC, sideAandBandC)
    {
        name = "Квадрат";
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

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Triangle triangle;
    RightAngledTriangle rightAngledTriangle;
    IsoscelesTriangle isoscelesTriangle;
    EquilateralTriangle equilateralTriangle;
    Quadrilateral quadrilateral;
    Parallelogram parallelogram{};
    RectangleFigure rectangle;
    Square square;
    Rhomb rhomb;

    Triangle* figureTriangle{ &triangle };
    print_info(figureTriangle);
    figureTriangle = &rightAngledTriangle;
    print_info(figureTriangle);
    figureTriangle = &isoscelesTriangle;
    print_info(figureTriangle);
    figureTriangle = &equilateralTriangle;
    print_info(figureTriangle);

    Quadrilateral* figureQuadrilateral{ &parallelogram };
    print_info(figureQuadrilateral);
    figureQuadrilateral = &rectangle;
    print_info(figureQuadrilateral);
    figureQuadrilateral = &square;
    print_info(figureQuadrilateral);
    figureQuadrilateral = &rhomb;
    print_info(figureQuadrilateral);

    return EXIT_SUCCESS;
}
