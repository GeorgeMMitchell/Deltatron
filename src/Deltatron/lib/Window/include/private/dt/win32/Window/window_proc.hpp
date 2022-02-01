#ifndef DELTATRON_WINDOW_IMP_WINDOW_PROC_HEADER
#define DELTATRON_WINDOW_IMP_WINDOW_PROC_HEADER

#include <Windows.h>

namespace dt {

extern "C" LRESULT CALLBACK window_proc(HWND hwnd, UINT msg, WPARAM w_param, LPARAM l_param);

}

#endif // DELTATRON_WINDOW_IMP_WINDOW_PROC_HEADER
