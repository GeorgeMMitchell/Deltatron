#include <dt/win32/Window/window_class.hpp>

#include <dt/win32/Window/window_proc.hpp>

namespace dt::Private {

WNDCLASSEXW create_window_class(std::wstring const& class_name, HINSTANCE instance) noexcept {
  auto window_class = WNDCLASSEXW{};

  //window_class.cbClsExtra;
  window_class.cbSize = sizeof(window_class);
  //window_class.cbWndExtra;
  window_class.hbrBackground = GetSysColorBrush(COLOR_HIGHLIGHTTEXT);
  //window_class.hCursor;
  //window_class.hIcon;
  //window_class.hIconSm;
  window_class.hInstance = instance;
  window_class.lpfnWndProc = window_proc;
  window_class.lpszClassName = class_name.c_str();
  //window_class.lpszMenuName;
  //window_class.style;

  return window_class;
}

}

dt::window_class::window_class(System const&, HINSTANCE instance) noexcept
: m_class_name{L"Deltatron Window Class"},
  m_window_class{Private::create_window_class(m_class_name, instance)} {}

dt::window_class::~window_class() noexcept {}
