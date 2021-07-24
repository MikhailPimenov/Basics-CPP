#pragma once

#include <iostream>

#include "Dollars.h"

class Cents final {
private:
	int m_cents;

public:
	Cents();
	Cents(int cents);

	friend bool operator>=(const Cents& object1, const Cents& object2);
	Cents& operator+=(const Cents& object);
	Cents& operator/=(const Cents& object);

	friend std::ostream& operator<<(std::ostream& out, const Cents& object);

	operator Dollars() const;
	operator int() const;
};

