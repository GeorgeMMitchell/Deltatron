#include <dt/util/string_vector.hpp>

dt::string_vector::string_vector(str_vector_type const& str_vector)
: m_str_vector{str_vector} {}

dt::string_vector::string_vector(str_vector_type&& str_vector)
: m_str_vector{std::move(str_vector)} {}
