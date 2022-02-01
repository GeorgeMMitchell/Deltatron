add_library("dt_Filesystem")

target_link_libraries("dt_Filesystem"
  PRIVATE
    "dt_build_flags"
    "dt_env_interface"
    "dt_exception_interface"
    "dt_ProgramArgs_interface")

target_include_directories("dt_Filesystem"
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include/public")

target_sources("dt_Filesystem"
  PRIVATE
    "include/public/dt/Filesystem.hpp"
    "src/file_copy.cpp"
    "src/Filesystem.cpp")

add_library("dt_Filesystem_interface" INTERFACE)

target_link_libraries("dt_Filesystem_interface"
  INTERFACE
    "dt_ProgramArgs_interface"
    "dt_exception_interface")

target_include_directories("dt_Filesystem_interface"
  INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}/include/public")
