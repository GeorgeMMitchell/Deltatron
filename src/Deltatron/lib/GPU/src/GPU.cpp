#include <dt/GPU.hpp>
#include <dt/GPUImp.hpp>

dt::GPU::GPU(System const& system)
: m_gpu{std::make_unique<GPUImp>(system)} {}

dt::GPU::~GPU() noexcept {}
