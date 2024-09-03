#include <iostream>
#include <Windows.h>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>

int numberGeneration{1};
int livingCells{};
int numberStable{};
int gameOver{}; //0 - играт продолжается, 1 - не осталось ни одной "живой" клетки, 2 - ни одна из клеток не поменяла своего положения

void live(char** array, int numberRows, int numberColumns);
void printGeneration(char** array, int numberRows, int numberColumns);

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int numberRows{};
    int numberColumns{};

    std::ifstream starterField("start.txt");
    starterField >> numberRows;
    starterField >> numberColumns;

    char** currentArray = new char* [numberRows];

    for (int i = 0; i < numberRows; ++i) { currentArray[i] = new char[numberColumns]; }

    //заполнение поля "мертвыми" клетками
    for (int i = 0; i < numberRows; ++i)
    {
        for (int j = 0; j < numberColumns; ++j) { currentArray[i][j] = '-'; }
    }

    int symbolFirst{}, symbolSecond{};

    //заполнение поля "живыми" клетками
    while (!(starterField >> symbolFirst).eof())
    {
        starterField >> symbolSecond;
        currentArray[symbolFirst][symbolSecond] = '*';
        ++livingCells;
    }

    printGeneration(currentArray, numberRows, numberColumns);

    do
    {
        live(currentArray, numberRows, numberColumns);
        printGeneration(currentArray, numberRows, numberColumns);
    } while (gameOver == 0);

    starterField.close();

    //очищение динамической памяти
    for (int i = 0; i < numberRows; ++i) { delete[] currentArray[i]; }
    delete[] currentArray;

    return EXIT_SUCCESS;
}



void live(char** array, int numberRows, int numberColumns)
{
    Sleep(2700);

    ++numberGeneration;
    livingCells = 0;
    numberStable = 0;

    int cellsNearby{};
    char** newArray = new char*[numberRows];

    for (int i = 0; i < numberRows; ++i)
    { newArray[i] = new char[numberColumns]; }

    for (int i = 0; i < numberRows; ++i)
    {
        for (int j = 0; j < numberColumns; ++j) { newArray[i][j] = array[i][j]; }
    }

    for (int i = 0; i < numberRows; ++i)
    {
        for (int j = 0; j < numberColumns; ++j)
        {
            if (array[i][j] == '-')
            {
                if (j - 1 >= 0)
                { if (array[i][j - 1] == '*') { cellsNearby++; } }
                if (j + 1 < numberColumns)
                { if (array[i][j + 1] == '*') { cellsNearby++; } }
                if ((i + 1 < numberRows) && (j - 1 >= 0))
                { if (array[i + 1][j - 1] == '*') { cellsNearby++; } }
                if (i + 1 < numberRows)
                { if (array[i + 1][j] == '*') { cellsNearby++; } }
                if ((i + 1 < numberRows) && (j + 1 < numberColumns))
                { if (array[i + 1][j + 1] == '*') { cellsNearby++; } }
                if ((i - 1 >= 0) && (j - 1 >= 0))
                { if (array[i - 1][j - 1] == '*') { cellsNearby++; } }
                if (i - 1 >= 0)
                { if (array[i - 1][j] == '*') { cellsNearby++; } }
                if ((i - 1 >= 0) && (j + 1 < numberColumns))
                { if (array[i - 1][j + 1] == '*') { cellsNearby++; } }

                if (cellsNearby == 3) { newArray[i][j] = '*'; }
                cellsNearby = 0;
            }
            if (array[i][j] == '*')
            {
                if (j - 1 >= 0)
                { if (array[i][j - 1] == '*') { cellsNearby++; } }
                if (j + 1 < numberColumns)
                { if (array[i][j + 1] == '*') { cellsNearby++; } }
                if ((i + 1 < numberRows) && (j - 1 >= 0))
                { if (array[i + 1][j - 1] == '*') { cellsNearby++; } }
                if (i + 1 < numberRows)
                { if (array[i + 1][j] == '*') { cellsNearby++; } }
                if ((i + 1 < numberRows) && (j + 1 < numberColumns))
                { if (array[i + 1][j + 1] == '*') { cellsNearby++; } }
                if ((i - 1 >= 0) && (j - 1 >= 0))
                { if (array[i - 1][j - 1] == '*') { cellsNearby++; } }
                if (i - 1 >= 0)
                { if (array[i - 1][j] == '*') { cellsNearby++; } }
                if ((i - 1 >= 0) && (j + 1 < numberColumns))
                { if (array[i - 1][j + 1] == '*') { cellsNearby++; } }

                if ((cellsNearby > 3) || (cellsNearby < 2)) { newArray[i][j] = '-'; }
                cellsNearby = 0;
            }
        }
    }

    for (int i = 0; i < numberRows; ++i)
    {
        for (int j = 0; j < numberColumns; ++j)
        {
            if (array[i][j] == newArray[i][j]) { ++numberStable; }
        }
    }

    if (numberStable == numberRows * numberColumns) { gameOver = 2; }

    //подсчет "живых" клеток
    for (int i = 0; i < numberRows; ++i)
    {
        for (int j = 0; j < numberColumns; ++j)
        {
            if (newArray[i][j] == '*') { ++livingCells; }
        }
    }

    if (livingCells == 0) { gameOver = 1; }

    for (int i = 0; i < numberRows; ++i)
    {
        for (int j = 0; j < numberColumns; ++j) { array[i][j] = newArray[i][j]; }
    }

    //очищение динамической памяти
    for (int i = 0; i < numberRows; ++i) { delete[] newArray[i]; }
    delete[] newArray;
}

void printGeneration(char** array, int numberRows, int numberColumns)
{
    system("cls");
    for (int i = 0; i < numberRows; i++)
    {
        for (int j = 0; j < numberColumns; j++) { std::cout << " " << array[i][j]; }
        std::cout << std::endl;
    }

    switch (gameOver)
    {
    case 0:
        std::cout << "Номер поколения: " << numberGeneration << ". Количество живых клеток: " << livingCells << "\n" << std::endl;
        break;
    case 1:
        std::cout << "Номер поколения: " << numberGeneration << ". Количество живых клеток: " << livingCells << std::endl;
        std::cout << "Все клетки мертвы. Игра окончена" << "\n";
        break;
    case 2:
        std::cout << "Номер поколения: " << numberGeneration << ". Количество живых клеток: " << livingCells << std::endl;
        std::cout << "Вселенная стабильна. Игра окончена" << "\n";
        break;
    }
}