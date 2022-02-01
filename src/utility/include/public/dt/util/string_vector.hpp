#ifndef DELTATRON_UTILITY_STRING_VECTOR_HEADER
#define DELTATRON_UTILITY_STRING_VECTOR_HEADER

#include <string>
#include <vector>

namespace dt {

class string_vector final {
public:
  using str_vector_type  = std::vector<std::string>;
  using cstr_vector_type = std::vector<char const*>;

private:
  str_vector_type  m_str_vector;
  cstr_vector_type m_cstr_vector;

public:
  string_vector() = default;

  string_vector(std::vector<std::string> const& str_vector);

  string_vector(std::vector<std::string>&& str_vector);

  string_vector(string_vector const&) = default;

  string_vector(string_vector&&) = default;

  ~string_vector() noexcept = default;

  constexpr auto vector()  const noexcept -> str_vector_type  const& { return m_str_vector;  }
  constexpr auto cvector() const noexcept -> cstr_vector_type const& { return m_cstr_vector; }

  constexpr auto vector()  noexcept -> str_vector_type & { return m_str_vector;  }
  constexpr auto cvector() noexcept -> cstr_vector_type& { return m_cstr_vector; }

};

}

#endif // DELTATRON_UTILITY_STRING_VECTOR_HEADER
