#include <iostream>
#include <Windows.h>
#include <string>
#include "counter.h"

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string answer{};

    std::cout << "Вы хотите указать начальное значение счетчика? Введите \"да\" или \"нет\": ";
    std::cin >> answer;

    if (answer == "да")
    {
        int initialValue{};
        std::cout << "Введите начальное значение счетчика: ";
        std::cin >> initialValue;

        Counter instance{ initialValue };

        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> answer;

        while (!(answer == "x") || !(answer == "х"))
        {            
            if (answer == "+") { instance.increaseValue(); }
            else {
                if (answer == "-") { instance.decreaseValue(); }
                else { instance.printValue(); }
            }

            std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
            std::cin >> answer;

            if (answer == "x") { std::cout << "До новых встреч!" << std::endl; return EXIT_SUCCESS; }
            else {
                if (answer == "х") { std::cout << "До новых встреч!" << std::endl; return EXIT_SUCCESS; }
            }
        }
    }
    else {
        Counter instance{};

        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> answer;

        while (!(answer == "x") || !(answer == "х"))
        {
            if (answer == "+") { instance.increaseValue(); }
            else {
                if (answer == "-") { instance.decreaseValue(); }
                else { instance.printValue(); }
            }

            std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
            std::cin >> answer;

            if (answer == "x")
            { std::cout << "До новых встреч!" << std::endl; return EXIT_SUCCESS; }
            else {
                if (answer == "х") { std::cout << "До новых встреч!" << std::endl; return EXIT_SUCCESS; }
             }
        }
    }

    return EXIT_SUCCESS;
}