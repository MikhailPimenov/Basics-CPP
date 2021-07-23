#include "Fraction.h"

Fraction::Fraction(int numerator, int denominator) : m_numerator(numerator), m_denominator(denominator) {
	assert(m_denominator != 0 && "Error: denominator should not equal to zero.");
	std::cout << "Fraction(int, int):\n";
}

Fraction::Fraction(const Fraction& object) : 
	m_numerator(object.m_numerator), 
	m_denominator(object.m_denominator) {
	std::cout << "Fraction(const Fraction&):\n";
}

std::ostream& operator<<(std::ostream& out, const Fraction& object) {
	out << object.m_numerator << '/' << object.m_denominator;
	return out;
}