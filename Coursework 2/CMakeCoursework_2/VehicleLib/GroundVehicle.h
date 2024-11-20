#ifndef GROUNDVEHICLE_H
#define GROUNDVEHICLE_H

#include <string>
#include "VehicleDynamic.h"

class Centaur : public GroundVehicle
{
public:
    Centaur(std::string name = "Кентавр", int speed = 15, int time = 8, float rest = 2.0f);

    float resultRace(float distance) override;
};


class Camel : public GroundVehicle
{
protected:
    float restFirst{};
public:

    Camel(std::string name = "Верблюд", int speed = 10, int time = 30, float rest = 8.0f, float restFirst = 5.0f);

    float resultRace(float distance) override;
};

class CamelSpeedster : public Camel
{
private:
    float restSecond{};
public:
    CamelSpeedster(float restSecond = 6.5f);

    float resultRace(float distance) override;
};

class AllTerrainVehicleBoots : public GroundVehicle
{
private:
    float restFirst{};
public:
    AllTerrainVehicleBoots(std::string name = "Ботинки-вездеходы", int speed = 6, int time = 60, float rest = 5.0f, float restFirst = 10.0f);

    float resultRace(float distance) override;
};

#endif