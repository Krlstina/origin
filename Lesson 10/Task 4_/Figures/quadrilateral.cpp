#include <iostream>
#include "quadrilateral.h"

int Quadrilateral::getSideA() { return aSide; }
int Quadrilateral::getSideB() { return bSide; }
int Quadrilateral::getSideC() { return cSide; }
int Quadrilateral::getSideD() { return dSide; }
int Quadrilateral::getCornerA() { return cornerA; }
int Quadrilateral::getCornerB() { return cornerB; }
int Quadrilateral::getCornerC() { return cornerC; }
int Quadrilateral::getCornerD() { return cornerD; }
std::string Quadrilateral::getName() { return name; };