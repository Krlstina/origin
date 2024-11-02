#include <iostream>
#include <string>
#include "Windows.h"
#include "FigureDynamic.h"

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    Triangle triangle;
    RightAngledTriangle rightAngledTriangle;
    IsoscelesTriangle isoscelesTriangle;
    EquilateralTriangle equilateralTriangle;
    
    print_info(&triangle);
    print_info(&rightAngledTriangle);
    print_info(&isoscelesTriangle);
    print_info(&equilateralTriangle);

    Quadrilateral quadrilateral;
    Parallelogram parallelogram{};
    RectangleFigure rectangle;
    Square square;
    Rhomb rhomb;
    
    print_info(&quadrilateral);
    print_info(&parallelogram);
    print_info(&rectangle);
    print_info(&square);
    print_info(&rhomb);

	return EXIT_SUCCESS;
}