#include <dt/Deltatron.hpp>

#include <thread>

#include <cstdlib>

dt::Deltatron::Deltatron(int const argc, argv_type const argv)
: m_system{argc, argv},
  m_GPU{m_system},
  m_window{m_system} {}

int dt::Deltatron::run() {
  std::thread{[&] { return m_window.run(); }}.join();

  return EXIT_SUCCESS;
}
