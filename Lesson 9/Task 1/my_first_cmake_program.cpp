#include <iostream>
#include "Windows.h"
#include <string>

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string enterName{};

	std::cout << "������� ���: ";
	std::cin >> enterName;
	std::cout << "������������, " << enterName << "!" << std::endl;

	return EXIT_SUCCESS;
}