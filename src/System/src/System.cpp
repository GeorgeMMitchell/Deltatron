#include <dt/System.hpp>

dt::System::System(int const argc, argv_type const argv)
: m_program_args{argc, argv},
  m_filesystem{m_program_args},
  m_logger{m_program_args, m_filesystem} {}
