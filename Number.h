#pragma once

#include <iostream>

class Number final {
private:
	int m_number;

public:
	Number();
	Number(int number);

	Number& operator++();
	Number& operator--();

	Number operator++(int);
	Number operator--(int);

	friend std::ostream& operator<<(std::ostream& out, const Number& object);
};

