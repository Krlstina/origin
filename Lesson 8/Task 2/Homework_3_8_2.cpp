#include <iostream>
#include "Windows.h"
#include "fraction.h"

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Fraction f1{};
	Fraction f2{};
	Fraction f3{};
	int enterNumber{};

	std::cout << "Введите числитель дроби 1: ";
	std::cin >> enterNumber;
	f1.setNumerator(enterNumber);
	std::cout << "Введите знаменатель дроби 1: ";
	std::cin >> enterNumber;
	f1.setDenominator(enterNumber);
	std::cout << "Введите числитель дроби 2: ";
	std::cin >> enterNumber;
	f2.setNumerator(enterNumber);
	std::cout << "Введите знаменатель дроби 2: ";
	std::cin >> enterNumber;
	f2.setDenominator(enterNumber);
	
	f3 = f1 + f2;
	std::cout << f1.getNumerator() << "/" << f1.getDenominator() << " + " << f2.getNumerator() << "/" << f2.getDenominator() << " = ";
	f3.printFraction();
	f3 = f1 - f2;
	std::cout << f1.getNumerator() << "/" << f1.getDenominator() << " - " << f2.getNumerator() << "/" << f2.getDenominator() << " = ";
	f3.printFraction();
	f3 = f1 * f2;
	std::cout << f1.getNumerator() << "/" << f1.getDenominator() << " * " << f2.getNumerator() << "/" << f2.getDenominator() << " = ";
	f3.printFraction();
	f3 = f1 / f2;
	std::cout << f1.getNumerator() << "/" << f1.getDenominator() << " / " << f2.getNumerator() << "/" << f2.getDenominator() << " = ";
	f3.printFraction();
	
	std::cout << "++" << f1.getNumerator() << "/" << f1.getDenominator() << " * " << f2.getNumerator() << "/" << f2.getDenominator() << " = ";
	f3 = ++f1 * f2;
	f3.printFraction();
	std::cout << "" << "Значение дроби 1: ";
	f1.printFraction();
	std::cout << f1.getNumerator() << "/" << f1.getDenominator() << "-- * " << f2.getNumerator() << "/" << f2.getDenominator() << " = ";
	f3 = f1-- * f2;
	f3.printFraction();
	std::cout << "" << "Значение дроби 1: ";
	f1.printFraction();

	std::cout << f2.getNumerator() << "/" << f2.getDenominator() << "++ - " << f1.getNumerator() << "/" << f1.getDenominator() << " = ";
	f3 = f2++ - f1;
	f3.printFraction();
	std::cout << "" << "Значение дроби 2: ";
	f2.printFraction();
	std::cout << f1.getNumerator() << "/" << f1.getDenominator() << " / --" << f2.getNumerator() << "/" << f2.getDenominator() << " = ";
	f3 = f1 / --f2;
	f3.printFraction();
	std::cout << "" << "Значение дроби 2: ";
	f2.printFraction();

	f3 = -f1;
	std::cout << "-f1" << " = ";
	f3.printFraction();
	f3 = -f2;
	std::cout << "-f2" << " = ";
	f3.printFraction();

	return EXIT_SUCCESS;
}