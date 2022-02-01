#ifndef JSON_HEADER
#define JSON_HEADER

#include <dt/json/value.hpp>

#include <istream>
#include <string>

namespace dt::json {

class document final {
private:
  std::string m_id;
  value       m_root_value;

public:
  document() = default;

  document(std::string const& id, std::string const& data);

  document(document const&) = default;

  document(document&&) noexcept = default;

  document& operator=(document const&) = default;

  document& operator=(document&&) = default;

  ~document() = default;

  constexpr auto& croot() const noexcept { return m_root_value; }

  constexpr auto& root() const noexcept { return m_root_value; }

  constexpr auto& root() noexcept { return m_root_value; }

  constexpr auto& id() const noexcept { return m_id; }
}; // document

} // json

#endif // JSON_HEADER
