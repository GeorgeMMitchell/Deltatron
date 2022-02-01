#include <dt/ProgramArgs.hpp>

dt::ProgramArgs::flag::flag(
  std::string const& name,
  std::string const& alias,
  std::string const& definition,
  value_type  const  value)
: m_name{name},
  m_alias{alias},
  m_definition{definition},
  m_value{value} {}
