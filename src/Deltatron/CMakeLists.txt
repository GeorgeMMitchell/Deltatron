add_subdirectory("lib")

add_library("dt")

target_include_directories("dt"
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include/private"
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include/public")

target_sources("dt"
  PRIVATE
    "include/public/dt/Deltatron.hpp"
    "src/Deltatron.cpp")

target_link_libraries("dt"
  PUBLIC
    "dt_System"
    "dt_GPU"
    "dt_Window")

add_executable("deltatron")

target_link_libraries("deltatron"
  PRIVATE
    "dt")

target_sources("deltatron"
  PRIVATE
    "src/main.cpp")
