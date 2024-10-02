#include <iostream>

#define SUB(numberFirst, numberSecond) ((numberFirst) - (numberSecond))

int main()
{
    int numberFirst{ 6 };
    int numberSecond{ 5 };
    int numberThird{ 2 };

    std::cout << SUB(numberFirst, numberSecond) << std::endl;
    std::cout << SUB(numberFirst, numberSecond) * numberThird << std::endl;
    std::cout << SUB(numberFirst, numberSecond + numberThird) * numberThird << std::endl;
    
    return EXIT_SUCCESS;
}