configure_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/configure_file/cmake_info.h.in"
  "${CMAKE_BINARY_DIR}/include/cmake/cmake_info.h")

add_library("dt_configure_file" INTERFACE)

target_include_directories("dt_configure_file"
  INTERFACE
    "${CMAKE_BINARY_DIR}/include")
