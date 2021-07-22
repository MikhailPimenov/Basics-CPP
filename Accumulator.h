#pragma once
class Accumulator {
private:
	int m_number;
public:
	Accumulator();

	const int& operator()(int increment = 0);
};

