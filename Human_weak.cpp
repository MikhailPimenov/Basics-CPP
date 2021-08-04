#include "Human_weak.h"

Human_weak::Human_weak(const std::string& name) : Human_base(name) {

}

const std::string& Human_weak::get_partner() const {
	return m_partner.lock()->m_name;
}