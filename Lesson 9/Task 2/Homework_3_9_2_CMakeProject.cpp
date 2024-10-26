#include <iostream>
#include "Windows.h"
#include <string>
#include "Figure/triangle.h"
#include "Figure/quadrilateral.h"
#include "Figure/right_angled_triangle.h"
#include "Figure/isosceles_triangle.h"
#include "Figure/equilateral_triangle.h"
#include "Figure/parallelogram.h"
#include "Figure/rectangle_figure.h"
#include "Figure/square.h"
#include "Figure/rhomb.h"

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
