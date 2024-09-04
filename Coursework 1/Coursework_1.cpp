#include <iostream>
#include <Windows.h>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>

int numberGeneration{1};
int livingCells{};
int numberStable{};
int gameOver{}; //0 - игра продолжается, 1 - не осталось ни одной "живой" клетки, 2 - ни одна из клеток не поменяла своего положения

int count(char** array, int numberRows, int numberColumns, int i, int j);
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
    for (int i = 0; i < numberRows; ++i)
    {
        for (int j = 0; j < numberColumns; ++j)
        {
            if (currentArray[i][j] == '-') { ++numberStable; }
        }
    }
    if (numberStable == numberRows * numberColumns) { gameOver = 1; printGeneration(currentArray, numberRows, numberColumns); }

    while (gameOver == 0)
    {
        live(currentArray, numberRows, numberColumns);
        printGeneration(currentArray, numberRows, numberColumns);
    }

    starterField.close();

    //очищение динамической памяти
    for (int i = 0; i < numberRows; ++i) { delete[] currentArray[i]; }
    delete[] currentArray;

    return EXIT_SUCCESS;
}

//функция безопастного подсчёта "живых" клеток
int count(char** array, int i, int j, int numberRows, int numberColumns)
{
    if ((i < 0) || (j < 0) || (i >= numberRows) || (j >= numberColumns))
    { return 0; }
    else {
        if (array[i][j] == '*') { return 1; }
        else { return 0; }
    }
}

void live(char** array, int numberRows, int numberColumns)
{
    Sleep(1000);

    ++numberGeneration;
    livingCells = 0;
    numberStable = 0;

    int aliveCellsNearby{};
    char** newArray = new char*[numberRows];
    int neighbors{};

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
                aliveCellsNearby = 0;
                //безопасный подсчет "живых" клеток в верхнем ряду
                aliveCellsNearby += count(array, i - 1, j - 1, numberRows, numberColumns);
                aliveCellsNearby += count(array, i - 1, j,     numberRows, numberColumns);
                aliveCellsNearby += count(array, i - 1, j + 1, numberRows, numberColumns);
                //безопасный подсчет "живых" клеток в среднем ряду (без центра)
                aliveCellsNearby += count(array, i    , j - 1, numberRows, numberColumns);
                aliveCellsNearby += count(array, i    , j + 1, numberRows, numberColumns);
                //безопасный подсчет "живых" клеток в нижнем ряду
                aliveCellsNearby += count(array, i + 1, j - 1, numberRows, numberColumns);
                aliveCellsNearby += count(array, i + 1, j,     numberRows, numberColumns);
                aliveCellsNearby += count(array, i + 1, j + 1, numberRows, numberColumns);

                if (aliveCellsNearby == 3) { newArray[i][j] = '*'; }

                if ((aliveCellsNearby > 3) || (aliveCellsNearby < 2)) { newArray[i][j] = '-'; }
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