#include <iostream>
#include <Windows.h>
#include <string>
#include <exception>
#include <string_view>
#include "triangle.h"
#include "quadrilateral.h"
#include "right_angled_triangle.h"
#include "isosceles_triangle.h"
#include "equilateral_triangle.h"
#include "parallelogram.h"
#include "rectangle_figure.h"
#include "square.h"
#include "rhomb.h"
#include "figure_creation_error.h"

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try
    {
        Triangle triangle{};
        Triangle* figureTriangle{ &triangle };
        print_info(figureTriangle);
        RightAngledTriangle rightAngledTriangle{};
        figureTriangle = &rightAngledTriangle;
        print_info(figureTriangle);
        IsoscelesTriangle isoscelesTriangle{};
        figureTriangle = &isoscelesTriangle;
        print_info(figureTriangle);
        EquilateralTriangle equilateralTriangle{};
        figureTriangle = &equilateralTriangle;
        print_info(figureTriangle);
        
        Quadrilateral quadrilateral{};
        Quadrilateral* figureQuadrilateral{ &quadrilateral };
        print_info(figureQuadrilateral);
        Parallelogram parallelogram{}; 
        figureQuadrilateral = &parallelogram;
        print_info(figureQuadrilateral);
        RectangleFigure rectangle{};
        figureQuadrilateral = &rectangle;
        print_info(figureQuadrilateral);
        Square square{};
        figureQuadrilateral = &square;
        print_info(figureQuadrilateral);
        Rhomb rhomb{};
        figureQuadrilateral = &rhomb;
        print_info(figureQuadrilateral);
    }
    catch (const CreationError& error)
    {
        std::cerr << error.what() << std::endl;
        exit(EXIT_FAILURE);
    }
    catch (...)
    {
        std::cerr << "Неизвестная ошибка!!";
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}
