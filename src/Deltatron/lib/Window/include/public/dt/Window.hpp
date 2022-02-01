#ifndef DELTATRON_WINDOW_HEADER
#define DELTATRON_WINDOW_HEADER

#include <dt/System.hpp>

#include <memory>

namespace dt {

class WindowImp;

class Window final {
private:
  std::unique_ptr<WindowImp> m_window;

public:
  Window(System const& system);

  Window(Window const&) = delete;

  Window(Window&&) = delete;

  ~Window() noexcept;

  Window& operator=(Window const&) = delete;

  Window& operator=(Window&&) = delete;

  Window& show();

  Window& hide();

  Window& minimize();

  Window& maximize();

  Window& scale(int x, int y);

  Window& translate(int x, int y);

  int run();
};

}

#endif // DELTATRON_WINDOW_HEADER
