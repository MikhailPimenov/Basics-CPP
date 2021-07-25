#pragma once

#include <iostream>

class Item final {
private:
	const int m_id;
	static int s_counter;
	static int s_alive;
public:
	Item();
	Item(const Item& object);

	~Item();
	Item& operator=(const Item& object);

	void sayHI() const;
};

