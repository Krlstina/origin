#include <iostream>
#include <Windows.h>
#include <string>
#include <exception>

int function(std::string str, int forbidden_length)
{
    if (str.length() == forbidden_length) { throw 1; }
    return str.length();
}

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int stopLength{};
    std::string enterWord{};

    std::cout << "Введите запретную длину: ";
    std::cin >> stopLength;

    while (true)
    {
        std::cout << "Введите слово: ";
        std::cin >> enterWord;
        try
        {
            std::cout << "Длина слова \"" << enterWord << "\" равна " << function(enterWord, stopLength) << std::endl;
        }
        catch (int bad_length)
        {
            std::cout << "Вы ввели слово запретной длины! До свидания!)" << std::endl;
            exit(EXIT_FAILURE);
        }
        catch (...)
        {
            std::cout << "Ошибка!" << std::endl;
        }
    }

    return EXIT_SUCCESS;
}