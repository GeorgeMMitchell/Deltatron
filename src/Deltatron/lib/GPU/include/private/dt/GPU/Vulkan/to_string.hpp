#ifndef DELTATRON_GPU_VULKAN_TO_STRING_HEADER
#define DELTATRON_GPU_VULKAN_TO_STRING_HEADER

#include <string>

#include <vulkan/vulkan.h>

namespace dt {

std::string to_string(VkResult const result);

}

#endif // DELTATRON_GPU_VULKAN_TO_STRING_HEADER
