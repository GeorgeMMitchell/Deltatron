#ifndef DELTATRON_GPU_VULKAN_INSTANCE_ALLOCATOR_CALLBACKS_HEADER
#define DELTATRON_GPU_VULKAN_INSTANCE_ALLOCATOR_CALLBACKS_HEADER

#include <dt/System.hpp>

#include <vulkan/vulkan.h>

namespace dt {

//
// Not implemented
//

class VulkanInstanceAllocatorCallbacks final {
private:
  VkAllocationCallbacks m_alloc_clbks;

public:
  VulkanInstanceAllocatorCallbacks() = delete;

  VulkanInstanceAllocatorCallbacks(System const& system);

  ~VulkanInstanceAllocatorCallbacks() noexcept = default;

  VulkanInstanceAllocatorCallbacks(VulkanInstanceAllocatorCallbacks const&) = delete;

  VulkanInstanceAllocatorCallbacks(VulkanInstanceAllocatorCallbacks&&) = delete;

  VulkanInstanceAllocatorCallbacks& operator=(VulkanInstanceAllocatorCallbacks const&) = delete;

  VulkanInstanceAllocatorCallbacks& operator=(VulkanInstanceAllocatorCallbacks&&) = delete;

  constexpr auto ptr() const noexcept -> VkAllocationCallbacks const* {

    return nullptr;

    // return std::addressof(m_alloc_clbks);
  }
};

}

#endif // DELTATRON_GPU_VULKAN_INSTANCE_ALLOCATOR_CALLBACKS_HEADER
