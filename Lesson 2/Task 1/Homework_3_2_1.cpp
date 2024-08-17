#include <iostream>
#include <Windows.h>

class Calculator
{
public:
    double num1{};
    double num2{};

    double add() { return (num1 + num2); }
    double multiply() { return (num1 * num2); }
    double subtract_1_2() { return (num1 - num2); }
    double subtract_2_1() { return (num2 - num1); }
    double divide_1_2() { return (num1 / num2); }
    double divide_2_1() { return (num2 / num1); }
    bool set_num1(double num1)
    {
        if (!(num1 == 0))
        {
            this->num1 = num1;
            return true;
        } else { return false; }
    }
    bool set_num2(double num2)
    {
        if (!(num2 == 0))
        {
            this->num2 = num2;
            return true;
        } else { return false; }
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    

    while (true)
    {
        Calculator operations{};

        std::cout << "Введите num1: ";
        std::cin >> operations.num1;
        while ((operations.set_num1(operations.num1)) == false)
        {
            std::cout << "Неверный ввод!\n" << "Введите num1: ";
            std::cin >> operations.num1;
        }

        std::cout << "Введите num2: ";
        std::cin >> operations.num2;
        while ((operations.set_num2(operations.num2)) == false)
        {
            std::cout << "Неверный ввод!\n" << "Введите num2: ";
            std::cin >> operations.num2;
        }

        std::cout << "num1 + num2 = " << operations.add() << std::endl;
        std::cout << "num1 * num2 = " << operations.multiply() << std::endl;
        std::cout << "num1 - num2 = " << operations.subtract_1_2() << std::endl;
        std::cout << "num2 - num1 = " << operations.subtract_2_1() << std::endl;
        std::cout << "num1 / num2 = " << operations.divide_1_2() << std::endl;
        std::cout << "num2 / num1 = " << operations.divide_2_1() << std::endl;
    }

    return EXIT_SUCCESS;
}