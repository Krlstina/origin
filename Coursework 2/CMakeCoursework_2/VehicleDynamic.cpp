#include <iostream>
#include <string>
#include <sstream>
#include "math.h"
#include "VehicleDynamic.h"



GroundVehicle::GroundVehicle(std::string type, int speed, int time, double rest)
    : typeVehicle{ type }, speed{ speed }, timeDrivingBeforeRest{ time }, rest{ rest }
{}

Centaur::Centaur(std::string name, int speed, int time, double rest)
    : GroundVehicle(name, speed, time, rest)
{}

Camel::Camel(std::string name, int speed, int time, double rest, double restFirst)
    : GroundVehicle(name, speed, time, rest)
{
    this->restFirst = restFirst;
}

CamelSpeedster::CamelSpeedster(double restSecond)
    : Camel("Верблюд-быстроход", 40, 10)
{
    this->restSecond = restSecond;
}

AllTerrainVehicleBoots::AllTerrainVehicleBoots(std::string name, int speed, int time, double rest, double restFirst)
    : GroundVehicle(name, speed, time, rest)
{
    this->restFirst = restFirst;
}



AirVehicle::AirVehicle(std::string type, int speed)
    : typeVehicle{ type }, speed{ speed }
{}

MagicCarpet::MagicCarpet(std::string name, int speed)
    : AirVehicle(name, speed)
{}

Eagle::Eagle(std::string name, int speed)
    : AirVehicle(name, speed)
{}

Broomstick::Broomstick(std::string name, int speed)
    : AirVehicle(name, speed)
{}




float Camel::resultRace(float distance)
{
    int numberOfStops{};
    float timeDriving{ distance / speed };
    numberOfStops = floor(timeDriving / timeDrivingBeforeRest);
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
    numberOfStops = floor(timeDriving / timeDrivingBeforeRest);
    return timeDriving + (numberOfStops * rest);
}

float CamelSpeedster::resultRace(float distance)
{
    int numberOfStops{};
    float timeDriving{ distance / speed };
    numberOfStops = floor(timeDriving / timeDrivingBeforeRest);
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
    numberOfStops = floor(timeDriving / timeDrivingBeforeRest);
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
    float coefficient{100.0f};
    float newDistance{ distance };
    while (newDistance > 1000.0f)
    {
        coefficient -= 1.0f;
        newDistance -= 1000.0f;
    }    
    return (distance * (coefficient / 100.0f)) / speed;
}

int printHello()
{
    int typeDriving{};
    std::cout << "\n1. Гонка для наземного транспорта" << std::endl;
    std::cout << "2. Гонка для воздушного транспорта" << std::endl;
    std::cout << "3. Гонка для наземного и воздушного транспорта" << std::endl;
    std::cout << "Выберите тип гонки: ";
    std::cin >> typeDriving;
    return typeDriving;
}


void printVehicle(float distance, int typeRace)
{
    if (typeRace == 1)
    {
        std::cout << "\nГонка для наземного транспорта. Расстояние: " << distance << std::endl;
    }
    else
    {
        if (typeRace == 2)
        {
            std::cout << "\nГонка для воздушного транспорта. Расстояние: " << distance << std::endl;
        }
        else
        {
            std::cout << "\nГонка для наземного и воздушного транспорта. Расстояние: " << distance << std::endl;
        }
    }
    std::cout << "1. Ботинки-вездеходы" << std::endl;
    std::cout << "2. Метла" << std::endl;
    std::cout << "3. Верблюд" << std::endl;
    std::cout << "4. Кентавр" << std::endl;
    std::cout << "5. Орёл" << std::endl;
    std::cout << "6. Верблюд-быстроход" << std::endl;
    std::cout << "7. Ковер-самолет" << std::endl;
    std::cout << "0. Закончить регистрацию" << std::endl;
    std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: ";
}

void createVehicle(Result* result, int index, float distance)
{
    if (index == 0)
    {
        AllTerrainVehicleBoots boots{};
        result[index].name = { "Ботинки-вездеходы" };
        result[index].allTime = { boots.resultRace(distance) };
    }
    if (index == 1)
    {
        Broomstick broomstick{};
        result[index].name = { "Метла" };
        result[index].allTime = { broomstick.resultRace(distance) };
    }
    if (index == 2)
    {
        Camel camel{};
        result[index].name = { "Верблюд" };
        result[index].allTime = { camel.resultRace(distance) };
    }
    if (index == 3)
    {
        Centaur centaur{};
        result[index].name = { "Кентавр" };
        result[index].allTime = { centaur.resultRace(distance) };
    }
    if (index == 4)
    {
        Eagle eagle{};
        result[index].name = { "Орёл" };
        result[index].allTime = { eagle.resultRace(distance) };
    }
    if (index == 5)
    {
        CamelSpeedster camelSpeedster{};
        result[index].name = { "Верблюд-быстроход" };
        result[index].allTime = { camelSpeedster.resultRace(distance) };
    }
    if (index == 6)
    {
        MagicCarpet magicCarpet{};
        result[index].name = { "Ковер-самолет" };
        result[index].allTime = { magicCarpet.resultRace(distance) };
    }
}

void createChoiceTypeVehicle(std::string* numberPartic, Result* arr, int index, float distance, std::string* registration)
{
    std::stringstream stringNumber{};
    std::string number{};

    stringNumber << index + 1;
    stringNumber >> number;

    if (arr[index].allTime != 0)
    {
        std::cout << "\nТС " << arr[index].name << " уже зарегистрировано!";
        std::cout << std::endl;
        std::cout << *registration;
    }
    else {
        createVehicle(arr, index, distance);
        std::cout << "\nТС " << arr[index].name << " успешно зарегестрировано" << std::endl;
        *numberPartic += std::string{number};
        *registration += " " + arr[index].name;
        std::cout << *registration;
    }
}