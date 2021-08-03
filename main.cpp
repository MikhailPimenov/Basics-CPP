#include <iostream>
#include <memory>

#include "Item.h"

void f1(){
	std::cout << "begin f1():\n";

	std::unique_ptr<Item> item(std::make_unique<Item>(15));
	item->sayHI();

	std::cout << "end f1():\n";
}

void f2() {
	std::cout << "begin f2():\n";
	std::unique_ptr<Item[]> items(new Item[3]);

	for (int index = 0; index < 3; ++index)
		items[index].sayHI();

	std::cout << "end f2():\n";
}

void f3() {
	std::cout << "begin f3():\n";

	std::unique_ptr<Item> item(std::make_unique<Item>(99));
	std::unique_ptr<Item> item2;

	if (item)
		item->sayHI();
	if (item2)
		item2->sayHI();

	std::cout << "item is " << (static_cast<bool>(item) ? "not null" : "null") << '\n';
	std::cout << "item2 is " << (static_cast<bool>(item2) ? "not null" : "null") << '\n';

	item2 = std::move(item);
	std::cout << "ownership transfered\n";

	if (item)
		item->sayHI();
	if (item2)
		item2->sayHI();

	std::cout << "item is " << (static_cast<bool>(item) ? "not null" : "null") << '\n';
	std::cout << "item2 is " << (static_cast<bool>(item2) ? "not null" : "null") << '\n';

	std::cout << "end f3():\n";
}

void take_by_value(std::unique_ptr<Item> item) {
	item->sayHI();
}
void f4() {
	std::cout << "begin f4():\n";

	std::unique_ptr<Item> item(std::make_unique<Item>(77));
	item->sayHI();

	take_by_value(std::move(item)); // item gets destroyed after take_by_value() finishes being executed

	std::cout << "end f4():\n";
}

void take_pointer_to_resource(Item* item) {
	item->sayHI();
}
void f5() {
	std::cout << "begin f5():\n";

	std::unique_ptr<Item> item(std::make_unique<Item>(66));
	item->sayHI();

	take_pointer_to_resource(item.get()); 

	std::cout << "end f5():\n";

	// item gets destroyed here
}

std::unique_ptr<Item> get_item() {
	std::unique_ptr<Item> item(std::make_unique<Item>(55));

	item->sayHI();

	return item;
}
void f6() {
	std::cout << "begin f6():\n";

	std::unique_ptr<Item> item(get_item());
	item->sayHI();

	std::cout << "end f6():\n";
}

void f7() {
	std::cout << "begin f7():\n";
	
	Item* item = new Item(999);
	std::unique_ptr<Item> p1(item);
	std::unique_ptr<Item> p2(item);
	
	std::cout << "end f7():\n";

	// item gets destroyed two times => undefined behaviour
}

void f8() {
	std::cout << "begin f8():\n";

	Item* item = new Item(111);
	std::unique_ptr<Item> p(item);

	delete item;
	std::cout << "end f8():\n";

	// item gets destroyed two times => undefined behaviour
}

int function_that_can_throw_an_exception() {
	std::cout << "Throwing an exception...\n";
	throw - 1;
	return 0;
}
void function(std::unique_ptr<Item> item1, int value, std::unique_ptr<Item> item2) {
	return;
}
void f9() {
	std::cout << "begin f9():\n";

	try {
		// Compiler can select the order it wants:
		// first allocate Item(11), then execute function_that_can_throw_an_exception,
		// then create unique_ptr for Item(11). 
		// In case of exception unique_ptr won't be created,
		// so there will be nobody resbonsible for deallocation of Item(11)
		// what will lead to memory leak

		function(
			std::unique_ptr<Item>(new Item(11)),
			function_that_can_throw_an_exception(),
			std::unique_ptr<Item>(new Item(33))
		);
	}
	catch (int exception) {
		std::cout << "Caught int-exception: " << exception << '\n';
	}

	std::cout << "end f9():\n";
}
void f10() {
	std::cout << "begin f9():\n";

	try {

		// Here memory allocation and unique_ptr creation
		// are not separated due to make_unique:
		
		function(
			std::unique_ptr<Item>(std::make_unique<Item>(11)),
			function_that_can_throw_an_exception(),
			std::unique_ptr<Item>(std::make_unique<Item>(33))
		);
	}
	catch (int exception) {
		std::cout << "Caught int-exception: " << exception << '\n';
	}

	std::cout << "end f9():\n";
}

int main() {
	f1();
	std::cout << '\n';
	
	f2();
	std::cout << '\n';

	f3();
	std::cout << '\n';

    f4();
	std::cout << '\n';

    f5();
	std::cout << '\n';

	f6();
	std::cout << '\n';

	//f7(); // undefined behaviour, same memory is deleted two times
	std::cout << '\n';

	//f8(); // undefined behaviour, same memory is deleted two times
	std::cout << '\n';

	f9();
	std::cout << '\n';

	f10();
	std::cout << '\n';

	return 0;
}