#include <dt/json/Lexer.hpp>

#include <dt/json/throw_exception.hpp>

#include <charconv>
#include <string_view>

#include <cctype>
#include <cstring>

dt::json::token_stream_type dt::json::Lexer::scan(std::string const& id, std::string const& data) {
  auto token_stream = token_stream_type{};

  for (auto lexer = Lexer{id, data}; !lexer.done(); ++lexer)
    lexer.append_token(token_stream);

  return token_stream;
}

dt::json::Lexer::Lexer(std::string const& id, std::string const& data)
: m_id{id},
  m_scanner{data} {}

void dt::json::Lexer::append_token(token_stream_type& token_stream) {
  if (auto const opt_keychar = is_keychar(); opt_keychar)
    token_stream.push_back({*opt_keychar, m_scanner.line()});

  else if (auto const opt_string = is_string(); opt_string)
    token_stream.push_back({*opt_string, m_scanner.line()});

  else if (auto const opt_int = is_int(); opt_int)
    token_stream.push_back({*opt_int, m_scanner.line()});

  else if (auto const opt_float = is_float(); opt_float)
    token_stream.push_back({*opt_float, m_scanner.line()});

  else if (auto const opt_bool = is_bool(); opt_bool)
    token_stream.push_back({*opt_bool, m_scanner.line()});

  else if (auto const opt_null = is_null(); opt_null)
    token_stream.push_back({token_type::Null, m_scanner.line()});

  else throw_lexer_exception("unknown token");
}

std::optional<dt::json::token_type> dt::json::Lexer::is_keychar() noexcept {
  switch (*m_scanner.current()) {
    case '{': return token_type::LBrace;
    case '}': return token_type::RBrace;
    case '[': return token_type::LBrack;
    case ']': return token_type::RBrack;
    case ':': return token_type::Colon;
    case ',': return token_type::Comma;
    default:  return {};
  }
}


std::optional<std::string> dt::json::Lexer::is_string() {
  if (*m_scanner.current() != '"')
    return {};

  if (m_scanner.current() >= m_scanner.end() - 2)
    throw_lexer_exception("string is missing closing quote");

  auto const string_begin = m_scanner.current() + 1;
  auto       string_end   = string_begin;
  auto       line         = m_scanner.line();

  while (string_end != m_scanner.end() && *string_end != '"') {
    if (*string_end == '\n')
      ++line;

    ++string_end;
  }

  if (done())
    throw_lexer_exception("string is missing closing quote");

  m_scanner.set_current(string_end);

  m_scanner.set_line(line);

  auto const string_value = std::string(string_begin, string_end);

  return string_value;
}

std::optional<dt::json::int_type> dt::json::Lexer::is_int() noexcept {
  if (!std::isdigit(*m_scanner.current()))
    return {};

  auto const int_begin = m_scanner.current();
  auto       int_end   = int_begin;

  while (int_end != m_scanner.end() && std::isdigit(*int_end))
    ++int_end;

  int_type int_value;

  auto const [ptr, ec] = std::from_chars(&*int_begin, &*int_end, int_value);

  if (ec != std::errc{})
    return {};

  m_scanner.set_current(int_end);

  return int_value;
}

std::optional<dt::json::float_type> dt::json::Lexer::is_float() noexcept {
  if (auto const c = *m_scanner.current(); !std::isdigit(c) || c != '-' || c != '.')
    return {};

  auto const float_begin = m_scanner.current();
  auto       float_end   = float_begin + 1;

  while (float_end != m_scanner.end() && (std::isdigit(*float_end) || *float_end == '.'))
    ++float_end;

#ifndef __GNUG__
  float_type float_value;

  auto const [ptr, ec] = std::from_chars(&*float_begin, &*(float_end - 1), float_value);

  if (ec != std::errc{})
    return {};

  return float_value;

#else
  // As of Jan. 2022 GCC still has no support for floating point from_chars
  // From what I understand it's an issue with libstdc++

  try {
    auto const float_string = std::string{float_begin, float_end};

    if constexpr (std::is_same_v<float_type, float>)
      return std::stof(float_string);

    else if constexpr (std::is_same_v<float_type, long double>)
      return std::stold(float_string);

    else
      return std::stod(float_string);

  } catch (...) { return {}; }

#endif
}

std::optional<bool> dt::json::Lexer::is_bool() noexcept {
  auto const true_string_view = std::string_view(&*m_scanner.current(), std::strlen("true"));

  if (true_string_view == "true") {
    m_scanner.set_current(m_scanner.current() + std::strlen("true") - 1);
    return true;
  }

  auto const false_string_view = std::string_view(&*m_scanner.current(), std::strlen("false"));

  if (false_string_view == "false") {
    m_scanner.set_current(m_scanner.current() + std::strlen("false") - 1);
    return false;
  }


  return {};
}

bool dt::json::Lexer::is_null() noexcept {
  auto const null_string_view = std::string_view(&*m_scanner.current(), std::strlen("null"));

  if (null_string_view == "null") {
    m_scanner.set_current(m_scanner.current() + std::strlen("null") - 1);
    return true;
  }

  return false;
}

[[noreturn]] void dt::json::Lexer::throw_lexer_exception(std::string const& what)
{ throw_exception(m_id, m_scanner.line(), what); }
