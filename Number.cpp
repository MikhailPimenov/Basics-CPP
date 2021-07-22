#include "Number.h"

Number::Number() : m_number(0) {

}

Number::Number(int number) : m_number(number) {

}

Number& Number::operator++() {
	++(this->m_number);
	return *this;
}

Number& Number::operator--() {
	--(this->m_number);
	return *this;
}

Number Number::operator++(int) {
	Number result_to_return(*this);
	
	++(*this);
	
	return result_to_return;
}

Number Number::operator--(int) {
	Number result_to_return(*this);

	--(*this);

	return result_to_return;
}

std::ostream& operator<<(std::ostream& out, const Number& object) {
	out << object.m_number;
	return out;
}