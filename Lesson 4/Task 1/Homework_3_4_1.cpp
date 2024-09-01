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

    void outputInformation()
    {
        std::cout << this->name << ": " << this->numberSides << std::endl;
    }
};

class Triangle :public Figure
{
private:
    int numberSides{ 3 };
    std::string name{ "Треугольник" };
public:
    Triangle() {}
    void outputInformation()
    {
        std::cout << this->name << ": " << this->numberSides << std::endl;
    }
};

class Quadrilateral :public Figure
{
private:
    int numberSides{ 4 };
    std::string name{ "Четырехугольник" };
public:
    Quadrilateral() {}
    void outputInformation()
    {
        std::cout << this->name << ": " << this->numberSides << std::endl;
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Figure figure;
    Triangle triangle;
    Quadrilateral quadrilateral;

    std::cout << "<Фигура>: <количество сторон>" << std::endl;

    figure.outputInformation();
    triangle.outputInformation();
    quadrilateral.outputInformation();

    return EXIT_SUCCESS;
}

