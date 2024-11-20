#include <iostream>
#include <string>
#include "GroundVehicle.h"

Centaur::Centaur(std::string name, int speed, int time, float rest)
    : GroundVehicle(name, speed, time, rest)
{}

Camel::Camel(std::string name, int speed, int time, float rest, float restFirst)
    : GroundVehicle(name, speed, time, rest)
{
    this->restFirst = restFirst;
}

CamelSpeedster::CamelSpeedster(float restSecond)
    : Camel("Верблюд-быстроход", 40, 10)
{
    this->restSecond = restSecond;
}

AllTerrainVehicleBoots::AllTerrainVehicleBoots(std::string name, int speed, int time, float rest, float restFirst)
    : GroundVehicle(name, speed, time, rest)
{
    this->restFirst = restFirst;
}

float Camel::resultRace(float distance)
{
    int numberOfStops{};
    float timeDriving{ distance / speed };
    numberOfStops = static_cast<int>(timeDriving / timeDrivingBeforeRest);
    if (numberOfStops < 1)
    {
        return timeDriving;
    }
    else {
        if (numberOfStops == 1)
        {
            return timeDriving + restFirst;
        }
        if (timeDriving == (int)timeDriving)
        {
            return timeDriving + restFirst + (numberOfStops - 2) * rest;
        }
        return timeDriving + restFirst + (numberOfStops - 1) * rest;
    }
}

float Centaur::resultRace(float distance)
{
    float timeDriving{ 0.0f };
    int numberOfStops{};
    timeDriving = distance / speed;
    numberOfStops = static_cast<int>(timeDriving / timeDrivingBeforeRest);
    return timeDriving + (numberOfStops * rest);
}

float CamelSpeedster::resultRace(float distance)
{
    int numberOfStops{};
    float timeDriving{ distance / speed };
    numberOfStops = static_cast<int>(timeDriving / timeDrivingBeforeRest);
    if (numberOfStops <= 1)
    {
        return timeDriving;
    }
    else
    {
        if (numberOfStops <= 2)
        {
            return timeDriving + restFirst + restSecond;
        }
        else
        {
            return timeDriving + restFirst + restSecond + (numberOfStops - 2) * rest;
        }
    }
}

float AllTerrainVehicleBoots::resultRace(float distance)
{
    int numberOfStops{};
    float timeDriving{ distance / speed };
    numberOfStops = static_cast<int>(timeDriving / timeDrivingBeforeRest);
    if (numberOfStops < 1)
    {
        return timeDriving;
    }
    else {
        if (numberOfStops == 1)
        {
            return timeDriving + restFirst;
        }
        return timeDriving + restFirst + (numberOfStops - 1) * rest;
    }
}