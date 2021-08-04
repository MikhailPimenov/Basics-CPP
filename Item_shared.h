#pragma once

#include <iostream>
#include <memory>

class Item_shared {
public:
	int m_value;
	std::shared_ptr<Item_shared> m_this;

public:
	Item_shared(int value = 0);
	~Item_shared();
};