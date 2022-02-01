#ifndef DELTATRON_GPU_VULKAN_HEADER
#define DELTATRON_GPU_VULKAN_HEADER

#include <dt/GPU/Vulkan/Instance.hpp>

#include <dt/System.hpp>

namespace dt {

class Vulkan final {
private:
  VulkanInstance m_instance;

public:
  Vulkan(System const& system);

  Vulkan(Vulkan const&) = delete;

  Vulkan(Vulkan&&) = delete;

  ~Vulkan() noexcept = default;

  Vulkan& operator=(Vulkan const&) = delete;

  Vulkan& operator=(Vulkan&&) = delete;
};

}

#endif // DELTATRON_GPU_VULKAN_HEADER
