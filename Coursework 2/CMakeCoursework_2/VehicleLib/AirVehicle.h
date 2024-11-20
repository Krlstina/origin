#ifndef AIRVEHICLE_H
#define AIRVEHICLE_H

#include <string>
#include "VehicleDynamic.h"

class MagicCarpet : public AirVehicle
{
public:
    MagicCarpet(std::string name = "Ковер-самолет", int speed = 10);

    float resultRace(float distance) override;
};

class Eagle : public AirVehicle
{
public:
    Eagle(std::string name = "Орёл", int speed = 8);

    float resultRace(float distance) override;
};

class Broomstick : public AirVehicle
{
public:
    Broomstick(std::string name = "Метла", int speed = 20);

    float resultRace(float distance) override;
};

#endif