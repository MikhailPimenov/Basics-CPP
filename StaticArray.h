#pragma once

#include <cassert>
#include <iostream>


template <typename T, int size>
class StaticArray_base {
protected:
	T m_data[size];
public:
	virtual ~StaticArray_base();
	T* data();

    T& operator[](int index);
	T const& operator[](int index) const;

	virtual void print() const;
};


template <typename T, int size>
class StaticArray : public StaticArray_base<T, size >{
};

template <int size>
class StaticArray <char, size> : public StaticArray_base<char, size > {
public:
	virtual void print() const override;
};

template <int size>
class StaticArray <double, size> : public StaticArray_base<double, size > {
public:
	virtual void print() const override;
};


