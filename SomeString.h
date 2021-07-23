#pragma once

#include <cassert>
#include <iostream>

class SomeString {
private:
	std::string m_string;

public:
	SomeString(int size = 0);
	SomeString(const char* cstring);

	friend std::ostream& operator<<(std::ostream& out, const SomeString& object);
};

