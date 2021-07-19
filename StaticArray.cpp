#include "StaticArray.h"

template <typename T, int size>
StaticArray_base<T, size>::~StaticArray_base() {

}

template <typename T, int size>
T* StaticArray_base<T, size>::data() {
	return this->m_data;
}

template <typename T, int size>
T& StaticArray_base<T, size>::operator[](int index) {
	assert(index >= 0 && index < size && "Error: index is out of range!");
	return this->m_data[index];
}

template <typename T, int size>
T const& StaticArray_base<T, size>::operator[](int index) const {
	assert(index >= 0 && index < size && "Error: index is out of range!");
	return this->m_data[index];
}

template <typename T, int size>
void StaticArray_base<T, size>::print() const {
	std::cout << "StaticArray_base::print(): common\n";
	for (int index = 0; index < size; ++index)
		std::cout << this->m_data[index] << ' ';
	std::cout << '\n';
}

template <int size>
void StaticArray<char, size>::print() const {
	std::cout << "StaticArray::print(): char\n";
	for (int index = 0; index < size; ++index)
		std::cout << this->m_data[index];
	std::cout << '\n';
}

template <int size>
void StaticArray<double, size>::print() const {
	std::cout << "StaticArray::print(): double\n";
	for (int index = 0; index < size; ++index)
		std::cout << std::scientific << this->m_data[index] << ' ';
	std::cout << '\n';
}