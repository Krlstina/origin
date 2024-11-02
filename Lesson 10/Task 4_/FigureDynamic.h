#ifndef FIGUREDYNAMIC_H
#define FIGUREDYNAMIC_H

#ifdef FIGUREDYNAMICLIB_EXPORTS
#define FIGUREDYNAMIC_API __declspec(dllexport)
#else
#define FIGUREDYNAMIC_API __declspec(dllimport)
#endif

#include <iostream>
#include <string>

#include "Figures/triangle.h"
#include "Figures/quadrilateral.h"
#include "Figures/right_angled_triangle.h"
#include "Figures/isosceles_triangle.h"
#include "Figures/equilateral_triangle.h"
#include "Figures/parallelogram.h"
#include "Figures/rectangle_figure.h"
#include "Figures/square.h"
#include "Figures/rhomb.h"

void FIGUREDYNAMIC_API print_info(Triangle* triangle);
void FIGUREDYNAMIC_API print_info(Quadrilateral* quadrilateral);

#endif