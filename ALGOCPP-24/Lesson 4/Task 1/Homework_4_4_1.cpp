#include <iostream>
#include "Windows.h"

void print_dynamic_array(int* arr, int logical_size, int actual_size)
{
    std::cout << "\nДинамический массив: ";
    for (int a_size = 0; a_size < actual_size; ++a_size)
    {
        if (a_size < logical_size)
        {
            std::cout << arr[a_size] << " ";
        }
        else {
            std::cout << "_ ";
        }
    }
    std::cout << std::endl;
}

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int actual_size{};

    int logical_size{};

    std::cout << "Введите фактический размер массива: ";
    std::cin >> actual_size;
    std::cout << "Введите логический размер массива: ";
    std::cin >> logical_size;

    if (logical_size > actual_size)
    {
        std::cout << "Ошибка! Логический размер массива не может превышать фактического!" << std::endl;
        return EXIT_FAILURE;
    }

    int* arr = new int[actual_size];

    for (int i = 0; i < logical_size; ++i)
    {
        std::cout << "Введите a[" << i << "]: ";
        std::cin >> arr[i];
    }

    print_dynamic_array(arr, logical_size, actual_size);

    return EXIT_SUCCESS;
}

