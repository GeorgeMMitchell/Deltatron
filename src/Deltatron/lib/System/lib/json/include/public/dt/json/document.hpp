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

  constexpr auto& croot_value() const noexcept { return m_root_value; }

  constexpr auto& root_value() const noexcept { return m_root_value; }

  constexpr auto& root_value() noexcept { return m_root_value; }

  constexpr auto& id() const noexcept { return m_id; }
}; // document

std::string to_string(document const& doc);

std::string to_formatted_string(document const& doc);

} // json

#endif // JSON_HEADER
