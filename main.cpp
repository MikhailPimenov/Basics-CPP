#include <iostream>

#include "Item.h"

void f1(Item& object) {
	std::cout << "f1(Item&):\n";
}
void f1(Item&& object) {
	std::cout << "f1(Item&&):\n";
}

int Item::s_alive = 0;
int Item::s_counter = 0;

void printLvalue(std::string& name) {
	std::cout << "[non-const lvalue only] " << name << '\n';
}

void printLvalueConst(const std::string& name) {
	std::cout << "[const lvalue only] " << name << '\n';
}

void printRvalue(std::string&& name) {
	std::cout << "[rvalue only] " << name << '\n';
}

void print(const std::string& name) {
	std::cout << "[lvalue] " << name << '\n';
}
void print(std::string&& name) {
	std::cout << "[rvalue] " << name << '\n';
}

int main() {
	Item item;
	f1(item);
	f1(Item());

	
	int lvalue = 6;


	const int& lref_const = lvalue;
	//const int&& rref_const = lvalue; // error

	int& lref = lvalue;
	//int&& rref = lvalue; // error

	const int& lref_const2 = 7;
	const int&& rref_const2 = 7;

	//int& lref2 = 7; // error
	int&& rref2 = 7;


	std::cout << "\n\n\n";
	
	std::string name = "Mikhail";
	std::string surname = "Ivanov";
	std::string full_name = name + surname;


	printLvalue(full_name);
	//printLvalue(name + surname); // error
	
	std::cout << '\n';

	//printRvalue(full_name); // error
	printRvalue(name + surname);
	
	std::cout << '\n';

	printLvalueConst(full_name);
	printLvalueConst(name + surname);

	std::cout << '\n';

	print(full_name); // const std::string& overloaded version invoked
	print(name + surname); // std::string&& overloaded version invoked
	
	std::cout << '\n';

	return 0;
}