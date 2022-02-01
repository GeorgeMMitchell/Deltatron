#ifndef DELTATRON_SYSTEM_HEADER
#define DELTATRON_SYSTEM_HEADER

#include <dt/ProgramArgs.hpp>
#include <dt/Filesystem.hpp>
#include <dt/Logger.hpp>

#include <dt/env.hpp>

namespace dt {

class System final {
public:
  using argv_type = ProgramArgs::argv_type;

private:
  ProgramArgs m_program_args;
  Filesystem  m_filesystem;
  Logger      m_logger;

public:
  System(int const argc, argv_type const argv);

  System(System const&) = delete;

  System(System&&) = delete;

  ~System() noexcept = default;

  System& operator=(System const&) = delete;

  System& operator=(System&&) = delete;

  constexpr auto program_args() const noexcept -> ProgramArgs const& { return m_program_args; }
  constexpr auto filesystem()   const noexcept -> Filesystem  const& { return m_filesystem;   }
  constexpr auto logger()       const noexcept -> Logger      const& { return m_logger;       }
};

}

#endif // DELTATRON_SYSTEM_HEADER
