#include "become_partner.h"


template <typename H>
bool become_partner(std::shared_ptr<H>& human1, std::shared_ptr<H>& human2) {
	if (!human1 || !human2)
		return false;

	human1->m_partner = human2;
	human2->m_partner = human1;

	std::cout << "Human " << human1->m_name << " and human " << human2->m_name << " are partners now!\n";
}