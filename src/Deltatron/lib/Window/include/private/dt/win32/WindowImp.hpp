#ifndef DELTATRON_WINDOW_IMP_HEADER
#define DELTATRON_WINDOW_IMP_HEADER

#include <dt/win32/Window/window_class.hpp>

#include <dt/System.hpp>

#include <string>

#include <Windows.h>

namespace dt {

class WindowImp final {
private:
  System       const& m_system;
  HINSTANCE           m_instance;
  window_class        m_window_class;
  HWND                m_window_handle;
  std::wstring        m_window_name;

public:
  WindowImp(System const& system);

  WindowImp(WindowImp const&) = delete;

  WindowImp(WindowImp&&) = delete;

  ~WindowImp() noexcept = default;

  WindowImp& operator=(WindowImp const&) = delete;

  WindowImp& operator=(WindowImp&&) = delete;

  WindowImp& show();

  WindowImp& hide();

  WindowImp& minimize();

  WindowImp& maximize();

  WindowImp& scale(int x, int y);

  WindowImp& translate(int x, int y);

  int run();

private:
  HWND create_window();
};

}

#endif // DELTATRON_WINDOW_IMP_HEADER
