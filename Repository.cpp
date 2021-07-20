#include "Repository.h"


template <typename T>
Repository_base<T>::Repository_base() : m_data(T()) {
	std::cout << "Repository_base():\n";
}

template <typename T>
Repository_base<T>::Repository_base(const T& data) : m_data(data) {
	std::cout << "Repository_base(const T&):\n";
}

template <typename T>
Repository_base<T>::~Repository_base() {

}

template <typename T>
void Repository_base<T>::print() const {
	std::cout << this->m_data << '\n';
}



template <typename T>
Repository<T>::Repository(const T& data) : Repository_base<T>(data) {
	std::cout << "Repository(const T&):\n";
}




template <typename T>
Repository<T*>::Repository(const T* data) : Repository_base<T*>() {
	std::cout << "Repository(const T*):\n";
	this->m_data = new T;
	*(this->m_data) = *data;
}

template <typename T>
Repository<T*>::~Repository() {
	delete this->m_data;
}

template <typename T>
void Repository<T*>::print() const {
	std::cout << *(this->m_data) << '\n';
}



inline Repository<char*>::Repository(char* cstring) {
	std::cout << "Repository(char*):\n";
	int length = 0;
	while (cstring[length] != '\0')
		++length;
	++length; // '\0'

	this->m_data = new char[length];
	for (int index = 0; index < length; ++index)
		this->m_data[index] = cstring[index];
}

inline Repository<char*>::~Repository() {
	delete[] this->m_data;
}
