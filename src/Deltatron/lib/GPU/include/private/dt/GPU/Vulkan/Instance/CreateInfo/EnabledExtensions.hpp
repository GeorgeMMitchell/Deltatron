#ifndef DELTATRON_GPU_VULKAN_INSTANCE_CREATE_INFO_ENABLED_EXTENSIONS_HEADER
#define DELTATRON_GPU_VULKAN_INSTANCE_CREATE_INFO_ENABLED_EXTENSIONS_HEADER

#include <dt/System.hpp>

#include <dt/util/string_vector.hpp>

namespace dt {

class VulkanEnabledExtensions final {
private:
  string_vector m_enabled_extensions;

public:
  VulkanEnabledExtensions() = delete;

  VulkanEnabledExtensions(System const& system);

  VulkanEnabledExtensions(VulkanEnabledExtensions const&) = delete;

  VulkanEnabledExtensions(VulkanEnabledExtensions&&) = delete;

  ~VulkanEnabledExtensions() noexcept = default;

  VulkanEnabledExtensions& operator=(VulkanEnabledExtensions const&) = delete;

  VulkanEnabledExtensions& operator=(VulkanEnabledExtensions&&) = delete;

  constexpr auto list() const noexcept -> string_vector const& { return m_enabled_extensions; }
};

}

#endif // DELTATRON_GPU_VULKAN_INSTANCE_CREATE_INFO_ENABLED_EXTENSIONS_HEADER
