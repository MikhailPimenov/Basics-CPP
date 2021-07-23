#include "Fraction.h"

Fraction::Fraction(int numerator, int denominator) : 
	m_numerator(numerator), 
	m_denominator(denominator) {
	assert(m_denominator != 0 && "Error: denominator should not be equal to zero.");
	std::cout << "Fraction(int, int):\n";
}

Fraction::Fraction(const Fraction& object) :
	m_numerator(object.m_numerator),
	m_denominator(object.m_denominator) {
	std::cout << "Fraction(const Fraction&):\n";
}

Fraction& Fraction::operator=(const Fraction& object) {
	std::cout << "operator=(const Fraction&):\n";
	
	if (this == &object)
		return *this;

	m_numerator = object.m_numerator;
	m_denominator = object.m_denominator;

	return *this;
}

void Fraction::setNumerator(int numerator) {
	m_numerator = numerator;
}

void Fraction::setDenominator(int denominator) {
	assert(denominator != 0 && "Error: tried to assign denominator to zero.");
	m_denominator = denominator;
}

int Fraction::getNumerator() const {
	return m_numerator;
}

int Fraction::getDenominator() const {
	return m_denominator;
}

std::ostream& operator<<(std::ostream& out, const Fraction& object) {
	out << object.m_numerator << '/' << object.m_denominator;
	return out;
}

