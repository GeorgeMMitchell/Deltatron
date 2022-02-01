#ifndef DELTATRON_HEADER
#define DELTATRON_HEADER

#include <dt/System.hpp>
#include <dt/GPU.hpp>
#include <dt/Window.hpp>

namespace dt {

class Deltatron final {
public:
  using argv_type = System::argv_type;

private:
  System m_system;
  GPU    m_GPU;
  Window m_window;

public:
  Deltatron(int const argc, argv_type const argv);

  Deltatron(Deltatron const&) = delete;

  Deltatron(Deltatron&&) = delete;

  ~Deltatron() noexcept = default;

  Deltatron& operator=(Deltatron const&) = delete;

  Deltatron& operator=(Deltatron&&) = delete;

  int run();
};

}

#endif // DELTATRON_HEADER
