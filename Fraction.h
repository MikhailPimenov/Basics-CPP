#pragma once

#include <cassert>
#include <iostream>

class Fraction {
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction(int numerator = 0, int denominator = 1);
	
	Fraction(const Fraction& object);
	Fraction& operator=(const Fraction& object);


	void setNumerator(int numerator);
	int getNumerator() const;

	friend std::ostream& operator<<(std::ostream& out, const Fraction& object);
};

