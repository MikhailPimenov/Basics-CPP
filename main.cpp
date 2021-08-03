#include <iostream>
#include <utility>
#include <vector>

class MoveClass {
public:
	int* m_resource;

public:
	MoveClass(int * resource = nullptr): 
		m_resource(resource) {
		//std::cout << "MoveClass(int*):\n";
	}
	MoveClass(int resource = 0): 
		m_resource(new int{resource}) {
		//std::cout << "MoveClass(int):\n";
	}
	MoveClass(const MoveClass &object): 
		m_resource(new int{*(object.m_resource)}) {
		//std::cout << "MoveClass(const MoveClass&):\n";
	}
	MoveClass(MoveClass&& object) noexcept: 
		m_resource(object.m_resource) {
		//std::cout << "MoveClass(MoveClass&&):\n";
		object.m_resource = nullptr;
	}

	~MoveClass() {
		std::cout << "Destroyed ";
		print();
		delete m_resource;
	}

	void print() const {
		std::cout << "MoveClass(";
		if (m_resource)
			std::cout << *m_resource;
		else
			std::cout << "Empty";
	
		std::cout << ")\n";
	}
};
class CopyClass {
public:
	bool m_throw{};

public:
	CopyClass(bool throww) : m_throw(throww) {
		
	}
	CopyClass(const CopyClass& object) : m_throw(object.m_throw) {
		if (m_throw)
			throw - 1;
	}
};

template <typename First, typename Second>
class Pair_move {
public:
	First m_first;
	Second m_second;

public:
	/*Pair_move(const First& first, const Second& second) : 
		m_first(first), 
		m_second(second) {
		std::cout << "Pair_move(const First&, const Second&):\n";
	}*/

	Pair_move(First&& first, Second&& second) :
		m_first(std::move(first)),
		m_second(std::move(second)) {
		std::cout << "Pair_move(First&&, Second&&):\n";
	}

};

template <typename First, typename Second>
class Pair_move_if_noexcept {
public:
	First m_first;
	Second m_second;

public:
	/*Pair_move_if_noexcept(const First& first, const Second& second) :
		m_first(first),
		m_second(second) {
		std::cout << "Pair_move_if_noexcept(const First&, const Second&):\n";
	}*/

	Pair_move_if_noexcept(First&& first, Second&& second) :
		// will convert to rvalue if there are no functions 
		// during constructing new First object, 
		// but it knows nothing about functions that may throw 
		// during construction new Second object
		m_first(std::move_if_noexcept(first)),

		// will convert to rvalue if there are no functions 
		// during constructing new Second object
		// but it knows nothing about functions that may throw 
		// during construction new First object
		m_second(std::move_if_noexcept(second)) {
		std::cout << "Pair_move_if_noexcept(First&&, Second&&):\n";
	}

};

void move_example() {
	Pair_move<MoveClass, CopyClass> pair{ MoveClass(14), CopyClass(false) };
	pair.m_second.m_throw = true;

	pair.m_first.print();
	{
		try {
			Pair_move<MoveClass, CopyClass> pair2{ std::move(pair) };
		}
		catch (int exception) {
			std::cout << "Caught an int-exception: " << exception << '\n';
		}
	}
	pair.m_first.print();
}

void move_if_noexcept_wrong_example() {
	Pair_move_if_noexcept<MoveClass, CopyClass> pair{ MoveClass(14), CopyClass(false) };
	pair.m_second.m_throw = true;

	pair.m_first.print();
	{
		try {
			Pair_move_if_noexcept<MoveClass, CopyClass> pair2{ std::move(pair) }; // still std::move
		}
		catch (int exception) {
			std::cout << "Caught an int-exception: " << exception << '\n';
		}
	}
	pair.m_first.print();
}

void move_if_noexcept_example1() {
	Pair_move<MoveClass, CopyClass> pair{ MoveClass(14), CopyClass(false) };
	pair.m_second.m_throw = true;

	pair.m_first.print();
	{
		try {
			// In that case move_if_noexcept will check if all functions invoked 
			// during constructing new Pair_move object don't throw any exception
			// and if so will convert pair to rvalue
			Pair_move<MoveClass, CopyClass> pair2{ std::move_if_noexcept(pair) }; // std::move_if_no_except instead of std::move
		}
		catch (int exception) {
			std::cout << "Caught an int-exception: " << exception << '\n';
		}
	}
	pair.m_first.print();
}



void move_if_noexcept_example2() {
	Pair_move_if_noexcept<MoveClass, CopyClass> pair{ MoveClass(14), CopyClass(false) };
	pair.m_second.m_throw = true;

	pair.m_first.print();
	{
		try {
			// In that case move_if_noexcept will check if all functions invoked 
			// during constructing new Pair_move_if_noexcept object don't throw any exception
			// and if so will convert pair to rvalue
			Pair_move_if_noexcept<MoveClass, CopyClass> pair2{ std::move_if_noexcept(pair) }; // std::move_if_no_except instead of std::move
		}
		catch (int exception) {
			std::cout << "Caught an int-exception: " << exception << '\n';
		}
	}
	pair.m_first.print();
}

int main() {
	std::cout << "\nData is lost while creating new object:\n";
	move_example();

	std::cout << "\nData is lost while creating new object. Wrong usage of move_if_noexcept : \n";
	move_if_noexcept_wrong_example();

	std::cout << "\nInstead of dangerous moving safe copying occures, data is not lost:\n";
	move_if_noexcept_example1();

	std::cout << "\nInstead of dangerous moving safe copying occures, data is not lost. A little bit safer:\n";
	move_if_noexcept_example2();

	return 0;
}