#pragma once
class Dollars final {
private:
	int m_dollars;

public:
	Dollars();
	Dollars(int dollars);

	friend bool operator==(const Dollars& object1, const Dollars& object2);
	friend bool operator!=(const Dollars& object1, const Dollars& object2);
	
	friend bool operator<(const Dollars& object1, const Dollars& object2);
	friend bool operator>(const Dollars& object1, const Dollars& object2);
	
	friend bool operator<=(const Dollars& object1, const Dollars& object2);
	friend bool operator>=(const Dollars& object1, const Dollars& object2);
};

