#include "Human_shared.h"


Human_shared::Human_shared(const std::string& name) : Human_base(name) {

}

const std::string& Human_shared::get_partner() const {
	return m_partner->m_name;
}