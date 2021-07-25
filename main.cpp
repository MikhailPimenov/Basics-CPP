#include <iostream>

#include "Item.h"
#include "Auto_ptr.h"
#include "Auto_ptr2.h"

void f1() {
	Item* p = new Item;
	delete p;
}

void f2(int a) {
	Item* p = new Item;

	if (!a) return;

	delete p;
}

void f3(int a) {
	Auto_ptr<Item> p(new Item);

	if (!a) return;

	p->sayHI();
}

void f4(Auto_ptr<Item> item) {
// End of this function can lead to undefined behaviour, 
// because in main() memory will be deleted for the second time
}

Auto_ptr<Item> f5() {
	Auto_ptr<Item> p(new Item);
	return p;
// End of this function can lead to undefined behaviour, 
// because in main() memory will be deleted for the second time
}

void f6(int a) {
	Auto_ptr2<Item> p(new Item);

	if (!a) return;

	p->sayHI();
}

void f7(Auto_ptr2<Item> item) {
	
}

Auto_ptr2<Item> f8() {
	Auto_ptr2<Item> p(new Item);
	return p;
}

int Item::s_counter = 0;
int Item::s_alive = 0;
int main() {
	f1();

	f2(1);
	f2(0);

	f3(0);

	Auto_ptr<Item> p(new Item());
	//f4(p); // undefined behaviour after main() is finished

	//Auto_ptr<Item> p_returned = f5(); // undefined behaviour after main() is finished

	//f6(0);

	Auto_ptr2<Item> p2(new Item());
	//f7();

	
	//Auto_ptr2<Item> p2_returned = f8();

	Auto_ptr2<Item> item1(new Item);
	Auto_ptr2<Item> item2; // начнем с nullptr

	std::cout << "item1 is " << (item1.isNull() ? "null\n" : "not null\n");
	std::cout << "item2 is " << (item2.isNull() ? "null\n" : "not null\n");

	item2 = item1; // item2 теперь является "владельцем" значения item1, объекту item1 присваивается null

	std::cout << "Ownership transferred\n";

	std::cout << "item1 is " << (item1.isNull() ? "null\n" : "not null\n");
	std::cout << "item2 is " << (item2.isNull() ? "null\n" : "not null\n");


	return 0;
}