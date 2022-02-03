configure_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/configure_file/info.h.in"
  "${CMAKE_BINARY_DIR}/include/build/info.h")

add_library("dt_build_info" INTERFACE)

target_include_directories("dt_build_info"
  INTERFACE
    "${CMAKE_BINARY_DIR}/include")
