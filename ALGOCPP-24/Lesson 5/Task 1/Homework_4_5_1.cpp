#include <iostream>
#include <string>
#include "Windows.h"

int pyramid_parent_index(int child_index)
{
    return (child_index - 1) / 2;
}

bool pyramid_if_left(int index)
{
    return (index % 2 == 1);
}

int pyramid_level(int index)
{
    return static_cast<int>(log2(index + 1));
}

void print_pyramid(int* arr, int size)
{
    std::cout << "Пирамида:" << std::endl;
    std::cout << 0 << " root " << arr[0] << std::endl;
    for (int i = 1; i < size; ++i)
    {
        int parent_index = pyramid_parent_index(i);
        int level = pyramid_level(i);
        std::string position_str{};
        if (pyramid_if_left(i))
        {
            position_str = "left";
        } else { position_str = "right"; }
        std::cout << level << " " << position_str << "(" << arr[parent_index] << ") " << arr[i] << std::endl;
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int arr_size{10};
    int* array = new int[arr_size]{16, 11, 9, 10, 5, 6, 8, 1, 2, 4};

    std::cout << "Исходный массив: ";
    for (int i = 0; i < arr_size; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    print_pyramid(array, arr_size);
    delete[] array;

    return EXIT_SUCCESS;
}