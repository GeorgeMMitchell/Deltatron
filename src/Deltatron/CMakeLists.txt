add_executable("deltatron")

target_link_libraries("deltatron"
  PRIVATE
    "dt_configure_file"
    "dt_build_requirements"
    "dt_System"
    "dt_GPU"
    "dt_Window")

target_include_directories("deltatron"
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include/private")

target_sources("deltatron"
  PRIVATE
    "include/private/dt/Deltatron.hpp"
    "src/Deltatron/main.cpp"
    "src/Deltatron.cpp")
