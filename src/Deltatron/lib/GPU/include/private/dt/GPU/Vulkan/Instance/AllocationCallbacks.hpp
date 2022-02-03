#ifndef DELTATRON_GPU_VULKAN_ALLOCATION_CALLBACKS_HEADER
#define DELTATRON_GPU_VULKAN_ALLOCATION_CALLBACKS_HEADER

#include <dt/System.hpp>

#include <vulkan/vulkan.h>

namespace dt {

//
// Not implemented
//

class VulkanAllocationCallbacks final {
private:
  VkAllocationCallbacks m_alloc_clbks;

public:
  VulkanAllocationCallbacks() = delete;

  VulkanAllocationCallbacks(System const& system);

  ~VulkanAllocationCallbacks() noexcept = default;

  VulkanAllocationCallbacks(VulkanAllocationCallbacks const&) = delete;

  VulkanAllocationCallbacks(VulkanAllocationCallbacks&&) = delete;

  VulkanAllocationCallbacks& operator=(VulkanAllocationCallbacks const&) = delete;

  VulkanAllocationCallbacks& operator=(VulkanAllocationCallbacks&&) = delete;

  constexpr auto callbacks_ptr() const noexcept -> VkAllocationCallbacks const* {

    return nullptr;

    // return std::addressof(m_alloc_clbks);
  }
};

}

#endif // DELTATRON_GPU_VULKAN_ALLOCATION_CALLBACKS_HEADER
