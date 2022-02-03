#ifndef DELTATRON_GPU_VULKAN_INSTANCE_CREATE_INFO_HEADER
#define DELTATRON_GPU_VULKAN_INSTANCE_CREATE_INFO_HEADER

#include <dt/GPU/Vulkan/Instance/CreateInfo/EnabledLayers.hpp>
#include <dt/GPU/Vulkan/Instance/CreateInfo/EnabledExtensions.hpp>

#include <dt/System.hpp>

#include <vulkan/vulkan.h>

namespace dt {

class VulkanInstanceCreateInfo final {
private:
  VulkanEnabledLayers     m_enabled_layers;
  VulkanEnabledExtensions m_enabled_extensions;
  VkInstanceCreateInfo    m_create_info;

public:
  VulkanInstanceCreateInfo() = delete;

  VulkanInstanceCreateInfo(System const& system, VkApplicationInfo const& app_info);

  VulkanInstanceCreateInfo(VulkanInstanceCreateInfo const&) = delete;

  VulkanInstanceCreateInfo(VulkanInstanceCreateInfo&&) = delete;

  ~VulkanInstanceCreateInfo() noexcept = default;

  VulkanInstanceCreateInfo& operator=(VulkanInstanceCreateInfo const&) = delete;

  VulkanInstanceCreateInfo& operator=(VulkanInstanceCreateInfo&&) = delete;

  constexpr auto info() const noexcept -> VkInstanceCreateInfo const& { return m_create_info; }

private:
  VkInstanceCreateInfo create_create_info(System const& system, VkApplicationInfo const& app_info) const;
};

}

#endif // DELTATRON_GPU_VULKAN_INSTANCE_CREATE_INFO_HEADER
