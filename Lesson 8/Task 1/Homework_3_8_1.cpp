#include <iostream>

class Fraction
{
private:
	int numerator_{};
	int denominator_{};

public:
	Fraction(int getNumerator, int getDenominator) : numerator_{ getNumerator }, denominator_{ getDenominator }
	{}
	double Transformator()
	{	return numerator_ / denominator_;	}

	bool operator==(Fraction fractionSecond)
	{	return (Transformator() == fractionSecond.Transformator());	}
	bool operator!=(Fraction fractionSecond)
	{	return !(*this == fractionSecond);	}
	bool operator>(Fraction fractionSecond)
	{	return (Transformator() > fractionSecond.Transformator());	}
	bool operator<(Fraction fractionSecond)
	{	return (fractionSecond > *this);	}
	bool operator>=(Fraction fractionSecond)
	{	return !(*this < fractionSecond);	}
	bool operator<=(Fraction fractionSecond)
	{	return !(*this > fractionSecond);	}
};

int main()
{
	Fraction f1(4, 3);
	Fraction f2(6, 11);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';

	return EXIT_SUCCESS;
}