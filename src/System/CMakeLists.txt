add_subdirectory("lib")

add_library("dt_System")

target_link_libraries("dt_System"
  PRIVATE
    "dt_configure_file"
    "dt_build_requirements"
  PUBLIC
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
    "dt_env_interface"
    "dt_ProgramArgs_interface"
    "dt_Filesystem_interface"
    "dt_Logger_interface")

target_include_directories("dt_System_interface"
  INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}/include/public")
