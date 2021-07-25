#include "Item.h"

Item::Item() : m_id(++s_counter) {
	std::cout << "Item(): Item #" << m_id << " acquired! ";
	std::cout << ++s_alive << " item(s) alive!\n";
}

Item::~Item() {
	std::cout << "~Item(): Item #" << m_id << " destroyed! ";
	std::cout << --s_alive << " item(s) still alive!\n";
}

Item::Item(const Item& object) : m_id(++s_counter) {
	std::cout << "Item(const Item&): Item #" 
		      << m_id << " acquired from #" << object.m_id << '\n';
	std::cout << ++s_alive << " item(s) alive!\n";
}

Item& Item::operator=(const Item& object) {
	std::cout << "Item(const Item&): Item #"
		<< m_id << " assigned from #" << object.m_id << '\n';

	return *this;
}

void Item::sayHI() const {
	std::cout << "HI from Item #" << m_id << '\n';
}

