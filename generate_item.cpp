#include "generate_item.h"

template <template<typename> typename Smart_pointer, typename Data>
typename Smart_pointer<Data> generate_item(Smart_pointer<Data>&&){
	Smart_pointer<Data> local_object_to_return(new Data);
	return local_object_to_return;
}