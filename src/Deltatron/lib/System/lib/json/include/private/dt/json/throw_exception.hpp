#ifndef DELTATRON_JSON_THROW_EXCEPTION_HEADER
#define DELTATRON_JSON_THROW_EXCEPTION_HEADER

#include <dt/exception.hpp>

#include <sstream>
#include <string>

#include <cstddef>

namespace dt::json {

[[noreturn]] inline void throw_exception(std::string const& id, std::size_t const line, std::string const& message) {
  auto msg = std::stringstream{};

  msg << id << ':' << line << ": " << message;

  throw dt::exception{msg.str()};
}

}

#endif // DELTATRON_JSON_THROW_EXCEPTION_HEADER
