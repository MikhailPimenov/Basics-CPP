#include "Fraction.h"

Fraction::Fraction(int numerator, int denominator) :
	m_numerator(numerator),
	m_denominator(denominator) {
	std::cout << "Fraction(int, int):\n";
	assert(m_denominator != 0 && "Error: denominator should not be equal to zero.");
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

std::ostream& operator<<(std::ostream& out, const Fraction& object) {
	out << object.m_numerator << '/' << object.m_denominator;
	return out;
}

void Fraction::setNumerator(int numerator) {
	m_numerator = numerator;
}

int Fraction::getNumerator() const {
	return m_numerator;
}