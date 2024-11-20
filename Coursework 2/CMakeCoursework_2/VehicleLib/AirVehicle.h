#ifndef AIRVEHICLE_H
#define AIRVEHICLE_H

#include <string>
#include "VehicleDynamic.h"

class MagicCarpet : public AirVehicle
{
public:
    MagicCarpet(std::string name = "�����-�������", int speed = 10);

    float resultRace(float distance) override;
};

class Eagle : public AirVehicle
{
public:
    Eagle(std::string name = "���", int speed = 8);

    float resultRace(float distance) override;
};

class Broomstick : public AirVehicle
{
public:
    Broomstick(std::string name = "�����", int speed = 20);

    float resultRace(float distance) override;
};

#endif