#include <dt/GPU/Vulkan/Instance.hpp>

#include <dt/GPU/Vulkan/to_string.hpp>

#include <build/info.h>

#include <vulkan/vulkan.h>

dt::VulkanInstance::VulkanInstance(System const& system)
: m_app_info{create_app_info(system)},
  m_alloc_clbks{system},
  m_create_info{system, m_app_info},
  m_instance{create_instance(system)} {}

dt::VulkanInstance::~VulkanInstance() noexcept {
  if (m_instance)
    vkDestroyInstance(m_instance, m_alloc_clbks.callbacks_ptr());
}

VkApplicationInfo dt::VulkanInstance::create_app_info(System const&) const {
  auto app_info = VkApplicationInfo{};

  app_info.sType              = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  app_info.pNext              = nullptr;
  app_info.pApplicationName   = "Deltatron";
  app_info.applicationVersion = VK_MAKE_VERSION(DELTATRON_VERSION_MAJOR, DELTATRON_VERSION_MINOR, DELTATRON_VERSION_PATCH);
  app_info.pEngineName        = "Deltatron Engine";
  app_info.engineVersion      = VK_MAKE_VERSION(DELTATRON_VERSION_MAJOR, DELTATRON_VERSION_MINOR, DELTATRON_VERSION_PATCH);
  app_info.apiVersion         = VK_API_VERSION_1_2;

  return app_info;
}

VkInstance dt::VulkanInstance::create_instance(System const&) const {
  auto instance = VkInstance{};

  auto const result = vkCreateInstance(&m_create_info.info(), m_alloc_clbks.callbacks_ptr(), &instance);


  if (result != VK_SUCCESS) {
    using namespace std::string_literals;
    throw exception{"could not create Vulkan instance: \""s + to_string(result) + '"'};
  }

  return instance;
}
