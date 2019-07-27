#include "window/window_manager.h"


namespace window {


HWND WindowManager::CreateMainWindow(HINSTANCE h_inst,
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
                                     )) {
  HWND hwnd;
  WNDCLASSEX wc;

  wc.cbSize         = sizeof(WNDCLASSEX);
  wc.style          = CS_HREDRAW | CS_VREDRAW;
  wc.lpfnWndProc    = MainWndProc;
  wc.cbClsExtra     = 0;
  wc.cbWndExtra     = 0;
  wc.hInstance      = h_inst;
  wc.hIcon          = LoadIcon(h_inst, L"MYICON");
  wc.hCursor        = LoadCursor(NULL, IDC_ARROW);
  wc.hbrBackground  = CreateSolidBrush(bg_color);
  wc.lpszMenuName   = L"MYMENU";
  wc.lpszClassName  = L"MainWindowClass";
  wc.hIconSm        = LoadIcon(h_inst, L"MYICON");
  
  if (!RegisterClassEx(&wc)) {
    throw std::runtime_error("RegisterClassEx Failed");
  }

  hwnd = CreateWindow(
    L"MainWindowClass", 
    lpsz_caption,
    WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN,
    rc.left,
    rc.top,
    rc.right,
    rc.bottom,
    nullptr,
    nullptr,
    h_inst,
    nullptr
  );

  if (!hwnd) {
    throw std::runtime_error("CreateWindow Failed");
  }

  ShowWindow(hwnd, n_cmd_show);
  UpdateWindow(hwnd);

  return hwnd;
}

}
