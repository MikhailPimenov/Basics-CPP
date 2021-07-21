#pragma once

#include <iostream>

class Dollars final{
private:
	int m_dollars;

public:
	Dollars(int dollars);

	int getDollars() const;
};

Dollars operator+(const Dollars& object1, const Dollars& object2);
Dollars operator+(const Dollars& object, int dollars);
Dollars operator+(int dollars, const Dollars& object);