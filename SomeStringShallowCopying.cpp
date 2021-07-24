#include "SomeStringShallowCopying.h"

SomeStringShallowCopying::SomeStringShallowCopying() : m_data(nullptr), m_length(0) {
	std::cout << "SomeStringShallowCopying():\n";
}

SomeStringShallowCopying::SomeStringShallowCopying(const char* data) {
	std::cout << "SomeString(const char*):\n";

	int length = 0;
	while (data[length] != '\0')
		++length;
	++length; // '\0'

	m_data = new char[length];

	for (int index = 0; index < length; ++index)
		m_data[index] = data[index];

	m_length = length;
}

SomeStringShallowCopying::~SomeStringShallowCopying() {
	std::cout << m_data << "~SomeStringShallowCopying():\n";
	delete[] m_data;
}

std::ostream& operator<<(std::ostream& out, const SomeStringShallowCopying& object) {
	out << object.m_data;
	return out;
}