#include <iostream>
#include <Windows.h>
#include <string>
#include "triangle.h"             //можно не указывать - подтянется через классы-потомки
#include "quadrilateral.h"        //можно не указывать - подтянется через класс-потомки
#include "right_angled_triangle.h"
#include "isosceles_triangle.h"
#include "equilateral_triangle.h"
#include "parallelogram.h"        //можно не указывать - подтянется через класс-потомки
#include "rectangle_figure.h"      //можно не указывать - подтянется через класс-потомки
#include "square.h"
#include "rhomb.h"

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
