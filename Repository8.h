#pragma once

#include <cassert>
#include <iostream>


template <typename T>
class Repository8 final {
private:
	T m_data[8];
public:
	Repository8();
	void set(int index, T value);
	const T& get(int index) const;
};

template <>
class Repository8<bool> final {
private:
	unsigned int m_data;
public:
	Repository8(): m_data(0u) {
		std::cout << "Repository8(): bool repository8\n";
	}
	void set(int index, bool value) {
		assert(index >= 0 && index < 8 && "Error: index is out of range!");

		static const unsigned int digit = 0x00000001;
		const unsigned int mask = digit << index;

		m_data &= (~mask);
		
		if(value) 
			m_data |= mask;

	}
	bool get(int index) const {
		static const unsigned int digit = 0x00000001;
		const unsigned int mask = digit << index;

		return static_cast<bool>(m_data & mask);
	}
};