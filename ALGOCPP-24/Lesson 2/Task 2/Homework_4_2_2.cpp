#include <iostream>
#include "Windows.h"

int memory[10000];

unsigned long long int f(int number)
{
    if (memory[number] == 0) {
        if (number == 1 || number == 2) {
            memory[number] = 1;
        }
        else {
            memory[number] = f(number - 1) + f(number - 2);
        }
    }

    return memory[number];
}

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int enterNumber{};
    std::cout << "Введите порядковый номер числа Фибоначчи: ";
    std::cin >> enterNumber;
    std::cout << enterNumber << "-ое число Фибоначчи: " << f(enterNumber) << std::endl;

    return EXIT_SUCCESS;
}