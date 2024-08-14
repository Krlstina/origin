#include <iostream>
#include <Windows.h>
#include <string>

struct ResidentialAddress
{
    std::string city;
    std::string street;
    std::string houseNumber; //строковая переменная, там как номера домов бывают и с добавлением букв, например, "6А"
    int apartmentNumber{1};
    int index{1};
};

void structureOutput(ResidentialAddress* address)
{
    std::cout << "Город: " << address->city << std::endl;
    std::cout << "Улица: " << address->street << std::endl;
    std::cout << "Номер дома: " << address->houseNumber << std::endl;
    std::cout << "Номер квартиры: " << address->apartmentNumber << std::endl;
    std::cout << "Индекс: " << address->index << std::endl;
}

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ResidentialAddress address1 = { "Рязань", "Высоковольтная", "9В", 23, 390039 };
    ResidentialAddress address2 = { "Москва", "8 марта", "12", 154, 117623 };

    structureOutput(&address1);
    std::cout << std::endl;
    structureOutput(&address2);

    return EXIT_SUCCESS;
}