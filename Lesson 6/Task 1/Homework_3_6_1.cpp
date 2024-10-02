#include <iostream>
#include <Windows.h>

#define MODE 1

#ifdef MODE == 1
void add(int num1, int num2)
{
    std::cout << "Результат сложения: " << (num1 + num2) << std::endl;
}
#endif

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

#ifndef MODE
    #error Не определено значение!!!
#endif

#if MODE == 0
    std::cout << "Работаю в режиме тренировки" << std::endl;
#elif MODE == 1
    int enterNumberFirst{};
    int enterNumberSecond{};
    std::cout << "Работаю в боевом режиме" << std::endl;
    std::cout << "Введите первое число: ";
    std::cin >> enterNumberFirst;
    std::cout << "Введите второе число: ";
    std::cin >> enterNumberSecond;
    add(enterNumberFirst, enterNumberSecond);
#else
    #error Неизвестный режим. Завершение работы
#endif

    return EXIT_SUCCESS;
}