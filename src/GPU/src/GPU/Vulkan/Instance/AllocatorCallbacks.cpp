#include <dt/GPU/Vulkan/Instance/AllocatorCallbacks.hpp>

#include <dt/util/ignore_unused.hpp>

dt::VulkanInstanceAllocatorCallbacks::VulkanInstanceAllocatorCallbacks(System const&)
: m_alloc_clbks{}
{
  ignore_unused(m_alloc_clbks);
}
