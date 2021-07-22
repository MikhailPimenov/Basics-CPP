#pragma once

#include <iostream>

class Dollars final{
private:
	int m_dollars;

public:
	Dollars();
	Dollars(int dollars);

	Dollars operator+(const Dollars& object);
	Dollars operator+(int dollars);
	friend Dollars operator+(int dollars, const Dollars& object);

	int getDollars() const;
};