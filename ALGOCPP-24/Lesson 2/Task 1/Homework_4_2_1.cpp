#include <iostream>
#include "Windows.h"

unsigned long long int f(int number)
{
    if (number == 0) return 0;
    if (number == 1 || number == 2) return 1;

    return f(number - 1) + f(number - 2);
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