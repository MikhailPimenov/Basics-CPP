#include "Item_weak.h"


Item_weak::Item_weak(int value) : m_value(value) {
	std::cout << "Item_weak(" << m_value << ") acquired!\n";
}

Item_weak::~Item_weak() {
	std::cout << "Item_weak(" << m_value << ") destroyed!\n";
}
