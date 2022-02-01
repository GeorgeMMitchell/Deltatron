#ifndef DELTATRON_ENV_HEADER
#define DELTATRON_ENV_HEADER

#include <optional>
#include <string>

namespace dt::env {

bool entry_defined(std::string const& name);

std::optional<std::string> entry_value(std::string const& name);

}

#endif // DELTATRON_ENV_HEADER
