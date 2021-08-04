#pragma once

#include <iostream>
#include <memory>

class Item_weak {
public:
	int m_value;
	std::weak_ptr<Item_weak> m_this;

public:
	Item_weak(int value = 0);
	~Item_weak();
};