#pragma once

#include <cassert>
#include <iostream>

class SomeStringDelete {
private:
	std::string m_string;

public:
	SomeStringDelete(int size);

	SomeStringDelete(const char* cstring);
	SomeStringDelete(char) = delete;

	friend std::ostream& operator<<(std::ostream& out, const SomeStringDelete& object);
};
