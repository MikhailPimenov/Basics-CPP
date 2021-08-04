#include "Human_base.h"

Human_base::Human_base(const std::string& name) : m_name(name) {
	std::cout << "Human " << m_name << " acquired!\n";
}

Human_base::~Human_base() {
	std::cout << "Human " << m_name << " destroyed!\n";
}