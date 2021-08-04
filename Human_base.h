#pragma once

#include <iostream>

class Human_base {
protected:
	std::string m_name;

protected:
	Human_base(const std::string& name);
	virtual ~Human_base();

	virtual const std::string& get_partner() const = 0;
};

