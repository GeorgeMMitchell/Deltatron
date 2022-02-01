add_library("dt_exception")

target_link_libraries("dt_exception"
  PRIVATE
    "dt_build_requirements")

target_include_directories("dt_exception"
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include/public")

target_sources("dt_exception"
  PRIVATE
    "include/public/dt/exception.hpp"
    "src/exception.cpp")


add_library("dt_exception_interface" INTERFACE)

target_include_directories("dt_exception_interface"
  INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}/include/public")
