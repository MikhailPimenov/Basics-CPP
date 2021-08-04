#include <iostream>
#include <memory>

#include "Item.h"

void f1() {
	std::cout << "begin f1():\n";

	Item* item = new Item(11);
	item->sayHI();

	std::shared_ptr<Item> ptr(item);
	ptr->sayHI();

	std::cout << "end f1():\n\n";
}
void f2() {
	std::cout << "begin f2():\n";

	Item* item = new Item(22);
	std::shared_ptr<Item> ptr1(item);
	{
		std::shared_ptr<Item> ptr2(ptr1);
		ptr2->sayHI();
		std::cout << "Killing one of shared pointers...\n";
	}

	ptr1->sayHI();

	std::cout << "end f2():\n\n";
}
void f3() {
	std::cout << "begin f3():\n";

	Item* item = new Item(33);
	std::shared_ptr<Item> ptr1(item);

	
	{
		std::shared_ptr<Item> ptr2(item); // wrong, ptr2 need to be created by copying ptr1
		ptr2->sayHI();
		std::wcout << "Killing one of shared pointers...\n";

		// item is destroyed here, because ptr2 thinks he is the only pointer to item
	}

	ptr1->sayHI();
	
	std::cout << "end f3():\n\n";

	// undefined behaviour here: ptr1 tries to delete already deleted item
}

int function_that_can_throw_an_exception() {
	throw - 1;
	return 0;
}
void function(std::shared_ptr<Item>, int, std::shared_ptr<Item>){
	return;
}
void f4() {
	std::cout << "begin f4():\n";


	// not recommended, unsafe in case of exceptions,
	// because compiler can choose order it wants,
	// such is allocating memory for object, 
	// then executing function_that_can_throw_an_exception,
	// and then creating shared_ptr responsible for object allocated before.
	// If exception is thrown, memory for object is allocated,
	// but shared_ptr responsible for that object is still not created,
	// so there will be nobody to delete allocated object:

	try {
		function(
			std::shared_ptr<Item>(new Item(441)),
			function_that_can_throw_an_exception(),
			std::shared_ptr<Item>(new Item(443))
		);
	}
	catch (int exception) {
		std::cout << "Caught int-exception: " << exception << '\n';
		std::cout << "Check if all objects are destroyed\n";
	}

	std::cout << "end f4():\n\n";
}

void f5() {
	std::cout << "begin f5():\n";

	// make_shared should be always used
	try {
		function(
			std::shared_ptr<Item>(std::make_shared<Item>(551)),
			function_that_can_throw_an_exception(),
			std::shared_ptr<Item>(std::make_shared<Item>(553))
		);
	}
	catch (int exception) {
		std::cout << "Caught int-exception: " << exception << '\n';
		std::cout << "Check if all objects are destroyed\n";
	}

	std::cout << "end f5():\n\n";
}

// do not use this because shared_ptr can not be safely converted to unique_ptr
std::shared_ptr<Item> get_shared_ptr() {
	return std::make_shared<Item>(999);
}

// use this because unique_ptr can be converted to shared_ptr
std::unique_ptr<Item> get_unique_ptr() {
	return std::make_unique<Item>(999);
}

void f6() {
	std::cout << "begin f6():\n";

	// wrong - there is no way to safely convert shared_ptr to unique_ptr
	//std::unique_ptr<Item> ptr1(std::make_shared<Item>(661));
	//std::unique_ptr<Item> ptr11(get_shared_ptr());


	std::shared_ptr<Item> ptr2(std::make_unique<Item>(662));
	std::shared_ptr<Item> ptr22(get_unique_ptr());


	ptr2->sayHI();
	ptr22->sayHI();

	std::cout << "end f6():\n\n";
}

int main() {
	f1();
	f2();
	//f3(); // undefined behaviour
	f4(); // memory leak
	f5();
	f6();


	return 0;
}