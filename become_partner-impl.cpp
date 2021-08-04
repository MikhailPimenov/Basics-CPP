#include "Human_shared.h"
#include "Human_weak.h"

#include "become_partner.cpp"

template bool become_partner<Human_shared>(std::shared_ptr<Human_shared>&, std::shared_ptr<Human_shared>&);
template bool become_partner<Human_weak>(std::shared_ptr<Human_weak>&, std::shared_ptr<Human_weak>&);