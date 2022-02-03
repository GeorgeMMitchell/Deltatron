#include <dt/GPU/Vulkan/Instance/AllocationCallbacks.hpp>

#include <dt/util/ignore_unused.hpp>

dt::VulkanAllocationCallbacks::VulkanAllocationCallbacks(System const&)
: m_alloc_clbks{}
{
  ignore_unused(m_alloc_clbks);
}
