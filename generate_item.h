#pragma once

template <template<typename> typename Smart_pointer, typename Data>
typename Smart_pointer<Data> generate_item(Smart_pointer<Data>&& dummy);

