#ifndef VEHICLEDYNAMIC_H
#define VEHICLEDYNAMIC_H

struct Result
{
    std::string name{"0"};
    float allTime{0.0f};
};

enum class TypeVehicle
{
    tv_AllTerrainVehicleBoots = 1,
    tv_Broomstick = 2,
    tv_Camel = 3,
    tv_Centaur = 4,
    tv_Eagle = 5,
    tv_CamelSpeedster = 6,
    tv_MagicCarpet = 7
};

class GroundVehicle
{
protected:
    std::string typeVehicle{};
    int speed{};
    int timeDrivingBeforeRest{};
    float rest{};
public:
    GroundVehicle(std::string type, int speed, int time, float rest);

    virtual float resultRace(float distance) = 0;
};


class AirVehicle
{
protected:
    std::string typeVehicle{};
    int speed{};
public:
    AirVehicle(std::string type, int speed);

    virtual float resultRace(float distance) = 0;
};


int printHello();

void printVehicle(float distance, int typeRace);
void createChoiceTypeVehicle(std::string* numberPartic, Result* arr, int index, float distance, std::string* registration);
void createVehicle(Result* result, int index, float distance);

#endif