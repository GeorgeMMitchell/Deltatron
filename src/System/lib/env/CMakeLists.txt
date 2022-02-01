add_library("dt_env")

target_link_libraries("dt_env"
  PRIVATE
    "dt_build_requirements"
    "dt_utility")

target_include_directories("dt_env"
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include/public")

target_sources("dt_env"
  PRIVATE
    "include/public/dt/env.hpp"
    "src/env.cpp")

add_library("dt_env_interface" INTERFACE)

target_include_directories("dt_env_interface" INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include/public")
