#include <dt/GPU/Vulkan/Instance/CreateInfo.hpp>

#include <dt/util/ignore_unused.hpp>

dt::VulkanInstanceCreateInfo::VulkanInstanceCreateInfo(System const& system, VkApplicationInfo const&)
: m_enabled_layers{system},
  m_enabled_extensions{system},
  m_create_info{}
{
  ignore_unused(m_create_info);
}

VkInstanceCreateInfo dt::VulkanInstanceCreateInfo::create_create_info(System const&, VkApplicationInfo const& app_info) const {
  auto create_info = VkInstanceCreateInfo{};

  create_info.sType                   = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  create_info.pNext                   = nullptr;
  create_info.flags                   = 0;
  create_info.pApplicationInfo        = &app_info;
  create_info.enabledLayerCount       = 0;
  create_info.ppEnabledLayerNames     = nullptr;
  create_info.enabledExtensionCount   = 0;
  create_info.ppEnabledExtensionNames = nullptr;

  return create_info;
}
