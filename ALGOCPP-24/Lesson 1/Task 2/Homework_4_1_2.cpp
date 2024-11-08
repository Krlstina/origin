#include <iostream>
#include <array>
#include "Windows.h"

int numberOfNumbersGreaterReferencePoint(int* arr, int referencePoint, int sizeArray)
{
    int left{};
    int right{ sizeArray - 1 };
    int middle{};
    int numberGreaterReferencePoint{};

    while (left < right)
    {
        middle = (left + right) / 2;
        if (arr[middle] > referencePoint)
        {
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }
    }

    if (arr[left] > referencePoint)
    {
        numberGreaterReferencePoint = sizeArray - left;
        return numberGreaterReferencePoint;
    }
    else {
        numberGreaterReferencePoint = sizeArray - 1 - left;
        return numberGreaterReferencePoint;
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int sizeArray{ 9 };
    int arr[sizeArray]{14, 16, 19, 32, 32, 32, 56, 69, 72};
    int referencePoint{};

    std::cout << "Введите точку отсчёта: ";
    std::cin >> referencePoint;
    std::cout << "Количество элементов в массиве больших, чем " << referencePoint << ": " << numberOfNumbersGreaterReferencePoint(arr, referencePoint, sizeArray);

    return EXIT_SUCCESS;
}