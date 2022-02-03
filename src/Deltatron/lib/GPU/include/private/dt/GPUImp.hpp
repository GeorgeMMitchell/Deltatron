#ifndef DELTATRON_GPU_IMP_HEADER
#define DELTATRON_GPU_IMP_HEADER

#include <dt/GPU/Vulkan.hpp>

#include <dt/System.hpp>

namespace dt {

class GPUImp final {
private:
  Vulkan m_vulkan;

public:
  GPUImp() = delete;

  GPUImp(System const& system)
  : m_vulkan{system} {}

  GPUImp(GPUImp const&) = delete;

  GPUImp(GPUImp&&) = delete;

  ~GPUImp() noexcept = default;

  GPUImp& operator=(GPUImp const&) = delete;

  GPUImp& operator=(GPUImp&&) = delete;
};

}

#endif // DELTATRON_GPU_IMP_HEADER
