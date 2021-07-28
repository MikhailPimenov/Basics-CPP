#include <iostream>

#include "Item.h"

#include "Auto_ptr3.h"
#include "Auto_ptr4.h"

#include "generate_item.h"

#include "Timer.h"

#include "DynamicArrayCopy.h"
#include "DynamicArrayMove.h"

#include "clone_array_and_double.h"



int Item::s_counter = 0;
int Item::s_alive = 0;



int main() {

	std::cout << "copy semantics:\n\n";
	{
		Auto_ptr3<Item> mainItem3; // only deep copy constructor and '=' available
		mainItem3 = generate_item(Auto_ptr3<Item>());
	}

	std::cout << "\n\nmove semantics:\n\n";
	{
		Auto_ptr4<Item> mainItem4; // both move and copy semantics available
		mainItem4 = generate_item(Auto_ptr4<Item>());
	}
	std::cout << "\n\n\n\n";


	const int length = 1000000;
	const int number_of_tests = 50;
	
	double total_time1 = 0.0;
	double total_time2 = 0.0;

	for (int i = 0; i < number_of_tests; ++i) {
		DynamicArrayCopy<int> array_copy(length);

		for (int i = 0; i < array_copy.getLength(); i++)
			array_copy[i] = i;

		Timer t;
	    array_copy = clone_array_and_double(array_copy);
		const double time1 = t.elapsed();
		total_time1 += time1;

		std::cout << "time for copy semantics: " << time1 << "\n\n";

		DynamicArrayMove<int> array_move(length);

		for (int i = 0; i < array_move.getLength(); i++)
			array_move[i] = i;

		t.reset();
		array_move = clone_array_and_double(array_move);
		const double time2 = t.elapsed();
		total_time2 += time2;

		std::cout << "time for move semantics: " << time2 << "\n\n";

		std::cout << "time1 / time2 = " << time1 / time2 << '\n';
	}
	std::cout << "\n\n\n";

	const double average_time1 = total_time1 / (number_of_tests + 1);
	const double average_time2 = total_time2 / (number_of_tests + 1);

	const double ratio = average_time1 / average_time2;
	std::cout << "average_time1 / average_time2 = " << ratio << "\n\n\n";

	return 0;
}