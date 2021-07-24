#pragma once

#include <cassert>
#include <iostream>

class SomeStringShallowCopying {
private:
	char* m_data;
	int m_length;

public:
	SomeStringShallowCopying();
	SomeStringShallowCopying(const char* data);

	virtual ~SomeStringShallowCopying();

	friend std::ostream& operator<<(std::ostream& out, const SomeStringShallowCopying& object);
};
