#ifndef RHOMB_H
#define RHOMB_H

#include "parallelogram.h"

class Rhomb :public Parallelogram
{
public:
    Rhomb(int sideAandBandC = 60, int cornerAandC = 70, int cornerBandD = 55)
        : Parallelogram(sideAandBandC, sideAandBandC, cornerAandC, cornerBandD)
    {
        name = "Ромб";
    }
};

#endif