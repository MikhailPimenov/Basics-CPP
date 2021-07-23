#pragma once

#include <cassert>
#include <iostream>


class Fraction final{
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction(int numerator = 0, int denominator = 1);
	Fraction(const Fraction& object);

	Fraction& operator=(const Fraction& object);

	void setNumerator(int numerator);
	void setDenominator(int denominator);

	int getNumerator() const;
	int getDenominator() const;

	friend std::ostream& operator<<(std::ostream& out, const Fraction& object);
};

