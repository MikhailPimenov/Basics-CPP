#pragma once
#include <iostream>
#include <cassert>

template <typename T, int size>
class StaticArray final {
private:
	T m_data[size];

public:
	T& operator[](int index);
	const T& operator[](int index) const;
};