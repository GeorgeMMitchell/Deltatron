#include <dt/Window.hpp>

#ifdef _WIN32
  #include <dt/win32/WindowImp.hpp>
#endif

dt::Window::Window(System const& system)
: m_window{std::make_unique<WindowImp>(system)} {}

dt::Window::~Window() noexcept {}

dt::Window& dt::Window::show()
{ m_window->show(); return *this; }

dt::Window& dt::Window::hide()
{ m_window->hide(); return *this; }

dt::Window& dt::Window::minimize()
{ m_window->minimize(); return *this; }

dt::Window& dt::Window::maximize()
{ m_window->maximize(); return *this; }

dt::Window& dt::Window::scale(int x, int y)
{ m_window->scale(x, y); return *this; }

dt::Window& dt::Window::translate(int x, int y)
{ m_window->translate(x, y); return *this; }

int dt::Window::run()
{ return m_window->run(); }
