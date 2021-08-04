#include "Item_shared.h"

Item_shared::Item_shared(int value) : m_value(value) {
	std::cout << "Item_shared(" << m_value << ") acquired!\n";
}

Item_shared::~Item_shared() {
	std::cout << "Item_shared(" << m_value << ") destroyed!\n";
}
