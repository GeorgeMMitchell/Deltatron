#ifndef DELTATRON_WINDOW_IMP_WINDOW_CLASS_HEADER
#define DELTATRON_WINDOW_IMP_WINDOW_CLASS_HEADER

#include <dt/System.hpp>

#include <string>

#include <Windows.h>

namespace dt {

class window_class final {
private:
  std::wstring m_class_name;
  WNDCLASSEXW  m_window_class;

public:
  window_class(System const& system, HINSTANCE instance) noexcept;

  ~window_class() noexcept;

  constexpr WNDCLASSEXW& get() noexcept { return m_window_class; }

  constexpr wchar_t const* name() noexcept { return m_class_name.c_str(); }
};

}

#endif // DELTATRON_WINDOW_IMP_WINDOW_CLASS_HEADER
