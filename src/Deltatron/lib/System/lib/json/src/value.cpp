#include <dt/json/value.hpp>

#include <utility>

dt::json::value::value() : m_value{std::nullopt}, m_type{enum_t::Null} {}

dt::json::value::value(std::nullopt_t const) : m_value{std::nullopt}, m_type{enum_t::Null} {}

dt::json::value::value(object_type const& object_value) : m_value{object_value}, m_type{enum_t::Object} {}

dt::json::value::value(array_type const& array_value) : m_value{array_value}, m_type{enum_t::Array} {}

dt::json::value::value(std::string const& string_value) : m_value{string_value}, m_type{enum_t::String} {}

dt::json::value::value(int const int_value) : m_value{int_value}, m_type{enum_t::Int} {}

dt::json::value::value(float const float_value) : m_value{float_value}, m_type{enum_t::Float} {}

dt::json::value::value(bool const bool_value) : m_value{bool_value}, m_type{enum_t::Bool} {}

dt::json::value& dt::json::value::operator=(std::nullopt_t const)
{ m_value = std::nullopt; m_type = enum_t::Null; return *this; }

dt::json::value& dt::json::value::operator=(object_type const& object_value)
{ m_value = object_value; m_type = enum_t::Object; return *this; }

dt::json::value& dt::json::value::operator=(array_type const& array_value)
{ m_value = array_value; m_type = enum_t::Array; return *this; }

dt::json::value& dt::json::value::operator=(std::string const& string_value)
{ m_value = string_value; m_type = enum_t::String; return *this; }

dt::json::value& dt::json::value::operator=(int const int_value)
{ m_value = int_value; m_type = enum_t::Int; return *this; }

dt::json::value& dt::json::value::operator=(float const float_value)
{ m_value = float_value; m_type = enum_t::Float; return *this; }

dt::json::value& dt::json::value::operator=(bool const bool_value)
{ m_value = bool_value; m_type = enum_t::Bool; return *this; }

dt::json::value& dt::json::value::operator=(object_type&& object_value)
{ m_value = std::move(object_value); m_type = enum_t::Object; return *this; }

dt::json::value& dt::json::value::operator=(array_type&& array_value)
{ m_value = std::move(array_value); m_type = enum_t::Array; return *this; }

dt::json::value& dt::json::value::operator=(std::string&& string_value)
{ m_value = std::move(string_value); m_type = enum_t::String; return *this; }

bool dt::json::value::operator==(value const& other) const noexcept {
  if (m_value.index() != other.m_value.index())
    return false;

  if (holds<std::nullopt_t>())
    return true;

  if (holds<object_type>())
    return as<object_type>() == other.as<object_type>();

  if (holds<array_type>())
    return as<array_type>() == other.as<array_type>();

  if (holds<std::string>())
    return as<std::string>() == other.as<std::string>();

  if (holds<int_type>())
    return as<int_type>() == other.as<int_type>();

  if (holds<float_type>())
    return as<float_type>() == other.as<float_type>();

  if (holds<bool>())
    return as<bool>() == other.as<bool>();

  return false;
}

bool dt::json::value::operator!=(value const& other) const noexcept
{ return !operator==(other); }
