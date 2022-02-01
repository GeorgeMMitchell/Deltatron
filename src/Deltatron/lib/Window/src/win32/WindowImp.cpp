#include <dt/win32/WindowImp.hpp>

#include <dt/util/ignore_unused.hpp>

#include <Windows.h>

#include <cassert>
#include <cstdlib>

dt::WindowImp::WindowImp(dt::System const& system)
: m_system{system},
  m_instance{GetModuleHandle(nullptr)},
  m_window_class{system, m_instance},
  m_window_handle{},
  m_window_name{L"Deltatron"}
{
  ignore_unused(m_system);
}

// Needs different enum to be thread-safe!
dt::WindowImp& dt::WindowImp::show()
{ ShowWindow(m_window_handle, SW_SHOW); return *this; }

// Needs different enum to be thread-safe!
dt::WindowImp& dt::WindowImp::hide()
{ ShowWindow(m_window_handle, SW_HIDE); return *this; }

// Needs different enum to be thread-safe!
dt::WindowImp& dt::WindowImp::minimize()
{ ShowWindow(m_window_handle, SW_MINIMIZE); return *this; }

// Needs different enum to be thread-safe!
dt::WindowImp& dt::WindowImp::maximize()
{ ShowWindow(m_window_handle, SW_MAXIMIZE); return *this; }

dt::WindowImp& dt::WindowImp::scale(int, int)
{ assert(false); return *this; }

dt::WindowImp& dt::WindowImp::translate(int, int)
{ assert(false); return *this; }

int dt::WindowImp::run() {
  RegisterClassExW(&m_window_class.get());

  m_window_handle = create_window();

  show();

  for (auto msg = MSG{}; GetMessage(&msg, nullptr, 0, 0); DispatchMessage(&msg))
    TranslateMessage(&msg);

  return EXIT_SUCCESS;
}

HWND dt::WindowImp::create_window() {
  auto window_handle = HWND{};

  window_handle = CreateWindowExW(
    0,                     // Optional window styles.
    m_window_class.name(), // Window class
    m_window_name.c_str(), // Window text
    WS_OVERLAPPEDWINDOW,   // Window style
    CW_USEDEFAULT,         // X
    CW_USEDEFAULT,         // Y
    CW_USEDEFAULT,         // Width
    CW_USEDEFAULT,         // Height
    nullptr,               // Parent window
    nullptr,               // Menu
    m_instance,            // Instance handle
    nullptr                // Additional application data
  );

  return window_handle;
}
