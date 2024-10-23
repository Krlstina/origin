#include <iostream>
#include "fraction.h"

Fraction::Fraction(int getNum, int getDen) : numerator_{ getNum }, denominator_{ getDen }
	{}
int Fraction::getNumerator() { return numerator_; }
int Fraction::getDenominator() { return denominator_; }
void Fraction::setNumerator(int number) { numerator_ = number; }
void Fraction::setDenominator(int number) { denominator_ = number; }

void Fraction::printFraction()
{
	std::cout << numerator_ << "/" << denominator_ << std::endl;
}

Fraction Fraction::operator+(Fraction& fractionSecond)
{
	if ((*this).denominator_ == fractionSecond.denominator_)
	{
		return { (*this).numerator_ + fractionSecond.numerator_, fractionSecond.denominator_ };
	}
	Fraction temporary{ *this };
	temporary.denominator_ = (*this).denominator_ * fractionSecond.denominator_;
	temporary.numerator_ = ((temporary.denominator_ / (*this).denominator_ * (*this).numerator_) + (temporary.denominator_ / fractionSecond.denominator_ * fractionSecond.numerator_));
	return temporary;
}
Fraction Fraction::operator-(Fraction& fractionSecond)
{
	if ((*this).denominator_ == fractionSecond.denominator_)
	{
		return { (*this).numerator_ - fractionSecond.numerator_, fractionSecond.denominator_ };
	}
	Fraction temporary{ *this };
	temporary.denominator_ = (*this).denominator_ * fractionSecond.denominator_;
	temporary.numerator_ = ((temporary.denominator_ / (*this).denominator_ * (*this).numerator_) - (temporary.denominator_ / fractionSecond.denominator_ * fractionSecond.numerator_));
	return temporary;
}
Fraction Fraction::operator*(Fraction& fractionSecond)
{
	if ((*this).denominator_ == fractionSecond.denominator_)
	{
		return { (*this).numerator_ * fractionSecond.numerator_, fractionSecond.denominator_ };
	}
	if ((*this).numerator_ == fractionSecond.denominator_)
	{
		return { fractionSecond.numerator_, (*this).denominator_ };
	}
	if ((*this).denominator_ == fractionSecond.numerator_)
	{
		return { (*this).numerator_, fractionSecond.denominator_ };
	}
	return { (*this).numerator_ * fractionSecond.numerator_, (*this).denominator_ * fractionSecond.denominator_ };
}
Fraction Fraction::operator/(Fraction& fractionSecond)
{
	if ((*this).numerator_ == fractionSecond.numerator_)
	{
		return { fractionSecond.denominator_, (*this).denominator_ };
	}
	if ((*this).denominator_ == fractionSecond.denominator_)
	{
		return { (*this).numerator_, fractionSecond.numerator_ };
	}
	return { (*this).numerator_ * fractionSecond.denominator_, (*this).denominator_ * fractionSecond.numerator_ };
}
Fraction& Fraction::operator++()
{
	numerator_ += denominator_;
	return *this;
}
Fraction Fraction::operator++(int)
{
	Fraction temporary{ *this };
	++(*this);
	return temporary;
}
Fraction& Fraction::operator--()
{
	numerator_ -= denominator_;
	return *this;
}
Fraction Fraction::operator--(int)
{
	Fraction temporary{ *this };
	--(*this);
	return temporary;
}
Fraction Fraction::operator-()
{
	numerator_ = -numerator_;
	return *this;
}