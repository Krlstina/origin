#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

#include "quadrilateral.h"

class Parallelogram :public Quadrilateral
{
public:
    Parallelogram(int sideAandC = 50, int sideBandD = 40, int cornerAandC = 30, int cornerBandD = 70);
};

#endif