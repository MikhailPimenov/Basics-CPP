#pragma once

#include <cassert>

template <typename T>
class Array final {
private:
	int m_length;
	T* m_data;
public:
	Array();
	Array(int length);
	~Array();

	void erase();

	T& operator[](int index);
	const T& operator[](int index) const;

	int getLength() const;
};
