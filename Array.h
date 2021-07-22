#pragma once

#include <cassert>

template <typename T, int size>
class Array final {
private:
	T m_data[size];

public:
	Array();

	T& operator[](int index);
	const T& operator[](int index) const;
};

