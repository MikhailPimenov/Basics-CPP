#include "SomeString.h"

SomeString::SomeString() : m_data(nullptr), m_length(0) {
	std::cout << "SomeString():\n";
}

SomeString::SomeString(const char* data) {
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

SomeString::SomeString(const SomeString &object) : m_length(object.m_length) {
	std::cout << "SomeString(const SomeString&):\n";

	if (!object.m_data) {
		m_data = nullptr;
		return;
	}

	m_data = new char[m_length];

	for (int index = 0; index < object.m_length; ++index)
		m_data[index] = object.m_data[index];
}

SomeString::~SomeString() {
	delete[] m_data;
}

SomeString& SomeString::operator=(const SomeString& object) {
	std::cout << "operator=(const SomeString&):\n";
	if (this == &object)
		return *this;

	if (m_data)
		delete[] m_data;

	m_length = object.m_length;

	if (!object.m_data) {
		m_data = nullptr;
		return *this;
	}

	m_data = new char[m_length];
	for (int index = 0; index < object.m_length; ++index)
		m_data[index] = object.m_data[index];

	return *this;
}

std::ostream& operator<<(std::ostream& out, const SomeString& object) {
	out << object.m_data;
	return out;
}