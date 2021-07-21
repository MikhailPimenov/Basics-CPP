#pragma once

class Values {
private:
	int m_minimum;
	int m_maximum;


public:
	Values(int minimum, int maximum);

	friend Values operator+(const Values& object1, const Values& object2);
	friend Values operator+(const Values& object, int value);
	friend Values operator+(int value, const Values& object);

	int getMin() const;
	int getMax() const;
private:
	void sort();
};