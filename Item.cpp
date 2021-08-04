#include "Item.h"

Item::Item(int data) : m_data(data) {
	std::cout << "Item(" << m_data << ") acquired!\n";
}

Item::~Item() {
	std::cout << "Item destroyed!\n";
}

void Item::sayHI() const {
	std::cout << "I am an Item(" << m_data << ")\n";
}