#pragma once

#include <iostream>

class Item {
private:
	int m_data;
public:
	Item(int data = 0);
	~Item();

	void sayHI() const;
};

