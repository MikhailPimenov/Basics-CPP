#pragma once

#include "Dollars.h"

class Cents final {
private:
	int m_cents;

public:
	Cents();
	Cents(int cents);

	operator Dollars() const;
};

