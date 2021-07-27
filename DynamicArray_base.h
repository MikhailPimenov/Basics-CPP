#pragma once

#include <cassert>

template <typename T>
class DynamicArray_base {
protected:
	T* m_data;
	int m_length;

protected:
	explicit DynamicArray_base(int length = 0);
	
public:
	virtual ~DynamicArray_base();
	int getLength() const;
	T& operator[](int index);
	const T& operator[](int index) const;
};

