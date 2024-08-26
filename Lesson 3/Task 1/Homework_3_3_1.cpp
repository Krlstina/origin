#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include <vector>

class BlockAdress
{
private:
    std::string city{};
    std::string street{};
    std::string houseNumber{};
    std::string apartmentNumber{};

public:
    BlockAdress() {}

   void getBlock(int numberRow)
    {
        std::string readLine{};
        int readNumberBlocks{};
        int currentLine{ 2 };
        std::ifstream inFile("./in.txt");
        inFile >> readNumberBlocks;
        
        while (currentLine < numberRow)
        {
            inFile >> readLine;
            ++currentLine;
        }
        inFile >> readLine;
        this->city = readLine;
        inFile >> readLine;
        this->street = readLine;
        inFile >> readLine;
        this->houseNumber = readLine;
        inFile >> readLine;
        this->apartmentNumber = readLine;

        inFile.close();
    }

    void printAll()
    {
        std::ofstream outFile("./out.txt", std::ios::app);
        outFile << this->city + ", " + this->street + ", " + this->houseNumber + ", " + this->apartmentNumber << std::endl;
        outFile.close();
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector<BlockAdress*> blocks{};
        
    int numberBlocks;

    std::ifstream inFile("./in.txt");
    inFile >> numberBlocks;
    inFile.close();

    std::ofstream outFile("./out.txt", std::ios::app);
    outFile << numberBlocks << std::endl;
    outFile.close();

    int counter{ 0 };
    int numberRow{ ((numberBlocks * 4) - 2) };

    while (counter < numberBlocks )
    {
        blocks.push_back(new BlockAdress{});
        blocks[counter]->getBlock(numberRow);
        blocks[counter]->printAll();
        numberRow -= 4;
        ++counter;
    }

    while (counter > 0) { delete blocks[counter-1];  --counter; }

    return EXIT_SUCCESS;
}