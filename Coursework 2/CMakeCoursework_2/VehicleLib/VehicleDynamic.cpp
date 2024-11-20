#include <iostream>
#include <string>
#include <sstream>
#include "math.h"
#include "VehicleDynamic.h"
#include "GroundVehicle.h"
#include "AirVehicle.h"


GroundVehicle::GroundVehicle(std::string type, int speed, int time, float rest)
    : typeVehicle{ type }, speed{ speed }, timeDrivingBeforeRest{ time }, rest{ rest }
{}


AirVehicle::AirVehicle(std::string type, int speed)
    : typeVehicle{ type }, speed{ speed }
{}


int printHello()
{
    int typeDriving{};
    std::cout << "\n1. ����� ��� ��������� ����������" << std::endl;
    std::cout << "2. ����� ��� ���������� ����������" << std::endl;
    std::cout << "3. ����� ��� ��������� � ���������� ����������" << std::endl;
    std::cout << "�������� ��� �����: ";
    std::cin >> typeDriving;
    return typeDriving;
}


void printVehicle(float distance, int typeRace)
{
    if (typeRace == 1)
    {
        std::cout << "\n����� ��� ��������� ����������. ����������: " << distance << std::endl;
    }
    else
    {
        if (typeRace == 2)
        {
            std::cout << "\n����� ��� ���������� ����������. ����������: " << distance << std::endl;
        }
        else
        {
            std::cout << "\n����� ��� ��������� � ���������� ����������. ����������: " << distance << std::endl;
        }
    }
    std::cout << "1. �������-���������" << std::endl;
    std::cout << "2. �����" << std::endl;
    std::cout << "3. �������" << std::endl;
    std::cout << "4. �������" << std::endl;
    std::cout << "5. ���" << std::endl;
    std::cout << "6. �������-���������" << std::endl;
    std::cout << "7. �����-�������" << std::endl;
    std::cout << "0. ��������� �����������" << std::endl;
    std::cout << "�������� ��������� ��� 0 ��� ��������� �������� �����������: ";
}

void createVehicle(Result* result, int index, float distance)
{
    if (index == 0)
    {
        AllTerrainVehicleBoots boots{};
        result[index].name = { "�������-���������" };
        result[index].allTime = { boots.resultRace(distance) };
    }
    if (index == 1)
    {
        Broomstick broomstick{};
        result[index].name = { "�����" };
        result[index].allTime = { broomstick.resultRace(distance) };
    }
    if (index == 2)
    {
        Camel camel{};
        result[index].name = { "�������" };
        result[index].allTime = { camel.resultRace(distance) };
    }
    if (index == 3)
    {
        Centaur centaur{};
        result[index].name = { "�������" };
        result[index].allTime = { centaur.resultRace(distance) };
    }
    if (index == 4)
    {
        Eagle eagle{};
        result[index].name = { "���" };
        result[index].allTime = { eagle.resultRace(distance) };
    }
    if (index == 5)
    {
        CamelSpeedster camelSpeedster{};
        result[index].name = { "�������-���������" };
        result[index].allTime = { camelSpeedster.resultRace(distance) };
    }
    if (index == 6)
    {
        MagicCarpet magicCarpet{};
        result[index].name = { "�����-�������" };
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

        registration->erase(registration->length() - 2, 2);
        std::cout << "\n�� " << arr[index].name << " ��� ����������������!";
        std::cout << std::endl;
        std::cout << *registration;
    }
    else {
        createVehicle(arr, index, distance);
        std::cout << "\n�� " << arr[index].name << " ������� ����������������" << std::endl;
        *numberPartic += std::string{number};
        *registration += arr[index].name;
        std::cout << *registration;
    }
}