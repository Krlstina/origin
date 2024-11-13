#include <iostream>
#include <sstream>
#include <string>
#include "Windows.h"
#include "VehicleDynamic.h"

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int typeDriving{};

    std::cout << "Добро пожаловать в гоночный симулятор!";
    typeDriving = printHello();
    std::cout << std::endl;

    float distance{};
    std::cout << "Укажите длину дистанции (должна быть положительна): ";
    std::cin >> distance;
    std::cout << std::endl;

    int action{};
    std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства" << std::endl;
    std::cout << "1. Зарегистрировать транспорт" << std::endl;
    std::cout << "Выберите действие: ";
    std::cin >> action;

    int choiceVehicle{};
    printVehicle(distance, typeDriving);
    std::cin >> choiceVehicle;
    std::cout << std::endl;

    std::string registration{ "Зарегистрированные транспортные средства:" };
    std::string* get_reg{&registration};

    std::string numberParticipant{ "0" };
    std::string* get_partic{&numberParticipant};

    Result arr[7];
    TypeVehicle choiceVehicleType{};
    choiceVehicleType = static_cast<TypeVehicle>(choiceVehicle);

    do
    {
        while (choiceVehicle != 0)
        {
            choiceVehicleType = static_cast<TypeVehicle>(choiceVehicle);
            //гонка наземных ТС
            if (typeDriving == 1)
            {
                switch (choiceVehicleType)
                {
                case TypeVehicle::tv_AllTerrainVehicleBoots:
                    createChoiceTypeVehicle(get_partic, arr, 0, distance, get_reg);
                    break;
                case TypeVehicle::tv_Camel:
                    createChoiceTypeVehicle(get_partic, arr, 2, distance, get_reg);
                    break;
                case TypeVehicle::tv_Centaur:
                    createChoiceTypeVehicle(get_partic, arr, 3, distance, get_reg);
                    break;
                case TypeVehicle::tv_CamelSpeedster:
                    createChoiceTypeVehicle(get_partic, arr, 5, distance, get_reg);
                    break;
                default:
                    std::cout << "\nПопытка зарегистрировать неправильный тип транспортного средства";
                    break;
                }
            }
            //гонка воздушных ТС
            if (typeDriving == 2)
            {
                switch (choiceVehicleType)
                {
                case TypeVehicle::tv_Broomstick:
                    createChoiceTypeVehicle(get_partic, arr, 1, distance, get_reg);
                    break;
                case TypeVehicle::tv_Eagle:
                    createChoiceTypeVehicle(get_partic, arr, 4, distance, get_reg);
                    break;
                case TypeVehicle::tv_MagicCarpet:
                    createChoiceTypeVehicle(get_partic, arr, 6, distance, get_reg);
                    break;
                default:
                    std::cout << "\nПопытка зарегистрировать неправильный тип транспортного средства";
                    break;
                }
            }
            //смешанная гонка ТС
            if (typeDriving == 3)
            {
                switch (choiceVehicleType)
                {
                case TypeVehicle::tv_AllTerrainVehicleBoots:
                    createChoiceTypeVehicle(get_partic, arr, 0, distance, get_reg);
                    break;
                case TypeVehicle::tv_Broomstick:
                    createChoiceTypeVehicle(get_partic, arr, 1, distance, get_reg);
                    break;
                case TypeVehicle::tv_Camel:
                    createChoiceTypeVehicle(get_partic, arr, 2, distance, get_reg);
                    break;
                case TypeVehicle::tv_Centaur:
                    createChoiceTypeVehicle(get_partic, arr, 3, distance, get_reg);
                    break;
                case TypeVehicle::tv_Eagle:
                    createChoiceTypeVehicle(get_partic, arr, 4, distance, get_reg);
                    break;
                case TypeVehicle::tv_CamelSpeedster:
                    createChoiceTypeVehicle(get_partic, arr, 5, distance, get_reg);
                    break;
                case TypeVehicle::tv_MagicCarpet:
                    createChoiceTypeVehicle(get_partic, arr, 6, distance, get_reg);
                    break;
                }
            }

            printVehicle(distance, typeDriving);
            std::cin >> choiceVehicle;

            if (choiceVehicle == 0 && std::stoi(numberParticipant) < 12) //проверка на регистрацию минимум 2 ТС
            {
                std::cout << "\nОшибка! Для начала гонки должно быть зарегистрировано хотя бы 2 транспортных средства!";
                printVehicle(distance, typeDriving);
                std::cin >> choiceVehicle;
            }
        }
        std::cout << "\n1. Зарегистрировать транспортное средство" << std::endl;
        std::cout << "2. Начать гонку" << std::endl;
        std::cout << "Выберите действие: ";
        std::cin >> action;
        std::cout << std::endl;

        if (action == 2)
        {
            std::cout << "Результаты гонки: \n";

            bool swapped{ false };
            do
            {
                swapped = false;
                for (int indexI = 1; indexI < 7; indexI++)
                {
                    if (arr[indexI - 1].allTime > arr[indexI].allTime)
                    {
                        Result temp = arr[indexI - 1];
                        arr[indexI - 1] = arr[indexI];
                        arr[indexI] = temp;
                        swapped = true;
                    }
                }
            } while (swapped);

            int numberResult{ 1 };
            for (int indexI = 0; indexI < 7; ++indexI)
            {
                if (arr[indexI].allTime != 0)
                {
                    std::cout << numberResult << ". " << arr[indexI].name << ". Время: " << arr[indexI].allTime << std::endl;
                    numberResult += 1;
                }
            }

            std::cout << std::endl;
            std::cout << "1. Провести еще одну гонку" << std::endl;
            std::cout << "2. Выйти" << std::endl;
            std::cout << "Выберите действие: ";
            std::cin >> action;

            if (action == 2)
            {
                break;
            }

            typeDriving = printHello();
            std::cout << std::endl;

            std::cout << "Укажите длину дистанции (должна быть положительна): ";
            std::cin >> distance;
            std::cout << std::endl;

            std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства" << std::endl;
            std::cout << "1. Зарегистрировать транспорт" << std::endl;
            std::cout << "Выберите действие: ";
            std::cin >> action;

            registration = "Зарегистрированные транспортные средства:";
            numberParticipant = "0";
            std::fill(std::begin(arr), std::end(arr), Result());
            printVehicle(distance, typeDriving);
            std::cin >> choiceVehicle;
            std::cout << std::endl;         
        } else {
            std::cout << registration;
            printVehicle(distance, typeDriving);
            std::cin >> choiceVehicle;
            std::cout << std::endl;
        }
    } while (action == 1);

	return EXIT_SUCCESS;
}