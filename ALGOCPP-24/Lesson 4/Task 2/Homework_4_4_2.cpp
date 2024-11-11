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

int* append_to_dynamic_array(int* arr, int* get_actual,int* get_logical,int enterNumber)
{
    if (*get_logical < *get_actual)
    {
        arr[*get_logical] = enterNumber;
        *get_logical += 1;
        return arr;
    } else {
        int* newArray = new int[2*(*get_actual)];
        for (int i = 0; i < *get_actual; ++i)
        {
            newArray[i] = arr[i];
        }
        newArray[*get_actual] = enterNumber;
        *get_actual *= 2;
        *get_logical += 1;
        delete [] arr;
        return newArray;
    }
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

    int enterNumber{};
    int* get_actual{ &actual_size };
    int* get_logical{ &logical_size };

    std::cout << "Введите элемент для добавления в массив: ";
    std::cin >> enterNumber;

    while (enterNumber != 0)
    {
        arr = append_to_dynamic_array(arr, get_actual, get_logical, enterNumber);
        print_dynamic_array(arr, logical_size, actual_size);

        std::cout << "Введите элемент для добавления в массив: ";
        std::cin >> enterNumber;
    }

    std::cout << "\nСпасибо!";
    print_dynamic_array(arr, logical_size, actual_size);

    return EXIT_SUCCESS;
}

