#ifndef FRACTION_H
#define FRACTION_H

class Fraction
{
private:
	int numerator_{};
	int denominator_{};

public:
	Fraction(int getNum = 1, int getDen = 3);
	int getNumerator();
	int getDenominator();
	void setNumerator(int number);
	void setDenominator(int number);

	void printFraction();

	Fraction operator+(Fraction& fractionSecond);
	Fraction operator-(Fraction& fractionSecond);
	Fraction operator*(Fraction& fractionSecond);
	Fraction operator/(Fraction& fractionSecond);
	Fraction& operator++();
	Fraction operator++(int);
	Fraction& operator--();
	Fraction operator--(int);
	Fraction operator-();
};

#endif