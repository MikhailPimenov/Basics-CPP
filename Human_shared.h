#pragma once

#include <memory>

#include "Human_base.h"

template <typename H>
bool become_partner(std::shared_ptr<H>&, std::shared_ptr<H>&);


class Human_shared : public Human_base {
private:
	std::shared_ptr<Human_shared> m_partner;

public:
	Human_shared(const std::string& name);


	 //here should be specialization become_partner<Humar_shared>, but it failed to make it work 
	template<typename H>
	friend bool become_partner(std::shared_ptr<H>& human1, std::shared_ptr<H>& human2);

	virtual const std::string& get_partner() const override;
};

