add_library("dt_Filesystem")

target_link_libraries("dt_Filesystem"
  PRIVATE
    "dt_build_requirements"
    "dt_env"
  PUBLIC
    "dt_exception"
    "dt_ProgramArgs")

target_include_directories("dt_Filesystem"
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include/public")

target_sources("dt_Filesystem"
  PRIVATE
    "include/public/dt/Filesystem.hpp"
    "src/Filesystem.cpp")

add_library("dt_Filesystem_interface" INTERFACE)

target_link_libraries("dt_Filesystem_interface"
  INTERFACE
    "dt_ProgramArgs_interface"
    "dt_exception_interface")

target_include_directories("dt_Filesystem_interface"
  INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}/include/public")
