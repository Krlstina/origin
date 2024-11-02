#include <iostream>
#include <string>
#include "Windows.h"
#include "HelloStatic.h"

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string enterName{};

	std::cout << "¬ведите им€: ";
	std::cin >> enterName;
	HelloStaticLib::Greeter hello{};
	hello.greet(enterName);


	return EXIT_SUCCESS;
}