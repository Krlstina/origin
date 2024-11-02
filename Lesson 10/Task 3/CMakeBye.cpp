#include <iostream>
#include <string>
#include "Windows.h"
#include "ByeDynamic.h"

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string enterName{};

	std::cout << "Введите имя: ";
	std::cin >> enterName;
	Leaver bye{};
	bye.leave(enterName);


	return EXIT_SUCCESS;
}