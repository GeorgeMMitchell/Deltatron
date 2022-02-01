#include <dt/json/Lexer/Scanner.hpp>

dt::json::Scanner::Scanner(std::string const& data)
: m_begin{data.begin()},
  m_end{data.end()},
  m_current{m_begin},
  m_line{1} {}

dt::json::Scanner& dt::json::Scanner::operator++() {
  if (!done())
    ++m_current;

  while (!done() && *m_current <= ' ') {
    if (*m_current == '\n')
      ++m_line;

    ++m_current;
  }

  return *this;
}

dt::json::Scanner dt::json::Scanner::operator++(int) {
  auto const old = *this;
  operator++();
  return old;
}

bool dt::json::Scanner::done() const noexcept
{ return m_current >= m_end; }

dt::json::Scanner& dt::json::Scanner::set_current(iterator const& iter) noexcept
{ m_current = iter; return *this; }
