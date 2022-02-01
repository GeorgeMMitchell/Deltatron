#include <dt/GPU/Vulkan/Instance.hpp>

#include <vulkan/vulkan.h>

dt::VulkanInstance::VulkanInstance(System const& system)
: m_app_info{},
  m_alloc_clbks{system},
  m_create_info{system, app_info},
  m_instance{} {}

dt::VulkanInstance::~VulkanInstance() noexcept {
  if (m_instance)
    VkDestroyInstance(m_instance, m_alloc_clks->ptr());
}
