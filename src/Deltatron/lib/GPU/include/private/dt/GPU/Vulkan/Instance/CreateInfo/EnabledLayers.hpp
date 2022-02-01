#ifndef DELTATRON_GPU_VULKAN_INSTANCE_CREATE_INFO_ENABLED_LAYERS_HEADER
#define DELTATRON_GPU_VULKAN_INSTANCE_CREATE_INFO_ENABLED_LAYERS_HEADER

#include <dt/System.hpp>

#include <dt/util/string_vector.hpp>

namespace dt {

class VulkanEnabledLayers final {
private:
  string_vector m_enabled_layers;

public:
  VulkanEnabledLayers() = delete;

  VulkanEnabledLayers(System const& system);

  VulkanEnabledLayers(VulkanEnabledLayers const&) = delete;

  VulkanEnabledLayers(VulkanEnabledLayers&&) = delete;

  ~VulkanEnabledLayers() noexcept = default;

  VulkanEnabledLayers& operator=(VulkanEnabledLayers const&) = delete;

  VulkanEnabledLayers& operator=(VulkanEnabledLayers&&) = delete;

  constexpr auto list() const noexcept -> string_vector const& { return m_enabled_layers; }
};

}

#endif // DELTATRON_GPU_VULKAN_INSTANCE_CREATE_INFO_ENABLED_LAYERS_HEADER
