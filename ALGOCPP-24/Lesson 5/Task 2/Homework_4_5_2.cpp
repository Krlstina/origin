#include <iostream>
#include <string>
#include "Windows.h"

struct CurrentPosition
{
    int level{0};
    int parent_index{};
    std::string position_str{"root"};
    int index{0};
    //int valueParent{};
    bool pyramid_if_left{};
};

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
        }
        else { position_str = "right"; }
        std::cout << level << " " << position_str << "(" << arr[parent_index] << ") " << arr[i] << std::endl;
    }
}

void found_child(int* arr, int size, CurrentPosition* position)
{
    int leftChildIndex{ 2 * position->index + 1 };
    int rightChildIndex{ 2 * position->index + 2 };

    if (position->pyramid_if_left == true)
    {
        if (size > leftChildIndex)
        {
            position->parent_index = position->index;
            position->level = pyramid_level(leftChildIndex);
            position->position_str = "left";
            position->index = leftChildIndex;
            std::cout << "Ок\n";
            std::cout << "Вы находитесь здесь: " << position->level << " " << position->position_str << "(" << arr[position->parent_index] << ") " << arr[position->index] << std::endl;
        } else { 
            std::cout << "Ошибка! Отсутствует левый потомок!" << std::endl;
            std::cout << "Вы находитесь здесь: " << position->level << " " << position->position_str << "(" << arr[position->parent_index] << ") " << arr[position->index] << std::endl;
        }
    }
    else {
        if (size > rightChildIndex)
        {
            position->parent_index = position->index;
            position->level = pyramid_level(rightChildIndex);
            position->position_str = "right";
            position->index = rightChildIndex;
            std::cout << "Ок\n";
            std::cout << "Вы находитесь здесь: " << position->level << " " << position->position_str << "(" << arr[position->parent_index] << ") " << arr[position->index] << std::endl;
        }
        else {
            std::cout << "Ошибка! Отсутствует правый потомок!" << std::endl;
            std::cout << "Вы находитесь здесь : " << position->level << " " << position->position_str << "(" << arr[position->parent_index] << ") " << arr[position->index] << std::endl;
        }
    }
}

void found_parent(int* arr, CurrentPosition* position)
{
    position->index = pyramid_parent_index(position->index);
    position->level = pyramid_level(position->index);
    if (position->level == 0)
    {
        position->position_str = "root";
        std::cout << "Ок\n" << "Вы находитесь здесь : ";
        std::cout << 0 << " root " << arr[0] << std::endl;
        return;
    }
    position->parent_index = pyramid_parent_index(position->index);
    if (pyramid_if_left(position->index))
    {
        position->position_str = "left";
    }
    else { position->position_str = "right"; }

    std::cout << "Ок\n";
    std::cout << "Вы находитесь здесь : " << position->level << " " << position->position_str << "(" << arr[position->parent_index] << ") " << arr[position->index] << std::endl;
}

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int arr_size{ 6 };
    int* array = new int[arr_size] {1, 3, 6, 5, 9, 8};
    //int* array = new int[arr_size] {16, 11, 9, 10, 5, 6, 8, 1, 2, 4};
    std::string enterAnswer{};
    

    std::cout << "Исходный массив: ";
    for (int i = 0; i < arr_size; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    print_pyramid(array, arr_size);

    CurrentPosition position{};
    CurrentPosition* curr_position{ &position };
    
    std::cout << "Вы находитесь здесь : ";
    std::cout << position.level << " " << position.position_str << " " << array[position.index] << std::endl;
    std::cout << "Введите команду (up, left, right или exit): ";
    std::cin >> enterAnswer;

    while (enterAnswer != "exit")
    {
        if (enterAnswer == "up")
        {
            if (position.level == 0)
            {
                std::cout << "Ошибка! Отстствует родитель!" << std::endl;
                std::cout << "Вы находитесь здесь : ";
                std::cout << position.level << " " << position.position_str << " " << array[position.index] << std::endl;
            }
            else {
                found_parent(array, curr_position);
            }
        }
        else {
            if (enterAnswer == "left")
            {
                position.pyramid_if_left = true;
                found_child(array, arr_size, curr_position);
            }
            else {
                position.pyramid_if_left = false;
                found_child(array, arr_size, curr_position);
            }
        }

        std::cout << "Введите команду (up, left, right или exit): ";
        std::cin >> enterAnswer;
    }

    delete[] array;

    return EXIT_SUCCESS;
}