#ifndef DELTATRON_JSON_THROW_EXCEPTION_HEADER
#define DELTATRON_JSON_THROW_EXCEPTION_HEADER

#include <string>

#include <cstddef>

namespace dt::json {

[[noreturn]] void throw_exception(std::string const& id, std::size_t const line, std::string const& message);

}

#endif // DELTATRON_JSON_THROW_EXCEPTION_HEADER
