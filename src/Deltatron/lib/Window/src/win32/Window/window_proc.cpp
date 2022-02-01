#include <dt/win32/Window/window_proc.hpp>

#include <Windows.h>

namespace dt::Private {

LRESULT basic_paint(HWND window_handle) noexcept {
  auto paint_struct   = PAINTSTRUCT{};
  auto brush          = GetSysColorBrush(COLOR_HIGHLIGHTTEXT);

  auto device_context = BeginPaint(window_handle, &paint_struct);

  FillRect(device_context, &paint_struct.rcPaint, brush);

  EndPaint(window_handle, &paint_struct);

  return 0;
}

LRESULT basic_quit() noexcept
{ PostQuitMessage(0); return 0; }

}

LRESULT CALLBACK dt::window_proc(HWND window_handle, UINT message, WPARAM w_param, LPARAM l_param) {
  switch (message) {
  case WM_DESTROY: return Private::basic_quit();
  case WM_PAINT:   return Private::basic_paint(window_handle);
  default:
    return DefWindowProc(window_handle, message, w_param, l_param);
  }
}
