#ifndef JSON_LEXER_SCANNER_HEADER
#define JSON_LEXER_SCANNER_HEADER

#include <string>

namespace dt::json {

class Scanner final {
public:
  using iterator = std::string::const_iterator;

private:
  iterator const m_begin;
  iterator const m_end;
  iterator       m_current;
  std::size_t    m_line;

public:
  Scanner() = delete;

  Scanner(std::string const& data);

  Scanner(Scanner const&) = default;

  Scanner(Scanner&&) = delete;

  ~Scanner() noexcept = default;

  Scanner& operator=(Scanner const&) = delete;

  Scanner& operator=(Scanner&&) = delete;

  Scanner& operator++();

  Scanner operator++(int);

  bool done() const noexcept;

  constexpr iterator const& begin() const noexcept { return m_begin; }

  constexpr iterator const& end() const noexcept { return m_end; }

  constexpr iterator const& current() const noexcept { return m_current; }

  constexpr std::size_t line() const noexcept { return m_line; }

  Scanner& set_current(iterator const& iter) noexcept;

  constexpr Scanner& set_line(std::size_t const line) noexcept { m_line = line; return *this; }
};

}

#endif // JSON_LEXER_SCANNER_HEADER
