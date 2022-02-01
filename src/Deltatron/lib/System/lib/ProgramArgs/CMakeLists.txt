add_library("dt_ProgramArgs")

target_link_libraries("dt_ProgramArgs"
  PRIVATE
    "dt_build_flags"
    "dt_build_info"
    "dt_exception_interface")

target_include_directories("dt_ProgramArgs"
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include/public")

target_sources("dt_ProgramArgs"
  PRIVATE
    "include/public/dt/ProgramArgs.hpp"
    "src/ProgramArgs/help_menu.cpp"
    "src/ProgramArgs/flag.cpp"
    "src/ProgramArgs.cpp")

add_library("dt_ProgramArgs_interface" INTERFACE)

target_link_libraries("dt_ProgramArgs_interface"
  INTERFACE
    "dt_build_info"
    "dt_exception_interface")

target_include_directories("dt_ProgramArgs_interface"
  INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}/include/public")
