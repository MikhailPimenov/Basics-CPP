#include "generate_item.cpp"

#include "Auto_ptr3.h"
#include "Auto_ptr4.h"

#include "Item.h"

template Auto_ptr3<Item> generate_item(Auto_ptr3<Item>&&);
template Auto_ptr4<Item> generate_item(Auto_ptr4<Item>&&);