#include "Fraction.h"

Fraction::Fraction(int numerator, int denominator) :
	m_numerator(numerator),
	m_denominator(denominator) {
	std::cout << "Fraction(int, int):\n";
	assert(m_denominator != 0 && "Error: denominator should not be equal to zero.");
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