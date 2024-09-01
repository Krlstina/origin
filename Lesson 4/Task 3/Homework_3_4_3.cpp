#include <iostream>
#include <Windows.h>
#include <string>

class Figure
{
private:
    int numberSides{ 0 };
    std::string name{ "Фигура" };
public:
    Figure() {}
    Figure(int sides, std::string name) : numberSides{ sides }, name{ name }
    {}

    virtual void outputInformation()
    {
        std::cout << this->name << ": " << std::endl;
        correctnessOfTheFigure();
        std::cout << "Количество сторон: " << this->numberSides << "\n" << std::endl;
    }

    virtual void correctnessOfTheFigure()
    {
        if (this->numberSides == 0) { std::cout << "Правильная" << std::endl; }
        else { std::cout << "Неправильная" << std::endl; }
    }
};

class Triangle: public Figure
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
        cornerA{ cornerA }, cornerB{ cornerB }, cornerC{ cornerC }, name{ name }
    {}

    void outputInformation() override
    {
        std::cout << this->name << ": " << std::endl;
        correctnessOfTheFigure();
        std::cout << "Стороны: a = " << this->aSide << ", b = " << this->bSide << ", c = " << this->cSide << std::endl;
        std::cout << "Углы: A = " << this->cornerA << ", B = " << this->cornerB << ", C = " << this->cornerC << "\n" << std::endl;
    }

    void correctnessOfTheFigure() override
    {
        if ((cornerA + cornerB + cornerC == 180) && (aSide > 0) && (bSide > 0) && (cSide > 0))
        { std::cout << "Правильная" << std::endl; }
        else { std::cout << "Неправильная" << std::endl; }
    }
};


class RightAngledTriangle :public Triangle
{
public:
    RightAngledTriangle(int sideA = 10, int sideB = 50, int sideC = 5,
        int cornerA = 30, int cornerB = 60)
        : Triangle(sideA, sideB, sideC, cornerA, cornerB, 90, "Прямоугольный треугольник")
    {}

    void correctnessOfTheFigure() override
    {
        if (cornerC == 90) { std::cout << "Правильная" << std::endl; }
        else { std::cout << "Неправильная" << std::endl; }
    }
};

class IsoscelesTriangle :public Triangle
{
public:
    IsoscelesTriangle(int sideAandC = 10, int sideB = 30, int cornerAandC = 60, int cornerB = 40)
        : Triangle(sideAandC, sideB, sideAandC, cornerAandC, cornerB, cornerAandC, "Равнобедренный треугольник")
    {}

    void correctnessOfTheFigure() override
    {
        if ((aSide == cSide) && (cornerA == cornerC)) { std::cout << "Правильная" << std::endl; }
        else { std::cout << "Неправильная" << std::endl; }
    }
};

class EquilateralTriangle :public Triangle
{
public:
    EquilateralTriangle(int sideAandBandC = 50, int cornerAandBandC = 60)
        : Triangle(sideAandBandC, sideAandBandC, sideAandBandC, cornerAandBandC, cornerAandBandC, cornerAandBandC, "Равносторонний треугольник")
    {}

    void correctnessOfTheFigure() override
    {
        if ((aSide == bSide) && (bSide == cSide) && (cornerA == 60) && (cornerB == 60) && (cornerC == 60)) { std::cout << "Правильная" << std::endl; }
        else { std::cout << "Неправильная" << std::endl; }
    }
};

class Quadrilateral: public Figure
{
protected:
    int aSide{}, bSide{}, cSide{}, dSide{};
    int cornerA{}, cornerB{}, cornerC{}, cornerD{};
    std::string name{ "Четырехугольник" };
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

    void outputInformation() override
    {
        std::cout << this->name << ": " << std::endl;
        correctnessOfTheFigure();
        std::cout << "Стороны: a = " << this->aSide << ", b = " << this->bSide << ", c = " << this->cSide << ", d = " << this->dSide << std::endl;
        std::cout << "Углы: A = " << this->cornerA << ", B = " << this->cornerB << ", C = " << this->cornerC << ", D = " << this->cornerD << "\n" << std::endl;
    }

    void correctnessOfTheFigure() override
    {
        if ((cornerA + cornerB + cornerC + cornerD == 360) && (aSide > 0) && (bSide > 0) && (cSide > 0) && (dSide > 0)) { std::cout << "Правильная" << std::endl; }
        else { std::cout << "Неправильная" << std::endl; }
    }
};

class Parallelogram :public Quadrilateral
{
public:

    Parallelogram(int sideAandC = 50, int sideBandD = 40,
        int cornerAandC = 30, int cornerBandD = 70)
        : Quadrilateral(sideAandC, sideBandD, sideAandC, sideBandD, cornerAandC, cornerBandD, cornerAandC, cornerBandD, "Параллелограмм")
    { }

    void correctnessOfTheFigure() override
    {
        if ((cornerA == cornerC) && (cornerB == cornerD) && (aSide == cSide) && (bSide == dSide)) { std::cout << "Правильная" << std::endl; }
        else { std::cout << "Неправильная" << std::endl; }
    }
};

class RectangleFigure :public Parallelogram
{
public:
    RectangleFigure(int sideAandC = 10, int sideBandD = 40)
        : Parallelogram(sideAandC, sideBandD, 90, 90)
    {
        name = "Прямоугольник";
    }

    void correctnessOfTheFigure() override
    {
        if ((cornerA == 90) && (cornerB == 90) && (cornerC == 90) && (cornerD == 90) && (aSide == cSide) && (bSide == dSide)) { std::cout << "Правильная" << std::endl; }
        else { std::cout << "Неправильная" << std::endl; }
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

    void correctnessOfTheFigure() override
    {
        if ((cornerA == 90) && (cornerB == 90) && (cornerC == 90) && (cornerD == 90) && (aSide == cSide) && (cSide == bSide) && (bSide == dSide)) { std::cout << "Правильная" << std::endl; }
        else { std::cout << "Неправильная" << std::endl; }
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

    void correctnessOfTheFigure() override
    {
        if ((cornerA == cornerC) && (cornerB == cornerD) && (aSide == cSide) && (cSide == bSide) && (bSide == dSide)) { std::cout << "Правильная" << std::endl; }
        else { std::cout << "Неправильная" << std::endl; }
    }
};

void print_info(Figure* figure) { figure->outputInformation(); }

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Figure figure;
    Triangle triangle;
    RightAngledTriangle rightAngledTriangle;
    IsoscelesTriangle isoscelesTriangle;
    EquilateralTriangle equilateralTriangle;
    Quadrilateral quadrilateral;
    Parallelogram parallelogram{};
    RectangleFigure rectangle;
    Square square;
    Rhomb rhomb;

    Figure* figureFigure(&figure);
    print_info(figureFigure);
    figureFigure = &triangle;
    print_info(figureFigure);
    figureFigure = &rightAngledTriangle;
    print_info(figureFigure);
    figureFigure = &isoscelesTriangle;
    print_info(figureFigure);
    figureFigure = &equilateralTriangle;
    print_info(figureFigure);
    figureFigure = &quadrilateral;
    print_info(figureFigure);
    figureFigure = &parallelogram;
    print_info(figureFigure);
    figureFigure = &rectangle;
    print_info(figureFigure);
    figureFigure = &square;
    print_info(figureFigure);
    figureFigure = &rhomb;
    print_info(figureFigure);

    return EXIT_SUCCESS;
}
