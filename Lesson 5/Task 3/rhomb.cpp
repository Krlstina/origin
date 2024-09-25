#include "rhomb.h"

Rhomb::Rhomb(int sideAandBandC, int cornerAandC, int cornerBandD)
    : Parallelogram(sideAandBandC, sideAandBandC, cornerAandC, cornerBandD)
{
    name = "Ромб";
}