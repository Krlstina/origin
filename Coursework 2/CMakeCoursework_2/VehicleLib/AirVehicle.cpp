#include <iostream>
#include <string>
#include "AirVehicle.h"

MagicCarpet::MagicCarpet(std::string name, int speed)
    : AirVehicle(name, speed)
{}

Eagle::Eagle(std::string name, int speed)
    : AirVehicle(name, speed)
{}

Broomstick::Broomstick(std::string name, int speed)
    : AirVehicle(name, speed)
{}


float MagicCarpet::resultRace(float distance)
{
    if (distance < 1000.0f)
    {
        return distance / speed;
    }
    else {
        if (distance < 5000.0f)
        {
            return (distance * 0.97f) / speed;
        }
        else {
            if (distance < 10000.0f)
            {
                return (distance * 0.9f) / speed;
            }
            else { return (distance * 0.95f) / speed; }
        }
    }
}

float Eagle::resultRace(float distance) { return (distance * 0.94f) / speed; }

float Broomstick::resultRace(float distance)
{
    float coefficient{ 100.0f };
    float newDistance{ distance };
    while (newDistance > 1000.0f)
    {
        coefficient -= 1.0f;
        newDistance -= 1000.0f;
    }
    return (distance * (coefficient / 100.0f)) / speed;
}