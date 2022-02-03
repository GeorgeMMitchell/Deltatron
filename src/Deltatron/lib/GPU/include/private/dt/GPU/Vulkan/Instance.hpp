#ifndef DELTATRON_GPU_VULKAN_INSTANCE_HEADER
#define DELTATRON_GPU_VULKAN_INSTANCE_HEADER

#include <dt/GPU/Vulkan/Instance/AllocationCallbacks.hpp>
#include <dt/GPU/Vulkan/Instance/CreateInfo.hpp>

#include <dt/System.hpp>

#include <vulkan/vulkan.h>

namespace dt {

class VulkanInstance final {
private:
  VkApplicationInfo         m_app_info;
  VulkanAllocationCallbacks m_alloc_clbks;
  VulkanInstanceCreateInfo  m_create_info;
  VkInstance                m_instance;

public:
  VulkanInstance() = delete;

  VulkanInstance(System const&);

  VulkanInstance(VulkanInstance const&) = delete;

  VulkanInstance(VulkanInstance&&) = delete;

  ~VulkanInstance() noexcept;

  VulkanInstance& operator=(VulkanInstance const&) = delete;

  VulkanInstance& operator=(VulkanInstance&&) = delete;

private:
  VkApplicationInfo create_app_info(System const&) const;

  VkInstance create_instance(System const&) const;
};

}

#endif // DELTATRON_GPU_VULKAN_INSTANCE_HEADER
