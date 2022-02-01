#ifndef JSON_LEXER_HEADER
#define JSON_LEXER_HEADER

#include <dt/json/Lexer/token.hpp>
#include <dt/json/Lexer/Scanner.hpp>

namespace dt::json {

class Lexer final {
private:
  std::string const& m_id;
  Scanner            m_scanner;

public:
  static token_stream_type scan(std::string const& id, std::string const& data);

private:
  Lexer(std::string const& id, std::string const& data);

  Lexer(Lexer const&) = default;

  Lexer(Lexer&&) = delete;

  ~Lexer() noexcept = default;

  Lexer& operator=(Lexer const&) = delete;

  Lexer& operator=(Lexer&&) = delete;

  Lexer& operator++() { ++m_scanner; return *this; }

  Lexer operator++(int) { auto const old = *this; operator++(); return old; }

  bool done() const noexcept { return m_scanner.done(); }

  void append_token(token_stream_type& token_stream);

  std::optional<token_type> is_keychar() noexcept;

  std::optional<std::string> is_string();

  std::optional<int_type> is_int() noexcept;

  std::optional<float_type> is_float() noexcept;

  std::optional<bool> is_bool() noexcept;

  bool is_null() noexcept;
};

}

#endif // JSON_LEXER_HEADER
