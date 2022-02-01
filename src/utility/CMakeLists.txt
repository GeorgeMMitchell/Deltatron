add_library("dt_utility")

target_link_libraries("dt_utility"
  PUBLIC
    "dt_build_requirements")

target_include_directories("dt_utility"
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include/public")

target_sources("dt_utility"
  PRIVATE
    "include/public/dt/util/buffer.hpp"
    "include/public/dt/util/hash.hpp"
    "include/public/dt/util/ignore_unused.hpp"
    "include/public/dt/util/random.hpp"

    "include/public/dt/util/string_vector.hpp"
    "src/string_vector.cpp")
