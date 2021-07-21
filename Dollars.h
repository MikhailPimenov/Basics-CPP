#pragma once

#include <iostream>

class Dollars final{
private:
	int m_dollars;

public:
	Dollars(int dollars);
	Dollars(const Dollars &object);
	Dollars(Dollars &&object);

	Dollars& operator=(const Dollars& object);
	Dollars& operator=(Dollars&& object) noexcept;


	friend Dollars operator+(const Dollars& object1, const Dollars& object2);
	friend Dollars operator+(const Dollars& object, int dollars);
	friend Dollars operator+(int dollars, const Dollars& object);

	int getDollars() const;
};