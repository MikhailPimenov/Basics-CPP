#include <iostream>
#include <memory>

#include "Human_shared.h"
#include "Human_weak.h"
#include "become_partner.h"

#include "Item_shared.h"
#include "Item_weak.h"

void example_with_memory_leak_because_of_circular_dependency() {
	std::cout << "\n\n\nMemory is not deleted because of circular dependency:\n\n";

	std::shared_ptr<Human_shared> andrew(std::make_shared<Human_shared>("Andrew"));
	std::shared_ptr<Human_shared> john(std::make_shared<Human_shared>("John"));

	become_partner(andrew, john);
}

void example_with_solved_circular_dependency_issue() {
	std::cout << "\n\n\nMemory is deleted because circular dependency issue is solved:\n\n";
	std::shared_ptr<Human_weak> beavis(std::make_shared<Human_weak>("Beavis"));
	std::shared_ptr<Human_weak> butthead(std::make_shared<Human_weak>("Butthead"));

	become_partner(beavis, butthead);
}


void example_with_memory_leak_because_of_simplified_circular_dependency() {
	std::cout << "\n\n\nMemory is not deleted because of simplified circular dependency:\n\n";

	std::shared_ptr<Item_shared> item(std::make_shared<Item_shared>(11));
	item->m_this = item;
}

void example_with_solved_simplified_circular_dependency_issue() {
	std::cout << "\n\n\nMemory is deleted because simplified circular dependency issue is solved:\n\n";
	std::shared_ptr<Item_weak> item(std::make_shared<Item_weak>(22));
	item->m_this.lock() = item;
}

int main() {
	example_with_memory_leak_because_of_circular_dependency();
	example_with_solved_circular_dependency_issue();

	example_with_memory_leak_because_of_simplified_circular_dependency();
	example_with_solved_simplified_circular_dependency_issue();

	return 0;
}