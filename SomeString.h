#pragma once

#include <cassert>
#include <iostream>

class SomeString {
private:
	char* m_data;
	int m_length;

public:
	SomeString();
	SomeString(const char* data);
	SomeString(const SomeString& object);
	

	virtual ~SomeString();

	SomeString& operator=(const SomeString& object);


	friend std::ostream& operator<<(std::ostream& out, const SomeString& object);
};

