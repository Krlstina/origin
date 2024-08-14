
#include <iostream>
#include <Windows.h>
#include <string>

struct BankAccount
{
    int numberAccount{1};
    std::string name{};
    float balance{0.5f};
};

void changeBalance(BankAccount* account)
{
    std::cout << "Введите новый баланс счета: ";
    std::cin >> account->balance;
}

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    BankAccount person;

    std::cout << "Введите номер счета: ";
    std::cin >> person.numberAccount;
    std::cout << "Введите имя владельца счета: ";
    std::cin >> person.name;
    std::cout << "Введите текущий баланс счета: ";
    std::cin >> person.balance;

    changeBalance(&person);

    std::cout << "Ваш счет: " << person.numberAccount << ", " << person.name << ", " << person.balance;

    return EXIT_SUCCESS;
}