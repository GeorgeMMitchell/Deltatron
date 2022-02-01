add_subdirectory("lib")

add_library("dt_System")

target_link_libraries("dt_System"
  PUBLIC
    "dt_build_flags"
    "dt_build_info"
    "dt_exception"
    "dt_utility"
    "dt_json"
    "dt_env"
    "dt_ProgramArgs"
    "dt_Filesystem"
    "dt_Logger")

target_include_directories("dt_System"
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include/public")

target_sources("dt_System"
  PRIVATE
    "include/public/dt/System.hpp"
    "src/System.cpp")

add_library("dt_System_interface" INTERFACE)

target_link_libraries("dt_System_interface"
  INTERFACE
    "dt_build_flags"
    "dt_build_info"
    "dt_exception_interface"
    "dt_utility_interface"
    "dt_json_interface"
    "dt_env_interface"
    "dt_ProgramArgs_interface"
    "dt_Filesystem_interface"
    "dt_Logger_interface")

target_include_directories("dt_System_interface"
  INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}/include/public")
