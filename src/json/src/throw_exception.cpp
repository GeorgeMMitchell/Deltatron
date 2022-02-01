#include <dt/json/throw_exception.hpp>

#include <dt/exception.hpp>

#include <sstream>

[[noreturn]] void throw_exception(std::string const& id, std::size_t const line, std::string const& message) {
  auto msg = std::stringstream{};

  msg << "JSON parsing error in " << id << " at line " << line << ": " << message;

  throw dt::exception{msg.str()};
}
