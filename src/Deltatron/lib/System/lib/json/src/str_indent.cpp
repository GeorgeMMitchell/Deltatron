#include <dt/json/document.hpp>

#include <iomanip>
#include <sstream>

#include <cassert>

namespace dt::json {

std::stringstream& add_space(std::stringstream& sstrm, int_type const indent) {
  for (int_type idx{}; idx < indent; ++idx)
    sstrm << ' ';

  return sstrm;
}

void write_array(std::stringstream& sstrm, array_type const& array, int_type const indent);

void write_object(std::stringstream& sstrm, object_type const& object, int_type const indent) {
  auto idx = std::size_t{};
  for (auto iter = object.begin(); iter != object.end(); ++iter, ++idx) {
    auto&& [key, val] = *iter;

    switch (val.type()) {
      case value::enum_t::Object:
        add_space(sstrm, indent) << std::quoted(key) << ": {" << std::endl;
        write_object(sstrm, val.as<object_type>(), indent + 2);
        add_space(sstrm, indent) << '}';
        break;

      case value::enum_t::Array:
        add_space(sstrm, indent) << std::quoted(key) << ": [" << std::endl;
        write_array(sstrm, val.as<array_type>(), indent + 2);
        add_space(sstrm, indent) << ']';
        break;

      case value::enum_t::String:
        add_space(sstrm, indent) << std::quoted(key) << ": " << val.as<std::string>();
        break;

      case value::enum_t::Float:
        add_space(sstrm, indent) << std::quoted(key) << ": " << std::fixed << std::setprecision(3) << val.as<float_type>();
        break;

      case value::enum_t::Int:
        add_space(sstrm, indent) << std::quoted(key) << ": " << val.as<int_type>();
        break;

      case value::enum_t::Bool:
        add_space(sstrm, indent) << std::quoted(key) << ": " << std::boolalpha << val.as<bool>();
        break;

      case value::enum_t::Null:
        add_space(sstrm, indent) << std::quoted(key) << ": null";
        break;

    }

    if (idx < (object.size() - 1))
      sstrm << ',' << std::endl;

    else endl(sstrm);
  }
}

void write_array(std::stringstream& sstrm, array_type const& array, int_type const indent) {
  for (auto iter = array.begin(); iter != array.end(); ++iter) {
    auto&& val = *iter;

    switch (val.type()) {
      case value::enum_t::Object:
        add_space(sstrm, indent) << '{' << std::endl;
        write_object(sstrm, val.as<object_type>(), indent + 2);
        add_space(sstrm, indent) << '}';
        break;

      case value::enum_t::Array:
        add_space(sstrm, indent) << '[' << std::endl;
        write_array(sstrm, val.as<array_type>(), indent + 2);
        add_space(sstrm, indent) << ']';
        break;

      case value::enum_t::String:
        add_space(sstrm, indent) << val.as<std::string>();
        break;

      case value::enum_t::Float:
        add_space(sstrm, indent) << std::fixed << std::setprecision(3) << val.as<float_type>();
        break;

      case value::enum_t::Int:
        add_space(sstrm, indent) << val.as<int_type>();
        break;

      case value::enum_t::Bool:
        add_space(sstrm, indent) << std::boolalpha << val.as<bool>();
        break;

      case value::enum_t::Null:
        add_space(sstrm, indent) << "null";
        break;
    }

    if (iter < (array.end() - 1))
      sstrm << ',' << std::endl;

    else endl(sstrm);
  }
}

}

std::string dt::json::document::str_indent() const {
  auto sstrm = std::stringstream{};

  switch (m_root_value.type()) {
    case value::enum_t::Object:
      sstrm << '{' << std::endl;
      write_object(sstrm, m_root_value.as<object_type>(), 2);
      sstrm << '}' << std::endl;
      break;

    case value::enum_t::Array:
      sstrm << '[' << std::endl;
      write_array(sstrm, m_root_value.as<array_type>(), 2);
      sstrm << ']' << std::endl;
      break;

    case value::enum_t::String:
      sstrm << m_root_value.as<std::string>() << std::endl;
      break;

    case value::enum_t::Float:
      sstrm << m_root_value.as<float_type>() << std::endl;
      break;

    case value::enum_t::Int:
      sstrm << m_root_value.as<int_type>() << std::endl;
      break;

    case value::enum_t::Bool:
      sstrm << std::boolalpha << m_root_value.as<bool>() << std::endl;
      break;

    case value::enum_t::Null:
      sstrm << "null" << std::endl;
      break;
  }

  return sstrm.str();
}
