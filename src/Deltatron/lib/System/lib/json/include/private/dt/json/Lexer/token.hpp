#ifndef JSON_LEXER_TOKEN_HEADER
#define JSON_LEXER_TOKEN_HEADER

#include <dt/json/value/types.hpp>

#include <vector>

namespace dt::json {

enum class token_type {
  String, Int, Float, Bool, Null,
  LBrace, RBrace, LBrack, RBrack,
  Colon, Comma
};

class token final {
public:
  using value_type = std::optional<std::variant<std::string, int_type, float_type, bool>>;

private:
  token_type  m_type;
  value_type  m_value;
  std::size_t m_line;

public:
  token() = delete;

  token(token_type const type, std::size_t const line);

  token(std::string const& string_value, std::size_t const line);

  token(int_type const int_value, std::size_t const line);

  token(float_type const float_value, std::size_t const line);

  token(bool const bool_value, std::size_t const line);

  token(token const&) = default;

  token(token&&) = default;

  ~token() noexcept = default;

  token& operator=(token const&) = default;

  token& operator=(token&&) = default;

  constexpr auto type() const noexcept { return m_type; }

  constexpr bool has_type(token_type const token_t) const noexcept { return m_type == token_t; }

  constexpr auto& cvalue() const noexcept { return m_value; }

  constexpr auto& value() const noexcept { return m_value; }

  constexpr auto& value() noexcept { return m_value; }

  constexpr auto line() const noexcept { return m_line; }

  template <typename T>
  constexpr auto const& as() const { return std::get<T>(*m_value); }
};

using token_stream_type = std::vector<token>;

}

#endif // JSON_LEXER_TOKEN_HEADER
