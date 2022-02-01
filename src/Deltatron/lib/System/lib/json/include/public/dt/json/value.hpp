#ifndef JSON_VALUE_HEADER
#define JSON_VALUE_HEADER

#include <dt/json/value/types.hpp>

namespace dt::json {

class value final {
public:
  enum class enum_t {
    Object, Array, String,
    Int, Float, Bool, Null
  };

private:
  value_type m_value;
  enum_t     m_type;

public:
  value();

  value(std::nullopt_t const);

  value(object_type const& object_value);

  value(array_type const& array_value);

  value(std::string const& string_value);

  value(int const int_value);

  value(float const float_value);

  value(bool const bool_value);

  value(value const&) = default;

  value(value&&) = default;

  ~value() noexcept = default;

  value& operator=(std::nullopt_t const);

  value& operator=(object_type const& object_value);

  value& operator=(array_type const& array_value);

  value& operator=(std::string const& string_value);

  value& operator=(int const int_value);

  value& operator=(float const float_value);

  value& operator=(bool const bool_value);

  value& operator=(object_type&&);

  value& operator=(array_type&&);

  value& operator=(std::string&&);

  value& operator=(value const&) = default;

  value& operator=(value&&) = default;

  bool operator==(value const&) const noexcept;

  bool operator!=(value const&) const noexcept;

  template <typename T>
  constexpr bool holds() const noexcept { return std::holds_alternative<T>(m_value); }

  template <typename T>
  T const& as() const { return std::get<T>(m_value); }

  template <typename T>
  T const& as() { return std::get<T>(m_value); }

  constexpr auto& as_any() const noexcept { return m_value; }

  constexpr auto& as_any()       noexcept { return m_value; }

  constexpr auto type() const noexcept { return m_type; }
};

}

#endif // JSON_VALUE_HEADER
