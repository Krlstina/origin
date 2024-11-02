#include <iostream>
#include "triangle.h"

int Triangle::getSideA() { return aSide; }
int Triangle::getSideB() { return bSide; }
int Triangle::getSideC() { return cSide; }
int Triangle::getCornerA() { return cornerA; }
int Triangle::getCornerB() { return cornerB; }
int Triangle::getCornerC() { return cornerC; }
std::string Triangle::getName() { return name; };