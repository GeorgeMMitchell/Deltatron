#include <dt/exception.hpp>

dt::exception::exception(std::string const& what)
: std::exception{},
  m_what{what} {}

char const* dt::exception::what() const noexcept
{ return m_what.c_str(); }
