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
    double rest{};
public:
    GroundVehicle(std::string type, int speed, int time, double rest);

    virtual float resultRace(float distance) = 0;
};

class Centaur : public GroundVehicle
{
public:
    Centaur(std::string name = "Кентавр", int speed = 15, int time = 8, double rest = 2);

    float resultRace(float distance) override;
};


class Camel : public GroundVehicle
{
protected:
    double restFirst{};
public:

    Camel(std::string name = "Верблюд", int speed = 10, int time = 30, double rest = 8, double restFirst = 5);

    float resultRace(float distance) override;
};

class CamelSpeedster : public Camel
{
private:
    double restSecond{};
public:
    CamelSpeedster(double restSecond = 6.5);

    float resultRace(float distance) override;
};

class AllTerrainVehicleBoots : public GroundVehicle
{
private:
    double restFirst{};
public:
    AllTerrainVehicleBoots(std::string name = "Ботинки-вездеходы", int speed = 6, int time = 60, double rest = 5, double restFirst = 10);

    float resultRace(float distance) override;
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


int printHello();

void printVehicle(float distance, int typeRace);
void createChoiceTypeVehicle(std::string* numberPartic, Result* arr, int index, float distance, std::string* registration);
void createVehicle(Result* result, int index, float distance);

#endif