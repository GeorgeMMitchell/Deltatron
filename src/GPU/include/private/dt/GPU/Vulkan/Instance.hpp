#ifndef DELTATRON_GPU_VULKAN_INSTANCE_HEADER
#define DELTATRON_GPU_VULKAN_INSTANCE_HEADER

#include <dt/GPU/Vulkan/Instance/AllocatorCallbacks.hpp>
#include <dt/GPU/Vulkan/Instance/CreateInfo.hpp>

#include <dt/System.hpp>

#include <vulkan/vulkan.h>

namespace dt {

class VulkanInstance final {
private:
  VkApplicationInfo        m_app_info;
  VulkanAllocatorCallbacks m_alloc_clbks;
  VulkanInstanceCreateInfo m_create_info;
  VkInstance               m_instance;

public:
  VulkanInstance() = delete;

  VulkanInstance(System const&);

  VulkanInstance(VulkanInstance const&) = delete;

  VulkanInstance(VulkanInstance&&) = delete;

  ~VulkanInstance() noexcept;

  VulkanInstance& operator=(VulkanInstance const&) = delete;

  VulkanInstance& operator=(VulkanInstance&&) = delete;
};

}

#endif // DELTATRON_GPU_VULKAN_INSTANCE_HEADER
