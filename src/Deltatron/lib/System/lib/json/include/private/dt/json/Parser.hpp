#ifndef JSON_PARSER_HEADER
#define JSON_PARSER_HEADER

#include <dt/json/Lexer/token.hpp>
#include <dt/json/value.hpp>

namespace dt::json {

class Parser final {
public:
  using iterator = typename token_stream_type::const_iterator;

private:
  std::string const& m_id;
  iterator    const  m_begin;
  iterator    const  m_end;
  iterator           m_current;

public:
  static value parse(std::string const& id, token_stream_type const& token_stream);

private:
  Parser(std::string const& id, token_stream_type const& token_stream);

  Parser(Parser const&) = default;

  Parser(Parser&&) = delete;

  ~Parser() noexcept = default;

  Parser& operator=(Parser const&) = delete;

  Parser& operator=(Parser&&) = delete;

  object_type parse_object();

  array_type parse_array();

  void increment();

  [[noreturn]] void throw_parser_exception(std::string const& what) const;
};

}

#endif // JSON_PARSER_HEADER
