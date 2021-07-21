#include "Values.h"

Values::Values(int minimum, int maximum) : m_minimum(minimum), m_maximum(maximum) {
	sort();
}

void Values::sort() {
	if (m_minimum <= m_maximum)
		return;

	int temporary = m_minimum;
	m_minimum = m_maximum;
	m_maximum = temporary;
}

Values operator+(const Values& object1, const Values& object2) {
	int minimum = object1.m_minimum <= object2.m_minimum ? object1.m_minimum : object2.m_minimum;
	int maximum = object1.m_maximum >= object2.m_maximum ? object1.m_maximum : object2.m_maximum;
	return Values(minimum, maximum);
}

Values operator+(const Values& object, int value) {
	int minimum = object.m_minimum < value ? object.m_minimum : value;
	int maximum = object.m_maximum > value ? object.m_maximum : value;
	return Values(minimum, maximum);
}

Values operator+(int value, const Values& object) {
	return operator+(object, value);
}


int Values::getMin() const {
	return m_minimum;
}
int Values::getMax() const {
	return m_maximum;
}

