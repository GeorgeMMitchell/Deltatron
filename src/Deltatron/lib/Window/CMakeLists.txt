add_library("dt_Window")

target_link_libraries("dt_Window"
  PUBLIC
    "dt_System_interface")

target_include_directories("dt_Window"
  PRIVATE
    "include/private"
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include/public")

target_sources("dt_Window"
  PRIVATE
    "include/public/dt/Window.hpp"
    "src/Window.cpp"

    $<$<PLATFORM_ID:Windows>:
      "include/private/dt/win32/WindowImp.hpp"
      "src/win32/WindowImp.cpp"
      "include/private/dt/win32/Window/window_class.hpp"
      "src/win32/Window/window_class.cpp"
      "include/private/dt/win32/Window/window_proc.hpp"
      "src/win32/Window/window_proc.cpp"
    >)
