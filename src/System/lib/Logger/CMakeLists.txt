add_library("dt_Logger")

target_link_libraries("dt_Logger"
  PRIVATE
    "dt_build_requirements"
    "dt_configure_file"
  PUBLIC
    "dt_exception"
    "dt_ProgramArgs"
    "dt_Filesystem")

target_include_directories("dt_Logger"
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include/public")

target_sources("dt_Logger"
  PRIVATE
    "include/public/dt/Logger.hpp"
    "src/Logger.cpp")

add_library("dt_Logger_interface" INTERFACE)

target_link_libraries("dt_Logger_interface"
  INTERFACE
    "dt_exception_interface"
    "dt_ProgramArgs_interface"
    "dt_Filesystem_interface")

target_include_directories("dt_Logger_interface"
  INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}/include/public")
