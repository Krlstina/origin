#include <iostream>
#include <Windows.h>
#include "calculator.h"

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int answer{};
    int num1{};
    int num2{};

    std::cout << "Введите первое число: ";
    std::cin >> num1;
    std::cout << "Введите второе число: ";
    std::cin >> num2;
    std::cout << "Введите команду (1 - сложение, 2 - вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
    std::cin >> answer;

    Calculator calculator{num1, num2};
        
    if (answer == 1) { std::cout << num1 << " + " << num2 << " = " << calculator.add() << std::endl; }
    else {
        if (answer == 2) { std::cout << num1 << " - " << num2 << " = " << calculator.subtract() << std::endl; }
        else {
            if (answer == 3) { std::cout << num1 << " * " << num2 << " = " << calculator.multiply() << std::endl; }
            else {
                if (answer == 4) {
                    if (num2 == 0) { std::cout << "На ноль делить нельзя!" << std::endl;
                    } else { std::cout << num1 << " / " << num2 << " = " << calculator.divide() << std::endl; }
                }
                else {
                    if (num1 == 0 && num2 == 0) { std::cout << num1 << " в степени " << num2 << " = неопределенность" << std::endl;
                    } else {
                        if (num1 == 0 && num2 < 0) { std::cout << "Ноль нельзя возводить в степень!" << std::endl;
                        } else { std::cout << num1 << " в степени " << num2 << " = " << calculator.exponentiation() << std::endl; }
                    }
                }
            }
        }
    }

    return EXIT_SUCCESS;
}
