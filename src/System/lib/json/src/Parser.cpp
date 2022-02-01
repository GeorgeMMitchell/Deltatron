#include <dt/json/Parser.hpp>

#include <dt/json/throw_exception.hpp>

dt::json::value dt::json::Parser::parse(std::string const& id, token_stream_type const& token_stream) {
  if (token_stream.empty())
    return {};

  auto const& first = token_stream[0];

  switch (first.type()) {
    // Object
    case token_type::LBrace: return Parser{id, token_stream}.parse_object();

    // Array
    case token_type::LBrack: return Parser{id, token_stream}.parse_array();

    // Basic Value
    // Check for token_stream.size() > 1
    case token_type::String: return first.as<std::string>();
    case token_type::Int:    return first.as<int_type>();
    case token_type::Float:  return first.as<float_type>();
    case token_type::Bool:   return first.as<bool>();
    case token_type::Null:   return std::nullopt;

    // Error
    //case token_type::RBrace: [[fallthrough]];
    //case token_type::RBrack: [[fallthrough]];
    //case token_type::Comma:  [[fallthrough]];
    //case token_type::Colon:
    default:
      throw_exception(id, 1, "expected root json value");
  }
}

dt::json::Parser::Parser(std::string const& id, token_stream_type const& token_stream)
: m_id{id},
  m_begin{token_stream.begin()},
  m_end{token_stream.end()},
  m_current{m_begin} {}

dt::json::object_type dt::json::Parser::parse_object() {
  if (!m_current->has_type(token_type::LBrace))
    throw_parser_exception("expected '{'");

  increment();

  auto object = object_type{};

  while (m_current != m_end) {
    if (m_current->has_type(token_type::RBrace))
      break;

    if (!m_current->has_type(token_type::String))
      throw_parser_exception("expected object key");

    auto const& key = m_current->as<std::string>();

    increment();

    if (!m_current->has_type(token_type::Colon))
      throw_parser_exception("expected ':' after object key");

    increment();

    switch (m_current->type()) {
      case token_type::LBrace: object.insert({key, parse_object()}); break;
      case token_type::LBrack: object.insert({key, parse_array()}); break;
      case token_type::String: object.insert({key, m_current->as<std::string>()}); break;
      case token_type::Int:    object.insert({key, m_current->as<int_type>()}); break;
      case token_type::Float:  object.insert({key, m_current->as<float_type>()}); break;
      case token_type::Bool:   object.insert({key, m_current->as<bool>()}); break;
      case token_type::Null:   object.insert({key, std::nullopt}); break;
      default:
        throw_parser_exception("expected value for object key");
    }

    increment();

    if (!m_current->has_type(token_type::Comma))
      if (!m_current->has_type(token_type::RBrace))
        throw_parser_exception("expected ',' or '}'");

    increment();
  }

  return object;
}

dt::json::array_type dt::json::Parser::parse_array() {
  if (!m_current->has_type(token_type::LBrack))
    throw_parser_exception("expected '['");

  increment();

  auto array = array_type{};

  while (m_current != m_end) {
    if (m_current->has_type(token_type::RBrack))
      break;

    switch (m_current->type()) {
      case token_type::LBrace: array.push_back(parse_object()); break;
      case token_type::LBrack: array.push_back(parse_array()); break;
      case token_type::String: array.push_back(m_current->as<std::string>()); break;
      case token_type::Int:    array.push_back(m_current->as<int_type>()); break;
      case token_type::Float:  array.push_back(m_current->as<float_type>()); break;
      case token_type::Bool:   array.push_back(m_current->as<bool>()); break;
      case token_type::Null:   array.push_back(std::nullopt); break;
      default:
        throw_parser_exception("expected array value");
    }

    increment();

    if (!m_current->has_type(token_type::Comma))
      if (!m_current->has_type(token_type::RBrace))
        throw_parser_exception("expected ',' or ']'");

    increment();
  }

  return array;
}

void dt::json::Parser::increment() {
  if (m_current >= m_end)
    throw_exception(m_id, (m_end - 1)->line(), "unexpected end of file");

  ++m_current;
}

[[noreturn]] void dt::json::Parser::throw_parser_exception(std::string const& what) const
{ throw_exception(m_id, m_current->line(), what); }
