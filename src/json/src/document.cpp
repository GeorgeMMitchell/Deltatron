#include <dt/json/document.hpp>

#include <dt/json/Lexer.hpp>
#include <dt/json/Parser.hpp>

dt::json::document::document(std::string const& id, std::string const& data)
: m_id{id},
  m_root_value{Parser::parse(id, Lexer::scan(id, data))} {}
