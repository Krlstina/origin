#ifndef RHOMB_H
#define RHOMB_H

#include "parallelogram.h"

class Rhomb :public Parallelogram
{
public:
    Rhomb(int sideA = 40, int sideB = 40, int sideC = 40, int sideD = 40);
};

#endif