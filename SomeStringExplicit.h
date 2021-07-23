#pragma once

#include <cassert>
#include <iostream>

class SomeStringExplicit {
private:
	std::string m_string;

public:
	explicit SomeStringExplicit(int size) {
		assert(size >= 0 && "Error: size can not be negative.");
		m_string.resize(size);
	}
	SomeStringExplicit(const char* cstring) : m_string(cstring) {}

	friend std::ostream& operator<<(std::ostream& out, const SomeStringExplicit& object) {
		out << object.m_string;
		return out;
	}
};
