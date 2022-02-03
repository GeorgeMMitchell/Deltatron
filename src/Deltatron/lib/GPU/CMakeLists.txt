find_package("Vulkan" REQUIRED)

add_library("dt_GPU")

target_link_libraries("dt_GPU"
  PRIVATE
    "Vulkan::Vulkan"
  PUBLIC
    "dt_System_interface")

target_include_directories("dt_GPU"
  PRIVATE
    "include/private"
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include/public")

target_sources("dt_GPU"
  PRIVATE
    "include/private/dt//GPU/Vulkan/to_string.hpp"
    "src/GPU/Vulkan/to_string.cpp"


    "include/private/dt/GPU/Vulkan/Instance/CreateInfo/EnabledLayers.hpp"
    "src/GPU/Vulkan/Instance/CreateInfo/EnabledLayers.cpp"
    "include/private/dt/GPU/Vulkan/Instance/CreateInfo/EnabledExtensions.hpp"
    "src/GPU/Vulkan/Instance/CreateInfo/EnabledExtensions.cpp"
    "include/private/dt/GPU/Vulkan/Instance/CreateInfo.hpp"
    "src/GPU/Vulkan/Instance/CreateInfo.cpp"
    "include/private/dt/GPU/Vulkan/Instance/AllocationCallbacks.hpp"
    "src/GPU/Vulkan/Instance/AllocationCallbacks.cpp"
    "include/private/dt/GPU/Vulkan/Instance.hpp"
    "src/GPU/Vulkan/Instance.cpp"

    "include/private/dt/GPU/Vulkan.hpp"
    "src/GPU/Vulkan.cpp"

    "include/private/dt/GPUImp.hpp"

    "include/public/dt/GPU.hpp"
    "src/GPU.cpp")

add_library("dt_GPU_interface" INTERFACE)

target_link_libraries("dt_GPU_interface"
  INTERFACE
    "dt_System_interface")

target_include_directories("dt_GPU_interface"
  INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}/include/public")
