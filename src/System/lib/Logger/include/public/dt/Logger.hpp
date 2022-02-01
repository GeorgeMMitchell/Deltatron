#ifndef DELTATRON_LOGGER_HEADER
#define DELTATRON_LOGGER_HEADER

#include <dt/Filesystem.hpp>
#include <dt/ProgramArgs.hpp>

namespace dt {

enum class log_level {
  Error,
  Warning,
  Info,
  Trace
};

class Logger final {
public:
  Logger(ProgramArgs const& args, Filesystem const& fs);

  Logger(Logger const&) = delete;

  Logger(Logger&&) = delete;

  ~Logger() noexcept;

  Logger& operator=(Logger const&) = delete;

  Logger& operator=(Logger&&) = delete;
};

}

#endif // DELTATRON_LOGGER_HEADER
