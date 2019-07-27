#ifndef WINDOW_MANAGER_
#define WINDOW_MANAGER_
#include <vector>
#include <stdexcept>
#include <windows.h>
#include "service/base_service.h"
#include "window/callbacks.h"
#include "window/window.h"


namespace window {

class WindowManager : public service::Service {
 public:
  HWND CreateMainWindow(HINSTANCE h_inst,
                        int n_cmd_show,
                        LPCWSTR lpsz_caption=L"3DViewer",
                        RECT rc=RECT{
                          CW_USEDEFAULT,
                          CW_USEDEFAULT,
                          CW_USEDEFAULT,
                          CW_USEDEFAULT
                        },
                        COLORREF bg_color=RGB(
                          0, 0, 0
                        ));

 private:
  std::vector<Window> windows_;
};


}

#endif