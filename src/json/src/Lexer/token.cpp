#include <dt/json/Lexer/token.hpp>

dt::json::token::token(token_type const type, std::size_t const line)
: m_type{type},
  m_value{},
  m_line{line} {}

dt::json::token::token(std::string const& string_value, std::size_t const line)
: m_type{token_type::String},
  m_value{string_value},
  m_line{line} {}

dt::json::token::token(int_type const int_value, std::size_t const line)
: m_type{token_type::Int},
  m_value{int_value},
  m_line{line} {}

dt::json::token::token(float_type const float_value, std::size_t const line)
: m_type{token_type::Float},
  m_value{float_value},
  m_line{line} {}

dt::json::token::token(bool const bool_value, std::size_t const line)
: m_type{token_type::Bool},
  m_value{bool_value},
  m_line{line} {}
