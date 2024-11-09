#include <iostream>
#include "Windows.h"

void printArray(int* arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
}

void count_sort(int* arr, int size)
{
    int i = 0;
    int j = size - 1;
    int mid = arr[size / 2];

    do {
        while (arr[i] < mid) {
            i++;
        }
        while (arr[j] > mid) {
            j--;
        }

        if (i <= j) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);

    if (j > 0) {
        count_sort(arr, j + 1);
    }
    if (i < size) {
        count_sort(&arr[i], size - i);
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int arrayFirst[] = { 19, 14, 22, 22, 17, 22, 13, 21, 20, 24, 18, 10, 17, 16, 17, 20, 22, 11, 20, 16, 14, 13, 10, 22, 18, 14, 16, 24, 19, 17 };
    int arraySecond[] = { 16, 17, 14, 20, 22, 20, 17, 22, 16, 19, 23, 24, 20, 22, 21, 18, 14, 16, 17, 21, 10, 11, 19, 23, 11, 11, 17, 17, 11, 21, 17, 11, 17, 16, 12, 11, 16, 22, 23, 16 };
    int arrayThird[] = { 21, 15, 19, 18, 23, 12, 18, 18, 19, 23, 12, 20, 15, 22, 21, 18, 19, 20, 12, 16, 20, 14, 17, 13, 10, 23, 19, 14, 10, 22, 19, 12, 24, 23, 22, 15, 13, 22, 18, 18, 11, 23, 24, 17, 10 };

    int size{ sizeof(arrayFirst) / sizeof(arrayFirst[0]) };
    std::cout << "Исходный массив: ";
    printArray(arrayFirst, size);
    count_sort(arrayFirst, size);
    std::cout << "\nОтсортированный массив: ";
    printArray(arrayFirst, size);

    std::cout << "\n\nИсходный массив: ";
    printArray(arraySecond, size);
    size = sizeof(arraySecond) / sizeof(arraySecond[0]);
    count_sort(arraySecond, size);
    std::cout << "\nОтсортированный массив: ";
    printArray(arraySecond, size);


    std::cout << "\n\nИсходный массив: ";
    printArray(arrayThird, size);
    size = sizeof(arrayThird) / sizeof(arrayThird[0]);
    count_sort(arrayThird, size);
    std::cout << "\nОтсортированный массив: ";
    printArray(arrayThird, size);
    std::cout << std::endl;



    return EXIT_SUCCESS;
}