#include <iostream>

enum class Months
{
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

int main()
{
    setlocale(LC_ALL, "rus");

    int enterNumberMonth{1};

    std::cout << "Введите номер месяца: ";
    std::cin >> enterNumberMonth;

    while (!(enterNumberMonth == 0))
    {
        switch (enterNumberMonth)
        {
            case static_cast<int>(Months::January):
                std::cout << "Январь" << std::endl;
                break;
            case static_cast<int>(Months::February):
                std::cout << "Февраль" << std::endl;
                break;
            case static_cast<int>(Months::March):
                std::cout << "Март" << std::endl;
                break;
            case static_cast<int>(Months::April):
                std::cout << "Апрель" << std::endl;
                break;
            case static_cast<int>(Months::May):
                std::cout << "Май" << std::endl;
                break;
            case static_cast<int>(Months::June):
                std::cout << "Июнь" << std::endl;
                break;
            case static_cast<int>(Months::July):
                std::cout << "Июль" << std::endl;
                break;
            case static_cast<int>(Months::August):
                std::cout << "Август" << std::endl;
                break;
            case static_cast<int>(Months::September):
                std::cout << "Сентябрь" << std::endl;
                break;
            case static_cast<int>(Months::October):
                std::cout << "Октябрь" << std::endl;
                break;
            case static_cast<int>(Months::November):
                std::cout << "Ноябрь" << std::endl;
                break;
            case static_cast<int>(Months::December):
                std::cout << "Декабрь" << std::endl;
                break;

            default:
                std::cout << "Неправильный номер!" << std::endl;
                break;
        }

        std::cout << "Введите номер месяца: ";
        std::cin >> enterNumberMonth;
    }

    std::cout << "До новых встреч!" << std::endl;

    return EXIT_SUCCESS;
}