#include <dt/GPU/Vulkan/Instance/CreateInfo.hpp>

#include <dt/util/ignore_unused.hpp>

dt::VulkanInstanceCreateInfo::VulkanInstanceCreateInfo(System const& system, VkApplicationInfo const&)
: m_enabled_layers{system},
  m_enabled_extensions{system},
  m_create_info{}
{
  ignore_unused(m_create_info);
}
