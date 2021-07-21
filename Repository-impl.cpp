#include "Repository.cpp"

template class Repository_base<int>;
template class Repository<int>;

template class Repository_base<int *>;
template class Repository<int *>;

template class Repository_base<char *>;
template class Repository<char *>;
